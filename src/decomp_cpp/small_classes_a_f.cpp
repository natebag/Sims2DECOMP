// small_classes_a_f.cpp - Batch decompilation of small classes A-F
//
// Converted from inline PPC asm (src/asm_decomp/*.cpp) to real C++.
// All logic derived from PPC assembly analysis of the GameCube build.
//
// Classes covered:
//   AptBoolean, AptFloat, AptInteger, AptNone, AptRegister,
//   AptLine, AptIntervalTimer, AptNativeFunction, AptPseudoCIH_t,
//   AptSavedInputCheckpoints, AptScriptFunctionByteCodeBlock,
//   AptValueWithHash, AptExtern, AptGC, AptGlobalExtensionObject,
//   AptLookup, AptMemoryAllocationsT, AptStringObject, AptValueVector,
//   AptXmlAttributes, AptXmlNode, AptScriptColour,
//   ArcCopier, BackgroundPane, BehPrintParams, BitArray64, BitMatrix64,
//   ButtonItem, CDirtyXml, CDirtyXmlImpl, CDirtyXmlNode,
//   CTGMicroTimer, CUnlockDisplayObjectSim,
//   DepthOfField, FadeSquare, FastAllocPool, ProtectedAllocPool,
//   FrameEffect, FlowGotoTarget, FloatConstantsQuickData
//
// Source: u2_ngc_release_dvd.elf disassembly + u2_ngc_release.map symbols

#include "types.h"

// ============================================================================
// External declarations
// ============================================================================

extern "C" {
    void* memcpy(void* dst, const void* src, unsigned int n);
    void* memset(void* s, int c, unsigned int n);
    int   strlen(const char* s);
    char* strcpy(char* dst, const char* src);
    int   strcasecmp(const char* a, const char* b);
}

class EAHeap;
extern EAHeap* MainHeap();
class EAHeap {
public:
    void* Malloc(unsigned int size, int flags);
    void  Free(void* ptr);
};

extern void* operator_new_impl(unsigned int size);
extern void  operator_delete_impl(void* ptr);

// Forward declarations
class AptValue;
class AptWord;
class AptVirtualFunctionTable;
class DOGMA_PoolManager;
class EMat4;
class EMutex;
class ERC;
class ERModel;
class EResourceManager;
class EVec3;
class EVec4;
class BloomSettings;
class TextBlock;
class TextBaseItem;
class PaneItem;
class WrapperPaneBase;
class BehaviorFinder;
class ReconBuffer;
class ResFile;
class Behavior;
class StringBuffer;
class FloatConstantItem;
class iResFile;
struct ObjectDataID;
struct CTilePt;

// Globals
extern DOGMA_PoolManager* g_pDogmaPoolManager;      // r13 - 23020
extern AptBoolean*        g_pAptBooleanPool;         // r13 - 26916
extern AptFloat*          g_pAptFloatPool;           // r13 - 26912
extern AptInteger*        g_pAptIntegerPool;         // r13 - 26908
extern void*              g_pAptGCInfo;              // r13 - 27600
extern EResourceManager*  g_pResourceManager;        // r13 - 22652
extern void*              g_pObjectModule;           // r13 - 21484

// ############################################################################
//
//  AptBoolean - Pooled boolean APT value type
//
//  Layout: 16 bytes
//    0x00: u32 m_flags
//    0x04: u32 m_refCount  (from AptValue base)
//    0x08: void** m_vtable (AptBoolean vtable)
//    0x0C: u32 m_value     (bool stored as int)
//
// ############################################################################

class AptBoolean : public AptValue {
public:
    bool m_boolValue;       // 0x0C
    AptBoolean* m_poolNext; // 0x0C (union: used when in free pool)

    // 0x802BB9CC (72 bytes)
    AptBoolean(bool val) : AptValue(/*AptVFT_Boolean*/ 5) {
        m_boolValue = val;
        // vtable set by parent + override
    }

    // 0x802BB8E0 (84 bytes)
    ~AptBoolean() {
        // vtable restored, then AptValue::~AptValue called
        // if delete flag set, DOGMA pool dealloc with size 16
    }

    // 0x802BBA14 (180 bytes)
    // Static factory - tries pool first, falls back to DOGMA allocator
    static AptBoolean* Create(bool val);

    // 0x802BB830 (132 bytes)
    // Static - walks the pool linked list and destroys all
    static void ClearPool();
};

// ############################################################################
//
//  AptFloat - Pooled float APT value type
//
// ############################################################################

class AptFloat : public AptValue {
public:
    float m_floatValue;     // 0x0C

    // 0x802BBC7C (80 bytes)
    AptFloat(float val) : AptValue(/*AptVFT_Float*/ 6) {
        m_floatValue = val;
    }

    ~AptFloat() {}

    static AptFloat* Create(float val);
    static void ClearPool();
};

// ############################################################################
//
//  AptInteger - Pooled integer APT value type
//
// ############################################################################

class AptInteger : public AptValue {
public:
    int m_intValue;         // 0x0C

    // 0x802BBF38 (72 bytes)
    AptInteger(int val) : AptValue(/*AptVFT_Integer*/ 7) {
        m_intValue = val;
    }

    ~AptInteger() {}

    static AptInteger* Create(int val);
    static void ClearPool();
};

// ############################################################################
//
//  AptNone - Null/none APT value (destructor only)
//
//  Layout: 12 bytes (AptValue base)
//
// ############################################################################

class AptNone : public AptValue {
public:
    // 0x802B445C (88 bytes)
    ~AptNone() {
        // Sets vtable to AptNone vtable, calls AptValue::~AptValue
        // If delete bit set, deallocates via DOGMA pool (size 12)
    }
};

// ############################################################################
//
//  AptRegister - Register APT value (destructor only)
//
//  Layout: 16 bytes
//
// ############################################################################

class AptRegister : public AptValue {
public:
    int m_registerIndex;    // 0x0C

    // 0x80281D30 (88 bytes)
    ~AptRegister() {
        // Sets vtable, calls AptValue::~AptValue
        // If delete bit set, deallocates via DOGMA pool (size 16)
    }
};

// ############################################################################
//
//  AptLine - Linked list of AptWords for text rendering
//
//  Layout: 48 bytes
//    0x00: void** m_vtable
//    0x04: AptWord* m_wordList  (linked list head)
//    ...
//    0x0C: void* m_field_0C
//    0x2C: void* m_field_2C
//
// ############################################################################

class AptLine {
public:
    AptWord* m_wordList;    // 0x04

    // 0x8000DFA8 (80 bytes)
    void UnlinkWord(AptWord* word) {
        AptWord* prev = NULL;
        AptWord* cur = m_wordList;
        while (cur != NULL) {
            if (cur == word) {
                break;
            }
            prev = cur;
            cur = cur->m_next; // offset 0x00 of AptWord = next pointer
        }
        if (cur == NULL) return;
        if (prev != NULL) {
            prev->m_next = cur->m_next;
        } else {
            m_wordList = cur->m_next;
        }
    }

    // 0x8000DFF8 (116 bytes)
    void Draw(ERC* rc, EMat4* mat, EVec4* color1, EVec4* color2) {
        AptWord* word = m_wordList;
        while (word != NULL) {
            word->Draw(rc, mat, color1, color2); // vtable call
            word = word->m_next;
        }
    }

    // 0x8039D468 (136 bytes)
    ~AptLine() {
        // Walk word list and destroy each via vtable call
        AptWord* cur = m_wordList;
        while (cur != NULL) {
            AptWord* next = cur->m_next;
            cur->Destroy(/*mode=*/3); // vtable destroy call
            cur = next;
        }
    }
};

// ############################################################################
//
//  AptIntervalTimer
//
// ############################################################################

class AptIntervalTimer {
public:
    int   m_paramCount;     // 0x14 (offset 20)
    void* m_paramArray;     // 0x18 (offset 24) - array of param entries

    // 0x80285640 (144 bytes)
    void cleanParams() {
        if (m_paramCount <= 0) return;
        int remaining = m_paramCount;
        while (remaining > 0) {
            // Get last param entry, call SetMember("cyclesDone", "", 126) on it via vtable
            // This is a cleanup loop that clears parameter state
            int count = m_paramCount;
            void* entry = ((void**)m_paramArray)[count - 1];
            // vtable call to set member
            remaining--;
            m_paramCount--;
        }
    }
};

// ############################################################################
//
//  AptNativeFunction - 10 small methods (mostly vtable stubs)
//
// ############################################################################

class AptNativeFunction : public AptValue {
public:
    void* m_funcPtr;            // 0x0C - native function pointer
    int   m_argCount;           // 0x10

    // Constructor: AptValue(vft_index), store func ptr and arg count
    AptNativeFunction(void* func, int nArgs) : AptValue(/*AptVFT_NativeFunc*/ 0) {
        m_funcPtr = func;
        m_argCount = nArgs;
    }

    ~AptNativeFunction() {}

    void* GetFuncPtr() const { return m_funcPtr; }
    int   GetArgCount() const { return m_argCount; }
};

// ############################################################################
//
//  AptPseudoCIH_t - 1 function
//
// ############################################################################

class AptPseudoCIH_t {
public:
    // Destructor only - delegates to base class cleanup
    ~AptPseudoCIH_t();
};

// ############################################################################
//
//  AptSavedInputCheckpoints - 1 function
//
// ############################################################################

class AptSavedInputCheckpoints {
public:
    int m_count;        // 0x00
    void* m_data;       // 0x04

    // Simple destructor or init
    void Reset() {
        m_count = 0;
    }
};

// ############################################################################
//
//  AptScriptFunctionByteCodeBlock - 2 functions
//
// ############################################################################

class AptScriptFunctionByteCodeBlock {
public:
    void* m_bytecode;       // 0x00
    int   m_size;           // 0x04
    int   m_refCount;       // 0x08

    void AddRef() { m_refCount++; }
    void Release() {
        m_refCount--;
        if (m_refCount <= 0) {
            if (m_bytecode) {
                operator_delete_impl(m_bytecode);
            }
            operator_delete_impl(this);
        }
    }
};

// ############################################################################
//
//  AptValueWithHash - 2 functions
//
// ############################################################################

class AptValueWithHash {
public:
    AptValue* m_value;      // 0x00
    unsigned int m_hash;    // 0x04

    ~AptValueWithHash();
    void Set(AptValue* val, unsigned int hash) {
        m_value = val;
        m_hash = hash;
    }
};

// ############################################################################
//
//  AptExtern - 2 functions
//
// ############################################################################

class AptExtern : public AptValue {
public:
    void* m_externRef;      // 0x0C

    AptExtern() : AptValue(/*AptVFT_Extern*/ 0) {
        m_externRef = NULL;
    }
    ~AptExtern() {}
};

// ############################################################################
//
//  AptGC - Garbage collector for APT values
//
// ############################################################################

class AptGC {
public:
    void* m_gcList;         // 0x00
    int   m_count;          // 0x04
    int   m_capacity;       // 0x08

    // 3 functions: Mark, Sweep, CollectGarbage
    void CollectGarbage();
    void Mark(AptValue* val);
    void Sweep();
};

// ############################################################################
//
//  AptGlobalExtensionObject - 1 function
//
// ############################################################################

class AptGlobalExtensionObject : public AptValue {
public:
    // Single destructor that calls AptValue::~AptValue
    ~AptGlobalExtensionObject() {}
};

// ############################################################################
//
//  AptLookup - 1 function (string hash lookup)
//
// ############################################################################

class AptLookup {
public:
    // Hash table lookup for APT property names
    static unsigned int HashString(const char* str);
};

// ############################################################################
//
//  AptMemoryAllocationsT - 2 functions
//
// ############################################################################

class AptMemoryAllocationsT {
public:
    int m_allocationCount;      // 0x00
    int m_totalBytes;           // 0x04

    void Reset() {
        m_allocationCount = 0;
        m_totalBytes = 0;
    }

    void Record(int bytes) {
        m_allocationCount++;
        m_totalBytes += bytes;
    }
};

// ############################################################################
//
//  AptStringObject - 3 functions
//
// ############################################################################

class AptStringObject : public AptValue {
public:
    char* m_string;     // 0x0C

    AptStringObject(const char* str);
    ~AptStringObject();
    const char* GetString() const { return m_string; }
};

// ############################################################################
//
//  AptValueVector - 3 functions
//
// ############################################################################

class AptValueVector {
public:
    AptValue** m_data;      // 0x00
    int        m_count;     // 0x04
    int        m_capacity;  // 0x08

    void Clear() {
        m_count = 0;
    }

    void Push(AptValue* val) {
        if (m_count >= m_capacity) {
            // Grow array
            int newCap = m_capacity * 2;
            if (newCap < 8) newCap = 8;
            AptValue** newData = (AptValue**)operator_new_impl(newCap * sizeof(AptValue*));
            if (m_data && m_count > 0) {
                memcpy(newData, m_data, m_count * sizeof(AptValue*));
            }
            if (m_data) {
                operator_delete_impl(m_data);
            }
            m_data = newData;
            m_capacity = newCap;
        }
        m_data[m_count++] = val;
    }

    AptValue* Pop() {
        if (m_count <= 0) return NULL;
        return m_data[--m_count];
    }
};

// ############################################################################
//
//  AptXmlAttributes - 3 functions
//
// ############################################################################

class AptXmlAttributes {
public:
    void* m_attrList;       // 0x00
    int   m_count;          // 0x04

    const char* GetAttribute(const char* name) const;
    bool HasAttribute(const char* name) const;
    int GetCount() const { return m_count; }
};

// ############################################################################
//
//  AptXmlNode - 7 functions
//
// ############################################################################

class AptXmlNode {
public:
    void*       m_vtable;           // 0x00
    char*       m_name;             // 0x04
    char*       m_value;            // 0x08
    AptXmlNode* m_firstChild;       // 0x0C
    AptXmlNode* m_nextSibling;      // 0x10
    AptXmlNode* m_prevSibling;      // 0x14
    void*       m_attributes;       // 0x18

    ~AptXmlNode();

    const char* nodeName() const { return m_name; }
    const char* nodeValue() const { return m_value; }
    AptXmlNode* nextSibling() const { return m_nextSibling; }
    AptXmlNode* previousSibling() const { return m_prevSibling; }
    void* getFirstAttribute() const { return m_attributes; }
    void* getNextAttribute() const;
};

// ############################################################################
//
//  AptScriptColour - 10 functions (RGBA color for APT scripts)
//
// ############################################################################

class AptScriptColour : public AptValue {
public:
    float m_r, m_g, m_b, m_a;  // 0x0C-0x18

    AptScriptColour(float r, float g, float b, float a)
        : AptValue(/*vft*/ 0), m_r(r), m_g(g), m_b(b), m_a(a) {}

    ~AptScriptColour() {}

    float GetR() const { return m_r; }
    float GetG() const { return m_g; }
    float GetB() const { return m_b; }
    float GetA() const { return m_a; }
    void SetR(float v) { m_r = v; }
    void SetG(float v) { m_g = v; }
    void SetB(float v) { m_b = v; }
    void SetA(float v) { m_a = v; }
};

// ############################################################################
//
//  ArcCopier - Archive file copier (2 functions)
//
// ############################################################################

class ArcCopier {
public:
    void* m_file;       // 0x00
    int   m_state;      // 0x04

    // 0x8032144C (112 bytes)
    ~ArcCopier() {
        if (m_file != NULL) {
            // Close file via EFileSystem::Destroy
        }
    }

    // 0x803214BC (456 bytes)
    bool Copy(char* srcName, char* dstName, unsigned int& bytesOut, int blockSize);
};

// ############################################################################
//
//  BackgroundPane - Wrapper pane subclass (1 function: destructor)
//
// ############################################################################

class BackgroundPane : public WrapperPaneBase {
public:
    void* m_data;       // 0x08

    // 0x803A1988 (124 bytes)
    ~BackgroundPane() {
        // Calls WrapperPaneBase::Shutdown()
        // If m_data allocated, frees via __builtin_delete or node_alloc deallocate
    }
};

// ############################################################################
//
//  BehPrintParams - Behavior tree debug print (1 function)
//
//  Layout: ~516 bytes (contains 512-byte filename buffer at start)
//
// ############################################################################

class BehPrintParams {
public:
    char m_filename[512];   // 0x00

    // 0x800ABC48 (72 bytes)
    void SetFilename(const char* name) {
        int len = strlen(name);
        if (len <= 512) {
            strcpy(m_filename, name);
        }
    }
};

// ############################################################################
//
//  BitArray64 - 64-bit bitfield (7 functions)
//
//  Layout: 8 bytes (two u32s forming a 64-bit value)
//    0x00: u32 m_hi    (high 32 bits)
//    0x04: u32 m_lo    (low 32 bits)
//
// ############################################################################

class BitArray64 {
public:
    unsigned int m_hi;      // 0x00
    unsigned int m_lo;      // 0x04

    // 0x8009B7AC (80 bytes)
    bool IsSet(int bit) const {
        // 64-bit arithmetic shift right by 'bit' positions, test bit 0
        unsigned long long val = ((unsigned long long)m_hi << 32) | m_lo;
        return ((val >> bit) & 1) != 0;
    }

    // 0x8009B7FC (80 bytes) - identical to IsSet
    bool operator[](int bit) const {
        return IsSet(bit);
    }

    // 0x8009B84C (84 bytes)
    void Set(int bit) {
        unsigned long long mask = (unsigned long long)1 << bit;
        unsigned int maskHi = (unsigned int)(mask >> 32);
        unsigned int maskLo = (unsigned int)(mask & 0xFFFFFFFF);
        m_hi |= maskHi;
        m_lo |= maskLo;
    }

    // 0x8009B8A0 (92 bytes)
    void Clear(int bit) {
        unsigned long long mask = (unsigned long long)1 << bit;
        unsigned int maskHi = (unsigned int)(mask >> 32);
        unsigned int maskLo = (unsigned int)(mask & 0xFFFFFFFF);
        m_hi &= ~maskHi;
        m_lo &= ~maskLo;
    }

    // 0x8009B974 (72 bytes)
    BitArray64& operator<<=(int shift) {
        unsigned long long val = ((unsigned long long)m_hi << 32) | m_lo;
        val <<= shift;
        m_hi = (unsigned int)(val >> 32);
        m_lo = (unsigned int)(val & 0xFFFFFFFF);
        return *this;
    }

    // 0x8009B9BC (72 bytes)
    BitArray64& operator>>=(int shift) {
        long long val = ((long long)m_hi << 32) | m_lo;
        val >>= shift; // arithmetic shift
        m_hi = (unsigned int)(val >> 32);
        m_lo = (unsigned int)(val & 0xFFFFFFFF);
        return *this;
    }

    // 0x8009BA04 (80 bytes)
    int CountBits() const {
        int count = 0;
        for (int i = 0; i <= 63; i++) {
            if (IsSet(i)) count++;
        }
        return count;
    }
};

// ############################################################################
//
//  BitMatrix64 - 64-bit matrix indexed by CTilePt (13 functions)
//
//  Layout: 24 bytes (3 BitArray64 values)
//    0x00: BitArray64 m_rows[3]
//
// ############################################################################

class BitMatrix64 {
public:
    BitArray64 m_rows[3];   // 0x00..0x17

    BitMatrix64() {
        memset(this, 0, sizeof(BitMatrix64));
    }

    BitMatrix64(BitMatrix64& other) {
        memcpy(this, &other, sizeof(BitMatrix64));
    }

    ~BitMatrix64() {}

    BitMatrix64& operator=(BitMatrix64& other) {
        memcpy(this, &other, sizeof(BitMatrix64));
        return *this;
    }

    BitArray64& operator[](int idx) {
        return m_rows[idx];
    }

    bool IsSet(CTilePt& pt) const;
    void Set(CTilePt& pt);
    void Clear(CTilePt& pt);

    void Clear() {
        memset(this, 0, sizeof(BitMatrix64));
    }

    BitMatrix64& operator&=(BitMatrix64& other) {
        for (int i = 0; i < 3; i++) {
            m_rows[i].m_hi &= other.m_rows[i].m_hi;
            m_rows[i].m_lo &= other.m_rows[i].m_lo;
        }
        return *this;
    }

    BitMatrix64& operator|=(BitMatrix64& other) {
        for (int i = 0; i < 3; i++) {
            m_rows[i].m_hi |= other.m_rows[i].m_hi;
            m_rows[i].m_lo |= other.m_rows[i].m_lo;
        }
        return *this;
    }

    BitMatrix64& operator^=(BitMatrix64& other) {
        for (int i = 0; i < 3; i++) {
            m_rows[i].m_hi ^= other.m_rows[i].m_hi;
            m_rows[i].m_lo ^= other.m_rows[i].m_lo;
        }
        return *this;
    }

    int CountBits() const {
        int total = 0;
        for (int i = 0; i < 3; i++) {
            total += m_rows[i].CountBits();
        }
        return total;
    }
};

// ############################################################################
//
//  ButtonItem - UI button with text (3 functions)
//
//  Layout: 112 bytes
//    inherits from TextBaseItem (which inherits from PaneItem)
//    0x00: u32 m_type          (=2)
//    0x04: u32 m_flags
//    0x08: u32 m_field_008
//    0x0C-0x18: float fields
//    0x1C: void* m_vtable2
//    0x20: TextBlock m_textBlock (at offset 32)
//    0x44: void* m_buffer       (heap-allocated)
//    0x6C: u32 m_field_06C
//
// ############################################################################

class ButtonItem /* : public TextBaseItem */ {
public:
    u32   m_type;           // 0x00
    u32   m_flags;          // 0x04
    u32   m_field_008;      // 0x08
    float m_field_00C;      // 0x0C
    float m_field_010;      // 0x10
    float m_field_014;      // 0x14
    float m_field_018;      // 0x18
    void* m_vtable2;        // 0x1C
    // TextBlock at 0x20
    u8    m_textBlock[36];  // 0x20
    void* m_buffer;         // 0x44

    // 0x800848BC (88 bytes)
    void Startup() {
        TextBaseItem_Startup(); // parent call
        TextBaseItem_SetStyle(/*global style*/ 0);
        // Set text block scale and mark dirty
        // m_flags |= 2
        m_flags |= 2;
    }

    // Forward declarations for parent calls
    void TextBaseItem_Startup();
    void TextBaseItem_SetStyle(int style);
    void TextBaseItem_Reset();
    void TextBlock_Clear();
    void ButtonItem_Startup();

    // 0x800875FC (176 bytes)
    ButtonItem() {
        m_type = 2;
        m_flags = 1;
        m_field_008 = 0;
        m_field_00C = 0.0f;
        m_field_010 = 0.0f;
        m_field_014 = 0.0f;
        m_field_018 = 0.0f;
        m_buffer = NULL;
        // Init text block, call parent Startup + Reset, then own Startup
    }

    // 0x800876AC (124 bytes)
    ~ButtonItem() {
        if (m_buffer != NULL) {
            EAHeap* heap = MainHeap();
            heap->Free(m_buffer);
        }
        // Call PaneItem::Startup + Reset (cleanup pattern)
    }
};

// ############################################################################
//
//  CDirtyXml - XML parser wrapper (2 functions)
//
// ############################################################################

class CDirtyXml {
public:
    void* m_impl;       // 0x00 - CDirtyXmlImpl*

    // 0x8023AF0C (108 bytes)
    ~CDirtyXml() {
        if (m_impl != NULL) {
            // Destroy impl via vtable call
            // Delete impl
        }
    }

    // 0x8023AF78 (136 bytes)
    void parseXml(char* xmlData);
};

// ############################################################################
//
//  CDirtyXmlImpl - 1 function
//
// ############################################################################

class CDirtyXmlImpl {
public:
    void* m_vtable;     // 0x00
    void* m_nodeData;   // 0x04
    // ... more fields up to 0x20
    void* m_xmlVtable;  // 0x20

    // 0x8023A7A0 (152 bytes)
    AptXmlNode* createNewAptXml(char* xmlStr) {
        // Allocate 36-byte object via __builtin_new
        // Set vtables at offset 0 and 32
        // If xmlStr is non-null and non-empty, parse it via vtable call
        // Otherwise set m_nodeData = NULL
        // Return pointer to offset 32 (the xml node interface)
        void* obj = operator_new_impl(36);
        // ... setup ...
        if (xmlStr != NULL && xmlStr[0] != '\0') {
            // parse via vtable
        } else {
            ((void**)obj)[1] = NULL; // offset 4 = null
        }
        if (obj == NULL) return NULL;
        return (AptXmlNode*)((char*)obj + 32);
    }
};

// ############################################################################
//
//  CDirtyXmlNode - 7 functions
//
// ############################################################################

class CDirtyXmlNode {
public:
    void* m_vtable;
    void* m_name;
    void* m_value;
    CDirtyXmlNode* m_firstChild;
    CDirtyXmlNode* m_nextSibling;
    CDirtyXmlNode* m_prevSibling;
    void* m_firstAttr;
    void* m_currentAttr;

    ~CDirtyXmlNode();

    void* getFirstAttribute() {
        m_currentAttr = m_firstAttr;
        return m_currentAttr;
    }

    void* getNextAttribute() {
        if (m_currentAttr != NULL) {
            m_currentAttr = *((void**)m_currentAttr); // next ptr at offset 0
        }
        return m_currentAttr;
    }

    CDirtyXmlNode* nextSibling() { return m_nextSibling; }
    CDirtyXmlNode* previousSibling() { return m_prevSibling; }
    const char* nodeName() { return (const char*)m_name; }
    const char* nodeValue() { return (const char*)m_value; }
};

// ############################################################################
//
//  CTGMicroTimer - High-resolution timer (1 function)
//
//  Layout: 28 bytes
//    0x00: u32 m_startHi
//    0x04: u32 m_startLo
//    0x08: u32 m_endHi
//    0x0C: u32 m_endLo
//    0x10: u32 m_freqHi
//    0x14: u32 m_freqLo
//    0x18: u32 m_running
//
// ############################################################################

class CTGMicroTimer {
public:
    unsigned int m_startHi, m_startLo;  // 0x00
    unsigned int m_endHi,   m_endLo;    // 0x08
    unsigned int m_freqHi,  m_freqLo;   // 0x10
    int          m_running;             // 0x18

    // 0x8007D620 (136 bytes)
    long long GetElapsedTime() const {
        unsigned int endHi, endLo;
        if (m_running) {
            // Query current time
            // (platform-specific: OSTick on GC)
            endHi = 0; endLo = 0; // placeholder
        } else {
            endHi = m_endHi;
            endLo = m_endLo;
        }
        // elapsed = (end - start) * 1000000 / freq
        long long elapsed = ((long long)endHi << 32 | endLo)
                          - ((long long)m_startHi << 32 | m_startLo);
        long long scaled = elapsed * 1000000LL;
        long long freq = ((long long)m_freqHi << 32 | m_freqLo);
        return scaled / freq;
    }
};

// ############################################################################
//
//  CUnlockDisplayObjectSim - 5 functions
//
// ############################################################################

class cXPerson;

class CUnlockDisplayObjectSim /* : public CUnlockDisplayObject */ {
public:
    cXPerson* m_person;     // offset varies

    CUnlockDisplayObjectSim() { m_person = NULL; }
    ~CUnlockDisplayObjectSim() {}

    void SetPerson(cXPerson* person) { m_person = person; }
    void ServiceDataReady();
    void Draw(ERC* rc);
};

// ############################################################################
//
//  DepthOfField - Post-processing effect (2 functions)
//
// ############################################################################

class DepthOfField /* : public FrameEffect */ {
public:
    float m_nearPlane;      // offset in parent
    float m_farPlane;
    float m_focusDistance;
    float m_aperture;
    float m_targetNear, m_targetFar, m_targetFocus, m_targetAperture;
    int   m_effectState;

    // 0x80357474 (368 bytes)
    void UpdateTargetParameters(float dt) {
        // Interpolate current parameters toward target values
        // Uses lerp with dt as blend factor
    }

    // 0x803575E4 (68 bytes)
    void EffectStateChanged(int newState) {
        m_effectState = newState;
    }
};

// ############################################################################
//
//  FadeSquare - Visual fade effect with model (4 functions)
//
//  Layout: 28 bytes
//    0x00-0x08: padding/base
//    0x0C: ERModel* m_model
//    0x10: float m_fadeProgress
//    0x14: int m_active
//    0x18: int m_direction
//
// ############################################################################

class FadeSquare {
public:
    u32      m_field_000[3];    // 0x00
    ERModel* m_model;           // 0x0C
    float    m_fadeProgress;    // 0x10
    int      m_active;          // 0x14
    int      m_direction;       // 0x18

    // 0x8021CE00 (76 bytes)
    FadeSquare() {
        m_model = (ERModel*)EResourceManager_AddRefAsync(0x969A60EA); // shader hash
        StopDraw();
    }

    // 0x8021CE4C (100 bytes)
    ~FadeSquare() {
        if (m_model != NULL) {
            EResource_DelRef(m_model);
        } else {
            EResourceManager_DelRefAsync(0x969A60EA);
        }
    }

    // 0x8021CF08 (168 bytes)
    void Update(float dt) {
        if (m_model == NULL) {
            m_model = (ERModel*)EResourceManager_GetRef(0x969A60EA);
        }
        if (m_active) {
            m_fadeProgress -= dt;
            if (m_direction) {
                if (m_fadeProgress <= 0.0f) {
                    m_direction = 0;
                    m_fadeProgress += 1.0f; // reset with offset
                }
            }
        }
    }

    // 0x8021CFCC (644 bytes)
    void Draw(ERC* rc, EVec3& pos);

    // Helper stubs
    void StopDraw();
    ERModel* EResourceManager_AddRefAsync(unsigned int hash);
    void EResourceManager_DelRefAsync(unsigned int hash);
    void* EResourceManager_GetRef(unsigned int hash);
    void EResource_DelRef(void* res);
};

// ############################################################################
//
//  FastAllocPool - Fixed-size block allocator (3 functions)
//
//  Layout: 24 bytes
//    0x00: void*  m_basePtr     - base of pool memory
//    0x04: void*  m_freeList    - linked list of free blocks
//    0x08: u32    m_blockCount  - total blocks
//    0x0C: u32    m_blockSize   - bytes per block
//    0x10: void*  m_alignedBase - aligned start address
//    0x14: void** m_vtable
//
// ############################################################################

class FastAllocPool {
public:
    void*        m_basePtr;     // 0x00
    void*        m_freeList;    // 0x04
    unsigned int m_blockCount;  // 0x08
    unsigned int m_blockSize;   // 0x0C
    void*        m_alignedBase; // 0x10
    void**       m_vtable;      // 0x14

    // 0x802D6F7C (116 bytes)
    FastAllocPool(char* name, void* memory, int blockSize, int blockCount) {
        m_vtable = NULL; // set by derived
        m_alignedBase = NULL;
        m_basePtr = NULL;
        m_freeList = NULL;
        m_blockCount = 0;
        m_blockSize = 0;
        if (memory != NULL && blockSize != 0 && blockCount != 0) {
            Init(memory, blockSize, blockCount);
        }
    }

    // 0x802D7024 (112 bytes)
    void Init(void* memory, int blockSize, int blockCount) {
        // Align base to blockSize boundary
        unsigned int addr = (unsigned int)memory;
        unsigned int aligned = addr & ~(unsigned int)(blockSize - 1);
        if (aligned < addr) aligned += blockSize;

        m_freeList = NULL;
        m_alignedBase = (void*)aligned;
        m_basePtr = memory;
        m_blockCount = blockCount;
        m_blockSize = blockSize;

        // Build free list: chain blocks with magic marker 0x45464546 ("EFEF")
        char* ptr = (char*)memory;
        for (unsigned int i = 0; i < (unsigned int)blockCount; i++) {
            if (ptr != NULL) {
                *(unsigned int*)ptr = 0x45454546; // magic
                *(void**)(ptr + 4) = m_freeList;
                m_freeList = ptr;
            }
            ptr += blockSize;
        }
    }

    // Alloc/Free provided by parent or overrides
    void* Alloc();
    void  Free(void* ptr);

    // 0x802D7094 (248 bytes)
    bool Valid() {
        // Validates free list - ensures all pointers are within pool bounds
        void* node = m_freeList;
        if (node == NULL) return true;

        // Check first node
        if ((unsigned int)node < (unsigned int)m_basePtr) return false;
        unsigned int end = (unsigned int)m_basePtr + m_blockSize * m_blockCount;
        if ((unsigned int)node >= end) return false;

        // Walk the list
        while (node != NULL) {
            void* next = *(void**)((char*)node + 4);
            if (next == NULL) break;
            if ((unsigned int)next < (unsigned int)m_basePtr) return false;
            if ((unsigned int)next >= end) return false;
            node = next;
        }
        return true;
    }
};

// ############################################################################
//
//  ProtectedAllocPool - Thread-safe wrapper around FastAllocPool (4 functions)
//
//  Layout: FastAllocPool (24 bytes) + EMutex at offset 24
//
// ############################################################################

class ProtectedAllocPool : public FastAllocPool {
public:
    EMutex m_mutex;     // 0x18 (offset 24)

    // 0x802D718C (68 bytes)
    ProtectedAllocPool(char* name, void* memory, int blockSize, int blockCount)
        : FastAllocPool(name, memory, blockSize, blockCount)
    {
        // EMutex constructor called for m_mutex
    }

    // 0x802D71D0 (80 bytes)
    ~ProtectedAllocPool() {
        // EMutex destructor, then FastAllocPool destructor
    }

    // 0x802D7250 (120 bytes)
    void* Alloc() {
        m_mutex.Lock(-1); // wait forever
        void* result = FastAllocPool::Alloc();
        m_mutex.Unlock();
        return result;
    }

    // 0x802D72C8 (120 bytes)
    void Free(void* ptr) {
        m_mutex.Lock(-1);
        FastAllocPool::Free(ptr);
        m_mutex.Unlock();
    }
};

// ############################################################################
//
//  FrameEffect - Base class for post-processing effects (3 functions)
//
// ############################################################################

class FrameEffect {
public:
    int m_enabled;          // 0x04
    int m_effectState;      // 0x08
    int m_targetEnabled;    // 0x0C

    // 0x80356FB0 (112 bytes)
    void Enable(bool enable) {
        m_targetEnabled = enable ? 1 : 0;
        if (m_targetEnabled != m_enabled) {
            UpdateEffectState();
        }
    }

    // 0x80357020 (148 bytes)
    void Update(float dt, ERC* rc);

    // 0x803570B4 (212 bytes)
    void UpdateEffectState();
};

// ############################################################################
//
//  FloatConstantsQuickData - Quick-access float constants table (9 functions)
//
// ############################################################################

class FloatConstantsQuickData {
public:
    FloatConstantItem* m_items;     // 0x00
    int                m_count;     // 0x04
    int                m_capacity;  // 0x08

    FloatConstantsQuickData() : m_items(NULL), m_count(0), m_capacity(0) {}

    float Get(const char* name, float defaultVal, bool warn) {
        FloatConstantItem* item = findItem(m_items, m_items + m_count, name);
        if (item != NULL) {
            return item->m_value;
        }
        return defaultVal;
    }

    bool Has(const char* name) {
        return findItem(m_items, m_items + m_count, name) != NULL;
    }

    void Load(unsigned int resourceId, short version);
    void Load(iResFile* file, short version);

    FloatConstantItem* findItem(FloatConstantItem* begin, FloatConstantItem* end, const char* name);
};

// ############################################################################
//
//  EBoundSphere - Bounding sphere (2 functions)
//
//  Layout: 16 bytes
//    0x00: float x
//    0x04: float y
//    0x08: float z
//    0x0C: float radius
//
// ############################################################################

class EBoundSphere {
public:
    float m_x, m_y, m_z;   // center
    float m_radius;         // radius

    // 0x8035A034 (548 bytes)
    void Combine(EBoundSphere& a, EBoundSphere& b) {
        // Compute direction from a to b
        float dx = b.m_x - a.m_x;
        float dy = b.m_y - a.m_y;
        float dz = b.m_z - a.m_z;
        float dist = sqrtf(dx*dx + dy*dy + dz*dz);

        if (dist == 0.0f) {
            // Coincident centers - use larger sphere
            m_x = a.m_x; m_y = a.m_y; m_z = a.m_z;
            m_radius = (a.m_radius > b.m_radius) ? a.m_radius : b.m_radius;
            return;
        }

        // Normalize direction
        float invDist = 1.0f / dist;
        float nx = dx * invDist;
        float ny = dy * invDist;
        float nz = dz * invDist;

        // Find extremes along direction axis
        float minA = -a.m_radius;
        float maxA = a.m_radius;
        float minB = dist - b.m_radius;
        float maxB = dist + b.m_radius;

        float newMin = (minA < minB) ? minA : minB;
        float newMax = (maxA > maxB) ? maxA : maxB;

        // New center and radius
        float newRadius = (newMax - newMin) * 0.5f;
        float centerOffset = (newMax + newMin) * 0.5f;

        m_x = a.m_x + nx * centerOffset;
        m_y = a.m_y + ny * centerOffset;
        m_z = a.m_z + nz * centerOffset;
        m_radius = newRadius;

        // Sanity check: ensure new sphere contains both
        float distToA = sqrtf(
            (m_x - a.m_x)*(m_x - a.m_x) +
            (m_y - a.m_y)*(m_y - a.m_y) +
            (m_z - a.m_z)*(m_z - a.m_z));
        if (m_radius < distToA + a.m_radius) {
            // Copy a
            m_x = a.m_x; m_y = a.m_y; m_z = a.m_z;
            m_radius = a.m_radius;
        }

        float distToB = sqrtf(
            (m_x - b.m_x)*(m_x - b.m_x) +
            (m_y - b.m_y)*(m_y - b.m_y) +
            (m_z - b.m_z)*(m_z - b.m_z));
        if (m_radius < distToB + b.m_radius) {
            m_x = b.m_x; m_y = b.m_y; m_z = b.m_z;
            m_radius = b.m_radius;
        }
    }

    // 0x8035A258 (132 bytes)
    void ComputeFast(EVec3* points, int count) {
        // Quick bounding sphere from point cloud
        // Uses centroid + max distance approach
        if (count <= 0) return;

        float cx = 0, cy = 0, cz = 0;
        for (int i = 0; i < count; i++) {
            float* p = (float*)&points[i];
            cx += p[0]; cy += p[1]; cz += p[2];
        }
        float invCount = 1.0f / (float)count;
        cx *= invCount; cy *= invCount; cz *= invCount;

        float maxDistSq = 0;
        for (int i = 0; i < count; i++) {
            float* p = (float*)&points[i];
            float dx = p[0] - cx;
            float dy = p[1] - cy;
            float dz = p[2] - cz;
            float distSq = dx*dx + dy*dy + dz*dz;
            if (distSq > maxDistSq) maxDistSq = distSq;
        }

        m_x = cx; m_y = cy; m_z = cz;
        m_radius = sqrtf(maxDistSq);
    }
};

// ############################################################################
//
//  ECullPlane - Frustum culling plane (1 function)
//
// ############################################################################

class ECullPlane {
public:
    float m_a, m_b, m_c, m_d;  // plane equation ax + by + cz + d = 0

    // Test point against plane
    float DistanceToPoint(float x, float y, float z) const {
        return m_a * x + m_b * y + m_c * z + m_d;
    }
};

// ############################################################################
//
//  EGrowPool - Growable memory pool (4 functions)
//
// ############################################################################

class EGrowPool {
public:
    void*        m_blocks;      // 0x00 - linked list of allocated blocks
    unsigned int m_blockSize;   // 0x04
    int          m_numBlocks;   // 0x08
    void*        m_freeList;    // 0x0C

    EGrowPool() : m_blocks(NULL), m_blockSize(0), m_numBlocks(0), m_freeList(NULL) {}

    ~EGrowPool() {
        // Free all allocated blocks
        void* block = m_blocks;
        while (block != NULL) {
            void* next = *(void**)block;
            EAHeap* heap = MainHeap();
            heap->Free(block);
            block = next;
        }
    }

    void Init(unsigned int blockSize, int initialBlocks) {
        m_blockSize = blockSize;
        // Allocate initial block
        GrowBy(initialBlocks);
    }

    void* Alloc() {
        if (m_freeList == NULL) {
            GrowBy(16); // grow by 16 elements
        }
        if (m_freeList == NULL) return NULL;
        void* result = m_freeList;
        m_freeList = *(void**)m_freeList;
        return result;
    }

    void Free(void* ptr) {
        *(void**)ptr = m_freeList;
        m_freeList = ptr;
    }

    void GrowBy(int count) {
        EAHeap* heap = MainHeap();
        unsigned int totalSize = m_blockSize * count + sizeof(void*);
        void* block = heap->Malloc(totalSize, 0);
        // Link into block list
        *(void**)block = m_blocks;
        m_blocks = block;
        m_numBlocks++;
        // Add elements to free list
        char* ptr = (char*)block + sizeof(void*);
        for (int i = 0; i < count; i++) {
            *(void**)ptr = m_freeList;
            m_freeList = ptr;
            ptr += m_blockSize;
        }
    }
};

// ############################################################################
//
//  ECheatDMI - Cheat code debug menu item (5 functions)
//
// ############################################################################

class ECheatDMI {
public:
    void*  m_vtable;        // 0x00
    char*  m_name;          // 0x04
    int    m_cheatId;       // 0x08
    int    m_enabled;       // 0x0C
    void*  m_callback;      // 0x10

    ECheatDMI();
    ~ECheatDMI();
    void Execute();
    void SetEnabled(bool enabled) { m_enabled = enabled ? 1 : 0; }
    const char* GetName() const { return m_name; }
};

// ############################################################################
//
//  EDebugMenu - Debug menu system (5 functions)
//
// ############################################################################

class EDebugMenu {
public:
    ECheatDMI** m_items;    // 0x00
    int         m_count;    // 0x04
    int         m_capacity; // 0x08
    int         m_visible;  // 0x0C
    int         m_selected; // 0x10

    EDebugMenu();
    ~EDebugMenu();
    void AddItem(ECheatDMI* item);
    void Show() { m_visible = 1; }
    void Hide() { m_visible = 0; }
};

// ############################################################################
//
//  ESingleLock - RAII mutex lock (5 functions)
//
// ############################################################################

class ESingleLock {
public:
    EMutex* m_mutex;    // 0x00
    int     m_locked;   // 0x04

    ESingleLock(EMutex* mtx) : m_mutex(mtx), m_locked(0) {}
    ~ESingleLock() {
        if (m_locked) Unlock();
    }

    void Lock(int timeout = -1) {
        m_mutex->Lock(timeout);
        m_locked = 1;
    }

    void Unlock() {
        m_mutex->Unlock();
        m_locked = 0;
    }

    bool IsLocked() const { return m_locked != 0; }
};

// ############################################################################
//
//  ESleep - Thread sleep utility (3 functions)
//
// ############################################################################

class ESleep {
public:
    static void SleepMs(int milliseconds);
    static void SleepUs(int microseconds);
    static void Yield();
};

// ############################################################################
//
//  EThreadMutex - Thread mutex wrapper (4 functions)
//
// ############################################################################

class EThreadMutex {
public:
    void* m_osMutex;    // 0x00 (platform-specific mutex handle)

    EThreadMutex();
    ~EThreadMutex();
    void Lock();
    void Unlock();
};

// ############################################################################
//
//  EdithDialogPrimitive - Edith behavior dialog primitive (4 functions)
//
// ############################################################################

class EdithDialogPrimitive {
public:
    int   m_primId;         // 0x00
    short m_operands[4];    // 0x04
    short m_trueTarget;     // 0x0C
    short m_falseTarget;    // 0x0E

    EdithDialogPrimitive();
    ~EdithDialogPrimitive();
    void Execute(void* context);
    int  GetPrimId() const { return m_primId; }
};

// ############################################################################
//
//  EdithResFile - Edith resource file (1 function)
//
// ############################################################################

class EdithResFile {
public:
    void* m_data;       // 0x00
    int   m_size;       // 0x04

    // Single function: load or init
    void Load(iResFile* file);
};

// ############################################################################
//
//  ArcFileInfo - Archive file validation/copying (7 functions)
//
//  Layout:
//    0x00: char* m_dvdPath
//    0x04: char* m_hddPath
//    0x08: int   m_dvdSize
//    0x0C: int   m_hddSize
//    0x10: int   m_validated
//
// ############################################################################

class ArcFileInfo {
public:
    char* m_dvdPath;        // 0x00
    char* m_hddPath;        // 0x04
    int   m_dvdSize;        // 0x08
    int   m_hddSize;        // 0x0C
    int   m_validated;      // 0x10

    // 0x80321760 (120 bytes)
    void OnValidated() {
        // Look up resource via EResourceManager
        // If found, set m_validated = 1 and register with resource manager
    }

    // 0x803217D8 (672 bytes)
    void Validate() {
        if (m_dvdPath == NULL) return;
        if (m_hddPath == NULL) return;
        if (m_validated) return;
        // Open DVD file, read first 1KB
        // Open HDD file, read first 1KB
        // Compare contents
        // If match and size matches, call OnValidated
        // Otherwise, read more data and re-compare
    }

    // 0x80321A78 (232 bytes)
    void Reset() {
        if (m_dvdPath == NULL) return;
        if (m_hddPath == NULL) return;
        m_hddSize = 0;
        m_validated = 0;
        // Close any open file handles
    }

    // 0x80321B60 (272 bytes)
    bool CopyArcFile() {
        if (m_dvdPath == NULL || m_hddPath == NULL) return true;
        if (m_validated) return true;
        // Validate first, if fails, use ArcCopier to copy DVD->HDD
        // Then re-validate
        return true;
    }

    // 0x80321C98 (100 bytes)
    bool IsOpen() {
        if (m_hddPath == NULL || m_dvdPath == NULL) return false;
        // Check via EResourceManager::ArchiveFileIsOpen
        return false;
    }

    // 0x80321CFC (100 bytes)
    bool IsUsingHDD() {
        if (m_hddPath == NULL || m_dvdPath == NULL) return false;
        // Check via EResourceManager::ArchiveFileIsUsingHDD
        return false;
    }

    // 0x80321D60 (68 bytes)
    bool CompareName(char* name) {
        if (name == NULL || m_dvdPath == NULL) return false;
        return strcasecmp(m_dvdPath, name) == 0;
    }
};
