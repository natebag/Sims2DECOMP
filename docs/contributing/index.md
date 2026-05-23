# Contributing

The repo is past 100% byte-match. Open work falls into two pillars:

- **Stub-to-real-C++ conversion** — turn `ASMPROC inject_before` byte-equivalent stubs into hand-written C++. Tracked via the [hand-written C++ ratio](../status/semantic-recovery.md).
- **Data section coverage** — convert vtables, string tables, and initialized globals into matching C++ source. Tracked via the [data section metric](../status/index.md#data-section-byte-match).

## Quick start

1. Clone the repo and set up the toolchain. See [Methodology](../methodology/index.md).
2. Run `python configure.py && ninja report` to confirm the environment and produce a baseline `report.json`.
3. Pick a function or class from the [Subsystem Map](subsystems.md).

## Workflow per conversion

1. **Check the address class.** Inject-only addresses move the hand-written ratio when converted; addresses already hand-written somewhere don't (the conversion is still valuable for code quality).

       find src/matched -name "match*<ADDR>*.cpp" | grep -v agent/

   Empty result → inject-only → metric-moving.

2. **Look up the class layout** in `include/types/*.h` (canonical) or `include/classes/*.h` (older).

3. **Write the C++.** File path: `src/matched/<class>/match_0x<ADDR>_<method>.cpp`. Declare the class, type the parameters, use real symbol names.

4. **Verify.**

       tools/verify_match.sh src/matched/<class>/<file>.cpp 0xADDR <size>

   Must print `MATCH`.

5. **Commit with explicit paths.**

       git commit --only src/matched/<class>/<file>.cpp -m "convert(<class>): <method> <size>B"

6. **Push.** The pre-commit hook re-verifies and regenerates `report.json`.

## Hard rules

- `tools/verify_match.sh` passes for every commit that adds or modifies a `.cpp` file under `src/matched/`. The pre-commit hook enforces this.
- `matched_code_percent` does not drop below 100.00%. Any commit that drops the percent is reverted.
- `git commit --only <explicit paths>` only. Never `git add -u`, `git add .`, or `git commit -a`. Wildcard staging can sweep up other contributors' in-flight changes in this shared repo.
- No `__asm__`, `.byte`, or `.long` byte-injection patterns. ASMPROC `inject_before` / `replace_insn` / `swap_adj` / `gpr_relabel` / `force_reg_at_pos` directives only.
- `SKIP_VERIFY=1` is allowed only for commits that are purely `git rm` of duplicate match files. The justification must appear in the commit message and the commit must be flagged for post-hoc canonical-metric verification.
- Class layouts in `include/types/` are added only with evidence: every documented offset must trace to at least two accessor functions.

## Reference

- [Tooling Guide](tooling.md) — every script in `tools/` documented
- [Subsystem Map](subsystems.md) — directory-by-directory status
- [Techniques](../techniques.md) — matching technique reference
