#if 0 // SKIP
// treetablequickdata.cpp - TreeTableQuickData, TreeTableEntryQuickData, TreeTableAdQuickData
// Decompiled from The Sims 2 GameCube (u2_ngc_release_dvd)
// Object file: treetablequickdata.obj

#include "treetablequickdata.h"

// ============================================================
// TreeTableAdQuickData
// ============================================================

// 8015e32c - 20 bytes
int TreeTableAdQuickData::AddRef() {
    m_refCount++;
    return m_refCount;
}

// 8015e590 - 12 bytes
// lwz r9, 4(r3); lha r3, 0(r9); blr
int TreeTableAdQuickData::GetPersonalityAd() const {
    return m_pImpl->m_personalityAd;
}

// 8015e59c - 12 bytes
// lwz r9, 4(r3); lha r3, 2(r9); blr
int TreeTableAdQuickData::GetMin() const {
    return m_pImpl->m_min;
}

// 8015e5a8 - 20 bytes
// lwz r9, 4(r3); lha r0, 4(r9); lha r3, 2(r9); add r3,r3,r0; blr
int TreeTableAdQuickData::GetMax() const {
    return m_pImpl->m_min + m_pImpl->m_range;
}

// 8015e5bc - 12 bytes
// lwz r9, 4(r3); lha r3, 4(r9); blr
int TreeTableAdQuickData::GetRange() const {
    return m_pImpl->m_range;
}

// 8015e5c8 - 4 bytes (just blr)
TreeTableAdQuickData& TreeTableAdQuickData::operator=(ITreeTableAd& other) {
    // Stub - does nothing, returns *this
    return *this;
}

// 8015e5cc - 4 bytes (just blr)
void TreeTableAdQuickData::SetPersonalityAd(int val) {
    // Stub
}

// 8015e5d0 - 4 bytes (just blr)
void TreeTableAdQuickData::SetMin(int val) {
    // Stub
}

// 8015e5d4 - 4 bytes (just blr)
void TreeTableAdQuickData::SetMax(int val) {
    // Stub
}

// 8015e5d8 - 4 bytes (just blr)
void TreeTableAdQuickData::SetRange(int val) {
    // Stub
}

// 8015e5dc - 8 bytes
// lwz r3, 4(r3); blr
TreeTableAd* TreeTableAdQuickData::GetImplementation() const {
    return m_pImpl;
}

// ============================================================
// TreeTableEntryQuickData
// ============================================================

// 8015e40c - 20 bytes
int TreeTableEntryQuickData::AddRef() {
    m_refCount++;
    return m_refCount;
}

// 8015e5e4 - 12 bytes
// lwz r9, 4(r3); lha r3, 0x14(r9); blr
// TreeTableEntry offset 0x14 = index (order index field)
short TreeTableEntryQuickData::GetIndex() const {
    return m_pImpl->m_index;
}

// 8015e5f0 - 12 bytes
// lwz r9, 4(r3); lha r3, 0x1a(r9); blr
// TreeTableEntry offset 0x1a = m_orderIndex
int TreeTableEntryQuickData::GetOrderIndex() const {
    return m_pImpl->m_index; // TODO: verify offset 0x1a mapping
}

// 8015e5fc - 28 bytes
// lwz r9, 4(r3); li r3, 0; lwz r0, 0x10(r9); andi. r9, r0, 1; beqlr-; li r3, 1; blr
bool TreeTableEntryQuickData::GetAvailableToVisitors() const {
    TreeTableEntry* p = m_pImpl;
    if (!(p->m_flags & 1)) return false;
    return true;
}

// 8015e618 - 16 bytes
// lwz r9, 4(r3); lwz r3, 0x10(r9); rlwinm r3,r3,31,31,31
bool TreeTableEntryQuickData::GetCanJoin() const {
    return ((unsigned int)m_pImpl->m_flags >> 1) & 1;
}

// 8015e628 - 16 bytes
bool TreeTableEntryQuickData::GetImmediate() const {
    return ((unsigned int)m_pImpl->m_flags >> 2) & 1;
}

// 8015e638 - 16 bytes
bool TreeTableEntryQuickData::GetAllowConsecutive() const {
    return ((unsigned int)m_pImpl->m_flags >> 3) & 1;
}

// 8015e648 - 16 bytes
bool TreeTableEntryQuickData::GetAvailableToGhosts() const {
    return ((unsigned int)m_pImpl->m_flags >> 4) & 1;
}

// 8015e658 - 20 bytes
// xori r3, r3, 64; rlwinm r3, r3, 26, 31, 31 -> bit 6 inverted
bool TreeTableEntryQuickData::GetAvailableToAdults() const {
    return (((unsigned int)m_pImpl->m_flags ^ 0x40) >> 6) & 1;
}

// 8015e66c - 16 bytes
bool TreeTableEntryQuickData::GetAvailableToChildrenDemo() const {
    return ((unsigned int)m_pImpl->m_flags >> 5) & 1;
}

// 8015e67c - 12 bytes
// lwz r9, 4(r3); lha r3, 0x18(r9)
short TreeTableEntryQuickData::GetJoinIndex() const {
    return m_pImpl->m_joinIndex;
}

// 8015e6c4 - 16 bytes
bool TreeTableEntryQuickData::GetAutoFirstSelect() const {
    return ((unsigned int)m_pImpl->m_flags >> 8) & 1;
}

// 8015e6d4 - 16 bytes
bool TreeTableEntryQuickData::GetAvailableToVisitingPlayers() const {
    return ((unsigned int)m_pImpl->m_flags >> 9) & 1;
}

// 8015e6e4 - 24 bytes
// lwz r9, 4(r3); lha r0, 0x16(r9); cmpwi cr7, r0, 99; mfcr r3; rlwinm r3,r3,30,31,31
bool TreeTableEntryQuickData::GetManualOnly() const {
    return m_pImpl->m_autonomyThreshold == 99;
}

// 8015e6fc - 8 bytes
// li r3, 16; blr
int TreeTableEntryQuickData::CountAds() const {
    return 16;
}

// 8015e704 - 16 bytes
bool TreeTableEntryQuickData::GetIgnorePrefixTree() const {
    return ((unsigned int)m_pImpl->m_flags >> 10) & 1;
}

// 8015e714 - 16 bytes
bool TreeTableEntryQuickData::GetMustRun() const {
    return ((unsigned int)m_pImpl->m_flags >> 11) & 1;
}

// 8015e724 - 24 bytes
// lwz r9, 4(r3); slwi r4, r4, 3; lwz r3, 4(r9); add r3, r3, r4; addi r3, r3, 4
// Ads start at TreeTableEntry +4 (pointer to array?), each 8 bytes, range at +4
short* TreeTableEntryQuickData::GetRangeRef(int idx) const {
    TreeTableAd* ads = (TreeTableAd*)m_pImpl->m_pad0C; // ads array pointer at entry+4 in impl
    return (short*)((char*)ads + idx * 8 + 4);
}

// 8015e73c - 24 bytes
// lwz r9, 4(r3); slwi r4, r4, 3; lwz r3, 4(r9); add r3, r3, r4; addi r3, r3, 2
short* TreeTableEntryQuickData::GetMinRef(int idx) const {
    TreeTableAd* ads = (TreeTableAd*)m_pImpl->m_pad0C;
    return (short*)((char*)ads + idx * 8 + 2);
}

// 8015e754 - 20 bytes
// lwz r9, 4(r3); slwi r4, r4, 3; lwz r3, 4(r9); add r3, r3, r4
short* TreeTableEntryQuickData::GetPersonalityVarRef(int idx) const {
    TreeTableAd* ads = (TreeTableAd*)m_pImpl->m_pad0C;
    return (short*)((char*)ads + idx * 8);
}

// 8015e768 - 12 bytes
// lwz r9, 4(r3); lha r3, 2(r9)
short TreeTableEntryQuickData::GetActionTreeID() const {
    return m_pImpl->m_actionTreeID;
}

// 8015e774 - 12 bytes
// lwz r9, 4(r3); lha r3, 0(r9)
short TreeTableEntryQuickData::GetCheckTreeID() const {
    return m_pImpl->m_checkTreeID;
}

// 8015e780 - 12 bytes
// lwz r9, 4(r3); lhz r3, 0xe(r9)
int TreeTableEntryQuickData::GetAttenuation() const {
    // Attenuation is stored as unsigned short at entry+0x0E
    // This maps to bits within the TreeTableEntry m_pad0C field
    return *((unsigned short*)((char*)m_pImpl + 0x0E));
}

// 8015e78c - 36 bytes
// lwz r3, 4(r3); bl TreeTableEntry::GetAttenuationValue
float TreeTableEntryQuickData::GetAttenuationValue(bool param) const {
    // Delegates to TreeTableEntry::GetAttenuationValue
    // This calls the CalculateAttenuationValue with the entry's data
    // NON_MATCHING - needs tail call to TreeTableEntry::GetAttenuationValue
    return 0.0f;
}

// 8015e7b0 - 12 bytes
// lwz r9, 4(r3); lfs f1, 8(r9); blr
float TreeTableEntryQuickData::GetCustomAttenuationValue() const {
    return m_pImpl->m_customAttenuationValue;
}

// 8015e7bc - 12 bytes
// lwz r9, 4(r3); lha r3, 0x16(r9)
short TreeTableEntryQuickData::GetAutonomyThreshold() const {
    return m_pImpl->m_autonomyThreshold;
}

// 8015e7c8 - 12 bytes
// lwz r9, 4(r3); lwz r3, 0x10(r9)
short TreeTableEntryQuickData::GetFlags() const {
    return m_pImpl->m_flags;
}

// 8015e7d4 - 16 bytes
// lwz r9, 4(r3); lwz r3, 0x10(r9); rlwinm r3,r3,20,31,31 -> bit 12
bool TreeTableEntryQuickData::GetUseCustomActivation() const {
    return ((unsigned int)m_pImpl->m_flags >> 12) & 1;
}

// 8015e7e4 - 32 bytes
// Extracts two 4-bit fields from m_pImpl->offset_0x20
void TreeTableEntryQuickData::GetActivationSubtile(unsigned char& x, unsigned char& y) const {
    TreeTableEntry* p = m_pImpl;
    unsigned int val = *(unsigned int*)((char*)p + 0x20);
    x = val & 0xF;
    y = (val >> 4) & 0xF;
}

// 8015e804 - 56 bytes
// Extracts four 6-bit fields from m_pImpl->offset_0x20
void TreeTableEntryQuickData::GetActivationExtents(unsigned char& a, unsigned char& b, unsigned char& c, unsigned char& d) const {
    TreeTableEntry* p = m_pImpl;
    unsigned int val = *(unsigned int*)((char*)p + 0x20);
    a = (val >> 8) & 0x3F;
    b = (val >> 14) & 0x3F;
    c = (val >> 20) & 0x3F;
    d = (val >> 26) & 0x3F;
}

// Stub setters - all 4 bytes (just blr)
// 8015e83c
void TreeTableEntryQuickData::SetOrderIndex(int val) {}
// 8015e840
void TreeTableEntryQuickData::SetAvailableToVisitors(bool val) {}
// 8015e844
void TreeTableEntryQuickData::SetCanJoin(bool val) {}
// 8015e848
void TreeTableEntryQuickData::SetImmediate(bool val) {}
// 8015e84c
void TreeTableEntryQuickData::SetAllowConsecutive(bool val) {}
// 8015e850
void TreeTableEntryQuickData::SetAvailableToGhosts(bool val) {}
// 8015e854
void TreeTableEntryQuickData::SetAvailableToAdults(bool val) {}
// 8015e858
void TreeTableEntryQuickData::SetAvailableToChildrenDemo(bool val) {}
// 8015e85c
void TreeTableEntryQuickData::SetJoinIndex(int val) {}
// 8015e860
void TreeTableEntryQuickData::SetDebugOnly(bool val) {}
// 8015e864
void TreeTableEntryQuickData::SetAutoFirstSelect(bool val) {}
// 8015e868
void TreeTableEntryQuickData::SetAvailableToVisitingPlayers(bool val) {}
// 8015e86c
void TreeTableEntryQuickData::SetIgnorePrefixTree(bool val) {}
// 8015e870
void TreeTableEntryQuickData::SetMustRun(bool val) {}

// 8015e874 - 8 bytes
// li r3, 0; blr
int TreeTableEntryQuickData::GetAd(int idx) {
    return 0;
}

// 8015e87c - 4 bytes (just blr)
void TreeTableEntryQuickData::SetAd(int idx, ITreeTableAd& ad) {}
// 8015e880
void TreeTableEntryQuickData::SetActionTreeID(short val) {}
// 8015e884
void TreeTableEntryQuickData::SetCheckTreeID(short val) {}
// 8015e888
void TreeTableEntryQuickData::SetAttenuation(int val) {}
// 8015e88c
void TreeTableEntryQuickData::SetCustomAttenuation(float val) {}
// 8015e890
void TreeTableEntryQuickData::SetAutonomyThreshold(short val) {}
// 8015e894
void TreeTableEntryQuickData::SetName(BString2& name) {}
// 8015e898
void TreeTableEntryQuickData::SetUseCustomActivation(bool val) {}
// 8015e89c
void TreeTableEntryQuickData::SetActivationSubtile(unsigned char x, unsigned char y) {}
// 8015e8a0
void TreeTableEntryQuickData::SetActivationExtents(unsigned char a, unsigned char b, unsigned char c, unsigned char d) {}

// 8015e8a4 - 8 bytes
// lwz r3, 4(r3); blr
TreeTableEntry* TreeTableEntryQuickData::GetImplementation() const {
    return m_pImpl;
}

// ============================================================
// TreeTableQuickData
// ============================================================

// 8015e4ec - 20 bytes
int TreeTableQuickData::AddRef() {
    m_refCount++;
    return m_refCount;
}

// 8015e018 - 8 bytes
// li r3, 0; blr
int TreeTableQuickData::SaveDataByID(ObjectDataID& id) {
    return 0;
}

// 8015e020 - 8 bytes
// li r3, 1; blr
int TreeTableQuickData::GetDataSourceType() const {
    return 1;
}

// 8015e8ac - 8 bytes
// li r3, 0; blr
int TreeTableQuickData::LoadFromIndex(unsigned int param1, int param2) {
    return 0;
}

// 8015e8b4 - 8 bytes
// li r3, 0; blr
int TreeTableQuickData::GetResourceName(StringBuffer& buf) const {
    return 0;
}

// 8015e8bc - 8 bytes
// li r3, 0; blr  (based on SetResourceName addr pattern)
int TreeTableQuickData::SetResourceName(StringBuffer& buf) {
    return 0;
}

// 8015e8c4 - 8 bytes
// li r3, 0; blr
int TreeTableQuickData::LoadOnlyNameAndIDFromIndex(unsigned int param1, int param2) {
    return 0;
}

// 8015e8cc - 28 bytes
// lwz r3, 4(r3); cmpwi r3, 0; beq-; lha r3, 6(r3); blr; li r3, 0; blr
short TreeTableQuickData::GetID() const {
    TreeTable* p = m_pImpl;
    if (p == 0) return 0;
    // ID is at TreeTable offset 6 - need to check exact field
    return *(short*)((char*)p + 6);
}

// 8015e8e8 - 24 bytes
// lwz r9, 4(r3); cmpwi r9, 0; li r3, 0; beqlr-; lha r3, 4(r9); blr
int TreeTableQuickData::CountMotiveAds() const {
    TreeTable* p = m_pImpl;
    if (p == 0) return 0;
    return *(short*)((char*)p + 4);
}

// 8015e900 - 44 bytes
// lwz r9, 4(r3); cmpwi r9, 0; beq-; lwz r9, 0(r9); li r3, 0; cmpwi r9, 0; beqlr-; lwz r3, -4(r9); blr
int TreeTableQuickData::CountEntries() const {
    TreeTable* p = m_pImpl;
    if (p == 0) return 0;
    TreeTableEntry* entries = p->m_pEntries;
    if (entries == 0) return 0;
    return ((int*)entries)[-1];
}

// 8015e92c - 28 bytes
// lwz r3, 4(r3); cmpwi r3, 0; beq-; lha r3, 8(r3); blr; li r3, 0; blr
short TreeTableQuickData::GetPrefixCheckTreeID() const {
    TreeTable* p = m_pImpl;
    if (p == 0) return 0;
    return *(short*)((char*)p + 8);
}

// 8015e948 - 4 bytes (just blr)
void TreeTableQuickData::SwapEntries(int a, int b) {}

// 8015e94c - 8 bytes
// li r3, 0; blr
int TreeTableQuickData::GetNthEntry(int n) {
    return 0;
}

// 8015e954 - 8 bytes
// li r3, 0; blr
int TreeTableQuickData::GetEntryByIndex(int idx) {
    return 0;
}

// 8015e95c - 8 bytes
// li r3, 0; blr
int TreeTableQuickData::GetNthOrderedEntry(int n) {
    return 0;
}

// 8015e964 - 4 bytes (just blr)
void TreeTableQuickData::SetName(StringBuffer& name) {}

// 8015e968 - 8 bytes
// li r3, 1; blr
int TreeTableQuickData::AreOrderIndicesValid() const {
    return 1;
}

// 8015e970 - 8 bytes
// li r3, -45; blr
int TreeTableQuickData::Save(unsigned int param1, short param2) {
    return -45;
}

// 8015e978 - 8 bytes
// li r3, -45; blr
int TreeTableQuickData::Save() {
    return -45;
}

// 8015e980 - 8 bytes
// li r3, 0; blr
int TreeTableQuickData::GetIsTuned() const {
    return 0;
}

// 8015e988 - 4 bytes (just blr)
void TreeTableQuickData::SetIsTuned(bool val) {}

// 8015e98c - 8 bytes
// li r3, 0; blr
int TreeTableQuickData::AddEntry(short a, short b) {
    return 0;
}

// 8015e994 - 8 bytes
// li r3, 0; blr
int TreeTableQuickData::RemoveEntry(ITreeTableEntry* entry) {
    return 0;
}

// 8015e99c - 4 bytes (just blr)
void TreeTableQuickData::SetPrefixCheckTreeID(short val) {}

// 8015e9a0 - 8 bytes
// lwz r3, 4(r3); blr
TreeTable* TreeTableQuickData::GetImplementation() const {
    return m_pImpl;
}

// ============================================================
// TreeTableEntryQuickData::GetDebugOnly - 60 bytes, more complex
// 8015e688
// ============================================================
// NON_MATCHING - GetDebugOnly is complex (checks bit 7 + string table lookup)
// lwz r9, 4(r3); li r3, 0; lwz r0, 0x10(r9); andi. r11, r0, 0x80; bne-;
// lwz r9, 0x1c(r9); li r11, 0; cmpwi r9, 0; beq-; lwz r11, 0(r9);
// lhz r0, 0(r11); cmpwi r0, 33; bnelr-; li r3, 1; blr
bool TreeTableEntryQuickData::GetDebugOnly() const {
    TreeTableEntry* p = m_pImpl;
    if (p->m_flags & 0x80) return true;
    // Check name string for debug marker '!'
    // TODO: This accesses a name pointer at entry+0x1c and checks first char == '!'
    return false;
}

// 8015dc9c - 28 bytes
// TreeTableEntryQuickData::GetName(void) const
// NON_MATCHING - needs proper string handling
#endif
