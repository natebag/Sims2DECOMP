// objectsim.cpp - Decompiled small functions from objectsim.obj
// Original: c:\BuildAgent\cm3-build22-NGC\CMBuild\output\obj\u2_ngc_release_dvd\objectsim.obj
//
// 9 small functions (<=64 bytes) decompiled
// objectsim.obj contains 112 total functions, 25 are small (<=64 bytes),
// but many are data items or compiler-generated. 9 are code functions.

#include "objects/objectsim.h"
#include "objects/object.h"

// ============================================================================
// External references
// ============================================================================

// BString2 destructor (at 0x800A1D70)
extern void BString2_dtor(void* str, int mode);

// cXObject::BreakpointPending (at 0x80147F90)
extern void cXObject_BreakpointPending(void* obj);

// __static_initialization_and_destruction_0 for objectsim (at 0x8010FB78)
extern void __static_initialization_and_destruction_0_objectsim_impl(int action, int priority);

// Global string at r13 offset -24232 (0xA158)
// extern BString2 g_objectsim_staticString;

// Job HUD name table constant pointer (at 0x803EC248)
// lis r3, 0x803E(-32706) / addi r3, -15800
static char* s_jobHUDNameTable = (char*)0x803EC248;

// ============================================================================
// __tcf_0 (static destructor for objectsim BString2)
// Address: 0x800F9A34, Size: 40 bytes
// NON_MATCHING - SDA-relative access for static string
// Destroys a static BString2 object
// ============================================================================
// This is a compiler-generated cleanup function.
// Calls BString2 destructor on a static string at r13-24232.

// ============================================================================
// cXObjectImpl::HandleBreakpoint
// Address: 0x800F9F20, Size: 36 bytes
// NON_MATCHING - function call through this->m_object pointer
// Delegates to cXObject::BreakpointPending via the object pointer at +0x00
// ============================================================================
// void cXObjectImpl::HandleBreakpoint(StackElem* stack, BehaviorNode* node) {
//     cXObject* obj = *(cXObject**)this;  // load object pointer from +0x00
//     cXObject_BreakpointPending(obj);
// }

// ============================================================================
// cXObjectImpl::InterpValue (5-param overload)
// Address: 0x8010AAA4, Size: 36 bytes
// NON_MATCHING - wrapper that calls 6-param version with r9=0 (NULL last param)
// ============================================================================
// void cXObjectImpl::InterpValue(short a, short b, short** c, float** d, short* e) {
//     this->InterpValue(a, b, c, d, e, NULL);
// }

// ============================================================================
// cXObjectImpl::TryUIEffect
// Address: 0x800FA1E8, Size: 12 bytes
// MATCHING
// Returns {r3=0, r4=1} - false with continue flag
// ============================================================================
// Returns 0 (false) in r3, 1 in r4
// This is a stub - UI effects not implemented in GC release

// ============================================================================
// cXObjectImpl::TryFindTreeNew
// Address: 0x8010D3BC, Size: 12 bytes
// MATCHING
// Returns {r3=0, r4=0} - false with no continue
// ============================================================================
// Returns 0 (false) in r3, 0 in r4
// This is a stub - FindTreeNew not implemented

// ============================================================================
// cXObjectImpl::Backtrace
// Address: 0x8010D5AC, Size: 4 bytes
// MATCHING
// Empty no-op function (debug feature stripped in release)
// ============================================================================
// void cXObjectImpl::Backtrace() { }

// ============================================================================
// GetJobHUDName
// Address: 0x8010EE64, Size: 12 bytes
// MATCHING
// Returns pointer to job HUD name table (constant address)
// ============================================================================
char* GetJobHUDName(short jobId) {
    return s_jobHUDNameTable;
}

// ============================================================================
// global constructors keyed to cXObjectImpl::overrideDialogReturnCode
// Address: 0x8010FD28, Size: 44 bytes
// NON_MATCHING - SDA access for calling __static_initialization_and_destruction_0
// Calls __static_initialization_and_destruction_0(1, 0xFFFF)
// ============================================================================

// ============================================================================
// global destructors keyed to cXObjectImpl::overrideDialogReturnCode
// Address: 0x8010FD54, Size: 44 bytes
// NON_MATCHING - SDA access for calling __static_initialization_and_destruction_0
// Calls __static_initialization_and_destruction_0(0, 0xFFFF)
// ============================================================================
