#if 0 // SKIP
// interaction.cpp - Sim interaction system
// Object file: interaction.obj
// Small functions (<= 64 bytes) decompiled from Sims 2 GameCube
//
// Matching status (devkitPPC GCC vs original SN Systems):
//   MATCHING: All Get* flag accessors (32 functions byte-match)
//   NON_MATCHING: All Set* flag mutators (GCC branch structure differs)
//   NON_MATCHING: SetStackVars (register allocation r0/r9 vs r9)
//   NON_MATCHING: SetUniqueID (SDA vs absolute addressing)
//   NON_MATCHING: HasID (branch vs arithmetic boolean)
//   NON_MATCHING: SetTextColor (register allocation r0 vs r9)
//   NON_MATCHING: SetName (depends on BString2)
//   NON_MATCHING: __tcf_0, __tcf_1 (static initializers)

#include "sim/interaction.h"

// External functions referenced by __tcf_0 and __tcf_1
// __tcf_0 calls BString2::~BString2 (0x800A1D70) on static s at r13-0x5F8C
// __tcf_1 calls some destructor (0x800B4724) on static at r13-0x5F84
extern void _BString2_dtor(void* obj, int mode);
extern void _StaticObj_dtor(void* obj, int mode);

// Static member
int Interaction::sLastUniqueID; // at 0x804FDC08

// ============================================================================
// __tcf_0 - Static destructor for BString2 object at r13-0x5F8C
// Address: 0x800C1040 | Size: 40 bytes
// ============================================================================
// NON_MATCHING - static initializer/destroyer, calls external BString2 dtor
static void __tcf_0() {
    // Calls BString2::~BString2 on a static BString2 object
    // Cannot match without knowing exact static object layout
}

// ============================================================================
// Interaction::SetStackVars - Copy 4 shorts from source to stack vars
// Address: 0x800C1780 | Size: 36 bytes
// NON_MATCHING - register allocation (original alternates r0/r9, GCC uses only r9)
// ============================================================================
void Interaction::SetStackVars(short* vars) {
    m_stackVars[0] = vars[0];
    m_stackVars[1] = vars[1];
    m_stackVars[2] = vars[2];
    m_stackVars[3] = vars[3];
}

// ============================================================================
// Interaction::SetUniqueID - Increment and assign unique ID
// Address: 0x800C189C | Size: 20 bytes
// NON_MATCHING - original uses r13-relative (SDA) for sLastUniqueID,
// GCC uses absolute addressing. Also store order differs.
// ============================================================================
void Interaction::SetUniqueID() {
    sLastUniqueID++;
    m_uniqueID = sLastUniqueID;
}

// ============================================================================
// Interaction::SetName(BString2 &) - Set interaction name from BString2
// Address: 0x800C1960 | Size: 60 bytes
// Calls BString2 copy/assign at 0x800A1DC8 on m_name (+0x34)
// Then sets FLAG_NAME_CHANGED in m_flags
// ============================================================================
// NON_MATCHING - depends on BString2 assignment operator
void Interaction::SetName(BString2& name) {
    // BString2 copy/assign on m_name
    // External call to BString2::operator= at 0x800A1DC8
    // Then: m_flags |= FLAG_NAME_CHANGED;
    // Cannot match without BString2 implementation
}

// ============================================================================
// Interaction::GetStackObject - Return stack object pointer
// Address: 0x800C1C74 | Size: 8 bytes
// lwz r3,12(r3); blr
// ============================================================================
cXObject* Interaction::GetStackObject() const {
    return m_pStackObject;
}

// ============================================================================
// Interaction::GetPerson - Return person pointer
// Address: 0x800C1C7C | Size: 8 bytes
// lwz r3,8(r3); blr
// ============================================================================
cXPerson* Interaction::GetPerson() const {
    return m_pPerson;
}

// ============================================================================
// Interaction::GetIconObject - Return icon object pointer
// Address: 0x800C1C84 | Size: 8 bytes
// lwz r3,16(r3); blr
// ============================================================================
cXObject* Interaction::GetIconObject() const {
    return m_pIconObject;
}

// ============================================================================
// Interaction::SetIconObject - Set icon object pointer
// Address: 0x800C1C8C | Size: 8 bytes
// stw r4,16(r3); blr
// ============================================================================
void Interaction::SetIconObject(cXObject* obj) {
    m_pIconObject = obj;
}

// ============================================================================
// __tcf_1 - Static destructor for object at r13-0x5F84
// Address: 0x800C1C94 | Size: 40 bytes
// ============================================================================
// NON_MATCHING - static initializer/destroyer

// ============================================================================
// Interaction::GetTextColor - Extract 3-bit color from flags bits 12-14
// Address: 0x800C1D20 | Size: 12 bytes
// lwz r3,60(r3); rlwinm r3,r3,20,29,31; blr
// ============================================================================
int Interaction::GetTextColor() const {
    return (tColor)((m_flags >> FLAG_TEXT_COLOR_SHIFT) & 7);
}

// ============================================================================
// Interaction::SetTextColor - Set 3-bit color in flags bits 12-14
// Address: 0x800C1D2C | Size: 24 bytes
// NON_MATCHING - register allocation (original uses r0, GCC uses r9)
// ============================================================================
void Interaction::SetTextColor(tColor color) {
    m_flags = (m_flags & ~FLAG_TEXT_COLOR_MASK) | (((int)color) << FLAG_TEXT_COLOR_SHIFT);
}

// ============================================================================
// Interaction::GetType - Return interaction type
// Address: 0x800C1D44 | Size: 8 bytes
// lwz r3,4(r3); blr
// ============================================================================
int Interaction::GetType() {
    return m_type;
}

// ============================================================================
// Interaction::GetAttenuation - Return attenuation float
// Address: 0x800C1D4C | Size: 8 bytes
// lfs f1,48(r3); blr
// ============================================================================
float Interaction::GetAttenuation() const {
    return m_attenuation;
}

// ============================================================================
// Interaction::GetTreeID - Return tree ID (sign-extended short)
// Address: 0x800C1D54 | Size: 8 bytes
// lha r3,44(r3); blr
// ============================================================================
short Interaction::GetTreeID() const {
    return m_treeID;
}

// ============================================================================
// Interaction::GetStackVars - Return pointer to stack vars array
// Address: 0x800C1D5C | Size: 8 bytes
// addi r3,r3,24; blr
// ============================================================================
short* Interaction::GetStackVars() {
    return m_stackVars;
}

// ============================================================================
// Interaction::GetLocalVars - Return pointer to local vars
// Address: 0x800C1D64 | Size: 8 bytes
// lwz r3,36(r3); blr
// ============================================================================
short* Interaction::GetLocalVars() {
    return m_pLocalVars;
}

// ============================================================================
// Interaction::GetLocalVarsCount - Return number of local vars
// Address: 0x800C1D6C | Size: 8 bytes
// lwz r3,32(r3); blr
// ============================================================================
int Interaction::GetLocalVarsCount() {
    return m_localVarsCount;
}

// ============================================================================
// Interaction::GetTreeTabEntryIndex - Return tree table entry index
// Address: 0x800C1D74 | Size: 8 bytes
// lwz r3,20(r3); blr
// ============================================================================
int Interaction::GetTreeTabEntryIndex() const {
    return m_treeTabEntryIndex;
}

// ============================================================================
// Interaction::GetPriority - Return priority value
// Address: 0x800C1D7C | Size: 8 bytes
// lwz r3,40(r3); blr
// ============================================================================
int Interaction::GetPriority() const {
    return m_priority;
}

// ============================================================================
// Interaction::SetPriority - Set priority value
// Address: 0x800C1D84 | Size: 8 bytes
// stw r4,40(r3); blr
// ============================================================================
void Interaction::SetPriority(int priority) {
    m_priority = priority;
}

// ============================================================================
// Interaction::HasID - Check if unique ID is non-zero
// Address: 0x800C1D8C | Size: 24 bytes
// NON_MATCHING - original uses branch (li/cmpwi/bnelr/li), GCC uses addic/subfe
// ============================================================================
bool Interaction::HasID() const {
    return m_uniqueID != 0;
}

// ============================================================================
// Interaction::GetID - Return unique ID
// Address: 0x800C1DA4 | Size: 8 bytes
// lwz r3,56(r3); blr
// ============================================================================
int Interaction::GetID() const {
    return m_uniqueID;
}

// ============================================================================
// Interaction::SetID - Set unique ID
// Address: 0x800C1DAC | Size: 8 bytes
// stw r4,56(r3); blr
// ============================================================================
void Interaction::SetID(int id) {
    m_uniqueID = id;
}

// ============================================================================
// Interaction::GetAutoFirstSelect
// Address: 0x800C1DB4 | Size: 12 bytes
// lwz r3,60(r3); clrlwi r3,r3,31; blr
// ============================================================================
bool Interaction::GetAutoFirstSelect() const {
    return (m_flags & FLAG_AUTO_FIRST_SELECT) != 0;
}

// ============================================================================
// Interaction::SetAutoFirstSelect
// Address: 0x800C1DC0 | Size: 32 bytes
// NON_MATCHING - GCC branch structure differs from SN Systems (clear-first vs set-first)
// ============================================================================
void Interaction::SetAutoFirstSelect(bool val) {
    m_flags &= ~FLAG_AUTO_FIRST_SELECT;
    if (val) {
        m_flags |= FLAG_AUTO_FIRST_SELECT;
    }
}

// ============================================================================
// Interaction::GetContinuation
// Address: 0x800C1DE0 | Size: 12 bytes
// ============================================================================
bool Interaction::GetContinuation() const {
    return (m_flags & FLAG_CONTINUATION) != 0;
}

// ============================================================================
// Interaction::SetContinuation
// Address: 0x800C1DEC | Size: 32 bytes
// NON_MATCHING - GCC branch structure differs from SN Systems
// ============================================================================
void Interaction::SetContinuation(bool val) {
    m_flags &= ~FLAG_CONTINUATION;
    if (val) {
        m_flags |= FLAG_CONTINUATION;
    }
}

// ============================================================================
// Interaction::GetChecked
// Address: 0x800C1E0C | Size: 12 bytes
// ============================================================================
bool Interaction::GetChecked() const {
    return (m_flags & FLAG_CHECKED) != 0;
}

// ============================================================================
// Interaction::SetChecked
// Address: 0x800C1E18 | Size: 32 bytes
// NON_MATCHING - GCC branch structure differs from SN Systems
// ============================================================================
void Interaction::SetChecked(bool val) {
    m_flags &= ~FLAG_CHECKED;
    if (val) {
        m_flags |= FLAG_CHECKED;
    }
}

// ============================================================================
// Interaction::GetAvailable
// Address: 0x800C1E38 | Size: 12 bytes
// ============================================================================
bool Interaction::GetAvailable() const {
    return (m_flags & FLAG_AVAILABLE) != 0;
}

// ============================================================================
// Interaction::SetAvailable
// Address: 0x800C1E44 | Size: 32 bytes
// NON_MATCHING - GCC branch structure differs from SN Systems
// ============================================================================
void Interaction::SetAvailable(bool val) {
    m_flags &= ~FLAG_AVAILABLE;
    if (val) {
        m_flags |= FLAG_AVAILABLE;
    }
}

// ============================================================================
// Interaction::GetHidden
// Address: 0x800C1E64 | Size: 12 bytes
// ============================================================================
bool Interaction::GetHidden() const {
    return (m_flags & FLAG_HIDDEN) != 0;
}

// ============================================================================
// Interaction::SetHidden
// Address: 0x800C1E70 | Size: 32 bytes
// NON_MATCHING - GCC branch structure differs from SN Systems
// ============================================================================
void Interaction::SetHidden(bool val) {
    m_flags &= ~FLAG_HIDDEN;
    if (val) {
        m_flags |= FLAG_HIDDEN;
    }
}

// ============================================================================
// Interaction::GetPushToHead
// Address: 0x800C1E90 | Size: 12 bytes
// ============================================================================
bool Interaction::GetPushToHead() const {
    return (m_flags & FLAG_PUSH_TO_HEAD) != 0;
}

// ============================================================================
// Interaction::SetPushToHead
// Address: 0x800C1E9C | Size: 32 bytes
// NON_MATCHING - GCC branch structure differs from SN Systems
// ============================================================================
void Interaction::SetPushToHead(bool val) {
    m_flags &= ~FLAG_PUSH_TO_HEAD;
    if (val) {
        m_flags |= FLAG_PUSH_TO_HEAD;
    }
}

// ============================================================================
// Interaction::GetCarryNameOver
// Address: 0x800C1EBC | Size: 12 bytes
// ============================================================================
bool Interaction::GetCarryNameOver() const {
    return (m_flags & FLAG_CARRY_NAME_OVER) != 0;
}

// ============================================================================
// Interaction::SetCarryNameOver
// Address: 0x800C1EC8 | Size: 32 bytes
// NON_MATCHING - GCC branch structure differs from SN Systems
// ============================================================================
void Interaction::SetCarryNameOver(bool val) {
    m_flags &= ~FLAG_CARRY_NAME_OVER;
    if (val) {
        m_flags |= FLAG_CARRY_NAME_OVER;
    }
}

// ============================================================================
// Interaction::GetNameChanged
// Address: 0x800C1EE8 | Size: 12 bytes
// ============================================================================
bool Interaction::GetNameChanged() const {
    return (m_flags & FLAG_NAME_CHANGED) != 0;
}

// ============================================================================
// Interaction::SetNameChanged
// Address: 0x800C1EF4 | Size: 32 bytes
// NON_MATCHING - GCC branch structure differs from SN Systems
// ============================================================================
void Interaction::SetNameChanged(bool val) {
    m_flags &= ~FLAG_NAME_CHANGED;
    if (val) {
        m_flags |= FLAG_NAME_CHANGED;
    }
}

// ============================================================================
// Interaction::GetCancelled
// Address: 0x800C1F14 | Size: 12 bytes
// ============================================================================
bool Interaction::GetCancelled() const {
    return (m_flags & FLAG_CANCELLED) != 0;
}

// ============================================================================
// Interaction::SetCancelled
// Address: 0x800C1F20 | Size: 32 bytes
// NON_MATCHING - GCC branch structure differs from SN Systems
// ============================================================================
void Interaction::SetCancelled(bool val) {
    m_flags &= ~FLAG_CANCELLED;
    if (val) {
        m_flags |= FLAG_CANCELLED;
    }
}

// ============================================================================
// Interaction::GetDebugOverride
// Address: 0x800C1F40 | Size: 12 bytes
// ============================================================================
bool Interaction::GetDebugOverride() const {
    return (m_flags & FLAG_DEBUG_OVERRIDE) != 0;
}

// ============================================================================
// Interaction::SetDebugOverride
// Address: 0x800C1F4C | Size: 32 bytes
// NON_MATCHING - GCC branch structure differs from SN Systems
// ============================================================================
void Interaction::SetDebugOverride(bool val) {
    m_flags &= ~FLAG_DEBUG_OVERRIDE;
    if (val) {
        m_flags |= FLAG_DEBUG_OVERRIDE;
    }
}

// ============================================================================
// Interaction::GetMustRun
// Address: 0x800C1F6C | Size: 12 bytes
// ============================================================================
bool Interaction::GetMustRun() const {
    return (m_flags & FLAG_MUST_RUN) != 0;
}

// ============================================================================
// Interaction::SetMustRun
// Address: 0x800C1F78 | Size: 32 bytes
// NON_MATCHING - GCC branch structure differs from SN Systems
// ============================================================================
void Interaction::SetMustRun(bool val) {
    m_flags &= ~FLAG_MUST_RUN;
    if (val) {
        m_flags |= FLAG_MUST_RUN;
    }
}

// ============================================================================
// Interaction::GetDisabled
// Address: 0x800C1F98 | Size: 12 bytes
// ============================================================================
bool Interaction::GetDisabled() const {
    return (m_flags & FLAG_DISABLED) != 0;
}

// ============================================================================
// Interaction::SetDisabled
// Address: 0x800C1FA4 | Size: 32 bytes
// NON_MATCHING - GCC branch structure differs from SN Systems
// ============================================================================
void Interaction::SetDisabled(bool val) {
    m_flags &= ~FLAG_DISABLED;
    if (val) {
        m_flags |= FLAG_DISABLED;
    }
}

// ============================================================================
// Interaction::GetRunAsSub
// Address: 0x800C1FC4 | Size: 12 bytes
// rlwinm r3,r3,17,31,31 = extract bit 15
// ============================================================================
bool Interaction::GetRunAsSub() const {
    return (m_flags & FLAG_RUN_AS_SUB) != 0;
}

// ============================================================================
// Interaction::SetRunAsSub
// Address: 0x800C1FD0 | Size: 32 bytes
// NON_MATCHING - GCC branch structure differs from SN Systems
// ============================================================================
void Interaction::SetRunAsSub(bool val) {
    m_flags &= ~FLAG_RUN_AS_SUB;
    if (val) {
        m_flags |= FLAG_RUN_AS_SUB;
    }
}

// ============================================================================
// Interaction::GetFlags - Return raw flags value
// Address: 0x800C1FF0 | Size: 8 bytes
// lwz r3,60(r3); blr
// ============================================================================
int Interaction::GetFlags() const {
    return m_flags;
}

// ============================================================================
// Interaction::SetFlags - Set raw flags value
// Address: 0x800C1FF8 | Size: 8 bytes
// stw r4,60(r3); blr
// ============================================================================
void Interaction::SetFlags(int flags) {
    m_flags = flags;
}

// ============================================================================
// Interaction::SetShader - Stub, always returns 0
// Address: 0x800C2000 | Size: 8 bytes
// li r3,0; blr
// ============================================================================
int Interaction::SetShader(EActionIcon* icon) const {
    return 0;
}
#endif
