#!/usr/bin/env python3
"""version_ab_test.py — Day-0 SN ProDG point-version A/B sweep.

Runs verify_match.sh on a corpus of source files under multiple SN ProDG
versions (3.9.3 / 3.8.1 / 3.7 / 3.5) by prepending a `// SN-VERSION:` header
to a temp copy of each source. NO post-compile mutation — this only selects
which historical compiler binary verify_match.sh invokes.

Modes:
  --clean-sample N [--seed S]   random N entries from build/audit/clean.txt
  --manifest FILE               explicit "addr size path" lines (audit format)
  --files PATH...               source files; addr parsed from filename
                                (0x........), size resolved via config/symbols.txt

Output: build/vertest/results_<label>.json + console summary.

Usage:
  python tools/version_ab_test.py --clean-sample 200 --label cleans
  python tools/version_ab_test.py --files src/wip/crack_*.cpp --label walls
"""
import argparse
import concurrent.futures
import json
import os
import random
import re
import subprocess
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
VERSIONS = ["3.9.3", "3.8.1", "3.7", "3.5"]
VERTEST = os.path.join(ROOT, "build", "vertest")


def load_symbol_sizes():
    """addr(int) -> size(int) from config/symbols.txt"""
    sizes = {}
    pat = re.compile(r"=\s*\.\w+:(0x[0-9A-Fa-f]+);\s*//.*?size:(0x[0-9A-Fa-f]+)")
    with open(os.path.join(ROOT, "config", "symbols.txt")) as f:
        for line in f:
            m = pat.search(line)
            if m:
                sizes[int(m.group(1), 16)] = int(m.group(2), 16)
    return sizes


def parse_manifest(path):
    jobs = []
    with open(path) as f:
        for line in f:
            line = line.strip()
            if not line or line.startswith("#"):
                continue
            m = re.match(r"(0x[0-9A-Fa-f]+)\s+(\d+)\s+(\S.*)$", line)
            if m:
                jobs.append((m.group(3).strip(), int(m.group(1), 16), int(m.group(2))))
    return jobs


def jobs_from_files(paths, sizes):
    jobs, skipped = [], []
    for p in paths:
        m = re.search(r"0[xX]([0-9A-Fa-f]{8})", os.path.basename(p))
        if not m:
            skipped.append((p, "no address in filename"))
            continue
        addr = int(m.group(1), 16)
        if addr not in sizes:
            skipped.append((p, "address not in symbols.txt"))
            continue
        jobs.append((p, addr, sizes[addr]))
    return jobs, skipped


def make_temp_src(src_path, version, run_id, label):
    tmp_dir = os.path.join(VERTEST, "tmp", label)
    os.makedirs(tmp_dir, exist_ok=True)
    with open(src_path, "r", encoding="utf-8", errors="replace") as f:
        lines = f.readlines()
    # strip any existing SN-VERSION marker so ours wins
    lines = [l for l in lines if not re.match(r"\s*//\s*SN-VERSION:", l)]
    tmp = os.path.join(tmp_dir, f"r{run_id}.cpp")
    with open(tmp, "w", encoding="utf-8", newline="\n") as f:
        f.write(f"// SN-VERSION: {version}\n")
        f.writelines(lines)
    return tmp


def parse_verify_symbol(src_path):
    with open(src_path, "r", encoding="utf-8", errors="replace") as f:
        for line in f:
            m = re.match(r"\s*//\s*VERIFY-SYMBOL:\s*(\S+)", line)
            if m:
                return m.group(1)
    return None


def run_one(job):
    src, addr, size, version, run_id, label = job
    tmp = make_temp_src(src, version, run_id, label)
    # relative forward-slash paths only — msys bash chokes on win-abs paths
    outdir = f"build/vertest/out/{label}/r{run_id}"
    cmd = ["bash", "tools/verify_match.sh", "--strict", "--outdir", outdir]
    sym = parse_verify_symbol(src)
    if sym:
        cmd += ["--symbol", sym]
    cmd += [os.path.relpath(tmp, ROOT).replace("\\", "/"), f"0x{addr:08X}", str(size)]
    try:
        r = subprocess.run(cmd, cwd=ROOT, capture_output=True, text=True, timeout=180)
        out = r.stdout + r.stderr
    except subprocess.TimeoutExpired:
        return dict(file=src, addr=f"0x{addr:08X}", size=size, version=version,
                    status="TIMEOUT", diff_words=None)
    if "MATCH!" in out:
        status, diff = "MATCH", 0
    elif "SIZE_MISMATCH" in out:
        status, diff = "SIZE_MISMATCH", None
    elif "COMPILE FAILED" in out:
        status, diff = "COMPILE_FAILED", None
    elif "ASSEMBLE FAILED" in out:
        status, diff = "ASSEMBLE_FAILED", None
    elif "REJECTED" in out:
        status, diff = "REJECTED", None
    elif "MISMATCH" in out:
        status = "MISMATCH"
        diff = len(re.findall(r"^\s+offset 0x[0-9a-f]+:", out, re.M))
    else:
        status, diff = "ERROR", None
    return dict(file=src, addr=f"0x{addr:08X}", size=size, version=version,
                status=status, diff_words=diff)


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--clean-sample", type=int)
    ap.add_argument("--seed", type=int, default=42)
    ap.add_argument("--manifest")
    ap.add_argument("--files", nargs="*")
    ap.add_argument("--versions", default=",".join(VERSIONS))
    ap.add_argument("--label", required=True)
    ap.add_argument("--workers", type=int, default=10)
    args = ap.parse_args()

    versions = [v.strip() for v in args.versions.split(",") if v.strip()]
    jobs3 = []
    skipped = []
    if args.clean_sample:
        all_clean = parse_manifest(os.path.join(ROOT, "build", "audit", "clean.txt"))
        random.seed(args.seed)
        jobs3 = random.sample(all_clean, min(args.clean_sample, len(all_clean)))
    elif args.manifest:
        jobs3 = parse_manifest(args.manifest)
    elif args.files:
        sizes = load_symbol_sizes()
        jobs3, skipped = jobs_from_files(args.files, sizes)
    else:
        ap.error("need --clean-sample, --manifest, or --files")

    for p, why in skipped:
        print(f"  skip: {p} ({why})", file=sys.stderr)

    work = []
    rid = 0
    for src, addr, size in jobs3:
        for v in versions:
            work.append((src, addr, size, v, rid, args.label))
            rid += 1

    print(f"[{args.label}] {len(jobs3)} functions x {len(versions)} versions = {len(work)} verify runs")
    results = []
    done = 0
    with concurrent.futures.ThreadPoolExecutor(max_workers=args.workers) as ex:
        for res in ex.map(run_one, work):
            results.append(res)
            done += 1
            if done % 50 == 0:
                print(f"  ... {done}/{len(work)}")

    os.makedirs(VERTEST, exist_ok=True)
    out_path = os.path.join(VERTEST, f"results_{args.label}.json")
    with open(out_path, "w") as f:
        json.dump(results, f, indent=1)
    print(f"wrote {out_path}")

    # ---- summary ----
    by_file = {}
    for r in results:
        by_file.setdefault((r["file"], r["addr"]), {})[r["version"]] = r

    print("\n=== per-version totals ===")
    for v in versions:
        vs = [r for r in results if r["version"] == v]
        n_match = sum(1 for r in vs if r["status"] == "MATCH")
        n_mis = sum(1 for r in vs if r["status"] == "MISMATCH")
        n_other = len(vs) - n_match - n_mis
        print(f"  {v:>6}: MATCH {n_match:>4}  MISMATCH {n_mis:>4}  other {n_other:>4}")

    base = versions[0]
    print(f"\n=== functions whose result differs from {base} ===")
    any_flip = False
    for (f_, a_), per_v in sorted(by_file.items()):
        b = per_v.get(base)
        if not b:
            continue
        diffs = []
        for v in versions[1:]:
            r = per_v.get(v)
            if not r:
                continue
            if r["status"] != b["status"] or (
                r["status"] == "MISMATCH" and r["diff_words"] != b["diff_words"]):
                diffs.append(f"{v}={r['status']}({r['diff_words']})")
        if diffs:
            any_flip = True
            print(f"  {a_} {os.path.basename(f_)}: {base}={b['status']}({b['diff_words']}) | " + " ".join(diffs))
    if not any_flip:
        print("  (none — all versions agree on every function)")


if __name__ == "__main__":
    main()
