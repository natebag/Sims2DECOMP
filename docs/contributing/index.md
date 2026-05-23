# How to Help

The project hit 100% byte-match in a marathon session. The next phase — stub-to-real-C++ conversion — is open work that benefits enormously from contributors. Here's where to start.

## Quick start

1. **Clone the repo**: `git clone https://github.com/natebag/Sims2DECOMP`
2. **Set up the toolchain**: devkitPPC + Python 3.10+ + Ninja. See [Methodology](../methodology/index.md) for full setup notes.
3. **Run the build**: `python configure.py && ninja report` — confirms your environment can regenerate `report.json` and gives you the current baseline.
4. **Pick a class** from the [Subsystem Map](subsystems.md).

## Workflow per conversion

1. **Check virgin status**: `find src/matched -name "match*<ADDR>*.cpp" | grep -v agent/` — if empty, the address is metric-moving (+1 semantic-ratio gain). If non-empty, the conversion is polish (still valuable; just no dashboard movement).
2. **Look up the class layout**: check `include/types/*.h` for canonical class definitions written by TypeArch during S17.
3. **Write the C++**: in the appropriate `src/matched/<class>/match_0xADDR_<method>.cpp`. Express the function as readable C++ — declare the class, type the parameters, use real symbol names.
4. **Verify**: `tools/verify_match.sh src/matched/<class>/match_0xADDR_<method>.cpp 0xADDR <size>` — must report **MATCH**.
5. **Commit with explicit paths**: `git commit --only src/matched/<class>/<file>.cpp -m "convert(<class>): <method> N B semantic"`
6. **Push**: `git push origin main` — pre-commit hook re-verifies, decomp.dev picks up the new metric.

## What NOT to do

- ❌ Don't use `git add -u` / `git add .` / `git commit -a` — wildcard staging silently sweeps in-flight changes from other contributors. Always `--only <explicit paths>`.
- ❌ Don't use `--no-verify`. The hook is the safety net.
- ❌ Don't promote a stub from `agent/` to a class directory without converting the body. That's polish (valid!) but report it honestly — semantic-ratio doesn't move.
- ❌ Don't speculate on class layouts. Add fields only when you have at least 2 access patterns confirming the offset.

## Useful references

- [**Tooling Guide**](tooling.md) — what each tool in `tools/` does
- [**Subsystem Map**](subsystems.md) — what's done, what's open, where to plug in
- [**Technique Library**](../story/techniques.md) — 18+ matching techniques from the marathon

## Got questions?

Open a discussion or issue on the [repo](https://github.com/natebag/Sims2DECOMP). The marathon documented enough methodology that most contributors can self-serve, but novel walls are interesting — flag them.
