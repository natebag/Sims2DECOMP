"""Render the pass/fail matrix for the asm_processor wall harness.

Pure rendering layer — consumes the result records produced by `test_walls.py`
and prints a human-readable matrix plus a one-line summary suitable for
grepping in CI logs (`ASM_PROCESSOR_SUMMARY:`).
"""
from __future__ import annotations

from dataclasses import dataclass
from typing import Iterable


# Terminal width target for the matrix. Keep modest — Cog + pager-friendly.
COL_WIDTHS = {
    "addr": 12,
    "cat": 4,
    "size": 6,
    "expected": 10,
    "observed": 16,
    "notes": 48,
}


@dataclass
class WallResult:
    addr: str
    size: int
    category: int
    symbol: str
    expected: str          # from manifest: match / improve / park
    observed: str          # match / mismatch / skip / error
    notes: str             # short human-readable status (e.g. mutator skipped)

    @property
    def passed(self) -> bool:
        """Does the harness treat this run as PASS?

        - expected=match      ⇒ pass iff observed=match
        - expected=improve    ⇒ pass iff observed in {match, improve}
        - expected=park       ⇒ always pass (harness records, never fails park)
        """
        if self.expected == "match":
            return self.observed == "match"
        if self.expected == "improve":
            return self.observed in ("match", "improve")
        if self.expected == "park":
            return True
        return False


def _fmt_row(cells: dict[str, str]) -> str:
    out = []
    for key, width in COL_WIDTHS.items():
        cell = cells.get(key, "")
        if len(cell) > width:
            cell = cell[: width - 1] + "…"
        out.append(cell.ljust(width))
    return "  ".join(out)


def render(results: Iterable[WallResult]) -> str:
    lines = []
    header = {
        "addr": "ADDR",
        "cat": "CAT",
        "size": "SIZE",
        "expected": "EXPECT",
        "observed": "OBSERVED",
        "notes": "NOTES",
    }
    lines.append(_fmt_row(header))
    lines.append("-" * (sum(COL_WIDTHS.values()) + 2 * (len(COL_WIDTHS) - 1)))

    totals = {"match": 0, "mismatch": 0, "skip": 0, "error": 0}
    fails = 0
    results_list = list(results)
    for r in results_list:
        totals[r.observed] = totals.get(r.observed, 0) + 1
        if not r.passed:
            fails += 1
        lines.append(_fmt_row({
            "addr": r.addr,
            "cat": str(r.category),
            "size": str(r.size),
            "expected": r.expected,
            "observed": r.observed,
            "notes": r.notes,
        }))
    lines.append("")
    lines.append(
        f"ASM_PROCESSOR_SUMMARY: walls={len(results_list)} "
        f"match={totals['match']} mismatch={totals['mismatch']} "
        f"skip={totals['skip']} error={totals['error']} fails={fails}"
    )
    return "\n".join(lines) + "\n"
