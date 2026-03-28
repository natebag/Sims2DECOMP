// motive.cpp - Decompiled small functions from motive.obj, motivecurve.obj,
//              motiveeffects.obj, player.obj, neighborhood.obj
// Original: c:\BuildAgent\cm3-build22-NGC\CMBuild\output\obj\u2_ngc_release_dvd\
//           motive.obj, motivecurve.obj, motiveeffects.obj, player.obj, neighborhood.obj
//
// 39 small functions (<=64 bytes) decompiled
//
// Matching status (devkitPPC GCC vs original SN Systems compiler):
//   MATCHING:     14 functions
//   NON_MATCHING: 25 functions

#include "sim/motive.h"
#include "types.h"

// ============================================================================
// External functions
// ============================================================================
extern "C" void* operator_new_wrapper(unsigned int size); // at 0x802d11b0
extern "C" void operator_delete_wrapper(void* ptr);       // at 0x802d1220
extern void GlobalConstantsClient_Construct(void* client, int id); // at 0x800ec068
extern void EString_destroy(void* estring, int mode);      // at 0x800a1d70
extern const char* EString_c_str(void* estring);            // at 0x800a6e68

// Vtable pointers
extern void* Neighborhood_vtable;       // at 0x80460678
extern void* MotiveConstantsClient_vtable; // at 0x8045f740
extern void* NeighborhoodConstants_vtable; // at 0x80460498

// Lot position table (at 0x804862dc)
extern int sLotPositionTable[][2];


// ########################################################################
// # MOTIVE.OBJ FUNCTIONS
// ########################################################################

// ============================================================================
// GetMotiveConstantsClient
// Address: 0x800c2008, Size: 8 bytes
// NON_MATCHING - SDA-relative addressing (r13 - 24444)
// GCC can't emit addi r3,r13,offset without inline asm
// ============================================================================
// Returns pointer to static MotiveConstantsClient at SDA r13-24444

// ============================================================================
// MotiveConstantsClient::MotiveConstantsClient
// Address: 0x800c2d1c, Size: 64 bytes
// NON_MATCHING - GCC tail-calls GlobalConstantsClient_Construct
// SN: full prologue (stwu/mflr/stmw), call ctor, set vtable, full epilogue
// GCC: just passes through to ctor
// ============================================================================
MotiveConstantsClient::MotiveConstantsClient() {
    GlobalConstantsClient_Construct(this, 1);
    // vtable set to MotiveConstantsClient_vtable (0x8045f740)
}

// ============================================================================
// global constructors keyed to redAspMotiveDecayMult
// Address: 0x800c2d5c, Size: 44 bytes
// NON_MATCHING - static init guard pattern
// Calls __static_initialization_and_destruction_0(1, 0xFFFF)
// ============================================================================


// ########################################################################
// # MOTIVECURVE.OBJ FUNCTIONS
// ########################################################################

// ============================================================================
// MotiveCurveSet::PrintMotiveGraph(__sFILE *, StringSet *)
// Address: 0x800c2d88, Size: 4 bytes
// MATCHING
// ============================================================================
void MotiveCurveSet::PrintMotiveGraph(__sFILE* file, StringSet* strings) {
}

// ============================================================================
// MotiveCurveSet::PrintMotiveGraph(char *)
// Address: 0x800c2d8c, Size: 4 bytes
// MATCHING
// ============================================================================
void MotiveCurveSet::PrintMotiveGraph(char* filename) {
}


// ########################################################################
// # MOTIVEEFFECTS.OBJ FUNCTIONS
// ########################################################################

// ============================================================================
// __tcf_0 (motiveeffects.obj)
// Address: 0x800c2f0c, Size: 40 bytes
// NON_MATCHING - static destructor
// Calls EString_destroy(sMotives at r13-24344, 2)
// SDA-relative addressing can't match with GCC
// ============================================================================


// ########################################################################
// # NEIGHBORHOOD.OBJ FUNCTIONS
// ########################################################################

// ============================================================================
// Neighborhood::CreateInstance
// Address: 0x800cc6d0, Size: 40 bytes
// NON_MATCHING - GCC tail-calls operator_new, SN uses stack frame
// Original: alloc 0xCC, call NeighborhoodImpl ctor at 0x800ccad8
// ============================================================================
Neighborhood* Neighborhood::CreateInstance() {
    Neighborhood* n = (Neighborhood*)operator_new_wrapper(0xCC);
    // NeighborhoodImpl constructor called here
    return n;
}

// ============================================================================
// Neighborhood::DestroyInstance
// Address: 0x800cc6f8, Size: 64 bytes
// NON_MATCHING - GCC uses bctr tail call, SN uses blrl with stack frame
// ============================================================================
void Neighborhood::DestroyInstance(Neighborhood* neighborhood) {
    if (neighborhood != 0) {
        int* vtbl = *(int**)neighborhood;
        short offset = *(short*)((char*)vtbl + 8);
        void (*dtor)(void*, int) = (void (*)(void*, int))*(int*)((char*)vtbl + 12);
        dtor((char*)neighborhood + offset, 3);
    }
}

// ============================================================================
// GetNeighborhoodConstantsClient
// Address: 0x800cc738, Size: 8 bytes
// NON_MATCHING - SDA-relative addressing (r13 - 24328)
// ============================================================================
// Returns pointer to static NeighborhoodConstants at SDA r13-24328

// ============================================================================
// NeighborhoodImpl::PostSim
// Address: 0x800ccd00, Size: 4 bytes
// MATCHING
// ============================================================================
void NeighborhoodImpl::PostSim() {
}

// ============================================================================
// NeighborhoodImpl::GetHouseNumberForLevel
// Address: 0x800cdd38, Size: 8 bytes
// MATCHING
// ============================================================================
int NeighborhoodImpl::GetHouseNumberForLevel(int level) {
    return 0;
}

// ============================================================================
// NeighborhoodImpl::FindNeighborByID
// Address: 0x800cdd40, Size: 56 bytes
// NON_MATCHING - GCC uses slwi+addi for index calc, SN uses addi+slwi
// ============================================================================
Neighbor* NeighborhoodImpl::FindNeighborByID(int id) {
    if (id <= 0) {
        return 0;
    }
    Neighbor** begin = m_neighborsBegin;
    Neighbor** end = m_neighborsEnd;
    int count = (int)(end - begin);
    if ((unsigned int)id > (unsigned int)count) {
        return 0;
    }
    return begin[id - 1];
}

// ============================================================================
// NeighborhoodImpl::GetNumFamilies
// Address: 0x800ceb20, Size: 20 bytes
// NON_MATCHING - GCC loads end(r9) first, SN loads begin(r0) first
// ============================================================================
int NeighborhoodImpl::GetNumFamilies() {
    return (int)(m_familiesEnd - m_familiesBegin);
}

// ============================================================================
// NeighborhoodImpl::GetFamilyByIndex
// Address: 0x800ceb34, Size: 16 bytes
// MATCHING
// ============================================================================
FamilyImpl* NeighborhoodImpl::GetFamilyByIndex(int index) {
    return m_familiesBegin[index];
}

// ============================================================================
// NeighborhoodImpl::MakeNewFamily
// Address: 0x800cebdc, Size: 40 bytes
// NON_MATCHING - GCC tail-calls CreateFamily, SN uses bl+stack frame
// ============================================================================
Family* NeighborhoodImpl::MakeNewFamily() {
    return CreateFamily(0, -1);
}

// ============================================================================
// NeighborhoodImpl::GetFamilyFriendsCount
// Address: 0x800cf794, Size: 60 bytes
// NON_MATCHING - GCC reorders: checks dirty first, fast path without frame
// SN always creates full stack frame with r31 save
// ============================================================================
int NeighborhoodImpl::GetFamilyFriendsCount(Family* family) {
    FamilyImpl* impl = (FamilyImpl*)family;
    int dirty = *(int*)((char*)impl + 0x20);
    if (dirty != 0) {
        RecalculateFamilyFriends();
    }
    return *(int*)((char*)impl + 0x1C);
}

// ============================================================================
// NeighborhoodImpl::GetHouseNumber
// Address: 0x800d1294, Size: 8 bytes
// MATCHING
// ============================================================================
int NeighborhoodImpl::GetHouseNumber() {
    return m_houseNumber;
}

// ============================================================================
// NeighborhoodImpl::UnloadHouse
// Address: 0x800d129c, Size: 4 bytes
// MATCHING
// ============================================================================
void NeighborhoodImpl::UnloadHouse() {
}

// ============================================================================
// NeighborhoodImpl::GetLotPosition
// Address: 0x800d12a0, Size: 64 bytes
// NON_MATCHING - GCC uses different addressing for table pair load
// SN: two separate lwzx with addi+4, GCC: lwzx then lwz with add+offset
// ============================================================================
void NeighborhoodImpl::GetLotPosition(int lot, int* outX, int* outY) {
    if ((unsigned int)(lot - 1) > 8) {
        *outY = 0;
        *outX = 0;
        return;
    }
    *outX = sLotPositionTable[lot][0];
    *outY = sLotPositionTable[lot][1];
}

// ============================================================================
// NeighborhoodImpl::GetNeighborhoodName
// Address: 0x800d1884, Size: 36 bytes
// NON_MATCHING - GCC uses b tail call, SN uses bl with stack frame
// ============================================================================
const char* NeighborhoodImpl::GetNeighborhoodName() {
    return EString_c_str(&m_name);
}

// ============================================================================
// NeighborhoodImpl::GetHighestLevelCompleted
// Address: 0x800d18a8, Size: 8 bytes
// MATCHING
// ============================================================================
short NeighborhoodImpl::GetHighestLevelCompleted() {
    return m_neighborhoodVars[0];
}

// ============================================================================
// NeighborhoodImpl::GetNeighborhoodVar
// Address: 0x800d18b0, Size: 16 bytes
// NON_MATCHING - GCC: add+lha, SN: addi+lhax
// ============================================================================
short NeighborhoodImpl::GetNeighborhoodVar(int index) const {
    return m_neighborhoodVars[index];
}

// ============================================================================
// NeighborhoodImpl::GetNeighborhoodVarRef
// Address: 0x800d18c0, Size: 16 bytes
// NON_MATCHING - GCC folds offset into shift, SN keeps separate addi
// ============================================================================
short* NeighborhoodImpl::GetNeighborhoodVarRef(int index) {
    return &m_neighborhoodVars[index];
}

// ============================================================================
// NeighborhoodImpl::SetNeighborhoodVar
// Address: 0x800d18d0, Size: 16 bytes
// NON_MATCHING - GCC: add+sth, SN: addi+sthx
// ============================================================================
void NeighborhoodImpl::SetNeighborhoodVar(int index, short value) {
    m_neighborhoodVars[index] = value;
}

// ============================================================================
// NeighborhoodImpl::GetNumNeighborHouses
// Address: 0x800d1928, Size: 20 bytes
// NON_MATCHING - GCC loads end(r9) first, SN loads begin(r0) first
// ============================================================================
int NeighborhoodImpl::GetNumNeighborHouses() {
    return (int)(m_neighborHousesEnd - m_neighborHousesBegin);
}

// ============================================================================
// NeighborhoodImpl::GetNeighborHouseByIndex
// Address: 0x800d193c, Size: 16 bytes
// MATCHING
// ============================================================================
int* NeighborhoodImpl::GetNeighborHouseByIndex(int index) {
    return (int*)m_neighborHousesBegin[index];
}

// ============================================================================
// NeighborhoodImpl::GetImpl
// Address: 0x800d194c, Size: 4 bytes
// MATCHING
// ============================================================================
NeighborhoodImpl* NeighborhoodImpl::GetImpl() {
    return this;
}

// ============================================================================
// NeighborhoodImpl::SetHouseNum
// Address: 0x800d1950, Size: 8 bytes
// MATCHING
// ============================================================================
void NeighborhoodImpl::SetHouseNum(int num) {
    m_houseNumber = num;
}

// ============================================================================
// NeighborhoodImpl::IsFreeplayLot
// Address: 0x800d1958, Size: 20 bytes
// NON_MATCHING - GCC: subfe/addi, SN: li/adde (branchless idiom)
// ============================================================================
int NeighborhoodImpl::IsFreeplayLot(int lot) {
    return (unsigned int)(lot - 13) <= 3;
}

// ============================================================================
// NeighborhoodConstants::NeighborhoodConstants
// Address: 0x800d196c, Size: 64 bytes
// NON_MATCHING - GCC tail-calls ctor, SN uses full prologue/epilogue
// ============================================================================
NeighborhoodConstants::NeighborhoodConstants() {
    GlobalConstantsClient_Construct(this, 4);
}

// ============================================================================
// Neighborhood::~Neighborhood
// Address: 0x803a6124, Size: 52 bytes
// NON_MATCHING - GCC optimizes out conditional delete
// SN: sets vtable, checks flags & 1, conditionally calls operator_delete
// ============================================================================
Neighborhood::~Neighborhood() {
    m_vtable = &Neighborhood_vtable;
}

// ============================================================================
// global constructors keyed to Neighborhood::CreateInstance(void)
// Address: 0x800d19ac, Size: 44 bytes
// NON_MATCHING - static init pattern
// ============================================================================

// ============================================================================
// global destructors keyed to Neighborhood::CreateInstance(void)
// Address: 0x800d19d8, Size: 44 bytes
// NON_MATCHING - static destruct pattern
// ============================================================================

// ============================================================================
// SimpleReconObject<NeighborhoodImpl>::~SimpleReconObject
// Address: 0x803a6158, Size: 32 bytes
// NON_MATCHING - calls ReconObject_Destroy
// ============================================================================

// ============================================================================
// SimpleReconObject<NeighborhoodImpl>::DoStream
// Address: 0x803a6178, Size: 56 bytes
// NON_MATCHING - virtual dispatch via impl vtable at 0xB0/0xB4, SN uses blrl
// ============================================================================

// ============================================================================
// SimpleReconObject<NeighborhoodImpl>::GetType
// Address: 0x803a61b0, Size: 8 bytes
// MATCHING
// ============================================================================

// ============================================================================
// void pop_heap<FamilyImpl **, bool (*)(Family *&, Family *&)>
// Address: 0x803a541c, Size: 64 bytes
// NON_MATCHING - STL template
// ============================================================================

// ============================================================================
// void partial_sort<FamilyImpl **, bool (*)(Family *&, Family *&)>
// Address: 0x803a5528, Size: 40 bytes
// NON_MATCHING - STL template
// ============================================================================

// ============================================================================
// void pop_heap<int *, bool (*)(int &, int &)>
// Address: 0x803a5ba0, Size: 64 bytes
// NON_MATCHING - STL template
// ============================================================================

// ============================================================================
// void partial_sort<int *, bool (*)(int &, int &)>
// Address: 0x803a5cac, Size: 40 bytes
// NON_MATCHING - STL template
// ============================================================================


// ########################################################################
// # PLAYER.OBJ FUNCTIONS
// ########################################################################

// Interactor color static data (at 0x80485594, 12 bytes)
float s_interactorColor[3];

// ============================================================================
// Player::Player
// Address: 0x800594f4, Size: 24 bytes
// NON_MATCHING - GCC uses r9 for zero, SN uses r0; GCC doesn't use r9 for this
// ============================================================================
Player::Player() {
    m_pad00 = 0;
    m_pad04 = 0;
    m_pad08 = 0;
}

// ============================================================================
// Player::GetInteractorColor
// Address: 0x800595ac, Size: 12 bytes
// MATCHING
// ============================================================================
void* Player::GetInteractorColor() {
    return (void*)&s_interactorColor;
}

// ============================================================================
// __static_initialization_and_destruction_0 (player.obj)
// Address: 0x800596e0, Size: 64 bytes
// NON_MATCHING - initializes s_interactorColor from .rodata floats
// GCC generates different static init guard check pattern
// ============================================================================

// ============================================================================
// global constructors keyed to Player::Player(void)
// Address: 0x80059720, Size: 44 bytes
// NON_MATCHING - static init pattern
// ============================================================================
