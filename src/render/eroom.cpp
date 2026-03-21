// eroom.cpp - ERoom, ERoomWall, EIWallPart, EIFenceWall classes
// Part of the Sims 2 GC decompilation
// Original: u2_ngc_release_dvd(eroom.obj)
//
// Small functions (<=64 bytes) decompiled from the eroom object file.

#include "types.h"

// Forward declarations
class EStream;
class EFile;
class EStorable;
class ETypeInfo;
class ELevelDrawData;
class E3DWindow;
class TileWallsSegment;
struct EBoundingBox { float x1, y1, z1, x2, y2, z2; };

// External functions
extern void* EAHeap_GetCurrentHeap();
extern void* EAHeap_Alloc(void* heap, u32 size, int align);
extern void EAHeap_Free(void* heap, void* ptr);
extern EStream& EStorable_StreamOut(EStream& stream, EStorable* obj);
extern EStream& EStorable_StreamIn(EStream& stream, EStorable*& obj);
extern EFile& EStorable_FileIn(EFile& file, EStorable*& obj);
extern int E3DWindow_TestBounds(E3DWindow& win, void* bounds);

// EIWallPart type info statics
extern ETypeInfo EIWallPart_typeInfo;
extern const char* EIWallPart_typeName;
extern u32 EIWallPart_typeKey;
extern u16 EIWallPart_readVersion;

// EIFenceWall type info statics
extern ETypeInfo EIFenceWall_typeInfo;
extern const char* EIFenceWall_typeName;
extern u32 EIFenceWall_typeKey;
extern u16 EIFenceWall_readVersion;

// Placement new
inline void* operator new(unsigned int, void* ptr) { return ptr; }

// EIWallPart - wall segment class
class EIWallPart {
public:
    u8 pad00[0x3C];         // 0x00 - includes vtable etc.
    EBoundingBox m_bounds;  // 0x3C - bounding box
    u8 pad54[0x08];         // 0x54
    u32 m_visFlags;         // 0x5C
    u8 pad60[0x2FA];        // 0x60
    s16 m_adjacentRoom;     // 0x35A

    // GetAdjacentRoom - return adjacent room index
    // Address: 0x8002B99C, Size: 8
    s16 GetAdjacentRoom() {
        return m_adjacentRoom;
    }

    // GetVisible
    // Address: 0x8002C32C, Size: 48
    int GetVisible(int side) {
        if (side == 0) {
            return m_visFlags & 1;
        }
        if (side == 1) {
            return (m_visFlags >> 1) & 1;
        }
        return 0;
    }

    // RealizeShaderTuning - empty stub
    // Address: 0x8003065C, Size: 4
    void RealizeShaderTuning() {}

    // SetForceFadeOff
    // Address: 0x80030654, Size: 8
    void SetForceFadeOff(bool val);

    // IsDiagonal (member)
    // Address: 0x80030624, Size: 24
    // NON_MATCHING - sdata reference
    int IsDiagonal();

    // isDiagonal (static)
    // Address: 0x8003063C, Size: 24
    // NON_MATCHING - sdata reference
    static int isDiagonal(TileWallsSegment seg);

    // operator new (placement)
    // Address: 0x8003061C, Size: 8
    static void* operator new(unsigned int, void* p) { return p; }

    // operator delete
    // Address: 0x800297BC, Size: 52
    static void operator delete(void* ptr) {
        void* heap = EAHeap_GetCurrentHeap();
        EAHeap_Free(heap, ptr);
    }

    // GetTypeInfo
    // Address: 0x80030560, Size: 12
    const ETypeInfo* GetTypeInfo() const {
        return &EIWallPart_typeInfo;
    }

    // GetTypeName
    // Address: 0x8003056C, Size: 12
    const char* GetTypeName() const {
        return EIWallPart_typeName;
    }

    // GetTypeKey
    // Address: 0x80030578, Size: 12
    u32 GetTypeKey() const {
        return EIWallPart_typeKey;
    }

    // GetTypeVersion
    // Address: 0x80030584, Size: 12
    u16 GetTypeVersion() const {
        return EIWallPart_readVersion;
    }

    // GetTypeInfoStatic
    // Address: 0x80030590, Size: 12
    static const ETypeInfo* GetTypeInfoStatic() {
        return &EIWallPart_typeInfo;
    }

    // GetReadVersion
    // Address: 0x8003059C, Size: 12
    static u16 GetReadVersion() {
        return EIWallPart_readVersion;
    }

    // New
    // Address: 0x800304A8, Size: 40
    // NON_MATCHING - heap alloc pattern
    static EIWallPart* New();

    // Construct
    // Address: 0x800304D0, Size: 44
    // NON_MATCHING - placement new + constructor
    static void Construct(EIWallPart* ptr);

    // Destruct
    // Address: 0x800304FC, Size: 36
    // NON_MATCHING - virtual destructor dispatch
    static void Destruct(EIWallPart* ptr);

    // CreateCopy
    // Address: 0x800305FC, Size: 32
    // NON_MATCHING - calls global CreateCopy
    EIWallPart* CreateCopy() const;

    // SafeDelete
    // Address: 0x80030520, Size: 64
    // NON_MATCHING - virtual dispatch through vtable
    void SafeDelete();
};

// EIFenceWall - fence wall subclass
class EIFenceWall {
public:
    u8 pad00[0x3C];         // 0x00
    EBoundingBox m_bounds;  // 0x3C

    // VisibilityTest
    // Address: 0x80029580, Size: 44
    int VisibilityTest(E3DWindow& win) {
        return E3DWindow_TestBounds(win, &m_bounds);
    }

    // IsOpaque - always returns 0
    // Address: 0x80030898, Size: 8
    int IsOpaque() {
        return 0;
    }

    // Draw - delegates to base draw
    // Address: 0x8002A4A0, Size: 32
    // NON_MATCHING - tail call
    void Draw(ELevelDrawData& data);

    // operator new (placement)
    // Address: 0x80030814, Size: 8
    static void* operator new(unsigned int, void* p) { return p; }

    // operator new (allocation)
    // Address: 0x800307D4, Size: 64
    // NON_MATCHING - heap alloc pattern
    static void* operator new(unsigned int size);

    // operator delete
    // Address: 0x8003081C, Size: 52
    static void operator delete(void* ptr) {
        void* heap = EAHeap_GetCurrentHeap();
        EAHeap_Free(heap, ptr);
    }

    // GetTypeInfo
    // Address: 0x80030718, Size: 12
    const ETypeInfo* GetTypeInfo() const {
        return &EIFenceWall_typeInfo;
    }

    // GetTypeName
    // Address: 0x80030724, Size: 12
    const char* GetTypeName() const {
        return EIFenceWall_typeName;
    }

    // GetTypeKey
    // Address: 0x80030730, Size: 12
    u32 GetTypeKey() const {
        return EIFenceWall_typeKey;
    }

    // GetTypeVersion
    // Address: 0x8003073C, Size: 12
    u16 GetTypeVersion() const {
        return EIFenceWall_readVersion;
    }

    // GetTypeInfoStatic
    // Address: 0x80030748, Size: 12
    static const ETypeInfo* GetTypeInfoStatic() {
        return &EIFenceWall_typeInfo;
    }

    // GetReadVersion
    // Address: 0x80030754, Size: 12
    static u16 GetReadVersion() {
        return EIFenceWall_readVersion;
    }

    // New
    // Address: 0x80030660, Size: 40
    // NON_MATCHING - heap alloc pattern
    static EIFenceWall* New();

    // Construct
    // Address: 0x80030688, Size: 44
    // NON_MATCHING - placement new + constructor
    static void Construct(EIFenceWall* ptr);

    // Destruct
    // Address: 0x800306B4, Size: 36
    // NON_MATCHING - virtual destructor dispatch
    static void Destruct(EIFenceWall* ptr);

    // CreateCopy
    // Address: 0x800307B4, Size: 32
    // NON_MATCHING - calls global CreateCopy
    EIFenceWall* CreateCopy() const;

    // SafeDelete
    // Address: 0x800306D8, Size: 64
    // NON_MATCHING - virtual dispatch through vtable
    void SafeDelete();

    // GetFenceMeterValue
    // Address: 0x80029360, Size: 64
    // NON_MATCHING - float conversion with int-to-double trick
    float GetFenceMeterValue();
};

// ERoomWall - linked list of walls
class ERoomWall {
public:
    u8 pad00[0x14];
    void* m_head;       // 0x14 - linked list head
    u8 pad18[0x14];
    u32 m_wallsOpaque[4]; // 0x2C - array of opaque flags

    // IsWallsOpaque
    // Address: 0x800295AC, Size: 16
    int IsWallsOpaque(int idx) {
        return ((u32*)((u8*)this + 0x2C))[idx];
    }

    // operator delete
    // Address: 0x8002C598, Size: 52
    static void operator delete(void* ptr) {
        void* heap = EAHeap_GetCurrentHeap();
        EAHeap_Free(heap, ptr);
    }

    // CountWalls - count non-null walls in linked list
    // Address: 0x8002F81C, Size: 48
    int CountWalls() {
        struct Node { void* wall; u8 pad[4]; Node* next; };
        Node* node = (Node*)m_head;
        int count = 0;
        if (node == NULL) return 0;
        while (node != NULL) {
            if (node->wall != NULL) {
                count++;
            }
            node = node->next;
        }
        return count;
    }

    // SafeDelete
    // Address: 0x80030914, Size: 64
    // NON_MATCHING - virtual dispatch through vtable
    void SafeDelete();

    // GetShortDistToCam
    // Address: 0x80030954, Size: 16
    // NON_MATCHING - sdata reference
    float GetShortDistToCam(int idx);
};

// Streaming operators for EIWallPart
// Address: 0x80029C8C, Size: 32
EStream& operator<<(EStream& stream, EIWallPart* obj) {
    return EStorable_StreamOut(stream, (EStorable*)obj);
}

// Address: 0x80029CAC, Size: 64
EStream& operator>>(EStream& stream, EIWallPart*& obj) {
    EStorable* tmp;
    EStorable_StreamIn(stream, tmp);
    obj = (EIWallPart*)tmp;
    return stream;
}

// Address: 0x80029CEC, Size: 64
EFile& operator>>(EFile& file, EIWallPart*& obj) {
    EStorable* tmp;
    EStorable_FileIn(file, tmp);
    obj = (EIWallPart*)tmp;
    return file;
}

// Streaming operators for EIFenceWall
// Address: 0x800297F0, Size: 32
EStream& operator<<(EStream& stream, EIFenceWall* obj) {
    return EStorable_StreamOut(stream, (EStorable*)obj);
}

// Address: 0x80029810, Size: 64
EStream& operator>>(EStream& stream, EIFenceWall*& obj) {
    EStorable* tmp;
    EStorable_StreamIn(stream, tmp);
    obj = (EIFenceWall*)tmp;
    return stream;
}

// Address: 0x80029850, Size: 64
EFile& operator>>(EFile& file, EIFenceWall*& obj) {
    EStorable* tmp;
    EStorable_FileIn(file, tmp);
    obj = (EIFenceWall*)tmp;
    return file;
}
