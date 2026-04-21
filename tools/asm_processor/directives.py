"""Parser for // ASMPROC_* pragma comments embedded in C++ source.

Syntax (keyword args only — matches SonnetWorker2's mutator contract):

    // ASMPROC_<name>: key=val key=val ...
    // ASMPROC_<name> key=val key=val ...    (colon optional)

Examples:
    // ASMPROC_swap_adj: a=andi. b=lfs which=first
    // ASMPROC_force_reg: match=lfs f0, from_reg=f0 to_reg=f13 occurrence=0
    // ASMPROC_nop_before: match=stw occurrence=0

Mutator names are lowercase_snake_case and must match a NAME registered in
tools/asm_processor/mutators/__init__.py REGISTRY.
"""
from __future__ import annotations

import re
from dataclasses import dataclass, field


DIRECTIVE_RE = re.compile(
    r"^\s*//\s*ASMPROC_(?P<name>[A-Za-z][A-Za-z0-9_]*)\s*:?\s*(?P<body>.*?)\s*$"
)


@dataclass
class Directive:
    name: str
    args: dict = field(default_factory=dict)
    lineno: int = 0
    raw: str = ""

    def __str__(self) -> str:
        kv = " ".join(f"{k}={v}" for k, v in self.args.items())
        return f"ASMPROC_{self.name}: {kv}" if kv else f"ASMPROC_{self.name}"


def _split_body(body: str) -> dict:
    body = body.strip()
    if not body:
        return {}
    args: dict = {}
    for tok in re.split(r"\s+", body):
        tok = tok.rstrip(",")
        if not tok:
            continue
        if "=" not in tok:
            raise ValueError(
                f"ASMPROC directive args must be key=val form (got token {tok!r})"
            )
        k, v = tok.split("=", 1)
        args[k.strip()] = v.strip()
    return args


def parse_directives(cpp_text: str) -> list[Directive]:
    out: list[Directive] = []
    for i, line in enumerate(cpp_text.splitlines(), start=1):
        m = DIRECTIVE_RE.match(line)
        if not m:
            continue
        try:
            args = _split_body(m.group("body"))
        except ValueError as exc:
            raise ValueError(f"line {i}: {exc}") from None
        out.append(
            Directive(
                name=m.group("name"),
                args=args,
                lineno=i,
                raw=line.strip(),
            )
        )
    return out


def strip_directives(cpp_text: str) -> str:
    kept = []
    for line in cpp_text.splitlines(keepends=True):
        if DIRECTIVE_RE.match(line):
            continue
        kept.append(line)
    return "".join(kept)


if __name__ == "__main__":
    import sys
    with open(sys.argv[1], encoding="utf-8") as f:
        text = f.read()
    for d in parse_directives(text):
        print(f"line {d.lineno}: {d}")
