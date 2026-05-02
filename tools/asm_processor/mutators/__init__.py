"""Mutator plugins for asm_processor (SonnetWorker2, S13 Track I).

Each mutator module exposes:

    NAME: str
        Stable short name used in manifest pipelines and result labels.

    def apply(asm_text: str, args: dict) -> str:
        Transform the cc1plus-emitted .s text. Returns the mutated .s text.
        Must raise NoApplicableSite if the asm does not contain what the
        mutator expects — the harness treats that as a skip, not a failure.

Mutators are DETERMINISTIC for a given (asm_text, args). Any sampling lives
in asm_processor.py's permuter driver.
"""
from __future__ import annotations


class NoApplicableSite(Exception):
    """Raised by a mutator when the .s has no site matching its spec."""


from . import anti_tail_merge, force_alias_base, force_reg, fp_relabel, gpr_relabel, insert_mr, nop_before, region_gpr_relabel, remove_mr, swap_adj, swap_cr_field, swap_operands  # noqa: E402 (registry below)

REGISTRY = {m.NAME: m for m in (swap_adj, force_reg, nop_before, fp_relabel, gpr_relabel, insert_mr, remove_mr, swap_cr_field, swap_operands, force_alias_base, anti_tail_merge, region_gpr_relabel)}


def get(name: str):
    """Look up a mutator by name. Raises KeyError listing known names if missing."""
    try:
        return REGISTRY[name]
    except KeyError as exc:
        raise KeyError(
            f"unknown mutator {name!r}; known: {sorted(REGISTRY)}"
        ) from exc
