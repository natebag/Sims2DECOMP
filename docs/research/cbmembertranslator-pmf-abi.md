# CBMemberTranslator PMF ABI Research

> **Status: TERRITORY FULLY DRAINED** — All 334 DVD-map symbols matched.  
> **Research value:** Documents the SN ProDG PMF ABI layout and matching technique for future reference / other projects.

---

## 1. Executive Summary

`CBMemberTranslator` is a callback-bridging template in The Sims 2 (GameCube) that translates C++ member-function pointers into C-style callback thunks. The SN ProDG compiler generates small thunk functions (120B standard, 144B for MI-adjust cases) that load a PMF struct, resolve virtual vs non-virtual dispatch, apply `this`-pointer adjustments, and tail-call through.

**Key finding:** GCC 2.95.3 (SN BUILD) generates byte-identical thunk code when compiling `(obj->*pmf)()` with the correct class hierarchy. No `asm()` or manual thunk assembly is required.

**Pool status:**
| Metric | Count |
|--------|-------|
| DVD map symbols | 334 |
| Matched files in `src/matched/` | 337 (3 extras not in map) |
| Unmatched | **0** |
| Standard 120B thunks | 331 |
| MI-adjust 144B thunks | 3 |

---

## 2. PMF Struct Layout (SN ProDG on PPC)

The PMF (pointer-to-member-function) data is embedded inline in the `CBFunctorBase` object. Field offsets are **hard-coded in the thunk prologue** — all 334 thunks load from the same offsets.

```
Offset  Size  Field      Description
------  ----  ---------  ---------------------------
  +0     s16  delta      Base this-adjust (signed)
  +2     s16  vindex     Vtable slot index (>=0 = virtual, <0 = non-virtual)
  +4     u32  func/voff  Non-virtual: direct function pointer
                         Virtual: s16 vtable-pointer offset within object
  +8     u32  obj        Stored object pointer
```

Total struct size: **12 bytes** (with 4-byte alignment, the compiler may pad to 16).

---

## 3. Standard Thunk Disassembly (120B, 30 instructions)

Specimen: `CBMemberTranslator1<int, EdithDialogPrimitive, ...>::thunk` at **0x803A3028**.

```asm
; Prologue
stwu   r1,-8(r1)          ; stack frame 8B
mflr   r0
stw    r0,12(r1)

; Load PMF fields
lha    r10,2(r3)          ; r10 = vindex (s16)
lwz    r8,8(r3)           ; r8  = obj pointer
cmpwi  r10,0              ; virtual or non-virtual?
blt    .L_nonvirtual      ; vindex < 0 → non-virtual path

.L_virtual:
lha    r0,4(r3)           ; r0 = vtable offset within object
slwi   r9,r10,3           ; r9 = vindex * 8
lwzx   r11,r8,r0          ; r11 = vtable pointer (obj + voff)
add    r9,r9,r11          ; r9 = vtable + vindex*8
lwz    r11,-8(r9)         ; r11 = vtable entry word 0 (delta_hi | pad)
lwz    r12,-4(r9)         ; r12 = vtable entry word 1 (function ptr)
mr     r9,r12             ; r9 = function ptr
b      .L_merge

.L_nonvirtual:
lwz    r9,4(r3)           ; r9 = direct function pointer

.L_merge:
lha    r3,0(r3)           ; r3 = base delta (overwrites CBFunctorBase&)
cmpwi  r10,0
blt    .L_skip_delta
srawi  r0,r11,16          ; r0 = vtable entry delta (upper s16)
add    r0,r0,r3           ; r0 = base delta + vtable delta
b      .L_call
.L_skip_delta:
mr     r0,r3              ; r0 = base delta only

.L_call:
add    r3,r8,r0           ; r3 = obj + final delta (real this pointer)
mtlr   r9
blrl                      ; tail-call through LR

; Epilogue
lwz    r0,12(r1)
mtlr   r0
addi   r1,r1,8
blr
```

### 3.1 Key observations

- **Vtable entry size = 8 bytes**: `slwi r10,3` (×8) proves SN uses 8-byte vtable slots for PMF resolution.
- **Vtable entry layout**:
  ```
  bytes 0-3:  (s16 this_delta << 16) | (s16 unused)
  bytes 4-7:  void* function_pointer
  ```
- **Tail-call**: All thunks use `mtlr` + `blrl` (not `bctr`), and restore LR in epilogue.
- **Argument forwarding**: The thunk does not touch r4/r5/r6; arguments pass through unchanged.

---

## 4. MI-Adjust Variant (144B, 36 instructions)

Specimen: `CBMemberTranslator0<LoadGameTarget, void (UIDialog::*)(UIDialog *)>::thunk` at **0x803B2AF4**.

Occurs when the stored object is a **derived class** but the PMF is a **base-class member function** with a non-zero offset.

### 4.1 Additional code vs 120B template

After computing `this = obj + delta`, the 144B variant adds:

```asm
add    r3,r8,r0           ; r3 = base this pointer (same as 120B)
cmpwi  r3,0               ; null check
li     r0,0
beq    .L_null
addi   r0,r3,0x84         ; this += 0x84 (UIDialog subobject offset)
.L_null:
mr     r3,r0              ; r3 = possibly-adjusted this
mtlr   r9
blrl
```

### 4.2 Why this happens

`LoadGameTarget` inherits from multiple bases:
```cpp
class OtherBase { char pad[0x84]; };
class UIDialog { virtual void dummy(); };
class LoadGameTarget : public OtherBase, public UIDialog { };
```

When the callback stores a `LoadGameTarget*` but calls a `UIDialog::*` PMF, the compiler must adjust `this` by `+0x84` to reach the `UIDialog` subobject. The thunk embeds this fixed offset.

### 4.3 Matching technique

Model the class hierarchy exactly:
```cpp
class OtherBase { public: char pad[0x84]; };
class UIDialog { public: virtual void dummy(); };
class LoadGameTarget : public OtherBase, public UIDialog { };

class CBFunctorBase {
public:
    void (UIDialog::*m_pmf)();
    LoadGameTarget* m_obj;
};

void thunk(CBFunctorBase& f) {
    LoadGameTarget* obj = f.m_obj;
    (obj->*f.m_pmf)();
}
```

GCC 2.95 emits the null-check + addi automatically.

---

## 5. GCC 2.95 Source Pattern

The matching source for **all** CBMemberTranslator thunks follows one template:

```cpp
// FLAGS: -fno-schedule-insns

class TargetClass;          // The concrete class stored in m_obj
class BaseClass {           // The class whose member function is the PMF
public:
    virtual void dummy();   // Force vtable if PMF is virtual
};

class CBFunctorBase {
public:
    void (BaseClass::*m_pmf)();
    TargetClass* m_obj;
};

void cbmt_thunk(CBFunctorBase& f) {
    TargetClass* obj = f.m_obj;
    (obj->*f.m_pmf)();
}
```

For **non-virtual** PMFs, remove `virtual void dummy()`.
For **MI-adjust** variants, model the inheritance with correct `pad[]` size.

---

## 6. Symbol Name Parsing

CBMemberTranslator symbol names encode the template instantiation:

```
CBMemberTranslator<N>[wRet]<ArgTypes, TargetClass, PMFSig>::thunk(...)
```

| Prefix | Args | Return |
|--------|------|--------|
| `CBMemberTranslator0` | 0 | void |
| `CBMemberTranslator1<T>` | 1 × T | void |
| `CBMemberTranslator2<T,U>` | 2 × T,U | void |
| `CBMemberTranslator1wRet<R,T>` | 1 × T | R |

The `TargetClass` is the concrete type stored in `m_obj`.  
The PMF signature `(BaseClass::*)(BaseClass*, ...)` tells you the base class for the PMF.

---

## 7. Territory Completion Notes

- **120B standard thunks**: Trivial match once the PMF struct layout is understood. All 331 verified.
- **144B MI-adjust thunks**: Require modeling the derived→base offset with a `pad[]` base class. All 3 verified.
- **No asm() needed**: GCC 2.95 SN BUILD generates identical code natively.
- **No remaining targets**: Scout pool is empty. Do not allocate future sessions to CBMemberTranslator.

---

## 8. References

- Matched examples:
  - `src/matched/cbmt_blast/match_0x803A3028_CBMemberTranslator1_int.cpp` (120B standard)
  - `src/matched/cbmt_blast/match_0x803B2AF4_CBMemberTranslator0_LoadGameTarget_UIDialog.cpp` (144B MI)
- Verify: `bash tools/verify_match.sh <file> <addr> <size>`
- DVD map: `extracted/files/u2_ngc_release_dvd.map`
