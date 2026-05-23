# Subsystem Map

Directory-by-directory status across `src/matched/`. Lists what's hand-written C++, what's still byte-equivalent stubs, and where help is most welcome.

## Legend

| Symbol | Meaning |
|--------|---------|
| ✅ | Substantially hand-written (>50% of matched functions are real C++) |
| 🟡 | Partial coverage — mostly stubs with scattered hand-written work |
| 🔴 | Byte-matched but ~0% hand-written |
| 📦 | SDK / middleware — out of scope for stub-to-real-C++ conversion |

## Object family — 🟡 partial

- `cXObject` (wrapper class): hand-written; holder pattern documented in `include/types/cXObject.h`
- `cXObjectImpl` (cousin class, the real impl): RTTI accessors + Construct/Destruct families converted. Primary field `m_objectTypeKey @ 0x488` documented (17 read sites, no write sites — likely set in ctor injection).
- `objectsim` translation unit: ~91 KB of complex methods remaining (`Simulate`, `Try*` dispatchers, `KillSelf`). Each is roughly multi-hour deep-RE work.
- `iobject`, `objectfolder`, `objectmodule`: substantially hand-written.

## Person family — 🟡 partial across three directories

- `src/matched/cxperson/` — three legacy templates (`Skipping3D`, `Place`, `Turn`).
- `src/matched/cxpersonimpl/` — 64 pre-existing conversions.
- `src/matched/person/` — additional layer of pre-existing work.
- Remaining: ~86 inject-only addresses in `cXPersonImpl`, mostly 88 B and up.

## Animation family — 🟡 mid

- `sanimator2`: small getters/setters and 32–52 B band partially done; 123 complex 100 B+ stubs remain.
- `e_animcontroller`: destructor + shutdown + track-management methods converted; 81 complex 100 B+ remain.
- `e_rlevel`: room/instance management partially hand-written.

## Targets family — ✅ trivial-stub territory closed

`src/matched/targets_s2c/`, `targets_tsc3/`, `targets_cas/`, plus per-class subdirs (`famtarget/`, `mmutarget/`, etc.).

- 35 trivial conversions landed across `FAMTarget` / `MMUTarget` / `CRDTarget` / `CSPTarget` / `PAZBase` / `R2LTarget` / `CASGeneticsTarget` / `CasListener` / `CasMediator` / `INVTarget`.
- 10 inject-only `INVTarget` stubs remain at 184 B and up — each requires per-function asm reading.
- Field layouts documented in [`include/types/INVTarget.h`](https://github.com/natebag/Sims2DECOMP/blob/main/include/types/INVTarget.h) and [`include/types/CasMediator.h`](https://github.com/natebag/Sims2DECOMP/blob/main/include/types/CasMediator.h).

## Mid-tier systems — 🟡 polished, complex residue

- `eroom` (`ERoom`): hand-written, layout in [`include/types/ERoom.h`](https://github.com/natebag/Sims2DECOMP/blob/main/include/types/ERoom.h).
- `camera` (`ESimsCam`): hand-written, layout in [`include/types/ESimsCam.h`](https://github.com/natebag/Sims2DECOMP/blob/main/include/types/ESimsCam.h).
- `xrouting` (`XRoute`): 76 complex stubs remain — SDA-relative, r9-relative, callee-saved, and tail-call shapes that don't fit family-blast templates.

## Resource files — ✅ family-blast complete

`ChainResFile`, `IFFResFile2`, `NghResFile`.

## Behavior + EI light family — ✅ family-blast complete

`Behavior::Get*`, `EIAmbLight`, `EIDirLight`, `EIPortalPointLight`, `EIStaticModel`, etc.

## TileWalls — ✅ substantially hand-written

Placement methods covered by the family-blast pattern.

## APT (Macromedia Flash bytecode interpreter) — 📦 SDK-adjacent

~21 methods converted in the `AptFloat` / `AptBoolean` / `AptInteger` / `AptValue` families; ~30 additional files verified as already matching. The bulk of the interpreter remains byte-matched but not hand-written. Treat as middleware — not a high-priority port-readiness target.

## SDK (`DolphinSDK`, `VMBase`, etc.) — 📦 middleware

Byte-matched. Not a stub-to-real-C++ target — the SDK ships from Nintendo and isn't re-derived in source.

## Data section opportunities

Tracked separately from the hand-written-ratio metric.

| Section | Current | Approach |
|---------|---------|----------|
| `.dtors` (360 B) | 0.00% | Declare the static destructor table |
| `.ctors` (644 B) | 2.02% | Declare the static constructor table |
| `.rodata` (362 KB) | 16.92% | Vtable conversion per class; string-table consolidation |
| `.data` (306 KB) | 0.25% | Initialized globals, game-state tables, lookup arrays |
| `.sdata` / `.sdata2` (~12 KB) | <8% | r13- and r2-relative globals |

See [Status — data section](../status/index.md#data-section-byte-match) for live numbers.

## Claiming a subsystem

Open an issue on the repo with the subsystem you're targeting. The issue acts as the public claim and reduces the risk of two contributors working the same addresses in parallel.
