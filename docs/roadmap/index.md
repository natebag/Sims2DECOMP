# Roadmap

## Completed

- `.text` byte-match — 4,145,724 / 4,145,724 bytes (100.00%)
- All 18,458 functions matched
- Data section tracking instrumented (`.ctors` / `.dtors` / `.rodata` / `.data` / `.sdata` / `.sdata2`)
- 13 canonical class layout headers in `include/types/`
- `tools/inject_matches.py` subdirectory scanning + multi-format annotation regex
- Documentation site (this site)

## Open work

### Stub-to-real-C++ conversion

About 43% of matched functions are byte-equivalent stubs produced by `ASMPROC inject_before` rather than hand-written C++. Converting these is the path to a readable, modifiable, retargetable source tree.

Largest open areas:

- `cXObjectImpl` methods compiled in the `objectsim` TU (~91 KB)
- `SAnimator2` complex stubs (123 functions, 100 B+ each)
- `EAnimController` complex stubs (81 functions, 100 B+ each)
- `cXPersonImpl` virgin pool (~69 KB across ~86 addresses)
- `xrouting` residual patterns

### Data section coverage

Currently 9.21% byte-matched. Approaching this systematically:

| Section | Current | Approach |
|---------|---------|----------|
| `.dtors` (360 B) | 0.00% | Declare the static destructor table |
| `.ctors` (644 B) | 2.02% | Declare the static constructor table |
| `.rodata` (362 KB) | 16.92% | Vtable conversion per class; string table consolidation |
| `.data` (306 KB) | 0.25% | Initialized globals, lookup tables, game-state structs |
| `.sdata` (7.5 KB) | 7.97% | r13-relative globals |
| `.sdata2` (4 KB) | 0.70% | r2-relative globals |

### Tooling

- Per-agent git worktrees — would eliminate the shared-`cwd` cross-contamination class observed when multiple contributors stage files concurrently
- Cross-canonical-dir cleanup — ~22 remaining `targets_s2c` ↔ `famtarget` directory duplicates from before the canonical-dir convention settled
- `EVec3` ABI reconciliation — the codebase uses both int-EVec3 (`ISimsObjectModel`) and float-EVec3 (`SAnimator2`, `EAnimController`) variants; consolidate into `include/shared-types/`

### Distant goals

- PC port — requires bringing the hand-written-C++ ratio above the major game-logic subsystems before it's practical
- Asset format documentation — `.arc`, `.NGH`, `.tpl` formats
- Modding surface — once the codebase is readable enough that authors can navigate it
