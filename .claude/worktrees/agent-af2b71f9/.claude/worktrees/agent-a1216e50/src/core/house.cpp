// house.cpp - House/lot management, careers, float constants, icon groups, portals, tile walls, walls
// From: house.obj, careers.obj, floatconstants.obj, icongroup.obj, portal.obj, tilewalls.obj, walls.obj
// Small functions (<=64 bytes) decompiled
//
// MATCHING STATUS LEGEND:
//   No annotation = matches original byte-for-byte
//   // NON_MATCHING = does not match (reason given)
//
// Systemic issues preventing matching (SN Systems ProDG vs GCC):
//   - SDA (r13-relative) addressing: SN Systems uses r13 offsets for globals, GCC uses lis+addi
//   - Destructor delete checks: SN generates r4&1 check + __builtin_delete, GCC omits for trivial dtors
//   - Register allocation: SN prefers r0/r9/r11, GCC uses r9/r10/r31
//   - Boolean idioms: SN uses subfic+adde, GCC uses cntlzw+srwi or addic+subfe
//   - Division by constant: slightly different magic number sequences
//   - vtable dispatch: SN inlines the this-adjust+dtor call, GCC goes through operator delete

#include "core/house.h"

// External function declarations
extern "C" void* __builtin_new(unsigned int size);
extern "C" void __builtin_delete(void* ptr);
extern "C" void* memset(void* dest, int val, unsigned int len);

// EAHeap functions
class EAHeap;
extern EAHeap* MainHeap(void);
extern void* EAHeap_Calloc(EAHeap* heap, unsigned int size, unsigned int align, int flags);
extern void EAHeap_Free(EAHeap* heap, void* ptr);

// cXMTObjectImpl::Initialize
extern void cXMTObjectImpl_Initialize(void* obj);

// TileWalls rotation lookup tables
u32 sRotateSegmentLUT[256];   // at 0x8050bc30
u32 sRotateDiagonalLUT[100];  // at 0x8050c030

// ============================================================================
// HouseStats (house.obj) - 10 functions
// ============================================================================

// HouseStats::HouseStats(void) - 0x800bc420 (52 bytes)
// NON_MATCHING - register allocation: original uses mr r9,r3; li r0,0; stw r0,off(r9)
//                GCC uses li r9,0; stw r9,off(r3)
HouseStats::HouseStats(void) {
    m_objectCount = 0;
    m_squareFeet = 0;
    m_unknown04 = 0;
    m_numBedrooms = 0;
    m_numBathrooms = 0;
    m_numLevels = 0;
    m_lotSize = 0;
    m_unknown18 = 0;
    m_unknown1C = 0;
    m_unknown20 = 0;
}

// HouseStats::GetSquareFeet(void) - 0x800bc454 (8 bytes)
// MATCHING: lwz r3,0(r3); blr
int HouseStats::GetSquareFeet(void) {
    return m_squareFeet;
}

// HouseStats::GetNumBedrooms(void) - 0x800bc95c (8 bytes)
// MATCHING: lwz r3,8(r3); blr
int HouseStats::GetNumBedrooms(void) {
    return m_numBedrooms;
}

// HouseStats::GetNumBathrooms(void) - 0x800bc964 (8 bytes)
// MATCHING: lwz r3,12(r3); blr
int HouseStats::GetNumBathrooms(void) {
    return m_numBathrooms;
}

// HouseStats::GetNumLevels(void) - 0x800bc96c (8 bytes)
// MATCHING: lwz r3,16(r3); blr
int HouseStats::GetNumLevels(void) {
    return m_numLevels;
}

// HouseStats::GetLotSize(void) - 0x800bc974 (8 bytes)
// MATCHING: lwz r3,20(r3); blr
int HouseStats::GetLotSize(void) {
    return m_lotSize;
}

// HouseStats::GetObjectCount(void) - 0x800bc97c (8 bytes)
// MATCHING: lwz r3,36(r3); blr
int HouseStats::GetObjectCount(void) {
    return m_objectCount;
}

// ============================================================================
// HouseImpl (house.obj) - 8 functions
// ============================================================================

// HouseImpl::GetFamily(void) - 0x800bc984 (8 bytes)
// MATCHING: lwz r3,20(r3); blr
Family* HouseImpl::GetFamily(void) {
    return m_family;
}

// HouseImpl::GetSizeScoreCurve(void) - 0x800bc98c (8 bytes)
// MATCHING: lwz r3,28(r3); blr
void* HouseImpl::GetSizeScoreCurve(void) {
    return m_sizeScoreCurve;
}

// HouseImpl::GetFurnishingsScoreCurve(void) - 0x800bc994 (8 bytes)
// MATCHING: lwz r3,32(r3); blr
void* HouseImpl::GetFurnishingsScoreCurve(void) {
    return m_furnishingsScoreCurve;
}

// HouseImpl::SetFamilyToNull(void) - 0x800bc99c (12 bytes)
// NON_MATCHING - register allocation: original uses li r0,0; stw r0,20(r3)
//                GCC uses li r9,0; stw r9,20(r3)
void HouseImpl::SetFamilyToNull(void) {
    m_family = 0;
}

// House::CreateInstance(void) - 0x800bb358 (40 bytes)
// NON_MATCHING - GCC generates different new+ctor inlining pattern
House* House::CreateInstance(void) {
    HouseImpl* impl = new HouseImpl();
    return impl;
}

// House::DestroyInstance(House *) - 0x800bb380 (64 bytes)
// NON_MATCHING - original uses vtable this-adjust + blrl pattern; GCC uses different delete dispatch
void House::DestroyInstance(House* house) {
    if (house) {
        delete house;
    }
}

// House::~House(void) - 0x803a37e0 (52 bytes)
// NON_MATCHING - SN generates vtable store + r4&1 delete check; GCC omits
House::~House(void) {
}

// HouseImpl::GetFirstObject(void) - 0x800bbd08 (56 bytes)
// NON_MATCHING - requires r13-relative global + vtable dispatch
// Original: lwz r3,-21484(r13); loads vtable; this-adjust; blrl
cXObject* HouseImpl::GetFirstObject(void) {
    return 0; // TODO: implement when ObjectModule globals available
}

// ============================================================================
// SimpleReconObject<HouseImpl> (house.obj) - 3 functions
// ============================================================================

// SimpleReconObject<HouseImpl>::GetType(void) - 0x803a386c (8 bytes)
// NON_MATCHING - original uses lwz r3,8(r3) (unsigned load), GCC uses lha (signed halfword load)
template<>
short SimpleReconObject<HouseImpl>::GetType(void) {
    return m_type;
}

// SimpleReconObject<HouseImpl>::~SimpleReconObject(void) - 0x803a3814 (32 bytes)
// NON_MATCHING - GCC generates different dtor chain
template<>
SimpleReconObject<HouseImpl>::~SimpleReconObject(void) {
}

// SimpleReconObject<HouseImpl>::DoStream(ReconBuffer *, int) - 0x803a3834 (56 bytes)
// NON_MATCHING - requires vtable dispatch through m_impl
template<>
void SimpleReconObject<HouseImpl>::DoStream(ReconBuffer* buf, int flags) {
    // Original dispatches through m_impl->vtable
}

// ============================================================================
// IconGroup / IconGroupImpl (icongroup.obj) - 6 functions
// ============================================================================

// IconGroup::CreateInstance(void) - 0x800bc9a8 (40 bytes)
// NON_MATCHING - GCC inlines new+ctor, original separates bl __builtin_new + bl ctor
IconGroup* IconGroup::CreateInstance(void) {
    IconGroupImpl* impl = new IconGroupImpl();
    return impl;
}

// IconGroup::DestroyInstance(IconGroup *) - 0x800bc9d0 (64 bytes)
// NON_MATCHING - vtable dispatch pattern differs
void IconGroup::DestroyInstance(IconGroup* group) {
    if (group) {
        delete group;
    }
}

// IconGroup::~IconGroup(void) - 0x803a3874 (52 bytes)
// NON_MATCHING - SN generates vtable store + delete check; GCC omits
IconGroup::~IconGroup(void) {
}

// IconGroupImpl::IconGroupImpl(void) - 0x800bca10 (36 bytes)
// NON_MATCHING - register allocation: SN uses r11 for this, r0 for zero; GCC uses r3, r9
IconGroupImpl::IconGroupImpl(void) {
    m_field04 = 0;
    m_field08 = 0;
    m_field0C = 0;
}

// IconGroupImpl::GetLabel(StringBuffer &) - 0x800bcb68 (4 bytes)
// MATCHING: blr
void IconGroupImpl::GetLabel(StringBuffer& buf) {
}

// IconGroupImpl::LoadStrings(void) - 0x800bcb6c (4 bytes)
// MATCHING: blr
void IconGroupImpl::LoadStrings(void) {
}

// ============================================================================
// Careers / CareersImpl (careers.obj) - 15 functions
// ============================================================================

// Careers::Careers(void) - 0x800b1b54 (20 bytes)
// NON_MATCHING - vtable address encoding differs
Careers::Careers(void) {
}

// Careers::~Careers(void) - 0x800b13ec (52 bytes)
// NON_MATCHING - SN generates vtable store + delete check; GCC omits
Careers::~Careers(void) {
}

// Careers::CreateInstance(void) - 0x800b1420 (64 bytes)
// NON_MATCHING - SN uses MainHeap+Calloc pattern; GCC uses different alloc sequence
Careers* Careers::CreateInstance(void) {
    EAHeap* heap = MainHeap();
    CareersImpl* impl = (CareersImpl*)EAHeap_Calloc(heap, 32, 1, 0);
    return impl;
}

// Careers::DestroyInstance(Careers *) - 0x800b1460 (64 bytes)
// NON_MATCHING - vtable dispatch pattern
void Careers::DestroyInstance(Careers* careers) {
    if (careers) {
        delete careers;
    }
}

// CareersImpl::CareersImpl(void) - 0x800b1b68 (20 bytes)
// NON_MATCHING - vtable address encoding
CareersImpl::CareersImpl(void) {
}

// CareersImpl::GetNumCareers(void) - 0x800b1698 (12 bytes)
// MATCHING: lwz r9,8(r3); lwz r3,12(r9); blr
int CareersImpl::GetNumCareers(void) {
    int* data = (int*)m_careerData;
    return ((int*)data)[3];
}

// CareersImpl::GetCareerByIndex(int) - 0x800b16a4 (20 bytes)
// MATCHING: lwz r9,8(r3); mulli r4,r4,20; lwz r3,4(r9); add r3,r3,r4; blr
Career* CareersImpl::GetCareerByIndex(int index) {
    char* data = (char*)m_careerData;
    char* arr = *(char**)(data + 4);
    return (Career*)(arr + index * 20);
}

// CareersImpl::GetIndexByCareer(Career *) - 0x800b16b8 (32 bytes)
// NON_MATCHING - division by 20 uses different magic number codegen
int CareersImpl::GetIndexByCareer(Career* career) {
    char* data = (char*)m_careerData;
    char* arr = *(char**)(data + 4);
    return (int)((char*)career - arr) / 20;
}

// CareersImpl::GetJobGrade(int) - 0x800b179c (52 bytes)
// NON_MATCHING - branch structure and register allocation differ
int* CareersImpl::GetJobGrade(int simID) {
    int** jobArr = (int**)m_jobData;
    int* arr = jobArr[0];
    int count = 0;
    if (arr != 0) {
        count = arr[-1];
    }
    if (simID < count) {
        return &arr[simID];
    }
    return (int*)((char*)this + 0x1C);
}

// CareersImpl::GetJobName(Job &, bool) - 0x800b1ab0 (56 bytes)
// NON_MATCHING - GCC generates trap for null deref; original has different null handling
void* CareersImpl::GetJobName(Job& job, bool useAlt) {
    if (useAlt) {
        char* jobPtr = (char*)&job;
        void* altPtr = *(void**)(jobPtr + 92);
        void* str = 0;
        if (altPtr != 0) {
            str = *(void**)altPtr;
        }
        unsigned short firstChar = *(unsigned short*)str;
        if (firstChar != 0) {
            return (void*)(jobPtr + 92);
        }
    }
    return (void*)((char*)&job + 88);
}

// CareersImpl::GetShortName(Job &, bool) - 0x800b1ae8 (56 bytes)
// NON_MATCHING - same issue as GetJobName
void* CareersImpl::GetShortName(Job& job, bool useAlt) {
    if (useAlt) {
        char* jobPtr = (char*)&job;
        void* altPtr = *(void**)(jobPtr + 100);
        void* str = 0;
        if (altPtr != 0) {
            str = *(void**)altPtr;
        }
        unsigned short firstChar = *(unsigned short*)str;
        if (firstChar != 0) {
            return (void*)(jobPtr + 100);
        }
    }
    return (void*)((char*)&job + 96);
}

// CareersImpl::GetCarpoolHour(Job &) - 0x800b1b20 (44 bytes)
// NON_MATCHING - register allocation differs in div-by-24 sequence
int CareersImpl::GetCarpoolHour(Job& job) {
    char* jobPtr = (char*)&job;
    int hour = *(int*)(jobPtr + 72);
    int adjusted = hour + 23;
    return adjusted % 24;
}

// CareersImpl::GetSuit(Job &, bool) - 0x800b1b4c (8 bytes)
// MATCHING: lwz r3,104(r4); blr
int CareersImpl::GetSuit(Job& job, bool female) {
    char* jobPtr = (char*)&job;
    return *(int*)(jobPtr + 104);
}

// CareersImpl::operator new(unsigned int) - 0x800b1bd4 (60 bytes)
// NON_MATCHING - register allocation in heap alloc pattern
void* CareersImpl::operator new(unsigned int size) {
    EAHeap* heap = MainHeap();
    return EAHeap_Calloc(heap, size, 1, 0);
}

// CareersImpl::operator delete(void *) - 0x800b1c10 (52 bytes)
// NON_MATCHING - register allocation differs
void CareersImpl::operator delete(void* ptr) {
    EAHeap* heap = MainHeap();
    EAHeap_Free(heap, ptr);
}

// ============================================================================
// FloatConstants / FloatConstantsQuickData (floatconstants.obj) - 14 functions
// ============================================================================

// FloatConstantsQuickData::CreateInstance(void) - 0x800b6ca8 (40 bytes)
// NON_MATCHING - GCC tail-calls __builtin_new; original uses bl + bl ctor
FloatConstantsQuickData* FloatConstantsQuickData::CreateInstance(void) {
    FloatConstantsQuickData* obj = (FloatConstantsQuickData*)__builtin_new(20);
    return obj;
}

// FloatConstants::CreateInstance(void) - 0x800b6cd0 (40 bytes)
// NON_MATCHING - same as above
FloatConstants* FloatConstants::CreateInstance(void) {
    FloatConstantsQuickData* obj = (FloatConstantsQuickData*)__builtin_new(20);
    return obj;
}

// FloatConstants::CreateInstance(ObjectDataID &) - 0x800b6cf8 (40 bytes)
// NON_MATCHING - same as above
FloatConstants* FloatConstants::CreateInstance(ObjectDataID& dataID) {
    FloatConstantsQuickData* obj = (FloatConstantsQuickData*)__builtin_new(20);
    return obj;
}

// FloatConstants::DestroyInstance(FloatConstants *) - 0x800b6d20 (64 bytes)
// NON_MATCHING - vtable dispatch pattern
void FloatConstants::DestroyInstance(FloatConstants* fc) {
    if (fc) {
        delete fc;
    }
}

// FloatConstants::~FloatConstants(void) - 0x803a3670 (52 bytes)
// NON_MATCHING - SN generates vtable store + delete check
FloatConstants::~FloatConstants(void) {
}

// FloatConstantsQuickData::~FloatConstantsQuickData(void) - 0x800b6db4 (60 bytes)
// NON_MATCHING - SN generates vtable store + delete check + zero m_items
FloatConstantsQuickData::~FloatConstantsQuickData(void) {
    m_items = 0;
}

// FloatConstantsQuickData::GetDataID(void) const - 0x800b7084 (52 bytes)
// NON_MATCHING - hidden return pointer + copy ctor call pattern differs
ObjectDataID FloatConstantsQuickData::GetDataID(void) const {
    return m_dataID;
}

// FloatConstantsQuickData::SaveDataByID(ObjectDataID &) - 0x800b70fc (8 bytes)
// MATCHING: li r3,0; blr
int FloatConstantsQuickData::SaveDataByID(ObjectDataID& dataID) {
    return 0;
}

// FloatConstantsQuickData::GetDataSourceType(void) const - 0x800b7174 (8 bytes)
// MATCHING: li r3,1; blr
int FloatConstantsQuickData::GetDataSourceType(void) const {
    return 1;
}

// FloatConstantsQuickData::AddRef(void) - 0x800b717c (20 bytes)
// NON_MATCHING - register allocation: original uses mr r9,r3 then lwz/stw via r9;
//                GCC uses lwz r9,16(r3) then mr r10,r3
int FloatConstantsQuickData::AddRef(void) {
    m_refCount++;
    return m_refCount;
}

// FloatConstantsQuickData::LoadFromIndex(unsigned int, int) - 0x800b71ec (8 bytes)
// MATCHING: li r3,0; blr
int FloatConstantsQuickData::LoadFromIndex(unsigned int index, int type) {
    return 0;
}

// FloatConstantsQuickData::GetResourceName(StringBuffer &) const - 0x800b71f4 (8 bytes)
// MATCHING: li r3,0; blr
int FloatConstantsQuickData::GetResourceName(StringBuffer& buf) const {
    return 0;
}

// FloatConstantsQuickData::SetResourceName(StringBuffer &) - 0x800b71fc (8 bytes)
// MATCHING: li r3,0; blr
int FloatConstantsQuickData::SetResourceName(StringBuffer& buf) {
    return 0;
}

// FloatConstantsQuickData::LoadOnlyNameAndIDFromIndex(unsigned int, int) - 0x800b7204 (8 bytes)
// MATCHING: li r3,0; blr
int FloatConstantsQuickData::LoadOnlyNameAndIDFromIndex(unsigned int index, int type) {
    return 0;
}

// ============================================================================
// Portal (portal.obj) - 5 functions
// ============================================================================

// cXPortalImpl::Initialize(void) - 0x8012fdac (36 bytes)
// NON_MATCHING - original has stack frame + bl cXMTObjectImpl::Initialize;
//                GCC tail-calls as b (and loads from offset 0x04 vs 0x00)
void cXPortalImpl::Initialize(void) {
    cXMTObjectImpl_Initialize(m_object);
}

// cXPortalImpl::ReconType(void) - 0x80130580 (12 bytes)
// MATCHING: lis r3,0x444F; ori r3,r3,0x4F52; blr
u32 cXPortalImpl::ReconType(void) {
    return 0x444F4F52; // 'DOOR'
}

// cXPortalImpl::GetPortalImplementation(void) - 0x8013280c (4 bytes)
// MATCHING: blr
cXPortalImpl* cXPortalImpl::GetPortalImplementation(void) {
    return this;
}

// cXPortal::setPortalImpl(cXPortalImpl *) - 0x80132730 (20 bytes)
// NON_MATCHING - pointer chain offset: original loads from 0(r3), GCC from 4(r3)
//                due to class layout difference (m_data offset)
void cXPortal::setPortalImpl(cXPortalImpl* impl) {
    void** p1 = (void**)m_data;
    void** p2 = (void**)*p1;
    void** p3 = (void**)*p2;
    p3[3] = (void*)impl;
}

// cXPortalImpl::GetRouteScore(short) - 0x80132788 (64 bytes)
// NON_MATCHING - GCC uses different register allocation and comparison sequence.
//                Original compares as mr. r4,r4 first; GCC uses cmpwi r4,0.
//                Array access: original uses clrlwi+addi+slwi; GCC uses slwi+addi.
float cXPortalImpl::GetRouteScore(short routeID) {
    if (routeID <= 0) {
        return -1.0f;
    }
    unsigned int count = (unsigned int)((char*)m_routeScoresEnd - (char*)m_routeScores) / 4;
    if ((unsigned short)routeID > count) {
        return -1.0f;
    }
    return m_routeScores[routeID - 1];
}

// ============================================================================
// TileWalls (tilewalls.obj) - 11 functions
// ============================================================================

// TileWalls::TileWalls(void) - 0x80146880 (56 bytes)
// NON_MATCHING - GCC tail-calls memset; original has stack frame + bl memset + returns this
TileWalls::TileWalls(void) {
    memset(this, 0, 0x38);
}

// TileWalls::~TileWalls(void) - 0x80146914 (40 bytes)
// NON_MATCHING - SN generates r4&1 delete check + stack frame; GCC generates just blr
TileWalls::~TileWalls(void) {
}

// TileWalls::HasWall(TileWallsSegment) const - 0x80146998 (24 bytes)
// NON_MATCHING - boolean idiom: original uses and+xor+subfic+adde;
//                GCC uses andc+cntlzw+srwi
bool TileWalls::HasWall(TileWallsSegment seg) const {
    return (m_wallBits & seg) == seg;
}

// TileWalls::HasWall(void) const - 0x801469b0 (24 bytes)
// NON_MATCHING - boolean idiom: original uses cmpwi+bnelr with li r3,1/li r3,0;
//                GCC uses addic+subfe
bool TileWalls::HasWall(void) const {
    return m_wallBits != 0;
}

// TileWalls::HasDiagonal(void) const - 0x80146a9c (24 bytes)
// NON_MATCHING - boolean idiom: original uses andi.+bnelr;
//                GCC uses rlwinm+addic+subfe
bool TileWalls::HasDiagonal(void) const {
    return (m_wallBits & 0x30) != 0;
}

// TileWalls::RemoveAllWalls(void) - 0x80146f04 (12 bytes)
// NON_MATCHING - register allocation: original uses li r0,0; stw r0,0(r3)
//                GCC uses li r9,0; stw r9,0(r3)
void TileWalls::RemoveAllWalls(void) {
    m_wallBits = 0;
}

// TileWalls::GetFloorValue(DiagonalSideSelector) const - 0x80146fdc (28 bytes)
// NON_MATCHING - GCC adds extra clrlwi (zero-extend) after lhz that original doesn't have.
//                Branch direction also differs (ble vs bgt).
FloorPattern TileWalls::GetFloorValue(DiagonalSideSelector side) const {
    if ((unsigned int)((int)side - 1) <= 1) {
        return m_floorValue1;
    }
    return m_floorValue2;
}

// TileWalls::SetFloorValue(FloorPattern, DiagonalSideSelector) - 0x80146ff8 (40 bytes)
// NON_MATCHING - GCC adds extra clrlwi after lhz; branch polarity differs
FloorPattern TileWalls::SetFloorValue(FloorPattern pattern, DiagonalSideSelector side) {
    FloorPattern old;
    if ((unsigned int)((int)side - 1) <= 1) {
        old = m_floorValue1;
        m_floorValue1 = pattern;
    } else {
        old = m_floorValue2;
        m_floorValue2 = pattern;
    }
    return old;
}

// TileWalls::ConvertToWorldCoords(void) - 0x80147020 (48 bytes)
// NON_MATCHING - GCC generates beqlr+ (tail call optimization); original has explicit frame
void TileWalls::ConvertToWorldCoords(void) {
    if (m_rotation != 0) {
        Rotate(4 - m_rotation);
    }
}

// TileWalls::RotateSegment(TileWallsSegment, int) - 0x80147050 (28 bytes)
// NON_MATCHING - LUT addressing: original uses slwi r3,r3,2; slwi r4,r4,8
//                GCC uses slwi r4,r4,6; add; slwi,2; lwzx
TileWallsSegment TileWalls::RotateSegment(TileWallsSegment seg, int rotation) {
    return sRotateSegmentLUT[seg + (rotation << 6)];
}

// TileWalls::RotateDiagonal(DiagonalSideSelector, int) - 0x8014706c (28 bytes)
// NON_MATCHING - LUT computation: original uses mulli r4,r4,20; slwi r3,r3,2
//                GCC uses mulli r4,r4,5; add; slwi,2
DiagonalSideSelector TileWalls::RotateDiagonal(DiagonalSideSelector side, int rotation) {
    return (DiagonalSideSelector)sRotateDiagonalLUT[(int)side + rotation * 5];
}

// ============================================================================
// Walls (walls.obj) - 3 functions
// ============================================================================

// CanWalkThrough(unsigned char) - 0x80149f50 (16 bytes)
// NON_MATCHING - boolean idiom: original uses xori+subfic+adde;
//                GCC uses xori+cntlzw+srwi
bool CanWalkThrough(unsigned char wallBits) {
    return wallBits == 3;
}

// CanWalkThrough(WallStyle) - 0x80149f60 (56 bytes)
// NON_MATCHING - original uses chain of cmpwi+beq (56 bytes);
//                GCC optimizes to bitmask table lookup (44 bytes)
bool CanWalkThrough(WallStyle style) {
    switch ((int)style) {
        case 3:
        case 5:
        case 6:
        case 15:
        case 23:
            return true;
        default:
            return false;
    }
}

// RotateWallBits(unsigned char, int) - 0x8014a544 (28 bytes)
// NON_MATCHING - instruction ordering: original does slwi first then subfic;
//                GCC does subfic first then slwi
unsigned char RotateWallBits(unsigned char bits, int rotation) {
    unsigned int doubled = ((unsigned int)bits << 4) | bits;
    int shift = (8 - rotation) >> 1;
    return (unsigned char)(((int)doubled >> shift) & 0xFF);
}
