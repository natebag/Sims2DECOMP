// misc_classes.cpp - Decompiled miscellaneous classes from asm_decomp
//
// Converted from inline PPC asm stubs to real C++.
// Classes covered: EStorable, ETypeInfo, EChecksum, CDirtyXml, QuickStringSet,
// EWindow, E3DWindow (partial), EMovie, ActionMenu, ActionQueue, Interaction,
// GoalUnlock, StringBuffer, ObjSelector, Commander, Neighbor, RoomManager,
// EResource, ObjectModuleImpl (partial), ObjectFolderImpl (partial),
// SimModel (partial), GameData (partial), Motives, ESubModelShader (partial)
//
// All logic derived from PPC assembly analysis of the GameCube build.

#include "types.h"

// ============================================================================
// Forward declarations
// ============================================================================
class EStorable;
class ETypeInfo;
class EMemoryWriteStream;
class EStream;
class EFile;
class ERC;
class ERenderSurface;
class ERShader;
class ETexture;
class ETextureDef;
class EResourceManager;
class EControllerManager;
class EController;
class EAnimController;
class EMat4;
class EVec2;
class EVec3;
class EBound3;
class EBoundSphere;
class BString2;
class BSplineVolume;
class Behavior;
class ChecksumList;
class CasSimDescriptionS2C;
class ENeighborhoodCustomChar;
class Family;
class HouseStats;
class Interaction;
class ObjDefinition;
class ObjSelector;
class ObjectDataInterface;
class ObjectModule;
class Quad;
class ReconBuffer;
class ResFile;
class Room;
class RoomManager;
class StringBuffer;
class cXMTObject;
class cXObject;
class cXObjectImpl;
class cXPerson;
class cXPersonImpl;
class iResFile;

struct CTilePt;
struct eBodyPartS2C;
struct eTattooTextureTypeS2C;
struct tRelationshipType;
struct ObjectDataID;
struct ESMSStrip;
struct ESMBuildDisplayListData;

template <typename T0> class TRect;
template <typename T0, typename T1> class TArray;
class TArrayERModelAllocator;

// CRC32 lookup table (external, loaded from ROM data)
extern unsigned int sCRC32Table[256];

// Global SDA references (r13-relative in PPC)
extern EResourceManager* g_pResourceManager;     // r13 - 21508 (ObjectFolder res mgr)
extern void* g_pCurrentWindow;                    // r13 - 26708
extern void* g_pCurrentWindowMat;                 // r13 - 26704
extern void* g_pRenderer;                         // r13 - 26392
extern void* g_pObjectModule;                     // r13 - 21484
extern void* g_pControllerManager;                // r13 - 26524
extern ETypeInfo* g_pTypeInfoList;                // r13 - 26844 (linked list head)
extern ETypeInfo* g_pTypeInfoTreeRoot;            // r13 - 26848 (BST root)
extern int g_typeInfoCount;                       // r13 - 26840

// External functions
extern "C" {
    void* MainHeap();
    int strlen(const char*);
    char* strcpy(char*, const char*);
    void* memset(void*, int, unsigned int);
    void* memcpy(void*, const void*, unsigned int);
}

// EAHeap
class EAHeap {
public:
    void Free(void* ptr);
};

// ============================================================================
// EChecksum - CRC32 and FNV hash computation
// ============================================================================

class EChecksum {
public:
    // CRC32 over a raw buffer
    static unsigned int Compute(void* data, int length) {
        unsigned char* ptr = (unsigned char*)data;
        unsigned int crc = 0xFFFFFFFF;

        for (int i = 0; i < length; i++) {
            unsigned char index = (unsigned char)(crc ^ ptr[i]);
            crc = (crc >> 8) ^ sCRC32Table[index];
        }

        return ~crc;
    }

    // CRC32 over a null-terminated string
    static unsigned int Compute(const char* str) {
        const unsigned char* ptr = (const unsigned char*)str;
        unsigned int crc = 0xFFFFFFFF;

        while (*ptr != 0) {
            unsigned char index = (unsigned char)(crc ^ (signed char)*ptr);
            crc = (crc >> 8) ^ sCRC32Table[index];
            ptr++;
        }

        return ~crc;
    }

    // CRC32 over a symbol string (case-insensitive, non-alnum -> '_')
    // If initialCrc is non-zero, uses ~initialCrc as starting value.
    // If initialCrc is zero and string starts with a digit, uses a
    // special start value from ROM data.
    static unsigned int ComputeSymbol(const char* str, unsigned int initialCrc) {
        const unsigned char* ptr = (const unsigned char*)str;
        unsigned int crc;

        if (initialCrc != 0) {
            crc = ~initialCrc;
        } else {
            unsigned char first = *ptr;
            crc = 0xFFFFFFFF;
            // Check if first char is a digit (0-9)
            if ((unsigned int)(first - '0') <= 9) {
                // Use special numeric symbol start value
                // Original: loads from ROM, XORs with 0x00FFFFFF
                extern unsigned int sNumericSymbolSeed;
                crc = sNumericSymbolSeed ^ 0x00FFFFFF;
            }
        }

        unsigned char ch = *ptr;
        while (ch != 0) {
            signed char sc = (signed char)ch;
            // Normalize: lowercase -> uppercase, non-alnum -> '_'
            if ((unsigned int)(sc - 'a') <= 25) {
                sc = sc - 32; // to uppercase
            } else if ((unsigned int)(sc - 'A') > 25) {
                if ((unsigned int)(sc - '0') > 9) {
                    sc = '_';
                }
            }

            unsigned char index = (unsigned char)(crc ^ sc);
            crc = (crc >> 8) ^ sCRC32Table[index];

            ptr++;
            ch = *ptr;
        }

        return ~crc;
    }

    // FNV-1a 64-bit hash
    static unsigned long long FNVHashString64(const char* str, unsigned long long basis) {
        const unsigned char* ptr = (const unsigned char*)str;
        unsigned long long hash = basis;

        while (*ptr != 0) {
            hash = hash * 435ULL;  // FNV prime (simplified for GC)
            hash ^= (signed char)*ptr;
            ptr++;
        }

        return hash;
    }
};

// ============================================================================
// ETypeInfo - Runtime type information system
// ============================================================================

class ETypeInfo {
public:
    // Fields (from assembly analysis):
    // 0x00: EStorable* (*m_createFunc)()
    // 0x04: void (*m_destructFunc)(void*)
    // 0x08: void (*m_deleteFunc)(void*)
    // 0x0C: const char* m_name
    // 0x10: unsigned int m_checksum
    // 0x14: unsigned short m_typeId
    // 0x16: short m_parentOffset  (init to -1)
    // 0x18: ETypeInfo* m_parent
    // 0x1C: ETypeInfo* m_left     (BST left child)
    // 0x20: ETypeInfo* m_right    (BST right child)
    // 0x24: ETypeInfo* m_next     (linked list next)

    typedef EStorable* (*CreateFunc)();
    typedef void (*DestructFunc)(void*);
    typedef void (*DeleteFunc)(void*);

    CreateFunc   m_createFunc;    // 0x00
    DestructFunc m_destructFunc;  // 0x04
    DeleteFunc   m_deleteFunc;    // 0x08
    const char*  m_name;         // 0x0C
    unsigned int m_checksum;     // 0x10
    unsigned short m_typeId;     // 0x14
    short        m_parentOffset; // 0x16
    ETypeInfo*   m_parent;       // 0x18
    ETypeInfo*   m_left;         // 0x1C
    ETypeInfo*   m_right;        // 0x20
    ETypeInfo*   m_next;         // 0x24

    void Register(CreateFunc create, DestructFunc destruct, DeleteFunc del,
                  unsigned short typeId, const char* name, ETypeInfo* parent) {
        m_createFunc = create;
        m_destructFunc = destruct;
        m_deleteFunc = del;
        m_name = name;
        m_checksum = EChecksum::Compute(name);
        m_typeId = typeId;
        m_parentOffset = -1;

        if (parent != this) {
            m_parent = parent;
        } else {
            m_parent = nullptr;
        }

        g_typeInfoCount++;
        Insert();
    }

    // Insert into the global BST sorted by checksum
    void Insert() {
        // Add to linked list
        m_next = g_pTypeInfoList;
        g_pTypeInfoList = this;

        // Insert into BST
        ETypeInfo* parent = nullptr;
        ETypeInfo* node = g_pTypeInfoTreeRoot;

        while (node != nullptr) {
            if (node->m_checksum == m_checksum) {
                return; // duplicate
            }
            parent = node;
            if (m_checksum < node->m_checksum) {
                node = parent->m_left;
            } else {
                node = parent->m_right;
            }
        }

        if (parent == nullptr) {
            g_pTypeInfoTreeRoot = this;
        } else if (m_checksum < parent->m_checksum) {
            parent->m_left = this;
        } else {
            parent->m_right = this;
        }

        m_left = nullptr;
        m_right = nullptr;
    }

    // Check if a type derives from this type
    bool IsDerivedFrom(ETypeInfo* target) const;
};

// ============================================================================
// EStorable - Base class for serializable objects with RTTI
// ============================================================================

class EStorable {
public:
    // vtable at offset 0
    // vtable entry 4 (offset 16): GetTypeInfo virtual
    // vtable entry 5 (offset 20): GetTypeInfo function pointer

    // Deep copy via serialization round-trip
    EStorable* CreateCopy() const {
        EMemoryWriteStream* stream = nullptr; // placeholder
        // 1. Serialize 'this' into a memory stream
        // 2. Allocate a copy of the buffer
        // 3. Deserialize from the buffer to create a new object
        // 4. Free the temporary buffer
        // The actual implementation serializes via operator<< and operator>>
        // This is a complex operation that depends on EMemoryWriteStream
        return nullptr; // simplified - real impl does serialize round-trip
    }

    // Check if this object's type derives from 'type'
    bool IsDerivedFrom(ETypeInfo* type) const {
        if (this == nullptr) {
            return false;
        }
        // Call virtual GetTypeInfo() via vtable
        // vtable[4] = offset to ETypeInfo subobject
        // vtable[5] = GetTypeInfo function
        ETypeInfo* myType = GetTypeInfo();
        return myType->IsDerivedFrom(type);
    }

    // Check exact type match
    bool IsExactType(ETypeInfo* type) const {
        if (this == nullptr) {
            return false;
        }
        ETypeInfo* myType = GetTypeInfo();
        return (myType == type);
    }

    // Safe downcast (const version)
    const EStorable* DynamicCast(ETypeInfo* type) const {
        if (this == nullptr) {
            return nullptr;
        }
        if (IsDerivedFrom(type)) {
            return this;
        }
        return nullptr;
    }

    // Safe downcast (non-const version)
    EStorable* DynamicCast(ETypeInfo* type) {
        if (this == nullptr) {
            return nullptr;
        }
        if (IsDerivedFrom(type)) {
            return this;
        }
        return nullptr;
    }

    // Virtual function - implemented by subclasses
    virtual ETypeInfo* GetTypeInfo() const = 0;
};

// Minimal EString stub for local variable usage in EResource methods
class EString {
public:
    char* m_buffer;
    static char m_null;
    EString() { m_buffer = &m_null; }
    void Deallocate(char*) {}
};
char EString::m_null = '\0';

// ============================================================================
// EResource - Reference-counted resource base class
// ============================================================================

class EResource {
public:
    // 0x00: vtable pointer
    // 0x04: EResourceManager* m_manager
    // 0x0C: short m_refCount

    void** m_vtable;              // 0x00
    EResourceManager* m_manager;  // 0x04
    int m_pad08;                  // 0x08
    short m_refCount;             // 0x0C

    ~EResource() {
        // Notify resource manager we're being destroyed
        if (m_manager != nullptr) {
            // EResourceManager::ResourceDestructing(this)
        }
        // If delete flag set, free memory via MainHeap
    }

    void Write(EStream& stream) {
        // Writes a default empty name string to the stream
        EString name;
        // name.MakeCopy("") - copies empty string literal
        // operator<<(stream, name)
        // name.Deallocate()
    }

    void Read(EStream& stream) {
        // Reads and discards name string (compatibility)
        EString name;
        // name.SetToNull()
        // if (!skipResourceNames) operator>>(stream, name)
        // name.Deallocate()
    }

    void Load(EFile& file) {
        // Same as Read but from EFile
        EString name;
        // name.SetToNull()
        // if (!skipResourceNames) operator>>(file, name)
        // name.Deallocate()
    }

    void DelRef() {
        if (m_manager != nullptr) {
            // EResourceManager::DelRef(this, DelRefMode::Normal)
            return;
        }
        // Manual ref counting
        m_refCount--;
        if (m_refCount <= 0) {
            // Call virtual destructor via vtable[2]
            // this->~EResource() with delete flag
        }
    }
};

// ============================================================================
// Commander - Base class for objects in a command chain
// ============================================================================

class Commander {
public:
    // 0x00: Commander* m_next (linked list)
    // 0x0C: vtable pointer

    Commander* m_next;     // 0x00
    int m_pad04;           // 0x04
    int m_pad08;           // 0x08
    void** m_vtable;       // 0x0C

    ~Commander() {
        // Walk the global commander list and unlink this node
        extern Commander* g_commanderListHead; // r13 - 32076
        Commander* prev = &g_commanderListHead[0]; // placeholder for head sentinel
        Commander* curr = prev->m_next;

        while (curr != nullptr) {
            if (curr == this) {
                // Unlink: prev->next = this->next
                prev->m_next = this->m_next;
                break;
            }
            prev = curr;
            curr = curr->m_next;
        }

        // If delete flag set (r4 & 1), free via __builtin_delete
    }
};

// ============================================================================
// CDirtyXml - Simple XML parser
// ============================================================================

class CDirtyXmlNode;

class CDirtyXml /* : public CDirtyXmlNode */ {
public:
    // 0x00: vtable pointer (CDirtyXml vtable)
    // 0x04: char* m_xmlData (allocated copy of input)
    // 0x10: int m_parsed
    // 0x1C: int* m_parseState
    // 0x20: vtable pointer (CDirtyXmlNode vtable)

    void** m_vtable_xml;    // 0x00
    char*  m_xmlData;       // 0x04
    int    m_pad08[3];      // 0x08-0x10
    int    m_parsed;        // 0x10
    int    m_pad14[2];      // 0x14-0x18
    int*   m_parseState;    // 0x1C
    void** m_vtable_node;   // 0x20

    ~CDirtyXml() {
        // Set CDirtyXml vtable pointers
        // Free m_xmlData via __builtin_vec_delete
        if (m_xmlData != nullptr) {
            delete[] m_xmlData;
        }
        // Set CDirtyXmlNode vtable, call CDirtyXmlNode::~CDirtyXmlNode()
    }

    void parseXml(char* xmlText) {
        // 1. Get length of input
        int len = strlen(xmlText);

        // 2. Allocate and copy the XML text
        m_xmlData = new char[len + 1];
        strcpy(m_xmlData, xmlText);

        // 3. Allocate parse state (4 bytes)
        m_parseState = (int*)new char[4];

        // 4. Parse the first node
        // _ParseNode(nullptr, (unsigned char*)m_xmlData) -> returns offset
        // Store result in m_parseState[0]

        // 5. Mark as parsed
        m_parsed = 1;

        // 6. Full parse pass
        // _Parse(this, m_parseState[0], m_xmlData)
    }
};

// ============================================================================
// StringBuffer - Fixed-capacity string buffer
// ============================================================================

class StringBuffer {
public:
    // 0x00: char* m_buffer  (points to inline data at offset 0x08 usually)
    // 0x04: unsigned int m_capacity

    char*        m_buffer;     // 0x00
    unsigned int m_capacity;   // 0x04
    // inline char data follows at 0x08

    StringBuffer() : m_buffer(0), m_capacity(0) {}

    StringBuffer(char* buffer, unsigned int capacity) {
        m_buffer = buffer;
        m_capacity = capacity;
        m_buffer[0] = '\0';
    }

    int length() const {
        return strlen(m_buffer);
    }

    int capacity() const {
        return (int)m_capacity;
    }

    void append(const char* str, int maxLen) {
        if (str == nullptr) return;

        int len;
        if (maxLen < 0) {
            len = strlen(str);
        } else {
            // Find actual length up to maxLen, stopping at null
            int i = 0;
            if (i < maxLen && str[0] != '\0') {
                while (i + 1 < maxLen && str[i + 1] != '\0') {
                    i++;
                }
                i++;
            }
            len = (maxLen < i) ? maxLen : i;
        }

        int currentLen = length();
        int totalNeeded = len + currentLen;
        int cap = capacity();

        if (totalNeeded >= cap) {
            len = cap - currentLen - 1;
        }

        // Copy characters
        int copied = 0;
        while (copied < len) {
            m_buffer[currentLen + copied] = str[copied];
            copied++;
        }

        // Null terminate
        m_buffer[currentLen + copied] = '\0';
    }

    void append(StringBuffer& other, int maxLen) {
        append(other.m_buffer, maxLen);
    }

    int compare(const StringBuffer& other) const {
        // strcmp-like comparison
        const char* a = m_buffer;
        const char* b = other.m_buffer;
        while (*a && *b && *a == *b) { a++; b++; }
        return *a - *b;
    }

    int compareNoCase(const StringBuffer& other) const {
        return compareNoCase(other.m_buffer, -1);
    }

    int compareNoCase(const char* str, int maxLen) const {
        const char* a = m_buffer;
        const char* b = str;
        while (*a && *b) {
            char ca = *a, cb = *b;
            if (ca >= 'A' && ca <= 'Z') ca += 32;
            if (cb >= 'A' && cb <= 'Z') cb += 32;
            if (ca != cb) return ca - cb;
            a++; b++;
            if (maxLen > 0 && (a - m_buffer) >= maxLen) break;
        }
        if (maxLen < 0) return *a - *b;
        return 0;
    }

    char charAt(int index) const {
        return m_buffer[index];
    }

    void toLower() {
        char* p = m_buffer;
        while (*p) {
            if (*p >= 'A' && *p <= 'Z') *p += 32;
            p++;
        }
    }

    void appendNum(int value) {
        // Converts int to decimal string and appends
        char buf[16];
        int i = 0;
        bool neg = false;
        if (value < 0) {
            neg = true;
            value = -value;
        }
        do {
            buf[i++] = '0' + (value % 10);
            value /= 10;
        } while (value > 0);
        if (neg) buf[i++] = '-';
        // Reverse
        for (int j = 0; j < i / 2; j++) {
            char t = buf[j]; buf[j] = buf[i - 1 - j]; buf[i - 1 - j] = t;
        }
        buf[i] = '\0';
        append(buf, -1);
    }

    void appendNum(int value, int radix) {
        // Appends number in given radix
        if (radix == 10) { appendNum(value); return; }
        char buf[34];
        int i = 0;
        unsigned int uval = (unsigned int)value;
        do {
            int digit = uval % radix;
            buf[i++] = (digit < 10) ? ('0' + digit) : ('a' + digit - 10);
            uval /= radix;
        } while (uval > 0);
        // Reverse
        for (int j = 0; j < i / 2; j++) {
            char t = buf[j]; buf[j] = buf[i - 1 - j]; buf[i - 1 - j] = t;
        }
        buf[i] = '\0';
        append(buf, -1);
    }

    int find(const char* needle, int startPos) const {
        const char* result = nullptr;
        const char* haystack = m_buffer + startPos;
        // Simple strstr
        while (*haystack) {
            const char* h = haystack;
            const char* n = needle;
            while (*n && *h && *h == *n) { h++; n++; }
            if (*n == '\0') return (int)(haystack - m_buffer);
            haystack++;
        }
        return -1;
    }

    int findNoCase(const char* needle, int startPos) const {
        const char* haystack = m_buffer + startPos;
        while (*haystack) {
            const char* h = haystack;
            const char* n = needle;
            while (*n && *h) {
                char ch = *h, cn = *n;
                if (ch >= 'A' && ch <= 'Z') ch += 32;
                if (cn >= 'A' && cn <= 'Z') cn += 32;
                if (ch != cn) break;
                h++; n++;
            }
            if (*n == '\0') return (int)(haystack - m_buffer);
            haystack++;
        }
        return -1;
    }

    void assignDebug(unsigned short* wstr) {
        // Converts wide string to narrow for debug display
        char* dst = m_buffer;
        int cap = capacity() - 1;
        int i = 0;
        while (wstr[i] != 0 && i < cap) {
            dst[i] = (char)wstr[i];
            i++;
        }
        dst[i] = '\0';
    }
};

// ============================================================================
// QuickStringSet - Fast string resource lookup
// ============================================================================

// Helper types
struct AStringSet {
    char** m_strings;  // 0x00 - array of string pointers
    // count stored at m_strings[-1] (4 bytes before the array)
};

struct WStringSet {
    char** m_strings;  // 0x00
};

class QuickStringSet {
public:
    // 0x00: vtable pointer
    // 0x04: WStringSet* m_locStrings
    // 0x08: AStringSet* m_strings
    // 0x0C: char* m_defaultString
    // 0x10: int m_refCount

    void** m_vtable;          // 0x00
    WStringSet* m_locStrings; // 0x04
    AStringSet* m_strings;    // 0x08
    const char* m_default;    // 0x0C
    int m_refCount;           // 0x10

    // Get count of strings in the set
    int Count(char type) {
        if (m_strings != nullptr) {
            char** arr = m_strings->m_strings;
            if (arr == nullptr) return 0;
            // Count is stored at arr[-1]
            return *(int*)((char*)arr - 4);
        }
        if (m_locStrings != nullptr) {
            char** arr = m_locStrings->m_strings;
            int count = 0;
            if (arr != nullptr) {
                count = *(int*)((char*)arr - 4);
            }
            return count;
        }
        return 0;
    }

    // Get string by 1-based index
    const char* GetString(int index, char type) {
        if (m_strings == nullptr) return nullptr;
        if (index <= 0) return nullptr;

        char** arr = m_strings->m_strings;
        int count = 0;
        if (arr != nullptr) {
            count = *(int*)((char*)arr - 4);
        }
        if (index > count) return nullptr;

        return arr[index - 1];
    }

    // Get localized string by 1-based index (returns via out param)
    void GetLocString(const char** out, int index) {
        if (m_locStrings == nullptr) {
            *out = m_default;
            return;
        }
        if (index <= 0) {
            *out = m_default;
            return;
        }

        char** arr = m_locStrings->m_strings;
        int count = 0;
        if (arr != nullptr) {
            count = *(int*)((char*)arr - 4);
        }
        if (index > count) {
            *out = m_default;
            return;
        }

        *out = arr[index - 1];
    }

    // SetInfo from namespace ID - resolves through global resource manager
    void SetInfo(unsigned int namespaceId, short resId, unsigned int flags,
                 bool flag, char type) {
        // Get iResFile* from global ObjectFolder resource manager
        // via virtual call, then delegate to SetInfo(iResFile*, ...)
        iResFile* resFile = nullptr; // resolved via vtable call
        SetInfo(resFile, resId, flags, flag, type);
    }

    // SetInfo from resource file
    void SetInfo(iResFile* file, short resId, unsigned int flags,
                 bool flag, char type) {
        m_strings = nullptr;
        m_locStrings = nullptr;

        if (file == nullptr) return;

        // Look up the AStringSet resource by ID
        // file->GetResources() returns resource array
        // FindRes<AStringSet> searches for matching resource
        // m_strings = result
    }

    // SetLocInfo from namespace ID
    void SetLocInfo(unsigned int namespaceId, short resId, unsigned int flags,
                    bool flag, char type) {
        iResFile* resFile = nullptr; // resolved via vtable call
        SetLocInfo(resFile, resId, flags, flag, type);
    }

    // SetLocInfo from resource file
    void SetLocInfo(iResFile* file, short resId, unsigned int flags,
                    bool flag, char type) {
        if (file == nullptr) return;

        m_strings = nullptr;
        m_locStrings = nullptr;

        // Look up WStringSet resource by ID
        // file->GetLocResources() returns localized resource array
        // FindRes<WStringSet> searches for matching resource
        // m_locStrings = result
    }

    // LoadRes from namespace ID
    void LoadRes(unsigned int namespaceId, short resId) {
        iResFile* resFile = nullptr; // resolved via vtable call
        LoadRes(resFile, resId);
    }

    // LoadRes from resource file
    void LoadRes(iResFile* file, short resId) {
        m_strings = nullptr;
        m_locStrings = nullptr;

        if (file != nullptr) {
            // Find AStringSet resource
        }

        // Call virtual function to check if loading is needed
        // If load returns non-null, retry the search
        bool needsLoad = false; // virtual call result
        if (needsLoad) {
            m_strings = nullptr;
            m_locStrings = nullptr;
            if (file != nullptr) {
                // Find AStringSet resource again after load
            }
            // Call virtual again
        }
    }

    // LoadLocRes from namespace ID
    void LoadLocRes(unsigned int namespaceId, short resId) {
        iResFile* resFile = nullptr; // resolved via vtable call
        LoadLocRes(resFile, resId);
    }

    // LoadLocRes from resource file
    int LoadLocRes(iResFile* file, short resId) {
        if (file != nullptr) {
            m_strings = nullptr;
            m_locStrings = nullptr;
            // Find WStringSet resource
        }

        if (m_locStrings == nullptr) {
            return -1;
        }
        return 0;
    }

    // Save resource
    void Save(unsigned int namespaceId, short resId) {
        iResFile* resFile = nullptr; // resolved via vtable call
        // Save(resFile, resId)
    }

    // Load from ObjectDataID reference
    bool LoadFromDataID(ObjectDataID& dataId) {
        // Call virtual function via vtable offset 232/236
        // Uses dataId fields (namespaceId at 0x00, resId at 0x04)
        // Returns whether load succeeded (result == 0 means success -> true)
        return false; // placeholder
    }

    // COM-style QueryInterface
    bool QueryInterface(unsigned int iid, void** ppOut) {
        if (ppOut == nullptr) return false;

        // Accepts IID 1 or 0x6BC37BC5
        if (iid == 1 || iid == 0x6BC37BC5) {
            // Get type info via vtable[4/5]
            *ppOut = this;
            return true;
        }

        return false;
    }

    // Release reference
    int Release() {
        m_refCount--;
        if (m_refCount <= 0) {
            if (this != nullptr) {
                // Call virtual destructor via vtable offset 96/100
                // with delete flag = 3
            }
            return 0;
        }
        return m_refCount;
    }
};

// ============================================================================
// EMovie - FMV video playback
// ============================================================================

class EMovie {
public:
    // 0x08: vtable pointer (for parent class)

    void** m_vtable08; // 0x08

    void Update() {
        // Call virtual function via vtable at offset 0x08
        // vtable[40/44] = IsPlaying check
        bool isPlaying = false; // virtual call result

        if (!isPlaying) {
            // Movie finished playing
            // 1. Get global renderer
            void* renderer = g_pRenderer;

            // 2. Get render window from renderer (vtable offset 128/132)
            // 3. Call AddChild on render window with this movie (vtable 592/596)
            // 4. Call RemoveChild on renderer (vtable 136/140) to clean up
        }
    }
};

// ============================================================================
// Motives - Sim needs/motives simulation
// ============================================================================

class Motives {
public:
    // 0x00 - 0x40: float m_currentValues[16]  (current motive values)
    // 0x40 - 0x80: float m_deltas[16]          (motive decay rates)
    // 0x80: int m_motiveConstantsPtr

    float m_currentValues[16];  // 0x00 (offset 0 from start of embedded struct)
    float m_deltas[16];         // 0x40
    int m_motiveConstants;      // 0x80

    void Init() {
        // If global motive constants not initialized, load them
        extern int g_motiveConstantsInited; // r13 - 32020
        if (g_motiveConstantsInited == 0) {
            // GetMotiveConstantsClient() -> call virtual init
        }

        // Initialize all 16 motive values to default
        float defaultValue = 0.0f; // loaded from ROM
        for (int i = 0; i < 16; i++) {
            m_currentValues[i] = defaultValue;
        }
        for (int i = 0; i < 16; i++) {
            m_deltas[i] = defaultValue;
        }
        m_motiveConstants = 0;
    }

    void Sim();     // Complex motive decay simulation (888 bytes)
    void Cleanup(); // Cleanup motive state
};

// ============================================================================
// GoalUnlock - Manages unlockable content progression
// ============================================================================

class GoalUnlock {
public:
    // 0x00: vtable pointer
    // 0x04: short m_unlockVars[64] (originally 39, expanded in later versions)

    void** m_vtable;     // 0x00
    short m_unlockVars[64]; // 0x04

    void DoStream(ReconBuffer* buffer, int version) {
        if (version <= 16) {
            // Old format: 39 unlock vars
            // ReconBuffer::Recon16(m_unlockVars, 39)
            // Then call virtual to recalculate
        } else {
            // New format: 64 unlock vars
            // ReconBuffer::Recon16(m_unlockVars, 64)
        }
    }

    // Get count of unlocks for a given type
    int GetUnlockCount(int unlockType) {
        switch (unlockType) {
            case 0: // Objects
            case 3: // Also objects (alias)
            case 4: // Also objects (alias)
                return 13; // number of object unlock categories
            case 1:
                return 5;  // recipes or similar
            case 2:
                return 7;  // another category
            default:
                return 0;
        }
    }

    // Check if a specific unlock is granted
    bool IsUnlocked(int type, short index) {
        int firstVar = GetFirstUnlockVar(type);
        if (firstVar < 0) return false;
        return (m_unlockVars[firstVar + index] != 0);
    }

    // Grant an unlock
    void GrantUnlock(int type, short index) {
        int firstVar = GetFirstUnlockVar(type);
        if (firstVar < 0) return;
        m_unlockVars[firstVar + index] = 1;
    }

    // Check if recently unlocked (for notification)
    bool IsRecentlyUnlocked(int type, short index) {
        // Uses a separate flag range in the unlock vars
        return false; // simplified
    }

    void SetRecentlyUnlocked(int type, short index, bool recent) {
        // Sets the recently-unlocked flag
    }

    // Get total unlocked count for a type
    int GetUnlockTotal(int type) {
        int count = GetUnlockCount(type);
        int total = 0;
        for (int i = 0; i < count; i++) {
            if (IsUnlocked(type, (short)i)) {
                total++;
            }
        }
        return total;
    }

    void SetupObjectUnlockInfo();
    int GetObjectIndexFromGuid(int guid);
    int GetFirstUnlockVar(int type);
    void GrantObjectUnlocks(int category);
};

// ============================================================================
// Interaction - A queued sim action/interaction
// ============================================================================

class Interaction {
public:
    // 0x00: short* m_localVars        (heap-allocated local variables)
    // 0x04: cXObject* m_targetObject
    // 0x08: cXPerson* m_actor
    // 0x0C: int m_treeId
    // 0x10: int m_interactionId
    // 0x14: int m_priority
    // 0x18: short m_flags1
    // 0x1A: short m_flags2
    // 0x1C: short m_entryPoint
    // 0x1E: short m_state
    // 0x20: int m_userData
    // 0x24: int m_pad
    // 0x28: int m_param1
    // 0x2C: short m_shortParam
    // 0x30: float m_floatParam
    // 0x34: BString2 m_name         (4 bytes: char* pointer)
    // 0x38: int m_visualGUID
    // 0x3C: int m_hudFlags

    short*    m_localVars;     // 0x00
    cXObject* m_targetObject;  // 0x04
    cXPerson* m_actor;         // 0x08
    int       m_treeId;        // 0x0C
    int       m_interactionId; // 0x10
    int       m_priority;      // 0x14
    short     m_flags1;        // 0x18
    short     m_flags2;        // 0x1A
    short     m_entryPoint;    // 0x1C
    short     m_state;         // 0x1E
    int       m_userData;      // 0x20
    int       m_pad24;         // 0x24
    int       m_param1;        // 0x28
    short     m_shortParam;    // 0x2C
    short     m_pad2E;         // 0x2E
    float     m_floatParam;    // 0x30
    BString2* m_name;          // 0x34 (embedded BString2)
    int       m_visualGUID;    // 0x38
    int       m_hudFlags;      // 0x3C

    Interaction() {
        m_localVars = nullptr;
        m_targetObject = nullptr;
        m_actor = nullptr;
        m_treeId = 0;
        m_interactionId = 0;
        m_priority = 0;
        m_flags1 = 0;
        m_flags2 = 0;
        m_entryPoint = 0;
        m_state = 0;
        m_userData = 0;
        m_pad24 = 0;
        m_param1 = 0;
        m_shortParam = 0;
        m_floatParam = 0.0f;
        m_name = nullptr;
        m_visualGUID = 0;
        m_hudFlags = 0;
    }

    void operator=(Interaction& other) {
        // Copy all fields
        m_hudFlags = other.m_hudFlags;
        m_targetObject = other.m_targetObject;
        m_param1 = other.m_param1;
        m_actor = other.m_actor;
        m_treeId = other.m_treeId;
        m_interactionId = other.m_interactionId;
        m_priority = other.m_priority;
        m_flags1 = other.m_flags1;
        m_flags2 = other.m_flags2;
        m_entryPoint = other.m_entryPoint;
        m_state = other.m_state;
        m_userData = other.m_userData;
        m_shortParam = other.m_shortParam;
        m_floatParam = other.m_floatParam;

        // Copy BString2 name
        // BString2::operator=(m_name, other.m_name)

        // Copy local vars if present
        m_localVars = nullptr;
        if (other.m_localVars != nullptr) {
            SetLocalVars(other.m_localVars, other.m_pad24);
        }
    }

    void SetLocalVars(short* vars, int count);

    // Get entry point info
    int GetEntry() const {
        return m_entryPoint;
    }

    // Get interaction name
    const char* GetName() const;
    void SetName(int nameId, int langId);
    void DoStream(ReconBuffer* buffer, int version);
    void GetCTilePt() const;
};

// ============================================================================
// ActionQueue - Queue of Interactions for a sim
// ============================================================================

class ActionQueue {
public:
    // 0x000: Interaction m_actions[10]  (10 * 68 = 680 bytes)
    // 0x2A8: int m_head
    // 0x2AC: int m_tail
    // 0x2B0: bool m_hudEnabled

    Interaction m_actions[10]; // 0x000 (each 68 bytes)
    int m_head;                // 0x2A8 (680)
    int m_tail;                // 0x2AC (684)
    bool m_hudEnabled;         // 0x2B0 (688)

    ActionQueue() {
        // Initialize all 10 interaction slots
        for (int i = 0; i < 10; i++) {
            // Interaction::Interaction() called on each
            // (handled by constructor)
        }
        m_head = 0;
        m_hudEnabled = true;
        m_tail = 0;
    }

    // Count visible actions in the queue
    int CountVisible() const {
        int count = 0;
        int start = m_tail;
        int end = m_head;
        int range = end - start;

        if (range <= 0) return 0;

        for (int i = 0; i < range; i++) {
            int idx = (start + i) % 10;
            // Check if action is visible
            // if (IsVisibleAction(m_actions[idx])) count++;
        }
        return count;
    }

    void AddActionToHUD(int index);
    void RemoveActionFromHUD(int index);
    void SetActionText(BString2& text, unsigned int index);
    void SetIconObject(cXObject* obj, unsigned int index);
    bool IsVisibleAction(const Interaction& action) const;
    unsigned int FindVisualInsertGUID(unsigned int guid) const;
    void UpdateAction(unsigned int index);
    void Insert(Interaction& action, unsigned int position);
    void Remove(unsigned int index);
    void DisableHUDAccess(int player);
    void EnableHUDAccess(int player);
};

// ============================================================================
// ActionMenu - Pie menu / action selection UI
// ============================================================================

class ActionMenu {
public:
    class MenuItem {
    public:
        // Layout (from asm analysis):
        // Each MenuItem contains sub-items and display data

        MenuItem() {
            // Initialize all fields to zero/default
        }

        ~MenuItem();

        void Setup(cXObject* obj, Interaction* interaction,
                   BString2& name, unsigned int guid,
                   ERShader* icon, bool autonomous);
        void AddSubItem(int* item);
        bool IsObjectInMenu(cXObject* obj);
        void ClearMenu();

        int GetMenuItemCount() const;
        MenuItem* GetSubMenu();
        MenuItem* GetNthItem(int n);
    };

    // 0x00: cXObject* m_targetObject
    // 0x04: short m_playerIndex
    // 0x06: short m_selectedIndex
    // 0x08: bool m_isActive
    // 0x09: unsigned char m_state
    // 0x0C: MenuItem m_rootMenu  (at offset 12, size ~100 bytes)
    // 0x70: int m_menuStack[7]   (at offset 112)
    // 0x8C: short m_menuDepths[7]
    // 0x90: short m_totalMenuItems
    // 0xA0: bool m_isClosing
    // 0xA1: bool m_visibleItemCount
    // 0xA2: bool m_maxVisibleItems
    // 0xA4: int m_inputFilter
    // 0xA8: int m_playerController
    // 0xAC: int m_iconResource
    // 0xB0: void* m_iconShader

    cXObject*    m_targetObject;      // 0x00
    short        m_playerIndex;       // 0x04
    short        m_selectedIndex;     // 0x06
    bool         m_isActive;          // 0x08
    unsigned char m_state;            // 0x09
    unsigned char m_pad0A[2];         // 0x0A
    MenuItem     m_rootMenu;          // 0x0C (offset 12)
    int          m_menuStack[7];      // 0x70 (offset 112)
    short        m_menuDepths[7];     // 0x90 (offset 144)
    unsigned char m_pad9E[2];         // 0x9E
    unsigned char m_cursorPos;        // 0xA0 (160)
    unsigned char m_visibleItemCount; // 0xA1 (161)
    unsigned char m_maxVisibleItems;  // 0xA2 (162)
    unsigned char m_padA3;            // 0xA3
    int          m_inputData;         // 0xA4 (164)
    int          m_playerController;  // 0xA8 (168)
    int          m_inputFilter;       // 0xAC (172)
    void*        m_iconShader;        // 0xB0 (176)

    ActionMenu() {
        // Initialize root menu
        // m_rootMenu = MenuItem()

        m_isActive = true;
        m_state = 0;
        m_menuStack[0] = (int)&m_rootMenu; // pointer to root menu
        m_menuDepths[0] = 0;
        m_targetObject = nullptr;
        m_playerIndex = 0;
        m_selectedIndex = 0;
        m_iconShader = nullptr;

        // Initialize menu stack and depths to 0
        for (int i = 0; i < 7; i++) {
            m_menuStack[i] = 0;
            m_menuDepths[i] = 0;
        }

        m_cursorPos = 0;
        m_inputData = 0;
        m_visibleItemCount = 0;
        m_maxVisibleItems = 0;
        m_inputFilter = 0;
    }

    ~ActionMenu() {
        // Remove input filter if active
        if (m_inputFilter != 0) {
            // Get player controller, remove filter
            m_inputFilter = 0;
        }

        // Release icon shader resource
        if (m_iconShader != nullptr) {
            // EResource::DelRef()
            m_iconShader = nullptr;
        }

        // Destroy root menu
        // m_rootMenu.~MenuItem()

        // Free this if delete flag set
    }

    void Draw(ERC* rc);
    void Stop();
    void Animate();
    void UpdateIcon();
    void FillInMenu();
    void Run();

    void AddMenu(cXObject* obj, BString2& name, unsigned int guid, ERShader* icon);
    void AddMenuItem(cXObject* obj, Interaction* interaction,
                     BString2& name, unsigned int guid,
                     ERShader* icon, bool autonomous);

    void ShowMenu();
    void BackOutMenu();
    void AcceptMenu();
    void CloseMenu();
    void TerminateMenu();

    const cXObject* GetPlayerSim() const;
};

// ============================================================================
// EWindow - 2D windowing system base
// ============================================================================

class EWindow {
public:
    // Field layout from assembly:
    // 0x00: EMat4 m_windowMat (16 floats = 64 bytes, but actually 48 bytes at 0x00)
    // Exact layout from constructor analysis:
    // 0x00-0x2F: matrix data (48 bytes)
    // 0x30: padding/extended matrix
    // 0x40: TRect<float> m_inputRect  (16 bytes: left, top, right, bottom)
    // 0x50: TRect<float> m_outputRect (16 bytes)
    // 0x60: TRect<float> m_clipRect   (16 bytes)
    // 0x70: TRect<float> m_clipBounds (16 bytes)
    // 0x80: TRect<float> m_clipInv    (16 bytes)
    // 0x90: ERenderSurface* m_surface
    // 0x94: int m_surfaceMode
    // 0x98: bool m_needsUpdate
    // 0x9C: void* m_vtable_window

    float m_matrix[12];            // 0x00 (48 bytes)
    float m_inputRect[4];          // 0x30 (set 2 - right/bottom initially)
    float m_outputRect[4];         // 0x40
    float m_clipRect[4];           // 0x50
    float m_screenRect[4];         // 0x60
    float m_clipCalc[4];           // 0x70 (calculated clip coords)
    float m_clipBounds[4];         // 0x80 (clip bounds)
    void* m_renderSurface;         // 0x90 (144)
    int   m_surfaceMode;           // 0x94 (148)
    int   m_needsUpdate;           // 0x98 (152)
    void* m_vtable;                // 0x9C (156)

    EWindow() {
        // Initialize all rects to (0, 1, 1, 0) pattern from ROM constants
        float zero = 0.0f;
        float one = 1.0f;

        // Set vtable
        // m_vtable = EWindow_vtable

        // Initialize output rect (0x60)
        m_outputRect[0] = zero; // left
        m_outputRect[1] = zero; // top
        m_outputRect[2] = one;  // right
        m_outputRect[3] = one;  // bottom

        // Copy to input rect
        m_inputRect[0] = m_outputRect[0];
        m_inputRect[1] = m_outputRect[1];
        m_inputRect[2] = m_outputRect[2];
        m_inputRect[3] = m_outputRect[3];

        // Copy to clip rect
        m_clipRect[0] = m_inputRect[0];
        m_clipRect[1] = m_inputRect[1];
        m_clipRect[2] = m_inputRect[2];
        m_clipRect[3] = m_inputRect[3];

        // Copy to screen rect
        m_screenRect[0] = m_clipRect[0];
        m_screenRect[1] = m_clipRect[1];
        m_screenRect[2] = m_clipRect[2];
        m_screenRect[3] = m_clipRect[3];

        m_needsUpdate = 1;

        // Calculate window matrix and clip
        CalcWindowMat();
        CalcClip();

        m_renderSurface = nullptr;
        m_surfaceMode = 5;
    }

    ~EWindow() {
        // Set vtable
        // Check if this is the current global window
        if (g_pCurrentWindow == this) {
            g_pCurrentWindow = nullptr;
        }
        if (g_pCurrentWindowMat == this) {
            g_pCurrentWindowMat = nullptr;
        }
        // If delete flag set, free via MainHeap
    }

    void SetRenderSurface(void* surface, int mode) {
        if (m_renderSurface == surface && m_surfaceMode == mode) {
            return;
        }

        m_renderSurface = surface;
        m_surfaceMode = mode;

        float outputRect[4];
        if (surface != nullptr) {
            // Get rect from render surface via vtable[6/7]
        } else {
            // Get rect from global renderer via vtable[26/27]
            // ScaleOutputRectForScreenshot(&outputRect)
        }

        SetOutputCoordinates(outputRect);
    }

    void ScaleForScreenshot(bool enable, int x, int y, int w, int h);

    void ScaleOutputRectForScreenshot(float* rect) {
        // Applies screenshot scaling to the output rectangle
        // Uses global screenshot scale factors
    }

    void ScaleScissorRectForScreenshot(float* scissor, float* reference) {
        // Applies screenshot scaling to scissor rectangle
    }

    void Select(ERC* rc);

    void CalcWindowMat() {
        // Compute the window transform matrix from input/output rects
        float inWidth = m_inputRect[2] - m_inputRect[0];
        float scaleX, scaleY;

        if (inWidth == 0.0f) {
            scaleX = 1.0f;
        } else {
            float outWidth = m_screenRect[2] - m_screenRect[0];
            scaleX = outWidth / inWidth;
        }

        float inHeight = m_inputRect[3] - m_inputRect[1];
        if (inHeight == 0.0f) {
            scaleY = 1.0f;
        } else {
            float outHeight = m_screenRect[3] - m_screenRect[1];
            scaleY = outHeight / inHeight;
        }

        // Build transform: translate(-inputOrigin) * scale * translate(+outputOrigin)
        // EMat4::Translate(-inputRect.left, -inputRect.top, 0)
        // EMat4::PostScale(scaleX, scaleY, 1)
        // EMat4::PostTranslate(screenRect.left, screenRect.top, 0)

        // Then invoke virtual CalcWindowMatDone() via vtable[6/7]
    }

    void CalcClip() {
        // Transform the clip rect corners through the window matrix
        // Produces m_clipCalc and m_clipBounds

        // clipCalc[0] = matrix[0]*outputRect[0] + matrix[12] (etc.)
        // Then compute tight clip bounds considering both input and output rects
    }

    void CalcClipInv() {
        // Inverse of CalcClip - transforms clip coords back
        // clipInv = (clip - translate) / scale
    }

    void SetClip(float* clipRect) {
        m_clipRect[0] = clipRect[0];
        m_clipRect[1] = clipRect[1];
        m_clipRect[2] = clipRect[2];
        m_clipRect[3] = clipRect[3];
        CalcClip();
    }

    void SetInputCoordinates(float* rect) {
        m_inputRect[0] = rect[0];
        m_inputRect[1] = rect[1];
        m_inputRect[2] = rect[2];
        m_inputRect[3] = rect[3];
        CalcWindowMat();
        CalcClip();
    }

    void SetOutputCoordinates(float* rect) {
        m_screenRect[0] = rect[0];
        m_screenRect[1] = rect[1];
        m_screenRect[2] = rect[2];
        m_screenRect[3] = rect[3];
        CalcWindowMat();
        CalcClip();
    }

    void SetRect(float* rect) {
        m_outputRect[0] = rect[0];
        m_outputRect[1] = rect[1];
        m_outputRect[2] = rect[2];
        m_outputRect[3] = rect[3];
        m_inputRect[0] = rect[0];
        m_inputRect[1] = rect[1];
        m_inputRect[2] = rect[2];
        m_inputRect[3] = rect[3];
        CalcWindowMat();
        CalcClip();
    }

    // Point clip test - returns true if (x,y) is inside clip bounds
    bool ClipTest(float x, float y) {
        if (x < m_clipBounds[0] || x > m_clipBounds[2]) return false;
        if (y < m_clipBounds[1] || y > m_clipBounds[3]) return false;
        return true;
    }

    // Rect clip test - returns true if rect overlaps clip bounds
    bool ClipTest(float* rect) {
        if (rect[2] < m_clipBounds[0] || rect[0] > m_clipBounds[2]) return false;
        if (rect[3] < m_clipBounds[1] || rect[1] > m_clipBounds[3]) return false;
        return true;
    }
};

// ============================================================================
// E3DWindow - 3D viewport window (extends EWindow)
// ============================================================================

class E3DWindow : public EWindow {
public:
    // Additional fields beyond EWindow (156 bytes):
    // +0xA0 (160): EMat4 m_viewMatrix (64 bytes)
    // +0xE0 (224): EMat4 m_viewMatrixInv (64 bytes)
    // +0x120 (288): EMat4 m_projMatrix (64 bytes)
    // +0x160 (352): EMat4 m_projMatrixCopy (64 bytes)
    // +0x220 (544): float m_viewportRect[4]
    // +0x230 (560): float m_viewportClip[4]
    // +0x28C (652): float m_fov
    // +0x29C (668): float m_aspect
    // +0x2F0 (752): float m_nearClip
    // +0x2F4 (756): float m_nearClipAdjusted
    // +0x2F8 (760): float m_farClip
    // +0x31C (796): int m_dirty

    // We declare them as flat arrays for the large EMat4 blocks
    float m_viewMatrix[16];       // 0xA0 (relative to EWindow base)
    float m_viewMatrixInv[16];    // 0xE0
    float m_projMatrixExtra[16];  // 0x120
    float m_projMatrix[16];       // 0x160
    // ... more data between ...
    float m_viewportRect[4];      // 0x220
    float m_viewportClip[4];      // 0x230
    // gap
    float m_fov;                  // 0x28C
    float m_aspect;               // 0x29C
    float m_nearClip;             // 0x2F0
    float m_nearClipAdjusted;     // 0x2F4
    float m_farClip;              // 0x2F8
    int m_dirty;                  // 0x31C

    E3DWindow() : EWindow() {
        // Set E3DWindow vtable

        // Initialize identity matrices
        // EMat4::Id() on m_projMatrix
        // EMat4::Id() on m_viewMatrix
        // EMat4::Id() on m_projMatrixExtra

        // Copy viewport rects from EWindow base rects
        // m_viewportRect = m_outputRect
        // m_viewportClip = m_clipRect

        // Set default FOV and aspect from ROM constants
        m_dirty = 1;
    }

    void SetProjection(float fov, float aspect, float nearClip, float farClip) {
        // Build projection matrix
        // EMat4::Projection(fov, aspect, nearClip, farClip) -> temp matrix
        m_fov = fov;
        m_aspect = aspect;
        m_nearClip = nearClip;
        m_nearClipAdjusted = nearClip;  // adjusted if negative
        if (nearClip < 0.0f) {
            m_nearClipAdjusted = nearClip;  // keep negative
        }
        m_farClip = farClip;

        // Copy temp matrix to m_projMatrix
        // memcpy(m_projMatrix, tempMatrix, 64)

        ProjectionMatrixChanged();
    }

    void CopyProjection(E3DWindow* source);
    void SetOrthoProjectionForUIHD(float, float, float, float, float,
                                    float, float, float, float, float, float);
    void SetOrthoProjection(float, float, float, float, float, float);
    void SetLookAt(EMat4& mat);
    void SetLookAtPos(EMat4& mat);
    void SetLookAt(EVec3& eye, EVec3& target, EVec3& up);
    void SetViewport(float* rect);
    void CalcViewport();
    void CalcViewportInv();
    void CalcViewportStructures();

    int Test(EBoundSphere& sphere);
    int Test(EBound3& bounds);
    int TestAsRect(EBound3& bounds);
    int Test(EVec3* points, int count);

    void ProjectionMatrixChanged();
    void LookAtMatrixChanged();
    void Select(ERC* rc);
    void CalcTextureProjection(EMat4& mat);
    void TransformToScreen(EVec3& worldPos, EVec2& screenPos);
    void TransformToScreen(EVec3& worldPos, EVec3& screenPos, float depth);
    void CameraTransformToScreen(EVec3& cameraPos, EVec3& screenPos);
    bool BackCullTest(EVec3* triangle);
    void TransformToWorld(EVec2& screenPos, EVec3& worldPos);
    void PinToFrustrum(EVec3* point);
    void CornerToWorld(EVec3* corner, int index);
    void ProjectToZPlane(EVec3* point, float z, EVec3& result);
    void MakeLineOnPlane(EVec3* line, float z, EVec3& result);
    void GetFrustrumQuadAtZ(float z, Quad* quad);
    void Get3DQuadFromScreenTrapAtZ(float z, float* trap, Quad* quad);

    ~E3DWindow() {
        // E3DWindow vtable cleanup, then EWindow::~EWindow()
    }
};

// ============================================================================
// ESubModelShader - Shader data for model sub-meshes
// ============================================================================

class ESubModelShader {
public:
    // 0x00: void* m_shaderData
    // 0x04: void* m_morphData
    // 0x08: int m_morphTargetCount
    // 0x0C: int m_vertexFormat
    // 0x10: int m_flags
    // 0x14: TArray<ESMSStrip> m_strips        (12 bytes)
    // 0x20: int m_pad20
    // 0x24: float m_lodScale
    // 0x28: int m_morphStripCount
    // 0x2C: TArray<ESMSStrip> m_morphStrips   (12 bytes)
    // 0x38: void* m_parameterizeVerts
    // 0x3C: void* m_latticeVerts
    // 0x68: void* m_morphDeltas
    // 0x6C: void* m_morphResult

    void*  m_shaderData;         // 0x00
    void*  m_morphData;          // 0x04
    int    m_morphTargetCount;   // 0x08
    int    m_vertexFormat;       // 0x0C
    int    m_flags;              // 0x10
    int    m_strips[3];          // 0x14 (TArray header: ptr, count, capacity)
    float  m_lodScale;           // 0x24
    int    m_morphStripCount;    // 0x28
    int    m_morphStrips[3];     // 0x2C (TArray header)
    char   m_meshData[48];       // 0x38 (various mesh buffers)
    void*  m_morphDeltas;        // 0x68
    void*  m_morphResult;        // 0x6C

    ESubModelShader() {
        // Initialize TArray for strips and morphStrips
        // TArray::TArray() on both

        m_shaderData = nullptr;
        m_morphTargetCount = 0;
        m_flags = 0;
        m_vertexFormat = 0;
        m_morphStripCount = 0;
        m_lodScale = 1.0f; // from ROM constant

        // memset(m_meshData, 0, 48)
        memset(m_meshData, 0, 48);

        m_morphData = nullptr;
        m_morphDeltas = nullptr;
        m_morphResult = nullptr;
    }

    ~ESubModelShader() {
        Deallocate();
    }

    void AddRefSubResources();
    void TryIncrementSubResources();
    void DeallocateStripData(ESMSStrip* strip);
    void Deallocate();
    void FreeStripResource();
    void FreeMorphStripResource();
    void FreeMorphResource();
    void CreateRCPrimitive(unsigned int type, ERC* rc, ESMSStrip* strip,
                           bool flag1, bool flag2, bool flag3);
    void ReadPositions(unsigned char* data, ESMSStrip* strip, bool compressed);
    void ReadTexcoords(unsigned char* data, ESMSStrip* strip);
    void ReadColors(unsigned char* data, ESMSStrip* strip);
    void ReadNormalsOld(unsigned char* data, ESMSStrip* strip);
    void ReadNormals(unsigned char* data, ESMSStrip* strip);
    void ReadWeights(unsigned char* data, ESMSStrip* strip, bool flag);
    void OptimizeStripsForMemory(ESubModelShader* source, ESMSStrip* strip,
                                  int count, bool flag);
    void ReadIndices(unsigned char* data, ESMSStrip* strip, unsigned int& offset);
    void Read(unsigned char* data, int version);
    void AllocateMorph();
    void RegisterMorphTarget(ESubModelShader* target, int index);
    void ResetMorph();
    void ApplyMorph();
    void GetMorphedVertex(EVec3& outPos, short vertIdx, short morphIdx);
    void GenerateMorphTargetDeltas(ESubModelShader* baseModel);
    void Morph(float* weights);
    void CreateLatticeList(TArray<BSplineVolume, TArrayERModelAllocator>* lattices);
    void AllocateParameterizeVerts();
    void ParameterizeVerts(TArray<BSplineVolume, TArrayERModelAllocator>* lattices);
    void LatticeDeform();
    void BuildDisplayList(ESMBuildDisplayListData* data);
    void BuildDisplayList(bool flag, char* name, bool flag2, float param1, float param2);
    void GetMinMaxX(float* minX, float* maxX);
    void TransformModelUV(EVec2& offset, EVec2& scale, unsigned int flags,
                           EVec2& pivot, EVec2& tiling, bool flip);
};

// ============================================================================
// Neighbor - Neighborhood resident data
// ============================================================================

class Neighbor {
public:
    // 0x00-0x0F: base data / vtable
    // 0x10: RelMatrix* m_relationships
    // 0x1C: short m_neighborId
    // 0x1E: short m_flags
    // 0x20: short m_personality
    // 0x22: short m_age
    // 0x24: int m_familyId
    // 0x28: StringBuffer m_name  (char* at 0x28, data at 0x30, cap 64)
    // 0x110: Motives m_motives   (at offset 272)
    // 0x194: WantFear::Bookmark* m_bookmarks (at offset 404)

    int m_pad00[4];             // 0x00
    void* m_relationships;      // 0x10
    int m_pad14;                // 0x14
    int m_pad18;                // 0x18
    short m_neighborId;         // 0x1C
    short m_flags;              // 0x1E
    short m_personality;        // 0x20
    short m_age;                // 0x22
    int m_familyId;             // 0x24
    char m_nameBuffer[64];      // 0x28 (StringBuffer inline data)
    // ... gap ...
    Motives m_motives;          // 0x110 (offset 272)
    // ... more data ...
    void* m_bookmarks;          // 0x194 (offset 404)
    char m_wantFearData[28];    // 0x198 (offset 408)

    Neighbor() {
        m_age = 0;
        m_neighborId = 0;
        m_flags = 0;
        m_personality = 0;

        // StringBuffer::StringBuffer(m_nameBuffer + 8, 64)
        // StringBuffer at offset 40, with data at offset 48, capacity 64

        m_motives.Init();

        // Allocate 20 WantFear::Bookmark objects (12 bytes each = 240)
        // m_bookmarks = new WantFear::Bookmark[20]
        // Initialize each bookmark

        m_familyId = 1;

        // RelMatrix::CreateInstance()
        // m_relationships = result

        m_motives.Init(); // called twice in original

        // memset(m_wantFearData, 0, 28)
        memset(m_wantFearData, 0, 28);
    }

    ~Neighbor();
    void operator=(Neighbor& other);

    int GetNumPersistentDataFields();
    void DoStream(ReconBuffer* buffer, int version);
    int GetFamily();
    bool IsCharacter();
    void RecalculateRelationshipData();
    bool RelCountsAsRel(tRelationshipType a, tRelationshipType b);
    int CalculateRelationshipLevel(int dailyVal, int lifetimeVal);
    int CalculateRelationshipLevel(Neighbor* other);
    int CountRelationshipsOfType(tRelationshipType type);
    bool IsMarriedTo(const Neighbor* other) const;
    bool GetRelationshipById(int neighborId, int* outRelLevel);
    void AdjustRelationship(Neighbor* other, int amount);
    void CopyRelationships(Neighbor* source);
    void LoadFromCharacter(ENeighborhoodCustomChar& character);
    void SaveToCharacter(ENeighborhoodCustomChar& character);
    void InitDefaultValues();
    void InitWantsFears();
    void InitWantFearIcons();
    void SpawnWantFearDialog(unsigned int dialogId) const;
    void Notify(int& event, bool flag);
    bool FindDuplicateBookmark(int& bookmark) const;
    void ForceNewTree(unsigned short treeId);
    bool FindActiveSlotIndex(int& slot) const;
    void AdvanceBookmark(unsigned int index);
    int FindBookmarkToReplace(unsigned int type, unsigned int index);
    void CalculateBookmarkAd(int& bookmark);
    float CalcAdMultiplier(float base, float min, float max);
    void CalculateWantFearAd(int& bookmark, short weight);
    void MakeNewActiveBookmark(unsigned int slot);
    void SelectInactiveBookmark(bool wantNotFear, bool force);
    void StartNewTree(unsigned int slot);
    void UpdateUIifNeeded(unsigned int slot, int reason);
    void ResetAllWantsAndFears();
    void ShuffleWantFear(int direction);
};

// ============================================================================
// RoomManager - Manages rooms in the lot
// ============================================================================

class RoomManager {
public:
    // 0x00: list header (STL list of rooms)
    // 0x04: Room** m_roomList (node alloc'd)
    // 0x10: list header (another list)
    // 0x24: float m_outsideAmbient
    // 0x28: int m_flags

    int m_roomListHeader[4];     // 0x00 (STL list sentinel)
    int m_partitionList[4];      // 0x10 (another STL list)
    float m_outsideAmbient;      // 0x20
    int m_pad24;                 // 0x24

    RoomManager() {
        // Initialize two STL lists with sentinel nodes
        // __node_alloc<false, 0>::_M_allocate(24) for room list
        // __node_alloc<false, 0>::_M_allocate(36) for partition list

        // Set default outside ambient level from ROM
    }

    ~RoomManager();

    void RoomScoreChanged(int roomId);
    void RoomLightingChanged(int roomId);
    void AllRoomsLightingChanged();
    void AllRoomsScoreChanged();
    void ComputeRooms();
    void PrintStats();
    Room* GetRoom(unsigned short roomId);
    Room* GetNewRoom(unsigned short roomId);
    void UpdateRooms();
    void OffsetWorld(CTilePt& offset);
    void ProcessDegenerateTile(CTilePt& pos, unsigned short roomId, int flags);
    void ResolveDiagonal(CTilePt& pos, Room** room1, Room** room2,
                          int* val1, int* val2);
    void ResolveDiagonal(CTilePt& pos, unsigned short* room1, unsigned short* room2,
                          int* val1, int* val2);
    void ResetRooms();
    float GetOutsideAmbientLevel();
    void ClearRoomPartitions();
    void ResetRoomManager();
    void SetRoomIntensityScale(int roomId, bool flag, float scale);
    void SetRoomIntensityColorScale(int roomId, bool flag, int color, float scale);
    void ChangeLightingGroup(unsigned short fromGroup, unsigned short toGroup);
};

// ============================================================================
// ObjSelector - Object template/definition selector
// ============================================================================

class ObjSelector {
public:
    // 0x00: int m_pad00
    // 0x04: int m_guid
    // 0x08: int m_subGuid
    // 0x0C: int m_instanceCount
    // 0x10: void* m_userData
    // 0x1C: ObjectDataObjDefinition m_objDef (at offset 28)
    // 0x3C: int m_treeTableId
    // 0x50: int m_flags
    // 0x54: int m_preloadFlags
    // 0x58: void* m_animations[4] (at offset 88)
    // 0x78: int m_masterGuid
    // 0x7C: unsigned int m_groupFlags

    int m_pad00;               // 0x00
    int m_guid;                // 0x04
    int m_subGuid;             // 0x08
    int m_instanceCount;       // 0x0C
    void* m_userData;          // 0x10
    int m_pad14[2];            // 0x14
    // ObjectDataObjDefinition at 0x1C (offset 28)
    char m_objDef[32];         // 0x1C
    int m_treeTableId;         // 0x3C
    int m_pad40[4];            // 0x40
    int m_flags;               // 0x50
    int m_preloadFlags;        // 0x54
    void* m_animations[4];     // 0x58 (at offset 88)
    int m_masterGuid;          // 0x78
    unsigned int m_groupFlags; // 0x7C

    ObjSelector() {
        m_instanceCount = 0;
        m_guid = -1;
        m_subGuid = -1;
        m_userData = nullptr;

        // ObjectDataObjDefinition::ObjectDataObjDefinition() at offset 28

        m_treeTableId = 0;
        m_flags = 0;
        m_preloadFlags = 0;
        m_animations[0] = nullptr;
        m_animations[1] = nullptr;
        m_animations[2] = nullptr;
        m_animations[3] = nullptr;
        m_masterGuid = -1;
        m_groupFlags = 0xFFFF0000;
    }

    ~ObjSelector();

    bool IsPreloaded() const;
    void loadFile();
    int GetEffectiveTreeTableID();
    ObjSelector* GetMasterSelector();
    const char* GetCatalogName();
    const char* GetCatalogDescription();
    const char* GetCatalogShortName();
    BString2* GetUserName();
    void SetUserName(BString2& name);
    BString2* GetUserLastName();
    void SetUserLastName(BString2& name);
    void GetUserFullName(BString2& outName);
    bool GetBigThumbnail(ERShader** outShader);
    bool GetThumbnail(ERShader** outShader);
    void SetThumbnail(ETexture* texture);
    void DestroyThumbnail();
    bool GetHasInteractions();
    int GetInitTreeVersion();
    int GetMainTreeVersion();
    int GetCatalogRating(int category);
    void* GetFnTable();
    void* GetCatalogResource();
    void GetShortFilename(StringBuffer* outName);
    int CountTypeAttributes();
    void* GetTypeAttributes();
    void* GetTreeTable();
    void* GetNormalSimDescription() const;
    void ResetAnimTables();
    void* GetAdultAnimTable();
    void* GetChildAnimTable();
    void* GetAdultToChildAnimTable();
    void* GetChildToAdultAnimTable();
    bool GetIsPerson();
};

// ============================================================================
// SimModel - Sim character model management
// ============================================================================

class SimModel {
public:
    // 0x00: 26 int/ptr fields initialized to 0 (104 bytes)
    // Then additional model part data

    int m_fields[26];  // 0x00 - 0x68 (various model part pointers/state)

    SimModel() {
        // Zero out first 26 fields
        for (int i = 0; i < 26; i++) {
            m_fields[i] = 0;
        }
    }

    ~SimModel();

    void Init(CasSimDescriptionS2C* desc, bool flag);
    void Reset();
    void DeallocateAllModels();
    void DeallocateModelPart(eBodyPartS2C part);
    void DeallocateMorphResources();
    void DeallocateAllSkinTextures();
    void SetSimDescription(CasSimDescriptionS2C* desc);
    void DetachSimDescription();
    SimModel* Clone();
    void SetAllModels();
    void SetModelPart(eBodyPartS2C part, unsigned int modelId);
    void UpdateModelPart(eBodyPartS2C part, bool flag1, bool flag2);
    void UpdateQueuedModelPart(eBodyPartS2C part, bool flag1, bool flag2);
    void ChangeModelPart(eBodyPartS2C part, unsigned int modelId, bool flag1, bool flag2);
    void GetChangedModels(int* outModels);
    void SetModelPartASync(eBodyPartS2C part, unsigned int modelId);
    void FlushLoadingModels();
    void WeldAllSharedVertices();
    void WeldSharedVertices(eBodyPartS2C part1, eBodyPartS2C part2, bool flag);
    void ApplyAllLatticeMorphing();
    void ApplyLatticeMorphingToModelPart(eBodyPartS2C part);
    void ApplyAllMorphTargets();
    void ApplyMorphTargetsToRegion(unsigned int region, unsigned int count,
                                    float weight, unsigned int* indices);
    void CreateSkin(char* name);
    void GetSkinTextureDef(ETextureDef& outDef, bool flag);
    void ApplySkinToModels();
    void ApplySkinToModelPart(eBodyPartS2C part);
    void TransformAllModelUV();
    void TransformModelPartUV(eBodyPartS2C part);
    void GetModelUVTransformParameters(eBodyPartS2C part, EVec2& offset, EVec2& scale,
                                        unsigned int& flags, EVec2& pivot, EVec2& tiling);
    void CompositeAllSkin();
    void CompositeSkinPart(unsigned char partIndex);
    void UpdateReweld(bool flag);
    void UpdateReweldCAS(bool flag);
    void UpdateSimDescriptionIndices(unsigned int* indices);
    void RebuildModified();
    void LoadAllMorphTargets();
    unsigned int GetGameStateModelID(unsigned int partId, bool flag);
    unsigned int GetGameStateTextureID(unsigned int partId, bool flag);
    void UpdateInnerLayerTorso(bool flag1, bool flag2, bool flag3);
    void UpdateInnerLayerSleeve(bool flag1, bool flag2, bool flag3);
    void UpdateMidLayerTorso(bool flag1, bool flag2, bool flag3, bool flag4);
    void UpdateMidLayerSleeve(bool flag1, bool flag2, bool flag3, bool flag4);
    void UpdateMidLayerCollar(bool flag);
    void UpdateOuterLayerTorso(bool flag1, bool flag2, bool flag3, bool flag4);
    void UpdateOuterLayerSleeve(bool flag1, bool flag2, bool flag3, bool flag4);
    void UpdateOuterLayerCollar(bool flag1, bool flag2);
    void UpdateLowerBody(bool flag1, bool flag2);
    void UpdateHair(bool flag1, bool flag2, bool flag3);
    void UpdateHead(bool flag1, bool flag2, bool flag3);
    void UpdateHat(bool flag1, bool flag2, bool flag3);
    void UpdateArmAccessory(bool flag1, bool flag2, bool flag3);
    void UpdateVestScarf(bool flag1, bool flag2, bool flag3);
    void UpdateNecklaceEarring(bool flag1, bool flag2, bool flag3);
    void UpdateBelt(bool flag1, bool flag2, bool flag3);
    void UpdateShoes(bool flag1, bool flag2, bool flag3);
    void UpdateFacialFeature(bool flag1, bool flag2, bool flag3);
    void UpdateGlasses(bool flag1, bool flag2, bool flag3);
    void GetModelName(eBodyPartS2C part, EString& outName);
    void GetTextureName(eBodyPartS2C part, EString& outName);
    void GetTattooTextureName(eTattooTextureTypeS2C type, EString& outName);
};

// ============================================================================
// GameData - Top-level game state management
// ============================================================================

// Forward declare Player helper class
class Player {
public:
    Player();
    void Reset(int playerIndex);
};

class EMemoryMeterWin {
public:
    EMemoryMeterWin();
    ~EMemoryMeterWin();
    void Init();
};

class GameData {
public:
    // 0x00: int m_state
    // 0x04: EMemoryMeterWin m_memMeter (large embedded object, ~156 bytes)
    // 0x2C: various game state fields
    // 0x54-0x78: more state pointers
    // 0xA0: int m_lastState
    // 0xA4: float m_timer1, m_timer2
    // 0xA8: float m_copyrightAlpha
    // 0xE4-0xF4: Player m_players[2] (16 bytes each, at offset 244)

    int m_state;                 // 0x00
    EMemoryMeterWin m_memMeter;  // 0x04
    int m_pad2C[5];              // 0x2C-0x3C (fields 44-76)
    int m_pad40[5];              // 0x40-0x50
    void* m_simController1;      // 0x54 (84)
    int m_pad58[6];              // 0x58-0x6C
    void* m_simController2;      // 0x6C (108)
    void* m_simController3;      // 0x70 (112)
    void* m_simController4;      // 0x74 (116)
    void* m_simController5;      // 0x78 (120)
    int m_pad7C[4];              // 0x7C-0x88
    int m_flags1;                // 0x80 (128)
    int m_flags2;                // 0x84 (132)
    int m_pad88[2];              // 0x88-0x8C
    int m_pad90[4];              // 0x90-0x9C
    int m_lastState;             // 0xA0 (160)
    int m_pad_a4;                // 0xA4 (164)
    int m_pad_a8;                // 0xA8 (168)
    int m_pad_ac[2];             // 0xAC-0xB0
    float m_copyrightAlpha;      // 0xDC (220)
    float m_copyrightBeta;       // 0xE0 (224)
    int m_flags3;                // 0xE4 (228)
    int m_flags4;                // 0xE8 (232)
    int m_flags5;                // 0xEC (236)
    int m_flags6;                // 0xF0 (240)
    Player m_players[2];         // 0xF4 (244) - 2 players

    GameData() {
        m_state = 0;

        // EMemoryMeterWin::EMemoryMeterWin()
        // (handled by member initializer)

        m_lastState = -1;

        // Zero out many state fields
        m_pad2C[0] = 0;  // offset 44
        m_pad2C[1] = 0;  // offset 48
        m_pad2C[2] = 0;  // offset 52
        m_pad40[0] = 0;  // offset 60
        m_pad40[1] = 0;  // offset 64
        m_pad40[2] = 0;  // offset 68
        m_pad40[3] = 0;  // offset 72
        m_pad40[4] = 0;  // offset 76
        m_pad58[0] = 0;  // offset 80

        m_flags1 = 1;    // offset 128
        m_flags2 = 1;    // offset 132

        // Many more zero initializations...
        // Default alpha values from ROM constant
    }

    ~GameData() {
        // Destroy sim controllers (call virtual destructors on each)
        if (m_simController1 != nullptr) {
            // vtable[2/3] -> destroy with delete flag 3
        }
        if (m_simController2 != nullptr) {
            // destroy
        }
        if (m_simController3 != nullptr) {
            // destroy
        }
        if (m_simController4 != nullptr) {
            // destroy
        }

        // EMemoryMeterWin::~EMemoryMeterWin()
        // (handled by member destructor)
    }

    void GamePlayShutdown() {
        // Clear global game pointer
        extern int g_gameActive; // global flag
        g_gameActive = 0;

        // Get neighborhood module via global, call Shutdown
        // NeighborhoodImpl::Unload()
    }

    void GamePlayReset() {
        m_flags3 = 1;     // offset 228
        m_flags4 = 0;     // offset 232
        m_flags6 = 0;     // offset 240
        m_flags2 = 0;     // offset 132

        // Reset global game state pointers
        // Reset both players
        for (int i = 0; i <= 1; i++) {
            m_players[i].Reset(i);
        }

        // EMemoryMeterWin::Init()
        m_memMeter.Init();
    }

    void LoadDefaultNeighborhood();
    void LoadSavedNeighborhood();
    void PrepareSimData(int simIndex, int flags);
    void ReplaceSimData(int simIndex, bool flag, int param1, int param2);
    void SaveCreateASim();
    void PlayerEnterHouse();
    void PrepCreateAFamilyData(int familyIndex);
    void CreateAFamilyAddFamilyMember(Family* family);
    void StoreCreateAFamilyData();
    void SaveCreateAFamily();
    void SystemPreUpdate();
    void SystemPreDraw(ERC* rc);
    void SystemPostDraw(ERC* rc);
    void SetTwoPlayerMode(bool enabled);
    bool IsPlayerConnected(unsigned char playerIndex);
    void CopyrightUpdate(float deltaTime);
    void CopyrightDraw(ERC* rc);
    void VersionInfoDraw(ERC* rc);
    const char* GetLocalizedSims2Logo();
    const char* GetLocalizedEAMovie();
    void SetBlackGraphicsBackgroundColor();
    void SetUglyGraphicsBackgroundColor();
    void StageInitTiming(float* timings, int count);
    void StageStartFrame();
    void StageEndFrame(char* stageName, int param1, int param2);
    void StageEnd(char* name, char* desc, bool flag);
    void GotoXamMode(int mode, int param1, int param2, int param3);
};

// ============================================================================
// ObjectModuleImpl - Manages all game objects in the world
// ============================================================================

class ObjectModuleImpl /* : public Commander */ {
public:
    // 0x00: vtable pointer (ObjectModuleImpl vtable)
    // 0x04: Commander base (offset 4)
    // 0x10: vtable pointer (secondary vtable)
    // 0x14: int m_flags1
    // 0x18: int m_objectCount
    // 0x1C: void* m_objects
    // 0x24: cXObject* m_objectArray[max]  (at offset 36)
    // ... (very large struct, ~8400 bytes)

    void** m_vtable1;           // 0x00
    char m_commander[12];       // 0x04 (Commander base)
    void** m_vtable2;           // 0x10
    int m_flags1;               // 0x14
    int m_objectCount;          // 0x18
    int m_pad1C;                // 0x1C
    int m_pad20;                // 0x20
    int m_objectSlotBase;       // 0x24
    int m_pad28[2];             // 0x28
    int m_pad30;                // 0x2C
    int m_pad34;                // 0x30
    // ... extensive field list continues to ~0x20E0 (8416 bytes)

    ObjectModuleImpl() {
        // Set vtable pointers
        // Commander::Commander() on embedded commander

        // Set secondary vtable pointers

        // Zero out many management fields
        m_flags1 = 0;
        m_objectCount = 0;

        // Initialize multiple linked lists to empty
        // (pairs of head/tail pointers, all set to 0)

        // memset on object array (64 entries * size)
    }

    ~ObjectModuleImpl();

    void Save(iResFile* file);
    void Load(iResFile* file);
    void killDemolishedObjects(iResFile* file);
    void PostLoad(iResFile* file, int version, bool flag);
    void SelectPlayerSims();
    void DoReconObject(ReconBuffer* buffer, cXObjectImpl** obj);
    void DoReconPerson(ReconBuffer* buffer, cXPersonImpl** person);
    void DoStream(ReconBuffer* buffer, int version);
    void Init();
    void LoadGlobalRoutingSlots();
    void Destroy();
    cXObject* GetObjectByGUID(int guid);
    cXPerson* GetPersonByGUID(int guid);
    cXObject* ConstructObject(ObjSelector* selector, cXMTObject* mtObj);
    cXObject* MakeNewOutOfWorldObject(ObjSelector* selector, short* outId);
    void KillOutOfWorldObject(short objectId, bool flag);
    void KillObject(short objectId);
    void KillQueueFlush();
    void PostSim(bool flag);
    void DayChanged();
    void UpdateRooms(int flags);
    void UpdateInteractionInfluences();
    void KillAllObjects();
    void KillObjectsOutsideBounds(int x1, int y1, int x2, int y2);
    void UpdateSimObjects();
    void AddToKillQueue(short objectId, bool flag);
    bool IsFamilyMemberAwakeAndVisible();
    void DoCommand(short objectId, int command);
    void PreviewAnimation(short objectId, short animId, short param, bool flag);
    void ForceAllLocations();
    short GetAnObjectID(short startId);
    void AddObject(cXObject* obj, short id, bool flag);
    void RemoveObject(cXObject* obj);
    void DisableBuyAndBuild(cXObject* obj);
    void EnableBuyAndBuild(cXObject* obj);
    void CheckIntegrity();
    void ClearAwarenessOfObject(cXObject* obj);
    void CleanupPeople(cXObject* obj);
    void BroadcastMessage(char* message, int param);
    void SendMessage(cXObject* obj, char* message, int param);
    void UpdateWallAdjacencies();
    void InvalidateAllRoutes();
    void RelationshipAccessed(Neighbor* n1, Neighbor* n2, int amount, bool flag);
    void OffsetObjectMap(CTilePt& offset);
    void OffsetWorld(CTilePt& offset);
    void SetTutorialObject(cXObject* obj);
    void ShowTutorialInfo();
    void ComputeStats(int* stat1, int* stat2, bool* flag1, bool* flag2, bool* flag3);
    void FillInObjectStats(RoomManager* roomMgr, HouseStats& stats);
    bool IsSelectionSwitchingAllowed();
    bool IsValidObject(cXObject* obj);
    bool IsValidPerson(cXPerson* person);
    void ClearIdleStatus(int simIndex);
    cXObject* GetObjectFromID(int objectId);
    short GetTileObjectID(CTilePt& pos);
    void SetTileObjectID(CTilePt& pos, short objectId);
    void CreateNeighbor(Neighbor* neighbor);
    cXObject* GetObject(int index);
    cXPerson* GetNextPerson(unsigned short startIndex);
    int GetSimMemory(int simIndex, int memType, int param);
    void SetSimMemory(int simIndex, int memType, int param, int value);
    int GetDominantMemory(int simIndex, int memType, int param);
};

// ============================================================================
// ObjectFolderImpl - Manages object definitions/templates
// ============================================================================

class ObjectFolderImpl /* : public Commander */ {
public:
    // Very large struct (~1748 bytes)
    // Contains lists of ObjSelectors, resource files, string buffers

    void** m_vtable1;            // 0x00
    void** m_vtable2;            // 0x04
    char m_commander[12];        // 0x08 (Commander base)
    void** m_vtable3;            // 0x14
    // STL list at offset 0x18 (selectors list 1)
    // STL list at offset 0x28 (selectors list 2)
    int m_selectorCount1;        // 0x38
    int m_selectorCount2;        // 0x3C
    // char data at offset 0x40 (1024 bytes of cached data)
    int m_cachedData[256];       // 0x40
    int m_fileCount;             // 0x440
    StringBuffer m_path1;        // 0x444 (embedded, data at 0x44C, cap 260)
    StringBuffer m_path2;        // 0x550 (embedded, data at 0x558, cap 260)
    int m_flags;                 // 0x65C (offset 1628)
    // More lists and data follow

    ObjectFolderImpl() {
        // Set 3 vtable pointers

        // Commander::Commander() on embedded commander

        // Set more vtable pointers (5640, 5696, 5664 offsets)

        // Initialize two STL lists with sentinel nodes
        // __node_alloc<false, 0>::_M_allocate(24) for each

        m_selectorCount1 = 0;
        m_selectorCount2 = 0;

        // memset(m_cachedData, 0, 1024)

        m_fileCount = 0;

        // StringBuffer::StringBuffer(path1_data, 260)
        // StringBuffer::StringBuffer(path2_data, 260)

        m_flags = 1;

        // More list initializations...
        // ObjectDataObjDefinition::ObjectDataObjDefinition()

        // Allocate STL list node for 72-byte entries
    }

    ~ObjectFolderImpl();

    int CountSelectors();
    ObjSelector* GetSelectorByGUID(int guid);
    ObjSelector* GetNextSelector(ObjSelector* current);
    ObjSelector* GetSubTileSelector(ObjSelector* selector, int x, int y, int z);
    ObjSelector* GetLeadSelector(ObjSelector* selector);
    ObjSelector* GetNthSubSelector(ObjSelector* selector, int n);
    void* GetQueueShaderByGUID(int guid);
    ObjSelector* GetMasterSelector(ObjSelector* selector);
    void Init(char* path, bool flag);
    void Destroy();
    void DestroySelector(ObjSelector* selector);
    void AddUserSelector(int guid, short id);
    unsigned int GetSemiGlobalID(unsigned int id);
    ObjSelector* AddSelector(ObjDefinition* def, char* name, char* path,
                              ResFile* file, short id, int* outResult);
    void OpenResFile(ObjSelector* selector);
    void CloseResFile(ObjSelector* selector);
    void LoadDatabase();
    void ReconSelector(ObjSelector** selector, ReconBuffer* buffer, bool flag, int version);
    ObjSelector* GetSelectorByBehavior(Behavior* behavior);
    void ReconBehavior(Behavior** behavior, ReconBuffer* buffer, int version);
    unsigned int GetPersonGlobNamespaceID();
    void* GetFileByID(unsigned int id);
    void LoadUserData(iResFile* file);
    void SaveUserData(iResFile* file);
    ObjSelector* CreateNewUserSelector();
    void RemoveSelector(ObjSelector* selector);
    void ForceDataPreload(ObjSelector* selector, bool flag);
    void forceDataPreload(ObjSelector* selector, bool flag);
    void CreatingInstance(ObjSelector* selector);
    void PrepareForModuleLoad(iResFile* file);
    void PrepareForModuleSave(iResFile* file);
    void FreeUnusedData();
    void DeleteUserSelectors();
    void DeleteSelectorAnimLists();
    void UnloadData(ObjSelector* selector);
    void DoStream(ReconBuffer* buffer, int version);
    void* GetRumbleByName(char* name);
    void* GetCameraBloomByName(char* name);
    void* GetCameraBlurByName(char* name);
    void GetAnimPreloadList(ChecksumList& list);
    void* GetTreeTable(ObjSelector* selector);
    void LoadResourceByIndex(unsigned int nsId, short type, ObjectDataInterface& data,
                              unsigned int index, unsigned int flags);
    void LoadResourceByID(unsigned int nsId, short type, ObjectDataInterface& data,
                           unsigned int id);
    void SaveResource(unsigned int nsId, short type, StringBuffer& name,
                       ObjectDataInterface& data);
    int GetResourceCount(unsigned int nsId, unsigned int type, unsigned int flags);
    void RemoveResourceByID(unsigned int nsId, short type, unsigned int id);
    void ChangeResourceID(unsigned int nsId, short oldId, short newId, unsigned int flags);
    void GetNamespaceName(unsigned int nsId, StringBuffer& outName);
    void FindUniqueResourceName(unsigned int nsId, unsigned int type, StringBuffer& outName);
    void FindUniqueResourceID(unsigned int nsId, unsigned int type, short& outId);
    void GetStringFromNamespaceID(unsigned int nsId, StringBuffer& outStr,
                                   short param1, short param2);
    void ClearAllCaches();
    ObjSelector* GetNamespaceSelector(unsigned int nsId);
    void FlushNamespaceCaches();
};
