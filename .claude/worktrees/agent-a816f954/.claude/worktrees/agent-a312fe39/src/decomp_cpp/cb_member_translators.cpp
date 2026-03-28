// cb_member_translators.cpp - All CBMemberTranslator template instantiations
// 147 files converted: 69 CBMemberTranslator0 + 78 CBMemberTranslator1
// All are identical member function pointer thunks with different template parameters.
// Each thunk is 120 bytes (30 PPC instructions) and implements the same logic:
//   1. Read member function pointer fields from CBFunctorBase
//   2. If vtable index >= 0: resolve through vtable (virtual call)
//   3. If vtable index < 0: direct function pointer call
//   4. Adjust 'this' pointer and tail-call the target function
//
// CBMemberTranslator0::thunk takes (CBFunctorBase&) - no extra args
// CBMemberTranslator1::thunk takes (CBFunctorBase&, P1) - one extra arg passed through
//
// The extra arg in CBMemberTranslator1 is passed in r4 (second parameter register).
// Since the thunk only modifies r3 (this pointer) and branches to the target,
// r4 is naturally preserved and forwarded to the callee - the assembly is identical
// to CBMemberTranslator0 because r4 is never touched.
//
// Generated from src/asm_decomp/CBMemberTranslator0_*.cpp and CBMemberTranslator1_*.cpp

#include "types.h"

// Forward declarations for all referenced classes
class ACTTarget;
class BBHTarget;
class CASBodyTarget;
class CASFashionTarget;
class CASGeneticsTarget;
class CASMiscTarget;
class CASMorphTarget;
class CASPersonalTarget;
class CASRoommateTarget;
class CASSelectionTarget;
class CASTarget;
class CASTattooTarget;
class CRDTarget;
class CSMTarget;
class CSPTarget;
class E2ETarget;
class ERC;
class EYETarget;
class EdithDialogPrimitive;
class FAMTarget;
class FCMTarget;
class FlowGotoTarget;
class FONTarget;
class G2DTarget;
class GOLTarget;
class H2DTarget;
class HUDTarget;
class HelpDialog;
class INGTarget;
class INTTarget;
class INVTarget;
class ITBTarget;
class K2YTarget;
class KEYTarget;
class LoadGameTarget;
class M2MTarget;
class MDITarget;
class MMUTarget;
class MODTarget;
class MOTTarget;
class MSGTarget;
class O2TTarget;
class OPTTarget;
class PAZBase;
class PAZTarget;
class PCTTarget;
class PDATarget;
class PRGTarget;
class PSETarget;
class PZ1Target;
class R2LTarget;
class RCPTarget;
class RELTarget;
class RGTTarget;
class RMDTarget;
class SKLTarget;
class SKNTarget;
class SaveGameTarget;
class UI3D;
class UIAUDIOTarget;
class UIAnalog;
class UIDBTarget;
class UIDialog;
class UIObjectBase;
class UIQDTarget;
class UIScreenManager;
class WAFTarget;
class WXFTarget;

// CBFunctorBase - the callback functor base class
// Layout derived from the PPC assembly field accesses:
//   lha  0(r3) -> m_thisAdj     (signed 16-bit at offset 0)
//   lha  2(r3) -> m_vtblIndex   (signed 16-bit at offset 2)
//   lha  4(r3) -> m_vtblOff     (signed 16-bit at offset 4, used when vtblIndex >= 0)
//   lwz  4(r3) -> m_funcPtr     (32-bit pointer at offset 4, used when vtblIndex < 0)
//   lwz  8(r3) -> m_obj         (32-bit pointer at offset 8)
class CBFunctorBase {
public:
    short m_thisAdj;    // 0x00 - adjustment added to 'this' pointer
    short m_vtblIndex;  // 0x02 - vtable index; negative means direct call
    union {
        short m_vtblOff;    // 0x04 - offset to vtable pointer in object (when vtblIndex >= 0)
        void* m_funcPtr;    // 0x04 - direct function pointer (when vtblIndex < 0)
    };
    void* m_obj;        // 0x08 - pointer to the target object
};

// Template declarations
template <typename T0, typename T1> class CBMemberTranslator0;
template <typename T0, typename T1, typename T2> class CBMemberTranslator1;

// ============================================================================
// Helper: the actual thunk logic (shared by all instantiations)
// ============================================================================
//
// This is the C++ equivalent of the 30-instruction PPC thunk.
// Every CBMemberTranslator0 and CBMemberTranslator1 instantiation compiles
// to byte-identical code (only the address labels differ).
//
// PPC register mapping:
//   r3  = CBFunctorBase* (this for thunk, later becomes adjusted obj ptr)
//   r4  = extra arg (CBMemberTranslator1 only, passed through untouched)
//   r8  = obj pointer from CBFunctorBase
//   r9  = function pointer to call (resolved)
//   r10 = vtblIndex
//   r11 = vtable thunk adjustment (upper 16 bits = this adjustment)
//   r12 = scratch for function pointer from vtable
//
// Assembly (identical across all 147 instantiations):
//   stwu    r1,-8(r1)          ; create stack frame
//   mflr    r0                 ; save link register
//   stw     r0,12(r1)          ; store LR on stack
//   lha     r10,2(r3)          ; r10 = m_vtblIndex (signed)
//   lwz     r8,8(r3)           ; r8 = m_obj
//   cmpwi   r10,0              ; check if virtual or direct
//   blt     direct_call
//   lha     r0,4(r3)           ; r0 = m_vtblOff
//   slwi    r9,r10,3           ; r9 = vtblIndex * 8
//   lwzx    r11,r8,r0          ; r11 = *(obj + vtblOff) = vtable ptr
//   add     r9,r9,r11          ; r9 = vtable + vtblIndex * 8
//   lwz     r11,-8(r9)         ; r11 = vtable_entry[-2] (thunk adj)
//   lwz     r12,-4(r9)         ; r12 = vtable_entry[-1] (func ptr)
//   mr      r9,r12             ; r9 = func ptr
//   b       resolve_this
// direct_call:
//   lwz     r9,4(r3)           ; r9 = m_funcPtr (direct)
// resolve_this:
//   lha     r3,0(r3)           ; r3 = m_thisAdj (signed)
//   cmpwi   r10,0              ; virtual path?
//   blt     direct_adj
//   srawi   r0,r11,16          ; r0 = thunk adj >> 16
//   add     r0,r0,r3           ; r0 = (thunk adj >> 16) + thisAdj
//   b       do_call
// direct_adj:
//   mr      r0,r3              ; r0 = thisAdj
// do_call:
//   add     r3,r8,r0           ; r3 = obj + final adjustment (new 'this')
//   mtlr    r9                 ; set up branch target
//   blrl                       ; tail-call the target function
//   lwz     r0,12(r1)          ; restore LR
//   mtlr    r0
//   addi    r1,r1,8            ; destroy stack frame
//   blr                        ; return

// Implementation note: The thunk performs a tail-call via blrl + blr.
// In portable C++ we express this as a function pointer call through
// the resolved CBFunctorBase fields. The compiler will generate
// equivalent code for each template instantiation.

namespace {

// Common thunk implementation for CBMemberTranslator0
// (no extra args beyond CBFunctorBase)
inline void cb_thunk0(CBFunctorBase& f) {
    typedef void (*FuncPtr)(void*);

    void* obj = f.m_obj;
    short vtblIndex = f.m_vtblIndex;
    FuncPtr funcPtr;
    int thunkAdj = 0;

    if (vtblIndex >= 0) {
        // Virtual call: resolve through vtable
        // vtable pointer is at *(obj + m_vtblOff)
        char* objBytes = (char*)obj;
        void** vtbl = *(void***)(objBytes + f.m_vtblOff);
        // Each vtable entry is 8 bytes: [4-byte thunk adj][4-byte func ptr]
        // Entry at index i starts at vtbl + i*8
        // But we read from entry[-8] and entry[-4] relative to (vtbl + i*8)
        char* entry = (char*)vtbl + vtblIndex * 8;
        thunkAdj = *(int*)(entry - 8);
        funcPtr = *(FuncPtr*)(entry - 4);
    } else {
        // Direct call
        funcPtr = (FuncPtr)f.m_funcPtr;
    }

    short thisAdj = f.m_thisAdj;
    int finalAdj;
    if (vtblIndex >= 0) {
        finalAdj = (thunkAdj >> 16) + thisAdj;
    } else {
        finalAdj = thisAdj;
    }

    funcPtr((char*)obj + finalAdj);
}

// Common thunk implementation for CBMemberTranslator1
// (one extra arg passed through in r4, untouched by thunk)
template <typename P1>
inline void cb_thunk1(CBFunctorBase& f, P1 arg) {
    typedef void (*FuncPtr)(void*, P1);

    void* obj = f.m_obj;
    short vtblIndex = f.m_vtblIndex;
    FuncPtr funcPtr;
    int thunkAdj = 0;

    if (vtblIndex >= 0) {
        char* objBytes = (char*)obj;
        void** vtbl = *(void***)(objBytes + f.m_vtblOff);
        char* entry = (char*)vtbl + vtblIndex * 8;
        thunkAdj = *(int*)(entry - 8);
        funcPtr = *(FuncPtr*)(entry - 4);
    } else {
        funcPtr = (FuncPtr)f.m_funcPtr;
    }

    short thisAdj = f.m_thisAdj;
    int finalAdj;
    if (vtblIndex >= 0) {
        finalAdj = (thunkAdj >> 16) + thisAdj;
    } else {
        finalAdj = thisAdj;
    }

    funcPtr((char*)obj + finalAdj, arg);
}

} // anonymous namespace


// ============================================================================
// CBMemberTranslator0 specializations (69 instantiations)
// ============================================================================
// Each one calls cb_thunk0() — the bodies are identical, only types differ.

// 0x803B5E20 (120 bytes)
template <> class CBMemberTranslator0<ACTTarget, void (ACTTarget::*)(ACTTarget *)> {
public:
    void thunk(CBFunctorBase& f) { cb_thunk0(f); }
};

// 0x803B6078 (120 bytes)
template <> class CBMemberTranslator0<BBHTarget, void (BBHTarget::*)(BBHTarget *)> {
public:
    void thunk(CBFunctorBase& f) { cb_thunk0(f); }
};

// 0x803B3AB8 (120 bytes)
template <> class CBMemberTranslator0<CASBodyTarget, void (UIObjectBase::*)(UIObjectBase *)> {
public:
    void thunk(CBFunctorBase& f) { cb_thunk0(f); }
};

// 0x803B41C0 (120 bytes)
template <> class CBMemberTranslator0<CASFashionTarget, void (UIObjectBase::*)(UIObjectBase *)> {
public:
    void thunk(CBFunctorBase& f) { cb_thunk0(f); }
};

// 0x803B3D10 (120 bytes)
template <> class CBMemberTranslator0<CASGeneticsTarget, void (CASGeneticsTarget::*)(CASGeneticsTarget *)> {
public:
    void thunk(CBFunctorBase& f) { cb_thunk0(f); }
};

// 0x803B4418 (120 bytes)
template <> class CBMemberTranslator0<CASMiscTarget, void (UIObjectBase::*)(UIObjectBase *)> {
public:
    void thunk(CBFunctorBase& f) { cb_thunk0(f); }
};

// 0x803B4670 (120 bytes)
template <> class CBMemberTranslator0<CASMorphTarget, void (UIObjectBase::*)(UIObjectBase *)> {
public:
    void thunk(CBFunctorBase& f) { cb_thunk0(f); }
};

// 0x803B48C8 (120 bytes)
template <> class CBMemberTranslator0<CASPersonalTarget, void (UIObjectBase::*)(UIObjectBase *)> {
public:
    void thunk(CBFunctorBase& f) { cb_thunk0(f); }
};

// 0x803B4D78 (120 bytes)
template <> class CBMemberTranslator0<CASRoommateTarget, void (UIObjectBase::*)(UIObjectBase *)> {
public:
    void thunk(CBFunctorBase& f) { cb_thunk0(f); }
};

// 0x803B3F68 (120 bytes)
template <> class CBMemberTranslator0<CASSelectionTarget, void (UIObjectBase::*)(UIObjectBase *)> {
public:
    void thunk(CBFunctorBase& f) { cb_thunk0(f); }
};

// 0x803B3770 (120 bytes)
template <> class CBMemberTranslator0<CASTarget, void (CASTarget::*)(CASTarget *)> {
public:
    void thunk(CBFunctorBase& f) { cb_thunk0(f); }
};

// 0x803B4B20 (120 bytes)
template <> class CBMemberTranslator0<CASTattooTarget, void (UIObjectBase::*)(UIObjectBase *)> {
public:
    void thunk(CBFunctorBase& f) { cb_thunk0(f); }
};

// 0x803B63F4 (120 bytes)
template <> class CBMemberTranslator0<CRDTarget, void (CRDTarget::*)(CRDTarget *)> {
public:
    void thunk(CBFunctorBase& f) { cb_thunk0(f); }
};

// 0x803B66C4 (120 bytes)
template <> class CBMemberTranslator0<CSMTarget, void (CSMTarget::*)(CSMTarget *)> {
public:
    void thunk(CBFunctorBase& f) { cb_thunk0(f); }
};

// 0x803B691C (120 bytes)
template <> class CBMemberTranslator0<CSPTarget, void (CSPTarget::*)(CSPTarget *)> {
public:
    void thunk(CBFunctorBase& f) { cb_thunk0(f); }
};

// 0x803B6B74 (120 bytes)
template <> class CBMemberTranslator0<E2ETarget, void (E2ETarget::*)(E2ETarget *)> {
public:
    void thunk(CBFunctorBase& f) { cb_thunk0(f); }
};

// 0x803BAFD8 (120 bytes)
template <> class CBMemberTranslator0<EYETarget, void (EYETarget::*)(EYETarget *)> {
public:
    void thunk(CBFunctorBase& f) { cb_thunk0(f); }
};

// 0x803A30A0 (120 bytes)
template <> class CBMemberTranslator0<EdithDialogPrimitive, void (UIDialog::*)(UIDialog *)> {
public:
    void thunk(CBFunctorBase& f) { cb_thunk0(f); }
};

// 0x803B6FE0 (120 bytes)
template <> class CBMemberTranslator0<FAMTarget, void (FAMTarget::*)(FAMTarget *)> {
public:
    void thunk(CBFunctorBase& f) { cb_thunk0(f); }
};

// 0x803B72B0 (120 bytes)
template <> class CBMemberTranslator0<FCMTarget, void (FCMTarget::*)(FCMTarget *)> {
public:
    void thunk(CBFunctorBase& f) { cb_thunk0(f); }
};

// 0x803BB2A8 (120 bytes)
template <> class CBMemberTranslator0<FONTarget, void (UIObjectBase::*)(UIObjectBase *)> {
public:
    void thunk(CBFunctorBase& f) { cb_thunk0(f); }
};

// 0x803B15C0 (120 bytes)
template <> class CBMemberTranslator0<FlowGotoTarget, void (UIObjectBase::*)(UIObjectBase *)> {
public:
    void thunk(CBFunctorBase& f) { cb_thunk0(f); }
};

// 0x803B7554 (120 bytes)
template <> class CBMemberTranslator0<G2DTarget, void (G2DTarget::*)(G2DTarget *)> {
public:
    void thunk(CBFunctorBase& f) { cb_thunk0(f); }
};

// 0x803BB500 (120 bytes)
template <> class CBMemberTranslator0<GOLTarget, void (GOLTarget::*)(GOLTarget *)> {
public:
    void thunk(CBFunctorBase& f) { cb_thunk0(f); }
};

// 0x803B77AC (120 bytes)
template <> class CBMemberTranslator0<H2DTarget, void (H2DTarget::*)(H2DTarget *)> {
public:
    void thunk(CBFunctorBase& f) { cb_thunk0(f); }
};

// 0x803B2700 (120 bytes)
template <> class CBMemberTranslator0<HUDTarget, void (HUDTarget::*)(HUDTarget *)> {
public:
    void thunk(CBFunctorBase& f) { cb_thunk0(f); }
};

// 0x803B0FA4 (120 bytes)
template <> class CBMemberTranslator0<HelpDialog, void (UIDialog::*)(UIDialog *)> {
public:
    void thunk(CBFunctorBase& f) { cb_thunk0(f); }
};

// 0x803B7A04 (120 bytes)
template <> class CBMemberTranslator0<INGTarget, void (INGTarget::*)(INGTarget *)> {
public:
    void thunk(CBFunctorBase& f) { cb_thunk0(f); }
};

// 0x803BBAA0 (120 bytes)
template <> class CBMemberTranslator0<INTTarget, void (INTTarget::*)(INTTarget *)> {
public:
    void thunk(CBFunctorBase& f) { cb_thunk0(f); }
};

// 0x803BB668 (120 bytes)
template <> class CBMemberTranslator0<INVTarget, void (INVTarget::*)(INVTarget *)> {
public:
    void thunk(CBFunctorBase& f) { cb_thunk0(f); }
};

// 0x803B7CD4 (120 bytes)
template <> class CBMemberTranslator0<ITBTarget, void (ITBTarget::*)(ITBTarget *)> {
public:
    void thunk(CBFunctorBase& f) { cb_thunk0(f); }
};

// 0x803B7F2C (120 bytes)
template <> class CBMemberTranslator0<K2YTarget, void (UIObjectBase::*)(UIObjectBase *)> {
public:
    void thunk(CBFunctorBase& f) { cb_thunk0(f); }
};

// 0x803BBCF8 (120 bytes)
template <> class CBMemberTranslator0<KEYTarget, void (UIObjectBase::*)(UIObjectBase *)> {
public:
    void thunk(CBFunctorBase& f) { cb_thunk0(f); }
};

// 0x803B298C (120 bytes)
template <> class CBMemberTranslator0<LoadGameTarget, void (LoadGameTarget::*)(LoadGameTarget *)> {
public:
    void thunk(CBFunctorBase& f) { cb_thunk0(f); }
};

// 0x803B2AF4 (120 bytes)
template <> class CBMemberTranslator0<LoadGameTarget, void (UIDialog::*)(UIDialog *)> {
public:
    void thunk(CBFunctorBase& f) { cb_thunk0(f); }
};

// 0x803B8184 (120 bytes)
template <> class CBMemberTranslator0<M2MTarget, void (M2MTarget::*)(M2MTarget *)> {
public:
    void thunk(CBFunctorBase& f) { cb_thunk0(f); }
};

// 0x803B8454 (120 bytes)
template <> class CBMemberTranslator0<MDITarget, void (MDITarget::*)(MDITarget *)> {
public:
    void thunk(CBFunctorBase& f) { cb_thunk0(f); }
};

// 0x803B86AC (120 bytes)
template <> class CBMemberTranslator0<MMUTarget, void (MMUTarget::*)(MMUTarget *)> {
public:
    void thunk(CBFunctorBase& f) { cb_thunk0(f); }
};

// 0x803B897C (120 bytes)
template <> class CBMemberTranslator0<MODTarget, void (MODTarget::*)(MODTarget *)> {
public:
    void thunk(CBFunctorBase& f) { cb_thunk0(f); }
};

// 0x803B8C4C (120 bytes)
template <> class CBMemberTranslator0<MOTTarget, void (MOTTarget::*)(MOTTarget *)> {
public:
    void thunk(CBFunctorBase& f) { cb_thunk0(f); }
};

// 0x803BBF50 (120 bytes)
template <> class CBMemberTranslator0<MSGTarget, void (UIObjectBase::*)(UIObjectBase *)> {
public:
    void thunk(CBFunctorBase& f) { cb_thunk0(f); }
};

// 0x803B9084 (120 bytes)
template <> class CBMemberTranslator0<O2TTarget, void (O2TTarget::*)(O2TTarget *)> {
public:
    void thunk(CBFunctorBase& f) { cb_thunk0(f); }
};

// 0x803B8EA4 (120 bytes)
template <> class CBMemberTranslator0<O2TTarget, void (UIObjectBase::*)(UIObjectBase *)> {
public:
    void thunk(CBFunctorBase& f) { cb_thunk0(f); }
};

// 0x803BC1A8 (120 bytes)
template <> class CBMemberTranslator0<OPTTarget, void (OPTTarget::*)(OPTTarget *)> {
public:
    void thunk(CBFunctorBase& f) { cb_thunk0(f); }
};

// 0x803B9264 (120 bytes)
template <> class CBMemberTranslator0<PAZTarget, void (PAZBase::*)(PAZBase *)> {
public:
    void thunk(CBFunctorBase& f) { cb_thunk0(f); }
};

// 0x803B9818 (120 bytes)
template <> class CBMemberTranslator0<PCTTarget, void (PCTTarget::*)(PCTTarget *)> {
public:
    void thunk(CBFunctorBase& f) { cb_thunk0(f); }
};

// 0x803BC400 (120 bytes)
template <> class CBMemberTranslator0<PDATarget, void (PDATarget::*)(PDATarget *)> {
public:
    void thunk(CBFunctorBase& f) { cb_thunk0(f); }
};

// 0x803BC568 (120 bytes)
template <> class CBMemberTranslator0<PDATarget, void (UIDialog::*)(UIDialog *)> {
public:
    void thunk(CBFunctorBase& f) { cb_thunk0(f); }
};

// 0x803B9AE8 (120 bytes)
template <> class CBMemberTranslator0<PRGTarget, void (UIObjectBase::*)(UIObjectBase *)> {
public:
    void thunk(CBFunctorBase& f) { cb_thunk0(f); }
};

// 0x803BC760 (120 bytes)
template <> class CBMemberTranslator0<PSETarget, void (UIObjectBase::*)(UIObjectBase *)> {
public:
    void thunk(CBFunctorBase& f) { cb_thunk0(f); }
};

// 0x803B94BC (120 bytes)
template <> class CBMemberTranslator0<PZ1Target, void (PAZBase::*)(PAZBase *)> {
public:
    void thunk(CBFunctorBase& f) { cb_thunk0(f); }
};

// 0x803B9D40 (120 bytes)
template <> class CBMemberTranslator0<R2LTarget, void (R2LTarget::*)(R2LTarget *)> {
public:
    void thunk(CBFunctorBase& f) { cb_thunk0(f); }
};

// 0x803BA010 (120 bytes)
template <> class CBMemberTranslator0<RCPTarget, void (RCPTarget::*)(RCPTarget *)> {
public:
    void thunk(CBFunctorBase& f) { cb_thunk0(f); }
};

// 0x803BC9B8 (120 bytes)
template <> class CBMemberTranslator0<RELTarget, void (UIObjectBase::*)(UIObjectBase *)> {
public:
    void thunk(CBFunctorBase& f) { cb_thunk0(f); }
};

// 0x803BCC10 (120 bytes)
template <> class CBMemberTranslator0<RGTTarget, void (UIObjectBase::*)(UIObjectBase *)> {
public:
    void thunk(CBFunctorBase& f) { cb_thunk0(f); }
};

// 0x803BA268 (120 bytes)
template <> class CBMemberTranslator0<RMDTarget, void (RMDTarget::*)(RMDTarget *)> {
public:
    void thunk(CBFunctorBase& f) { cb_thunk0(f); }
};

// 0x803BA4C0 (120 bytes)
template <> class CBMemberTranslator0<SKLTarget, void (SKLTarget::*)(SKLTarget *)> {
public:
    void thunk(CBFunctorBase& f) { cb_thunk0(f); }
};

// 0x803BCE68 (120 bytes)
template <> class CBMemberTranslator0<SKNTarget, void (UIObjectBase::*)(UIObjectBase *)> {
public:
    void thunk(CBFunctorBase& f) { cb_thunk0(f); }
};

// 0x803B2CEC (120 bytes)
template <> class CBMemberTranslator0<SaveGameTarget, void (SaveGameTarget::*)(SaveGameTarget *)> {
public:
    void thunk(CBFunctorBase& f) { cb_thunk0(f); }
};

// 0x803B2E54 (120 bytes)
template <> class CBMemberTranslator0<SaveGameTarget, void (UIDialog::*)(UIDialog *)> {
public:
    void thunk(CBFunctorBase& f) { cb_thunk0(f); }
};

// 0x803B1084 (120 bytes)
template <> class CBMemberTranslator0<UI3D, void (UI3D::*)(UI3D *)> {
public:
    void thunk(CBFunctorBase& f) { cb_thunk0(f); }
};

// 0x803B1DD0 (120 bytes)
template <> class CBMemberTranslator0<UIAUDIOTarget, void (UIObjectBase::*)(UIObjectBase *)> {
public:
    void thunk(CBFunctorBase& f) { cb_thunk0(f); }
};

// 0x803B2028 (120 bytes)
template <> class CBMemberTranslator0<UIAnalog, void (UIObjectBase::*)(UIObjectBase *)> {
public:
    void thunk(CBFunctorBase& f) { cb_thunk0(f); }
};

// 0x803B1334 (120 bytes)
template <> class CBMemberTranslator0<UIDBTarget, void (UIObjectBase::*)(UIObjectBase *)> {
public:
    void thunk(CBFunctorBase& f) { cb_thunk0(f); }
};

// 0x803B38D8 (120 bytes)
template <> class CBMemberTranslator0<UIDialog, void (UIDialog::*)(UIDialog *)> {
public:
    void thunk(CBFunctorBase& f) { cb_thunk0(f); }
};

// 0x803B1920 (120 bytes)
template <> class CBMemberTranslator0<UIQDTarget, void (UIObjectBase::*)(UIObjectBase *)> {
public:
    void thunk(CBFunctorBase& f) { cb_thunk0(f); }
};

// 0x803B1B78 (120 bytes)
template <> class CBMemberTranslator0<UIScreenManager, void (UIScreenManager::*)(UIScreenManager *)> {
public:
    void thunk(CBFunctorBase& f) { cb_thunk0(f); }
};

// 0x803BA718 (120 bytes)
template <> class CBMemberTranslator0<WAFTarget, void (WAFTarget::*)(WAFTarget *)> {
public:
    void thunk(CBFunctorBase& f) { cb_thunk0(f); }
};

// 0x803BA970 (120 bytes)
template <> class CBMemberTranslator0<WXFTarget, void (WXFTarget::*)(WXFTarget *)> {
public:
    void thunk(CBFunctorBase& f) { cb_thunk0(f); }
};


// ============================================================================
// CBMemberTranslator1 specializations (78 instantiations)
// ============================================================================
// Each one calls cb_thunk1() — the bodies are identical, only types differ.
// The extra argument (ERC* or int) is passed through r4 untouched by the thunk.

// --- ERC* specializations (61 instantiations) ---

// 0x803B5E98 (120 bytes)
template <> class CBMemberTranslator1<ERC *, ACTTarget, void (UIObjectBase::*)(UIObjectBase *, ERC *)> {
public:
    void thunk(CBFunctorBase& f, ERC* arg) { cb_thunk1(f, arg); }
};

// 0x803B60F0 (120 bytes)
template <> class CBMemberTranslator1<ERC *, BBHTarget, void (UIObjectBase::*)(UIObjectBase *, ERC *)> {
public:
    void thunk(CBFunctorBase& f, ERC* arg) { cb_thunk1(f, arg); }
};

// 0x803B3B30 (120 bytes)
template <> class CBMemberTranslator1<ERC *, CASBodyTarget, void (UIObjectBase::*)(UIObjectBase *, ERC *)> {
public:
    void thunk(CBFunctorBase& f, ERC* arg) { cb_thunk1(f, arg); }
};

// 0x803B4238 (120 bytes)
template <> class CBMemberTranslator1<ERC *, CASFashionTarget, void (UIObjectBase::*)(UIObjectBase *, ERC *)> {
public:
    void thunk(CBFunctorBase& f, ERC* arg) { cb_thunk1(f, arg); }
};

// 0x803B3D88 (120 bytes)
template <> class CBMemberTranslator1<ERC *, CASGeneticsTarget, void (CASGeneticsTarget::*)(CASGeneticsTarget *, ERC *)> {
public:
    void thunk(CBFunctorBase& f, ERC* arg) { cb_thunk1(f, arg); }
};

// 0x803B4490 (120 bytes)
template <> class CBMemberTranslator1<ERC *, CASMiscTarget, void (UIObjectBase::*)(UIObjectBase *, ERC *)> {
public:
    void thunk(CBFunctorBase& f, ERC* arg) { cb_thunk1(f, arg); }
};

// 0x803B46E8 (120 bytes)
template <> class CBMemberTranslator1<ERC *, CASMorphTarget, void (UIObjectBase::*)(UIObjectBase *, ERC *)> {
public:
    void thunk(CBFunctorBase& f, ERC* arg) { cb_thunk1(f, arg); }
};

// 0x803B4940 (120 bytes)
template <> class CBMemberTranslator1<ERC *, CASPersonalTarget, void (UIObjectBase::*)(UIObjectBase *, ERC *)> {
public:
    void thunk(CBFunctorBase& f, ERC* arg) { cb_thunk1(f, arg); }
};

// 0x803B4DF0 (120 bytes)
template <> class CBMemberTranslator1<ERC *, CASRoommateTarget, void (CASRoommateTarget::*)(CASRoommateTarget *, ERC *)> {
public:
    void thunk(CBFunctorBase& f, ERC* arg) { cb_thunk1(f, arg); }
};

// 0x803B3FE0 (120 bytes)
template <> class CBMemberTranslator1<ERC *, CASSelectionTarget, void (UIObjectBase::*)(UIObjectBase *, ERC *)> {
public:
    void thunk(CBFunctorBase& f, ERC* arg) { cb_thunk1(f, arg); }
};

// 0x803B37E8 (120 bytes)
template <> class CBMemberTranslator1<ERC *, CASTarget, void (CASTarget::*)(CASTarget *, ERC *)> {
public:
    void thunk(CBFunctorBase& f, ERC* arg) { cb_thunk1(f, arg); }
};

// 0x803B4B98 (120 bytes)
template <> class CBMemberTranslator1<ERC *, CASTattooTarget, void (UIObjectBase::*)(UIObjectBase *, ERC *)> {
public:
    void thunk(CBFunctorBase& f, ERC* arg) { cb_thunk1(f, arg); }
};

// 0x803B646C (120 bytes)
template <> class CBMemberTranslator1<ERC *, CRDTarget, void (CRDTarget::*)(CRDTarget *, ERC *)> {
public:
    void thunk(CBFunctorBase& f, ERC* arg) { cb_thunk1(f, arg); }
};

// 0x803B673C (120 bytes)
template <> class CBMemberTranslator1<ERC *, CSMTarget, void (UIObjectBase::*)(UIObjectBase *, ERC *)> {
public:
    void thunk(CBFunctorBase& f, ERC* arg) { cb_thunk1(f, arg); }
};

// 0x803B6994 (120 bytes)
template <> class CBMemberTranslator1<ERC *, CSPTarget, void (UIObjectBase::*)(UIObjectBase *, ERC *)> {
public:
    void thunk(CBFunctorBase& f, ERC* arg) { cb_thunk1(f, arg); }
};

// 0x803B6BEC (120 bytes)
template <> class CBMemberTranslator1<ERC *, E2ETarget, void (UIObjectBase::*)(UIObjectBase *, ERC *)> {
public:
    void thunk(CBFunctorBase& f, ERC* arg) { cb_thunk1(f, arg); }
};

// 0x803BB050 (120 bytes)
template <> class CBMemberTranslator1<ERC *, EYETarget, void (UIObjectBase::*)(UIObjectBase *, ERC *)> {
public:
    void thunk(CBFunctorBase& f, ERC* arg) { cb_thunk1(f, arg); }
};

// 0x803B7058 (120 bytes)
template <> class CBMemberTranslator1<ERC *, FAMTarget, void (UIObjectBase::*)(UIObjectBase *, ERC *)> {
public:
    void thunk(CBFunctorBase& f, ERC* arg) { cb_thunk1(f, arg); }
};

// 0x803B7328 (120 bytes)
template <> class CBMemberTranslator1<ERC *, FCMTarget, void (UIObjectBase::*)(UIObjectBase *, ERC *)> {
public:
    void thunk(CBFunctorBase& f, ERC* arg) { cb_thunk1(f, arg); }
};

// 0x803BB320 (120 bytes)
template <> class CBMemberTranslator1<ERC *, FONTarget, void (UIObjectBase::*)(UIObjectBase *, ERC *)> {
public:
    void thunk(CBFunctorBase& f, ERC* arg) { cb_thunk1(f, arg); }
};

// 0x803B1638 (120 bytes)
template <> class CBMemberTranslator1<ERC *, FlowGotoTarget, void (UIObjectBase::*)(UIObjectBase *, ERC *)> {
public:
    void thunk(CBFunctorBase& f, ERC* arg) { cb_thunk1(f, arg); }
};

// 0x803B75CC (120 bytes)
template <> class CBMemberTranslator1<ERC *, G2DTarget, void (UIObjectBase::*)(UIObjectBase *, ERC *)> {
public:
    void thunk(CBFunctorBase& f, ERC* arg) { cb_thunk1(f, arg); }
};

// 0x803BB578 (120 bytes)
template <> class CBMemberTranslator1<ERC *, GOLTarget, void (GOLTarget::*)(GOLTarget *, ERC *)> {
public:
    void thunk(CBFunctorBase& f, ERC* arg) { cb_thunk1(f, arg); }
};

// 0x803B7824 (120 bytes)
template <> class CBMemberTranslator1<ERC *, H2DTarget, void (H2DTarget::*)(H2DTarget *, ERC *)> {
public:
    void thunk(CBFunctorBase& f, ERC* arg) { cb_thunk1(f, arg); }
};

// 0x803B2778 (120 bytes)
template <> class CBMemberTranslator1<ERC *, HUDTarget, void (HUDTarget::*)(HUDTarget *, ERC *)> {
public:
    void thunk(CBFunctorBase& f, ERC* arg) { cb_thunk1(f, arg); }
};

// 0x803B7A7C (120 bytes)
template <> class CBMemberTranslator1<ERC *, INGTarget, void (UIObjectBase::*)(UIObjectBase *, ERC *)> {
public:
    void thunk(CBFunctorBase& f, ERC* arg) { cb_thunk1(f, arg); }
};

// 0x803BBB18 (120 bytes)
template <> class CBMemberTranslator1<ERC *, INTTarget, void (UIObjectBase::*)(UIObjectBase *, ERC *)> {
public:
    void thunk(CBFunctorBase& f, ERC* arg) { cb_thunk1(f, arg); }
};

// 0x803BB8C0 (120 bytes)
template <> class CBMemberTranslator1<ERC *, INVTarget, void (INVTarget::*)(INVTarget *, ERC *)> {
public:
    void thunk(CBFunctorBase& f, ERC* arg) { cb_thunk1(f, arg); }
};

// 0x803B7D4C (120 bytes)
template <> class CBMemberTranslator1<ERC *, ITBTarget, void (UIObjectBase::*)(UIObjectBase *, ERC *)> {
public:
    void thunk(CBFunctorBase& f, ERC* arg) { cb_thunk1(f, arg); }
};

// 0x803B7FA4 (120 bytes)
template <> class CBMemberTranslator1<ERC *, K2YTarget, void (UIObjectBase::*)(UIObjectBase *, ERC *)> {
public:
    void thunk(CBFunctorBase& f, ERC* arg) { cb_thunk1(f, arg); }
};

// 0x803BBD70 (120 bytes)
template <> class CBMemberTranslator1<ERC *, KEYTarget, void (UIObjectBase::*)(UIObjectBase *, ERC *)> {
public:
    void thunk(CBFunctorBase& f, ERC* arg) { cb_thunk1(f, arg); }
};

// 0x803B2A04 (120 bytes)
template <> class CBMemberTranslator1<ERC *, LoadGameTarget, void (UIObjectBase::*)(UIObjectBase *, ERC *)> {
public:
    void thunk(CBFunctorBase& f, ERC* arg) { cb_thunk1(f, arg); }
};

// 0x803B81FC (120 bytes)
template <> class CBMemberTranslator1<ERC *, M2MTarget, void (UIObjectBase::*)(UIObjectBase *, ERC *)> {
public:
    void thunk(CBFunctorBase& f, ERC* arg) { cb_thunk1(f, arg); }
};

// 0x803B84CC (120 bytes)
template <> class CBMemberTranslator1<ERC *, MDITarget, void (UIObjectBase::*)(UIObjectBase *, ERC *)> {
public:
    void thunk(CBFunctorBase& f, ERC* arg) { cb_thunk1(f, arg); }
};

// 0x803B8724 (120 bytes)
template <> class CBMemberTranslator1<ERC *, MMUTarget, void (MMUTarget::*)(MMUTarget *, ERC *)> {
public:
    void thunk(CBFunctorBase& f, ERC* arg) { cb_thunk1(f, arg); }
};

// 0x803B89F4 (120 bytes)
template <> class CBMemberTranslator1<ERC *, MODTarget, void (UIObjectBase::*)(UIObjectBase *, ERC *)> {
public:
    void thunk(CBFunctorBase& f, ERC* arg) { cb_thunk1(f, arg); }
};

// 0x803B8CC4 (120 bytes)
template <> class CBMemberTranslator1<ERC *, MOTTarget, void (UIObjectBase::*)(UIObjectBase *, ERC *)> {
public:
    void thunk(CBFunctorBase& f, ERC* arg) { cb_thunk1(f, arg); }
};

// 0x803BBFC8 (120 bytes)
template <> class CBMemberTranslator1<ERC *, MSGTarget, void (UIObjectBase::*)(UIObjectBase *, ERC *)> {
public:
    void thunk(CBFunctorBase& f, ERC* arg) { cb_thunk1(f, arg); }
};

// 0x803B8F1C (120 bytes)
template <> class CBMemberTranslator1<ERC *, O2TTarget, void (UIObjectBase::*)(UIObjectBase *, ERC *)> {
public:
    void thunk(CBFunctorBase& f, ERC* arg) { cb_thunk1(f, arg); }
};

// 0x803BC220 (120 bytes)
template <> class CBMemberTranslator1<ERC *, OPTTarget, void (UIObjectBase::*)(UIObjectBase *, ERC *)> {
public:
    void thunk(CBFunctorBase& f, ERC* arg) { cb_thunk1(f, arg); }
};

// 0x803B92DC (120 bytes)
template <> class CBMemberTranslator1<ERC *, PAZTarget, void (UIObjectBase::*)(UIObjectBase *, ERC *)> {
public:
    void thunk(CBFunctorBase& f, ERC* arg) { cb_thunk1(f, arg); }
};

// 0x803B9890 (120 bytes)
template <> class CBMemberTranslator1<ERC *, PCTTarget, void (PCTTarget::*)(PCTTarget *, ERC *)> {
public:
    void thunk(CBFunctorBase& f, ERC* arg) { cb_thunk1(f, arg); }
};

// 0x803BC478 (120 bytes)
template <> class CBMemberTranslator1<ERC *, PDATarget, void (UIObjectBase::*)(UIObjectBase *, ERC *)> {
public:
    void thunk(CBFunctorBase& f, ERC* arg) { cb_thunk1(f, arg); }
};

// 0x803B9B60 (120 bytes)
template <> class CBMemberTranslator1<ERC *, PRGTarget, void (UIObjectBase::*)(UIObjectBase *, ERC *)> {
public:
    void thunk(CBFunctorBase& f, ERC* arg) { cb_thunk1(f, arg); }
};

// 0x803BC7D8 (120 bytes)
template <> class CBMemberTranslator1<ERC *, PSETarget, void (UIObjectBase::*)(UIObjectBase *, ERC *)> {
public:
    void thunk(CBFunctorBase& f, ERC* arg) { cb_thunk1(f, arg); }
};

// 0x803B9534 (120 bytes)
template <> class CBMemberTranslator1<ERC *, PZ1Target, void (UIObjectBase::*)(UIObjectBase *, ERC *)> {
public:
    void thunk(CBFunctorBase& f, ERC* arg) { cb_thunk1(f, arg); }
};

// 0x803B9DB8 (120 bytes)
template <> class CBMemberTranslator1<ERC *, R2LTarget, void (UIObjectBase::*)(UIObjectBase *, ERC *)> {
public:
    void thunk(CBFunctorBase& f, ERC* arg) { cb_thunk1(f, arg); }
};

// 0x803BA088 (120 bytes)
template <> class CBMemberTranslator1<ERC *, RCPTarget, void (RCPTarget::*)(RCPTarget *, ERC *)> {
public:
    void thunk(CBFunctorBase& f, ERC* arg) { cb_thunk1(f, arg); }
};

// 0x803BCA30 (120 bytes)
template <> class CBMemberTranslator1<ERC *, RELTarget, void (UIObjectBase::*)(UIObjectBase *, ERC *)> {
public:
    void thunk(CBFunctorBase& f, ERC* arg) { cb_thunk1(f, arg); }
};

// 0x803BCC88 (120 bytes)
template <> class CBMemberTranslator1<ERC *, RGTTarget, void (UIObjectBase::*)(UIObjectBase *, ERC *)> {
public:
    void thunk(CBFunctorBase& f, ERC* arg) { cb_thunk1(f, arg); }
};

// 0x803BA2E0 (120 bytes)
template <> class CBMemberTranslator1<ERC *, RMDTarget, void (UIObjectBase::*)(UIObjectBase *, ERC *)> {
public:
    void thunk(CBFunctorBase& f, ERC* arg) { cb_thunk1(f, arg); }
};

// 0x803BA538 (120 bytes)
template <> class CBMemberTranslator1<ERC *, SKLTarget, void (UIObjectBase::*)(UIObjectBase *, ERC *)> {
public:
    void thunk(CBFunctorBase& f, ERC* arg) { cb_thunk1(f, arg); }
};

// 0x803BCEE0 (120 bytes)
template <> class CBMemberTranslator1<ERC *, SKNTarget, void (UIObjectBase::*)(UIObjectBase *, ERC *)> {
public:
    void thunk(CBFunctorBase& f, ERC* arg) { cb_thunk1(f, arg); }
};

// 0x803B2D64 (120 bytes)
template <> class CBMemberTranslator1<ERC *, SaveGameTarget, void (UIObjectBase::*)(UIObjectBase *, ERC *)> {
public:
    void thunk(CBFunctorBase& f, ERC* arg) { cb_thunk1(f, arg); }
};

// 0x803B1E48 (120 bytes)
template <> class CBMemberTranslator1<ERC *, UIAUDIOTarget, void (UIObjectBase::*)(UIObjectBase *, ERC *)> {
public:
    void thunk(CBFunctorBase& f, ERC* arg) { cb_thunk1(f, arg); }
};

// 0x803B20A0 (120 bytes)
template <> class CBMemberTranslator1<ERC *, UIAnalog, void (UIObjectBase::*)(UIObjectBase *, ERC *)> {
public:
    void thunk(CBFunctorBase& f, ERC* arg) { cb_thunk1(f, arg); }
};

// 0x803B13AC (120 bytes)
template <> class CBMemberTranslator1<ERC *, UIDBTarget, void (UIObjectBase::*)(UIObjectBase *, ERC *)> {
public:
    void thunk(CBFunctorBase& f, ERC* arg) { cb_thunk1(f, arg); }
};

// 0x803B1998 (120 bytes)
template <> class CBMemberTranslator1<ERC *, UIQDTarget, void (UIObjectBase::*)(UIObjectBase *, ERC *)> {
public:
    void thunk(CBFunctorBase& f, ERC* arg) { cb_thunk1(f, arg); }
};

// 0x803B1BF0 (120 bytes)
template <> class CBMemberTranslator1<ERC *, UIScreenManager, void (UIObjectBase::*)(UIObjectBase *, ERC *)> {
public:
    void thunk(CBFunctorBase& f, ERC* arg) { cb_thunk1(f, arg); }
};

// 0x803BA790 (120 bytes)
template <> class CBMemberTranslator1<ERC *, WAFTarget, void (UIObjectBase::*)(UIObjectBase *, ERC *)> {
public:
    void thunk(CBFunctorBase& f, ERC* arg) { cb_thunk1(f, arg); }
};

// 0x803BA9E8 (120 bytes)
template <> class CBMemberTranslator1<ERC *, WXFTarget, void (UIObjectBase::*)(UIObjectBase *, ERC *)> {
public:
    void thunk(CBFunctorBase& f, ERC* arg) { cb_thunk1(f, arg); }
};

// --- int specializations (17 instantiations) ---

// 0x803B3860 (120 bytes)
template <> class CBMemberTranslator1<int, CASTarget, void (CASTarget::*)(CASTarget *, int)> {
public:
    void thunk(CBFunctorBase& f, int arg) { cb_thunk1(f, arg); }
};

// 0x803B6CDC (120 bytes)
template <> class CBMemberTranslator1<int, E2ETarget, void (E2ETarget::*)(E2ETarget *, int)> {
public:
    void thunk(CBFunctorBase& f, int arg) { cb_thunk1(f, arg); }
};

// 0x803A3028 (120 bytes)
template <> class CBMemberTranslator1<int, EdithDialogPrimitive, void (EdithDialogPrimitive::*)(EdithDialogPrimitive *, int)> {
public:
    void thunk(CBFunctorBase& f, int arg) { cb_thunk1(f, arg); }
};

// 0x803B70D0 (120 bytes)
template <> class CBMemberTranslator1<int, FAMTarget, void (FAMTarget::*)(FAMTarget *, int)> {
public:
    void thunk(CBFunctorBase& f, int arg) { cb_thunk1(f, arg); }
};

// 0x803B0F2C (120 bytes)
template <> class CBMemberTranslator1<int, HelpDialog, void (HelpDialog::*)(HelpDialog *, int)> {
public:
    void thunk(CBFunctorBase& f, int arg) { cb_thunk1(f, arg); }
};

// 0x803B8F94 (120 bytes)
template <> class CBMemberTranslator1<int, HelpDialog, void (UIDialog::*)(UIDialog *, int)> {
public:
    void thunk(CBFunctorBase& f, int arg) { cb_thunk1(f, arg); }
};

// 0x803B7AF4 (120 bytes)
template <> class CBMemberTranslator1<int, INGTarget, void (INGTarget::*)(INGTarget *, int)> {
public:
    void thunk(CBFunctorBase& f, int arg) { cb_thunk1(f, arg); }
};

// 0x803BB5F0 (120 bytes)
template <> class CBMemberTranslator1<int, INVTarget, void (INVTarget::*)(INVTarget *, int)> {
public:
    void thunk(CBFunctorBase& f, int arg) { cb_thunk1(f, arg); }
};

// 0x803B2A7C (120 bytes)
template <> class CBMemberTranslator1<int, LoadGameTarget, void (LoadGameTarget::*)(LoadGameTarget *, int)> {
public:
    void thunk(CBFunctorBase& f, int arg) { cb_thunk1(f, arg); }
};

// 0x803B8274 (120 bytes)
template <> class CBMemberTranslator1<int, M2MTarget, void (M2MTarget::*)(M2MTarget *, int)> {
public:
    void thunk(CBFunctorBase& f, int arg) { cb_thunk1(f, arg); }
};

// 0x803B879C (120 bytes)
template <> class CBMemberTranslator1<int, MMUTarget, void (MMUTarget::*)(MMUTarget *, int)> {
public:
    void thunk(CBFunctorBase& f, int arg) { cb_thunk1(f, arg); }
};

// 0x803B900C (120 bytes)
template <> class CBMemberTranslator1<int, O2TTarget, void (O2TTarget::*)(O2TTarget *, int)> {
public:
    void thunk(CBFunctorBase& f, int arg) { cb_thunk1(f, arg); }
};

// 0x803B9908 (120 bytes)
template <> class CBMemberTranslator1<int, PCTTarget, void (PCTTarget::*)(PCTTarget *, int)> {
public:
    void thunk(CBFunctorBase& f, int arg) { cb_thunk1(f, arg); }
};

// 0x803BC4F0 (120 bytes)
template <> class CBMemberTranslator1<int, PDATarget, void (PDATarget::*)(PDATarget *, int)> {
public:
    void thunk(CBFunctorBase& f, int arg) { cb_thunk1(f, arg); }
};

// 0x803B9E30 (120 bytes)
template <> class CBMemberTranslator1<int, R2LTarget, void (R2LTarget::*)(R2LTarget *, int)> {
public:
    void thunk(CBFunctorBase& f, int arg) { cb_thunk1(f, arg); }
};

// 0x803B2DDC (120 bytes)
template <> class CBMemberTranslator1<int, SaveGameTarget, void (SaveGameTarget::*)(SaveGameTarget *, int)> {
public:
    void thunk(CBFunctorBase& f, int arg) { cb_thunk1(f, arg); }
};

// 0x803BB6E0 (120 bytes)
template <> class CBMemberTranslator1<int, UIDialog, void (UIDialog::*)(UIDialog *, int)> {
public:
    void thunk(CBFunctorBase& f, int arg) { cb_thunk1(f, arg); }
};
