# Subsystem Map

Where each subsystem stands, who owns it, and where help is most welcome.

## Status legend

| Symbol | Meaning |
|--------|---------|
| ✅ | Substantially semantic (>50% real C++) |
| 🟡 | Partial coverage (mostly stubs, scattered semantic work) |
| 🔴 | Untouched semantically (100% byte-match, ~0% readable C++) |
| 📦 | SDK / middleware (out of scope for port-readiness work) |

## The big subsystems

### Object family
**Status**: 🟡 partial

- `cXObject` (wrapper): semantic for top-level, holder pattern documented
- `cXObjectImpl` (impl, "cousin" class): RTTI accessors + Construct/Destruct families converted; primary fields documented including `m_objectTypeKey @ 0x488` (the hottest field)
- `objectsim` TU: ~91 KB of complex methods remaining — `Simulate`, `Try*` dispatchers, `KillSelf` — multi-hour cracks per function
- `iobject`, `objectfolder`, `objectmodule`: substantially semantic

**S18 priority**: high. The `objectsim` TU is the single largest deep-RE opportunity in the project.

### Person family
**Status**: 🟡 partial — three semantic directories coexist

- `src/matched/cxperson/` — 3 S16 templates (`Skipping3D`, `Place`, `Turn`)
- `src/matched/cxpersonimpl/` — 64 pre-existing semantic conversions
- `src/matched/person/` — additional pre-existing layer
- Remaining: ~86 virgin VAs in `cXPersonImpl`, most 88B+ (back-loaded — easy quick wins largely done)

**S18 priority**: medium. Bigger functions per remaining target = lower throughput.

### Animation family
**Status**: 🟡 mid

- `sanimator2`: 8B getters/setters cracked, 32-52B band partial, 123 complex 100B+ stubs remain
- `e_animcontroller`: dtor + Shutdown + track-management methods converted, 81 complex 100B+ remaining
- `e_rlevel`: room/instance management partially semantic

**S18 priority**: medium. Requires deep RE with `diff_func.sh` tooling per function.

### Targets-family (`targets_s2c` / `targets_tsc3` / `targets_cas`)
**Status**: ✅ Lane 1 trivial-stub territory exhausted in S17

- 35 conversions across `FAMTarget` / `MMUTarget` / `CRDTarget` / `CSPTarget` / `PAZBase` / `R2LTarget` / `CASGeneticsTarget` / `CasListener` / `CasMediator` / `INVTarget`
- 10 verified-virgin `INVTarget` ASMPROC stubs remain — all 184B+ (multi-hour each)
- Roadmap: see [TypeArch's `include/types/INVTarget.h`](https://github.com/natebag/Sims2DECOMP/blob/main/include/types/INVTarget.h) for documented field offsets

**S18 priority**: low-medium. Big `INVTarget` cracks are the next opportunity.

### Mid-tier systems
**Status**: 🟡 substantial polish, residue of complex patterns

- `eroom` (`ERoom`): semantic with [`include/types/ERoom.h`](https://github.com/natebag/Sims2DECOMP/blob/main/include/types/ERoom.h)
- `camera` (`ESimsCam`): semantic 
- `xrouting` (`XRoute`): partial — 76 complex stubs remain (SDA-relative / r9-relative / callee-saved / tail-call patterns that don't fit simple templates)

**S18 priority**: medium. Pattern variety = needs per-shape tooling.

### Animation events / effects
**Status**: 🟡 partial — many conversions in S16

### Resource files
**Status**: ✅ family-blast complete on `ChainResFile` / `IFFResFile2` / `NghResFile`

### Behavior + EI light family
**Status**: ✅ family-blast complete (`Behavior::Get*`, `EIAmbLight`/`EIDirLight`/`EIStaticModel`/etc.)

### APT (Macromedia Flash bytecode interpreter)
**Status**: 📦 SDK-adjacent. KimiWorker's S17 work converted ~21 `AptFloat` / `AptBoolean` / `AptInteger` / `AptValue` family methods + verified ~30 existing semantic files. Bulk of the interpreter remains unmatched-as-real-C++ but byte-matched.

### TileWalls (placement / building)
**Status**: ✅ substantially semantic — S16 family-blast covered placement methods

### SDK (`DolphinSDK` / `VMBase` / etc.)
**Status**: 📦 byte-matched (the 100% close required the final `VMBASEDSIExceptionHandler` + `VMBASEISIExceptionHandler` twin). NOT a stub-to-real-C++ target — SDK comes from Nintendo and shouldn't be re-derived.

## Data section roadmap

A separate axis of work, just opened up:

| Section | Opportunity | Approach |
|---------|-------------|----------|
| `.dtors` (360 B at 0%) | Quick win — could hit 100% in one commit | Declare static destructor table |
| `.ctors` (644 B at 2%) | Similar to dtors | Declare static constructor table |
| `.rodata` (362 KB at 17%) | Vtables + string tables | Vtable conversion per class (TypeArch headers already document layouts) |
| `.data` (306 KB at 0.25%) | Biggest opportunity | Initialized globals, game-state tables |
| `.sdata` / `.sdata2` (~12 KB at <8%) | Small | r13/r2-relative globals |

See [`.data` tracking](../status/index.md#per-section-data-breakdown) for current numbers.

## Want to claim a subsystem?

Open an issue on the repo with the subsystem you're targeting and the time you're willing to spend. The fleet-coordination protocol means we want to avoid two contributors working the same VAs in parallel — the issue serves as the public claim.
