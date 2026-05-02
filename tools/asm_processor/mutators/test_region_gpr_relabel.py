"""Smoke tests for region_gpr_relabel mutator.

Standalone — run with: `python -m tools.asm_processor.mutators.test_region_gpr_relabel`

Covers the 8 cases locked with MainGuy:
  1. Kill-point dest-only rename on start_anchor (start_mode='at')
  2. Full-region rename on lines strictly between anchors
  3. End-anchor inclusion (end_mode='at') vs exclusion (end_mode='before')
  4. NON_GPR_INT_OPCODES skip (control-flow lines untouched)
  5. Unique-anchor enforcement (refuse 0 or >1 matches without occurrence_*)
  6. Occurrence-index handling (explicit override allows non-unique anchor)
  7. In-region liveness refusal (TO reg not in FROM, src-before-dst)
  8. Post-region liveness refusal (SA-1: FROM reg src after end without redef)
"""
from __future__ import annotations

import sys
from pathlib import Path

REPO_ROOT = Path(__file__).resolve().parents[3]
if str(REPO_ROOT) not in sys.path:
    sys.path.insert(0, str(REPO_ROOT))

from tools.asm_processor.mutators import NoApplicableSite, region_gpr_relabel


def _normalize(s: str) -> list[str]:
    """Strip both ends + collapse run-of-spaces so tests don't care about
    indent/separator formatting (relabel_line emits ', ' but originals use ',').
    """
    out = []
    for ln in s.strip("\n").splitlines():
        t = ln.strip()
        # Collapse internal whitespace runs.
        t = " ".join(t.split())
        # Drop space after comma so tests can compare against tight `r0,0,4` form.
        t = t.replace(", ", ",")
        out.append(t)
    return out


def _run(asm: str, args: dict) -> list[str]:
    return _normalize(region_gpr_relabel.apply(asm, args))


def case_1_kill_point_dest_only() -> None:
    """start_mode='at' renames ONLY dest of start_anchor, not its sources."""
    asm = (
        "    srawi 0,0,2\n"   # dest r0, sources r0,2 — only dest renamed
        "    add 0,0,4\n"      # full rename: r0->r3
        "    mulli 3,0,20\n"   # full rename: r0->r3
    )
    out = _run(asm, {
        "start_anchor": "srawi 0,0,2",
        "end_anchor": "mulli 3,0,20",
        "rename": "0:3",
    })
    assert out[0] == "srawi 3,0,2", f"start_anchor dest-only: got {out[0]!r}"
    assert out[1] == "add 3,3,4", f"mid-region full: got {out[1]!r}"
    assert out[2] == "mulli 3,3,20", f"end_anchor full: got {out[2]!r}"
    print("OK  case_1_kill_point_dest_only")


def case_2_full_region_rename() -> None:
    """Lines strictly between anchors: every GPR token renamed."""
    asm = (
        "    srawi 0,0,2\n"
        "    add 0,0,4\n"
        "    divw 9,0,11\n"
        "    mullw 9,9,11\n"
        "    subf. 0,9,0\n"
        "    mulli 3,0,20\n"
    )
    out = _run(asm, {
        "start_anchor": "srawi 0,0,2",
        "end_anchor": "mulli 3,0,20",
        "rename": "0:3,9:0",
    })
    # Mid-region: simultaneous (0->3, 9->0).
    assert out[1] == "add 3,3,4"
    assert out[2] == "divw 0,3,11"
    assert out[3] == "mullw 0,0,11"
    assert out[4] == "subf. 3,0,3"
    print("OK  case_2_full_region_rename")


def case_3_end_anchor_modes() -> None:
    """end_mode='at' renames end line; 'before' leaves it untouched.

    Note: end_mode='before' means the end_anchor IS the post-region, so it
    keeps its original (now-renamed-away) register references — that's
    intentional, post-region liveness check normally catches this. This test
    uses unsafe_clobber to isolate the end_mode plumbing.
    """
    asm_at = (
        "    srawi 0,0,2\n"
        "    add 0,0,4\n"
        "    mulli 3,0,20\n"
    )
    out_at = _run(asm_at, {
        "start_anchor": "srawi 0,0,2",
        "end_anchor": "mulli 3,0,20",
        "rename": "0:3",
        "end_mode": "at",
    })
    assert out_at[2] == "mulli 3,3,20"

    out_before = _run(asm_at, {
        "start_anchor": "srawi 0,0,2",
        "end_anchor": "mulli 3,0,20",
        "rename": "0:3",
        "end_mode": "before",
        "unsafe_clobber": True,  # mulli's r0 is now stale post-region
    })
    assert out_before[2] == "mulli 3,0,20", f"end_mode=before: got {out_before[2]!r}"
    print("OK  case_3_end_anchor_modes")


def case_4_non_gpr_skip() -> None:
    """Control-flow lines (bge, blr) untouched; labels untouched."""
    asm = (
        "    srawi 0,0,2\n"
        "    add 0,0,4\n"
        "    bge 0x44\n"        # branch — NON_GPR_INT
        ".L7:\n"                 # label — not an instruction
        "    mulli 3,0,20\n"
    )
    out = _run(asm, {
        "start_anchor": "srawi 0,0,2",
        "end_anchor": "mulli 3,0,20",
        "rename": "0:3",
    })
    assert out[2] == "bge 0x44", f"branch untouched: got {out[2]!r}"
    assert out[3] == ".L7:", f"label untouched: got {out[3]!r}"
    print("OK  case_4_non_gpr_skip")


def case_5_unique_anchor_enforcement() -> None:
    """0 matches OR >1 matches without occurrence_* => NoApplicableSite."""
    asm_zero = "    add 0,0,4\n    blr\n"
    try:
        region_gpr_relabel.apply(asm_zero, {
            "start_anchor": "srawi 0,0,2",
            "end_anchor": "blr",
            "rename": "0:3",
        })
        raise AssertionError("expected NoApplicableSite for 0 matches")
    except NoApplicableSite:
        pass

    asm_dup = (
        "    add 0,0,4\n"
        "    add 0,0,4\n"        # duplicate start_anchor candidate
        "    add 0,0,4\n"
        "    mulli 3,0,20\n"
    )
    try:
        region_gpr_relabel.apply(asm_dup, {
            "start_anchor": "add 0,0,4",
            "end_anchor": "mulli 3,0,20",
            "rename": "0:3",
        })
        raise AssertionError("expected NoApplicableSite for >1 matches")
    except NoApplicableSite:
        pass
    print("OK  case_5_unique_anchor_enforcement")


def case_6_occurrence_override() -> None:
    """occurrence_start lets the caller pick a non-unique anchor."""
    asm = (
        "    add 0,0,4\n"
        "    srawi 0,0,2\n"     # 1st occurrence
        "    add 0,0,4\n"
        "    srawi 0,0,2\n"     # 2nd occurrence — pick this
        "    mulli 3,0,20\n"
    )
    out = _run(asm, {
        "start_anchor": "srawi 0,0,2",
        "end_anchor": "mulli 3,0,20",
        "rename": "0:3",
        "occurrence_start": 1,  # 0-indexed: 1 = second match
    })
    # 1st srawi untouched (idx 1), 2nd is start_anchor (idx 3).
    assert out[1] == "srawi 0,0,2", f"1st srawi untouched: got {out[1]!r}"
    assert out[3] == "srawi 3,0,2", f"2nd srawi dest-only: got {out[3]!r}"
    assert out[4] == "mulli 3,3,20"
    print("OK  case_6_occurrence_override")


def case_7_inregion_clobber_refuse() -> None:
    """TO reg (not in FROM) used as src before dst inside region => refuse."""
    asm = (
        "    srawi 0,0,2\n"
        "    add 4,5,6\n"        # uses r6 as src — but rename is 0:6, r6 NOT in FROM
        "    add 6,0,4\n"        # r6 is dest later — but src-first-wins
        "    mulli 3,0,20\n"
    )
    try:
        region_gpr_relabel.apply(asm, {
            "start_anchor": "srawi 0,0,2",
            "end_anchor": "mulli 3,0,20",
            "rename": "0:6",
        })
        raise AssertionError("expected NoApplicableSite for in-region clobber")
    except NoApplicableSite as exc:
        assert "live-in clobber" in str(exc) or "r6" in str(exc), str(exc)

    # Bypass: unsafe_clobber=true should let it through.
    out_lines = _run(asm, {
        "start_anchor": "srawi 0,0,2",
        "end_anchor": "mulli 3,0,20",
        "rename": "0:6",
        "unsafe_clobber": True,
    })
    assert out_lines[0] == "srawi 6,0,2", f"unsafe bypass: got {out_lines[0]!r}"
    print("OK  case_7_inregion_clobber_refuse")


def case_8_postregion_clobber_refuse() -> None:
    """FROM reg used as src after end_anchor without redef => refuse (SA-1)."""
    asm = (
        "    srawi 0,0,2\n"
        "    add 0,0,4\n"
        "    mulli 3,0,20\n"
        "    add 5,0,6\n"        # uses r0 as src AFTER end_anchor — clobber
        "    blr\n"
    )
    try:
        region_gpr_relabel.apply(asm, {
            "start_anchor": "srawi 0,0,2",
            "end_anchor": "mulli 3,0,20",
            "rename": "0:3",
        })
        raise AssertionError("expected NoApplicableSite for post-region clobber")
    except NoApplicableSite as exc:
        assert "post-region clobber" in str(exc), str(exc)

    # Safe variant: blr immediately ends the function (canonical primary shape).
    asm_safe = (
        "    srawi 0,0,2\n"
        "    add 0,0,4\n"
        "    mulli 3,0,20\n"
        "    blr\n"
    )
    out_lines = _run(asm_safe, {
        "start_anchor": "srawi 0,0,2",
        "end_anchor": "mulli 3,0,20",
        "rename": "0:3",
    })
    assert out_lines[0] == "srawi 3,0,2", f"safe path dest-only: got {out_lines[0]!r}"
    print("OK  case_8_postregion_clobber_refuse")


def case_extra_arg_validation() -> None:
    """Author-error fail-loud: missing args, bad mode, bad opcode, single-line."""
    base_asm = "    srawi 0,0,2\n    mulli 3,0,20\n"

    # Missing args
    for missing in ("start_anchor", "end_anchor", "rename"):
        args = {"start_anchor": "srawi 0,0,2", "end_anchor": "mulli 3,0,20", "rename": "0:3"}
        del args[missing]
        try:
            region_gpr_relabel.apply(base_asm, args)
            raise AssertionError(f"expected ValueError for missing {missing}")
        except ValueError:
            pass

    # Bad mode
    try:
        region_gpr_relabel.apply(base_asm, {
            "start_anchor": "srawi 0,0,2", "end_anchor": "mulli 3,0,20",
            "rename": "0:3", "start_mode": "include",
        })
        raise AssertionError("expected ValueError for bad start_mode")
    except ValueError:
        pass

    # start_mode='at' on non-accept-list opcode (stb)
    asm_stb = "    stb 0,0(3)\n    mulli 3,0,20\n"
    try:
        region_gpr_relabel.apply(asm_stb, {
            "start_anchor": "stb 0,0(3)", "end_anchor": "mulli 3,0,20",
            "rename": "0:3",
        })
        raise AssertionError("expected ValueError for store opcode at start_mode=at")
    except ValueError as exc:
        assert "DEST_AT_POS_0" in str(exc) or "GPR dest at pos 0" in str(exc), str(exc)

    # Single-line region
    asm_single = "    srawi 0,0,2\n    blr\n"
    try:
        region_gpr_relabel.apply(asm_single, {
            "start_anchor": "srawi 0,0,2", "end_anchor": "srawi 0,0,2",
            "rename": "0:3",
        })
        raise AssertionError("expected ValueError for single-line region")
    except ValueError as exc:
        assert "single-line" in str(exc), str(exc)
    print("OK  case_extra_arg_validation")


def case_canonical_primary_AptActionQueueC() -> None:
    """Canonical primary collapse: 7-mismatch register-coloring -> single directive.

    Mirrors the `getdeque_v2.cpp` cc1plus output (block layout matches DOL after
    the v2 polarity-flip). Validates that `0:3,9:0` produces the DOL register
    coloring across the kill-point + tail.
    """
    asm = (
        "    subf 0,10,0\n"     # 0x14 — outside region (before start_anchor)
        "    mullw 0,0,9\n"      # 0x18 — outside region
        "    srawi 0,0,2\n"      # 0x1c — START kill point: dest r0->r3
        "    add 0,0,4\n"        # 0x20 — full: r0->r3
        "    divw 9,0,11\n"      # 0x24 — full: 9->0, 0->3
        "    mullw 9,9,11\n"     # 0x28 — full: 9->0
        "    subf. 0,9,0\n"      # 0x2c — full
        "    bge 0x44\n"         # 0x30 — branch, NON_GPR_INT skip
        "    add 3,0,11\n"       # 0x34 — full: 0->3
        "    mulli 3,3,20\n"     # 0x38 — outside (3->3 silent identity anyway)
        "    add 3,10,3\n"       # 0x3c
        "    blr\n"              # 0x40
        "    mulli 3,0,20\n"     # 0x44 — END: full: 0->3
        "    add 3,10,3\n"       # 0x48 — outside
        "    blr\n"              # 0x4c
    )
    out = _run(asm, {
        "start_anchor": "srawi 0,0,2",
        "end_anchor": "mulli 3,0,20",
        "rename": "0:3,9:0",
    })

    # Outside region (before start) untouched.
    assert out[0] == "subf 0,10,0"
    assert out[1] == "mullw 0,0,9"
    # Start anchor: dest only.
    assert out[2] == "srawi 3,0,2"
    # In-region full rename.
    assert out[3] == "add 3,3,4"
    assert out[4] == "divw 0,3,11"
    assert out[5] == "mullw 0,0,11"
    assert out[6] == "subf. 3,0,3"
    assert out[7] == "bge 0x44"
    assert out[8] == "add 3,3,11"
    # End anchor: full rename.
    assert out[12] == "mulli 3,3,20"
    # Outside region (after end) untouched.
    assert out[13] == "add 3,10,3"
    assert out[14] == "blr"
    print("OK  case_canonical_primary_AptActionQueueC")


def main() -> int:
    cases = [
        case_1_kill_point_dest_only,
        case_2_full_region_rename,
        case_3_end_anchor_modes,
        case_4_non_gpr_skip,
        case_5_unique_anchor_enforcement,
        case_6_occurrence_override,
        case_7_inregion_clobber_refuse,
        case_8_postregion_clobber_refuse,
        case_extra_arg_validation,
        case_canonical_primary_AptActionQueueC,
    ]
    failed = 0
    for c in cases:
        try:
            c()
        except Exception as exc:
            failed += 1
            print(f"FAIL {c.__name__}: {exc}")
    print(f"\n{len(cases) - failed}/{len(cases)} passed")
    return 0 if failed == 0 else 1


if __name__ == "__main__":
    sys.exit(main())
