# Failed Matches — Functions to Revisit

Functions that agents attempted but couldn't match. Organized by failure reason.
These are our "come back later" list.

## Compiler Version Mismatch (SN v3.93 vs EA's build version)

Functions where the SN compiler produces correct logic but different
branch scheduling or instruction ordering. May need the exact compiler
version EA used, or NON_MATCHING annotation.

### Register Allocation Differences (mr r9,r3 vs mr r11,r3)

The SN compiler v3.93 consistently uses r11 as the first temp register
when copying the `this` pointer or first arg, while the DOL uses r9.
This affects all functions that start with `mr rN, r3`. Affected:

- `0x802433C4` `memcmp` — r11 vs r9 for first pointer
- `0x802438E0` `strcpy` — r11 vs r9, plus andc/and. register swap
- `0x8024370C` `strcat` — same pattern as strcpy
- `0x80243C84` `strstr` — r3 kept vs moved to r10
- `0x80243838` `strcmp` — same word-loop register issue

### Instruction Scheduling Differences

The SN compiler v3.93 schedules stores/loads differently from the DOL,
especially around:
- Floating point constant loads (lis/lfs vs reloc)
- Constructor field stores (reordering based on data dependencies)

- `0x80016FB8` `ESimsCam::ApplyPan(float)` — stfs scheduled before lfs constant
- `0x800210E4` `ECheatLookup::ECheatLookup(void)` — store order differs
- `0x802E0E90` `EMemoryReadStream::EMemoryReadStream(void *)` — store order of zero-init fields reversed
- `0x802E0EC4` `EMemoryBufferWriteStream::EMemoryBufferWriteStream(void *)` — same store order issue
- `0x802CD9B8` `ERedBlackTree::ERedBlackTree(void)` — store order of init fields differs

### extsb Injection Differences

- `0x802D2C48` `EString::MakeUpper(void)` — SN compiler inserts extsb for char comparison; DOL does not
- `0x802C75E8` `EFixedString::MakeCopy(char)` — register allocation differs (r11 vs r3)
- `0x802E08E0` `EBitArray::operator[](int)` — SN emits `or r9,r3,r3` for struct return hidden param, compiler omits copy

### Register Allocation (r29/r30 swap)

- `0x802D1348` `realloc` — r3->r30/r4->r29 in DOL, reversed by compiler
- `0x802D116C` `memalign` — same r29/r30 register allocation mismatch

### Conditional Branch Pattern Differences

- `0x80024940` `TimeIsInRange(int, int, int)` — Uses r0 temp + mr r3,r0 in DOL
  but compiler puts result directly in r3

### Loop Optimization Differences

- `0x8004AFA8` `BBI::InventoryItems::GetNewItemIndex(void) const` — DOL uses
  lwzx with slwi index, compiler optimizes to lwzu (load with update)

(Agents: add entries here as you find them)

- `0x8035227C` `InteractorModule::DirectInteractor::CameraDirectorPermitsDirectControl`
  Return/signature cleanup fixed the first compile issue, but the verified C++ body still diverged from SN codegen shape. Left as unmatched after exhausting the worker's attempt budget.

- `0x803529E4` `InteractorModule::FloorPainter::UpdateStickState`
  High-level logic looked correct, but the compiled control-flow and scheduling still diverged from the DOL under SN. Skipped after repeated verification failures.

- `0x8039D4F0` `EmitterSpr3d::~EmitterSpr3d(void)`
  Tried `Destroy()`-style and explicit base-destructor wrapper shapes. All variants failed verification, suggesting a destructor-wrapper/codegen shape issue rather than missing high-level logic.

- `0x803AE07C` `StdResFile::~StdResFile(void)`
  Two destructor wrapper shapes were attempted. One introduced extra vtable/base-call work; the other compiled into the deleting-destructor flag path instead of the raw wrapper used by the DOL.

## Relocation Issues (bl/b targets differ in .o vs DOL)

Functions that call other functions — the branch offsets in standalone .o
files differ from the linked DOL. The relocation masking in verify_match.sh
handles some of these, but complex call patterns still fail.

## Multiple Return Paths

Functions with complex control flow (multiple if/else chains, early returns)
where the compiler schedules branches differently.

## Unknown Failures

Functions that failed for unclear reasons — need manual investigation.

- `0x80014028` `AwarenessManager::GetPlayerObject(int)`
  Best C++ attempt came very close but did not match the original branch ordering. Current mismatch points:
  original wants `slwi` before the `addi 0x5DCC`, an explicit `li r3,0`, and `beqlr cr1`; generated code kept the same logic but scheduled those pieces differently.
  Restored the file to its raw-byte body instead of landing a wrong C++ version.

---

Last updated: 2026-03-28
Total matched: 5,544 / 20,508 (27.0%)
Total remaining: ~14,964

## Agent Range 801E0000-801FFFFF (2026-03-28)

### Failed matches (store reordering issue):
- `801E1634` SKLTarget::HideSkills(void) - 16 bytes - compiler reorders stores ascending by offset
- `801E3580` WAFTarget::HideWantsAndFears(void) - 16 bytes - same store reordering issue

### Failed matches (conditional return beqlr/bgtlr):
- `801E7058` G2DTarget::HasPendingTransition(void) - 32 bytes - DOL uses beqlr, SN compiler generates beq+blr
- `801ECDC4` ConvertShoppingCategoryToInventoryCategory(int) - 44 bytes - compiler uses mfcr trick instead of beqlr/bgtlr

### Failed matches (instruction scheduling differs):
- `801F2370` INVTarget::InstallBldVariables(void) - 64 bytes - DOL loads global before null check

### Skipped (SDA r13-relative globals):
- `801E7050` G2DTarget::IsInitComplete(void) - 8 bytes - r13 relative
- `801E7098` K2YTarget::GetMode(void) - 8 bytes - r13 relative
- `801E70FC` EYETarget::EyeToyUnplugCallback(int) - 24 bytes - r13 relative + beqlr

### Skipped (7-byte struct copy pattern):
- `801E9248` GetVar_EYE_exists::Handler(char *) - 36 bytes - 7-byte struct field-by-field copy
- `801F65A4` INVTarget::GetOnMsgInvExists(char *) - 36 bytes - identical pattern

### Skipped (variadic crclr calls):
- Many INVTarget Get/Set message handler functions using crclr + sprintf patterns

## Agent Range 80100000-80120000 (2026-03-28)

### Failed matches (instruction scheduling / code ordering):
- `0x801110C0` ObjSelector::GetHasGraphics(void) - 24 bytes - DOL puts li r3,0 default before load, SN compiler puts load first
- `0x80111148` ObjSelector::GetIsMultiTileSubObject(void) - 40 bytes - same pattern, DOL sets default return early
- `0x801102D4` ObjFnTableQuickData::Release(void) - 92 bytes - virtual call pattern via vtable differs from direct call

### Skipped (SDA r13-relative globals):
- `0x8011A9E0` GetAutonomyConstantsClient(void) - 8 bytes - uses addi r3, r13, offset
- `0x80117EEC` unknown global getter - 8 bytes - lwz r3, -31776(r13)
- `0x8010EE64` GetJobHUDName(short) - 12 bytes - lis/addi global address

### Notes on this range:
- The SN compiler heavily interleaves code in this range (mustates.obj, pregamestate.obj, statemachine.obj, thesims.obj)
- Most map symbols point to mid-block addresses, not clean function boundaries
- Leaf functions found between blr pairs were the primary matching strategy
- 49 new verified matches added (63 total in range, up from 14)

## 0x80260000-0x80280000 Range — Failed Matches

### mr instruction reordering (r3/r4 restore order after bl)
After a `bl` call, the SN compiler restores saved registers in different orders.
DOL does `mr r3,r31; mr r4,r30` while our compiler does `mr r4,r30; mr r3,r31`.
Cannot control from C++. Affects all 2-param functions that call other functions
with both params preserved.

- `0x8027F444` AptActionInterpreter::_FunctionAptActionCallFuncSetVar — mr order swap
- `0x8027F540` AptActionInterpreter::_FunctionAptActionCallMethodSetVar — same pattern
- `0x8026AAEC` AptAddToInputQueue — register allocation differs (SDA vs absolute)

### Register allocation: r4 vs r11 for local pointer
DOL uses r4 for a frequently-accessed local pointer while SN v3.93 uses r11.

- `0x8026C790` EAStringC::operator= — old ptr in r4 (DOL) vs r11 (compiled)

### Code size/layout mismatch (branch offset differences)
SN compiler generates different branch structure leading to size mismatches.

- `0x8026B6FC` AptDebugIsPlaying — compiled version 16 bytes longer (extra li/branch)

### Note: SN interleaved code
The 0x80260000-0x80280000 range is HEAVILY interleaved by the SN linker. Most
map entries do NOT correspond to actual function boundaries. Only ~20 functions
in this entire 128KB range have standard stwu/blr prologues. The rest are
mid-function fragments.

## Agent Range 0x801C0000 - 0x801E0000

### Failed - branch prediction hints
- `M2MTarget::OnGetNumItems` (0x801C10C8, 64B) - beqlr prediction bit mismatch (4C vs 4D)
- `O2TTarget::AudioOptionsModified` (0x801CEBE8, 84B) - beqlr/bgelr prediction bits
- `O2TTarget::GameOptionsModified` (0x801CEC3C, 84B) - beqlr/bgelr prediction bits

### Failed - register allocation mismatch
- `sort_records_by_name` (0x801DA670, 128B) - r30/r31 swapped for a/temp
- `M2MTarget::DoesMemoryDeviceExist` (0x801C1D08, 104B) - r30 vs r0 for zero init

### Failed - store ordering / scheduling
- `M2MTarget::StartLoadedGame` (0x801C1D70, 112B) - sth/stw reorder
- `MMUTarget::LaunchFreeplay` (0x801C6DF0, 108B) - stw field ordering

### Failed - comparison encoding
- `M2MTarget::OnCancel` (0x801C0D08, 140B) - cmpwi 11/blt vs cmpwi 10/ble canonicalization

### Failed - SDA/global access patterns
- `MMUTarget::UpdateDevMenuState` (0x801C85D0, 76B) - lis+lwz vs single lwz for global

### Range 801A0000-801BFFFF Agent Failures

- `0x801B0750` `FAMTarget::UpdateText(void)` — Empty function generates just `blr` but DOL has `stwu; addi; blr` (stack frame for empty function)
- `0x801B938C` `find_ingredient(Ingredient**, unsigned int, short)` — Loop with lwzu pattern; compiler uses different register allocation and loop structure  
- `0x801B93D4` `find_ingredient_type(IngredientType**, unsigned int, short)` — Same as find_ingredient (identical bytes)
- `0x801B9458` `INGTarget::SetRefrigeratorLevel(int)` — Uses SDA global (r13-relative), can't match without SDA setup
- `0x801A091C` `CASGeneticsTarget::IsGenerating(void)` — Uses SDA global (r13-relative)
- `0x801BC984` `INGTarget::is_group_meal(void) const` — Uses xori/subfic/adde pattern, SDA relative access
- `0x801B8E08` `H2DTarget::CountModelessDialogs(void)` — Register allocation: DOL uses lwz r0 but compiler generates lwz r3
- `0x801BE548` `K2YTarget::IsModeValid(void)` — Uses SDA global (r13-relative)

## Agent Range 0x80120000 - 0x80140000

### Failed - rlwinm mask difference on unsigned short
- `0x8012C928` cXPersonImpl::SetInvisible(bool) — 36 bytes — SN compiler generates `rlwinm r0,r0,0,16,30` for `&= ~1` on unsigned short, DOL has `rlwinm r0,r0,0,0,30` (full 32-bit mask). Also branch offset differs (no trailing blr in DOL version).
- `0x8012C950` cXPersonImpl::SetIsAlien(bool) — 36 bytes — Same pattern, `rlwinm r0,r0,0,29,27` mask differs.

### Skipped (SDA r13-relative globals):
- `0x80135544` cBoxX::PauseSFX(void) — 8 bytes — stw r3, -31680(r13) — SDA global store
- `0x8013884C` unknown getter — 8 bytes — lwz r3, -31676(r13) — SDA global load

### Skipped (register-dependent return):
- `0x80132D34` / `0x8013E440` — `mr r3, r0; blr` — return from r0 (context-dependent)
- `0x80137BD8` — `mr r3, r9; blr` — return from r9 (context-dependent)
- `0x80138DA8` / `0x80138E28` / `0x8013EF44` — `mr r3, r10; blr` — return from r10 (context-dependent)

### Notes on this range:
- The SN compiler heavily interleaves function code within .obj compilation units
- Most map symbols point to mid-block addresses, not clean function boundaries
- Inline copies of cXPersonImpl accessors are scattered throughout AmbientSoundPlayer.obj
- Leaf functions found between blr pairs were the primary matching strategy
- 82 new verified matches added (99 total in range, up from 17)

### EVec3 Struct Copy Patterns

Functions where the SN compiler generates a specific stack-temp pattern for
EVec3 struct copies: `stfs f0, 8(r9); stfs f0, 4(r9); stfs f0, 8(r1)` followed
by `lwz` back from stack. Our SN compiler v3.93 produces different register
allocations (r10 vs r9 for temp ptr) and different store orderings.

- `0x80230F8C` `ELightGrid::LightData::Clear(void)` — 112 bytes, zero vec init
- `0x80226A58` `WallPainter::RestoreFromHoldPos(EVec3 &)` — 116 bytes
- `0x802093AC` `Interactor::ResetInputState(void)` — 68 bytes

### Extended Static Init (non-standard pattern)

- `0x8022F694` `__static_initialization_and_destruction_0` (EIStaticSubModel) — 140 bytes, has extra EVec3 init after RegisterType call, different lis/addi scheduling

## Agent Range 0x80180000-0x801A0000 - Failed Attempts

### Register allocation / operand order mismatches (SN compiler quirk):
- `80199E5C` CASSelectionTarget::ConvertGridIdxToOptionIdx(unsigned int) - `add` operand order: DOL has `add r3, r4, r3` vs compiled `add r3, r3, r4`
- `80180308` UIScreenManager::PopQueue(int) - `bgtlr` vs `bgt+offset`, `add` operand order swap

### Switch statement code generation differences:
- `8018A6BC` LoadGameTarget::ZeroInputCallback(void) - binary search vs linear compare ordering
- `80194E4C` CASTarget::GotoInitialScreen(void) - switch on view mode

### Missing crclr instruction:
- `8019011C` RepTitleSupport::GetRepTitleLevel(int) - DOL has `crclr 4*cr1+eq` before `bl` which SN compiler doesn't emit
- `80190224` RepTitleSupport::GetRepTableRawTitle(int) - same crclr issue
- `8019025C` RepTitleSupport::GetRepTableRawFriendTitle(int) - same crclr issue
- `80190294` RepTitleSupport::GetRepTableRawEnemyTitle(int) - same crclr issue

### Global address split (lis+addi) vs single relocation:
- `80193F2C` CASTarget::UnloadLastScreen(void) - global address loaded with 2 instructions in DOL vs 1 in compiled

### Loop/branch structure differences:
- `80181C58` UIUpdateTable::ContainsEntry(CBFunctor0 &) - branch target for loop differs
- `80185758` ActionQueueHUD::CatchUpPendingActions(void) - goto-based flow restructured by compiler

### Constructor/destructor store ordering:
- `80182F40` ActionMenu::MenuItem::MenuItem(void) - stores reordered by compiler
- `801812AC` UIButtonImages::~UIButtonImages(void) - vtable offset off by 4 due to virtual keyword
