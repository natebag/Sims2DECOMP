// uicore.cpp - Small functions (<=64 bytes) from UI core object files
// Sources: uibase.obj, uicore.obj, uiflow.obj, uisupport.obj, widgetsupport.obj,
//          ui2d.obj, ui3d.obj
//
// Compiled with: powerpc-eabi-g++ -mcpu=750 -meabi -mhard-float -O2
//                -fno-exceptions -fno-rtti -fno-builtin -fshort-wchar
//                -nostdinc++ -Iinclude -c

#include "ui/uicore.h"

// ============================================================================
// External function declarations
// ============================================================================
extern "C" {
    void* __builtin_new(unsigned int size);
    void __builtin_delete(void* ptr);
}

// AptViewer member functions - called via global AptViewer pointer
// Original code calls these as: aptViewer->Method(this_uiobj, player, ...)
// AptViewer::PushAptButtonFilter(int, char*) at 0x80011a48
// AptViewer::PopAptButtonFilter(int, unsigned int) at 0x80011b4c
// AptViewer::AddCmdToAptButtonFilter(int, unsigned int, ECTRL_CMD) at 0x80011c44
// AptViewer::RemoveCmdFromAptButtonFilter(int, unsigned int, ECTRL_CMD) at 0x80011ca8
namespace AptViewerFuncs {
    extern void PushAptButtonFilter(AptViewer* viewer, int player, char* name);
    extern void PopAptButtonFilter(AptViewer* viewer, int player, unsigned int id);
    extern void AddCmdToAptButtonFilter(AptViewer* viewer, int player, unsigned int id, ECTRL_CMD cmd);
    extern void RemoveCmdFromAptButtonFilter(AptViewer* viewer, int player, unsigned int id, ECTRL_CMD cmd);
}

// UIQDTarget::UIQDSubstitutionStrings(unsigned wchar_t*) at 0x8017c92c
extern void UIQDTarget_UIQDSubstitutionStrings(unsigned short* str);

// ============================================================================
// Globals - AptViewer pointer in _globals struct
// _globals at 0x80475dcc, AptViewer* at offset 0xB4 = 0x80475E80
// ============================================================================
struct GlobalsStruct {
    u8 _pad[0xB4];
    AptViewer* m_aptViewer; // 0xB4
};
extern GlobalsStruct _globals;

// ============================================================================
// UIObjectBase functions (from uibase.obj)
// NON_MATCHING: SN Systems compiles member function calls with different
// register shuffling than GCC for these thunk-style wrappers.
// The original saves this to r0, shuffles params for the AptViewer call.
// GCC generates a simpler tail call without the same register moves.
// ============================================================================

// 0x80177a64 - 52 bytes
// NON_MATCHING: register shuffling differs (SN saves this→r0, moves player→r5)
void UIObjectBase::pushAptButtonFilter(int player, char* name) {
    AptViewerFuncs::PushAptButtonFilter(_globals.m_aptViewer, player, name);
}

// 0x80177a98 - 52 bytes
// NON_MATCHING: same register shuffling issue as pushAptButtonFilter
void UIObjectBase::popAptButtonFilter(int player, unsigned int id) {
    AptViewerFuncs::PopAptButtonFilter(_globals.m_aptViewer, player, id);
}

// 0x80177acc - 60 bytes
// NON_MATCHING: same register shuffling issue
void UIObjectBase::addCmdToAptButtonFilter(int player, unsigned int id, ECTRL_CMD cmd) {
    AptViewerFuncs::AddCmdToAptButtonFilter(_globals.m_aptViewer, player, id, cmd);
}

// 0x80177b08 - 60 bytes
// NON_MATCHING: same register shuffling issue
void UIObjectBase::removeCmdFromAptButtonFilter(int player, unsigned int id, ECTRL_CMD cmd) {
    AptViewerFuncs::RemoveCmdFromAptButtonFilter(_globals.m_aptViewer, player, id, cmd);
}

// 0x80177ca8 - 32 bytes
// NON_MATCHING: GCC optimizes to a 4-byte tail call (b target),
// original SN Systems generates full 32-byte prologue/bl/epilogue.
// Static function - delegates to UIQDTarget::UIQDSubstitutionStrings
void UIObjectBase::doUIQDStringSubstitution(unsigned short* str) {
    UIQDTarget_UIQDSubstitutionStrings(str);
}

// ============================================================================
// GetVariableCommandTable singleton (from uicore.obj)
// ============================================================================

// 0x80178bf8 - 60 bytes
// NON_MATCHING: GCC uses absolute addressing for s_pInstance instead of
// r13-relative SDA addressing. Also generates early-return branch structure
// vs original's linear prologue-check-allocate-epilogue flow.
GetVariableCommandTable* GetVariableCommandTable::Instance() {
    if (s_pInstance == 0) {
        s_pInstance = new GetVariableCommandTable();
    }
    return s_pInstance;
}

// ============================================================================
// SetVariableCommandTable singleton (from uicore.obj)
// ============================================================================

// 0x80178c80 - 60 bytes
// NON_MATCHING: same SDA addressing issue as GetVariableCommandTable::Instance
SetVariableCommandTable* SetVariableCommandTable::Instance() {
    if (s_pInstance == 0) {
        s_pInstance = new SetVariableCommandTable();
    }
    return s_pInstance;
}

// ============================================================================
// GetLocalizableCommandTable singleton (from uicore.obj)
// ============================================================================

// 0x80178d08 - 60 bytes
// NON_MATCHING: same SDA addressing issue as GetVariableCommandTable::Instance
GetLocalizableCommandTable* GetLocalizableCommandTable::Instance() {
    if (s_pInstance == 0) {
        s_pInstance = new GetLocalizableCommandTable();
    }
    return s_pInstance;
}

// ============================================================================
// UI2D functions (from ui2d.obj)
// ============================================================================

// 0x80176628 - 48 bytes
// NON_MATCHING: GCC uses branchless cmpwi→addic→subfe pattern for != 0 test,
// original uses cmpwi→li r3,1→bne→li r3,0 conditional branches.
int UI2D::ContainsEntry(char* name) {
    if (FindEntry(name) != 0) {
        return 1;
    }
    return 0;
}

// 0x801767f8 - 60 bytes
// NON_MATCHING: SDA addressing (r13-relative vs absolute lis/lwz)
UI2D* UI2D::Instance() {
    if (s_pInstance == 0) {
        s_pInstance = new UI2D();
    }
    return s_pInstance;
}

// ============================================================================
// UI3D functions (from ui3d.obj)
// ============================================================================

// 0x80176f90 - 48 bytes
// NON_MATCHING: same branchless pattern issue as UI2D::ContainsEntry
int UI3D::ContainsEntry(char* name) {
    if (FindEntry(name) != 0) {
        return 1;
    }
    return 0;
}

// 0x80177004 - 52 bytes
// NON_MATCHING: original uses mr. (move and record) for null check,
// GCC uses cmpwi. Also original has explicit li r3,0 + branch for null path.
void* UI3D::GetDisplayObject(char* name) {
    UI3DRecord* record = FindEntry(name);
    if (record == 0) {
        return 0;
    }
    return record->m_displayObject;
}

// 0x80177038 - 60 bytes
// NON_MATCHING: SDA addressing
UI3D* UI3D::Instance() {
    if (s_pInstance == 0) {
        s_pInstance = new UI3D();
    }
    return s_pInstance;
}

// ============================================================================
// FlowGotoTarget functions (from uiflow.obj)
// ============================================================================

// 0x8017b960 - 32 bytes
// NON_MATCHING: GCC uses xor+addic+subfe branchless pattern,
// original uses li r11,1→cmpw→bne→li r11,0→mr r3,r11 conditional branches.
int FlowGotoTarget::IsStateRequestPending() {
    if (m_stateRequest == m_pendingState) {
        return 0;
    }
    return 1;
}

// 0x8017b980 - 8 bytes
int FlowGotoTarget::GetStateRequest() {
    return m_stateRequest;
}

// 0x8017b988 - 12 bytes
// NON_MATCHING: original uses r0 for temp, GCC uses r9
void FlowGotoTarget::SetPendingStateCurrent() {
    m_pendingState = m_stateRequest;
}

// ============================================================================
// UIButtonImages functions (from uisupport.obj)
// ============================================================================

// 0x801812ac - 52 bytes
// NON_MATCHING: SN Systems destructor ABI differs from GCC.
// Original: stores vtable ptr at this+0xB0, checks (r4 & 1) delete flag,
// conditionally calls __builtin_delete. GCC has different destructor dispatch.
UIButtonImages::~UIButtonImages() {
    // Body intentionally empty - SN Systems-specific vtable and delete handling
}

// 0x80181678 - 40 bytes
// NON_MATCHING: SDA addressing for instance pointer (r13-relative vs absolute).
// Also original uses addi+lfsx for array access, GCC uses add+lfs.
float UIButtonImages::GetButtonMinSize(int buttonId) {
    if (instance != 0) {
        return instance->m_buttonMinSizes[buttonId];
    }
    return 0.0f;
}

// ============================================================================
// WidgetScreenFormat functions (from widgetsupport.obj)
// ============================================================================

// 0x8018230c - 28 bytes
// NON_MATCHING: original copies r3→r9 first then uses r9 as base register,
// GCC uses r3 directly and r9 for the zero value. Different register allocation.
WidgetScreenFormat::WidgetScreenFormat() {
    m_field10 = 0;
    m_field1c = 0;
    m_field04 = 0;
    m_field00 = 0;
}
