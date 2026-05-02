"""Smoke tests for force_reg_at_pos.

Run as a script: python -m tools.asm_processor.mutators.test_force_reg_at_pos
or directly: python tools/asm_processor/mutators/test_force_reg_at_pos.py

Coverage:
- canonical FamilyImpl shape (subf 0,11,0 → subf 0,11,8 at pos=2)
- pos=0 rename (rt position)
- pos=1 rename (middle operand)
- memory-form operand rename inside parens (lwz r3, 4(r9))
- r-prefix preservation (force_reg_at_pos preserves the prefix per token)
- multiple `match` lines + occurrence selector
- pos out of range → NoApplicableSite
- from_reg not present at pos → NoApplicableSite
- match substring not found → NoApplicableSite
- author errors: missing args, identity rename, bad pos, bad reg
- prove non-target operands are PRESERVED when same register name appears at multiple positions

The asymmetric-rename property (rt stays, ra changes) is the entire reason
this mutator exists — every test that exercises it asserts BOTH the change
and the preservation.
"""
from __future__ import annotations

import os
import sys

# Allow running this file directly without installing the package.
HERE = os.path.dirname(os.path.abspath(__file__))
ROOT = os.path.abspath(os.path.join(HERE, "..", "..", ".."))
if ROOT not in sys.path:
    sys.path.insert(0, ROOT)

from tools.asm_processor.mutators import NoApplicableSite, force_reg_at_pos


def _normalize(text: str) -> str:
    """Normalise asm text for comparison: strip ends, collapse whitespace,
    drop ', ' → ',' so layout differences in the rebuild don't false-fail
    the assertions. Mirrors test_region_gpr_relabel's normaliser."""
    out_lines = []
    for line in text.splitlines():
        line = line.strip()
        line = " ".join(line.split())
        line = line.replace(", ", ",")
        out_lines.append(line)
    return "\n".join(out_lines)


def _run(asm: str, args: dict) -> str:
    return _normalize(force_reg_at_pos.apply(asm, args))


def case_canonical_familyimpl():
    """Canonical FamilyImpl shape: subf 0,11,0 → subf 0,11,8 at pos=2.

    rt (pos 0) is r0 and MUST stay r0.
    ra (pos 2) is r0 and MUST become r8.
    """
    asm = "\tsubf 0,11,0\n\tblr\n"
    out = _run(asm, {
        "match": "subf 0,11,0",
        "pos": 2,
        "from_reg": 0,
        "to_reg": 8,
    })
    assert "subf 0,11,8" in out, f"expected ra rename, got: {out!r}"
    assert "subf 0,11,0" not in out, f"expected pre-rename line gone, got: {out!r}"
    print("PASS case_canonical_familyimpl")


def case_pos_0_rt_rename():
    """pos=0 renames rt only; rb/ra with the same reg name must stay."""
    asm = "\tsubf 0,11,0\n\tblr\n"
    out = _run(asm, {
        "match": "subf 0,11,0",
        "pos": 0,
        "from_reg": 0,
        "to_reg": 8,
    })
    assert "subf 8,11,0" in out, f"expected rt rename only, got: {out!r}"
    print("PASS case_pos_0_rt_rename")


def case_pos_1_middle_rename():
    """pos=1 renames the middle operand."""
    asm = "\tand 3,4,5\n\tblr\n"
    out = _run(asm, {
        "match": "and 3,4,5",
        "pos": 1,
        "from_reg": 4,
        "to_reg": 7,
    })
    assert "and 3,7,5" in out, f"expected pos=1 rename, got: {out!r}"
    print("PASS case_pos_1_middle_rename")


def case_memory_form_inside_parens():
    """For `lwz r3, 4(r9)` style operands, pos=1 = the whole `4(r9)` chunk.
    Renaming r9 → r10 should produce `4(r10)`."""
    asm = "\tlwz r3, 4(r9)\n\tblr\n"
    out = _run(asm, {
        "match": "lwz r3,",
        "pos": 1,
        "from_reg": 9,
        "to_reg": 10,
    })
    assert "lwz r3,4(r10)" in out, f"expected memory-form rename, got: {out!r}"
    print("PASS case_memory_form_inside_parens")


def case_r_prefix_preserved():
    """Bare-numeric tokens stay bare; `rN` tokens stay `rN`."""
    asm_bare = "\tadd 3,4,5\n\tblr\n"
    out_bare = _run(asm_bare, {
        "match": "add 3,4,5",
        "pos": 2,
        "from_reg": 5,
        "to_reg": 6,
    })
    assert "add 3,4,6" in out_bare, f"bare prefix lost: {out_bare!r}"

    asm_rN = "\tadd r3, r4, r5\n\tblr\n"
    out_rN = _run(asm_rN, {
        "match": "add r3",
        "pos": 2,
        "from_reg": 5,
        "to_reg": 6,
    })
    assert "add r3,r4,r6" in out_rN, f"r-prefix lost: {out_rN!r}"
    print("PASS case_r_prefix_preserved")


def case_occurrence_selector():
    """When `match` hits multiple lines, occurrence picks which one to rewrite."""
    asm = (
        "\tsubf 0,11,0\n"      # idx 0
        "\tmr 11,9\n"          # filler
        "\tsubf 0,11,0\n"      # idx 1
        "\tblr\n"
    )
    out0 = _run(asm, {
        "match": "subf 0,11,0",
        "pos": 2,
        "from_reg": 0,
        "to_reg": 8,
        "occurrence": 0,
    })
    out0_lines = out0.split("\n")
    assert out0_lines[0] == "subf 0,11,8", f"occ=0 should rewrite first, got: {out0_lines!r}"
    assert out0_lines[2] == "subf 0,11,0", f"occ=0 should leave second alone, got: {out0_lines!r}"

    out1 = _run(asm, {
        "match": "subf 0,11,0",
        "pos": 2,
        "from_reg": 0,
        "to_reg": 8,
        "occurrence": 1,
    })
    out1_lines = out1.split("\n")
    assert out1_lines[0] == "subf 0,11,0", f"occ=1 should leave first alone, got: {out1_lines!r}"
    assert out1_lines[2] == "subf 0,11,8", f"occ=1 should rewrite second, got: {out1_lines!r}"
    print("PASS case_occurrence_selector")


def case_pos_out_of_range_refuses():
    """pos beyond operand list → NoApplicableSite."""
    asm = "\tsubf 0,11,0\n\tblr\n"
    try:
        force_reg_at_pos.apply(asm, {
            "match": "subf 0,11,0",
            "pos": 5,
            "from_reg": 0,
            "to_reg": 8,
        })
    except NoApplicableSite as e:
        assert "out of range" in str(e), f"expected 'out of range', got: {e!s}"
        print("PASS case_pos_out_of_range_refuses")
        return
    raise AssertionError("expected NoApplicableSite for pos out of range")


def case_from_reg_not_at_pos_refuses():
    """If pos points at an operand that doesn't contain from_reg → NoApplicableSite."""
    asm = "\tsubf 0,11,0\n\tblr\n"
    try:
        force_reg_at_pos.apply(asm, {
            "match": "subf 0,11,0",
            "pos": 1,            # operand 1 is "11", not r0
            "from_reg": 0,
            "to_reg": 8,
        })
    except NoApplicableSite as e:
        assert "does not contain register" in str(e), f"got: {e!s}"
        print("PASS case_from_reg_not_at_pos_refuses")
        return
    raise AssertionError("expected NoApplicableSite when from_reg absent at pos")


def case_match_not_found_refuses():
    """match substring missing → NoApplicableSite."""
    asm = "\tblr\n"
    try:
        force_reg_at_pos.apply(asm, {
            "match": "subf 0,11,0",
            "pos": 2,
            "from_reg": 0,
            "to_reg": 8,
        })
    except NoApplicableSite as e:
        assert "no .s line contains" in str(e), f"got: {e!s}"
        print("PASS case_match_not_found_refuses")
        return
    raise AssertionError("expected NoApplicableSite when match missing")


def case_identity_rename_refuses():
    """from_reg == to_reg → ValueError (author error, not runtime skip)."""
    asm = "\tsubf 0,11,0\n\tblr\n"
    try:
        force_reg_at_pos.apply(asm, {
            "match": "subf 0,11,0",
            "pos": 2,
            "from_reg": 0,
            "to_reg": 0,
        })
    except ValueError as e:
        assert "must differ" in str(e), f"got: {e!s}"
        print("PASS case_identity_rename_refuses")
        return
    raise AssertionError("expected ValueError for identity rename")


def case_missing_args_refuses():
    """Missing required args → ValueError."""
    try:
        force_reg_at_pos.apply("\tblr\n", {"match": "blr"})
    except ValueError as e:
        assert "requires args" in str(e), f"got: {e!s}"
        print("PASS case_missing_args_refuses")
        return
    raise AssertionError("expected ValueError for missing args")


def case_bad_pos_refuses():
    """Negative or non-integer pos → ValueError."""
    asm = "\tsubf 0,11,0\n\tblr\n"
    try:
        force_reg_at_pos.apply(asm, {
            "match": "subf 0,11,0",
            "pos": -1,
            "from_reg": 0,
            "to_reg": 8,
        })
    except ValueError as e:
        assert "non-negative" in str(e), f"got: {e!s}"
    else:
        raise AssertionError("expected ValueError for negative pos")

    try:
        force_reg_at_pos.apply(asm, {
            "match": "subf 0,11,0",
            "pos": "abc",
            "from_reg": 0,
            "to_reg": 8,
        })
    except ValueError as e:
        assert "must be an integer" in str(e), f"got: {e!s}"
        print("PASS case_bad_pos_refuses")
        return
    raise AssertionError("expected ValueError for non-integer pos")


def case_word_boundary_regex_safety():
    """`r1` must NOT match `r10`/`r11`/`r12` — verify boundary handling.
    Operand `r10` at pos=2; rename from_reg=1 should refuse (no r1 here)."""
    asm = "\tadd r3, r10, r10\n\tblr\n"
    try:
        force_reg_at_pos.apply(asm, {
            "match": "add r3",
            "pos": 2,
            "from_reg": 1,
            "to_reg": 5,
        })
    except NoApplicableSite as e:
        assert "does not contain register" in str(e), f"got: {e!s}"
        print("PASS case_word_boundary_regex_safety")
        return
    raise AssertionError("r1 should NOT match r10 token")


def main():
    cases = [
        case_canonical_familyimpl,
        case_pos_0_rt_rename,
        case_pos_1_middle_rename,
        case_memory_form_inside_parens,
        case_r_prefix_preserved,
        case_occurrence_selector,
        case_pos_out_of_range_refuses,
        case_from_reg_not_at_pos_refuses,
        case_match_not_found_refuses,
        case_identity_rename_refuses,
        case_missing_args_refuses,
        case_bad_pos_refuses,
        case_word_boundary_regex_safety,
    ]
    for c in cases:
        c()
    print(f"\n{len(cases)}/{len(cases)} smoke tests passed.")


if __name__ == "__main__":
    main()
