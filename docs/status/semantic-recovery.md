# Semantic recovery

## What this means

A function is **byte-matched** when its compiled output equals the original DOL bytes. That is the metric the public dashboard reports.

A function is **hand-written** when, on top of being byte-matched, its C++ source is the actual code: declares its class, takes typed parameters, expresses program logic — rather than baking in raw PowerPC bytes via `ASMPROC inject_before`. This is the metric that matters for port-readiness.

Byte-match is the floor. Hand-written C++ is the open work.

## Current numbers

- Matchable-function hand-written ratio: **~57%** (10,468 / 18,458)
- Remaining inject-only addresses: **9,233** — functions that byte-match but read as wrapped bytes

## Classifier note

The internal classifier counts **unique addresses**, deduped across the whole `src/matched/` tree. Implications:

- Promoting a file from `src/matched/agent/match_0xADDR_method.cpp` to a canonical class directory produces no change in the ratio if the address was already counted as hand-written elsewhere. The work is still valuable for code quality, just not for this metric.
- Converting an `inject_only` address — one that has no hand-written file anywhere in the tree — increases the ratio by one.

To find inject-only addresses for net new conversion work:

```bash
find src/matched -name "match*<ADDR>*.cpp" | grep -v agent/
# empty result → address is inject-only, conversion will move the ratio
# non-empty   → polish work, ratio stays flat
```

## Where to focus

Open conversion territory by lane (see [Subsystem map](../contributing/subsystems.md)):

- `cXObjectImpl` methods compiled in the `objectsim` translation unit (~91 KB of complex methods)
- `cXPersonImpl` virgin pool (~69 KB remaining after subtracting pre-existing semantic dirs)
- `SAnimator2` complex stubs (123 functions, 100 B+ each)
- `EAnimController` complex stubs (81 functions, 100 B+ each)
- `xrouting` residual patterns (SDA-relative, r9-relative, callee-saved, tail-call)

The [Techniques page](../techniques.md) catalogs the recipes that close these.
