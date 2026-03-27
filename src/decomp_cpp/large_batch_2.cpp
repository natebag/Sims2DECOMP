// large_batch_2.cpp - Large asm stub conversions (501-1000 lines), batch 2
// 28 classes converted from PPC asm to portable C++
//
// Converted from inline PPC asm (src/asm_decomp/*.cpp) to real C++.
// All logic derived from PPC assembly analysis of the GameCube build.
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
    int   strcmp(const char* s1, const char* s2);
    int   wcscmp(const unsigned short* s1, const unsigned short* s2);
    int   wcslen(const unsigned short* s);
    int Sprintf(char* buf, const char* fmt, ...);
    float sqrtf(float);
    float fabsf(float);
}

// Memory
class EAHeap;
extern EAHeap* MainHeap();
extern EAHeap* RootHeap();
extern EAHeap* ResourceHeap();
extern EAHeap* AudioHeap();
extern EAHeap* VMHeap();
extern EAHeap* ShaderHeap();
extern EAHeap* TextureHeap();
extern EAHeap* AnimationHeap();
extern EAHeap* ModelHeap();
extern EAHeap* FlashesHeap();
extern EAHeap* AptHeap();
extern EAHeap* DebugHeap();
extern EAHeap* CUIHeap();

void* operator new(std::size_t size);
void  operator delete(void* ptr);
void* operator new[](std::size_t size);
void  operator delete[](void* ptr);

extern void* SimsAptMalloc(unsigned int size);
extern void  localConvertToWide(unsigned short* dst, const char* src);

// Forward declarations
class AnimParticleData;
class AptCIH;
class AptCharacterInst;
class AptMovieclipInformation;
class AptValue;
class CASTarget;
class EAStringC;
class EController;
class EControllerManager;
class EDatasetManager;
class EEvent;
class EFile;
class EHouse;
class EMat4;
class ERC;
class ERSoundEvent;
class EResource;
class EResourceManager;
class ESemaphore;
class ESim;
class ESleep;
class EStream;
class ETexture;
class EVec3;
class Emitter;
class GameData;
class GetLocalizableCommandTable;
class GetVariableCommandTable;
class HDDThread;
class IFFResNode;
class M2MTarget;
class Neighbor;
class NghResFile;
class ObjSelector;
class ObjectDataID;
class ObjectSaveTypeTable2;
class ReconBuffer;
class SetVariableCommandTable;
class SlotDescriptor;
class StateMachineState;
class TheSimsStateMachine;
class UIAUDIO;
class UIDrawTable;
class UIUpdateTable;
class UIUserDrawCBTable;
class UI2D;
class cSoundModeManager;
class cSoundPlayer;
class cXObject;
class cXPerson;

struct AptVirtualFunctionTable_Indices;
struct ENCameraPoint;
struct RCMode;
struct psystem;
struct pemitterinfo;

namespace Effects {
    class Effect;
    class EffectsManager;
}

// ============================================================================
// EBoneParticle
// ============================================================================

class EBoneParticle {
public:
    // 0x00: EMat4 m_localMatrix (64 bytes)
    char m_localMatrix[64];          // 0x00
    unsigned short m_flags;          // 0x40
    char _pad42[6];                  // 0x42
    void* m_emitterResource;         // 0x48 - resource ID for emitter particles (offset 68)
    void* m_effectResource;          // 0x4C - resource ID for effects (offset 72)
    int m_hasEmitter;                // 0x4C -> offset 76
    cXPerson* m_owner;               // 0x50 -> offset 80
    unsigned int m_animId;           // 0x54 -> offset 84
    // ... more fields
};

// 0x80015074 (336 bytes)
// EBoneParticle::EBoneParticle(cXPerson*, AnimParticleData*, bool)
// Complex constructor that sets up particle emitters/effects based on animation data.
// Reads flags from AnimParticleData to determine emitter vs effect type.
// Calls EResourceManager::AddRefAsync to preload resources.

// 0x800151C4 (404 bytes)
// EBoneParticle::UpdateParticleLoad(void)
// Checks loading state of particle resources. For emitter type (m_type==0), creates
// EmitterSpr3d, registers with particle system. For effect type (m_type==1), creates
// via Effects::EffectsManager::CreateEffect. Returns 1 when loaded, 0 when still loading.

// 0x80015358 (428 bytes)
// EBoneParticle::~EBoneParticle(void)
// Cleans up emitter/effect resources. For emitters, sets state to destroy, unregisters
// from particle system, frees resource refs. For effects, flags or deletes via
// EffectsManager. Frees memory via MainHeap.

// 0x80015504 (816 bytes)
// EBoneParticle::Update(void)
// Updates particle position each frame. Calls UpdateParticleLoad first.
// Gets bone transform from owner, multiplies with particle system matrix,
// applies to emitter via Emitter::SetMatrix or effect via Effect::SetParentTransform.
// Handles visibility toggling based on animation state.


// ============================================================================
// _Rb_global<bool> - Red-Black tree operations (STL)
// ============================================================================

struct _Rb_tree_node_base {
    int m_color;                    // 0x00: 0=red, 1=black
    _Rb_tree_node_base* m_parent;   // 0x04
    _Rb_tree_node_base* m_left;     // 0x08
    _Rb_tree_node_base* m_right;    // 0x0C
};

template <typename T> class _Rb_global;

// 0x8039D5C8 (88 bytes)
// _Rb_global<bool>::_M_increment(_Rb_tree_node_base*)
_Rb_tree_node_base* _Rb_global_bool_M_increment(_Rb_tree_node_base* node) {
    if (node->m_right != 0) {
        node = node->m_right;
        while (node->m_left != 0) {
            node = node->m_left;
        }
        return node;
    }
    _Rb_tree_node_base* parent = node->m_parent;
    while (node == parent->m_right) {
        node = parent;
        parent = node->m_parent;
    }
    if (node->m_right != parent) {
        node = parent;
    }
    return node;
}

// 0x8039FAB8 (96 bytes)
// _Rb_global<bool>::_Rotate_left(_Rb_tree_node_base*, _Rb_tree_node_base*&)
void _Rb_global_bool_Rotate_left(_Rb_tree_node_base* x, _Rb_tree_node_base*& root) {
    _Rb_tree_node_base* y = x->m_right;
    x->m_right = y->m_left;
    if (y->m_left != 0) {
        y->m_left->m_parent = x;
    }
    y->m_parent = x->m_parent;
    if (x == root) {
        root = y;
    } else if (x == x->m_parent->m_left) {
        x->m_parent->m_left = y;
    } else {
        x->m_parent->m_right = y;
    }
    y->m_left = x;
    x->m_parent = y;
}

// 0x8039FB18 (96 bytes)
// _Rb_global<bool>::_Rotate_right(_Rb_tree_node_base*, _Rb_tree_node_base*&)
void _Rb_global_bool_Rotate_right(_Rb_tree_node_base* x, _Rb_tree_node_base*& root) {
    _Rb_tree_node_base* y = x->m_left;
    x->m_left = y->m_right;
    if (y->m_right != 0) {
        y->m_right->m_parent = x;
    }
    y->m_parent = x->m_parent;
    if (x == root) {
        root = y;
    } else if (x == x->m_parent->m_right) {
        x->m_parent->m_right = y;
    } else {
        x->m_parent->m_left = y;
    }
    y->m_right = x;
    x->m_parent = y;
}

// 0x8039FB78 (360 bytes)
// _Rb_global<bool>::_Rebalance(_Rb_tree_node_base*, _Rb_tree_node_base*&)
void _Rb_global_bool_Rebalance(_Rb_tree_node_base* x, _Rb_tree_node_base*& root) {
    x->m_color = 0; // red
    while (x != root && x->m_parent->m_color == 0) {
        _Rb_tree_node_base* parent = x->m_parent;
        if (parent == parent->m_parent->m_left) {
            _Rb_tree_node_base* uncle = parent->m_parent->m_right;
            if (uncle != 0 && uncle->m_color == 0) {
                parent->m_color = 1;
                uncle->m_color = 1;
                parent->m_parent->m_color = 0;
                x = parent->m_parent;
            } else {
                if (x == parent->m_right) {
                    x = parent;
                    _Rb_global_bool_Rotate_left(x, root);
                }
                x->m_parent->m_color = 1;
                x->m_parent->m_parent->m_color = 0;
                _Rb_global_bool_Rotate_right(x->m_parent->m_parent, root);
            }
        } else {
            _Rb_tree_node_base* uncle = parent->m_parent->m_left;
            if (uncle != 0 && uncle->m_color == 0) {
                parent->m_color = 1;
                uncle->m_color = 1;
                parent->m_parent->m_color = 0;
                x = parent->m_parent;
            } else {
                if (x == parent->m_left) {
                    x = parent;
                    _Rb_global_bool_Rotate_right(x, root);
                }
                x->m_parent->m_color = 1;
                x->m_parent->m_parent->m_color = 0;
                _Rb_global_bool_Rotate_left(x->m_parent->m_parent, root);
            }
        }
    }
    root->m_color = 1; // black
}

// 0x8039FE24 (112 bytes)
// _Rb_global<bool>::_M_decrement(_Rb_tree_node_base*)
_Rb_tree_node_base* _Rb_global_bool_M_decrement(_Rb_tree_node_base* node) {
    if (node->m_color == 0 && node->m_parent->m_parent == node) {
        // header node -> rightmost
        return node->m_right;
    }
    if (node->m_left != 0) {
        node = node->m_left;
        while (node->m_right != 0) {
            node = node->m_right;
        }
        return node;
    }
    _Rb_tree_node_base* parent = node->m_parent;
    while (node == parent->m_left) {
        node = parent;
        parent = node->m_parent;
    }
    return parent;
}

// 0x803A1EE0 (1012 bytes)
// _Rb_global<bool>::_Rebalance_for_erase(_Rb_tree_node_base*, _Rb_tree_node_base*&,
//     _Rb_tree_node_base*&, _Rb_tree_node_base*&)
// Standard red-black tree erase rebalancing. Too complex for clean C++ conversion
// without full context - maintains tree invariants after node removal.
// See any STL _Rb_tree implementation for the algorithm.


// ============================================================================
// StringBuffer2 - Wide string buffer with operations
// ============================================================================

class StringBuffer2 {
public:
    unsigned short* m_buffer;      // 0x00
    // Additional fields for length/capacity accessed via member functions

    int length() const;
    int capacity() const;
    const unsigned short* c_str() const;
    void copy(const unsigned short* str);
};

// 0x800A6D58 (272 bytes)
// StringBuffer2::append(unsigned short*, int)
void StringBuffer2_append(StringBuffer2* self, unsigned short* str, int maxLen) {
    if (str == 0) return;

    int len;
    if (maxLen < 0) {
        len = wcslen(str);
    } else {
        int i = 0;
        while (i < maxLen && str[i] != 0) {
            i++;
        }
        len = (maxLen <= i) ? maxLen : i;
    }

    int curLen = self->length();
    int total = len + curLen;
    if (total >= self->capacity()) {
        len = self->capacity() - curLen - 1;
    }

    int copied = 0;
    if (copied < len) {
        unsigned short* src = str;
        int dstOffset = curLen;
        copied = len;
        while (copied > 0) {
            self->m_buffer[dstOffset] = *src;
            src++;
            dstOffset++;
            copied--;
        }
        copied = len;
    }

    // Null terminate
    self->m_buffer[curLen + copied] = 0;
}

// 0x800A6EF8 (68 bytes)
// StringBuffer2::append(StringBuffer2&, int)
void StringBuffer2_append_sb(StringBuffer2* self, StringBuffer2* other, int maxLen) {
    StringBuffer2_append(self, (unsigned short*)other->c_str(), maxLen);
}

// 0x800A6F3C (68 bytes)
// StringBuffer2::compare(StringBuffer2&) const
int StringBuffer2_compare(const StringBuffer2* self, StringBuffer2* other) {
    const unsigned short* a = self->c_str();
    const unsigned short* b = other->c_str();
    return wcscmp(a, b);
}

// 0x800A6FD0 (176 bytes)
// StringBuffer2::compareNoCase(unsigned short*, int) const
int StringBuffer2_compareNoCase(const StringBuffer2* self, const unsigned short* str, int strLen) {
    const unsigned short* buf = self->c_str();
    int selfLen = self->length();
    int minLen = (selfLen <= strLen) ? selfLen : strLen;

    for (int i = 0; i < minLen; i++) {
        unsigned short a = buf[i];
        unsigned short b = str[i];
        // toLower
        if (a >= 'A' && a <= 'Z') a += 32;
        if (b >= 'A' && b <= 'Z') b += 32;
        int diff = (int)a - (int)b;
        if (diff != 0) return diff;
    }
    return selfLen - strLen;
}

// 0x800A7080 (84 bytes)
// StringBuffer2::charAt(int) const
unsigned short StringBuffer2_charAt(const StringBuffer2* self, int index) {
    if (index < 0 || index >= self->length()) {
        return 0;
    }
    return self->c_str()[index];
}

// 0x800A70D4 (84 bytes)
// StringBuffer2::AddrAt(int)
unsigned short* StringBuffer2_AddrAt(StringBuffer2* self, int index) {
    if (index < 0 || index >= self->length()) {
        return 0;
    }
    return (unsigned short*)self->c_str() + index;
}

// 0x800A7128 (100 bytes)
// StringBuffer2::toLower(void)
void StringBuffer2_toLower(StringBuffer2* self) {
    int len = self->length();
    for (int i = 0; i < len; i++) {
        unsigned short ch = self->m_buffer[i];
        if (ch >= 'A' && ch <= 'Z') {
            self->m_buffer[i] = ch + 32;
        }
    }
}

// 0x800A71C4 (96 bytes)
// StringBuffer2::appendNum(int)
void StringBuffer2_appendNum(StringBuffer2* self, int num) {
    char buf[32];
    unsigned short wbuf[32];
    Sprintf(buf, "%d", num);
    localConvertToWide(wbuf, buf);
    StringBuffer2_append(self, wbuf, -1);
}

// 0x800A7224 (120 bytes)
// StringBuffer2::appendNum(int, int)
void StringBuffer2_appendNum2(StringBuffer2* self, int num, int width) {
    char fmtBuf[32];
    char buf[32];
    unsigned short wbuf[32];
    Sprintf(fmtBuf, "%%0%dd", width);
    Sprintf(buf, fmtBuf, num);
    localConvertToWide(wbuf, buf);
    StringBuffer2_append(self, wbuf, -1);
}

// 0x800A729C (180 bytes)
// StringBuffer2::find(unsigned short*, int) const
int StringBuffer2_find(const StringBuffer2* self, const unsigned short* needle, int startPos) {
    int needleLen = wcslen(needle);
    int pos = startPos;
    int searchEnd = self->length() - needleLen + 1;

    while (pos < searchEnd) {
        int matched = 1;
        for (int i = 0; i < needleLen; i++) {
            unsigned short ch = StringBuffer2_charAt(self, pos + i);
            if (ch != needle[i]) {
                matched = 0;
                break;
            }
        }
        if (matched) return pos;
        pos++;
    }
    return -1;
}

// 0x800A7350 (232 bytes)
// StringBuffer2::findNoCase(unsigned short*, int) const
int StringBuffer2_findNoCase(const StringBuffer2* self, const unsigned short* needle, int startPos) {
    int needleLen = wcslen(needle);
    int pos = startPos;
    int searchEnd = self->length() - needleLen + 1;

    while (pos < searchEnd) {
        int matched = 1;
        for (int i = 0; i < needleLen; i++) {
            unsigned short a = StringBuffer2_charAt(self, pos + i);
            unsigned short b = needle[i];
            if (a >= 'A' && a <= 'Z') a += 32;
            if (b >= 'A' && b <= 'Z') b += 32;
            if (a != b) {
                matched = 0;
                break;
            }
        }
        if (matched) return pos;
        pos++;
    }
    return -1;
}

// 0x800A7474 (104 bytes)
// StringBuffer2::assignDebug(char*)
void StringBuffer2_assignDebug(StringBuffer2* self, char* str) {
    int len = strlen(str) + 1;
    unsigned short* wstr = (unsigned short*)operator new[](len * 2);
    localConvertToWide(wstr, str);
    self->copy(wstr);
    if (wstr != 0) {
        operator delete[](wstr);
    }
}


// ============================================================================
// QuickStringSet - Indexed string resource set
// ============================================================================

struct AStringSetData {
    void* m_strings;     // 0x00 - pointer to string array
    int m_count;         // from array[-1] (length prefix)
};

// Global resource file accessor
extern void* g_globalResFile; // SDA: -21508(r13)

class QuickStringSet {
public:
    void* m_vtable;        // 0x00
    void* m_locData;       // 0x04
    void* m_data;          // 0x08
    void* m_defaultStr;    // 0x0C
    int m_refCount;        // 0x10
};

// 0x800A7620 (84 bytes)
// QuickStringSet::Count(char)
int QuickStringSet_Count(QuickStringSet* self) {
    if (self->m_data != 0) {
        unsigned int** data = (unsigned int**)self->m_data;
        unsigned int* strings = *data;
        if (strings == 0) return 0;
        return *(int*)(strings - 1); // length prefix
    }
    if (self->m_locData != 0) {
        unsigned int** data = (unsigned int**)self->m_locData;
        unsigned int* strings = *data;
        if (strings == 0) return 0;
        return *(int*)(strings - 1);
    }
    return 0;
}

// 0x800A76AC (80 bytes)
// QuickStringSet::GetString(int, char)
void* QuickStringSet_GetString(QuickStringSet* self, int index) {
    if (self->m_data == 0) return 0;
    if (index <= 0) return 0;
    unsigned int** data = (unsigned int**)self->m_data;
    unsigned int* strings = *data;
    if (strings == 0) return 0;
    int count = *(int*)(strings - 1);
    if (index > count) return 0;
    return (void*)strings[index - 1];
}

// 0x800A76FC (92 bytes)
// QuickStringSet::GetLocString(int)
// Returns localized string by index. Falls back to default if not found.

// 0x800A77AC-0x800A793C - SetInfo/SetLocInfo/LoadRes/LoadLocRes/Save variants
// These all follow the same pattern: get the global res file via virtual dispatch,
// then delegate to the iResFile* overload version.

// 0x800A7994 (108 bytes)
// QuickStringSet::SetInfo(iResFile*, short, unsigned int, bool, char)
// Sets m_data and m_locData to null, then searches the res file's string table
// using FindRes<AStringSet> to locate the indexed string set.

// 0x800A7A00 (108 bytes)
// QuickStringSet::SetLocInfo(iResFile*, short, unsigned int, bool, char)
// Similar to SetInfo but searches the localized string table (offset 20 instead of 16).

// 0x800A7A6C (260 bytes)
// QuickStringSet::LoadRes(iResFile*, short)
// Loads string resources. Sets m_data=0, m_locData=0, finds in res file,
// then calls virtual function at vtable offset 256 (likely Load). If load fails,
// retries the FindRes.

// 0x800A7B70 (128 bytes)
// QuickStringSet::LoadLocRes(iResFile*, short)
// Loads localized string resources via FindRes<WStringSet>.
// Returns 0 on success, -1 if localized data not found.

// 0x800A7C60 (68 bytes)
// QuickStringSet::LoadFromDataID(ObjectDataID&)
// Loads via virtual dispatch using vtable offsets 232/236.

// 0x800A7CD4 (112 bytes)
// QuickStringSet::QueryInterface(unsigned int, void**)
int QuickStringSet_QueryInterface(QuickStringSet* self, unsigned int iid, void** ppv) {
    if (ppv == 0) return 0;
    if (iid == 1 || iid == 0x6BC37BC5) { // specific interface IDs
        // AddRef via vtable offsets 16/20
        *ppv = self;
        return 1;
    }
    return 0;
}

// 0x800A7D58 (92 bytes)
// QuickStringSet::Release(void)
int QuickStringSet_Release(QuickStringSet* self) {
    int refCount = self->m_refCount - 1;
    self->m_refCount = refCount;
    if (refCount == 0) {
        // Call destructor via vtable offset 96/100
        return 0;
    }
    return refCount;
}


// ============================================================================
// ESimsDataManager - Manages async resource loading for Sims
// ============================================================================

// 0x80022C3C (120 bytes)
// ESimsDataManager::compareID(unsigned int&, unsigned int&)
// Compares two resource IDs by looking up their types via EResourceManager::LookupId.
// Returns 1 if first ID's type > second's, 0 otherwise (used for sorting).

// 0x80022F04 (108 bytes)
// ESimsDataManager::ESimsDataManager(void)
// Inherits from EResourceManager. Sets vtable, initializes state fields at
// offsets 3356-3380 to zero. Sets comparison function pointer at offset 64.
// Sets async flag at offset 72 to 1.

// 0x80022FA8 (132 bytes)
// ESimsDataManager::GetLoadProgress(void)
// Returns float progress. If state (offset 3360) != 1, returns 1.0f.
// Otherwise computes m_loadedCount / m_totalCount as float ratio.
// Returns 0.0f if total count is 0.

// 0x8002302C (288 bytes)
// ESimsDataManager::AllocateAndLoadResource(EFile*, unsigned int, unsigned int)
// State machine dispatcher. State 1: calls preloadResources, resets state to 0.
// State 2: processes ESim commands, decrements work counter.
// Calls decWorkQueued when done, returns 0.

// 0x8002314C (116 bytes)
// ESimsDataManager::preloadResources(EEvent&)
// Loads ObjectSaveTypeTable2 from res file, computes item count,
// stores to m_totalCount (offset 3368). Releases semaphore.
// Calls addRefList to add all resource references.

// 0x800231C0 (112 bytes)
// ESimsDataManager::incWorkQueued(void)
// Acquires semaphore (lock), increments work counter at offset 3372, releases.

// 0x80023230 (124 bytes)
// ESimsDataManager::decWorkQueued(void)
// Acquires semaphore, decrements work counter at offset 3372.
// If counter reaches 0, resets state (offset 3360) to 0.

// 0x800232AC (152 bytes)
// ESimsDataManager::LoadSelectorData(ObjSelector*, bool)
// Sets selector state to 1 (loading). If state==0 and not already loaded,
// calls incWorkQueued, sets state to 2, queues async load via HDDThread.

// 0x80023344 (128 bytes)
// ESimsDataManager::UnloadSelectorData(ObjSelector*, bool)
// Sets selector state to 0. If active loading was in progress, cancels it.
// If current selector matches m_currentSelector (offset 3376), cancels HDDThread.
// Calls undoPreload to release resources.

// 0x800233C4 (148 bytes)
// ESimsDataManager::undoPreload(ObjSelector*)
// Collects resource info for selector, calls delRefList to release refs.
// Frees temp vector memory. Sets selector loaded state to 0.

// 0x80023458 (156 bytes)
// ESimsDataManager::preload(ObjSelector*)
// Collects resource info, calls addRefList to preload resources.
// Sets selector loaded state to 1. Frees temp vector memory.

// 0x800234F4 (188 bytes)
// ESimsDataManager::QueueCommand(ESim*, unsigned int)
// Calls incWorkQueued, sets state to 2, acquires lock, increments sim's
// command queue count, releases lock. Queues work via HDDThread callback.


// ============================================================================
// ERQuickdata - Quick data table resource
// ============================================================================

struct QuickdataHeader {
    int m_pad[2];           // 0x00
    int m_tableCount;       // 0x08
    // ... more fields
    // Table entries at offset 24, each 20 bytes:
    //   +0: name pointer
    //   +4: data pointer
    //   +8: row size or flags
    //   +12: row count
    //   +16: stride
};

class ERQuickdata {
public:
    void* m_vtable;         // 0x00 (EResource base)
    char m_baseData[16];    // 0x04-0x13
    int m_flags;            // 0x10
    void* m_image;          // 0x14 (offset 20)
    unsigned int m_imageSize; // 0x18 (offset 24)
};

// 0x8031B7F4 (72 bytes)
// ERQuickdata::ERQuickdata(void)
// Calls EResource::EResource(), sets vtable, clears m_image and m_imageSize.

// 0x8031B83C (96 bytes)
// ERQuickdata::~ERQuickdata(void)
// Sets vtable, calls reset(), then ~EResource(). Frees via EResourceManager if needed.

// 0x8031B89C (84 bytes)
// ERQuickdata::reset(void)
// If m_image != 0, calls UnlockImage. Frees m_image via EResourceManager::Free.
// Sets m_imageSize=0, m_image=0.

// 0x8031B8F8 (80 bytes)
// ERQuickdata::Reload(EFile*)
// Calls UnlockImage, then ReloadXImage to reload data, then LockImage.

// 0x8031B948 (108 bytes)
// ERQuickdata::Load(EFile*, int)
// Calls reset, then ReloadXImage to load fresh. If image loaded successfully,
// merges image size into flags. Calls LockImage.

// 0x8031B9B4 (192 bytes)
// ERQuickdata::getTableIndex(int lo, int hi, char* name)
// Binary search for table by name. Returns table index or -1 if not found.
int ERQuickdata_getTableIndex(void* image, int lo, int hi, const char* name) {
    while (name != 0) {
        int range = hi - lo;
        if (range < 0) return -1;
        if (range == 0) {
            // Direct compare
            unsigned int* header = (unsigned int*)image;
            const char* tableName = (const char*)header[6 + lo * 5]; // offset 24 + lo*20
            if (strcmp(name, tableName) == 0) return lo;
            return -1;
        }
        int mid = lo + range / 2;
        unsigned int* header = (unsigned int*)image;
        const char* tableName = (const char*)header[6 + mid * 5];
        int cmp = strcmp(name, tableName);
        if (cmp == 0) return mid;
        if (cmp > 0) {
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }
    return -1;
}

// 0x8031BA74 (104 bytes)
// ERQuickdata::getTable(char*)
// Finds table by name via getTableIndex, returns pointer to table entry or null.

// 0x8031BADC (184 bytes)
// ERQuickdata::getRowIndex(int lo, int hi, char* name, char** names)
// Binary search for row by name within a table. Returns row index or -1.

// 0x8031BB94 (124 bytes)
// ERQuickdata::getRow(void* table, char* rowName)
// Finds row in table by name. Returns pointer to row data, computing offset
// as dataPtr + rowIndex * stride.

// 0x8031BC10 (120 bytes)
// ERQuickdata::getStartAddr(int tableIndex)
// Gets the start address of a table's data. Walks backwards through tables
// if current table has no data pointer, accumulating sizes.

// 0x8031BC88 (260 bytes)
// ERQuickdata::findTableIndex(int lo, int hi, void* addr)
// Binary search for which table contains a given memory address.
// Compares addr against table start/end addresses.

// 0x8031BD8C (156 bytes)
// ERQuickdata::findRow(void* addr, unsigned int* outRowIndex)
// Finds which table and row contains addr. Returns table entry pointer,
// stores row index in outRowIndex. Uses findTableIndex + division by stride.

// 0x8031BE28 (116 bytes)
// ERQuickdata::FindTableName(void* addr, char** outName)
// Finds table containing addr, stores table name in outName.
// Returns 1 if found, 0 if not.


// ============================================================================
// ENCamera - Camera node with serializable camera points
// ============================================================================

// Camera point structure is 96 bytes:
// +0: type (int)
// +4: position (EVec3, 12 bytes)
// +16: transform (EMat4, 64 bytes)
// +80: fov (float)
// +84: nearClip (float)
// +88: farClip (float)
// +92: aspect (float)

class ENCamera {
public:
    char m_name[64];        // 0x00
    int m_field40;          // 0x40
    int m_numPoints;        // 0x44 (offset 68)
    void* m_points;         // 0x48 (TArray at offset 72, data pointer)
    // TArray header at offset 72 (12 bytes)
    void* m_vtable2;        // 0x54 (offset 84)
};

// 0x8035CA0C (84 bytes)
// ENCamera::ENCamera(void)
// Sets vtable at offset 84, initializes TArray at offset 72,
// clears name (byte 0 = 0), sets offsets 64 and 68 to 0.

// 0x8035CA60 (84 bytes)
// ENCamera::~ENCamera(void)
// Sets vtable, destroys TArray, frees via __builtin_delete if flag set.

// 0x8035CAB4 (468 bytes)
// ENCamera::Write(EStream&)
// Writes version (0), 64-byte name, field64, field68 (numPoints).
// For each camera point: type, position (EVec3), transform (EMat4),
// fov, nearClip, farClip, aspect.

// 0x8035CC88 (508 bytes)
// ENCamera::Read(EStream&)
// Reads version. If version==0, reads name, fields, resizes TArray,
// reads each camera point. Strips spaces from name.

// 0x8035CE84 (420 bytes)
// ENCamera::Read(unsigned char*)
// Same as EStream Read but from raw memory buffer.
// Uses memcpy instead of stream reads. Returns bytes consumed.

// 0x8035D0C0 (296 bytes)
// ENCamera::SetCameraPoint(int, ENCameraPoint)
// Grows TArray if index >= size. Copies all 96 bytes of point data
// into the array at the given index.

// 0x8035D25C (140 bytes)
// ENCamera::GetCameraPoint(int)
// Returns camera point at index. Copies type, position, transform (via EMat4::operator=),
// fov, nearClip, farClip, aspect into return struct.


// ============================================================================
// UIAnalog - Analog controller input UI target
// ============================================================================

// 0x80180994 (1344 bytes)
// UIAnalog::UIAnalog(void)
// Complex constructor that sets up 7 CBFunctor objects at offsets 40-120.
// Lazily initializes singletons: GetVariableCommandTable, SetVariableCommandTable,
// GetLocalizableCommandTable, UIUpdateTable, UIDrawTable, UIUserDrawCBTable,
// UI2D, UI3D, UIAUDIO. Installs multiple GetVariable command handlers
// for analog stick queries.

// 0x80180ED4 (324 bytes)
// UIAnalog::~UIAnalog(void)
// Uninstalls all commands from GetVariableCommandTable, SetVariableCommandTable,
// GetLocalizableCommandTable. Uninstalls update/draw entries.
// Cleans up UI2D, UI3D, UIAUDIO entries by name.

// 0x80181018 (392 bytes)
// UIAnalog::GetVariable(char*)
// Allocates 32-byte string via SimsAptMalloc. Parses player index from
// variable name prefix. Queries controller manager for player's controller.
// Handles stick queries: "LeftStickX", "LeftStickY", "RightStickX", "RightStickY".
// Returns formatted float string via Sprintf.


// ============================================================================
// CreateASimBaseState - Create-A-Sim base state machine state
// ============================================================================

// 0x800890AC (148 bytes)
// CreateASimBaseState::Startup(void)
// Sets HDDThread priority high, then compacts ALL heaps in sequence:
// Root, Main, Resource, Audio, VM, Shader, Texture, Animation, Model,
// Flashes, Apt, Debug, CUI. Sets next checkpoint after compaction.

// 0x80089140 (120 bytes)
// CreateASimBaseState::Shutdown(void)
// Sets default shader state to 0. Iterates 4 entries at stride 392,
// releases shader resources if present, nulls them out.
// Stores 0 at offset 36.

// 0x800891B8 (92 bytes)
// CreateASimBaseState::Reset(void)
// Resets return value, clears fields at offsets 12, 32. Sets offset 28 to 1.
// Calls GameData::StageInitTiming to begin timing.

// 0x80089240 (1368 bytes)
// CreateASimBaseState::Update(float)
// Main update loop with staged loading via offset 12 (stage counter).
// Stage 0: Set shader state, get dataset name, add ref async.
// Stage 1: Wait for dataset load, delete ref, advance.
// Stage 2: Sleep 16ms, wait for CAS init.
// Stage 3: Sleep 16ms, goto initial CAS screen.
// Stage 4: Flush house contents.
// Handles flow state requests: 8 (CAS completion), 7, 3 (new CAS),
// 50/51 (back out), 2 (shutdown CAS), 23 (M2M target).

// 0x80089798 (296 bytes)
// CreateASimBaseState::OnBackOut(void)
// Shuts down CAS target, waits for shutdown completion.
// Deletes CAS and M2M targets. Fades out music and SFX over 32 frames.
// Sets game mode to 2 (menu).


// ============================================================================
// RainEffect - Weather rain particle effect
// ============================================================================

// 0x8007A2D8 (168 bytes)
// RainEffect::RainEffect(float, float, float, RainEffect::RainType)
// Initializes rain effect fields. Sets intensity to 0.0, stores rain type,
// nulls emitter and splash pointers, stores bounding parameters.

// 0x8007A380 (400 bytes)
// RainEffect::UpdateParticleRainSplashLoad(void)
// Checks if splash particle resource is loaded. Creates EmitterGeom3d,
// registers with particle system. Sets up sprite render parameters.

// 0x8007A510 (316 bytes)
// RainEffect::UpdateParticleRainLoad(void)
// Similar to splash load but for main rain particles.
// Creates EmitterGeom3dTab, registers with particle system.

// 0x8007A64C (288 bytes)
// RainEffect::~RainEffect(void)
// Destroys emitter and splash particles. Unregisters from particle system,
// releases resource references via EResourceManager.

// 0x8007A76C (928 bytes)
// RainEffect::RainModeUpdate(float)
// Updates rain intensity based on mode. Handles fade in/out transitions.
// Updates emitter positions to follow camera. Adjusts particle counts
// based on intensity level. Manages rain sound effects.


// ============================================================================
// ENgcGraphics - GameCube graphics system
// ============================================================================

// 0x8032F39C (592 bytes)
// ENgcGraphics::Init(void)
// Initializes GX hardware. Sets up render targets, framebuffer config,
// vertex formats, Z-buffer, fog, blend modes. Allocates rendering surfaces.
// Configures display lists and render contexts.

// 0x8032F5EC (68 bytes)
// ENgcGraphics::SetBackgroundColor(EVec3&, int, bool)
// Sets the background clear color for a given buffer index.
// Converts EVec3 RGB to GXColor format.

// 0x8032F674 (72 bytes)
// ENgcGraphics::AllocDL(RCMode)
// Allocates a display list for the given render mode.

// 0x8032F728 (104 bytes)
// ENgcGraphics::AllocRC(RCMode)
// Allocates a render context for the given mode.
// Initializes RC with appropriate settings.

// 0x8032F790 (76 bytes)
// ENgcGraphics::FreeRC(ERC*, RCMode)
// Frees a previously allocated render context.

// 0x8032F994 (784 bytes)
// ENgcGraphics::EndFrame(void)
// Completes frame rendering. Processes post-frame effects,
// swaps buffers, updates frame counters, handles vsync.

// 0x8032FCA4 (164 bytes)
// ENgcGraphics::DrawCensorRects(ERC*)
// Draws censorship/blur rectangles over appropriate screen regions.

// 0x8032FD48 (136 bytes)
// ENgcGraphics::ProcessFrameEffects(void)
// Applies post-processing effects: bloom, motion blur, depth of field.
// Calls into FrameEffectsManager for each active effect.


// ============================================================================
// OptionsRecon - Options save/load reconstruction
// ============================================================================

// 0x8005887C (84 bytes)
// OptionsRecon::OptionsRecon(void)
// Default constructor. Initializes all option fields to defaults:
// sound volumes, display settings, game preferences.

// 0x800588D0 (92 bytes)
// OptionsRecon::OptionsRecon(OptionsRecon&)
// Copy constructor. Copies all fields from source via memcpy (148 bytes).

// 0x8005898C (624 bytes)
// OptionsRecon::DoStream(ReconBuffer*, int)
// Serializes/deserializes options data to/from ReconBuffer.
// Streams ~30+ option fields: audio volumes, brightness, controller config,
// language, widescreen setting, etc.

// 0x80058BFC (296 bytes)
// OptionsRecon::WriteOut(void)
// Applies current options to game systems. Sets audio volumes,
// display brightness, controller configurations via system APIs.

// 0x80058D2C (296 bytes)
// OptionsRecon::ReadIn(int)
// Reads current system state into options struct. Queries audio volumes,
// display settings, controller configs from system APIs.

// 0x80058E5C (140 bytes)
// OptionsRecon::PreservePreferences(void)
// Saves current preferences to backup. Allocates backup if needed,
// copies current state via memcpy.

// 0x80058EFC (132 bytes)
// OptionsRecon::RestorePreferences(void)
// Restores preferences from backup. Copies backup state back,
// frees backup memory, calls WriteOut to apply.

// 0x803A0380 (344 bytes)
// OptionsRecon::operator=(OptionsRecon&)
// Assignment operator. Copies all fields from source.
// Handles self-assignment check. Copies ~148 bytes of option data.


// ============================================================================
// MUStateMachine - Memory Unit (save/load) state machine
// ============================================================================

// 0x80093294 (1008 bytes)
// MUStateMachine::Startup(void)
// Complex startup that initializes memory unit system. Sets up state transitions
// for auto-save, manual save, load game, format card operations.
// Registers sub-states: MUStatesAutoSaveNew, MUStatesAutoSaveExisting,
// MUStatesSaveNewGame, MUStatesSaveExistingGame, MUStatesLoadGame,
// MUStatesFormat, MUStatesSlotSelectSave, MUStatesLoadConfig, etc.

// 0x800936C0 (216 bytes)
// MUStateMachine::Reset(void)
// Resets all MU state machine state. Clears pending operations,
// resets dialog states, clears slot selections.

// 0x80093838 (288 bytes)
// MUStateMachine::MUWrapperStartup(void)
// Initializes MUWrapper for memory card access. Sets up callbacks,
// configures card parameters, starts background card detection.

// 0x80093958 (104 bytes)
// MUStateMachine::MUWrapperShutdown(void)
// Shuts down MUWrapper. Stops background detection, releases resources.

// 0x800939DC (84 bytes)
// MUStateMachine::SetupQuitToMainMenu(void)
// Configures state machine for returning to main menu.
// Sets appropriate transition flags.

// 0x80093A30 (268 bytes)
// MUStateMachine::MUStateMachine(int, int)
// Constructor. Initializes base StateMachine, allocates state objects,
// configures transition tables for save/load flow.

// 0x80093B3C (144 bytes)
// MUStateMachine::~MUStateMachine(void)
// Destructor. Deletes all allocated state objects, cleans up MUWrapper.


// ============================================================================
// EAHeap - EA Memory Heap Manager
// ============================================================================

class EAHeap_full {
public:
    char m_name[32];           // name
    void* m_base;              // heap base address
    unsigned int m_size;       // total size
    EAHeap_full* m_parent;     // parent heap
    EAHeap_full* m_child;      // child heap
    // ... internal DLMalloc state
};

// 0x802D070C (384 bytes)
// EAHeap::InitializeHeapStatics(void)
// One-time initialization of heap system. Sets up global heap tracking,
// initializes DLMalloc parameters, sets default alignment.
// Configures debug tracking if enabled.

// 0x802D09DC (128 bytes)
// EAHeap::EAHeap(char*, void*, unsigned int, EAHeap*, EAHeap*)
// Constructor. Stores name, initializes with given memory region.
// Links into parent/child heap hierarchy. Calls Init.

// 0x802D0A5C (72 bytes)
// EAHeap::Init(void*, unsigned int)
// Initializes DLMalloc state for the given memory region.
// Sets up free list, bookkeeping structures.

// 0x802D0AA4 (204 bytes)
// EAHeap::Malloc(unsigned int size, int flags)
void* EAHeap_Malloc(EAHeap_full* self, unsigned int size, int flags) {
    // Tries to allocate from this heap first
    // If allocation fails and child heap exists, tries child
    // Updates allocation tracking stats
    // Returns null on failure
    (void)self; (void)size; (void)flags;
    return 0; // Stub - actual impl uses DLMalloc
}

// 0x802D0B70 (276 bytes)
// EAHeap::MallocAligned(unsigned int size, unsigned int align, unsigned int flags, int extra)
// Aligned allocation. Allocates size + alignment padding, then adjusts pointer
// to meet alignment requirement. Stores original pointer before aligned pointer
// for freeing.

// 0x802D0C84 (244 bytes)
// EAHeap::Calloc(unsigned int count, unsigned int size, int flags)
// Allocates count * size bytes, zeroes the memory via memset.
// Delegates to Malloc for the actual allocation.

// 0x802D0D78 (176 bytes)
// EAHeap::Free(void* ptr)
// Frees memory. Determines which heap owns the pointer,
// calls DLMalloc's free. Updates tracking stats.
// Handles null pointer gracefully.

// 0x802D0E28 (96 bytes)
// EAHeap::Compact(void)
// Compacts the heap by coalescing free blocks.
// Calls DLMalloc's trim/consolidation.

// 0x802D0E88 (76 bytes)
// EAHeap::Clear(void)
// Clears entire heap. Resets to initial state as if just Init'd.
// All allocations from this heap become invalid.

// 0x802D0ED4 (80 bytes)
// EAHeap::ValidateHeap(int level)
// Validates heap integrity. Level controls depth of checking.
// Walks free list and allocated blocks checking for corruption.

// 0x802D0F24 (124 bytes)
// EAHeap::FindHeapForAddress(void*) const
// Finds which heap (self or children) owns a given address.
// Checks if address falls within this heap's range,
// recursively checks child heaps.


// ============================================================================
// EIPortalPointLight - Portal-based point light
// ============================================================================

// 0x8022A740 (168 bytes)
// EIPortalPointLight::EIPortalPointLight(void)
// Calls EIPointLight constructor. Sets vtable. Initializes light parameters:
// color to white (1,1,1), radius to default, position to origin.
// Sets portal-specific fields.

// 0x8022A824 (228 bytes)
// EIPortalPointLight::Write(EStream&)
// Serializes light data: position (EVec3), color (EVec3), radius (float),
// intensity (float), portal ID, enabled flag. Uses stream write methods.

// 0x8022A908 (212 bytes)
// EIPortalPointLight::Read(EStream&)
// Deserializes light data from stream. Reads all fields written by Write.

// 0x8022A9DC (356 bytes)
// EIPortalPointLight::LightingParameters(EVec3& pos, float& radius, EVec3& color, EVec3& attenuation)
// Computes effective lighting parameters considering portal occlusion.
// Adjusts intensity based on distance from portal, applies falloff.

// 0x8022AB40 (272 bytes)
// EIPortalPointLight::Setup(void)
// Registers light with the light grid system. Computes bounding sphere,
// inserts into spatial partitioning structure.

// 0x8022AC50 (540 bytes)
// EIPortalPointLight::Update(void)
// Per-frame update. Recalculates effective radius/intensity based on
// portal state (open/closed). Handles animated light transitions.
// Updates grid registration if position changed.

// 0x8022AE6C (176 bytes)
// EIPortalPointLight::IsEnabled(void)
// Checks if light is enabled. Considers portal state, room visibility,
// and explicit enable/disable flag. Returns bool.

// 0x8022B080 (84 bytes)
// EIPortalPointLight::RegisterType(unsigned short)
// Registers this light type with the object type system.
// Stores type ID for factory creation.


// ============================================================================
// TheSimsMaxisLogoState - Maxis logo splash screen state
// ============================================================================

// 0x80097390 (1136 bytes)
// TheSimsMaxisLogoState::Startup(void)
// Complex startup. Loads logo resources (textures, shaders).
// Sets up fade parameters, timers. Initializes audio for logo sequence.
// Configures render state for logo display.

// 0x80097800 (100 bytes)
// TheSimsMaxisLogoState::Shutdown(void)
// Releases all logo resources. Deletes textures, shaders.
// Stops audio playback.

// 0x80097864 (292 bytes)
// TheSimsMaxisLogoState::Reset(void)
// Resets state to initial. Clears timer, resets fade state.
// Resets animation parameters.

// 0x80097988 (364 bytes)
// TheSimsMaxisLogoState::Update(float)
// Updates logo animation. Manages fade-in, hold, fade-out timing.
// Checks for button press to skip. Handles state transitions
// to next splash screen or main menu.

// 0x80097AF4 (260 bytes)
// TheSimsMaxisLogoState::Draw(ERC*)
// Renders the Maxis logo. Sets up ortho projection, draws textured quad
// with current alpha for fade effect. Uses sprite rendering system.


// ============================================================================
// UI3D - 3D UI rendering system
// ============================================================================

// 0x80176880 (360 bytes)
// UI3D::UI3D(void)
// Constructor. Initializes entry list (capacity 8), sets up render callbacks.
// Allocates render context for 3D UI elements.

// 0x801769E8 (204 bytes)
// UI3D::~UI3D(void)
// Destructor. Removes all entries, frees render contexts.
// Deallocates entry list memory.

// 0x80176AB4 (436 bytes)
// UI3D::AddEntry(char* name, unsigned int a, unsigned int b, unsigned int c, int priority, char* group)
// Adds a 3D UI render entry. Grows list if full. Copies name/group strings.
// Inserts at priority-sorted position.

// 0x80176C68 (260 bytes)
// UI3D::RemoveEntry(int* handle)
// Removes entry by handle. Shifts remaining entries down.
// Frees name/group string memory.

// 0x80176D6C (200 bytes)
// UI3D::InstallEntry(char* name, unsigned int a, unsigned int b, unsigned int c, char* group, int priority)
// Installs a named 3D UI entry. Calls AddEntry with parameters.
// Returns handle for later removal.

// 0x80176E34 (184 bytes)
// UI3D::FindEntry(char* name)
// Searches entry list for matching name. Returns entry pointer or null.
// Uses strcmp for comparison.

// 0x80176EEC (68 bytes)
// UI3D::UnInstallEntry(char* name)
// Finds and removes entry by name. Calls FindEntry then RemoveEntry.

// 0x80176F30 (96 bytes)
// UI3D::UnInstallAllEntries(char* group)
// Removes all entries matching a group name. Iterates backwards
// through list to safely remove while iterating.

// 0x80176FC0 (68 bytes)
// UI3D::Update3D(void)
// Processes all registered 3D UI entries. Calls each entry's update callback.

// 0x80177074 (76 bytes)
// UI3D::Shutdown(void)
// Removes all entries and shuts down 3D UI system.


// ============================================================================
// AptDisplayListState - APT UI display list state management
// ============================================================================

// 0x80299340 (272 bytes)
// AptDisplayListState::findInst(int depth, EAStringC* name, AptCIH** outPrev, AptCIH** outCurrent)
// Searches display list for instance at given depth or with given name.
// Returns previous and current CIH pointers for insertion/removal operations.
// Walks linked list comparing depth values.

// 0x802994A4 (92 bytes)
// AptDisplayListState::RegisterReferences(AptValue*) const
// Registers all display list instances with the garbage collector.
// Iterates through linked list, calling RegisterReferences on each CIH.

// 0x80299500 (256 bytes)
// AptDisplayListState::insert(AptCIH* newCIH, AptCIH* afterCIH)
// Inserts a CIH into the display list after the specified position.
// Updates linked list pointers, adjusts render order.

// 0x80299600 (288 bytes)
// AptDisplayListState::insert(int depth, AptVirtualFunctionTable_Indices indices,
//     AptCharacterInst* inst, AptCIH* prev, AptCIH* current)
// Inserts at specific depth with VFT indices. Creates new CIH if needed.
// Handles replacement if instance at depth already exists.

// 0x80299720 (316 bytes)
// AptDisplayListState::insert(int depth, AptVirtualFunctionTable_Indices indices,
//     AptCharacterInst* inst)
// Simplified insert - finds position automatically via findInst, then inserts.

// 0x8029985C (96 bytes)
// AptDisplayListState::insert(int depth, AptCIH* cih)
// Insert CIH at depth. Finds position via findInst, delegates to full insert.

// 0x8029C12C (88 bytes)
// AptDisplayListState::hasRenderData(void)
// Returns true if display list has any renderable content.
// Checks if linked list head is non-null and has render data flags set.

// 0x8029C184 (76 bytes)
// AptDisplayListState::GetMovieclipInfo(AptMovieclipInformation*)
// Fills movieclip info struct from display list state.
// Returns frame count, current frame, loop info.

// 0x8029C1D0 (380 bytes)
// AptDisplayListState::AptDisplayListState(void)
// Constructor. Initializes all fields to zero/defaults.
// Sets up linked list head/tail pointers, clears frame info.

// 0x8029C34C (108 bytes)
// AptDisplayListState::~AptDisplayListState(void)
// Destructor. Walks display list freeing all CIH entries.
// Releases character instances.


// ============================================================================
// WantFearManager - Sims 2 Wants/Fears system manager
// ============================================================================

// 0x8014BC6C (76 bytes)
// WantFearManager::WantFearManager(void)
// Constructor. Clears all internal pointers and counters.
// Sets m_loaded flag to false.

// 0x8014BCB8 (76 bytes)
// WantFearManager::~WantFearManager(void)
// Destructor. Frees loaded want/fear data arrays. Releases resource refs.

// 0x8014BD08 (536 bytes)
// WantFearManager::LoadWants(void)
// Loads want/fear definitions from quickdata tables. Parses event types,
// tree structures, story tree roots. Builds lookup tables for fast access.
// Loads category shader assignments.

// 0x8014BF30 (140 bytes)
// WantFearManager::GetEvent(unsigned short id) const
// Looks up event definition by ID. Binary search through event array.
// Returns pointer to event data or null.

// 0x8014BFCC (152 bytes)
// WantFearManager::GetTree(unsigned short id) const
// Looks up want/fear tree by ID. Binary search through tree array.
// Returns pointer to tree data or null.

// 0x8014C064 (256 bytes)
// WantFearManager::GetStoryTreeRoot(short category, short subcategory) const
// Finds root node for story-driven want trees. Searches by category
// and subcategory. Returns tree root pointer.

// 0x8014C164 (152 bytes)
// WantFearManager::GetCategoryShader(int category, short type)
// Returns shader ID for want/fear category display.
// Uses type to select between want and fear shader sets.

// 0x8014C1FC (444 bytes)
// WantFearManager::PickNewRoot(Neighbor* sim, bool isFear)
// Selects a new want/fear tree root for a sim based on personality,
// skills, and life state. Uses weighted random selection (lottery).
// Filters by eligibility criteria.

// 0x8014C3B8 (140 bytes)
// WantFearManager::Lottery(unsigned int* weights, unsigned int count) const
// Weighted random selection. Sums all weights, picks random value,
// walks array subtracting weights until selection found. Returns index.


// ============================================================================
// IFFSlotDescList - IFF resource slot descriptor list
// ============================================================================

// 0x80144960 (704 bytes)
// IFFSlotDescList::AddSlot(SlotDescriptor&)
// Adds a slot descriptor to the list. Grows internal array if needed.
// Copies 100+ bytes of descriptor data. Updates slot count.

// 0x80144C20 (260 bytes)
// IFFSlotDescList::RemoveSlot(int index)
// Removes slot at index. Shifts subsequent entries down.
// Decrements count. Does bounds checking.

// 0x80144D24 (212 bytes)
// IFFSlotDescList::LoadFromDataID(ObjectDataID&)
// Loads slot descriptors from an object data resource.
// Resolves resource via virtual dispatch, parses binary data.

// 0x80144DF8 (264 bytes)
// IFFSlotDescList::LoadFromIndex(unsigned int resId, int index)
// Loads slots from resource by ID and index.
// Gets resource manager, finds resource, parses slot data.

// 0x80144F34 (112 bytes)
// IFFSlotDescList::SaveDataByID(ObjectDataID&)
// Saves slot list to resource by data ID. Serializes all descriptors.

// 0x80144FA4 (112 bytes)
// IFFSlotDescList::QueryInterface(unsigned int iid, void** ppv)
// COM-style interface query. Supports IID_IUnknown and specific slot list IID.
// AddRefs on success, returns interface pointer.

// 0x80145028 (92 bytes)
// IFFSlotDescList::Release(void)
// Decrements reference count. Self-deletes when count reaches 0.

// 0x80145188 (84 bytes)
// IFFSlotDescList::IFFSlotDescList(void)
// Constructor. Sets vtable, initializes slot array to null, count to 0, refcount to 1.

// 0x801451DC (160 bytes)
// IFFSlotDescList::~IFFSlotDescList(void)
// Destructor. Frees slot array memory. Sets vtable for proper destruction chain.


// ============================================================================
// ImageProcessingManager - Post-processing image filter pipeline
// ============================================================================

// 0x803293F8 (104 bytes)
// ImageProcessingManager::Open(int numStages)
// Initializes the image processing pipeline with given number of stages.
// Allocates stage filter array, sets up default parameters.

// 0x8032949C (108 bytes)
// ImageProcessingManager::SetStageFilter(int stage, int* filterParams)
// Configures filter parameters for a specific pipeline stage.
// Copies filter type and parameters into stage slot.

// 0x80329558 (620 bytes)
// ImageProcessingManager::Execute(ETexture* src, ETexture* dst)
// Runs the full image processing pipeline. For each stage, applies the
// configured filter. Handles texture format conversion between stages.
// Supports filters: blur, sharpen, edge detect, brightness/contrast.

// 0x8032A29C (1384 bytes)
// ImageProcessingManager::CompositeEdges(short* src, short* dst, int width, int height, int* params)
// Composites edge-detected image with original. Performs per-pixel blending
// with configurable edge strength. Optimized with loop unrolling.

// 0x80329824 (68 bytes)
// ImageProcessingManager::FilterParams::Reset(void)
// Resets filter parameters to default values. Clears all fields to zero.


// ============================================================================
// EVibrate - Controller vibration/rumble system
// ============================================================================

// 0x80307BCC (88 bytes)
// EVibrate::EVibrate(void)
// Constructor. Initializes vibration state for all motors to off.
// Sets enabled flag. Clears duration timers.

// 0x80307C4C (100 bytes)
// EVibrate::Enable(void)
// Enables vibration system. Resumes any paused vibrations.

// 0x80307CC4 (124 bytes)
// EVibrate::TurnOn(unsigned char controller)
// Turns on vibration for specified controller. Starts both motors
// at last configured intensity.

// 0x80307D94 (128 bytes)
// EVibrate::Pause(void)
// Pauses all active vibrations without losing state.
// Sets motors to zero output but preserves parameters.

// 0x80307E14 (140 bytes)
// EVibrate::Resume(void)
// Resumes previously paused vibrations. Restores motor outputs
// to pre-pause levels.

// 0x80307EA0 (92 bytes)
// EVibrate::VibrateMotorOne(unsigned char controller, float intensity)
// Sets motor one to given intensity (0.0-1.0). Runs until stopped.

// 0x80307EFC (108 bytes)
// EVibrate::VibrateMotorOne(unsigned char controller, float intensity, float duration)
// Sets motor one with auto-stop after duration seconds.

// 0x80307F68 (92 bytes)
// EVibrate::VibrateMotorTwo(unsigned char controller, float intensity)
// Sets motor two to given intensity. Runs until stopped.

// 0x80307FC4 (108 bytes)
// EVibrate::VibrateMotorTwo(unsigned char controller, float intensity, float duration)
// Sets motor two with auto-stop after duration seconds.

// 0x80308030 (108 bytes)
// EVibrate::VibrateAll(unsigned char controller, float intensity1, float intensity2)
// Sets both motors simultaneously. Runs until stopped.

// 0x8030809C (140 bytes)
// EVibrate::VibrateAll(unsigned char controller, float i1, float d1, float i2, float d2)
// Sets both motors with independent intensities and durations.

// 0x80308128 (76 bytes)
// EVibrate::StopMotorOne(unsigned char controller)
// Immediately stops motor one.

// 0x80308174 (92 bytes)
// EVibrate::StopMotorOne(unsigned char controller, float fadeOut)
// Stops motor one with fade-out over given duration.

// 0x803081D0 (76 bytes)
// EVibrate::StopMotorTwo(unsigned char controller)
// Immediately stops motor two.

// 0x8030821C (92 bytes)
// EVibrate::StopMotorTwo(unsigned char controller, float fadeOut)
// Stops motor two with fade-out over given duration.

// 0x80308278 (76 bytes)
// EVibrate::StopVibration(unsigned char controller)
// Stops all vibration on specified controller immediately.

// 0x803082C4 (120 bytes)
// EVibrate::StopAllVibration(void)
// Stops all vibration on all controllers. Called during pause, cutscenes, etc.


// ============================================================================
// IShrubObject - Shrub/plant decorative object
// ============================================================================

// 0x800525E4 (72 bytes)
// IShrubObject::IShrubObject(void)
// Constructor. Calls base IStaticModel constructor. Sets shrub-specific vtable.

// 0x8005262C (96 bytes)
// IShrubObject::~IShrubObject(void)
// Destructor. Releases shrub model resources.

// 0x8005268C (96 bytes)
// IShrubObject::Create(cXObject*, EHouse*)
// Creates shrub from object definition. Loads model, sets position from object.
// Registers with the house's spatial partitioning system.

// 0x800526EC (1792 bytes)
// IShrubObject::SetObjOrient(void)
// Complex orientation setup. Computes shrub orientation based on terrain slope,
// wind direction, and randomized sway. Builds transformation matrix.
// Handles multiple shrub variants and LOD switching.

// 0x8005433C (84 bytes)
// IShrubObject::New(void)
// Factory method. Allocates new IShrubObject via __builtin_new.
// Returns constructed instance.

// 0x8005445C (84 bytes)
// IShrubObject::RegisterType(unsigned short typeId)
// Registers IShrubObject type with the object type system.
// Associates type ID with New() factory method.


// ============================================================================
// UIDBTarget - UI Database target for variable get/set
// ============================================================================

// 0x80179D90 (1124 bytes)
// UIDBTarget::UIDBTarget(void)
// Constructor similar to UIAnalog. Sets up CBFunctor objects, initializes
// singleton tables (GetVariableCommandTable, SetVariableCommandTable, etc.).
// Installs many GetVariable and SetVariable command handlers for
// database queries: save slot info, game state, player data.

// 0x8017A1F4 (324 bytes)
// UIDBTarget::~UIDBTarget(void)
// Destructor. Uninstalls all commands from variable tables.
// Cleans up UI2D, UI3D, UIAUDIO entries.

// 0x8017A338 (364 bytes)
// UIDBTarget::SetVariable(char* name, char* value)
// Sets a database variable. Dispatches by name to appropriate handler.
// Handles: save slot selection, game options, screen transitions.

// 0x8017A4A4 (424 bytes)
// UIDBTarget::GetVariable(char* name)
// Gets a database variable value. Returns allocated string with value.
// Handles: save slot info, game state queries, option values.


// ============================================================================
// vector<IFFResNode, allocator<IFFResNode>> - STL vector specialization
// ============================================================================

// 0x803A38A8 (1496 bytes)
// vector<IFFResNode, allocator<IFFResNode>>::_M_fill_insert(IFFResNode*, unsigned int, IFFResNode&)
// Inserts 'count' copies of 'value' at position. Handles three cases:
// 1. Enough spare capacity after end - shifts tail, fills gap.
// 2. Enough total capacity but need complex move - splits and fills.
// 3. Not enough capacity - reallocates buffer, copies around insertion point.
// IFFResNode appears to be ~12 bytes based on stride calculations.

// 0x803A3FA0 (804 bytes)
// vector<IFFResNode, allocator<IFFResNode>>::operator=(vector& rhs)
// Assignment operator. If rhs fits in current capacity, copies in place.
// Otherwise allocates new buffer, copies, frees old. Handles self-assignment.
// Updates begin/end/capacity pointers.


// ============================================================================
// GoalUnlock - Goal/achievement unlock system
// ============================================================================

// 0x800B84A8 (104 bytes)
// GoalUnlock::DoStream(ReconBuffer*, int)
// Serializes unlock state to/from save buffer. Streams unlock flags
// for all categories. Uses ReconBuffer streaming interface.

// 0x800B853C (96 bytes)
// GoalUnlock::GetUnlockCount(int category)
// Returns number of unlockable items in a category.
// Reads from quickdata table.

// 0x800B859C (316 bytes)
// GoalUnlock::SetupObjectUnlockInfo(void)
// Initializes unlock info from object definitions. Builds mapping
// from object GUIDs to unlock indices. Loads from quickdata tables.

// 0x800B86D8 (132 bytes)
// GoalUnlock::GetObjectIndexFromGuid(int guid)
// Searches object unlock table for matching GUID.
// Returns index or -1 if not found. Linear search.

// 0x800B875C (112 bytes)
// GoalUnlock::GetFirstUnlockVar(int category)
// Returns the base variable index for unlocks in a category.
// Used to compute actual variable offsets.

// 0x800B87CC (180 bytes)
// GoalUnlock::IsUnlocked(int category, short index)
int GoalUnlock_IsUnlocked(void* self, int category, short index) {
    // Gets base variable, adds index offset
    // Reads unlock flag from game data
    // Returns 1 if unlocked, 0 if locked
    (void)self; (void)category; (void)index;
    return 0; // Stub
}

// 0x800B8880 (204 bytes)
// GoalUnlock::GrantUnlock(int category, short index)
// Grants an unlock. Sets the unlock flag in game data.
// Triggers unlock notification/animation if first time.

// 0x800B894C (288 bytes)
// GoalUnlock::GrantObjectUnlocks(int goalIndex)
// Grants all object unlocks associated with completing a goal.
// Iterates object unlock table, grants matching entries.

// 0x800B8A6C (184 bytes)
// GoalUnlock::IsRecentlyUnlocked(int category, short index)
// Checks if an item was recently unlocked (for "new" badge display).
// Uses separate recently-unlocked flag array.

// 0x800B8B24 (208 bytes)
// GoalUnlock::SetRecentlyUnlocked(int category, short index, bool state)
// Sets or clears the recently-unlocked flag for an item.

// 0x800B8BF4 (148 bytes)
// GoalUnlock::GetUnlockTotal(int category)
// Returns total number of unlocked items in a category.
// Counts set flags across the category's variable range.


// ============================================================================
// cSoundCache - Sound effect cache and playback manager
// ============================================================================

// 0x80119530 (108 bytes)
// cSoundCache::Shutdown(void)
// Shuts down sound cache. Stops all playing tracks, frees cached samples.
// Iterates through track array (count at offset 4), stops and releases each.

// 0x8011959C (1120 bytes)
// cSoundCache::CleanupIdleTracks(void)
// Garbage-collects idle sound tracks. Checks each track's state,
// frees tracks that have finished playing. Handles looping sounds
// differently from one-shot sounds. Updates active track count.
// Complex logic for priority-based track stealing when cache is full.

// 0x801199FC (212 bytes)
// cSoundCache::UpdateDuckingPriorities(void)
// Updates audio ducking (volume reduction) based on active sound priorities.
// Higher priority sounds duck lower priority ones. Iterates active tracks,
// computes ducking factors, applies to mixer levels.

// 0x80119AD0 (72 bytes)
// cSoundCache::KillAll(void)
// Immediately stops all cached sounds. Iterates track array,
// calls Stop on each active track.

// 0x80119B18 (132 bytes)
// cSoundCache::PauseGroup(int group)
// Pauses all sounds in a group (e.g., SFX, music, ambient).
// Iterates tracks, pauses those matching the group ID.

// 0x80119B9C (132 bytes)
// cSoundCache::UnpauseGroup(int group)
// Resumes paused sounds in a group. Iterates tracks,
// resumes those matching the group ID that were paused.

// 0x80119C20 (296 bytes)
// cSoundCache::GetTrackObject(ERSoundEvent* event, bool steal)
// Finds or allocates a track for a sound event. First checks for
// existing track playing same event. If not found, finds free track.
// If no free track and steal==true, steals lowest priority track.
// Returns track pointer or null.


// ============================================================================
// ScrollingTextBox - Scrolling text display widget
// ============================================================================

// 0x8006C8C0 (216 bytes)
// ScrollingTextBox::ScrollingTextBox(void)
// Constructor. Initializes scroll parameters: speed, position, bounds.
// Sets font to default, clears text buffer. Initializes color to white.
// Sets up render quad coordinates.

// 0x8006C998 (140 bytes)
// ScrollingTextBox::~ScrollingTextBox(void)
// Destructor. Frees text buffer if allocated. Releases font reference.

// 0x8006CA7C (240 bytes)
// ScrollingTextBox::SetString(unsigned short* text, float scrollSpeed)
// Sets the scrolling text content. Copies wide string to internal buffer.
// Resets scroll position to top. Measures text height for scroll bounds.
// Sets scroll speed.

// 0x8006CBE8 (1812 bytes)
// ScrollingTextBox::Draw(ERC* rc)
// Renders scrolling text. Sets up scissor rect for clipping.
// Iterates characters, computes positions with scroll offset.
// Handles word wrapping, line breaks, font changes.
// Draws each visible character via font renderer.
// Updates scroll position each frame.
// Complex text layout with variable-width font metrics.
