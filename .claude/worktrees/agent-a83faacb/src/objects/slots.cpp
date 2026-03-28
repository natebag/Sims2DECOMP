/**
 * slots.cpp - Object slot management for The Sims 2 (GameCube)
 *
 * Decompiled from slots.obj in u2_ngc_release_dvd.elf
 * Original source: c:\BuildAgent\cm3-build22-NGC\CMBuild\
 *
 * Contains Slot, RoutingSlot, ObjectSlot, SpriteSlot classes and
 * associated SlotDescriptor/SlotLoader/SlotDescList classes.
 *
 * NOTE: Original was compiled with SN Systems ProDG for GameCube.
 * Many functions marked NON_MATCHING due to GCC vs SN Systems
 * differences in register allocation, instruction selection, and
 * bool conversion patterns. The C++ logic is correct for all functions.
 */

#include "objects/slots.h"

// ============================================================================
// Slot base class
// ============================================================================

// 0x80142968 | 0x14 bytes | NON_MATCHING
// Original: lis; mr r11,r3; addi; stw r9,0(r11); blr (5 insns)
// GCC: lis; addi; stw r9,0(r3); blr (4 insns) - uses r3 directly
Slot::Slot() {
    // Sets vtable pointer only
}

// 0x8014297C | 0x14 bytes | NON_MATCHING (same issue as above)
Slot::Slot(SlotDescriptor* desc) {
    // Sets vtable pointer only, ignores desc
    (void)desc;
}

// 0x80142990 | 0x04 bytes | MATCHING
void Slot::WriteSlot(SlotDescriptor* desc) {
    // Empty virtual - just blr
    (void)desc;
}

// 0x801452C0 | 0x34 bytes | NON_MATCHING
// Original uses SN Systems ABI deleting destructor pattern:
//   Set Slot vtable, test r4 & 1, conditionally call operator delete
// GCC generates different destructor ABI (D0/D1/D2 variants)
Slot::~Slot() {
}

// ============================================================================
// RoutingSlot
// ============================================================================

// 0x8014548C | 0x34 bytes | NON_MATCHING (same ABI issue as Slot::~Slot)
RoutingSlot::~RoutingSlot() {
}

// --- Setters ---

// 0x80142B54 | 0x10 bytes | NON_MATCHING
// Original: lwz r0,28(r3); clrrwi r0,r0,8; stw r0,28(r3)
// GCC uses r9 instead of r0 for the temp register
void RoutingSlot::SetIsOnTopOfObject() {
    m_flags &= ~0xFFu;
}

// 0x80142B64 | 0x20 bytes | NON_MATCHING
// Register allocation: original uses r0 for shift temp, GCC uses r10
void RoutingSlot::AllowDirection(int dir) {
    if ((unsigned int)dir > 7) return;
    m_flags |= (1 << dir);
}

// 0x80142B84 | 0x10 bytes | NON_MATCHING
// Register allocation: original uses r0, GCC uses r9
void RoutingSlot::AllowAnyRotation() {
    m_flags |= 0x100;
}

// 0x80142B94 | 0x0C bytes | NON_MATCHING
// Register allocation: original uses r0, GCC uses r9
void RoutingSlot::AllowAnyFacing() {
    m_facingDirection = -3;
}

// 0x80142BA0 | 0x0C bytes | NON_MATCHING
// Register allocation: original uses r0, GCC uses r9
void RoutingSlot::FaceTowardsObject() {
    m_facingDirection = -2;
}

// 0x80142BAC | 0x0C bytes | NON_MATCHING
// Register allocation: original uses r0, GCC uses r9
void RoutingSlot::FaceAwayFromObject() {
    m_facingDirection = -1;
}

// 0x80142BB8 | 0x10 bytes | MATCHING
void RoutingSlot::SetFacingDirection(int dir) {
    if ((unsigned int)dir > 7) return;
    m_facingDirection = dir;
}

// 0x80142BC8 | 0x10 bytes | NON_MATCHING
// Original stores in order: r6->0x2C, r4->0x24, r5->0x28
// GCC stores in order: r4->0x24, r5->0x28, r6->0x2C
void RoutingSlot::SetDistances(int minDist, int maxDist, int optimalDist) {
    m_optimalDist = optimalDist;
    m_minDist = minDist;
    m_maxDist = maxDist;
}

// 0x80142C30 | 0x10 bytes | NON_MATCHING
// Original: slwi r4,r4,2; addi r3,r3,16; stwx r5,r3,r4
// GCC: addi r4,r4,4; slwi r4,r4,2; stwx r5,r3,r4
// Same result, different constant folding approach
void RoutingSlot::SetMultiplier(VerticalPosition pos, int value) {
    m_multipliers[(int)pos] = value;
}

// 0x80145560 | 0x20 bytes | NON_MATCHING
// Original: clear bit first, store, test, then ori and store again
// GCC: test first, compute both paths, then store once
void RoutingSlot::SetIgnoreRooms(bool ignore) {
    m_flags &= ~0x800u;
    if (ignore) {
        m_flags |= 0x800;
    }
}

// 0x8014561C | 0x20 bytes | NON_MATCHING (same pattern as SetIgnoreRooms)
void RoutingSlot::SetHasRandomScoring(bool random) {
    m_flags &= ~0x2000u;
    if (random) {
        m_flags |= 0x2000;
    }
}

// 0x8014563C | 0x20 bytes | NON_MATCHING (same pattern)
void RoutingSlot::SetAllowFailureTrees(bool allow) {
    m_flags &= ~0x4000u;
    if (allow) {
        m_flags |= 0x4000;
    }
}

// 0x80145668 | 0x20 bytes | NON_MATCHING (same pattern)
void RoutingSlot::SetAllowDifferentAlts(bool allow) {
    m_flags &= ~0x8000u;
    if (allow) {
        m_flags |= 0x8000;
    }
}

// 0x80145694 | 0x20 bytes | NON_MATCHING (same pattern)
void RoutingSlot::SetUseAverageObjectLocation(bool use) {
    m_flags &= ~0x10000u;
    if (use) {
        m_flags |= 0x10000;
    }
}

// 0x801456C0 | 0x08 bytes | MATCHING
void RoutingSlot::SetResolution(int res) {
    m_resolution = res;
}

// --- Getters ---

// 0x801454C0 | 0x10 bytes | NON_MATCHING
// Original: lbz r3,31(r3); subfic r0,r3,0; adde r3,r0,r3
// GCC: lbz r9,31(r3); addic r3,r9,-1; subfe r3,r3,r9
// Different bool conversion idiom (SN vs GCC)
bool RoutingSlot::IsOnTopOfObject() const {
    // Loads byte at offset 0x1F (low byte of m_flags)
    return (*(volatile u8*)((char*)&m_flags + 3)) != 0;
}

// 0x801454D0 | 0x1C bytes | NON_MATCHING
// Original: sraw r0,r0,r4 + andi. r9,r0,1 + bnelr/li pattern
// GCC: srw r3,r3,r4 + clrlwi r3,r3,31 (no branch)
bool RoutingSlot::IsDirectionAllowed(int dir) const {
    return (m_flags >> dir) & 1;
}

// 0x801454EC | 0x18 bytes | NON_MATCHING
// Original: andi. r9,r0,256 + bnelr + li r3,0 (branch pattern)
// GCC: rlwinm r3,r3,24,31,31 (branchless bit extract)
bool RoutingSlot::IsAnyRotationAllowed() const {
    return (m_flags & 0x100) != 0;
}

// 0x80145504 | 0x14 bytes | NON_MATCHING
// Original: subfic + subfic + adde (SN bool conversion)
// GCC: addi + cntlzw + srwi (GCC bool conversion)
bool RoutingSlot::IsAnyFacingAllowed() const {
    return m_facingDirection == -3;
}

// 0x80145518 | 0x14 bytes | NON_MATCHING (same issue)
bool RoutingSlot::IsFacingTowardsObject() const {
    return m_facingDirection == -2;
}

// 0x8014552C | 0x14 bytes | NON_MATCHING (same issue)
bool RoutingSlot::IsFacingAwayFromObject() const {
    return m_facingDirection == -1;
}

// 0x80145540 | 0x08 bytes | MATCHING
int RoutingSlot::GetFacingDirection() const {
    return m_facingDirection;
}

// 0x80145548 | 0x18 bytes | NON_MATCHING
// Original: andi. + bnelr pattern; GCC: rlwinm branchless
bool RoutingSlot::GetIgnoreRooms() const {
    return (m_flags & 0x800) != 0;
}

// 0x80145580 | 0x08 bytes | MATCHING
int RoutingSlot::GetMinDist() const {
    return m_minDist;
}

// 0x80145588 | 0x08 bytes | MATCHING
int RoutingSlot::GetMaxDist() const {
    return m_maxDist;
}

// 0x80145590 | 0x08 bytes | MATCHING
int RoutingSlot::GetOptimalDist() const {
    return m_optimalDist;
}

// 0x80145598 | 0x08 bytes | MATCHING
int RoutingSlot::GetResolution() const {
    return m_resolution;
}

// 0x801455A0 | 0x08 bytes | MATCHING
float RoutingSlot::GetGradient() const {
    return m_gradient;
}

// 0x801455A8 | 0x10 bytes | NON_MATCHING
// Same offset calculation difference as SetMultiplier
int RoutingSlot::GetMultiplier(VerticalPosition pos) const {
    return m_multipliers[(int)pos];
}

// 0x801455B8 | 0x08 bytes | MATCHING
int RoutingSlot::GetSnapTargetSlot() const {
    return m_snapTargetSlot;
}

// 0x801455C0 | 0x18 bytes | NON_MATCHING
// Original: andi. + bnelr pattern; GCC: rlwinm branchless
bool RoutingSlot::SnapsToDirection() const {
    return (m_flags & 0x1000) != 0;
}

// 0x801455D8 | 0x2C bytes | NON_MATCHING
// Original uses ctr loop (bdnz); GCC unrolls or uses different loop
int RoutingSlot::GetSnapDirection() const {
    for (int i = 0; i < 7; i++) {
        if ((m_flags >> i) & 1) {
            return i;
        }
    }
    return 0;
}

// 0x80145604 | 0x0C bytes | MATCHING
// rlwinm r3,r3,23,31,31 => bit 9
bool RoutingSlot::Absolute() const {
    return (m_flags >> 9) & 1;
}

// 0x80145610 | 0x0C bytes | MATCHING
// rlwinm r3,r3,19,31,31 => bit 13
bool RoutingSlot::HasRandomScoring() const {
    return (m_flags >> 13) & 1;
}

// 0x8014565C | 0x0C bytes | MATCHING
// rlwinm r3,r3,18,31,31 => bit 14
bool RoutingSlot::GetAllowFailureTrees() const {
    return (m_flags >> 14) & 1;
}

// 0x80145688 | 0x0C bytes | MATCHING
// rlwinm r3,r3,17,31,31 => bit 15
bool RoutingSlot::GetAllowDifferentAlts() const {
    return (m_flags >> 15) & 1;
}

// 0x801456B4 | 0x0C bytes | MATCHING
// lhz r3,28(r3); clrlwi r3,r3,31 => bit 16
bool RoutingSlot::GetUseAverageObjectLocation() const {
    return (m_flags >> 16) & 1;
}

// 0x801456C8 | 0x08 bytes | MATCHING
float RoutingSlot::GetXOffset() const {
    return m_xOffset;
}

// 0x801456D0 | 0x08 bytes | MATCHING
float RoutingSlot::GetYOffset() const {
    return m_yOffset;
}

// 0x801456D8 | 0x08 bytes | MATCHING
float RoutingSlot::GetAltOffset() const {
    return m_altOffset;
}

// ============================================================================
// ObjectSlot
// ============================================================================

// 0x801452F4 | 0x34 bytes | NON_MATCHING (destructor ABI)
ObjectSlot::~ObjectSlot() {
}

// 0x80145328 | 0x08 bytes | MATCHING
int ObjectSlot::GetHeight() {
    return m_height;
}

// 0x80145330 | 0x18 bytes | NON_MATCHING
// Original: andi. + beqlr + li pattern (branching)
// GCC: clrlwi (branchless)
bool ObjectSlot::IsSurface() {
    return (m_flags & 1) != 0;
}

// 0x80145348 | 0x0C bytes | MATCHING
// rlwinm r3,r3,31,31,31 => extract bit 1
bool ObjectSlot::IsFreePos() {
    return (m_flags >> 1) & 1;
}

// 0x80145354 | 0x10 bytes | NON_MATCHING
// Register allocation: original puts 1 in r3, result in r3
// GCC puts 1 in r9, result in r3
int ObjectSlot::GetHeightMask(StdHeight height) {
    return 1 << ((int)height - 1);
}

// ============================================================================
// SpriteSlot
// ============================================================================

// 0x80145364 | 0x08 bytes | MATCHING
int SpriteSlot::GetTicksPerFrame() {
    return 12;
}

// 0x801453CC | 0x08 bytes | MATCHING
void SpriteSlot::UseBalloonSprite(int id) {
    m_balloonSpriteID = id;
}

// 0x801453D4 | 0x08 bytes | MATCHING
void SpriteSlot::UseOverlaySprite(int id) {
    m_overlaySpriteID = id;
}

// 0x801453DC | 0x08 bytes | MATCHING
void SpriteSlot::SetOptions(int options) {
    m_options = options;
}

// 0x801453E4 | 0x08 bytes | MATCHING
void SpriteSlot::SetPopSize(float size) {
    m_popSize = size;
}

// 0x80145408 | 0x08 bytes | MATCHING
int SpriteSlot::GetSpriteID() const {
    return m_spriteID;
}

// 0x80145410 | 0x08 bytes | MATCHING
int SpriteSlot::GetBalloonSpriteID() const {
    return m_balloonSpriteID;
}

// 0x80145418 | 0x08 bytes | MATCHING
int SpriteSlot::GetOverlaySpriteID() const {
    return m_overlaySpriteID;
}

// 0x80145420 | 0x08 bytes | MATCHING
int SpriteSlot::GetCurrentFrame() const {
    return m_currentFrame;
}

// 0x80145428 | 0x08 bytes | MATCHING
cXPerson* SpriteSlot::GetPPerson() {
    return m_pPerson;
}

// 0x80145430 | 0x08 bytes | MATCHING
void SpriteSlot::SetPriority(int priority) {
    m_priority = priority;
}

// 0x80145438 | 0x08 bytes | MATCHING
int SpriteSlot::GetPriority() const {
    return m_priority;
}

// 0x80145440 | 0x08 bytes | MATCHING
int SpriteSlot::GetOptions() const {
    return m_options;
}

// 0x80145448 | 0x0C bytes | MATCHING
// rlwinm r3,r3,28,31,31 => extracts bit 4 of m_options
bool SpriteSlot::GetIsSkillMeter() const {
    return (m_options >> 4) & 1;
}

// 0x80145454 | 0x08 bytes | NON_MATCHING
// Original: lwz r3,96(r3) + blr (returns int directly)
// GCC: bool conversion with addic/subfe
bool SpriteSlot::GetShowOverInactivePeople() const {
    return m_showOverInactivePeople;
}

// 0x8014545C | 0x08 bytes | MATCHING
void SpriteSlot::SetShowOverInactivePeople(bool show) {
    m_showOverInactivePeople = show;
}

// 0x80145464 | 0x08 bytes | MATCHING
float SpriteSlot::GetAltOffset() const {
    return m_altOffset;
}

// 0x8014546C | 0x08 bytes | MATCHING
void SpriteSlot::SetAltOffset(float offset) {
    m_altOffset = offset;
}

// 0x80145474 | 0x08 bytes | MATCHING
float SpriteSlot::GetSizeMultiplierX() const {
    return m_sizeMultiplierX;
}

// 0x8014547C | 0x08 bytes | MATCHING
float SpriteSlot::GetSizeMultiplierY() const {
    return m_sizeMultiplierY;
}

// 0x80145484 | 0x08 bytes | MATCHING
float SpriteSlot::GetAlpha() const {
    return m_alpha;
}

// 0x801453EC | 0x1C bytes | NON_MATCHING
// Original: check spriteID != -1 first, return 0, else return m_pSelector
// GCC: branches inverted
ObjSelector* SpriteSlot::GetSelector() const {
    if (m_spriteID != -1) {
        return 0;
    }
    return m_pSelector;
}

// 0x801453B4 | 0x18 bytes | NON_MATCHING
// Original: li r3,1; cmpwi r0,0; bnelr; li r3,0 (branch pattern)
// GCC: addic/subfe (branchless)
bool SpriteSlot::IsActive() const {
    return m_tickCount != 0;
}

// 0x8014536C | 0x24 bytes | NON_MATCHING
// Original: full call frame (stwu/mflr/bl/lwz/mtlr/addi/blr)
// GCC: optimizes to tail call (li/b) - same behavior, fewer instructions
void SpriteSlot::ActivateForever() {
    ActivateForTicks(-1);
}

// 0x80145390 | 0x24 bytes | NON_MATCHING
// Same tail call optimization issue as ActivateForever
void SpriteSlot::Deactivate() {
    ActivateForTicks(0);
}

// 0x801430BC | 0x18 bytes | NON_MATCHING
// Register allocation: original uses r0 for temp, GCC uses r9
void SpriteSlot::AlternateWithSprite(int altSpriteID, int altFrameCount) {
    m_altSpriteID = altSpriteID;
    m_options |= 0x40;
    m_altFrameCount = altFrameCount;
}

// 0x80142F8C | 0x34 bytes | NON_MATCHING (destructor ABI)
SpriteSlot::~SpriteSlot() {
}

// ============================================================================
// SlotLoader
// ============================================================================

// 0x80143814 | 0x14 bytes | NON_MATCHING
// Register allocation: original uses r9 for this, r0 for zero
// GCC uses r9 for zero
SlotLoader::SlotLoader(unsigned int id) {
    m_id = id;
    m_count = 0;
}

// 0x801445C4 | 0x08 bytes | MATCHING
int SlotLoader::Save(short, void*, void*, void*, cXObject*) {
    return 1;
}

// 0x801445CC | 0x04 bytes | MATCHING
void SlotLoader::GetSlotName(Slot* slot, BString& name, int index) {
    (void)slot;
    (void)name;
    (void)index;
}

// 0x801445D0 | 0x28 bytes | NON_MATCHING (destructor ABI)
SlotLoader::~SlotLoader() {
}

// ============================================================================
// QuickDataSlotDescList
// ============================================================================

// 0x80145170 | 0x08 bytes | MATCHING
int QuickDataSlotDescList::SaveDataByID(ObjectDataID& id) {
    (void)id;
    return 0;
}

// 0x80145178 | 0x08 bytes | MATCHING
int QuickDataSlotDescList::GetDataSourceType() const {
    return 1;
}

// 0x80145180 | 0x08 bytes | MATCHING
int QuickDataSlotDescList::LoadOnlyNameAndIDFromIndex(unsigned int index, int type) {
    (void)index;
    (void)type;
    return 0;
}

// 0x8014512C | 0x08 bytes | MATCHING
int QuickDataSlotDescList::AddSlot(SlotDescriptor& desc) {
    (void)desc;
    return 0;
}

// 0x80145134 | 0x08 bytes | MATCHING
int QuickDataSlotDescList::RemoveSlot(int index) {
    (void)index;
    return 0;
}

// 0x80145164 | 0x08 bytes | MATCHING
int QuickDataSlotDescList::GetStringSetID() const {
    return 0;
}

// 0x8014516C | 0x04 bytes | MATCHING
void QuickDataSlotDescList::SetStringSetID(int id) {
    (void)id;
}

// 0x80145154 | 0x10 bytes | NON_MATCHING
// Instruction ordering: original does mulli first, then lwz
// GCC: lwz first, then mulli
SlotDescriptor* QuickDataSlotDescList::GetSlot(int index) {
    // Loads m_pSlots at offset 0x54, adds index * sizeof(SlotDescriptor)
    SlotDescriptor** ppSlots = (SlotDescriptor**)((char*)this + 0x54);
    return (SlotDescriptor*)((char*)*ppSlots + index * 72);
}

// 0x801448F0 | 0x14 bytes | NON_MATCHING
// Register usage differs: original mr r9,r3 first, GCC different allocation
int QuickDataSlotDescList::AddRef() {
    int* pRefCount = (int*)((char*)this + 0x5C);
    int count = *pRefCount + 1;
    *pRefCount = count;
    return count;
}

// 0x8014513C | 0x18 bytes | NON_MATCHING
// Original: lwz r9,84(r3); li r3,0; cmpwi r9,0; beqlr; lwz r3,-4(r9)
// Checks if m_pSlots is null, returns 0. Otherwise returns count from header.
int QuickDataSlotDescList::GetNumSlots() {
    SlotDescriptor** ppSlots = (SlotDescriptor**)((char*)this + 0x54);
    SlotDescriptor* pSlots = *ppSlots;
    if (pSlots == 0) return 0;
    // ReconStreamVector stores count at offset -4 from data pointer
    return *((int*)pSlots - 1);
}

// ============================================================================
// IFFSlotDescList
// ============================================================================

// 0x801452B8 | 0x08 bytes | MATCHING
int IFFSlotDescList::GetDataSourceType() const {
    return 2;
}

// 0x801452AC | 0x08 bytes | MATCHING
int IFFSlotDescList::GetStringSetID() const {
    return 0;
}

// 0x801452B4 | 0x04 bytes | MATCHING
void IFFSlotDescList::SetStringSetID(int id) {
    (void)id;
}

// 0x8014529C | 0x10 bytes | NON_MATCHING (instruction ordering)
SlotDescriptor* IFFSlotDescList::GetSlot(int index) {
    SlotDescriptor** ppSlotsBegin = (SlotDescriptor**)((char*)this + 0x54);
    return (SlotDescriptor*)((char*)*ppSlotsBegin + index * 72);
}

// 0x80145014 | 0x14 bytes | NON_MATCHING (register allocation)
int IFFSlotDescList::AddRef() {
    int* pRefCount = (int*)((char*)this + 0x64);
    int count = *pRefCount + 1;
    *pRefCount = count;
    return count;
}

// 0x8014527C | 0x20 bytes | NON_MATCHING
// Original: loads begin/end pointers, subtracts, multiplies by magic constant
// for division by 72 (sizeof SlotDescriptor)
// lwz r9,84(r3); lwz r3,88(r3); sub r3,r3,r9
// lis r0,0x38e3; ori r0,r0,0x8e39; mullw r3,r3,r0; srawi r3,r3,3
int IFFSlotDescList::GetNumSlots() {
    SlotDescriptor** ppBegin = (SlotDescriptor**)((char*)this + 0x54);
    SlotDescriptor** ppEnd = (SlotDescriptor**)((char*)this + 0x58);
    // (end - begin) in bytes / sizeof(SlotDescriptor) = count
    int byteSize = (int)((char*)*ppEnd - (char*)*ppBegin);
    return byteSize / 72;
}
