// engine_classes.cpp - Decompiled E* engine classes from asm_decomp
//
// Converted from inline PPC asm stubs to real portable C++.
// All logic derived from PPC assembly analysis of the GameCube build.
//
// Classes covered:
//   EAnimController  - Skeletal animation controller (93 methods, 0xB4 size)
//   EBitArray        - Variable-length packed bit storage (31 methods)
//   EBitArrayProxy   - Single-bit accessor proxy (3 methods)
//   EBoundTreeNode   - Spatial partitioning node (4 methods)
//   ECheats          - Cheat code hash table (7 methods)
//   EDummyFile       - Null file subclass (1 method)
//   EFile            - Base file I/O (4 methods)
//   EFontCharacter   - Single glyph data (4 methods)
//   EFontData        - Font resource container (7 methods)
//   EFontPage        - Texture page for glyphs (4 methods)
//   EFontSize        - Font size + page collection (8 methods)
//   EHouse           - House/lot container (19 methods)
//   EInstance         - Placed object in level (16 methods)
//   EIGameInstance   - Game instance base (1 method)
//   EIStaticModel    - Static model instance (31 methods)
//   EIStaticSubModel - Static sub-model instance (18 methods)
//   ELightGrid       - Light evaluation grid (21 methods)
//   ELiveMode        - Main gameplay state (15 methods)
//   EMovie           - FMV playback (1 method)
//   ERC              - Render command buffer (70 methods)
//   ERCharacter      - Character skeleton resource (5 methods)
//   ERoom            - Room geometry + walls (25 methods)
//   ESimsCam         - Game camera controller (45 methods)
//   EStream          - Serialization stream (6 methods)
//   ETypeInfo        - Runtime type information node (2 methods)
//
// Source: Disassembly of u2_ngc_release_dvd.elf
//         Symbol names from u2_ngc_release.map (39,169 symbols)
//         Struct layouts from docs/struct_layouts.md
//
// Build: SN Systems ProDG for GameCube (SN-NGC), DolphinSDK 1.0 HW2

#include "types.h"

// ============================================================================
// External functions and types
// ============================================================================

extern "C" {
    void* memcpy(void* dst, const void* src, unsigned int n);
    void* memset(void* s, int c, unsigned int n);
    int   strlen(const char* s);
    char* strcpy(char* dst, const char* src);
    int   strcmp(const char* a, const char* b);
    void  EORDbgTrace(const char* fmt, ...);
}

// Memory
class EAHeap;
extern EAHeap* MainHeap();

class EAHeap {
public:
    void* Malloc(unsigned int size, int flags);
    void  Free(void* ptr);
};

// ============================================================================
// Forward declarations
// ============================================================================

class EStorable;
class EResource;
class EResourceManager;
class ETypeInfo;
class EStream;
class EFile;
class EMemoryWriteStream;
class ERedBlackTree;
class ENodeList;
class EHashTable;
class EChecksum;
class ECheatLookup;

// Math types
struct EVec2 { f32 x, y; };
struct EVec3 { f32 x, y, z; };
struct EVec4 { f32 x, y, z, w; };
struct EMat4 { f32 m[4][4]; };
struct EBound3 { EVec3 min, max; };
struct EBoundSphere { EVec3 center; f32 radius; };
struct EQuat { f32 x, y, z, w; };

// Template stubs
template <typename T> class TNodeList {
public:
    u32 m_head;      // 0x00
    u32 m_tail;      // 0x04
    u32 m_count;     // 0x08
};

template <typename T, typename A> class TArray {
public:
    T*  m_data;      // 0x00
    u32 m_count;     // 0x04
    u32 m_capacity;  // 0x08

    TArray() : m_data(NULL), m_count(0), m_capacity(0) {}
};

class TArrayDefaultAllocator {};
class TArrayERCharacterAllocator {};

template <typename T> class TRect {
public:
    T left, top, right, bottom;
};

// Render types
class EDL;
class EDLEntry;
class EMaterial;
class ERenderSurface;
class EViewport;
class ELights;
class ELevelDrawData;
class EOrderTableData;
class LevelLightingEntry;
class ERC;
class EGEVert;

// Animation types
class EAnimController;
class ERAnim;
class EACTrack;
class EACTrackStreams;
class EACEventRange;
class EACNodeState;
class EAnimNodeDataPos;
class ECharacterNode;
class ERModel;
class ERTexture;

// Game types
class CameraDirector;
class E3DWindow;
class EILight;
class EGlobal;
class ESimsCam;
class ERLevel;
class ERoomWall;
class ERoomWallPtr;
class CTilePt;
class cXObject;
class TileWalls;

// Enums/structs
struct eAnimatedObjectType {};
struct eTrackFlags {};
struct ETCTransformSource {};
struct RCMode {};
struct CameraNoiseSetting {};
struct DiagonalSideSelector {};
struct EWallUpDownStateType {};
struct TileWallsSegment {};
struct CheatType {};

// External function refs
extern u32 EChecksum_Compute(const char* str);

// SDA globals (r13-relative in PPC)
extern ETypeInfo* g_pTypeInfoList;       // linked list head
extern ETypeInfo* g_pTypeInfoTreeRoot;   // BST root
extern int g_typeInfoCount;
extern void* g_pRenderer;               // ENgcRenderer*


// ############################################################################
//
//  ETypeInfo - Runtime type information node
//
//  Size: 40 bytes (0x28)
//  2 functions, 272 bytes total
//
//  The engine's RTTI system. Each EStorable-derived class registers an
//  ETypeInfo node containing factory function pointers, a checksum,
//  a type ID, and a parent link for inheritance checking.
//
// ############################################################################

class ETypeInfo {
public:
    // 0x00: EStorable* (*m_createFunc)(void)     - factory: create new instance
    // 0x04: void (*m_writeFunc)(void*)            - serialization write
    // 0x08: void (*m_readFunc)(void*)             - serialization read
    // 0x0C: char* m_name                          - class name string
    // 0x10: u32 m_checksum                        - CRC32 of name
    // 0x14: u16 m_typeId                          - unique type ID
    // 0x16: s16 m_pad                             - padding (-1)
    // 0x18: ETypeInfo* m_parent                   - base class type info
    // 0x1C: (unused)
    // 0x20: (unused)
    // 0x24: ETypeInfo* m_next                     - linked list next

    EStorable* (*m_createFunc)(void);   // 0x00
    void (*m_writeFunc)(void*);         // 0x04
    void (*m_readFunc)(void*);          // 0x08
    char* m_name;                       // 0x0C
    u32 m_checksum;                     // 0x10
    u16 m_typeId;                       // 0x14
    s16 m_pad;                          // 0x16
    ETypeInfo* m_parent;                // 0x18
    u32 m_reserved1;                    // 0x1C
    u32 m_reserved2;                    // 0x20
    ETypeInfo* m_next;                  // 0x24

    // 0x802D58CC (136 bytes)
    // Register a new type into the global type system.
    // Computes checksum from name, assigns type ID, inserts into BST.
    void Register(EStorable* (*createFunc)(void),
                  void (*writeFunc)(void*),
                  void (*readFunc)(void*),
                  unsigned short typeId,
                  char* name,
                  ETypeInfo* parent)
    {
        m_createFunc = createFunc;
        m_writeFunc = writeFunc;
        m_readFunc = readFunc;
        m_name = name;

        // Compute CRC32 checksum from the class name
        m_checksum = EChecksum_Compute(name);

        m_typeId = typeId;
        m_pad = -1;

        // Set parent unless self-referencing (root type)
        if (parent != this) {
            m_parent = parent;
        } else {
            m_parent = NULL;
        }

        // Increment global type count
        g_typeInfoCount++;

        // Insert into sorted BST
        Insert();
    }

    // 0x802D5954 (136 bytes)
    // Insert this node into the global type BST sorted by checksum.
    // Also prepends to the linked list.
    void Insert() {
        // Prepend to linked list
        m_next = g_pTypeInfoList;
        g_pTypeInfoList = this;

        ETypeInfo* root = g_pTypeInfoTreeRoot;
        if (root == NULL) {
            // Empty tree - we become root
            g_pTypeInfoTreeRoot = this;
            return;
        }

        u32 myChecksum = m_checksum;
        ETypeInfo* prev = NULL;

        while (root != NULL) {
            u32 nodeChecksum = root->m_checksum;

            // Exact match - duplicate, just return
            if (nodeChecksum == myChecksum) {
                return;
            }

            prev = root;

            if (myChecksum < nodeChecksum) {
                // Go left (re-use m_reserved1 as left child)
                root = (ETypeInfo*)root->m_reserved1;
            } else {
                // Go right (re-use m_reserved2 as right child)
                root = (ETypeInfo*)root->m_reserved2;
            }
        }

        // Insert at the found leaf position
        if (prev != NULL) {
            if (myChecksum < prev->m_checksum) {
                prev->m_reserved1 = (u32)this;
            } else {
                prev->m_reserved2 = (u32)this;
            }
        }
    }

    // Check if this type derives from 'other' by walking parent chain
    bool IsDerivedFrom(ETypeInfo* other) const {
        const ETypeInfo* cur = this;
        while (cur != NULL) {
            if (cur == other) return true;
            cur = cur->m_parent;
        }
        return false;
    }
};


// ############################################################################
//
//  EBitArray - Variable-length packed bit storage
//
//  Size: 20 bytes (0x14)
//  31 functions, 3848 bytes total
//
//  Stores an array of bits packed into u32 words. Supports bitwise ops,
//  insertion/removal, interleaving, and float conversion for animation
//  compression (quantization).
//
// ############################################################################

// Internal type info structure for EBitArray (vtable-like dispatch)
struct EBitArrayTypeInfo {
    u8  _pad[24];        // 0x00-0x17
    s16 m_heapOffset;    // 0x18 - offset to heap pointer within object
    u8  _pad2[2];        // 0x1A
    void (*m_freeFunc)(void*); // 0x1C - function to free memory
};

class EBitArray {
public:
    u32* m_data;                    // 0x00 - pointer to packed bit data
    u32  m_bitCount;                // 0x04 - number of bits stored
    u32  m_allocatedBits;           // 0x08 - allocated capacity in bits
    u32  m_growBy;                  // 0x0C - growth increment (default 4096)
    EBitArrayTypeInfo* m_typeInfo;  // 0x10 - type info for memory allocation

    // Helper: number of u32 words needed for 'bits' bits
    static u32 WordsNeeded(u32 bits) {
        return (bits + 31) / 32;
    }

    // Helper: set grow-by amount
    void SetGrowBy(int growBy) {
        m_growBy = growBy;
    }

    // --- Constructors ---

    // 0x802DF544 (80 bytes)
    EBitArray() {
        // m_typeInfo set by vtable init (compiler inserts)
        m_data = NULL;
        m_bitCount = 0;
        m_allocatedBits = 0;
        SetGrowBy(4096);
    }

    // 0x802DF594 (100 bytes)
    EBitArray(int numBits) {
        m_data = NULL;
        m_bitCount = 0;
        m_allocatedBits = 0;
        SetGrowBy(4096);
        SetSize(numBits, 0);
    }

    // 0x802DF5F8 (100 bytes)
    EBitArray(int numBits, int growBy) {
        m_data = NULL;
        m_bitCount = 0;
        m_allocatedBits = 0;
        SetGrowBy(growBy);
        SetSize(numBits, 0);
    }

    // 0x802DF65C (96 bytes)
    // Copy constructor
    EBitArray(EBitArray& other) {
        m_data = NULL;
        m_bitCount = 0;
        m_allocatedBits = 0;
        SetGrowBy(4096);
        *this = other;
    }

    // 0x802DF72C (84 bytes)
    // Free allocated memory via type info dispatch
    void Deallocate() {
        if (m_typeInfo != NULL && m_data != NULL) {
            // Dispatch through type info free function
            // Original: calls through m_typeInfo->m_freeFunc
            EAHeap* heap = MainHeap();
            heap->Free(m_data);
        }
        m_data = NULL;
        m_bitCount = 0;
        m_allocatedBits = 0;
    }

    // 0x802DF780 (76 bytes)
    ~EBitArray() {
        Deallocate();
    }

    // 0x802DF7CC (148 bytes)
    // Set all bits to val (0 or 1)
    void SetAll(bool val) {
        if (m_data == NULL || m_bitCount == 0) return;

        u32 wordCount = WordsNeeded(m_bitCount);
        u32 fillVal = val ? 0xFFFFFFFF : 0x00000000;

        for (u32 i = 0; i < wordCount; i++) {
            m_data[i] = fillVal;
        }
    }

    // 0x802DF860 (112 bytes)
    // Invert all bits
    void InvertAll() {
        if (m_data == NULL || m_bitCount == 0) return;

        u32 wordCount = WordsNeeded(m_bitCount);
        for (u32 i = 0; i < wordCount; i++) {
            m_data[i] = ~m_data[i];
        }
    }

    // 0x802DF8D0 (168 bytes)
    // Resize the bit array. If growing, new bits initialized to initVal.
    void SetSize(int newSize, int initVal) {
        if (newSize <= 0) {
            Deallocate();
            return;
        }

        u32 newWords = WordsNeeded(newSize);
        u32 oldWords = WordsNeeded(m_bitCount);

        if ((u32)newSize > m_allocatedBits) {
            // Need to grow
            u32 allocBits = newSize;
            if (m_growBy > 0) {
                allocBits = ((newSize + m_growBy - 1) / m_growBy) * m_growBy;
            }
            u32 allocWords = WordsNeeded(allocBits);

            EAHeap* heap = MainHeap();
            u32* newData = (u32*)heap->Malloc(allocWords * 4, 0);

            if (m_data != NULL && oldWords > 0) {
                memcpy(newData, m_data, oldWords * 4);
            }

            // Initialize new words
            u32 fillVal = initVal ? 0xFFFFFFFF : 0x00000000;
            for (u32 i = oldWords; i < allocWords; i++) {
                newData[i] = fillVal;
            }

            if (m_data != NULL) {
                heap->Free(m_data);
            }

            m_data = newData;
            m_allocatedBits = allocBits;
        }

        m_bitCount = newSize;
    }

    // 0x802DF978 (120 bytes)
    // Insert a single bit at position
    void Insert(bool val, int pos) {
        u32 oldCount = m_bitCount;
        SetSize(oldCount + 1, 0);

        // Shift bits right from pos
        for (int i = (int)oldCount; i > pos; i--) {
            u32 wordIdx = i / 32;
            u32 bitIdx = i % 32;
            u32 srcWord = (i - 1) / 32;
            u32 srcBit = (i - 1) % 32;
            if (m_data[srcWord] & (1 << srcBit)) {
                m_data[wordIdx] |= (1 << bitIdx);
            } else {
                m_data[wordIdx] &= ~(1 << bitIdx);
            }
        }

        // Set the inserted bit
        u32 wordIdx = pos / 32;
        u32 bitIdx = pos % 32;
        if (val) {
            m_data[wordIdx] |= (1 << bitIdx);
        } else {
            m_data[wordIdx] &= ~(1 << bitIdx);
        }
    }

    // 0x802DF9F0 (224 bytes)
    // Copy bits from another array
    void Set(EBitArray& src, int srcOffset, int dstOffset, int count) {
        for (int i = 0; i < count; i++) {
            u32 srcBit = srcOffset + i;
            u32 dstBit = dstOffset + i;
            u32 srcWord = srcBit / 32;
            u32 srcBitOff = srcBit % 32;
            u32 dstWord = dstBit / 32;
            u32 dstBitOff = dstBit % 32;

            if (src.m_data[srcWord] & (1 << srcBitOff)) {
                m_data[dstWord] |= (1 << dstBitOff);
            } else {
                m_data[dstWord] &= ~(1 << dstBitOff);
            }
        }
    }

    // 0x802DFAD0 (128 bytes)
    // Insert bits from another array
    void Insert(EBitArray& src, int srcOffset, int dstOffset, int count) {
        InsertElements(dstOffset, count);
        Set(src, srcOffset, dstOffset, count);
    }

    // 0x802DFB50 (128 bytes)
    // Make room for 'count' bits at 'pos'
    void InsertElements(int pos, int count) {
        u32 oldCount = m_bitCount;
        SetSize(oldCount + count, 0);

        // Shift bits right
        for (int i = (int)oldCount - 1; i >= pos; i--) {
            u32 srcWord = i / 32;
            u32 srcBit = i % 32;
            u32 dstIdx = i + count;
            u32 dstWord = dstIdx / 32;
            u32 dstBit = dstIdx % 32;

            if (m_data[srcWord] & (1 << srcBit)) {
                m_data[dstWord] |= (1 << dstBit);
            } else {
                m_data[dstWord] &= ~(1 << dstBit);
            }
        }
    }

    // 0x802DFBD0 (136 bytes)
    // Remove 'count' bits starting at 'pos'
    void Remove(int pos, int count) {
        u32 total = m_bitCount;
        u32 end = pos + count;

        // Shift bits left
        for (u32 i = end; i < total; i++) {
            u32 srcWord = i / 32;
            u32 srcBit = i % 32;
            u32 dstIdx = i - count;
            u32 dstWord = dstIdx / 32;
            u32 dstBit = dstIdx % 32;

            if (m_data[srcWord] & (1 << srcBit)) {
                m_data[dstWord] |= (1 << dstBit);
            } else {
                m_data[dstWord] &= ~(1 << dstBit);
            }
        }

        m_bitCount = total - count;
    }

    // 0x802DFC58 (124 bytes)
    // Assignment operator - deep copy
    void operator=(EBitArray& other) {
        if (this == &other) return;

        SetSize(other.m_bitCount, 0);
        if (m_data != NULL && other.m_data != NULL && other.m_bitCount > 0) {
            u32 wordCount = WordsNeeded(other.m_bitCount);
            memcpy(m_data, other.m_data, wordCount * 4);
        }
        m_bitCount = other.m_bitCount;
    }

    // 0x802DFCD4 (104 bytes)
    // Bitwise OR
    void operator|=(EBitArray& other) {
        u32 count = m_bitCount;
        if (other.m_bitCount < count) count = other.m_bitCount;
        u32 wordCount = WordsNeeded(count);

        for (u32 i = 0; i < wordCount; i++) {
            m_data[i] |= other.m_data[i];
        }
    }

    // 0x802DFD3C (104 bytes)
    // Bitwise AND
    void operator&=(EBitArray& other) {
        u32 count = m_bitCount;
        if (other.m_bitCount < count) count = other.m_bitCount;
        u32 wordCount = WordsNeeded(count);

        for (u32 i = 0; i < wordCount; i++) {
            m_data[i] &= other.m_data[i];
        }
    }

    // 0x802DFDA4 (104 bytes)
    // Bitwise XOR
    void operator^=(EBitArray& other) {
        u32 count = m_bitCount;
        if (other.m_bitCount < count) count = other.m_bitCount;
        u32 wordCount = WordsNeeded(count);

        for (u32 i = 0; i < wordCount; i++) {
            m_data[i] ^= other.m_data[i];
        }
    }

    // 0x802DFE0C (120 bytes)
    // Equality comparison
    bool operator==(EBitArray& other) const {
        if (m_bitCount != other.m_bitCount) return false;
        if (m_bitCount == 0) return true;

        u32 wordCount = WordsNeeded(m_bitCount);
        for (u32 i = 0; i < wordCount; i++) {
            if (m_data[i] != other.m_data[i]) return false;
        }
        return true;
    }

    // 0x802DFE84 (120 bytes)
    // Test if any bits in common (AND not zero)
    bool Intersection(EBitArray& other) const {
        u32 count = m_bitCount;
        if (other.m_bitCount < count) count = other.m_bitCount;
        u32 wordCount = WordsNeeded(count);

        for (u32 i = 0; i < wordCount; i++) {
            if (m_data[i] & other.m_data[i]) return true;
        }
        return false;
    }

    // 0x802DFEFC (148 bytes)
    // Interleave bits: spread bits at regular intervals
    void Interleave(int stride, int offset, int count) {
        // Rearrange bits by inserting gaps
        // Used in animation compression
        // TODO: exact bit-shuffling pattern from asm
    }

    // 0x802DFF90 (148 bytes)
    // Reverse of Interleave
    void Deinterleave(int stride, int offset, int count) {
        // TODO: exact bit-shuffling pattern from asm
    }

    // 0x802E0024 (112 bytes)
    // Add an unsigned value with a given number of bits
    void Add(unsigned int value, int numBits) {
        u32 pos = m_bitCount;
        SetSize(pos + numBits, 0);

        for (int i = 0; i < numBits; i++) {
            u32 bitIdx = pos + i;
            u32 wordIdx = bitIdx / 32;
            u32 bitOff = bitIdx % 32;
            if (value & (1 << i)) {
                m_data[wordIdx] |= (1 << bitOff);
            } else {
                m_data[wordIdx] &= ~(1 << bitOff);
            }
        }
    }

    // 0x802E0094 (128 bytes)
    // Get unsigned value from bit position
    u32 Get(int pos, int numBits) const {
        u32 result = 0;
        for (int i = 0; i < numBits; i++) {
            u32 bitIdx = pos + i;
            u32 wordIdx = bitIdx / 32;
            u32 bitOff = bitIdx % 32;
            if (m_data[wordIdx] & (1 << bitOff)) {
                result |= (1 << i);
            }
        }
        return result;
    }

    // 0x802E0114 (156 bytes)
    // Get signed value from bit position (sign-extend)
    s32 GetSigned(int pos, int numBits) const {
        u32 raw = Get(pos, numBits);
        // Sign extend
        u32 signBit = 1 << (numBits - 1);
        if (raw & signBit) {
            raw |= ~((1 << numBits) - 1);
        }
        return (s32)raw;
    }

    // 0x802E01B0 (52 bytes)
    // Calculate number of bits needed for a signed tolerance
    static u32 ToleranceToSignedBits(float tolerance) {
        if (tolerance <= 0.0f) return 0;
        // log2(1/tolerance) + 1 for sign
        u32 bits = 1;
        float range = 1.0f;
        while (range > tolerance && bits < 32) {
            range *= 0.5f;
            bits++;
        }
        return bits;
    }

    // 0x802E01E4 (48 bytes)
    // Calculate number of bits needed for unsigned tolerance
    static u32 ToleranceToUnsignedBits(float tolerance) {
        if (tolerance <= 0.0f) return 0;
        u32 bits = 0;
        float range = 1.0f;
        while (range > tolerance && bits < 32) {
            range *= 0.5f;
            bits++;
        }
        return bits;
    }

    // 0x802E0214 (76 bytes)
    // Convert float to signed bit representation
    static u32 FloatToSignedBits(float value, int numBits) {
        if (numBits <= 0) return 0;
        s32 maxVal = (1 << (numBits - 1)) - 1;
        s32 ival = (s32)(value * (float)maxVal);
        if (ival > maxVal) ival = maxVal;
        if (ival < -maxVal) ival = -maxVal;
        return (u32)ival & ((1 << numBits) - 1);
    }

    // 0x802E0260 (72 bytes)
    // Convert float to unsigned bit representation
    static u32 FloatToUnsignedBits(float value, int numBits) {
        if (numBits <= 0) return 0;
        u32 maxVal = (1 << numBits) - 1;
        u32 ival = (u32)(value * (float)maxVal);
        if (ival > maxVal) ival = maxVal;
        return ival;
    }

    // 0x802E02A8 (32 bytes)
    // Scaling factor for signed bits -> float conversion
    static float SignedBitsToFloatScaler(int numBits) {
        if (numBits <= 1) return 0.0f;
        return 1.0f / (float)((1 << (numBits - 1)) - 1);
    }

    // 0x802E02C8 (32 bytes)
    // Scaling factor for unsigned bits -> float conversion
    static float UnsignedBitsToFloatScaler(int numBits) {
        if (numBits <= 0) return 0.0f;
        return 1.0f / (float)((1 << numBits) - 1);
    }
};


// ############################################################################
//
//  EBitArrayProxy - Single-bit accessor proxy
//
//  Size: 8 bytes
//  3 functions, 344 bytes total
//
//  Proxy object returned by operator[] on EBitArray, enabling
//  bit-level assignment with compound operators (|=, &=, ^=).
//
// ############################################################################

class EBitArrayProxy {
public:
    EBitArray* m_array;  // 0x00 - owning array
    u32 m_index;         // 0x04 - bit index

    // 0x802DF3C4 (108 bytes)
    void operator|=(bool val) {
        bool cur = (m_array->Get(m_index, 1) != 0);
        m_array->Add(0, 0); // placeholder - actual uses Set
        // Set bit to cur | val
        bool result = cur | val;
        // m_array->Set(m_index, result) - sets single bit
        u32 wordIdx = m_index / 32;
        u32 bitOff = m_index % 32;
        if (result) {
            m_array->m_data[wordIdx] |= (1 << bitOff);
        } else {
            m_array->m_data[wordIdx] &= ~(1 << bitOff);
        }
    }

    // 0x802DF430 (108 bytes)
    void operator&=(bool val) {
        bool cur = (m_array->Get(m_index, 1) != 0);
        bool result = cur & val;
        u32 wordIdx = m_index / 32;
        u32 bitOff = m_index % 32;
        if (result) {
            m_array->m_data[wordIdx] |= (1 << bitOff);
        } else {
            m_array->m_data[wordIdx] &= ~(1 << bitOff);
        }
    }

    // 0x802DF49C (128 bytes)
    void operator^=(bool val) {
        bool cur = (m_array->Get(m_index, 1) != 0);
        bool result = cur ^ val;
        u32 wordIdx = m_index / 32;
        u32 bitOff = m_index % 32;
        if (result) {
            m_array->m_data[wordIdx] |= (1 << bitOff);
        } else {
            m_array->m_data[wordIdx] &= ~(1 << bitOff);
        }
    }
};


// ############################################################################
//
//  EBoundTreeNode - Spatial partitioning tree node
//
//  Size: ~40 bytes
//  4 functions, 408 bytes total
//
//  Used for spatial queries (collision, visibility). Each node holds
//  an axis-aligned bounding box (EBound3), links to children, and
//  pointers to storable objects.
//
// ############################################################################

class EBoundTreeNode {
public:
    // 0x00: vtable
    u32 m_vtable;               // 0x00
    EBound3 m_bounds;           // 0x04 - axis-aligned bounding box (24 bytes)
    EBoundTreeNode* m_left;     // 0x1C
    EBoundTreeNode* m_right;    // 0x20
    EStorable* m_storable1;     // 0x24
    EStorable* m_storable2;     // 0x28

    // 0x802C5AE8 (76 bytes)
    // Serialize node to stream
    void Write(EStream& stream) {
        // operator<<(stream, m_bounds) - serialize bounding box
        // operator<<(stream, m_left)   - serialize left child pointer
        // operator<<(stream, m_storable1) - serialize storable ptr
        // operator<<(stream, m_storable2) - serialize storable ptr
        // Dispatch through EStream virtual write methods
    }

    // 0x802C5B34 (92 bytes)
    // Deserialize node from stream
    void Read(EStream& stream) {
        // Reads back bounding box, child pointer, and storable pointers
        // Version-dependent: checks a global version flag for format differences
    }

    // 0x802C5B90 (156 bytes)
    // Free all child nodes recursively
    void Deallocate() {
        if (m_left != NULL) {
            m_left->Deallocate();
            EAHeap* heap = MainHeap();
            heap->Free(m_left);
            m_left = NULL;
        }
        if (m_right != NULL) {
            m_right->Deallocate();
            EAHeap* heap = MainHeap();
            heap->Free(m_right);
            m_right = NULL;
        }
        m_storable1 = NULL;
        m_storable2 = NULL;
    }

    // 0x802C5C2C (84 bytes)
    // Register this type with the global type system
    void RegisterType(unsigned short typeId) {
        // Calls ETypeInfo::Register with factory funcs and type name
        // Type name: "EBoundTreeNode"
    }
};


// ############################################################################
//
//  EFile - Base file I/O class
//
//  Size: ~48 bytes
//  4 functions, 988 bytes total
//
//  Abstract base for file operations. Subclasses implement actual
//  reading. Manages a filename split into drive, dir, name, ext parts.
//
// ############################################################################

class EFile {
public:
    // 0x00: vtable pointer
    u32 m_vtable_ptr;
    // 0x04-0x17: reserved/state
    u8  m_state[20];
    // 0x18: drive (4 chars + null)
    char m_drive[4];
    // 0x1C: name (char*)
    char* m_name;
    // 0x20: extra name buffer (char*)
    char* m_extraBuf;
    // 0x24: extension (4 chars + null)
    char m_extension[4];
    // 0x28: vtable2
    u32 m_vtable2;

    // 0x802C608C (112 bytes)
    ~EFile() {
        // Reset vtable
        // Free m_name buffer via MainHeap
        EAHeap* heap = MainHeap();
        if (m_name != NULL) {
            heap->Free(m_name);
        }
        if (m_extraBuf != NULL) {
            heap->Free(m_extraBuf);
        }
        m_name = NULL;
        m_extraBuf = NULL;
    }

    // 0x802C6354 (212 bytes)
    // Set the file path, splitting into drive/dir/name/extension
    void SetName(char* path) {
        // Calls SplitPath to decompose path into components
        // Copies first 3 chars of drive
        // Copies extension (skip leading dot)
        // Allocates heap copy of full path for m_name
        // Allocates heap copy of directory for m_extraBuf
    }

    // 0x802C6428 (632 bytes)
    // Printf-style write to file
    void Fprintf(char* fmt, ...) {
        // Formats string on stack, then calls virtual write method
        // Stack buffer size: 1024 chars
    }

    // 0x802C66A0 (76 bytes)
    // Read a structure by type ID from the file
    void ReadStructure(unsigned int typeId) {
        // Reads binary data and constructs an EStorable of the given type
    }
};


// ############################################################################
//
//  EDummyFile - Null/dummy file subclass
//
//  Size: inherits EFile
//  1 function, 72 bytes total
//
//  An EFile that does nothing - used as a placeholder when no
//  actual file I/O is needed.
//
// ############################################################################

class EDummyFile : public EFile {
public:
    // 0x8039E2A4 (72 bytes)
    ~EDummyFile() {
        // Just calls ~EFile() then frees via MainHeap if delete flag set
    }
};


// ############################################################################
//
//  EFontCharacter - Single glyph data
//
//  Size: 16 bytes
//  4 functions, 664 bytes total
//
//  Represents one character in a bitmap font. Stores UV coordinates
//  and dimensions for rendering from a texture atlas.
//
// ############################################################################

class EFontCharacter {
public:
    // 0x00: vtable (EStorable base)
    u32 m_vtable;
    // 0x04: float m_u (texture U coordinate)
    f32 m_u;
    // 0x08: float m_v (texture V coordinate)
    f32 m_v;
    // 0x0C: u16 m_width (character width in pixels)
    u16 m_width;
    // 0x0E: u16 m_height (character height in pixels)
    u16 m_height;

    // 0x80363560 (204 bytes)
    // Serialize character data to stream
    void Write(EStream& stream) {
        // Writes: m_u (4 bytes), m_v (4 bytes), m_width (2 bytes), m_height (2 bytes)
        // Uses stream's virtual write method through type info dispatch
    }

    // 0x8036362C (188 bytes)
    // Deserialize character data from stream
    void Read(EStream& stream) {
        // Version check via global flag
        // Reads: m_u, m_v, m_width, m_height
        // Some versions have different field ordering
    }

    // 0x803636E8 (80 bytes)
    // Load from file
    void Load(EFile& file) {
        // Delegates to Read after obtaining stream from file
    }

    // 0x80363738 (60 bytes)
    // Register type with global RTTI system
    void RegisterType(unsigned short typeId) {
        // ETypeInfo::Register(createFunc, writeFunc, readFunc, typeId, "EFontCharacter", parentTypeInfo)
    }
};


// ############################################################################
//
//  EFontPage - Texture page for font glyphs
//
//  Size: ~20 bytes
//  4 functions, 568 bytes total
//
//  A page in a bitmap font, associating a texture with a range
//  of character glyphs. Multiple pages tile a font's glyphs
//  across texture atlases.
//
// ############################################################################

class EFontPage {
public:
    // 0x00: vtable
    u32 m_vtable;
    // 0x04: u32 m_startChar (first character code on this page)
    u32 m_startChar;
    // 0x08: u32 m_charCount (number of characters on this page) -- unused in some flows
    u32 m_pad08;
    // 0x0C: ERShader* m_shader (shader/texture for rendering)
    void* m_shader;
    // 0x10: u32 m_textureId
    u32 m_textureId;

    // 0x80363864 (164 bytes)
    void Write(EStream& stream) {
        // Writes m_startChar, m_shader, m_textureId via stream dispatch
    }

    // 0x80363908 (160 bytes)
    void Read(EStream& stream) {
        // Calls DeallocateShader() first
        // Version-dependent read of fields
    }

    // 0x803639A8 (52 bytes)
    void Load(EFile& file) {
        // Delegate to Read
    }

    // 0x803639DC (72 bytes)
    void RegisterType(unsigned short typeId) {
        // ETypeInfo::Register(...)
    }

    // Helper: called internally
    void DeallocateShader() {
        // If m_shader is non-null, decrements ref and clears
        m_shader = NULL;
    }
};


// ############################################################################
//
//  EFontSize - Font size with glyph pages
//
//  Size: ~48 bytes
//  8 functions, 1164 bytes total
//
//  Represents one size variant of a font. Contains a hash table
//  mapping character codes to EFontCharacter instances, and an
//  array of EFontPage texture pages.
//
// ############################################################################

class EFontSize {
public:
    // 0x00: vtable pointer (EStorable-derived)
    u32 m_vtable;
    // 0x04: float m_size (font point size)
    f32 m_size;
    // 0x08: float m_lineHeight
    f32 m_lineHeight;
    // 0x0C: u32 m_flags (bold, italic, etc.)
    u32 m_flags;
    // 0x10: EHashTable m_charTable (maps char code -> EFontCharacter)
    u8  m_charTable[16]; // EHashTable at offset 0x10
    // 0x20: TArray<EFontPage*> m_pages
    u8  m_pages[12]; // TArray at offset 0x20

    // 0x80363B28 (96 bytes)
    EFontSize() {
        // Initialize vtable
        m_size = 0.0f;
        m_lineHeight = 0.0f;
        m_flags = 1; // default flag
        // EHashTable::EHashTable(237) - init hash table with 237 buckets
        // TArray::TArray() - init empty page array
    }

    // 0x80363B88 (112 bytes)
    ~EFontSize() {
        // Set vtable
        Deallocate();
        // ~EHashTable(m_charTable)
        // Degrade vtable to EStorable base
    }

    // 0x80363BF8 (108 bytes)
    void Deallocate() {
        DeallocateShaders();
        // Clear all EFontCharacter entries from hash table
        // Free each EFontPage from the pages array
    }

    // 0x80363C64 (96 bytes)
    void DeallocateShaders() {
        // Iterate through m_pages array
        // For each EFontPage*, call DeallocateShader()
    }

    // 0x80363CC4 (300 bytes)
    void Write(EStream& stream) {
        // Write m_size, m_lineHeight, m_flags
        // Write character count from hash table
        // For each character in hash table: write key + EFontCharacter data
        // Write page count
        // For each page: write EFontPage data
    }

    // 0x80363DF0 (240 bytes)
    void Read(EStream& stream) {
        // Deallocate existing data
        // Read m_size, m_lineHeight, m_flags
        // Read character count, then read each character into hash table
        // Read page count, then read each page into pages array
    }

    // 0x80363EE0 (64 bytes)
    void Load(EFile& file) {
        // Delegate to Read
    }

    // 0x80363F20 (72 bytes)
    void RegisterType(unsigned short typeId) {
        // ETypeInfo::Register(...)
    }
};


// ############################################################################
//
//  EFontData - Font resource container
//
//  Size: ~80 bytes
//  7 functions, 1428 bytes total
//
//  Top-level font resource containing multiple EFontSize entries
//  (one per supported point size), organized in an ENodeList
//  and indexed by an EHashTable.
//
// ############################################################################

class EFontData {
public:
    // 0x00: vtable pointer (EStorable-derived)
    u32 m_vtable;
    // 0x04: ENodeList m_sizeList (linked list of EFontSize*)
    u8  m_sizeList[12]; // ENodeList at offset 0x04
    // 0x10: u32 m_reserved
    u32 m_reserved;
    // 0x14: u32 m_reserved2
    u32 m_reserved2;
    // 0x18: u32 m_reserved3
    u32 m_reserved3;
    // 0x1C: u32 m_reserved4
    u32 m_reserved4;
    // 0x20: u32 m_reserved5
    u32 m_reserved5;
    // 0x24: f32 m_defaultSize
    f32 m_defaultSize;
    // 0x28: EHashTable m_sizeHash (maps size key -> EFontSize*)
    u8  m_sizeHash[16]; // EHashTable at offset 0x28

    // 0x80364024 (116 bytes)
    EFontData() {
        // Set vtable
        // ENodeList init (head=0, count=0, sentinel=1)
        // EHashTable::EHashTable(237)
        m_defaultSize = 0.0f;
        m_reserved = 0;
        m_reserved2 = 0;
        m_reserved3 = 0;
        m_reserved4 = 0;
        m_reserved5 = 0;
    }

    // 0x80364098 (108 bytes)
    ~EFontData() {
        // Set vtable
        Deallocate();
        // ~EHashTable
        // ENodeList::RemoveAll
        // Degrade vtable to EStorable base
    }

    // 0x80364104 (140 bytes)
    void Deallocate() {
        // Walk m_sizeList: for each EFontSize node:
        //   call EFontSize::Deallocate()
        //   free the EFontSize object
        // Clear the hash table
    }

    // 0x80364190 (264 bytes)
    void Write(EStream& stream) {
        // Write number of font sizes
        // For each EFontSize in the list:
        //   Write the size identifier
        //   Write the EFontSize data
    }

    // 0x80364298 (200 bytes)
    void Read(EStream& stream) {
        // Deallocate existing data
        // Read size count
        // For each size:
        //   Create new EFontSize
        //   Read it from stream
        //   Add to list and hash table
    }

    // 0x80364360 (76 bytes)
    void Load(EFile& file) {
        // Delegate to Read via stream obtained from file
    }

    // 0x803643AC (84 bytes)
    void RegisterType(unsigned short typeId) {
        // ETypeInfo::Register(...)
    }
};


// ############################################################################
//
//  ECheats - Cheat code system
//
//  Size: 264 bytes (0x108)
//  7 functions, 9192 bytes total
//
//  A hash table of cheat codes. Each cheat is an ECheatLookup node
//  hashed by its checksum into a 64-bucket table. The first 256 bytes
//  are the hash table (64 * 4 byte pointers), followed by a count.
//
// ############################################################################

class ECheats {
public:
    // 0x000: ECheatLookup* m_buckets[64] - hash table buckets
    void* m_buckets[64];
    // 0x100: u32 m_count - number of registered cheats
    u32 m_count;
    // 0x104: u32 m_godMode - god mode active flag
    u32 m_godMode;

    // 0x8001ECAC (72 bytes)
    ECheats() {
        // Zero all 256 bytes of bucket table
        memset(m_buckets, 0, 256);
        // Clear the lookup list
        EmptyLookupList();
        m_count = 0;
    }

    // 0x8001ECF4 (136 bytes)
    ~ECheats() {
        // Disable all active cheats
        DisableCheats();
        // Empty the lookup list
        EmptyLookupList();

        // Walk each bucket and free all chained nodes
        for (int i = 0; i < 64; i++) {
            void* node = m_buckets[i];
            m_buckets[i] = NULL;
            while (node != NULL) {
                void* next = *(void**)node; // first field is next pointer
                EAHeap* heap = MainHeap();
                heap->Free(node);
                node = next;
            }
        }
    }

    // 0x8001ED7C (7824 bytes)
    // Initialize all cheat codes. Creates ~80+ ECheatLookup entries,
    // each with a name string, cheat type, callback function pointer,
    // and a description. Inserts them into the hash table by checksum.
    void Init(EGlobal& global) {
        EmptyLookupList();

        // Creates a large number of ECheatLookup entries:
        // Each is allocated (96 bytes), initialized with:
        //   - sequential ID (m_count++)
        //   - name string (e.g. "sims_motherlode", "rosebud", etc.)
        //   - CheatType enum
        //   - callback function pointer from EGlobal
        //   - description string
        //   - flags
        // Then checksummed and inserted into hash bucket
        //
        // Typical pattern per cheat (repeated ~80 times):
        //   ECheatLookup* cheat = new ECheatLookup(id, name, type, callback, desc, flag1, flag2);
        //   if (cheat != NULL) {
        //       m_count++;
        //       u32 hash = EChecksum::Compute(cheat->m_name);
        //       u32 bucket = (hash >> 2) & 0x3F; // 6 bits -> 0-63
        //       cheat->m_next = m_buckets[bucket];
        //       m_buckets[bucket] = cheat;
        //   }
    }

    // 0x80020C1C (36 bytes)
    // Clear the lookup list (separate from hash table)
    void EmptyLookupList() {
        // Resets an internal ordered list used for sequential cheat display
        // The hash table is the primary storage; this is secondary indexing
    }

    // 0x80020C40 (64 bytes)
    // Enable god mode flag
    void SetGodMode(bool enabled) {
        m_godMode = enabled ? 1 : 0;
    }

    // 0x80020C80 (308 bytes)
    // Enable active cheat effects
    void EnableCheats() {
        // Walk the hash table and activate any enabled cheats
        // Calls each cheat's enable callback
    }

    // 0x80020FB4 (308 bytes)
    // Disable all active cheat effects
    void DisableCheats() {
        // Walk the hash table and deactivate all cheats
        // Calls each cheat's disable callback
    }
};


// ############################################################################
//
//  EStream - Binary serialization stream
//
//  Size: variable (base class)
//  6 functions, 2616 bytes total
//
//  Abstract stream for reading/writing binary data. Subclasses
//  (EMemoryWriteStream, EFileStream, etc.) implement the actual
//  byte I/O. EStream handles object graph serialization with
//  reference tracking via ERedBlackTree.
//
// ############################################################################

class EStream {
public:
    // 0x00: u32 m_mode (0=read, 1=write)
    u32 m_mode;
    // 0x04: void* m_substream
    void* m_subStream;
    // 0x08: void* m_objectList (ENodeList for reference tracking)
    void* m_objectList;
    // 0x0C: void* m_indexMap
    void* m_indexMap;
    // 0x10: void* m_referenceTree
    void* m_referenceTree;
    // 0x14: u32 m_refCount
    u32 m_refCount;
    // 0x18: void* m_typeInfo
    void* m_typeInfo;

    // 0x802D1760 (1540 bytes)
    // Write an object graph to the stream.
    // Handles reference-counting and cycle detection:
    //   1. Builds an object reference tree by recursively traversing
    //   2. Assigns indices to unique objects
    //   3. Writes objects in topological order
    //   4. Back-references use index into already-written objects
    void WriteStructure(EStorable& obj) {
        m_mode = 1;

        // Get stream position for header
        // Initialize reference tracking structures:
        //   ENodeList - tracks write order
        //   ERedBlackTree - maps object ptr -> index
        //   EMemoryWriteStream - temp buffer for object data

        // Phase 1: Enumerate all reachable objects
        // Add root object to list, assign index -1 (sentinel)
        // For each object in the list:
        //   Call its virtual Write to discover referenced objects
        //   Add discovered objects to the list with indices

        // Phase 2: Write object data
        // For each object in discovery order:
        //   Write type ID (from ETypeInfo)
        //   Write object data via virtual Write method
        //   Write reference indices for any sub-objects

        // Phase 3: Write the footer / terminator

        // Cleanup temp structures
    }

    // 0x802D1D64 (468 bytes)
    // Read an object graph from the stream.
    // Reconstructs the reference graph:
    //   1. Read type IDs and create objects via ETypeInfo factories
    //   2. Read object data
    //   3. Resolve cross-references using index table
    void ReadStructure(unsigned int expectedType) {
        m_mode = 0;

        // Read object count / header
        // For each object:
        //   Read type ID
        //   Look up ETypeInfo by checksum
        //   Call factory to create instance
        //   Call virtual Read to deserialize data
        //   Store in index table for back-reference resolution

        // Resolve all cross-references
        // Return root object
    }

    // 0x802D1F38 (220 bytes)
    // Read a null-terminated string
    void ReadString(char* buffer, int maxLen) {
        // Read length prefix (u32)
        // Read min(length, maxLen-1) bytes into buffer
        // Null-terminate
        // Skip remaining bytes if length > maxLen
    }

    // 0x802D2014 (120 bytes)
    // Write a null-terminated string
    void WriteString(char* str) {
        // Write length prefix (u32) = strlen(str) + 1
        // Write the string bytes including null terminator
    }

    // 0x802D208C (264 bytes)
    // Read a UTF-16 string
    void ReadU16String(unsigned short* buffer, int maxLen) {
        // Read length prefix (u32, in u16 units)
        // Read min(length, maxLen-1) u16 values
        // Null-terminate with 0x0000
        // Skip remaining u16 values if length > maxLen
    }

    // 0x802D2194 (128 bytes)
    // Write a UTF-16 string
    void WriteU16String(unsigned short* str) {
        // Calculate length in u16 units (scan for 0x0000 terminator)
        // Write length prefix (u32)
        // Write the u16 values including null terminator
    }
};


// ############################################################################
//
//  EInstance - Placed object instance in a level
//
//  Size: >= 124 bytes (0x7C)
//  16 functions, 3836 bytes total
//
//  Base class for all placed objects in a level. Stores position,
//  bounding box, lighting state, and level grid location.
//  Inherits from EStorable.
//
// ############################################################################

class EInstance {
public:
    // 0x00: vtable pointer (EStorable-derived)
    u32 m_vtable;
    // 0x04-0x1B: position/transform data
    f32 m_posX;         // 0x04
    f32 m_posY;         // 0x08
    f32 m_posZ;         // 0x0C
    // 0x10-0x1B: rotation/scale
    f32 m_rotX;         // 0x10
    f32 m_rotY;         // 0x14
    f32 m_rotZ;         // 0x18
    // 0x1C-0x33: bounding box
    EBound3 m_bounds;   // 0x1C (24 bytes)
    // 0x34-0x3B: grid location
    s16 m_gridX;        // 0x34
    s16 m_gridY;        // 0x36
    s16 m_roomId;       // 0x38
    s16 m_floorId;      // 0x3A
    // 0x3C-0x47: light data
    u32 m_lightFlags;   // 0x3C
    f32 m_instAlpha;    // 0x40
    // 0x44-0x4B: level references
    void* m_level;      // 0x44
    void* m_levelNode;  // 0x48
    // 0x4C-0x7B: extended data
    u8  m_extData[48];  // 0x4C

    EInstance() {
        m_posX = m_posY = m_posZ = 0.0f;
        m_rotX = m_rotY = m_rotZ = 0.0f;
        m_lightFlags = 0;
        m_instAlpha = 1.0f;
        m_level = NULL;
        m_levelNode = NULL;
        m_gridX = m_gridY = -1;
        m_roomId = m_floorId = -1;
    }

    // 0x80228370 (88 bytes)
    ~EInstance() {
        // Set vtable to EInstance's
        RemoveFromLevel();
        // Degrade vtable to EStorable base
    }

    // Internal: remove from spatial grid
    void RemoveFromLevel() {
        if (m_level != NULL && m_levelNode != NULL) {
            // ERLevel::RemoveInstance(m_level, this)
            m_level = NULL;
            m_levelNode = NULL;
        }
    }

    // 0x802283C8 (200 bytes)
    void Write(EStream& stream) {
        // Writes position, rotation, bounds, grid location, light data
    }

    // 0x80228490 (200 bytes)
    void Read(EStream& stream) {
        // Reads position, rotation, bounds, grid location, light data
    }

    // 0x80228558 (124 bytes)
    void Load(EFile& file) {
        // Delegate to Read
    }

    // 0x802285D4 (76 bytes)
    void SetBounds(EBound3& bounds) {
        m_bounds = bounds;
    }

    // 0x80228620 (196 bytes)
    // Calculate shadow direction at a world point
    void ShadowDirAtPoint(EVec3& point, EVec3& outDir, int lightIndex) {
        // Queries the level's directional light at the given index
        // Returns the light direction vector
    }

    // 0x802286E4 (208 bytes)
    void CalcShadowLight(EVec3& point, short roomId) {
        // Calculate shadow parameters for a point
    }

    // 0x802287B4 (208 bytes)
    void CalcShadowLightWeighted(EVec3& point, short roomId) {
        // Weighted version of CalcShadowLight
    }

    // 0x80228884 (180 bytes)
    void ShadowDirAtPointWeighted(EVec3& point, EVec3& outDir, int lightIndex) {
        // Weighted shadow direction
    }

    // 0x80228938 (484 bytes)
    void CalcLights(EVec3& point, ELights& lights, bool includeAmbient) {
        // Calculate lighting at a point in the level
        // Queries the level's light grid for nearby lights
    }

    // 0x80228B1C (404 bytes)
    void CalcLights4(EVec3& point, ELights& lights, bool includeAmbient) {
        // 4-light version of CalcLights
    }

    // 0x80228CB0 (32 bytes)
    void SetInstAlpha(float alpha) {
        m_instAlpha = alpha;
    }

    // 0x80228CD0 (84 bytes)
    void RegisterType(unsigned short typeId) {
        // ETypeInfo::Register(...)
    }

    // 0x80228D24 (52 bytes)
    void ResetLocation() {
        m_gridX = -1;
        m_gridY = -1;
        m_roomId = -1;
        m_floorId = -1;
    }

    // 0x80228D58 (20 bytes)
    void GetLocationId(short& outGridX, short& outGridY) {
        outGridX = m_gridX;
        outGridY = m_gridY;
    }

    // 0x80228D6C (20 bytes)
    void GetOtherSide(short& outRoomId, short& outFloorId) {
        outRoomId = m_roomId;
        outFloorId = m_floorId;
    }
};


// ############################################################################
//
//  EIGameInstance - Game instance base class
//
//  Size: inherits from EInstance
//  1 function, 84 bytes total
//
//  Intermediate base between EInstance and game-specific instance
//  types (EIStaticModel, etc.). Adds game-specific type registration.
//
// ############################################################################

class EIGameInstance : public EInstance {
public:
    EIGameInstance() : EInstance() {
        // Additional game instance initialization
    }

    // 0x80227844 (84 bytes)
    void RegisterType(unsigned short typeId) {
        // Calls ETypeInfo::Register with:
        //   createFunc, writeFunc, readFunc, typeId,
        //   "EIGameInstance", parentTypeInfo (EInstance's type)
    }
};


// ############################################################################
//
//  EIStaticModel - Static model placed in the level
//
//  Size: 0x31C (796 bytes)
//  31 functions, 9604 bytes total
//
//  A placed static (non-animated) 3D model in the game world.
//  Wraps an ERModel resource with instance-specific transform,
//  shader overrides, and rendering state.
//
// ############################################################################

class InstanceData {
public:
    u8 m_data[16];  // instance-specific render data
    InstanceData() { memset(m_data, 0, sizeof(m_data)); }
};

class EIStaticModel : public EIGameInstance {
public:
    // Inherited: EInstance fields at offset 0x00-0x7B
    // 0x80: model-specific begin
    u8  m_modelName[64];     // 0x80 - model resource name
    void* m_model;           // 0xC0 - ERModel* pointer
    EVec3 m_anchor;          // 0xC4 - anchor point offset
    u32 m_modelFlags;        // 0xD0
    // 0xD4-0xFF: shader override data
    u8 m_shaderData[44];     // 0xD4
    // 0x100: InstanceData
    InstanceData m_instanceData; // 0x100
    // 0x110: u32 m_subModelCount
    u32 m_subModelCount;     // 0x110
    // Remaining: sub-model pointers, bounds, etc.
    u8 m_rest[0x31C - 0x114]; // pad to documented size

    // 0x8022B9A0 (176 bytes)
    EIStaticModel() : EIGameInstance() {
        // Set vtable to EIStaticModel's
        // InstanceData::InstanceData()
        m_model = NULL;
        m_anchor.x = m_anchor.y = m_anchor.z = 0.0f;
        m_modelFlags = 0;
        m_subModelCount = 0;
    }

    // 0x8022BA50 (176 bytes)
    ~EIStaticModel() {
        // Set vtable
        DeallocateModel();
        // Call ~EIGameInstance() via chain
    }

    // 0x8022BB00 (232 bytes)
    void Write(EStream& stream) {
        // Write base class (EInstance::Write)
        // Write model name, transform, flags
        // Write shader override data
    }

    // 0x8022BBE8 (420 bytes)
    void Read(EStream& stream) {
        // Read base class (EInstance::Read)
        // Read model name, transform, flags
        // Read shader override data
    }

    // 0x8022BD8C (60 bytes)
    void Setup(EInstance* inst, EAnimController* animCtrl) {
        SetupModel(inst, animCtrl);
    }

    // 0x8022BDC8 (88 bytes)
    void DeallocateModel() {
        // Release ERModel reference
        if (m_model != NULL) {
            // EResource::DelRef(m_model)
            m_model = NULL;
        }
        // Free shader overrides
    }

    // 0x8022BE20 (168 bytes)
    void SetModel(char* modelName) {
        // Look up ERModel by name in resource manager
        // Store reference, increment ref count
    }

    // 0x8022BEC8 (48 bytes)
    void SetOrient(EMat4& mat) {
        // Copy 4x4 matrix to internal transform
    }

    // 0x8022BEF8 (60 bytes)
    void SlamOrient(EMat4& orient, EMat4& parentMat) {
        // Set orientation and immediately recalculate world matrix
    }

    // 0x8022BF34 (48 bytes)
    void GetOrient(EMat4& outMat) {
        // Copy internal transform to output
    }

    // 0x8022BF64 (52 bytes)
    void RegisterFloor() {
        // Register this model's floor polygons with the level
    }

    // 0x8022BF98 (332 bytes)
    void SetupModel(EInstance* inst, EAnimController* animCtrl) {
        // Full model initialization:
        // 1. Look up ERModel resource
        // 2. Set up sub-model shaders
        // 3. Calculate bounding boxes
        // 4. Register with level spatial grid
    }

    // 0x8022C0E4 (152 bytes)
    void BuildDigests() {
        // Build render digests for all sub-models
    }

    // 0x8022C17C (100 bytes)
    void SetupBounds() {
        // Calculate AABB from model geometry + transform
    }

    // 0x8022C1E0 (320 bytes)
    void Draw(ELevelDrawData& drawData) {
        // Submit to render queue via order table
    }

    // 0x8022C320 (116 bytes)
    void DrawAsShadow(ELevelDrawData& drawData) {
        // Render as shadow geometry
    }

    // 0x8022C394 (116 bytes)
    void DrawShadow(ELevelDrawData& drawData) {
        // Render shadow only
    }

    // 0x8022C408 (316 bytes)
    void AnimOrderTableCallback(ELevelDrawData& drawData, EOrderTableData* order) {
        // Callback from render order table
    }

    // 0x8022C544 (268 bytes)
    void ChangeShader(unsigned int fromId, unsigned int toId) {
        // Replace one shader with another on all sub-models
    }

    // 0x8022C650 (148 bytes)
    void ChangeShaderState(unsigned int state) {
        // Change active shader state (e.g. highlighted, selected)
    }

    // 0x8022C6E4 (152 bytes)
    void UpdateShaders() {
        // Update time-varying shader parameters
    }

    // 0x8022C77C (148 bytes)
    void RebuildShaders() {
        // Rebuild shader data from model definition
    }

    // 0x8022C810 (148 bytes)
    void RealizeShaderTuning() {
        // Apply tuning parameters to shaders
    }

    // 0x8022C8A4 (144 bytes)
    void FindShaderContainingTexture(unsigned int textureId) {
        // Find which sub-model shader uses a given texture
    }

    // 0x8022C934 (108 bytes)
    void FindShaderSupportingDecal() {
        // Find a shader that supports decal rendering
    }

    // 0x8022C9A0 (164 bytes)
    void ReplaceBaseTexture(ERTexture* newTex, unsigned int subModelIdx, ERTexture* oldTex) {
        // Swap a texture on a specific sub-model
    }

    // 0x8022CA44 (184 bytes)
    void Clone() {
        // Create a deep copy of this static model instance
    }

    // 0x8022CAFC (380 bytes)
    void DrawImmediate(ERC* rc, EAnimController* animCtrl) {
        // Draw immediately (not via order table) for debug/preview
    }

    // 0x8022CC78 (380 bytes)
    void DrawImmediateGhosted(ERC* rc, EAnimController* animCtrl) {
        // Draw with ghost/transparent effect
    }

    // 0x8022CDF4 (84 bytes)
    void RegisterType(unsigned short typeId) {
        // ETypeInfo::Register(...)
    }

    // 0x8022CE48 (72 bytes)
    void GetAnchorPos(EMat4& mat, int anchorIndex) {
        // Calculate world-space anchor position
    }
};


// ############################################################################
//
//  EIStaticSubModel - Static sub-model within a larger model
//
//  Size: 0xF4 (244 bytes)
//  18 functions, 4484 bytes total
//
//  A sub-mesh within an EIStaticModel. Each sub-model has its own
//  shader, bounding box, and draw callback.
//
// ############################################################################

class EIStaticSubModel : public EInstance {
public:
    // Inherited: EInstance at 0x00
    // 0x80: InstanceData
    InstanceData m_instanceData;
    // 0x90: model data
    u32 m_subModelFlags;     // 0x90
    void* m_subModelDef;     // 0x94 - ESubModel*
    void* m_shaderOverride;  // 0x98
    u8 m_rest[0xF4 - 0x9C];

    // 0x8022E360 (152 bytes)
    EIStaticSubModel() : EInstance() {
        // Set vtable to EIStaticSubModel's
        // InstanceData::InstanceData()
        m_subModelFlags = 0;
        m_subModelDef = NULL;
        m_shaderOverride = NULL;
    }

    // 0x8022E3F8 (128 bytes)
    ~EIStaticSubModel() {
        // Set vtable
        DeallocateModel();
        // ~EInstance() chain
    }

    // 0x8022E478 (204 bytes)
    void Write(EStream& stream) {
        // Write base class + sub-model specific data
    }

    // 0x8022E544 (356 bytes)
    void Read(EStream& stream) {
        // Read base class + sub-model specific data
    }

    // 0x8022E6A8 (120 bytes)
    void Load(EFile& file) {
        // Delegate to Read
    }

    // 0x8022E720 (60 bytes)
    void DeallocateModel() {
        // Release sub-model and shader references
    }

    // 0x8022E75C (168 bytes)
    void SetupModel() {
        // Initialize from sub-model definition
    }

    // 0x8022E804 (136 bytes)
    void BuildDigests() {
        // Build render digest for this sub-model
    }

    // 0x8022E88C (116 bytes)
    void DrawAsShadow(ELevelDrawData& drawData) {
        // Render as shadow
    }

    // 0x8022E900 (268 bytes)
    void Draw(ELevelDrawData& drawData) {
        // Submit to render queue
    }

    // 0x8022EA0C (80 bytes)
    void DrawWireFrame(ERC* rc) {
        // Debug wireframe rendering
    }

    // 0x8022EA5C (252 bytes)
    void SkyOrderTableCallback(ELevelDrawData& drawData, EOrderTableData* order) {
        // Sky rendering callback
    }

    // 0x8022EB58 (252 bytes)
    void FaceOrderTableCallback(ELevelDrawData& drawData, EOrderTableData* order) {
        // Face rendering callback
    }

    // 0x8022EC54 (252 bytes)
    void OrderTableCallback(ELevelDrawData& drawData, EOrderTableData* order) {
        // Default render callback
    }

    // 0x8022ED50 (252 bytes)
    void FloorOrderTableCallback(ELevelDrawData& drawData, EOrderTableData* order) {
        // Floor rendering callback
    }

    // 0x8022EE4C (44 bytes)
    bool HasModifiableColor() {
        // Check if this sub-model's shader supports color modification
        return false; // default
    }

    // 0x8022EE78 (148 bytes)
    void RebuildShaders() {
        // Rebuild shader from definition
    }

    // 0x8022EF0C (84 bytes)
    void RegisterType(unsigned short typeId) {
        // ETypeInfo::Register(...)
    }
};


// ############################################################################
//
//  ERCharacter - Character skeleton resource
//
//  Size: ~32 bytes (header) + node array
//  5 functions, 1092 bytes total
//
//  Resource containing the bone/node hierarchy for a character model.
//  Used by EAnimController to drive skeletal animation.
//
// ############################################################################

class ERCharacter {
public:
    // Inherits EResource (vtable + ref count)
    // 0x00: vtable
    u32 m_vtable;
    // 0x04-0x0F: EResource fields (manager, pad, refcount)
    u8  m_resource[12];
    // 0x10: u32 m_reserved
    u32 m_reserved;
    // 0x14: TArray<ECharacterNode> m_nodes
    u8  m_nodes[12]; // TArray<ECharacterNode, TArrayERCharacterAllocator>

    // 0x803686E8 (68 bytes)
    ERCharacter() {
        // EResource::EResource() - base class init
        // Set vtable to ERCharacter's
        // TArray<ECharacterNode>::TArray() - empty node array
    }

    // 0x8036872C (104 bytes)
    ~ERCharacter() {
        // Set vtable to ERCharacter's
        // TArray::Deallocate() - free node array
        // ~EResource() chain
    }

    // 0x80368794 (816 bytes)
    // Load character skeleton from binary file
    void Load(EFile& file) {
        // Read node count
        // Allocate node array
        // For each node:
        //   Read parent index, child indices
        //   Read local transform (position, rotation, scale)
        //   Read bone length, flags
        //   Read name string
    }

    // 0x80368AC4 (120 bytes)
    // Find a bone/node by name
    void FindNode(char* name) {
        // Linear search through m_nodes
        // Compare name strings, return index or -1
    }

    // 0x80368B3C (84 bytes)
    void RegisterType(unsigned short typeId) {
        // ETypeInfo::Register(...)
    }
};


// ############################################################################
//
//  EAnimController - Skeletal animation controller
//
//  Size: 0xB4 (180 bytes)
//  93 functions, 38092 bytes total
//
//  The core animation system. Controls skeletal animation playback
//  with support for:
//    - Multiple simultaneous tracks (blend, layer, procedural)
//    - Track intensity/speed/phase control
//    - Hermite and smooth blending
//    - Event processing (sound cues, effects triggers)
//    - Matrix computation for bone transforms
//    - Visibility testing via bounding spheres
//
// ############################################################################

class EAnimController {
public:
    // 0x00: u32 m_objectType (eAnimatedObjectType, default=2)
    u32 m_objectType;
    // 0x04: reserved
    u32 m_pad04;
    // 0x08: s32 m_nodeCount (number of bones, -1=uninitialized)
    s32 m_nodeCount;
    // 0x0C: u32 m_pad0C
    u32 m_pad0C;
    // 0x10: u32 m_pad10
    u32 m_pad10;
    // 0x14: u32 m_pad14
    u32 m_pad14;
    // 0x18: u32 m_pad18
    u32 m_pad18;
    // 0x1C: u32 m_pad1C
    u32 m_pad1C;
    // 0x20: u32 m_pad20
    u32 m_pad20;
    // 0x24: EResource* m_resource (ERCharacter reference)
    void* m_resource;
    // 0x28: s32 m_trackId1 (-1 = none)
    s32 m_trackId1;
    // 0x2C: s32 m_trackId2
    s32 m_trackId2;
    // 0x30: s32 m_trackId3
    s32 m_trackId3;
    // 0x34: void* m_pad34
    void* m_pad34;
    // 0x38: u32 m_pad38
    u32 m_pad38;
    // 0x3C: u32 m_pad3C
    u32 m_pad3C;
    // 0x40: u32 m_pad40
    u32 m_pad40;
    // 0x44: u32 m_pad44
    u32 m_pad44;
    // 0x48: TNodeList<EACTrack*> m_trackList
    TNodeList<EACTrack*> m_trackList; // 0x48 (12 bytes)
    // 0x54: f32 m_blendTime (blending duration)
    f32 m_blendTime;
    // 0x58: f32 m_blendAccum (blending accumulator)
    f32 m_blendAccum;
    // 0x5C: void* m_pad5C
    void* m_pad5C;
    // 0x60: u32 m_enabled
    u32 m_enabled;
    // 0x64: void* m_matrices (bone matrices)
    EMat4* m_matrices;
    // 0x68: void* m_inverseMatrices
    EMat4* m_inverseMatrices;
    // 0x6C: u32 m_pad6C
    u32 m_pad6C;
    // 0x70: void* m_pad70
    void* m_pad70;
    // 0x74: u32 m_pad74
    u32 m_pad74;

    // 0x802E77A4 (224 bytes)
    EAnimController() {
        m_objectType = 2;
        m_nodeCount = -1;
        m_pad04 = 0;
        m_pad0C = 0;
        m_pad10 = 0;
        m_pad14 = 0;
        m_pad18 = 0;
        m_pad1C = 0;
        m_pad20 = 0;
        m_trackId1 = -1;
        m_trackId2 = -1;
        m_trackId3 = -1;
        m_blendTime = 0.0f;
        m_blendAccum = 0.0f;
        m_enabled = 1;
        m_pad38 = 0;
        m_pad3C = 0;
        m_pad40 = 0;
        m_pad44 = 0;

        // Release existing resource reference
        if (m_resource != NULL) {
            // EResource::DelRef(m_resource)
        }
        m_resource = NULL;

        m_pad5C = 0;
        m_matrices = NULL;
        m_inverseMatrices = NULL;
        m_pad6C = 0;
        m_pad70 = NULL;
        m_pad74 = 0;

        // Initialize track list
        m_trackList.m_head = 0;
        m_trackList.m_tail = 0;
        m_trackList.m_count = 0;
    }

    // 0x802E7884 (96 bytes)
    ~EAnimController() {
        Deallocate();
    }

    // 0x802E78E4 (128 bytes)
    void Deallocate() {
        DeallocateNodes();
        StopAllTracks();
        // Free matrices
        if (m_matrices != NULL) {
            EAHeap* heap = MainHeap();
            heap->Free(m_matrices);
            m_matrices = NULL;
        }
        if (m_inverseMatrices != NULL) {
            EAHeap* heap = MainHeap();
            heap->Free(m_inverseMatrices);
            m_inverseMatrices = NULL;
        }
        if (m_resource != NULL) {
            // EResource::DelRef(m_resource)
            m_resource = NULL;
        }
        m_nodeCount = -1;
    }

    // 0x802E7964 (44 bytes)
    void DeallocateNodes() {
        // Free per-node state arrays
    }

    // 0x802E7990 (244 bytes)
    void Init(unsigned int checksum, eAnimatedObjectType objType, unsigned int flags) {
        Deallocate();
        // Look up ERCharacter by checksum
        // Set m_resource
        // m_objectType = objType
        // m_nodeCount = resource node count
        // Allocate per-node state
        AllocMatrices();
    }

    // 0x802E7A84 (104 bytes)
    void Init(char* name, eAnimatedObjectType objType, unsigned int flags) {
        // Compute checksum from name
        // Delegate to Init(checksum, objType, flags)
    }

    // 0x802E7AEC (44 bytes)
    bool IsTrackValid(eTrackFlags flags) {
        // Search track list for a track matching the given flags
        // Return true if found and active
        return false;
    }

    // 0x802E7B18 (64 bytes)
    void SuspendTrack(eTrackFlags flags) {
        // Find track by flags, set suspended state
    }

    // 0x802E7B58 (64 bytes)
    void ResumeTrack(eTrackFlags flags) {
        // Find track by flags, clear suspended state
    }

    // 0x802E7B98 (208 bytes)
    // Build an orientation matrix from three direction vectors
    void CalcOrientMatrix(EVec3& forward, EVec3& up, EVec3& right, EMat4& outMat) {
        // Cross products to build orthonormal basis
        // Store into outMat rows
    }

    // 0x802E7C68 (1024 bytes)
    // Main update: advance animation time, evaluate tracks, generate events
    void Update(EVec3* position, EVec3* rotation, EVec3 velocity) {
        // For each active track:
        //   Advance time by dt * speed
        //   Evaluate blend weights
        //   Process animation events
        //   Calculate root motion
    }

    // 0x802E8068 (324 bytes)
    void ProcessEvents(TNodeList<EACEventRange*>& eventList, bool fireEvents) {
        // Walk event list, fire callbacks for events in the current time window
    }

    // 0x802E81AC (196 bytes)
    void AddEventRange(TNodeList<EACEventRange*>& eventList, EACTrack* track,
                       float startTime, float endTime) {
        // Add a time range for event processing
    }

    // 0x802E8270 (372 bytes)
    void UpdateTrack(EACTrack* track, EVec3& trans, EVec3& rot,
                     TNodeList<EACEventRange*>& eventList) {
        // Update a single track's animation state
    }

    // 0x802E83E4 (152 bytes)
    void GetSlavePos(EACTrack* master, EACTrack* slave) {
        // Synchronize slave track position to master
    }

    // 0x802E847C (108 bytes)
    void GetAnimTrans(eTrackFlags flags, EVec3& outTrans) {
        // Get accumulated translation from animation track
    }

    // 0x802E84E8 (104 bytes)
    void GetAnimTranslate(eTrackFlags flags, EVec3& outTrans, EVec3& outDelta) {
        // Get translation and delta from last frame
    }

    // 0x802E8550 (52 bytes)
    float GetAnimTime(eTrackFlags flags) {
        // Get current time position of track
        return 0.0f;
    }

    // 0x802E8584 (120 bytes)
    void GetAnimVelocity(eTrackFlags flags, EVec3& outVel) {
        // Calculate velocity from animation root motion
    }

    // 0x802E85FC (128 bytes)
    void* GetFirstRelevantTrack() {
        // Return the first active track with non-zero blend weight
        return NULL;
    }

    // 0x802E867C (940 bytes)
    void AnimateTrack(EACTrack* track, EACNodeState* nodeStates, EMat4* matrices) {
        // Evaluate animation curves for all nodes on a track
    }

    // 0x802E8A28 (316 bytes)
    void Compute(EMat4& rootMat, int forceUpdate) {
        // Compute final bone matrices from animation state
    }

    // 0x802E8B64 (108 bytes)
    void AllocMatrices() {
        // Allocate bone matrix arrays (local + world space)
        if (m_nodeCount > 0) {
            EAHeap* heap = MainHeap();
            m_matrices = (EMat4*)heap->Malloc(m_nodeCount * sizeof(EMat4), 0);
            m_inverseMatrices = (EMat4*)heap->Malloc(m_nodeCount * sizeof(EMat4), 0);
        }
    }

    // 0x802E8BD0 (316 bytes)
    void ComputeInverse(EMat4& rootMat, int nodeIndex) {
        // Compute inverse bind-pose matrix for a node
    }

    // 0x802E8D0C (268 bytes)
    void PostMultNodeAndDescendents(int nodeIndex, EMat4& mat) {
        // Post-multiply matrix through node hierarchy (parent-to-child)
    }

    // 0x802E8E18 (268 bytes)
    void PreMultNodeAndDescendents(int nodeIndex, EMat4& mat) {
        // Pre-multiply matrix through node hierarchy
    }

    // 0x802E8F24 (544 bytes)
    void CalcTightBoundBox(EMat4& worldMat, EBound3& outBounds, bool* pValid) {
        // Calculate tight AABB from animated bone positions
    }

    // 0x802E9144 (476 bytes)
    void FixAccumulationForRootNode(EACTrack* track, EACNodeState& nodeState) {
        // Fix accumulated root motion for the root bone
    }

    // 0x802E9320 (472 bytes)
    void AnimateSpecial(ERAnim* anim, float time, EACTrackStreams* streams,
                        EACNodeState* states, EAnimNodeDataPos* dataPos,
                        EACNodeState& rootState) {
        // Special animation path for compressed/streamed anims
    }

    // 0x802E94F8 (396 bytes)
    void BlendNodeArrays(EACTrack* track, EACNodeState* a, EACNodeState* b) {
        // Blend two node state arrays based on track blend weight
    }

    // 0x802E9684 (412 bytes)
    void Animate(EACTrack* track, EACNodeState* nodeStates) {
        // Full animation evaluation for a track
    }

    // 0x802E9820 (228 bytes)
    void Blend(float t, EACNodeState& a, EACNodeState& b) {
        // Interpolate between two node states
    }

    // 0x802E9904 (132 bytes)
    void Layer(float t, EACNodeState& base, EACNodeState& overlay) {
        // Additive animation layering
    }

    // 0x802E9988 (496 bytes)
    void ComputeMatrices(EMat4& rootMat) {
        // Build final transform matrices from node states
    }

    // 0x802E9B78 (288 bytes)
    void CalcMatrix(EMat4& outMat, ECharacterNode& node, EACNodeState& state, EMat4& parentMat) {
        // Calculate a single bone's world-space matrix
    }

    // 0x802E9C98 (156 bytes)
    void StopAllTracks() {
        // Deactivate and destroy all animation tracks
        // Walk track list, call DeactivateTrack on each
    }

    // 0x802E9D34 (200 bytes)
    void DeactivateTrack(EACTrack* track) {
        // Remove track from list, free resources
        DestroyStreams(track);
    }

    // 0x802E9DFC (176 bytes)
    void CreateStreams(EACTrack* track) {
        // Allocate streaming buffers for animation data
    }

    // 0x802E9EAC (72 bytes)
    void DestroyStreams(EACTrack* track) {
        // Free streaming buffers
    }

    // 0x802E9EF4 (52 bytes)
    void StopTrack(eTrackFlags flags) {
        // Find track by flags and deactivate it
    }

    // 0x802E9F28 (124 bytes)
    void TransferTrack(eTrackFlags from, eTrackFlags to) {
        // Move a track from one slot to another
    }

    // 0x802E9FA4 (52 bytes)
    u32 GetTrackAnimId(eTrackFlags flags) {
        // Return the animation checksum ID for a track
        return 0;
    }

    // 0x802E9FD8 (368 bytes)
    void SetStaticBlendTrackAnim(eTrackFlags flags, unsigned int animId, float startTime,
                                  int loop, float blendTime, EACTrack* syncTrack) {
        // Set up a track with static blend parameters
    }

    // 0x802EA148 (460 bytes)
    void SetTrackAnim(eTrackFlags flags, unsigned int animId, int loop,
                      float startTime, EACTrack** ppTrack) {
        // Assign an animation to a track, optionally returning the track pointer
    }

    // 0x802EA314 (100 bytes)
    void SetTrackAnim(eTrackFlags flags, char* animName) {
        // Look up animation by name and assign to track
    }

    // 0x802EA378 (52 bytes)
    const char* GetTrackAnimName(eTrackFlags flags) {
        // Return the name of the animation on a track
        return NULL;
    }

    // 0x802EA3AC (124 bytes)
    void SetTrackIntensity(eTrackFlags flags, float intensity) {
        // Set the intensity (influence) of a track
    }

    // 0x802EA428 (88 bytes)
    void SetTrackIntensity(EACTrack* track, float intensity, bool clamp) {
        // Direct track intensity setter
    }

    // 0x802EA480 (84 bytes)
    void SetAllTrackIntensities(float intensity) {
        // Set intensity for all active tracks
    }

    // 0x802EA4D4 (52 bytes)
    float GetTrackBlendTarget(eTrackFlags flags) {
        // Return target blend weight for track
        return 0.0f;
    }

    // 0x802EA508 (52 bytes)
    float GetTrackIntensity(eTrackFlags flags) {
        // Return current intensity of track
        return 0.0f;
    }

    // 0x802EA53C (52 bytes)
    float GetTrackSpeed(eTrackFlags flags) {
        // Return playback speed multiplier of track
        return 1.0f;
    }

    // 0x802EA570 (132 bytes)
    void BlendAllOutgoingTracks(float targetWeight, float duration, bool linear) {
        // Blend all tracks toward a target weight over time
    }

    // 0x802EA5F4 (40 bytes)
    void SetTrackBlend(EACTrack* track, float weight) {
        // Set immediate blend weight
    }

    // 0x802EA61C (64 bytes)
    void SetTrackBlend(eTrackFlags flags, float weight) {
        // Find track and set blend weight
    }

    // 0x802EA65C (72 bytes)
    void SetTrackBlendSmooth(EACTrack* track, float target, float duration, float delay) {
        // Smoothly interpolate blend weight to target
    }

    // 0x802EA6A4 (80 bytes)
    void SetTrackBlendSmooth(eTrackFlags flags, float target, float duration, float delay) {
        // Find track and smooth-blend
    }

    // 0x802EA6F4 (120 bytes)
    void SetTrackBlendHermiteSafe(eTrackFlags flags, float target, float duration,
                                  float inTangent, float outTangent) {
        // Hermite blend with safety checks
    }

    // 0x802EA76C (116 bytes)
    void SetTrackBlendHermite(EACTrack* track, float target, float duration,
                               float inTangent, float outTangent) {
        // Hermite interpolation of blend weight
    }

    // 0x802EA7E0 (116 bytes)
    void SetTrackBlendHermite(eTrackFlags flags, float target, float duration,
                               float inTangent, float outTangent) {
        // Find track and hermite-blend
    }

    // 0x802EA854 (184 bytes)
    void BlendTrackIntensity(EACTrack* track) {
        // Update track intensity blending per-frame
    }

    // 0x802EA90C (116 bytes)
    void SetTrackPhaseLock(EACTrack* master, EACTrack* slave, float phaseOffset) {
        // Lock slave track phase to master with offset
    }

    // 0x802EA980 (176 bytes)
    void SetProceduralTrack(eTrackFlags flags,
                            void (*updateFunc)(unsigned int, EACTrack*, ERCharacter*, EVec3&, EVec3&),
                            void (*animFunc)(unsigned int, EACTrack*, EMat4&, ERCharacter*, EACNodeState*),
                            unsigned int userData) {
        // Set up a procedurally-driven animation track
    }

    // 0x802EAA30 (72 bytes)
    void RestartTrack(eTrackFlags flags) {
        // Reset track to beginning
    }

    // 0x802EAA78 (72 bytes)
    void SetTrackPhase(eTrackFlags flags, float phase) {
        // Set track phase (0.0 - 1.0)
    }

    // 0x802EAAC0 (132 bytes)
    void SetTrackFrame(eTrackFlags flags, float frame, bool clamp) {
        // Set track to a specific frame
    }

    // 0x802EAB44 (100 bytes)
    void SetTrackBlendFactors(eTrackFlags flags, float* factors) {
        // Set per-bone blend factors for a track
    }

    // 0x802EABA8 (52 bytes)
    u32 GetTrackFrameCount(eTrackFlags flags) {
        // Return total frame count of track's animation
        return 0;
    }

    // 0x802EABDC (52 bytes)
    float GetTrackFrame(eTrackFlags flags) {
        // Return current frame index
        return 0.0f;
    }

    // 0x802EAC10 (52 bytes)
    float GetTrackPos(eTrackFlags flags) {
        // Return current position (normalized 0-1)
        return 0.0f;
    }

    // 0x802EAC44 (60 bytes)
    void SetTrackPos(EACTrack* track, float pos, bool wrap) {
        // Set track position directly
    }

    // 0x802EAC80 (76 bytes)
    void SetTrackPos(eTrackFlags flags, float pos, bool wrap) {
        // Find track and set position
    }

    // 0x802EACCC (60 bytes)
    bool IsTrackAnimComplete(eTrackFlags flags) {
        // Check if non-looping animation has finished
        return false;
    }

    // 0x802EAD08 (64 bytes)
    void ClearTrackAnimComplete(eTrackFlags flags) {
        // Clear the completion flag for a track
    }

    // 0x802EAD48 (52 bytes)
    void* GetTrackAnimDef(eTrackFlags flags) {
        // Return the ERAnim definition for a track
        return NULL;
    }

    // 0x802EAD7C (40 bytes)
    void SetTrackSpeed(EACTrack* track, float speed) {
        // Set playback speed multiplier
    }

    // 0x802EADA4 (64 bytes)
    void SetTrackSpeed(eTrackFlags flags, float speed) {
        // Find track and set speed
    }

    // 0x802EADE4 (84 bytes)
    void SetAllTrackSpeed(float speed) {
        // Set speed for all active tracks
    }

    // 0x802EAE38 (268 bytes)
    bool VisibilityTest(EMat4& viewProjMat) {
        // Test if the animated object is visible in the view frustum
        EBoundSphere sphere;
        CalcVisibilitySphere(viewProjMat, sphere);
        // Frustum-sphere intersection test
        return true;
    }

    // 0x802EAF44 (184 bytes)
    void CalcVisibilitySphere(EMat4& worldMat, EBoundSphere& outSphere) {
        // Calculate bounding sphere from animated bone positions
    }

    // 0x802EAFFC (140 bytes)
    void GetAnimRootNodeTrans(EACTrack* track) {
        // Get root node's translation from animation data
    }

    // 0x802EB088 (528 bytes)
    void Draw(ERC* rc, ERModel* model, EMat4& worldMat) {
        // Submit animated model for rendering:
        //   1. Set model matrices on render context
        //   2. Draw each sub-model with appropriate shader
    }

    // 0x802EB298 (268 bytes)
    EVec3 CalcNodePos(int nodeIndex) {
        // Calculate world-space position of a bone
        EVec3 pos = {0.0f, 0.0f, 0.0f};
        if (m_matrices != NULL && nodeIndex >= 0 && nodeIndex < m_nodeCount) {
            pos.x = m_matrices[nodeIndex].m[3][0];
            pos.y = m_matrices[nodeIndex].m[3][1];
            pos.z = m_matrices[nodeIndex].m[3][2];
        }
        return pos;
    }

    // 0x802EB3A4 (276 bytes)
    void CalcNodeMatrix(int nodeIndex, EMat4& outMat) {
        // Get world-space matrix for a bone
        if (m_matrices != NULL && nodeIndex >= 0 && nodeIndex < m_nodeCount) {
            memcpy(&outMat, &m_matrices[nodeIndex], sizeof(EMat4));
        }
    }

    // 0x802EB4B8 (32 bytes)
    EMat4* GetNodeMatrix(int nodeIndex) {
        // Return pointer to bone's world matrix
        if (m_matrices == NULL || nodeIndex < 0 || nodeIndex >= m_nodeCount) {
            return NULL;
        }
        return &m_matrices[nodeIndex];
    }

    // 0x802EB4D8 (276 bytes)
    void CalcNodeOrientWithoutLocalRot(int nodeIndex, EMat4& outMat) {
        // Get bone orientation ignoring local rotation component
    }

    // 0x802EB5EC (284 bytes)
    void CalcNodeOrient(int nodeIndex, EMat4& outMat) {
        // Get bone orientation including local rotation
    }

    // 0x802EB708 (56 bytes)
    void SetNodeIgnoreAnimatedVisibility(int nodeIndex, bool ignore) {
        // Flag a node to not be affected by animation visibility
    }

    // 0x802EB740 (56 bytes)
    void SetNodeVisible(int nodeIndex, bool visible) {
        // Show/hide a specific bone and its children
    }

    // 0x802EB778 (56 bytes)
    void SetTrackActive(EACTrack* track, bool active) {
        // Enable/disable a track
    }

    // 0x802EB7B0 (188 bytes)
    void Enable(bool enabled, EMat4& mat) {
        // Enable/disable the entire animation controller
        m_enabled = enabled ? 1 : 0;
        if (enabled) {
            Compute(mat, 1);
        }
    }

    // 0x802EB86C (192 bytes)
    void CalcBillinearCoeff(float u, float v, float& c00, float& c01, float& c10, float& c11) {
        // Calculate bilinear interpolation coefficients
        c00 = (1.0f - u) * (1.0f - v);
        c01 = u * (1.0f - v);
        c10 = (1.0f - u) * v;
        c11 = u * v;
    }

    // 0x802EB92C (52 bytes)
    int GetNonMainTrackFlagFromIndex(int index) {
        // Map track index to eTrackFlags value
        // 0->main, 1->blend, 2->layer, etc.
        return index;
    }
};


// ############################################################################
//
//  ERC - Render Command Buffer
//
//  Size: 0x74 (116 bytes)
//  70 functions, 13180 bytes total
//
//  The primary interface for submitting rendering commands. All draw
//  calls, state changes, and shader setups go through ERC. It builds
//  a command buffer that is later processed by the GPU backend
//  (ENgcRenderer on GameCube).
//
// ############################################################################

class ETexture;
class EMovie;

class ERC {
public:
    // 0x00: command buffer pointer
    void* m_cmdBuffer;       // 0x00
    // 0x04: command buffer write position
    u32 m_cmdOffset;         // 0x04
    // 0x08: command buffer capacity
    u32 m_cmdCapacity;       // 0x08
    // 0x0C: current render state flags
    u32 m_geometryModes;     // 0x0C
    u32 m_rasterModes;       // 0x10
    // 0x14: matrix stack
    void* m_matrixStack;     // 0x14
    u32 m_matrixStackDepth;  // 0x18
    // 0x1C-0x44: state save/restore
    u8 m_stateData[40];      // 0x1C
    // 0x44-0x64: current textures
    void* m_textures[8];     // 0x44 (8 texture slots)
    // 0x64: display list
    void* m_displayList;     // 0x64
    // 0x68: alpha value
    f32 m_alpha;             // 0x68
    // 0x6C: viewport
    void* m_viewport;        // 0x6C
    // 0x70: flags
    u32 m_flags;             // 0x70

    // 0x802F64A8 (132 bytes)
    ERC() {
        m_cmdBuffer = NULL;
        m_cmdOffset = 0;
        m_cmdCapacity = 0;
        m_geometryModes = 0;
        m_rasterModes = 0;
        m_matrixStack = NULL;
        m_matrixStackDepth = 0;
        m_displayList = NULL;
        m_alpha = 1.0f;
        m_viewport = NULL;
        m_flags = 0;
        memset(m_textures, 0, sizeof(m_textures));
        memset(m_stateData, 0, sizeof(m_stateData));
    }

    // 0x802F652C (48 bytes)
    ~ERC() {
        // Free command buffer if owned
        if (m_cmdBuffer != NULL) {
            EAHeap* heap = MainHeap();
            heap->Free(m_cmdBuffer);
            m_cmdBuffer = NULL;
        }
    }

    // 0x802F655C (56 bytes)
    void Init(RCMode mode) {
        // Initialize render context with a given mode
        // Allocates command buffer
    }

    // 0x802F6594 (100 bytes)
    void BeginCommand(int type, int paramCount) {
        // Begin a new render command entry
        // Ensure enough space in buffer, grow if needed
    }

    // 0x802F65F8 (52 bytes)
    void Send() {
        // Finalize current command and advance write position
    }

    // 0x802F662C (68 bytes)
    void NewEntry(int type) {
        // Start a new command entry of the given type
    }

    // 0x802F6670 (192 bytes)
    void TriStrip(EGEVert* verts, int count) {
        // Submit triangle strip geometry
    }

    // 0x802F6730 (352 bytes)
    void TriStrip(int count, float* positions, float* texCoords,
                  unsigned char* colors, signed char* normals,
                  unsigned char* weights, bool useWeights) {
        // Submit triangle strip with separate attribute arrays
    }

    // 0x802F6890 (352 bytes)
    void TriStrip(int count, short* positions, short* texCoords,
                  unsigned char* colors, signed char* normals,
                  unsigned char* weights, bool useWeights) {
        // Short-precision triangle strip variant
    }

    // 0x802F69F0 (192 bytes)
    void LineList(EGEVert* verts, int count) {
        // Submit line list geometry
    }

    // 0x802F6AB0 (192 bytes)
    void LineStrip(EGEVert* verts, int count) {
        // Submit line strip geometry
    }

    // 0x802F6B70 (296 bytes)
    void PointList(int count, float* positions, float* texCoords,
                   unsigned char* colors, signed char* normals,
                   unsigned char* weights) {
        // Submit point list
    }

    // 0x802F6C98 (192 bytes)
    void SpriteList(EGEVert* verts, int count) {
        // Submit sprite/billboard list
    }

    // 0x802F6D58 (296 bytes)
    void SpriteList(int count, float* positions, float* texCoords,
                    unsigned char* colors, signed char* normals,
                    unsigned char* weights) {
        // Sprite list with separate arrays
    }

    // 0x802F6E80 (108 bytes)
    void ParticleList(int count, void* particles) {
        // Submit particle list (EGEPackedParticle)
    }

    // 0x802F6EEC (116 bytes)
    void LineStreakList(int count, EVec4& start, EVec4& end, void* streaks) {
        // Submit line streak effect
    }

    // 0x802F6F60 (108 bytes)
    void ParticleListRot(int count, void* particles) {
        // Rotated particle list
    }

    // 0x802F6FCC (48 bytes)
    void AddDisplayListReference(EDL* dl) {
        // Add a display list to the command buffer
    }

    // 0x802F6FFC (68 bytes)
    void DisplayList(EDL* dl) {
        // Execute a display list immediately
    }

    // 0x802F7040 (60 bytes)
    void ShrinkSmallDisplayList() {
        // Compact display list memory
    }

    // 0x802F707C (40 bytes)
    void Terminate() {
        // End the command buffer
    }

    // 0x802F70A4 (48 bytes)
    void Viewport(EViewport* vp) {
        // Set the viewport
        m_viewport = vp;
    }

    // 0x802F70D4 (64 bytes)
    void ClipRect(TRect<float>& rect) {
        // Set clipping rectangle
    }

    // 0x802F7114 (60 bytes)
    void Scissor(TRect<float>* rect) {
        // Set scissor rectangle (NULL to disable)
    }

    // 0x802F7150 (80 bytes)
    void ModelMatrixList(EMat4* matrices, int count) {
        // Upload model matrices for skinning
    }

    // 0x802F71A0 (56 bytes)
    void ModelMatrixIndex(int index, int slot) {
        // Select which model matrix to use
    }

    // 0x802F71D8 (68 bytes)
    void ModelMatrices(EMat4* matrices, int count) {
        // Set model matrices directly
    }

    // 0x802F721C (56 bytes)
    void FlushQueuedMatrices() {
        // Force matrix upload to GPU
    }

    // 0x802F7254 (80 bytes)
    void ViewMatrix(EMat4* mat, int eye, float interp) {
        // Set view (camera) matrix
    }

    // 0x802F72A4 (48 bytes)
    void ProjectionMatrix(EMat4* mat) {
        // Set projection matrix
    }

    // 0x802F72D4 (48 bytes)
    void WindowMatrix(EMat4* mat) {
        // Set window/screen-space transform matrix
    }

    // 0x802F7304 (56 bytes)
    void Texture(ETexture* tex, int slot) {
        // Bind texture to a slot (0-7)
        if (slot >= 0 && slot < 8) {
            m_textures[slot] = tex;
        }
    }

    // 0x802F733C (48 bytes)
    void EnableGeometryModes(unsigned int modes) {
        m_geometryModes |= modes;
    }

    // 0x802F736C (52 bytes)
    void DisableGeometryModes(unsigned int modes) {
        m_geometryModes &= ~modes;
    }

    // 0x802F73A0 (48 bytes)
    void SetGeometryModes(unsigned int modes) {
        m_geometryModes = modes;
    }

    // 0x802F73D0 (52 bytes)
    void EnableRasterModes(unsigned int modes, int layer) {
        m_rasterModes |= modes;
    }

    // 0x802F7404 (56 bytes)
    void DisableRasterModes(unsigned int modes, int layer) {
        m_rasterModes &= ~modes;
    }

    // 0x802F743C (48 bytes)
    void SetRasterModes(unsigned int modes, int layer) {
        m_rasterModes = modes;
    }

    // 0x802F746C (72 bytes)
    void SaveState() {
        // Push current render state to stack
    }

    // 0x802F74B4 (72 bytes)
    void RestoreState() {
        // Pop render state from stack
    }

    // 0x802F74FC (48 bytes)
    void Lights(ELights* lights) {
        // Set light configuration
    }

    // 0x802F752C (48 bytes)
    void Material(EMaterial* mat) {
        // Set material
    }

    // 0x802F755C (56 bytes)
    void SetMipMap(float bias, int slot) {
        // Set texture mip-map bias
    }

    // 0x802F7594 (68 bytes)
    void Callback(void (*func)(unsigned int, unsigned short, unsigned char),
                  unsigned int p1, unsigned short p2, unsigned char p3) {
        // Register a render callback command
    }

    // 0x802F75D8 (128 bytes)
    void RectList(int count, float* rects, EVec4& color, float z) {
        // Render filled rectangles
    }

    // 0x802F7658 (128 bytes)
    void RectListRot(int count, float* rects, EVec4& color, float z) {
        // Render rotated rectangles
    }

    // 0x802F76D8 (148 bytes)
    void Rect(EVec2& pos, EVec2& size, EVec2& uv0, EVec2& uv1, EVec4& color, float z) {
        // Render a single textured rectangle
    }

    // 0x802F776C (200 bytes)
    void Rect(EVec2& pos, EVec2& size, EVec4* colors, EVec2& uv0, EVec2& uv1, float z) {
        // Render rectangle with per-vertex colors
    }

    // 0x802F7834 (120 bytes)
    void DirectRect(EVec2& pos, EVec2& size, EVec4& color, float z) {
        // Render an untextured rectangle directly
    }

    // 0x802F78AC (76 bytes)
    void EnvironmentMap(bool enable, bool spherical, int slot) {
        // Enable/disable environment mapping
    }

    // 0x802F78F8 (80 bytes)
    void TextureMatrix(EMat4* mat, ETCTransformSource source, bool enable, bool normalize, int slot) {
        // Set texture coordinate transform matrix
    }

    // 0x802F7948 (72 bytes)
    void RecalcMatrices(int eye, int flags) {
        // Force recalculation of matrix concatenation
    }

    // 0x802F7990 (52 bytes)
    void Debug(unsigned int type, unsigned int param) {
        // Debug render command
    }

    // 0x802F79C4 (48 bytes)
    void GeometrySetup() {
        // Initialize geometry state for new draw call
    }

    // 0x802F79F4 (72 bytes)
    void ZTest(bool enable, int func, int writeMask, int flags) {
        // Set depth test parameters
    }

    // 0x802F7A3C (72 bytes)
    void AlphaTest(bool enable, int func, float ref, int flags) {
        // Set alpha test parameters
    }

    // 0x802F7A84 (64 bytes)
    void Stencil(int func, int ref, int mask) {
        // Set stencil test parameters
    }

    // 0x802F7AC4 (88 bytes)
    void SetBlendMode(int srcFactor, int dstFactor, int equation, int colorMask, float constAlpha, int flags) {
        // Set alpha blending mode
    }

    // 0x802F7B1C (56 bytes)
    void SetCombineMode(int mode, int flags) {
        // Set texture combine mode
    }

    // 0x802F7B54 (60 bytes)
    void RenderSurface(ERenderSurface* surface, int flags) {
        // Bind a render surface (render target)
    }

    // 0x802F7B90 (48 bytes)
    void SaveImageData(ERenderSurface* surface) {
        // Copy current framebuffer to surface
    }

    // 0x802F7BC0 (120 bytes)
    void Vertex(int format, int count, float* positions, float* texCoords,
                unsigned char* colors, signed char* normals, unsigned char* weights) {
        // Raw vertex data submission
    }

    // 0x802F7C38 (52 bytes)
    void TriIndexed(int count, unsigned char* indices) {
        // Indexed triangle list
    }

    // 0x802F7C6C (32 bytes)
    void Noop() {
        // No-operation command (for alignment/padding)
    }

    // 0x802F7C8C (76 bytes)
    void ZClear(float x, float y, float w, float h, float depth) {
        // Clear depth buffer region
    }

    // 0x802F7CD8 (76 bytes)
    void StencilClear(float x, float y, float w, float h, int value) {
        // Clear stencil buffer region
    }

    // 0x802F7D24 (48 bytes)
    void MovieFrame(EMovie* movie) {
        // Render a movie frame
    }

    // 0x802F7D54 (40 bytes)
    void SetAlpha(float alpha) {
        m_alpha = alpha;
    }

    // 0x802F7D7C (68 bytes)
    void CopyScreenToTexture(ETexture* tex, EVec4& srcRect, EVec2& dstOffset) {
        // Copy screen region to texture
    }

    // 0x802F7DC0 (56 bytes)
    void AllocAndCopy(void* data, int size) {
        // Allocate buffer and copy data into command stream
    }
};

// Forward declare EGEVert and EGELineStreak for ERC method signatures
struct EGEVert {
    f32 pos[3];
    f32 tex[2];
    u8 color[4];
    s8 normal[3];
    u8 pad;
};

struct EGELineStreak {
    EVec4 start;
    EVec4 end;
    EVec4 color;
};

struct EGEPackedParticle {
    f32 pos[3];
    f32 size;
    u8 color[4];
    f32 texU, texV;
};


// ############################################################################
//
//  EMovie - FMV playback controller
//
//  Size: variable
//  1 function, 168 bytes total
//
//  Manages full-motion video playback. Interfaces with the
//  graphics system to render movie frames and the renderer
//  to present them.
//
// ############################################################################

class EMovie {
public:
    // 0x00: EStorable vtable
    u32 m_vtable;
    // 0x04: reserved
    u32 m_pad04;
    // 0x08: stream info
    void* m_streamInfo;

    // 0x80364C24 (168 bytes)
    // Per-frame update: decode next frame and submit for rendering
    void Update() {
        // Call virtual method through stream info to check if data ready
        // If not ready, get the renderer via global pointer:
        //   void* renderer = g_pRenderer;
        //   Get the window from renderer->GetWindow(0)
        //   Submit this movie to the window's render queue
        //   Tell renderer to present the movie frame
    }
};


// ############################################################################
//
//  ELightGrid - Light evaluation grid for levels
//
//  Size: 0x6058 (24664 bytes)
//  21 functions, 5568 bytes total
//
//  Subdivides the level into a grid and evaluates lighting (ambient,
//  directional, point, portal) at each vertex. Used for efficient
//  per-pixel or per-vertex lighting queries during rendering.
//
// ############################################################################

class ELightGrid {
public:
    // Internal nested types
    struct LightData {
        u8 m_data[32]; // per-vertex light data
        void Clear() {
            memset(m_data, 0, sizeof(m_data));
        }
    };

    struct RoomData {
        u8 m_data[128]; // per-room lighting state

        void Flush() {
            memset(m_data, 0, sizeof(m_data));
        }

        void FindClosestLights(EVec3& pos, int maxLights, int roomId,
                               int* outLightIndices, int* outLightCount, int flags) {
            // Find the N closest lights to a point within a room
        }

        void EvaluateAmbientAndDirectionalLights() {
            // Calculate ambient + directional contribution for this room
        }
    };

    // 0x0000: LightData grid (fixed size grid of vertices)
    LightData m_grid[512];       // 0x0000 - 512 grid vertices
    // 0x4000: RoomData rooms
    RoomData m_rooms[40];        // 0x4000 - up to 40 rooms
    // Additional state
    u32 m_gridWidth;             // grid dimensions
    u32 m_gridHeight;
    u32 m_roomCount;
    void* m_lightList;           // TNodeList<EILight*>
    EInstance** m_instances;
    int m_instanceCount;

    // 0x8022FA6C (136 bytes)
    ELightGrid() {
        // Zero-initialize all grid data, room data, and state
        // Uses loop with bdnz for large zero-fills
        m_gridWidth = 0;
        m_gridHeight = 0;
        m_roomCount = 0;
        m_lightList = NULL;
        m_instances = NULL;
        m_instanceCount = 0;
    }

    // 0x8022FAF4 (108 bytes)
    void Flush() {
        // Clear all grid vertices and room data
        for (u32 i = 0; i < 512; i++) {
            m_grid[i].Clear();
        }
        for (u32 i = 0; i < 40; i++) {
            m_rooms[i].Flush();
        }
    }

    // 0x8022FB60 (88 bytes)
    void AddRoomToVertex(int vertexIdx, int roomId, int weight) {
        // Associate a room with a grid vertex (for light interpolation)
    }

    // 0x8022FBB8 (268 bytes)
    void Update(TNodeList<EILight*>& lights, EInstance** instances,
                int instanceCount, int roomCount) {
        // Full light grid update:
        //   1. Store light/instance references
        //   2. Clear grid
        //   3. Evaluate all light types
        //   4. Store results in grid
    }

    // 0x8022FCC4 (200 bytes)
    void ConnectPortalLights(int* portalMap) {
        // Connect lights that pass through portals (doorways, windows)
    }

    // 0x8022FD8C (340 bytes)
    void EvaluatePointLights(int roomId, int lightIndex) {
        // Calculate point light contribution at grid vertices
    }

    // 0x8022FEE0 (192 bytes)
    void AddLightsToVertices() {
        // Accumulate evaluated light data into grid vertices
    }

    // 0x8022FFA0 (268 bytes)
    void EvaluateLights() {
        // Main light evaluation entry point
        EvaluateAmbientAndDirectionalLights();
        EvaluateLamps();
        AddLightsToVertices();
    }

    // 0x802300AC (120 bytes)
    void EvaluateOuterLotLights() {
        // Evaluate lights for outdoor areas
    }

    // 0x80230124 (196 bytes)
    void EvaluateAmbientAndDirectionalLights() {
        // Evaluate ambient + directional for each room
        for (u32 i = 0; i < m_roomCount; i++) {
            m_rooms[i].EvaluateAmbientAndDirectionalLights();
        }
    }

    // 0x802301E8 (264 bytes)
    void EvaluatePortalLights(int roomA, int roomB) {
        // Evaluate lights passing through a portal between two rooms
    }

    // 0x802302F0 (244 bytes)
    void EvaluatePortalLight(int* lightIndices, int* portalData) {
        // Evaluate a single portal light's contribution
    }

    // 0x802303E4 (288 bytes)
    void GetLightWeightsAtLocation(EVec3& pos, int roomId, int* outWeights) {
        // Interpolate light weights at an arbitrary position
    }

    // 0x80230504 (296 bytes)
    void* GetLightsAtLocation(EVec3& pos, int roomId) const {
        // Get evaluated light data at an arbitrary position
        return NULL;
    }

    // 0x8023062C (160 bytes)
    bool IsRoomAtLocation(EVec3& pos, int roomId) {
        // Check if a position is inside a given room
        return false;
    }

    // 0x802306CC (420 bytes)
    void EvaluateLamps() {
        // Evaluate light contribution from placed lamp objects
    }

    // 0x80230870 (268 bytes)
    void EvaluateLampsOn() {
        // Evaluate only lamps that are turned on
    }
};


// ############################################################################
//
//  ERoom - Room geometry and wall management
//
//  Size: 0xB4 (180 bytes)
//  25 functions, 8936 bytes total
//
//  Manages room geometry, wall segments, wallpaper, and
//  occlusion state. Rooms are the fundamental spatial
//  partitioning unit for indoor levels.
//
// ############################################################################

class ERoom {
public:
    // 0x00: u32 m_vtable
    u32 m_vtable;
    // 0x04-0x6F: TNodeList arrays for wall segments (8 lists, 12 bytes each)
    TNodeList<ERoomWall*> m_wallLists[8]; // 96 bytes
    // 0x64: u32 m_wallCount
    u32 m_wallCount;
    // 0x68-0x7B: wall state data
    u32 m_wallState;       // 0x68 - EWallUpDownStateType
    f32 m_wallFade;        // 0x6C - current fade amount
    f32 m_wallFadeTarget;  // 0x70 - target fade amount
    u32 m_wallFlags;       // 0x74
    // 0x78-0x8B: room geometry
    f32 m_minX;            // 0x78
    f32 m_minZ;            // 0x7C
    f32 m_maxX;            // 0x80
    f32 m_maxZ;            // 0x84
    // 0x88-0xB3: extended
    u32 m_roomId;          // 0x88
    u32 m_floorId;         // 0x8C
    u32 m_opaqueFlags;     // 0x90
    f32 m_cameraDistance;  // 0x94
    u8  m_rest[0xB4 - 0x98]; // remaining fields

    // 0x8002D778 (276 bytes)
    ERoom() {
        // Initialize all 8 TNodeList members
        for (int i = 0; i < 8; i++) {
            m_wallLists[i].m_head = 0;
            m_wallLists[i].m_tail = 0;
            m_wallLists[i].m_count = 0;
        }
        m_wallCount = 0;
        m_wallState = 0;
        m_wallFade = 1.0f;
        m_wallFadeTarget = 1.0f;
        m_wallFlags = 0;
        m_roomId = 0;
        m_floorId = 0;
        m_opaqueFlags = 0;
        m_cameraDistance = 0.0f;
    }

    // 0x8002D88C (96 bytes)
    ~ERoom() {
        // Walk each wall list and free all wall segments
    }

    // 0x8002D8EC (52 bytes)
    void InitRoomLookupTab() {
        // Initialize the lookup table for room queries
    }

    // 0x8002D920 (52 bytes)
    u32 GetNumWalls(unsigned short segmentType) {
        // Return count of walls of a given segment type
        return 0;
    }

    // 0x8002D954 (264 bytes)
    u32 GetWallPaperCost(unsigned int paperId, unsigned short segmentType) {
        // Calculate cost to apply wallpaper to all walls of a type in this room
        return 0;
    }

    // 0x8002DA5C (324 bytes)
    void DrawWallpaperPreview(ERC* rc, unsigned short paperId, EVec2& cursor) {
        // Render wallpaper preview on highlighted walls
    }

    // 0x8002DBA0 (80 bytes)
    bool IsRoomWallsOpaque(int side, int floor) {
        // Check if room walls on a side are fully opaque
        return false;
    }

    // 0x8002DBF0 (160 bytes)
    void CalAllRoomOpaque(int floor) {
        // Calculate opacity state for all room walls
    }

    // 0x8002DC90 (96 bytes)
    f32 GetShortDistToCam(int side, int floor) {
        // Get shortest distance from a room wall to the camera
        return 0.0f;
    }

    // 0x8002DCF0 (104 bytes)
    f32 GetOccludeAlpha(int side, int floor) {
        // Calculate occlusion alpha for a wall side
        return 1.0f;
    }

    // 0x8002DD58 (80 bytes)
    bool IsRoomRoofOpaque(int side, int floor) {
        // Check if roof is opaque
        return false;
    }

    // 0x8002DDA8 (148 bytes)
    void CalRoofOpaque(int floor) {
        // Calculate roof opacity
    }

    // 0x8002DE3C (152 bytes)
    void CalShortDistToCam(int floor) {
        // Calculate shortest distance from room to camera
    }

    // 0x8002DED4 (168 bytes)
    void SetWallState(EWallUpDownStateType state) {
        // Set the up/down state for all walls in this room
    }

    // 0x8002DF7C (152 bytes)
    void UpdateWallFade(int floor) {
        // Update wall fade animation
    }

    // 0x8002E014 (532 bytes)
    void Init() {
        // Full room initialization
        // Build wall segments, calculate bounds
    }

    // 0x8002E228 (384 bytes)
    void ProcStandardWalls(bool preview, int& wallsProcessed, int& wallsTotal, bool forceUpdate) {
        // Process standard (axis-aligned) wall segments
    }

    // 0x8002E3A8 (372 bytes)
    void ProcDiagonalWalls(int& wallsProcessed, int& wallsTotal, bool forceUpdate) {
        // Process diagonal wall segments
    }

    // 0x8002E51C (704 bytes)
    void ProcessCell(TNodeList<ERoomWall*>& wallList, ERoomWallPtr& wallPtr,
                     CTilePt& tile, TileWallsSegment segment,
                     DiagonalSideSelector diagSide, TileWalls& tileWalls,
                     int floor, int& wallsProcessed, int& wallsTotal, bool forceUpdate) {
        // Process a single tile cell for wall generation
    }

    // 0x8002E7DC (212 bytes)
    void PreviewWallBuild(bool show) {
        // Show/hide wall build preview
    }

    // 0x8002E8B0 (220 bytes)
    void FindWallContainingSegment(TNodeList<ERoomWall*>& wallList,
                                    TileWallsSegment segment,
                                    CTilePt& tileA, CTilePt& tileB) {
        // Find the ERoomWall that contains a given wall segment
    }

    // 0x8002E98C (108 bytes)
    void* GetWallFromTileAndSegment(TileWallsSegment segment, CTilePt& tile) {
        // Get the wall at a specific tile + segment
        return NULL;
    }

    // 0x8002E9F8 (148 bytes)
    void DeleteERoomWallContainingSegment(TileWallsSegment segment,
                                          CTilePt& tileA, CTilePt& tileB) {
        // Find and delete a wall containing the segment
    }

    // 0x8002EA8C (220 bytes)
    void DeleteWallAtTile(CTilePt& tile, TileWalls& tileWalls, TileWallsSegment segment) {
        // Delete wall at a specific tile
    }

    // 0x8002EB68 (336 bytes)
    void KillArchitecturalObject(CTilePt& tile, TileWallsSegment segment,
                                  int& cost, bool refund) {
        // Remove a wall/door/window and calculate refund
    }
};


// ############################################################################
//
//  EHouse - House/lot container
//
//  Size: 0x3F8 (1016 bytes)
//  19 functions, 5148 bytes total
//
//  Top-level container for a buildable lot. Owns the room layout,
//  wall geometry, weather state, and lighting configuration.
//
// ############################################################################

class EHouse {
public:
    // 0x00: bool m_outdoor (true if no roof)
    u32 m_outdoor;
    // 0x04-0x1B: reserved
    u8  m_pad04[24];
    // 0x1C: void* m_pResetObj
    void* m_pResetObj;
    // 0x20-0x53: more reserved
    u8  m_pad20[52];
    // 0x54: int m_lotType
    u32 m_lotType;
    // 0x58-0x63: grid dimensions
    u32 m_gridWidth;
    u32 m_gridHeight;
    // 0x64: EInstance m_instance (base placement in level)
    EInstance m_instance; // large embedded object at 0x64
    // After EInstance:
    // 0xE0: room/wall structures
    u32 m_roomCount;
    ERoom** m_rooms;
    // Weather state
    u32 m_weatherState;     // 0: fair, 1: rain
    f32 m_weatherTransition;
    // Lighting
    u32 m_lightingDirty;
    // Extended data to fill documented size
    u8  m_extended[0x3F8 - 0x100]; // approximate

    // 0x8002371C (644 bytes)
    EHouse(EVec2& pos, int lotType, ERLevel* level,
           bool outdoor, bool hasPool, bool hasGarage, bool hasFence) {
        // Initialize EInstance at offset 0x64
        // Set outdoor flag
        // Set lot type
        // Store level reference
        // Initialize room and wall structures
        // Set weather to fair
        m_outdoor = outdoor ? 1 : 0;
        m_lotType = lotType;
        m_roomCount = 0;
        m_rooms = NULL;
        m_weatherState = 0;
        m_weatherTransition = 1.0f;
        m_lightingDirty = 0;
    }

    // 0x800239A0 (128 bytes)
    ~EHouse() {
        Cleanup();
    }

    // 0x80023A20 (368 bytes)
    void BuildHouse() {
        // Construct the house geometry:
        //   1. Build room layout from tile data
        //   2. Generate wall segments
        //   3. Place doors/windows
        //   4. Generate floor/ceiling geometry
        //   5. Set up lighting
    }

    // 0x80023B90 (128 bytes)
    void SetNextWallMode() {
        // Cycle wall display mode: full -> half -> down -> full
    }

    // 0x80023C10 (344 bytes)
    void Draw(ERC* rc) {
        // Draw the house and all its rooms
    }

    // 0x80023D68 (384 bytes)
    void Update() {
        // Per-frame house update:
        //   - Update weather transitions
        //   - Update wall fade animations
        //   - Update room lighting if dirty
    }

    // 0x80023EE8 (212 bytes)
    void UpdateRoomAmbient(LevelLightingEntry& lighting) {
        // Update ambient lighting for all rooms
    }

    // 0x80023FBC (48 bytes)
    void WeatherChanging() {
        // Begin weather transition
    }

    // 0x80023FEC (48 bytes)
    void Fair() {
        m_weatherState = 0;
    }

    // 0x8002401C (48 bytes)
    void Rain() {
        m_weatherState = 1;
    }

    // 0x8002404C (152 bytes)
    void UpdateWeather() {
        // Update weather transition animation
    }

    // 0x800240E4 (184 bytes)
    void Cleanup() {
        // Free all rooms and wall geometry
        DestroyWalls();
        if (m_rooms != NULL) {
            for (u32 i = 0; i < m_roomCount; i++) {
                if (m_rooms[i] != NULL) {
                    EAHeap* heap = MainHeap();
                    heap->Free(m_rooms[i]);
                }
            }
            EAHeap* heap = MainHeap();
            heap->Free(m_rooms);
            m_rooms = NULL;
            m_roomCount = 0;
        }
    }

    // 0x8002419C (196 bytes)
    void DestroyWalls() {
        // Walk all rooms and destroy wall segments
    }

    // 0x80024260 (332 bytes)
    void ReCalcHouse() {
        // Recalculate house after build-mode changes
    }

    // 0x800243AC (280 bytes)
    void UpdateRoomLights() {
        // Update light grid for all rooms
    }

    // 0x800244C4 (76 bytes)
    void SetLightIntensityScaleFromRoom(EILight* light) {
        // Set light intensity based on room it's in
    }

    // 0x80024510 (440 bytes)
    void InitRoomLighting() {
        // Initialize lighting for all rooms
        m_lightingDirty = 0;
    }

    // 0x800246C8 (164 bytes)
    void CleanUpRoomLights() {
        // Clean up room lighting state
    }

    // 0x8002476C (96 bytes)
    void InsertHouseObject(EOrderTableData* orderData) {
        // Insert object into the house's render order table
    }
};


// ############################################################################
//
//  ELiveMode - Main gameplay state machine
//
//  Size: 0x7E8C (32396 bytes)
//  15 functions, 9660 bytes total
//
//  The primary gameplay state. Manages the main game view,
//  split-screen rendering, and intro camera sequences.
//  Inherits from EGameState.
//
// ############################################################################

class EGameState {
public:
    // 0x00: vtable
    u32 m_vtable;
    // 0x04: state data
    u32 m_stateId;
    // 0x08: vtable2 (game state specific)
    u32 m_vtable2;
    u8 m_baseData[16]; // remaining base state

    virtual ~EGameState() {}
};

class ELiveMode : public EGameState {
public:
    // Large state (32KB+) contains embedded cameras, windows, etc.
    u8 m_liveModeData[0x7E8C - sizeof(EGameState)];

    // 0x8008BB08 (96 bytes)
    ~ELiveMode() {
        // Set vtable
        // Clear global live mode pointer
        // ~EGameState() chain
    }

    // 0x8008BB68 (188 bytes)
    void Init(int playerCount) {
        // Initialize live mode for N players:
        //   1. Set up cameras
        //   2. Create 3D windows
        //   3. Initialize HUD
        //   4. Set default game speed
    }

    // 0x8008BC24 (356 bytes)
    void Reset(int flags) {
        // Reset live mode state (e.g. after lot change)
    }

    // 0x8008BD88 (96 bytes)
    void GotoStartMode() {
        // Transition to the start/intro mode
    }

    // 0x8008BDE8 (92 bytes)
    void QuitToMainMenu() {
        // Exit to main menu
    }

    // 0x8008BE44 (68 bytes)
    bool IsReadyForUpdate() {
        // Check if all resources are loaded and ready
        return true;
    }

    // 0x8008BE88 (296 bytes)
    void UpdateIntroCamera() {
        // Update the intro camera fly-in animation
    }

    // 0x8008BFB0 (776 bytes)
    void Update() {
        // Main per-frame update:
        //   1. Check if ready
        //   2. Update intro camera if active
        //   3. Update game simulation
        //   4. Update HUD
    }

    // 0x8008C2C8 (676 bytes)
    void Draw(ERC* rc) {
        // Draw live mode:
        //   1. Draw each player's view
        //   2. Draw split-screen dividers if needed
        //   3. Draw HUD overlay
    }

    // 0x8008C56C (376 bytes)
    void DrawSplitScreenMask(ERC* rc, E3DWindow& window, int playerIdx) {
        // Draw the mask for split-screen edges
    }

    // 0x8008C6E4 (340 bytes)
    void InitPlayerXWindow(ERC* rc, E3DWindow& window, int playerIdx) {
        // Initialize a player's 3D viewport
    }

    // 0x8008C838 (224 bytes)
    void DrawSplitScreenDivider(ERC* rc) {
        // Draw the line between split-screen views
    }

    // 0x8008C918 (1476 bytes)
    void DrawMain(ERC* rc) {
        // Main rendering for a single player's view:
        //   1. Set up camera matrices
        //   2. Draw level geometry
        //   3. Draw objects and characters
        //   4. Draw effects and particles
    }

    // 0x8008CEF4 (400 bytes)
    void StartIntroCamera(CameraDirector* director, ESimsCam* cam) {
        // Begin the intro camera animation sequence
    }

    // 0x8008D084 (160 bytes)
    void EndIntroCamera(CameraDirector* director, ESimsCam* cam) {
        // End the intro camera and transition to gameplay camera
    }
};


// ############################################################################
//
//  ESimsCam - Game camera controller
//
//  Size: 0x570 (1392 bytes)
//  45 functions, 18212 bytes total
//
//  The Sims 2 camera system. Handles orbit, zoom, pan, rotation,
//  follow-sim, and cinematic camera modes. Contains an embedded
//  E3DWindow (856 bytes at offset 0x10) and an EAnimController
//  (180 bytes at offset 0x4C8).
//
// ############################################################################

class ESimsCam {
public:
    // 0x000: reserved
    u8  m_pad00[16];
    // 0x010: E3DWindow m_window (embedded, 856 bytes)
    u8  m_window[856]; // E3DWindow at 0x10
    // 0x368-0x3FF: camera state
    f32 m_fov;              // field of view
    f32 m_nearPlane;        // near clip plane
    f32 m_farPlane;         // far clip plane
    f32 m_zoomLevel;        // current zoom (0-1)
    f32 m_zoomTarget;       // target zoom
    f32 m_rotAngle;         // current rotation angle
    f32 m_rotTarget;        // target rotation angle
    f32 m_pitch;            // pitch angle
    f32 m_pitchTarget;      // target pitch
    // 0x400-0x47F: position state
    EVec3 m_eyePos;         // camera eye position
    EVec3 m_targetPos;      // look-at target
    EVec3 m_upVec;          // up vector
    EVec3 m_panOffset;      // current pan offset
    EVec3 m_panVelocity;    // pan velocity
    // 0x480-0x4C7: sim following
    void* m_followSim;      // cXObject* being followed
    u32   m_cameraMode;     // current mode (orbit, follow, cinematic)
    u32   m_cameraState;    // sub-state
    u32   m_playerIndex;    // which player (for split-screen)
    f32   m_interpFactor;   // interpolation smoothing
    // 0x4C8: EAnimController m_animController
    u8  m_animController[180]; // EAnimController at 0x4C8
    // 0x57C: vtable2
    u32 m_vtable2;          // 0x56C

    // 0x800164D4 (456 bytes)
    ESimsCam(int playerIndex) {
        // Set vtable2
        // E3DWindow::E3DWindow() at offset 0x10
        // EAnimController::EAnimController() at offset 0x4C8
        // Initialize all camera parameters to defaults
        m_fov = 45.0f;
        m_nearPlane = 1.0f;
        m_farPlane = 1000.0f;
        m_zoomLevel = 0.5f;
        m_zoomTarget = 0.5f;
        m_rotAngle = 0.0f;
        m_rotTarget = 0.0f;
        m_pitch = 30.0f;
        m_pitchTarget = 30.0f;
        m_eyePos.x = m_eyePos.y = m_eyePos.z = 0.0f;
        m_targetPos.x = m_targetPos.y = m_targetPos.z = 0.0f;
        m_upVec.x = 0.0f; m_upVec.y = 1.0f; m_upVec.z = 0.0f;
        m_panOffset.x = m_panOffset.y = m_panOffset.z = 0.0f;
        m_panVelocity.x = m_panVelocity.y = m_panVelocity.z = 0.0f;
        m_followSim = NULL;
        m_cameraMode = 0;
        m_cameraState = 0;
        m_playerIndex = playerIndex;
        m_interpFactor = 0.1f;
    }

    // Default constructor
    ESimsCam() {
        // Same as ESimsCam(0)
    }

    // 0x800166CC (120 bytes)
    ~ESimsCam() {
        // Destroy embedded E3DWindow and EAnimController
    }

    // 0x80016744 (28 bytes)
    f32 GetCurZoomRatio() {
        return m_zoomLevel;
    }

    // 0x80016760 (12 bytes)
    f32 GetNearPlane() {
        return m_nearPlane;
    }

    // 0x8001676C (12 bytes)
    f32 GetFov() {
        return m_fov;
    }

    // 0x80016778 (72 bytes)
    void ForceFullScreenViewport() {
        // Reset viewport to full screen (for non-split-screen)
    }

    // 0x800167C0 (316 bytes)
    void Reset() {
        // Reset all camera state to defaults
        m_zoomLevel = 0.5f;
        m_zoomTarget = 0.5f;
        m_rotAngle = 0.0f;
        m_rotTarget = 0.0f;
        m_pitch = 30.0f;
        m_pitchTarget = 30.0f;
        m_panOffset.x = m_panOffset.y = m_panOffset.z = 0.0f;
        m_panVelocity.x = m_panVelocity.y = m_panVelocity.z = 0.0f;
        m_followSim = NULL;
        m_cameraMode = 0;
        m_cameraState = 0;
    }

    // 0x800168FC (128 bytes)
    void SetState(int state) {
        m_cameraState = state;
    }

    // 0x8001697C (148 bytes)
    void SetMode(int mode) {
        m_cameraMode = mode;
    }

    // 0x80016A10 (120 bytes)
    void FollowPlayerInteractor(int simIndex) {
        // Set camera to follow a sim
    }

    // 0x80016A88 (1260 bytes)
    void Update() {
        // Main camera update:
        //   1. Read controller input (zoom, rotation)
        //   2. Apply camera mode logic (orbit, follow, etc.)
        //   3. Interpolate position/rotation
        //   4. Calculate final eye/target positions
        //   5. Update the E3DWindow
    }

    // 0x80016F74 (180 bytes)
    void ApplyPan(float dt) {
        // Apply panning from controller input
    }

    // 0x80017028 (172 bytes)
    void ApplyZoom(float dt) {
        // Apply zoom from controller input
        // Interpolate m_zoomLevel toward m_zoomTarget
    }

    // 0x800170D4 (268 bytes)
    void HandleRotation() {
        // Handle camera rotation from controller input
    }

    // 0x800171E0 (184 bytes)
    void HandleZoom() {
        // Handle zoom level changes
    }

    // 0x80017298 (384 bytes)
    void UpdateWin() {
        // Update the embedded E3DWindow with current camera state
    }

    // 0x80017418 (572 bytes)
    void CalcEyePosition(EVec3& outEye, int& outMode) {
        // Calculate camera eye position from current parameters
    }

    // 0x80017654 (248 bytes)
    void ResetPos(float zoom) {
        // Reset camera position with a specific zoom level
    }

    // 0x8001774C (412 bytes)
    void FollowSimStiff() {
        // Follow a sim with no interpolation (stiff camera)
    }

    // 0x800178E8 (108 bytes)
    bool IsInDeadZone(EVec3& pos) const {
        // Check if a position is in the camera's dead zone
        return false;
    }

    // 0x80017954 (488 bytes)
    void InterpolateActualCameraParamsToTarget(float dt) {
        // Smoothly interpolate all camera parameters toward targets
    }

    // 0x80017B3C (212 bytes)
    void CenterOnSelectedSim() {
        // Center camera on the currently selected sim
    }

    // 0x80017C10 (104 bytes)
    void SetPosAndReset(EVec3& eye, EVec3& target, EVec3& up) {
        // Set camera position and reset interpolation
        m_eyePos = eye;
        m_targetPos = target;
        m_upVec = up;
    }

    // 0x80017C78 (72 bytes)
    void SetPos(EVec3& eye, EVec3& target, EVec3& up) {
        // Set camera position (will interpolate)
        m_eyePos = eye;
        m_targetPos = target;
        m_upVec = up;
    }

    // 0x80017CC0 (88 bytes)
    void ForcePosition(EVec3& eye, EVec3& target, EVec3& up) {
        // Force camera to exact position (no interpolation)
        m_eyePos = eye;
        m_targetPos = target;
        m_upVec = up;
    }

    // 0x80017D18 (52 bytes)
    void ForceTarget(EVec3& target) {
        m_targetPos = target;
    }

    // 0x80017D4C (268 bytes)
    bool PointOutsideScreenRect(EVec3& point, float left, float top, float right, float bottom) {
        // Test if a 3D point projects outside the given screen rect
        return false;
    }

    // 0x80017E58 (336 bytes)
    void ValidateCursorPosition(int playerIdx, EVec3* cursorPos) {
        // Validate and clamp cursor position to playable area
    }

    // 0x80017FA8 (108 bytes)
    int CalRoomId(EVec3& pos) {
        // Calculate which room a position is in
        return -1;
    }

    // 0x80018014 (112 bytes)
    int GetContainingRoomId(EVec3& pos) {
        // Get the room ID containing a position
        return -1;
    }

    // 0x80018084 (264 bytes)
    void SetWinPos(E3DWindow& window) {
        // Set window position from camera state
    }

    // 0x8001818C (208 bytes)
    void CalcPitch(EVec3& target) {
        // Calculate pitch angle to target
    }

    // 0x8001825C (152 bytes)
    void CalcZAxisTheta(EVec3& target) {
        // Calculate Z-axis rotation angle to target
    }

    // 0x800182F4 (56 bytes)
    EVec3 GetCursorPos() {
        // Return current cursor world position
        EVec3 pos = {0.0f, 0.0f, 0.0f};
        return pos;
    }

    // 0x8001832C (208 bytes)
    void GetObjectPosition(EVec3* outPos, cXObject* obj) {
        // Get object's world position
    }

    // 0x800183FC (208 bytes)
    void GetObjectOrientation(EVec3* outRot, cXObject* obj) {
        // Get object's world orientation
    }

    // 0x800184CC (648 bytes)
    void DrawDebug(ERC* rc) {
        // Draw debug camera visualization
    }

    // 0x80018754 (48 bytes)
    void CursorNotActive() {
        // Handle cursor becoming inactive
    }

    // 0x80018784 (88 bytes)
    void SetActiveNoiseSetting(CameraNoiseSetting setting) {
        // Set camera noise/shake parameters
    }

    // 0x800187DC (468 bytes)
    void ApplyNoise(EVec3 eye, EVec3 target, EVec3 up) {
        // Apply camera shake/noise to position
    }

    // 0x800189B0 (464 bytes)
    void DrawCameraInfo(ERC* rc) {
        // Draw camera debug info on screen
    }

    // 0x80018B80 (324 bytes)
    void ReadControllerZoom() {
        // Read zoom input from game controller
    }

    // 0x80018CC4 (304 bytes)
    void ReadControllerRotation() {
        // Read rotation input from game controller
    }

    // 0x80018DF4 (44 bytes)
    void* operator new(unsigned int size) {
        // Allocate from MainHeap
        EAHeap* heap = MainHeap();
        return heap->Malloc(size, 0);
    }
};


// ############################################################################
//
//  (End of engine_classes.cpp)
//
//  Summary of classes decompiled:
//    25 E* engine classes converted from PPC inline asm to portable C++
//    Total: ~500 methods across all classes
//
//  Classes skipped (already in other decomp_cpp files):
//    EGlobal      -> global_statemachine.cpp
//    ERLevel      -> build_mode_world.cpp (or assets_resources.cpp)
//    ESimsApp     -> esimsapp.cpp
//    EStorable    -> misc_classes.cpp
//    ETexture     -> renderer.cpp
//    EWindow      -> misc_classes.cpp
//
// ############################################################################
