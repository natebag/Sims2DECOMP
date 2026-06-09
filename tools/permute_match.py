#!/usr/bin/env python3
"""permute_match.py — honest source-level permuter for near-miss matches.

Takes a near-miss .cpp and hill-climbs toward a byte-match by applying ONLY
honest C++ source transforms, scoring each candidate with verify_match.sh
--strict (differing-word count). No ASMPROC, no asm, no post-compile mutation
— every candidate is plain C++ run through the same strict gate as hand work.

Transforms (v1):
  F  flag-state sweep: {default, -fno-schedule-insns, -fno-schedule-insns2, both}
  S  adjacent-statement swap (same brace depth, ';'-terminated lines)
  D  local-decl reorder (adjacent decl lines swapped)

Search: best-first. Evaluate all flag states; take best; then iterate
single-swap neighbors, accepting strict improvements, until MATCH, no
improving neighbor, or --budget candidates evaluated.

Usage:
  python tools/permute_match.py SRC ADDR SIZE [--budget 300] [--workers 8]
  python tools/permute_match.py --targets docs/tracking/permuter-targets-day0.txt --top 5

Output: build/permute/<addr>/best.cpp (best candidate) + result line.
Exit 0 if a MATCH was found.
"""
import argparse
import concurrent.futures
import itertools
import os
import re
import subprocess
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
FLAG_STATES = [
    None,
    "-fno-schedule-insns",
    "-fno-schedule-insns2",
    "-fno-schedule-insns -fno-schedule-insns2",
]
_counter = itertools.count()


def read_src(path):
    with open(path, "r", encoding="utf-8", errors="replace") as f:
        return f.read().replace("\r\n", "\n")


def set_flags(text, flags):
    """Replace/insert the // FLAGS: header line. None = remove (default flags)."""
    lines = [l for l in text.split("\n") if not re.match(r"\s*//\s*FLAGS:", l)]
    if flags is not None:
        # FLAGS replaces the default -fno-elide-constructors, so preserve it
        lines.insert(0, f"// FLAGS: -fno-elide-constructors {flags}")
    return "\n".join(lines)


def brace_depth_lines(text):
    """Yield (index, line, depth_at_line_start) for the whole file."""
    depth = 0
    out = []
    for i, line in enumerate(text.split("\n")):
        out.append((i, line, depth))
        # crude but effective: count braces outside string/char literals
        stripped = re.sub(r'"(\\.|[^"\\])*"', '""', line)
        stripped = re.sub(r"'(\\.|[^'\\])*'", "''", stripped)
        stripped = re.sub(r"//.*", "", stripped)
        depth += stripped.count("{") - stripped.count("}")
    return out


_STMT = re.compile(r"^\s*[^\s/].*;\s*$")
_CTRL = re.compile(r"^\s*(if|else|for|while|do|switch|case|default|return|break|continue|goto|\})\b")
_DECL = re.compile(r"^\s*(?:const\s+)?(?:unsigned\s+|signed\s+)?\w+(?:\s*[*&]+\s*|\s+)\w+\s*(=[^;]*)?;\s*$")


_AGGREGATE = re.compile(r"\b(struct|class|union|enum)\b")


def _aggregate_depths(text):
    """Per line, the set of brace depths opened by struct/class/union/enum.

    Lines whose innermost enclosing brace belongs to an aggregate are member
    declarations — permuting them changes layout/semantics (and a member
    pushed outside the struct becomes a global whose SDA reloc the verifier
    masks, i.e. a wildcarded instruction). Never touch them.
    """
    depth = 0
    stack = []  # True = aggregate scope
    inside = []
    pending_aggregate = False
    for line in text.split("\n"):
        stripped = re.sub(r'"(\\.|[^"\\])*"', '""', line)
        stripped = re.sub(r"'(\\.|[^'\\])*'", "''", stripped)
        stripped = re.sub(r"//.*", "", stripped)
        if _AGGREGATE.search(stripped):
            pending_aggregate = True
        inside.append(bool(stack) and stack[-1])
        for ch in stripped:
            if ch == "{":
                stack.append(pending_aggregate)
                pending_aggregate = False
                depth += 1
            elif ch == "}":
                if stack:
                    stack.pop()
                depth -= 1
        if ";" in stripped and "{" not in stripped:
            pending_aggregate = False
    return inside


def _permutable_runs(text):
    """Find runs of consecutive permutable statement lines (same depth>=1),
    excluding aggregate (struct/class/union/enum) bodies."""
    info = brace_depth_lines(text)
    in_aggregate = _aggregate_depths(text)
    runs, cur = [], []
    for i, line, d in info:
        ok = (d >= 1 and not in_aggregate[i]
              and _STMT.match(line) and not _CTRL.match(line))
        if ok:
            if cur and info[cur[-1]][2] != d:
                runs.append(cur)
                cur = []
            cur.append(i)
        else:
            if len(cur) >= 2:
                runs.append(cur)
            cur = []
    if len(cur) >= 2:
        runs.append(cur)
    return runs


def swap_candidates(text):
    """Generate single-edit neighbors: adjacent swaps + 3-line rotations.

    Operates on runs of consecutive simple ';'-terminated statements at the
    same brace depth. Decl/non-decl mixing is allowed in rotations (a decl
    moved past first use is a compile error the scorer rejects — costs one
    candidate, occasionally wins).
    """
    lines = text.split("\n")
    seen = set()

    def emit(tag, idxs, perm):
        nl = list(lines)
        for dst, src_i in zip(idxs, perm):
            nl[dst] = lines[src_i]
        out = "\n".join(nl)
        if out != text and out not in seen:
            seen.add(out)
            yield (tag, idxs[0], out)

    for run in _permutable_runs(text):
        # adjacent swaps
        for i, j in zip(run, run[1:]):
            if lines[i].strip() == lines[j].strip():
                continue
            a_decl, b_decl = bool(_DECL.match(lines[i])), bool(_DECL.match(lines[j]))
            tag = "D-swap" if (a_decl and b_decl) else "S-swap"
            yield from emit(tag, [i, j], [j, i])
        # 3-line rotations
        for a, b, c in zip(run, run[1:], run[2:]):
            yield from emit("rot-l", [a, b, c], [b, c, a])
            yield from emit("rot-r", [a, b, c], [c, a, b])


def score(text, addr, size, symbol, tag):
    """Compile+verify a candidate. Returns (status, diff_words|None)."""
    n = next(_counter)
    workdir = f"build/permute/{addr:08X}"
    os.makedirs(os.path.join(ROOT, workdir), exist_ok=True)
    cand = f"{workdir}/c{n}_{tag}.cpp"
    with open(os.path.join(ROOT, cand), "w", encoding="utf-8", newline="\n") as f:
        f.write(text)
    cmd = ["bash", "tools/verify_match.sh", "--strict", "--outdir", f"{workdir}/o{n}"]
    if symbol:
        cmd += ["--symbol", symbol]
    cmd += [cand, f"0x{addr:08X}", str(size)]
    try:
        r = subprocess.run(cmd, cwd=ROOT, capture_output=True, text=True, timeout=120)
    except subprocess.TimeoutExpired:
        return cand, "TIMEOUT", None, None
    out = r.stdout + r.stderr
    # reloc fingerprint: count per relocation type. A candidate that GAINS
    # relocations vs the baseline is hiding a changed instruction under the
    # verifier's reloc mask (e.g. member decl pushed out of a struct becomes
    # an SDA global) — that is a fake match, not a crack.
    rfp = tuple(sorted(__import__("collections").Counter(
        re.findall(r"\|(\w+)\|", out)).items()))
    if "MATCH!" in out:
        return cand, "MATCH", 0, rfp
    if "MISMATCH" in out and "SIZE_MISMATCH" not in out:
        return cand, "MISMATCH", len(re.findall(r"^\s+offset 0x[0-9a-f]+:", out, re.M)), rfp
    return cand, "FAIL", None, rfp


def parse_symbol(text):
    m = re.search(r"//\s*VERIFY-SYMBOL:\s*(\S+)", text)
    return m.group(1) if m else None


def permute_one(src_path, addr, size, budget=300, workers=8, log=print):
    base = read_src(src_path)
    symbol = parse_symbol(base)
    evaluated = 0
    best_text, best_diff, best_status = None, 10 ** 9, None

    def evaluate(cands):
        """cands: list of (tag, text). Returns list of (text, status, diff, tag, rfp)."""
        nonlocal evaluated
        res = []
        with concurrent.futures.ThreadPoolExecutor(max_workers=workers) as ex:
            futs = {ex.submit(score, t, addr, size, symbol, tag): (tag, t)
                    for tag, t in cands}
            for fu in concurrent.futures.as_completed(futs):
                tag, t = futs[fu]
                _, status, diff, rfp = fu.result()
                evaluated += 1
                res.append((t, status, diff, tag, rfp))
        return res

    # Phase F: flag states on the unmodified source — each viable state seeds
    # its own hill-climb (scheduling flags couple with statement order, so a
    # state that starts worse can still win after reordering).
    seeds = []
    flag_cands = [(f"flags{k}", set_flags(base, fs)) for k, fs in enumerate(FLAG_STATES)]
    for t, status, diff, tag, rfp in evaluate(flag_cands):
        if status == "MATCH":
            return t, "MATCH", 0, evaluated
        if status == "MISMATCH":
            seeds.append((diff, t, rfp))
    if not seeds:
        return None, "NO_BASELINE", None, evaluated
    seeds.sort(key=lambda s: s[0])
    best_diff, best_text = seeds[0][0], seeds[0][1]
    log(f"  flag sweep: {len(seeds)} viable states, best {best_diff} words off")

    # Phase S/D/rot: per-seed hill climb with limited plateau moves
    PLATEAU_LIMIT = 2
    budget_per = max(20, (budget - evaluated) // len(seeds))
    for seed_diff, seed_text, seed_rfp in seeds:
        frontier, frontier_diff = seed_text, seed_diff
        spent_here, plateau_used = 0, 0
        visited = {frontier}
        while spent_here < budget_per and evaluated < budget:
            cands = [(f"{kind}@{i}", t) for kind, i, t in swap_candidates(frontier)
                     if t not in visited]
            if not cands:
                break
            cands = cands[: max(0, min(budget - evaluated, budget_per - spent_here))]
            spent_here += len(cands)
            round_best, round_diff = None, frontier_diff
            plateau_cand = None
            for t, status, diff, tag, rfp in evaluate(cands):
                visited.add(t)
                if rfp != seed_rfp:
                    continue  # reloc fingerprint changed — masked-instruction fake
                if status == "MATCH":
                    return t, "MATCH", 0, evaluated
                if status != "MISMATCH":
                    continue
                if diff < round_diff:
                    round_best, round_diff = t, diff
                elif diff == frontier_diff and plateau_cand is None:
                    plateau_cand = t
            if round_best is not None:
                frontier, frontier_diff = round_best, round_diff
                if round_diff < best_diff:
                    best_text, best_diff = round_best, round_diff
                    log(f"  improved -> {best_diff} words off ({evaluated} evaluated)")
            elif plateau_cand is not None and plateau_used < PLATEAU_LIMIT:
                frontier = plateau_cand
                plateau_used += 1
            else:
                break
    return best_text, "MISMATCH", best_diff, evaluated


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("src", nargs="?")
    ap.add_argument("addr", nargs="?")
    ap.add_argument("size", nargs="?", type=int)
    ap.add_argument("--targets")
    ap.add_argument("--top", type=int, default=5)
    ap.add_argument("--budget", type=int, default=300)
    ap.add_argument("--workers", type=int, default=8)
    args = ap.parse_args()

    jobs = []
    if args.targets:
        with open(args.targets) as f:
            for line in f:
                if line.startswith("#") or not line.strip():
                    continue
                m = re.match(r"(0x[0-9A-Fa-f]+)\s+(\d+)\s+(\d+)\s+(\S.*)$", line)
                if m:
                    jobs.append((m.group(4).strip().replace("\\", "/"),
                                 int(m.group(1), 16), int(m.group(2))))
        jobs = jobs[: args.top]
    elif args.src and args.addr and args.size:
        jobs = [(args.src, int(args.addr, 16), args.size)]
    else:
        ap.error("need SRC ADDR SIZE or --targets")

    any_match = False
    for src, addr, size in jobs:
        print(f"== permuting {src} @0x{addr:08X} ({size}B), budget {args.budget}")
        text, status, diff, n = permute_one(src, addr, size, args.budget, args.workers)
        outdir = os.path.join(ROOT, f"build/permute/{addr:08X}")
        os.makedirs(outdir, exist_ok=True)
        if text is not None:
            with open(os.path.join(outdir, "best.cpp"), "w", encoding="utf-8",
                      newline="\n") as f:
                f.write(text)
        print(f"   -> {status}" + (f" ({diff} words off)" if diff else "") +
              f" after {n} candidates; best saved to build/permute/{addr:08X}/best.cpp")
        if status == "MATCH":
            any_match = True
    sys.exit(0 if any_match else 1)


if __name__ == "__main__":
    main()
