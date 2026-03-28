#if 0 // SKIP
// treetab.cpp - TreeTable, TTabScratchEntry, TreeTableAdScratch
// Decompiled from The Sims 2 GameCube (u2_ngc_release_dvd)
// Object file: treetab.obj

#include "treetab.h"

// ============================================================
// TreeTable
// ============================================================

// 801493b0 - 60 bytes
// TreeTable::GetNthEntry(int) const
const TreeTableEntry* TreeTable::GetNthEntry(int n) const {
    if (n < 0) return 0;

    int count = 0;
    TreeTableEntry* entries = m_pEntries;
    if (entries != 0) {
        count = ((int*)entries)[-1];
    }

    if (n >= count) return 0;

    return &entries[n];
}

// 801498b0 - 116 bytes
// NON_MATCHING - TreeTable::GetIndexOfResource - too complex for small func batch

// 80149924 - 92 bytes
// NON_MATCHING - TreeTable::GetIndexByTreeID - too complex for small func batch

// 80149980 - 60 bytes
// TreeTable::GetIndexOfNthOrderedEntry(int) const
int TreeTable::GetIndexOfNthOrderedEntry(int n) const {
    TreeTableEntry* entries = m_pEntries;
    int count = 0;
    if (entries != 0) {
        count = ((int*)entries)[-1];
    }
    if (n < 0) return -1;
    if (n >= count) return -1;

    return entries[n].m_index;
}

// ============================================================
// TreeTableAdScratch
// ============================================================

// 801499bc - 44 bytes
// TreeTableAdScratch::TreeTableAdScratch(void)
// NON_MATCHING - constructor needs exact vtable address, handled in linker

// 801499e8 - 52 bytes
// TreeTableAdScratch::~TreeTableAdScratch(void)
// NON_MATCHING - destructor needs exact vtable address

// 80149760 - 20 bytes
// TreeTableAdScratch::AddRef(void)
int TreeTableAdScratch::AddRef() {
    m_refCount++;
    return m_refCount;
}

// 80149b00 - 8 bytes
int TreeTableAdScratch::GetPersonalityAd() const {
    return m_personalityAd;
}

// 80149b08 - 8 bytes
void TreeTableAdScratch::SetPersonalityAd(int val) {
    m_personalityAd = (short)val;
}

// 80149b10 - 8 bytes
int TreeTableAdScratch::GetMin() const {
    return m_min;
}

// 80149b18 - 8 bytes
void TreeTableAdScratch::SetMin(int val) {
    m_min = (short)val;
}

// 80149b20 - 16 bytes
// GetMax returns min + range
int TreeTableAdScratch::GetMax() const {
    return m_min + m_range;
}

// 80149b30 - 16 bytes
// SetMax stores (val - min) as range
void TreeTableAdScratch::SetMax(int val) {
    m_range = (short)(val - (unsigned short)m_min);
}

// 80149b40 - 8 bytes
int TreeTableAdScratch::GetRange() const {
    return m_range;
}

// 80149b48 - 8 bytes
void TreeTableAdScratch::SetRange(int val) {
    m_range = (short)val;
}

// ============================================================
// TTabScratchEntry - simple getters/setters
// ============================================================

// 80149840 - 20 bytes
int TTabScratchEntry::AddRef() {
    m_refCount++;
    return m_refCount;
}

// 80149b50 - 8 bytes
short TTabScratchEntry::GetIndex() const {
    return m_index;
}

// 80149b58 - 12 bytes
// lhz r3, 0x110(r3); clrlwi r3, r3, 31; blr
bool TTabScratchEntry::GetAvailableToVisitors() const {
    return (unsigned short)m_flags & 1;
}

// 80149b64 - 32 bytes
void TTabScratchEntry::SetAvailableToVisitors(bool val) {
    unsigned short f = (unsigned short)m_flags;
    f &= ~1;
    m_flags = (short)f;
    if (val == 0) return;
    f |= 1;
    m_flags = (short)f;
}

// 80149b84 - 12 bytes
// lhz r3, 0x110(r3); rlwinm r3,r3,31,31,31; blr
bool TTabScratchEntry::GetCanJoin() const {
    return ((unsigned short)m_flags >> 1) & 1;
}

// 80149b90 - 32 bytes
void TTabScratchEntry::SetCanJoin(bool val) {
    unsigned short f = (unsigned short)m_flags;
    f &= ~2;
    m_flags = (short)f;
    if (val == 0) return;
    f |= 2;
    m_flags = (short)f;
}

// 80149bb0 - 12 bytes
bool TTabScratchEntry::GetImmediate() const {
    return ((unsigned short)m_flags >> 2) & 1;
}

// 80149bbc - 32 bytes
void TTabScratchEntry::SetImmediate(bool val) {
    unsigned short f = (unsigned short)m_flags;
    f &= ~4;
    m_flags = (short)f;
    if (val == 0) return;
    f |= 4;
    m_flags = (short)f;
}

// 80149bdc - 12 bytes
bool TTabScratchEntry::GetAllowConsecutive() const {
    return ((unsigned short)m_flags >> 3) & 1;
}

// 80149be8 - 32 bytes
void TTabScratchEntry::SetAllowConsecutive(bool val) {
    unsigned short f = (unsigned short)m_flags;
    f &= ~8;
    m_flags = (short)f;
    if (val == 0) return;
    f |= 8;
    m_flags = (short)f;
}

// 80149c08 - 12 bytes
bool TTabScratchEntry::GetAvailableToGhosts() const {
    return ((unsigned short)m_flags >> 4) & 1;
}

// 80149c14 - 32 bytes
void TTabScratchEntry::SetAvailableToGhosts(bool val) {
    unsigned short f = (unsigned short)m_flags;
    f &= ~0x10;
    m_flags = (short)f;
    if (val == 0) return;
    f |= 0x10;
    m_flags = (short)f;
}

// 80149c34 - 16 bytes
// xori r3, r3, 64; rlwinm r3, r3, 26, 31, 31 -> inverted bit 6
bool TTabScratchEntry::GetAvailableToAdults() const {
    return (((unsigned short)m_flags ^ 0x40) >> 6) & 1;
}

// 80149c44 - 32 bytes
// Note: SetAvailableToAdults uses inverted logic:
// clears bit 6 then sets it if val == 0 (i.e. bit 6 = NOT available)
void TTabScratchEntry::SetAvailableToAdults(bool val) {
    unsigned short f = (unsigned short)m_flags;
    f &= ~0x40;
    m_flags = (short)f;
    if (val != 0) return;  // Note: inverted! Sets bit when val is false
    f |= 0x40;
    m_flags = (short)f;
}

// 80149c64 - 12 bytes
bool TTabScratchEntry::GetAvailableToChildrenDemo() const {
    return ((unsigned short)m_flags >> 5) & 1;
}

// 80149c70 - 32 bytes
void TTabScratchEntry::SetAvailableToChildrenDemo(bool val) {
    unsigned short f = (unsigned short)m_flags;
    f &= ~0x20;
    m_flags = (short)f;
    if (val == 0) return;
    f |= 0x20;
    m_flags = (short)f;
}

// 80149c90 - 8 bytes
short TTabScratchEntry::GetJoinIndex() const {
    return m_joinIndex;
}

// 80149c98 - 8 bytes
void TTabScratchEntry::SetJoinIndex(int val) {
    m_joinIndex = (short)val;
}

// 80149ca0 - 12 bytes
bool TTabScratchEntry::GetDebugOnly() const {
    return ((unsigned short)m_flags >> 7) & 1;
}

// 80149cac - 32 bytes
void TTabScratchEntry::SetDebugOnly(bool val) {
    unsigned short f = (unsigned short)m_flags;
    f &= ~0x80;
    m_flags = (short)f;
    if (val == 0) return;
    f |= 0x80;
    m_flags = (short)f;
}

// 80149ccc - 12 bytes
bool TTabScratchEntry::GetAutoFirstSelect() const {
    return ((unsigned short)m_flags >> 8) & 1;
}

// 80149cd8 - 32 bytes
void TTabScratchEntry::SetAutoFirstSelect(bool val) {
    unsigned short f = (unsigned short)m_flags;
    f &= ~0x100;
    m_flags = (short)f;
    if (val == 0) return;
    f |= 0x100;
    m_flags = (short)f;
}

// 80149cf8 - 12 bytes
bool TTabScratchEntry::GetAvailableToVisitingPlayers() const {
    return ((unsigned short)m_flags >> 9) & 1;
}

// 80149d04 - 32 bytes
void TTabScratchEntry::SetAvailableToVisitingPlayers(bool val) {
    unsigned short f = (unsigned short)m_flags;
    f &= ~0x200;
    m_flags = (short)f;
    if (val == 0) return;
    f |= 0x200;
    m_flags = (short)f;
}

// 80149d24 - 12 bytes
bool TTabScratchEntry::GetIgnorePrefixTree() const {
    return ((unsigned short)m_flags >> 10) & 1;
}

// 80149d30 - 32 bytes
void TTabScratchEntry::SetIgnorePrefixTree(bool val) {
    unsigned short f = (unsigned short)m_flags;
    f &= ~0x400;
    m_flags = (short)f;
    if (val == 0) return;
    f |= 0x400;
    m_flags = (short)f;
}

// 80149d50 - 12 bytes
bool TTabScratchEntry::GetMustRun() const {
    return ((unsigned short)m_flags >> 11) & 1;
}

// 80149d5c - 32 bytes
void TTabScratchEntry::SetMustRun(bool val) {
    unsigned short f = (unsigned short)m_flags;
    f &= ~0x800;
    m_flags = (short)f;
    if (val == 0) return;
    f |= 0x800;
    m_flags = (short)f;
}

// 80149d7c - 20 bytes
// lha r0, 0x114(r3); cmpwi cr7, r0, 99; mfcr r3; rlwinm r3,r3,30,31,31
bool TTabScratchEntry::GetManualOnly() const {
    return m_autonomyThreshold == 99;
}

// 80149d90 - 8 bytes
int TTabScratchEntry::CountAds() const {
    return 16;
}

// 80149d98 - 20 bytes
// GetRangeRef(int) const - returns pointer to range field of ad[idx]
// slwi r4, r4, 4; addi r4, r4, 8; add r3, r3, r4; addi r3, r3, 8
short* TTabScratchEntry::GetRangeRef(int idx) const {
    return (short*)((char*)this + idx * 16 + 8 + 8);
}

// 80149dac - 20 bytes
// GetMinRef(int) const - returns pointer to min field of ad[idx]
// slwi r4, r4, 4; addi r4, r4, 8; add r3, r3, r4; addi r3, r3, 6
short* TTabScratchEntry::GetMinRef(int idx) const {
    return (short*)((char*)this + idx * 16 + 8 + 6);
}

// 80149dc0 - 20 bytes
// GetPersonalityVarRef(int) const
// slwi r4, r4, 4; addi r4, r4, 8; add r3, r3, r4; addi r3, r3, 4
short* TTabScratchEntry::GetPersonalityVarRef(int idx) const {
    return (short*)((char*)this + idx * 16 + 8 + 4);
}

// 80149dd4 - 20 bytes - non-const versions
short* TTabScratchEntry::GetRangeRef(int idx) {
    return (short*)((char*)this + idx * 16 + 8 + 8);
}

// 80149de8 - 20 bytes
short* TTabScratchEntry::GetMinRef(int idx) {
    return (short*)((char*)this + idx * 16 + 8 + 6);
}

// 80149dfc - 20 bytes
short* TTabScratchEntry::GetPersonalityVarRef(int idx) {
    return (short*)((char*)this + idx * 16 + 8 + 4);
}

// 80149e10 - 16 bytes
// GetAd(int) const
// slwi r4, r4, 4; addi r4, r4, 8; add r3, r3, r4; blr
const TTabScratchAd* TTabScratchEntry::GetAd(int idx) const {
    return (const TTabScratchAd*)((char*)this + idx * 16 + 8);
}

// 80149e20 - 16 bytes
// GetAd(int) - non-const
TTabScratchAd* TTabScratchEntry::GetAd(int idx) {
    return (TTabScratchAd*)((char*)this + idx * 16 + 8);
}

// 80149e78 - 8 bytes
short TTabScratchEntry::GetActionTreeID() const {
    return m_actionTreeID;
}

// 80149e80 - 8 bytes
void TTabScratchEntry::SetActionTreeID(short val) {
    m_actionTreeID = val;
}

// 80149e88 - 8 bytes
short TTabScratchEntry::GetCheckTreeID() const {
    return m_checkTreeID;
}

// 80149e90 - 8 bytes
void TTabScratchEntry::SetCheckTreeID(short val) {
    m_checkTreeID = val;
}

// 80149e98 - 8 bytes
int TTabScratchEntry::GetAttenuation() const {
    return m_attenuation;
}

// 80149ea0 - 8 bytes
void TTabScratchEntry::SetAttenuation(int val) {
    m_attenuation = (int)val;
}

// 80149ea8 - 8 bytes
float TTabScratchEntry::GetCustomAttenuationValue() const {
    return m_customAttenuationValue;
}

// 80149eb0 - 16 bytes
// li r0, 0; stfs f1, 0x10C(r3); stw r0, 0x108(r3)
void TTabScratchEntry::SetCustomAttenuation(float val) {
    m_customAttenuationValue = val;
    m_attenuation = 0;
}

// 80149ec0 - 8 bytes
short TTabScratchEntry::GetAutonomyThreshold() const {
    return m_autonomyThreshold;
}

// 80149ec8 - 8 bytes
void TTabScratchEntry::SetAutonomyThreshold(short val) {
    m_autonomyThreshold = val;
}

// 80149f1c - 4 bytes (just blr)
void TTabScratchEntry::SetName(BString2& name) {
    // Stub - does nothing
}

// 80149f20 - 8 bytes
short TTabScratchEntry::GetFlags() const {
    return m_flags;
}

// 80149f28 - 8 bytes
// li r3, 0; blr
int TTabScratchEntry::GetOrderIndex() const {
    return 0;
}

// 80149f30 - 4 bytes (just blr)
void TTabScratchEntry::SetOrderIndex(int val) {
    // Stub - does nothing
}

// 80149f34 - 8 bytes
// li r3, 0; blr
bool TTabScratchEntry::GetUseCustomActivation() const {
    return false;
}

// 80149f3c - 4 bytes (just blr)
void TTabScratchEntry::SetUseCustomActivation(bool val) {
    // Stub - does nothing
}

// 80149f40 - 4 bytes (just blr)
void TTabScratchEntry::GetActivationSubtile(unsigned char& x, unsigned char& y) const {
    // Stub - does nothing
}

// 80149f44 - 4 bytes (just blr)
void TTabScratchEntry::SetActivationSubtile(unsigned char x, unsigned char y) {
    // Stub - does nothing
}

// 80149f48 - 4 bytes (just blr)
void TTabScratchEntry::GetActivationExtents(unsigned char& a, unsigned char& b, unsigned char& c, unsigned char& d) const {
    // Stub - does nothing
}

// 80149f4c - 4 bytes (just blr)
void TTabScratchEntry::SetActivationExtents(unsigned char a, unsigned char b, unsigned char c, unsigned char d) {
    // Stub - does nothing
}
#endif
