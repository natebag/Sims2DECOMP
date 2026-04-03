# ObjFnTableQuickData Verification Notes

## Status: Analysis Complete, Awaiting SN Compiler Verification

All 9 ObjFnTableQuickData functions have been analyzed and initial C++ reconstructions created in src/wip/objects/.

## Functions Created

1. **ObjFnTableQuickData::ObjFnTableQuickData (0x801BE134, 88 bytes)**
   - Constructor initializing vtable and ObjectDataID
   - File: match_0x801be134_ObjFnTableQuickData_ctor_real.cpp

2. **ObjFnTableQuickData::~ObjFnTableQuickData (0x801BE18C, 92 bytes)**
   - Destructor with refcount-based self-deletion
   - File: match_0x801be18c_ObjFnTableQuickData_dtor.cpp

3. **ObjFnTableQuickData::Release (0x801BE6BC, 92 bytes)**
   - Reference counting release with virtual dtor dispatch
   - File: match_0x801be6bc_ObjFnTableQuickData_Release.cpp

4. **ObjFnTableQuickData::SetTreeID (0x801BE278, 96 bytes)**
   - Array index bounds check and short value storage
   - File: match_0x801be278_ObjFnTableQuickData_SetTreeID.cpp

## Assembly Analysis Summary

From src/asm_decomp/ObjFnTableQuickData.cpp, extracted patterns:

- **ctor**: VTable assignment (lis/addi), ObjectDataID constructor call, field zeroing
- **dtor**: VTable update, conditional __builtin_delete calls, refcount check with beq
- **Release**: Decrement, compare to 0, virtual call if zero
- **SetTreeID**: Bounds check (cmplwi), dual-path code (m_fnData vs m_fnDataArray), offset calculation (add + addi), store (sth)

## Key Issue: Struct Layout

The C++ implementations require exact struct member offsets to compile to matching bytes. Current challenge:
- ObjectDataID is 12 bytes
- Member layout must match original executable
- Vtable addresses are hardcoded magic numbers

## Verification Workflow

1. **Fix struct definitions** with proper alignment and offsets from map file analysis
2. **Compile with SN Systems cc1plus.exe** (devkitPPC GCC won't produce matching bytes)
3. **Run verify_match.sh** to confirm byte-exact match
4. **Move to src/matched/** only after passing verification

## Next Steps (for OpusWorker or verification expert)

- Extract complete struct definitions from disassembly
- Verify ObjectDataID layout and vtable assignments
- Attempt compilation with -msdata=eabi -G 8 flags (SN ProDG settings)
- Fine-tune until verify_match.sh returns MATCH

All source files include address/size verification markers at top for easy reference.
