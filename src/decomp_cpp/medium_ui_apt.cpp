// medium_ui_apt.cpp - UI/APT/Font/QuickData medium stubs (101-500 lines)
// ~87 files converted from PPC asm to portable C++
#include "types.h"

// Forward declarations - standard library
extern "C" {
    void* memcpy(void*, const void*, unsigned int);
    void* memset(void*, int, unsigned int);
    void* memmove(void*, const void*, unsigned int);
    int strlen(const char*);
    char* strcpy(char*, const char*);
    char* strncpy(char*, const char*, unsigned int);
    int strncmp(const char*, const char*, unsigned int);
    int strcasecmp(const char*, const char*);
    int sprintf(char*, const char*, ...);
}

// Forward declarations - engine types
class EAHeap;
class ERC;
class EStream;
class EFile;
class EMat4;
class EVec4;
class EResource;
class ETypeInfo;
class EAStringC;
class BString2;

extern EAHeap* MainHeap();
void operator delete(void*, unsigned int);

// Forward declarations - APT types
class AptValue;
class AptValueGC;
class AptString;
class AptArray;
class AptWord;
class AptCIH;
class AptFile;
class AptDisplayList;
class AptNativeHash;
class AptMatrix;
class AptRect;
class AptCXForm;
class AptAction_DefineFunction;
class AptAction_DefineFunction2;
class AptScriptFunctionBase;
class AptPseudoCIH_t;
class AptPseudoData_t;
class IAptXmlNode;
struct AptMaskRenderOperation;
struct AptVirtualFunctionTable_Indices;
class _AptScriptFunctionState;

// Forward declarations - pool managers
class DOGMA_PoolManager;
class AptValueGC_PoolManager;

// Externs
extern DOGMA_PoolManager* g_pDOGMA_PoolManager;       // r13 - 23020
extern AptValueGC_PoolManager* g_pAptValueGC_PoolManager; // r13 - 23016
extern AptValue* g_pAptBooleanPool;    // r13 - 26916
extern AptValue* g_pAptFloatPool;      // r13 - 26912
extern AptValue* g_pAptIntegerPool;    // r13 - 26908
extern AptValue* g_pAptNoneValue;      // r13 - 22936
extern AptValue* g_pAptGlobalObject;   // r13 - 27000
extern AptValue* g_pAptMovieClipProto; // r13 - 26996
extern AptValue* g_pAptFrameStack;     // r13 - 26960
extern void* g_pAptValueVector;        // r13 - 27600
extern void* g_pAptRefRegistrationCb;  // r13 - 27024
extern int g_aptGCDisableDelete;       // r13 - 27028
extern void* g_pAptRegisterStack;      // r13 - 26972
extern int g_aptRegisterCount;         // r13 - 26968
extern void* g_pAptClipStackData;      // r13 - 27252
extern void* g_pAptClipStackRaw;       // r13 - 27248
extern short g_aptClipStackMaxDepth;   // r13 - 27244
extern short g_aptClipStackCurDepth;   // r13 - 27242
extern void* g_pLoadingScreenSM;       // r13 - 32160
extern void* g_pGameStateMan;          // r13 - 26392

// Sound globals
extern AptValue* g_pAptSoundAttach;    // r13 - 27096
extern AptValue* g_pAptSoundStart;     // r13 - 27088
extern AptValue* g_pAptSoundStop;      // r13 - 27092
extern AptValue* g_pAptStageWidth;     // r13 - 27108
extern AptValue* g_pAptStageHeight;    // r13 - 27104

// ============================================================
// AptBoolean - APT boolean value type
// ============================================================

class AptBoolean : public AptValue {
public:
    void ClearPool();
    ~AptBoolean();
    AptBoolean(bool value);
    static AptValue* Create(bool value);
};

// 0x802BB830
void AptBoolean::ClearPool() {
    while (g_pAptBooleanPool != 0) {
        AptValue* current = g_pAptBooleanPool;
        AptValue* next = *(AptValue**)((char*)current + 12);
        // Call virtual destructor via vtable
        // current->vt_DestroyGCPointers();
        // current->vt_operator_delete(3);
        g_pAptBooleanPool = next;
    }
}

// 0x802BB8E0
AptBoolean::~AptBoolean() {
    // vtable = AptBoolean_vtable
    // AptValue::~AptValue();
    // if (flags & 1) operator delete(this, 16);
}

// 0x802BB9CC
AptBoolean::AptBoolean(bool value) {
    // AptValue::AptValue(5); // kAptBoolean
    // vtable = AptBoolean_vtable
    // m_value = value; // offset 12
}

// 0x802BBA14
AptValue* AptBoolean::Create(bool value) {
    AptValue* obj = g_pAptBooleanPool;
    if (obj != 0) {
        AptValue* next = *(AptValue**)((char*)obj + 12);
        g_pAptBooleanPool = next;
        // Reuse pooled object, set value
        *(int*)((char*)obj + 12) = (int)value;
        return obj;
    }
    // Allocate new
    // AptValue* newObj = g_pDOGMA_PoolManager->Allocate(16);
    // new (newObj) AptBoolean(value);
    // return newObj;
    return 0;
}

// ============================================================
// AptFloat - APT float value type
// ============================================================

class AptFloat : public AptValue {
public:
    void ClearPool();
    ~AptFloat();
    AptFloat(float value);
    static AptValue* Create(float value);
};

// 0x802BBAE0
void AptFloat::ClearPool() {
    while (g_pAptFloatPool != 0) {
        AptValue* current = g_pAptFloatPool;
        AptValue* next = *(AptValue**)((char*)current + 12);
        // current->vt_DestroyGCPointers();
        // current->vt_operator_delete(3);
        g_pAptFloatPool = next;
    }
}

// 0x802BBB90
AptFloat::~AptFloat() {
    // vtable = AptFloat_vtable
    // AptValue::~AptValue();
    // if (flags & 1) operator delete(this, 16);
}

// 0x802BBC7C
AptFloat::AptFloat(float value) {
    // AptValue::AptValue(6); // kAptFloat
    // vtable = AptFloat_vtable
    // *(float*)((char*)this + 12) = value;
}

// 0x802BBCCC
AptValue* AptFloat::Create(float value) {
    AptValue* obj = g_pAptFloatPool;
    if (obj != 0) {
        AptValue* next = *(AptValue**)((char*)obj + 12);
        g_pAptFloatPool = next;
        *(float*)((char*)obj + 12) = value;
        return obj;
    }
    // Allocate new
    // AptValue* newObj = g_pDOGMA_PoolManager->Allocate(16);
    // new (newObj) AptFloat(value);
    // return newObj;
    return 0;
}

// ============================================================
// AptInteger - APT integer value type
// ============================================================

class AptInteger : public AptValue {
public:
    void ClearPool();
    ~AptInteger();
    AptInteger(int value);
    static AptValue* Create(int value);
};

// 0x802BBD9C
void AptInteger::ClearPool() {
    while (g_pAptIntegerPool != 0) {
        AptValue* current = g_pAptIntegerPool;
        AptValue* next = *(AptValue**)((char*)current + 12);
        // current->vt_DestroyGCPointers();
        // current->vt_operator_delete(3);
        g_pAptIntegerPool = next;
    }
}

// 0x802BBE4C
AptInteger::~AptInteger() {
    // vtable = AptInteger_vtable
    // AptValue::~AptValue();
    // if (flags & 1) operator delete(this, 16);
}

// 0x802BBF38
AptInteger::AptInteger(int value) {
    // AptValue::AptValue(7); // kAptInteger
    // vtable = AptInteger_vtable
    // *(int*)((char*)this + 12) = value;
}

// 0x802BBF80
AptValue* AptInteger::Create(int value) {
    AptValue* obj = g_pAptIntegerPool;
    if (obj != 0) {
        AptValue* next = *(AptValue**)((char*)obj + 12);
        g_pAptIntegerPool = next;
        *(int*)((char*)obj + 12) = value;
        return obj;
    }
    // Allocate new
    // AptValue* newObj = g_pDOGMA_PoolManager->Allocate(16);
    // new (newObj) AptInteger(value);
    // return newObj;
    return 0;
}

// ============================================================
// AptCharacter - APT character base class
// ============================================================

class AptCharacter {
public:
    int m_type;         // offset 0
    // offset 8: bounding rect (AptRect)
    // offset 24: child inst pointer
    void render(AptRenderingContext* ctx, AptMaskRenderOperation maskOp, AptMatrix* matrix);
    void _getBoundingRect(AptRenderingContext* ctx, AptRect* outRect, AptMatrix* matrix);
};

// 0x80288090
void AptCharacter::render(AptRenderingContext* ctx, AptMaskRenderOperation maskOp, AptMatrix* matrix) {
    if (matrix != 0) {
        ctx->pushVertexMatrix();
        ctx->appendVertexMatrix(matrix);
    }
    if (m_type == 1) {
        // Call render function on child via function pointer table
        // AptCharacterInst* inst = *(AptCharacterInst**)((char*)this + 24);
        // inst->vt_render(maskOp);
    }
    if (matrix != 0) {
        ctx->popVertexMatrix();
    }
}

// 0x80288120
void AptCharacter::_getBoundingRect(AptRenderingContext* ctx, AptRect* outRect, AptMatrix* matrix) {
    if (matrix != 0) {
        ctx->pushVertexMatrix();
        ctx->appendVertexMatrix(matrix);
    }
    int type = m_type;
    if (type == 1 || type == 10) {
        // ctx->expandBoundingRect(outRect, &this->m_rect);
    }
    if (matrix != 0) {
        ctx->popVertexMatrix();
    }
}

// ============================================================
// AptCharacterAnimationInst
// ============================================================

template <typename T> class AptSharedPtr {
public:
    T* m_ptr; // offset 0
};

class AptCharacterAnimationInst {
public:
    // offset 0-19: inherited from AptCharacterSpriteInstBase
    // offset 20: vtable2
    // offset 48: unknown field
    // offset 52: AptSharedPtr<AptFile>
    AptCharacterAnimationInst(AptSharedPtr<AptFile> filePtr);
    ~AptCharacterAnimationInst();
};

// 0x80282EBC
AptCharacterAnimationInst::AptCharacterAnimationInst(AptSharedPtr<AptFile> filePtr) {
    // AptCharacterSpriteInstBase::AptCharacterSpriteInstBase();
    // vtable2 = AptCharacterAnimationInst_vtable;
    // m_field48 = 0;
    // m_sharedFile.m_ptr = 0;
    // Copy shared ptr with ref increment
    // if (filePtr.m_ptr != 0) AptSharedPtrIncRef(filePtr.m_ptr);
    // m_sharedFile = filePtr;
    // m_characterDef = filePtr.m_ptr->m_field16;
    // Release source shared ptr
}

// 0x80282F54
AptCharacterAnimationInst::~AptCharacterAnimationInst() {
    // vtable2 = AptCharacterAnimationInst_vtable;
    // Release shared ptr
    // AptCharacterSpriteInstBase::~AptCharacterSpriteInstBase();
    // if (flags & 1) g_pDOGMA_PoolManager->Deallocate(this, 56);
}

// ============================================================
// AptCharacterSpriteInstBase
// ============================================================

class AptCharacterSpriteInstBase {
public:
    AptCharacterSpriteInstBase();
    ~AptCharacterSpriteInstBase();
};

// 0x802881B8
AptCharacterSpriteInstBase::AptCharacterSpriteInstBase() {
    // Initialize fields to zero/defaults
    // m_type = -1;        // offset 0
    // m_characterDef = 0; // offset 8
    // m_parent = 0;       // offset 12
    // m_flags = 0;        // offset 16
    // vtable2 = AptCharacterSpriteInstBase_vtable; // offset 20
    // AptDisplayList::AptDisplayList() at offset 36
    // m_field32 = 0;
    // m_field40 = 0;
    // Allocate and init AptNativeHash
    // AptNativeHash* hash = g_pDOGMA_PoolManager->Allocate(20);
    // hash = new AptNativeHash(8);
    // m_memberHash = hash; // offset 12
    // m_field24 = -1;
    // m_field44 = 0;
    // Lookup "onClipEvent" in global proto, set up handlers
}

// 0x802882F8
AptCharacterSpriteInstBase::~AptCharacterSpriteInstBase() {
    // vtable2 = AptCharacterSpriteInstBase_vtable;
    // if (m_field44 == 1) g_pDOGMA_PoolManager->Deallocate(m_field8, 64);
    // AptDisplayList::~AptDisplayList() at offset 36
    // if (m_memberHash) AptNativeHash::~AptNativeHash(m_memberHash);
    // if (flags & 1) __builtin_delete(this);
}

// ============================================================
// AptFrameStack - frame stack for APT VM
// ============================================================

class AptFrameStack {
public:
    // offset 0-11: AptValue base
    // offset 12-31: AptNativeHash (inline)
    // offset 32: parent pointer
    void DestroyGCPointers();
    void RegisterReferences() const;
    ~AptFrameStack();
};

// 0x802B921C
void AptFrameStack::DestroyGCPointers() {
    AptValue* parent = *(AptValue**)((char*)this + 32);
    if (parent != 0) {
        // Call vt_Unlink on parent (vtable offset 16/20)
    }
    // AptValueWithHash::DestroyGCPointers();
}

// 0x802B9284
void AptFrameStack::RegisterReferences() const {
    AptValue* parent = *(AptValue**)((char*)this + 32);
    if (parent != 0) {
        // g_pAptRefRegistrationCb(this, parent, "parent");
    }
    // AptValueWithHash::RegisterReferences();
}

// 0x802B92D4
AptFrameStack::~AptFrameStack() {
    // vtable = AptFrameStack_vtable;
    // AptNativeHash::~AptNativeHash(&this->m_hash) at offset 12
    // AptValue::~AptValue();
    // if (flags & 1) g_pAptValueGC_PoolManager->DeallocateAptValueGC(this, 36);
}

// ============================================================
// AptGC - Garbage collector
// ============================================================

class AptGC {
public:
    static void sReferenceRegistrationCb(AptValue* owner, AptValue* ref, char* name);
    static void CleanUnreachable();
    static void CleanAll();
};

// 0x8029C654
void AptGC::sReferenceRegistrationCb(AptValue* owner, AptValue* ref, char* name) {
    unsigned int flags = *(unsigned int*)((char*)ref);
    if (!(flags & 0x40000000)) {
        flags |= 0x40000000;
        *(unsigned int*)((char*)ref) = flags;
        // Call virtual RegisterReferences via vtable (offset 112/116)
    }
}

// 0x8029C69C
void AptGC::CleanUnreachable() {
    // Phase 1: Release values vector, mark live objects
    // g_pAptValueVector->ReleaseValues();
    // Iterate all AptValues, mark unreachable for collection
    // Phase 2: Call DestroyGCPointers on unreachable
    // Phase 3: Call operator delete on unreachable
    // Phase 4: Clear pools
    // AptBoolean::ClearPool();
    // AptInteger::ClearPool();
    // AptFloat::ClearPool();
    // StringPool::ClearTemporaryPool();
}

// 0x8029C834
void AptGC::CleanAll() {
    // g_pAptValueVector->ReleaseValues();
    // Iterate all AptValues, call DestroyGCPointers and delete
    // AptBoolean::ClearPool();
    // AptInteger::ClearPool();
    // AptFloat::ClearPool();
    // StringPool::ClearTemporaryPool();
}

// ============================================================
// AptGlobal - global scope object for APT
// ============================================================

class AptGlobal : public AptValue {
public:
    // offset 12: AptNativeHash (inline)
    // offset 32: flags
    AptValue* objectMemberLookup(AptValue* unused, EAStringC* name) const;
    int objectMemberSet(AptValue* unused, EAStringC* name, AptValue* value);
    AptGlobal();
    ~AptGlobal();
};

// 0x802B5B6C
AptValue* AptGlobal::objectMemberLookup(AptValue* unused, EAStringC* name) const {
    AptValue* result = 0; // AptNativeHash at g_pAptGlobalObject+12 ->Lookup(name)
    if (result != 0) {
        unsigned int flags = *(unsigned int*)result;
        if (flags & 0x08000000) return result;
    }
    // Fall back to movie clip proto lookup
    // result = AptNativeHash at g_pAptMovieClipProto+12 ->Lookup(name)
    return result;
}

// 0x802B5BC8
int AptGlobal::objectMemberSet(AptValue* unused, EAStringC* name, AptValue* value) {
    // Check if name exists in global native hash
    // If not found, set in this object's hash
    // AptNativeHash at this+12 ->Set(name, value)
    return 1;
}

// 0x802B5C2C
AptGlobal::AptGlobal() {
    // AptValue::AptValue(25); // kAptGlobal
    // vtable = AptObject_vtable
    // AptNativeHash::AptNativeHash(11) at offset 12
    // m_implementedCount = 0; // offset 32
    // vtable = AptGlobal_vtable
    // Clear flags bits
    // AptValue::setGCRoot(1);
}

// 0x802B5CA4
AptGlobal::~AptGlobal() {
    // vtable = AptGlobal_dtor_vtable;
    // AptNativeHash::~AptNativeHash() at offset 12
    // AptValue::~AptValue();
    // if (flags & 1) g_pAptValueGC_PoolManager->DeallocateAptValueGC(this, 36);
}

// ============================================================
// AptObject - base object for APT values with properties
// ============================================================

class AptObject : public AptValue {
public:
    // offset 12: AptNativeHash (inline member hash)
    // offset 20: prototype pointer
    // offset 32: implemented objects info (byte)
    void SetImplementedObjects(AptArray* arr, int count);
    AptValue* GetImplementedObjects(int* outCount) const;
    int DoesImplementObject(AptValue* obj) const;
    AptObject(AptVirtualFunctionTable_Indices idx, int hashSize);
    void SetPrototype(AptValue* proto);
    ~AptObject();
};

// 0x802B5E94
void AptObject::SetImplementedObjects(AptArray* arr, int count) {
    EAStringC nameStr;
    // EAStringC::InitFromBuffer("__implements__");
    // AptNativeHash at offset 12 ->Set(&nameStr, arr);
    *(unsigned char*)((char*)this + 32) = (unsigned char)count;
    // Release EAStringC
}

// 0x802B5F18
AptValue* AptObject::GetImplementedObjects(int* outCount) const {
    unsigned char count = *(unsigned char*)((char*)this + 32);
    *outCount = count;
    if (count == 0) return 0;
    EAStringC nameStr;
    // EAStringC::InitFromBuffer("__implements__");
    // AptValue* result = AptNativeHash at offset 12 ->Lookup(&nameStr);
    // Release EAStringC
    // return result;
    return 0;
}

// 0x802B5FB0
int AptObject::DoesImplementObject(AptValue* target) const {
    // Walk prototype chain checking if target matches
    AptValue* proto = *(AptValue**)((char*)this + 20);
    while (proto != 0) {
        if (proto == target) return 1;
        // Check if proto has getPrototype virtual
        // proto = proto->getPrototype();
        break;
    }
    // Check __implements__ array
    unsigned char count = *(unsigned char*)((char*)this + 32);
    if (count == 0) return 0;
    // Lookup __implements__ and check each entry
    return 0;
}

// 0x802B6320
AptObject::AptObject(AptVirtualFunctionTable_Indices idx, int hashSize) {
    // AptValue::AptValue(idx);
    // vtable = AptObject_base_vtable
    // AptNativeHash::AptNativeHash(hashSize) at offset 12
    // m_implementedCount = 0; // offset 32
    // vtable = AptObject_vtable
    // Clear bits in offset 32
}

// 0x802B64C4
void AptObject::SetPrototype(AptValue* proto) {
    AptValue* oldProto = *(AptValue**)((char*)this + 12 + 12); // hash->m_prototype
    // AddRef on new proto
    if (proto != 0) {
        // proto->vt_AddRef();
    }
    // DecRef on old proto
    if (oldProto != 0) {
        // oldProto->vt_DecRef();
    }
    *(AptValue**)((char*)this + 12 + 12) = proto;
}

// 0x802B655C
AptObject::~AptObject() {
    // vtable = AptObject_dtor_vtable;
    // AptNativeHash::~AptNativeHash() at offset 12
    // AptValue::~AptValue();
    // if (flags & 1) g_pAptValueGC_PoolManager->DeallocateAptValueGC(this, 36);
}

// ============================================================
// AptPrototype
// ============================================================

class AptPrototype : public AptValue {
public:
    // offset 12: AptNativeHash
    // offset 32: super constructor pointer
    void DestroyGCPointers();
    void RegisterReferences() const;
    AptPrototype();
    AptValue* objectMemberLookup(AptValue* unused, EAStringC* name) const;
    int objectMemberSet(AptValue* unused, EAStringC* name, AptValue* value);
    void SetSuperConstructor(AptValue* ctor);
    ~AptPrototype();
};

// 0x802B5D54
void AptPrototype::DestroyGCPointers() {
    AptValue* superCtor = *(AptValue**)((char*)this + 32);
    if (superCtor != 0) {
        // superCtor->vt_DecRef();
    }
    *(AptValue**)((char*)this + 32) = 0;
    // AptValueWithHash::DestroyGCPointers();
}

// 0x802B5DC4
void AptPrototype::RegisterReferences() const {
    // AptValueWithHash::RegisterReferences();
    AptValue* superCtor = *(AptValue**)((char*)this + 32);
    if (superCtor != 0) {
        // g_pAptRefRegistrationCb(this, superCtor, "superCtor");
    }
}

// 0x802B6108
AptPrototype::AptPrototype() {
    // AptValue::AptValue(28); // kAptPrototype
    // vtable = AptObject_base_vtable
    // AptNativeHash::AptNativeHash(8) at offset 12
    // vtable = AptPrototype_vtable
    // Clear enumerable bit in flags
    // m_superCtor = 0; // offset 32
}

// 0x802B6174
AptValue* AptPrototype::objectMemberLookup(AptValue* unused, EAStringC* name) const {
    // if (EAStringC::Equal(name, "__constructor__"))
    //     return GetSuperConstructor();
    return 0;
}

// 0x802B61C0
int AptPrototype::objectMemberSet(AptValue* unused, EAStringC* name, AptValue* value) {
    // if (EAStringC::Equal(name, "__constructor__"))
    //     SetSuperConstructor(value);
    //     return 1;
    return 0;
}

// 0x802B6220
void AptPrototype::SetSuperConstructor(AptValue* newCtor) {
    AptValue* oldCtor = *(AptValue**)((char*)this + 32);
    *(AptValue**)((char*)this + 32) = newCtor;
    if (newCtor != 0) {
        // newCtor->vt_AddRef();
    }
    if (oldCtor != 0) {
        // oldCtor->vt_DecRef();
    }
}

// 0x802B62B8
AptPrototype::~AptPrototype() {
    // vtable = AptPrototype_dtor_vtable;
    // AptNativeHash::~AptNativeHash() at offset 12
    // AptValue::~AptValue();
    // if (flags & 1) g_pAptValueGC_PoolManager->DeallocateAptValueGC(this, 36);
}

// ============================================================
// AptLine
// ============================================================

class AptLine {
public:
    // offset 4: word list head pointer
    // offset 12: vtable for line
    void UnlinkWord(AptWord* word);
    void Draw(ERC* rc, EMat4* mat, EVec4* v1, EVec4* v2);
    ~AptLine();
};

// 0x8000DFA8
void AptLine::UnlinkWord(AptWord* word) {
    AptWord* prev = 0;
    AptWord* cur = *(AptWord**)((char*)this + 4);
    while (cur != 0) {
        if (cur == word) {
            if (cur == 0) return;
            if (prev != 0) {
                *(AptWord**)prev = *(AptWord**)cur; // prev->next = cur->next
            } else {
                *(AptWord**)((char*)this + 4) = *(AptWord**)cur; // head = cur->next
            }
            return;
        }
        prev = cur;
        cur = *(AptWord**)cur; // cur = cur->next
    }
}

// 0x8000DFF8
void AptLine::Draw(ERC* rc, EMat4* mat, EVec4* v1, EVec4* v2) {
    AptWord* word = *(AptWord**)((char*)this + 4);
    while (word != 0) {
        // word->vt_Draw(rc, mat, v1, v2) via vtable at offset 44
        word = *(AptWord**)word; // word = word->next
    }
}

// 0x8039D468
AptLine::~AptLine() {
    // vtable = AptLine_vtable
    AptWord* cur = *(AptWord**)((char*)this + 4);
    while (cur != 0) {
        AptWord* next = *(AptWord**)cur;
        // cur->vt_destructor(3) via vtable at offset 44
        cur = next;
    }
    // if (flags & 1) __builtin_delete(this);
}

// ============================================================
// AptMath - clip stack management
// ============================================================

class AptMath {
public:
    static void ClipStackMakeUnit();
    static void ClipStackInit(unsigned int maxDepth);
    static void ClipStackShutdown();
};

// 0x802A2574
void AptMath::ClipStackMakeUnit() {
    // Initialize current clip stack entry to identity matrix (4x4 floats)
    // Set transform = identity, clip region = unit, etc.
    int depth = g_aptClipStackCurDepth;
    float* data = (float*)g_pAptClipStackData;
    float* entry = data + depth * 24; // 96 bytes = 24 floats per entry
    // Set identity: entry[0]=1, entry[5]=1, entry[10]=1, rest=0
    // Copy clip rect data
    memset(entry + 16, 0, 16); // clear clip rect portion
}

// 0x802A26B0
void AptMath::ClipStackInit(unsigned int maxDepth) {
    unsigned int allocSize = maxDepth * 96 + 16;
    void* raw = 0; // g_pDOGMA_PoolManager->Allocate(allocSize);
    g_pAptClipStackRaw = raw;
    // Align to 16 bytes
    void* aligned = raw;
    if (((unsigned int)raw & 15) != 0) {
        aligned = (void*)(((unsigned int)raw + 16) & ~15u);
    }
    g_pAptClipStackData = aligned;
    g_aptClipStackMaxDepth = (short)maxDepth;
    g_aptClipStackCurDepth = 0;
    AptMath::ClipStackMakeUnit();
}

// 0x802A2714
void AptMath::ClipStackShutdown() {
    if (g_pAptClipStackData != 0) {
        unsigned int size = g_aptClipStackMaxDepth * 96 + 16;
        // g_pDOGMA_PoolManager->Deallocate(g_pAptClipStackRaw, size);
    }
    g_pAptClipStackData = 0;
}

// ============================================================
// AptMemoryAllocationsT - memory stats accumulator
// ============================================================

struct AptMemoryAllocationsT {
    int field0, field4, field8, field12, field16, field20, field24, field28;

    AptMemoryAllocationsT operator+(AptMemoryAllocationsT& other);
    void operator+=(AptMemoryAllocationsT& other);
};

// 0x80268714
AptMemoryAllocationsT AptMemoryAllocationsT::operator+(AptMemoryAllocationsT& other) {
    AptMemoryAllocationsT result;
    result.field0  = field0  + other.field0;
    result.field4  = field4  + other.field4;
    result.field8  = field8  + other.field8;
    result.field12 = field12 + other.field12;
    result.field16 = field16 + other.field16;
    result.field20 = field20 + other.field20;
    result.field24 = field24 + other.field24;
    result.field28 = field28 + other.field28;
    return result;
}

// 0x80268834
void AptMemoryAllocationsT::operator+=(AptMemoryAllocationsT& other) {
    field0  += other.field0;
    field4  += other.field4;
    field8  += other.field8;
    field12 += other.field12;
    field16 += other.field16;
    field20 += other.field20;
    field24 += other.field24;
    field28 += other.field28;
}

// ============================================================
// AptNativeFunction - multiple destructor instances at different addresses
// ============================================================

class AptNativeFunction : public AptValue {
public:
    // offset 12: AptNativeHash (inline)
    ~AptNativeFunction();
};

// 0x80287DD8 through 0x802BB6A0 (10 instances, all identical pattern)
AptNativeFunction::~AptNativeFunction() {
    // vtable = AptObject_dtor_vtable;
    // AptNativeHash::~AptNativeHash() at offset 12
    // AptValue::~AptValue();
    // if (flags & 1) g_pAptValueGC_PoolManager->DeallocateAptValueGC(this, 40);
}

// ============================================================
// AptRenderingContext - matrix stack and rendering context
// ============================================================

class AptRenderingContext {
public:
    // offset 0-31: current colour transform (8 floats)
    // offset 32-55: current vertex matrix (6 floats = AptMatrix)
    // offset 56+: colour transform stack (32 bytes per entry)
    // offset 568+: vertex matrix stack (24 bytes per entry)
    // offset 952: colour stack depth
    // offset 956: vertex stack depth
    void pushColourTransform();
    void popColourTransform();
    void appendColourTransform(AptCXForm* cxform);
    void getVertexMatrix(AptMatrix* outMatrix);
    void pushVertexMatrix();
    void popVertexMatrix();
    void multMatrix(AptMatrix* a, AptMatrix* b, AptMatrix* result);
    void appendVertexMatrix(AptMatrix* matrix);
    void expandBoundingRect(AptRect* outRect, AptRect* srcRect);
};

// 0x802AB1E4
void AptRenderingContext::pushColourTransform() {
    int depth = *(int*)((char*)this + 952);
    // Copy 32 bytes (colour transform) from this to stack[depth]
    float* src = (float*)this;
    float* dst = (float*)((char*)this + 56 + depth * 32);
    for (int i = 0; i < 8; i++) dst[i] = src[i];
    *(int*)((char*)this + 952) = depth + 1;
}

// 0x802AB25C
void AptRenderingContext::popColourTransform() {
    int depth = *(int*)((char*)this + 952) - 1;
    *(int*)((char*)this + 952) = depth;
    // Copy 32 bytes from stack[depth] back to this
    float* src = (float*)((char*)this + 56 + depth * 32);
    float* dst = (float*)this;
    for (int i = 0; i < 8; i++) dst[i] = src[i];
}

// 0x802AB2D0
void AptRenderingContext::appendColourTransform(AptCXForm* cxform) {
    float* ct = (float*)this;
    float* cx = (float*)cxform;
    // Multiply RGBA: ct[i] *= cx[i] for i=0..3
    ct[0] *= cx[0];
    ct[1] *= cx[1];
    ct[2] *= cx[2];
    ct[3] *= cx[3];
    // Add offsets: ct[i+4] += cx[i+4] for i=0..3
    ct[4] += cx[4];
    ct[5] += cx[5];
    ct[6] += cx[6];
    ct[7] += cx[7];
    // Call platform-specific update
}

// 0x802AB380
void AptRenderingContext::getVertexMatrix(AptMatrix* outMatrix) {
    int depth = *(int*)((char*)this + 956);
    if (depth > 0) {
        float* src = (float*)((char*)this + 32);
        float* dst = (float*)outMatrix;
        for (int i = 0; i < 6; i++) dst[i] = src[i];
    } else {
        // Copy from identity/default matrix
    }
}

// 0x802AB400
void AptRenderingContext::pushVertexMatrix() {
    int depth = *(int*)((char*)this + 956);
    float* src = (float*)((char*)this + 32);
    float* dst = (float*)((char*)this + 568 + depth * 24);
    for (int i = 0; i < 6; i++) dst[i] = src[i];
    *(int*)((char*)this + 956) = depth + 1;
}

// 0x802AB450
void AptRenderingContext::popVertexMatrix() {
    int depth = *(int*)((char*)this + 956) - 1;
    *(int*)((char*)this + 956) = depth;
    float* src = (float*)((char*)this + 568 + depth * 24);
    float* dst = (float*)((char*)this + 32);
    for (int i = 0; i < 6; i++) dst[i] = src[i];
    // Call platform-specific update
}

// 0x802AB4D0
void AptRenderingContext::multMatrix(AptMatrix* a, AptMatrix* b, AptMatrix* result) {
    // 2x3 matrix multiply: result = a * b
    // Layout: [a b tx; c d ty]
    float* A = (float*)a;
    float* B = (float*)b;
    float* R = (float*)result;
    R[0] = A[0]*B[0] + A[2]*B[1];
    R[1] = A[1]*B[0] + A[3]*B[1];
    R[2] = A[0]*B[2] + A[2]*B[3];
    R[3] = A[1]*B[2] + A[3]*B[3];
    R[4] = A[0]*B[4] + A[2]*B[5] + A[4];
    R[5] = A[1]*B[4] + A[3]*B[5] + A[5];
}

// 0x802AB5CC
void AptRenderingContext::appendVertexMatrix(AptMatrix* matrix) {
    float* current = (float*)((char*)this + 32);
    multMatrix((AptMatrix*)current, matrix, (AptMatrix*)current);
    // Call platform-specific update
}

// 0x802AB614
void AptRenderingContext::expandBoundingRect(AptRect* outRect, AptRect* srcRect) {
    float* src = (float*)srcRect;
    float left = src[0], top = src[1], right = src[2], bottom = src[3];
    float* mat = (float*)((char*)this + 32);

    // Transform 4 corners of srcRect through the matrix
    float cornersX[4], cornersY[4];
    float xs[4] = { left, right, left, right };
    float ys[4] = { top, top, bottom, bottom };

    for (int i = 0; i < 4; i++) {
        cornersX[i] = mat[0]*xs[i] + mat[2]*ys[i] + mat[4];
        cornersY[i] = mat[1]*xs[i] + mat[3]*ys[i] + mat[5];
    }

    // Expand outRect to include all transformed corners
    float* out = (float*)outRect;
    for (int i = 0; i < 4; i++) {
        if (cornersX[i] < out[0]) out[0] = cornersX[i]; // minX
        if (cornersX[i] > out[2]) out[2] = cornersX[i]; // maxX
        if (cornersY[i] < out[1]) out[1] = cornersY[i]; // minY
        if (cornersY[i] > out[3]) out[3] = cornersY[i]; // maxY
    }
}

// ============================================================
// AptScriptFunction1 - single-argument script function
// ============================================================

class AptScriptFunction1 {
public:
    // offset 52: action definition pointer
    AptScriptFunction1(AptScriptFunctionBase* base, AptAction_DefineFunction* def, AptCIH* cih);
    AptScriptFunction1(AptScriptFunction1* other, AptCIH* cih);
    ~AptScriptFunction1();
    void SetArgument(AptValue* value, int argIndex);
    AptValue* Duplicate(AptCIH* cih);
};

// 0x802B8010
AptScriptFunction1::AptScriptFunction1(AptScriptFunctionBase* base, AptAction_DefineFunction* def, AptCIH* cih) {
    // AptScriptFunctionBase::AptScriptFunctionBase(43, base, cih, true);
    // vtable = AptScriptFunction1_vtable;
    // m_actionDef = def; // offset 52
}

// 0x802B8060
AptScriptFunction1::AptScriptFunction1(AptScriptFunction1* other, AptCIH* cih) {
    // AptScriptFunctionBase::AptScriptFunctionBase(43, other, cih);
    // vtable = AptScriptFunction1_vtable;
    // m_actionDef = other->m_actionDef; // copy offset 52
}

// 0x802B8158
AptScriptFunction1::~AptScriptFunction1() {
    // vtable = AptScriptFunction1_vtable;
    // AptScriptFunctionBase::~AptScriptFunctionBase();
    // if (flags & 1) g_pAptValueGC_PoolManager->DeallocateAptValueGC(this, 56);
}

// 0x802B8D20
void AptScriptFunction1::SetArgument(AptValue* value, int argIndex) {
    // If no frame stack exists, create one
    // Look up argument name from action def, set in frame stack hash
}

// 0x802B8ED4
AptValue* AptScriptFunction1::Duplicate(AptCIH* cih) {
    void* mem = 0; // g_pAptValueGC_PoolManager->AllocateAptValueGC(56);
    // return new (mem) AptScriptFunction1(this, cih);
    return (AptValue*)mem;
}

// ============================================================
// AptScriptFunction2 - multi-register script function
// ============================================================

class AptScriptFunction2 {
public:
    // offset 52: action definition pointer
    AptScriptFunction2(AptScriptFunctionBase* base, AptAction_DefineFunction2* def, AptCIH* cih);
    AptScriptFunction2(AptScriptFunction2* other, AptCIH* cih);
    ~AptScriptFunction2();
    void SetupBeforeExecution(_AptScriptFunctionState* state, AptValue* thisObj);
    void CleanupAfterExecution(_AptScriptFunctionState* state);
    void SetArgument(AptValue* value, int argIndex);
    AptValue* Duplicate(AptCIH* cih);
};

// 0x802B80B4
AptScriptFunction2::AptScriptFunction2(AptScriptFunctionBase* base, AptAction_DefineFunction2* def, AptCIH* cih) {
    // AptScriptFunctionBase::AptScriptFunctionBase(44, base, cih, true);
    // vtable = AptScriptFunction2_vtable;
    // m_actionDef = def; // offset 52
}

// 0x802B8104
AptScriptFunction2::AptScriptFunction2(AptScriptFunction2* other, AptCIH* cih) {
    // AptScriptFunctionBase::AptScriptFunctionBase(44, other, cih);
    // vtable = AptScriptFunction2_vtable;
    // m_actionDef = other->m_actionDef;
}

// 0x802B81B0
AptScriptFunction2::~AptScriptFunction2() {
    // vtable = AptScriptFunction2_vtable;
    // AptScriptFunctionBase::~AptScriptFunctionBase();
    // if (flags & 1) g_pAptValueGC_PoolManager->DeallocateAptValueGC(this, 56);
}

// 0x802B84CC
void AptScriptFunction2::SetupBeforeExecution(_AptScriptFunctionState* state, AptValue* thisObj) {
    // AptScriptFunctionBase::SetupBeforeExecution(state, thisObj);
    // Save register stack state
    // Based on preloadFlags in m_actionDef:
    //   bit 0: preload "this" into register 1
    //   bit 2: preload "arguments" into next register
    //   bit 4: preload "super" into next register
    //   bit 6: preload "_root" into next register
    //   bit 7: preload "_parent" into next register
    //   bit 8: preload "_global" into next register
}

// 0x802B86E0
void AptScriptFunction2::CleanupAfterExecution(_AptScriptFunctionState* state) {
    // AptScriptFunctionBase::CleanupAfterExecution(state);
    // Restore register values from saved state
    // Reset register count/stack
}

// 0x802B8F64
void AptScriptFunction2::SetArgument(AptValue* value, int argIndex) {
    // Check if argument has a register assignment in the definition
    // If so, set directly into register
    // Otherwise, set into frame stack hash by name
}

// 0x802B913C
AptValue* AptScriptFunction2::Duplicate(AptCIH* cih) {
    void* mem = 0; // g_pAptValueGC_PoolManager->AllocateAptValueGC(56);
    // return new (mem) AptScriptFunction2(this, cih);
    return (AptValue*)mem;
}

// ============================================================
// AptSound
// ============================================================

class AptSound : public AptObject {
public:
    // offset 36: sound bank pointer
    // offset 40: sound ID
    // offset 44: sound name
    AptSound(AptCIH* cih);
    void CleanNativeFunctions();
    AptValue* sMethod_attachSound(AptValue* thisObj, int argCount);
    AptValue* sMethod_start(AptValue* thisObj, int argCount);
    AptValue* objectMemberLookup(AptValue* unused, EAStringC* name) const;
    ~AptSound();
};

// 0x802AB848
AptSound::AptSound(AptCIH* cih) {
    // AptValue::AptValue(21); // kAptSound
    // vtable = AptObject_base_vtable
    // AptNativeHash::AptNativeHash(8) at offset 12
    // m_implementedCount = 0;
    // vtable = AptSound_vtable
    // m_soundID = 0; // offset 40
    // Clear flags
    // m_soundName = 0; // offset 44
    // m_soundBank = cih->getSoundBank(); // offset 36
}

// 0x802AB8D4
void AptSound::CleanNativeFunctions() {
    // Release cached native function objects for attachSound, start, stop
    if (g_pAptSoundAttach) { /* DecRef */ g_pAptSoundAttach = 0; }
    if (g_pAptSoundStart)  { /* DecRef */ g_pAptSoundStart = 0;  }
    if (g_pAptSoundStop)   { /* DecRef */ g_pAptSoundStop = 0;   }
}

// 0x802AB9B0
AptValue* AptSound::sMethod_attachSound(AptValue* thisObj, int argCount) {
    // Verify thisObj is AptSound type
    // Get sound name string from argument
    // Search sound bank for matching name
    // Store sound ID and name in this object
    return g_pAptNoneValue;
}

// 0x802ABAEC
AptValue* AptSound::sMethod_start(AptValue* thisObj, int argCount) {
    // Verify thisObj is AptSound type
    // Play sound if valid sound ID
    return g_pAptNoneValue;
}

// 0x802ABB58
AptValue* AptSound::objectMemberLookup(AptValue* unused, EAStringC* name) const {
    // Hash lookup using SoundMembersIndex (gperf)
    // Returns cached native function for "attachSound" (1), "stop" (2), "start" (3)
    return 0;
}

// 0x802ABE34
AptSound::~AptSound() {
    // vtable = AptObject_dtor_vtable;
    // AptNativeHash::~AptNativeHash() at offset 12
    // AptValue::~AptValue();
    // if (flags & 1) g_pAptValueGC_PoolManager->DeallocateAptValueGC(this, 48);
}

// ============================================================
// AptStage
// ============================================================

class AptStage : public AptObject {
public:
    void CleanNativeFunctions();
    AptValue* objectMemberLookup(AptValue* unused, EAStringC* name) const;
    AptStage();
    ~AptStage();
};

// 0x802A8428
void AptStage::CleanNativeFunctions() {
    if (g_pAptStageWidth)  { /* DecRef */ g_pAptStageWidth = 0;  }
    if (g_pAptStageHeight) { /* DecRef */ g_pAptStageHeight = 0; }
}

// 0x802A84C4
AptValue* AptStage::objectMemberLookup(AptValue* unused, EAStringC* name) const {
    // Hash lookup using StageMembersIndex (gperf)
    // Returns stage width (float), height (float), or none
    return 0;
}

// 0x802A8A20
AptStage::AptStage() {
    // AptValue::AptValue(39); // kAptStage
    // vtable = AptObject_base_vtable
    // AptNativeHash::AptNativeHash(8) at offset 12
    // m_implementedCount = 0;
    // vtable = AptStage_vtable
    // Clear flags
    // AptValue::setGCRoot(1);
}

// 0x802A8A98
AptStage::~AptStage() {
    // vtable = AptObject_dtor_vtable;
    // AptNativeHash::~AptNativeHash() at offset 12
    // AptValue::~AptValue();
    // if (flags & 1) g_pAptValueGC_PoolManager->DeallocateAptValueGC(this, 36);
}

// ============================================================
// AptStringObject
// ============================================================

class AptStringObject : public AptObject {
public:
    // offset 36: AptString* pointer
    ~AptStringObject();
    void setString(AptString* str);
    AptValue* objectMemberLookup(AptValue* unused, EAStringC* name) const;
};

// 0x80281DE0
AptStringObject::~AptStringObject() {
    // vtable = AptStringObject_vtable;
    // if (m_string) DecRef(m_string);
    // m_string = 0;
    // AptNativeHash::~AptNativeHash() at offset 12
    // AptValue::~AptValue();
    // if (flags & 1) g_pAptValueGC_PoolManager->DeallocateAptValueGC(this, 40);
}

// 0x80281E94
void AptStringObject::setString(AptString* str) {
    // AddRef on str
    *(AptString**)((char*)this + 36) = str;
}

// 0x80281EF0
AptValue* AptStringObject::objectMemberLookup(AptValue* unused, EAStringC* name) const {
    AptString* str = *(AptString**)((char*)this + 36);
    // First check string-specific members via str->vt_memberLookup
    // If not found, fall back to AptObject::objectMemberLookup
    return 0;
}

// ============================================================
// AptValueFactory - factory for creating APT values
// ============================================================

class AptValueFactory {
public:
    static AptValue* CreateInteger(int value);
    static AptValue* CreateFloat(float value);
    static AptValue* CreateBoolean(bool value);
    static AptValue* CreateArray(int size, AptValue** elements);
    static AptValue* CreateStringFormatted(char* fmt, ...);
};

// 0x802B4DFC
AptValue* AptValueFactory::CreateInteger(int value) {
    return AptInteger::Create(value);
}

// 0x802B4EB0
AptValue* AptValueFactory::CreateFloat(float value) {
    return AptFloat::Create(value);
}

// 0x802B4F68
AptValue* AptValueFactory::CreateBoolean(bool value) {
    return AptBoolean::Create(value);
}

// 0x802B501C
AptValue* AptValueFactory::CreateArray(int size, AptValue** elements) {
    void* mem = 0; // g_pAptValueGC_PoolManager->AllocateAptValueGC(48);
    // return new (mem) AptArray(size, elements);
    return (AptValue*)mem;
}

// 0x802B5060
AptValue* AptValueFactory::CreateStringFormatted(char* fmt, ...) {
    // AptString::Create(buffer);
    // vsprintf with fmt and varargs
    return 0;
}

// ============================================================
// AptValueGC_PoolManager
// ============================================================

// 0x802B512C
void* AptValueGC_PoolManager_AllocateAptValueGC(void* poolMgr, unsigned int size) {
    void* ptr = 0; // DOGMA_PoolManager::Allocate(size);
    // Set allocation tracking bit based on pool manager mode
    return ptr;
}

// 0x802B5180
void AptValueGC_PoolManager_DeallocateAptValueGC(void* poolMgr, AptValueGC* ptr, unsigned int size) {
    // DOGMA_PoolManager::Deallocate(ptr, size);
    // Clear allocation tracking bit
}

// 0x802B51E8
AptValue* AptValueGC_PoolManager_GetNextAptValue(void* poolMgr, AptValue* current) {
    // Walk pool blocks to find next allocated AptValue after current
    // Check allocation bit to determine if slot is in use
    // Returns next live AptValue or null
    return 0;
}

// 0x802B5420
AptValue* AptValueGC_PoolManager_GetFirstAptValue(void* poolMgr) {
    // Walk pool blocks to find first allocated AptValue
    return 0;
}

// 0x802B54EC
void AptValueGC_PoolManager_VerifyList(void* poolMgr) {
    // Walk all AptValues to verify list integrity
    AptValue* val = AptValueGC_PoolManager_GetFirstAptValue(poolMgr);
    while (val != 0) {
        val = AptValueGC_PoolManager_GetNextAptValue(poolMgr, val);
    }
}

// 0x802B5534
void AptValueGC_PoolManager_StaticInitialize() {
    // Initialize pool manager configuration
    // Set allocation tracking mode, find min/max allocation sizes
}

// ============================================================
// AptValueVector
// ============================================================

class AptValueVector {
public:
    int m_capacity;  // offset 0
    int m_count;     // offset 4
    AptValue** m_data; // offset 8

    AptValueVector(int capacity);
    ~AptValueVector();
    void ReleaseValues();
};

// 0x802BC04C
AptValueVector::AptValueVector(int capacity) {
    m_count = 0;
    m_capacity = capacity;
    m_data = 0; // (AptValue**)g_pDOGMA_PoolManager->Allocate(capacity * 4);
}

// 0x802BC098
AptValueVector::~AptValueVector() {
    // g_pDOGMA_PoolManager->Deallocate(m_data, m_capacity * 4);
    // if (flags & 1) g_pDOGMA_PoolManager->Deallocate(this, 12);
}

// 0x802BC0F0
void AptValueVector::ReleaseValues() {
    while (m_count > 0) {
        m_count--;
        AptValue* val = m_data[m_count];
        unsigned int flags = *(unsigned int*)val;
        unsigned int refCount = (flags >> 14) & 0xFFF;
        if (refCount == 0) {
            // Call virtual AddRef via vtable
        } else {
            // Clear ref bits
            *(unsigned int*)val = flags & ~0x3FFC000u;
        }
    }
}

// ============================================================
// AptXmlAttributes
// ============================================================

class AptXmlAttributes : public AptObject {
public:
    // offset 36: IAptXmlNode* pointer
    ~AptXmlAttributes();
    AptXmlAttributes(AptVirtualFunctionTable_Indices idx, IAptXmlNode* node);
    int objectMemberSet(AptValue* unused, EAStringC* name, AptValue* value);
};

// 0x802C4DEC
AptXmlAttributes::~AptXmlAttributes() {
    *(void**)((char*)this + 36) = 0;
    // AptNativeHash::~AptNativeHash() at offset 12
    // AptValue::~AptValue();
    // if (flags & 1) g_pAptValueGC_PoolManager->DeallocateAptValueGC(this, 40);
}

// 0x802C4E5C
AptXmlAttributes::AptXmlAttributes(AptVirtualFunctionTable_Indices idx, IAptXmlNode* node) {
    // AptValue::AptValue(idx);
    // vtable = AptObject_base_vtable
    // AptNativeHash::AptNativeHash(8) at offset 12
    // m_implementedCount = 0;
    // vtable = AptXmlAttributes_vtable
    // m_node = node; // offset 36
    // Clear flags
}

// 0x802C4ED8
int AptXmlAttributes::objectMemberSet(AptValue* unused, EAStringC* name, AptValue* value) {
    // Only handles AptXmlNode type (34) with string/key values
    // Sets attribute on the underlying XML node
    return 1;
}

// ============================================================
// AptPseudoDisplayList
// ============================================================

class AptPseudoDisplayList {
public:
    // offset 0: sentinel/root node pointer
    void ClearList();
    void FindInst(int depth, AptPseudoCIH_t** outPrev, AptPseudoCIH_t** outFound);
    void Insert(AptPseudoCIH_t* inst);
    void Insert(AptPseudoCIH_t* afterNode, AptPseudoCIH_t* inst, AptPseudoCIH_t* existing);
    void Remove(AptPseudoCIH_t* inst);
};

// 0x80299074
void AptPseudoDisplayList::ClearList() {
    void** root = (void**)this;
    void* sentinel = *root;
    void* node = *(void**)((char*)sentinel + 8); // sentinel->next
    while (node != 0) {
        void* next = *(void**)((char*)node + 8);
        // Clean up node's data, delete node
        node = next;
    }
}

// 0x80299100
void AptPseudoDisplayList::FindInst(int depth, AptPseudoCIH_t** outPrev, AptPseudoCIH_t** outFound) {
    void** root = (void**)this;
    void* prev = *root;
    void* cur = *(void**)((char*)prev + 8);
    while (cur != 0) {
        int curDepth = *(int*)((char*)cur + 16);
        if (curDepth >= depth) {
            if (curDepth == depth) {
                *outFound = (AptPseudoCIH_t*)cur;
            } else {
                *outFound = 0;
            }
            *outPrev = (AptPseudoCIH_t*)prev;
            return;
        }
        prev = cur;
        cur = *(void**)((char*)cur + 8);
    }
    *outFound = 0;
    *outPrev = (AptPseudoCIH_t*)prev;
}

// 0x80299150
void AptPseudoDisplayList::Insert(AptPseudoCIH_t* inst) {
    AptPseudoCIH_t* prev = 0;
    AptPseudoCIH_t* found = 0;
    int depth = *(int*)((char*)inst + 16);
    FindInst(depth, &prev, &found);
    if (found != 0) {
        Remove(found);
        FindInst(depth, &prev, &found);
    }
    // Insert(prev, inst);
}

// 0x802992A4
void AptPseudoDisplayList::Remove(AptPseudoCIH_t* inst) {
    // Unlink from doubly-linked list
    void* next = *(void**)((char*)inst + 8);
    void* prev = *(void**)((char*)inst + 12);
    if (prev) *(void**)((char*)prev + 8) = next;
    if (next) *(void**)((char*)next + 12) = prev;
    // Clean up and delete inst
}

// ============================================================
// Font System
// ============================================================

class EFontCharacter {
public:
    // offset 4: texture rect (int)
    // offset 8: char rect (int)
    // offset 12: width (short)
    // offset 14: advance (short)
    void Write(EStream& stream);
    void Read(EStream& stream);
    void Load(EFile& file);
    static void RegisterType(unsigned short typeId);
};

// 0x80363560
void EFontCharacter::Write(EStream& stream) {
    // Write 4 fields: rect.x(4), rect.y(4), width(2), advance(2)
    // Each via stream.vt_Write()
}

// 0x8036362C
void EFontCharacter::Read(EStream& stream) {
    // Read 4 fields from stream (checking version flag)
}

// 0x803636E8
void EFontCharacter::Load(EFile& file) {
    // Read 4 fields from file (checking version flag)
}

// 0x80364760
void EFontCharacter::RegisterType(unsigned short typeId) {
    // ETypeInfo::Register(factory, destructor, cleanup, typeId, "EFontCharacter", parent);
}

class EFontPage {
public:
    // offset 4: texture ID (int)
    // offset 8: shader pointer
    // offset 12: width (int)
    // offset 16: height (int)
    void Write(EStream& stream);
    void Read(EStream& stream);
    void Load(EFile& file);
    void DeallocateShader();
    static void RegisterType(unsigned short typeId);
};

// 0x80363864
void EFontPage::Write(EStream& stream) {
    // Write textureID, width, height
}

// 0x80363908
void EFontPage::Read(EStream& stream) {
    DeallocateShader();
    // Read textureID, width, height (version check)
}

// 0x803639A8
void EFontPage::Load(EFile& file) {
    DeallocateShader();
    // Read textureID, width, height from file
}

// 0x803648B4
void EFontPage::RegisterType(unsigned short typeId) {
    // ETypeInfo::Register(factory, destructor, cleanup, typeId, "EFontPage", parent);
}

class EFontSize {
public:
    // offset 0: vtable
    // offset 4: point size (int)
    // offset 8: ascent (int)
    // offset 12: line height (int)
    // offset 16: EHashTable<uint, EFontCharacter*>
    // offset 32: TArray<EFontPage*>
    EFontSize();
    ~EFontSize();
    void Deallocate();
    void DeallocateShaders();
    void Write(EStream& stream);
    void Read(EStream& stream);
    void Load(EFile& file);
    static void RegisterType(unsigned short typeId);
};

// 0x80363B28
EFontSize::EFontSize() {
    // vtable = EFontSize_vtable;
    // EHashTable::EHashTable(237) at offset 16
    // TArray::TArray() at offset 32
    // m_pointSize = 0; m_lineHeight = 1; m_ascent = 0;
}

// 0x80363B88
EFontSize::~EFontSize() {
    // vtable = EFontSize_vtable;
    // Deallocate();
    // TArray::~TArray() at offset 32
    // EHashTable::~EHashTable() at offset 16
    // if (flags & 1) __builtin_delete(this);
}

// 0x80363BF8
void EFontSize::Deallocate() {
    // Walk hash table, delete all EFontCharacter entries
    // EHashTable::RemoveAll() at offset 16
    // DeallocatePages();
}

// 0x80363C74
void EFontSize::DeallocateShaders() {
    // For each page in the array, call DeallocateShader()
}

// 0x80363CFC through 0x80363E68 (Write, Read, Load)
// Standard serialization: point size, ascent, line height, character hash, page array

class EFontData {
public:
    // offset 0: vtable
    // offset 4: ENodeList<EFontSize*>
    // offset 16-36: various int fields
    // offset 40: EHashTable<uint, int>
    EFontData();
    ~EFontData();
    void Deallocate();
    void Write(EStream& stream);
    void Read(EStream& stream);
    void Load(EFile& file);
    static void RegisterType(unsigned short typeId);
};

// 0x80364024
EFontData::EFontData() {
    // vtable = EFontData_vtable;
    // ENodeList init at offset 4
    // EHashTable::EHashTable(237) at offset 40
    // Zero all int fields
}

// 0x80364098
EFontData::~EFontData() {
    // vtable = EFontData_vtable;
    // Deallocate();
    // EHashTable::~EHashTable() at offset 40
    // ENodeList::RemoveAll() at offset 4
    // if (flags & 1) __builtin_delete(this);
}

// 0x80364104
void EFontData::Deallocate() {
    // Walk node list, delete each EFontSize
    // ENodeList::RemoveAll() at offset 4
    // EHashTable::RemoveAll() at offset 40
}

// ============================================================
// UI Items (TextItem, ButtonItem, MenuItem)
// ============================================================

class TextBaseItem {
public:
    void Startup();
    void Reset();
    void SetStyle(int style);
};

class TextBlock {
public:
    void Clear();
    void SetDirty();
};

class PaneItem {
public:
    void Startup();
    void Reset();
};

class TextItem {
public:
    // offset 0: type
    // offset 4: flags
    // offset 8: ???
    // offset 12-24: position floats
    // offset 28: vtable
    // offset 32-107: TextBlock (inline)
    // offset 108: data ptr
    TextItem();
    ~TextItem();
    void Startup();
};

// 0x8008480C
void TextItem::Startup() {
    // TextBaseItem::Startup();
    // TextBaseItem::SetStyle(g_textItemStyle);
    // Set line spacing in TextBlock
    // TextBlock::SetDirty();
    // flags |= 2;
}

// 0x800873AC
TextItem::TextItem() {
    // PaneItem vtable
    // type = 0; flags = 1;
    // TextBlock::Clear() on inline text block
    // m_data = 0;
    // TextBaseItem::Startup();
    // TextBaseItem::Reset();
    // vtable = TextItem_vtable;
    // Startup();
    // flags = 1;
}

// 0x80087458
TextItem::~TextItem() {
    // vtable = TextBaseItem_vtable;
    // if (m_data) MainHeap()->Free(m_data);
    // vtable = PaneItem_vtable;
    // PaneItem::Startup();
    // PaneItem::Reset();
    // if (flags & 1) __builtin_delete(this);
}

class ButtonItem {
public:
    ButtonItem();
    ~ButtonItem();
    void Startup();
};

// 0x800848BC
void ButtonItem::Startup() {
    // TextBaseItem::Startup();
    // TextBaseItem::SetStyle(g_buttonItemStyle);
    // Set line spacing
    // TextBlock::SetDirty();
    // flags |= 2;
}

// 0x800875FC
ButtonItem::ButtonItem() {
    // Similar to TextItem but with ButtonItem vtable
    // type = 2;
}

// 0x800876AC
ButtonItem::~ButtonItem() {
    // vtable = TextBaseItem_vtable;
    // if (m_data) MainHeap()->Free(m_data);
    // PaneItem::Startup(); PaneItem::Reset();
    // if (flags & 1) __builtin_delete(this);
}

class MenuItem {
public:
    MenuItem();
    ~MenuItem();
    void Startup();
};

// 0x80084864
void MenuItem::Startup() {
    // TextBaseItem::Startup();
    // TextBaseItem::SetStyle(g_menuItemStyle);
    // Set line spacing
    // TextBlock::SetDirty();
    // flags |= 2;
}

// 0x800874D4
MenuItem::MenuItem() {
    // PaneItem vtable; type = 1; flags = 1;
    // TextBlock::Clear(); m_data = 0;
    // TextBaseItem::Startup(); TextBaseItem::Reset();
    // vtable = MenuItem_vtable; Startup(); flags = 1;
}

// 0x80087580
MenuItem::~MenuItem() {
    // vtable = TextBaseItem_vtable;
    // if (m_data) MainHeap()->Free(m_data);
    // PaneItem::Startup(); PaneItem::Reset();
    // if (flags & 1) __builtin_delete(this);
}

// ============================================================
// DialogPaneBase
// ============================================================

class WrapperPaneBase {
public:
    void Startup();
    void Shutdown();
};

class DialogPaneBase {
public:
    // offset 0: type count
    // offset 4: flags
    // offset 8: vector (std::vector<PaneItem*>) at offsets 8-20
    // offset 24-91: various layout fields
    // offset 92: vtable2
    // offset 96: text item 1
    // offset 100: text item 2
    DialogPaneBase(int type, int itemCount);
    ~DialogPaneBase();
    void Startup();
};

// 0x800863CC
void DialogPaneBase::Startup() {
    // WrapperPaneBase::Startup();
    // Create TextItem for field 96, add to vector
    // Create TextItem for field 100, add to vector
    // Set style to 5 for both
}

// 0x80088B6C
DialogPaneBase::DialogPaneBase(int type, int itemCount) {
    // vtable2 = DialogPaneBase_vtable;
    // m_type = type;
    // m_flags = 0;
    // Initialize vector with (itemCount + 2) capacity
    // Initialize layout floats
    // WrapperPaneBase::Startup();
    // vtable2 = DialogPaneBase_vtable2;
    // Startup();
}

// 0x80088CA4
DialogPaneBase::~DialogPaneBase() {
    // vtable2 = DialogPaneBase_vtable;
    // WrapperPaneBase::Shutdown();
    // Free vector storage
    // if (flags & 1) __builtin_delete(this);
}

// ============================================================
// UIDialog
// ============================================================

class UIDialog {
public:
    // offset 0-39: various fields (0=0, 4=0, etc.)
    // offset 20: enabled flag
    // offset 24: selected index
    // offset 28-36: more fields
    // offset 40-59: 5x BString2 (4 bytes each = ptr)
    // offset 60: resource ptr
    // offset 64: ???
    // offset 68: resource ptr 2
    // offset 72-131: callback data
    // offset 132: vtable
    UIDialog();
    ~UIDialog();
    void HideDialog();
};

// 0x801B7100
UIDialog::~UIDialog() {
    // vtable = UIDialog_vtable;
    // Release resources at offset 60 and 68
    // Destroy BString2 at offsets 56, 52, 48, 44, 40
    // if (flags & 1) __builtin_delete(this);
}

// 0x801B7208
void UIDialog::HideDialog() {
    // Clear all 4 BString2 strings (erase(0, -1))
    // G2DTarget::HideDialog();
}

// 0x801E6F2C
UIDialog::UIDialog() {
    // Zero all fields 0-36
    // vtable = UIDialog_vtable;
    // enabled = 1; selectedIndex = -1;
    // Construct 5 BString2 objects
    // Initialize all to empty wchar_t string
    // Zero resources, callbacks, etc.
}

// ============================================================
// UIRouter
// ============================================================

class GetVariableCommandTable;
class SetVariableCommandTable;

class UIRouter {
public:
    // offset 0-39: various fields
    // offset 40-119: 5 pairs of (data, size) = 5 * 16 bytes
    // offset 120: ???
    // offset 128: vtable
    // offset 132: get variable table
    // offset 136: set variable table
    UIRouter();
    ~UIRouter();
    AptValue* GetVariable(char* name);
    void SetVariable(char* name, char* value);
};

// 0x8017EDA8
UIRouter::UIRouter() {
    // vtable = UIRouter_vtable;
    // Zero all fields
    // Create GetVariableCommandTable singleton if needed
    // Create SetVariableCommandTable singleton if needed
    // AptViewer::NewSetMessageHandler(this);
}

// 0x8017EEA4
UIRouter::~UIRouter() {
    // vtable = UIRouter_intermediate_vtable;
    // AptViewer::NewRemoveMessageHandler(this);
    // vtable = UIRouter_base_vtable;
    // if (flags & 1) __builtin_delete(this);
}

// 0x8017EF08
AptValue* UIRouter::GetVariable(char* name) {
    int len = strlen(name);
    if (len == 0) return 0;
    if (len > 63) len = 63;
    char buf[64];
    strncpy(buf, name, len + 1);
    if (len == 63) buf[63] = 0;
    // Prefix matching for special variable names
    // GetVariableCommandTable::ExecuteCommand(buf, name);
    return 0;
}

// 0x8017EFE0
void UIRouter::SetVariable(char* name, char* value) {
    int len = strlen(name);
    if (len == 0) return;
    if (len > 63) len = 63;
    char buf[64];
    strncpy(buf, name, len + 1);
    if (len == 63) buf[63] = 0;
    // Prefix matching
    // SetVariableCommandTable::ExecuteCommand(buf, name, value);
}

// ============================================================
// Loading Screen States
// ============================================================

struct FaderState {
    float m_duration;   // offset 168 from owner
    float m_rate;       // offset 172 (4 from fader base)
    float m_elapsed;    // offset 176 (8 from fader base)
    int   m_flags;      // offset 180 (12 from fader base)
    // flags: bit 0=interpolating_up, bit 1=interpolating_down
    //        bit 2=at_max, bit 3=at_min, bit 4=active
};

class LoadingScreenFadeInState {
public:
    void Update(float dt);
    void DrawTopmost(ERC* rc);
    void FaderUpdate(float dt);
    float FaderGetFadeOpacity();
};

// 0x8009027C
void LoadingScreenFadeInState::Update(float dt) {
    FaderUpdate(dt);
    // Check if fade complete (opacity reached target)
    // If so, transition to next state
    // Update loading screen if it exists
}

// 0x8009038C
void LoadingScreenFadeInState::DrawTopmost(ERC* rc) {
    // Get loading screen from state machine
    // Calculate opacity from fader state
    // Draw loading screen with computed opacity
}

// 0x800910D0
void LoadingScreenFadeInState::FaderUpdate(float dt) {
    // Subtract dt from elapsed time
    // If elapsed <= 0, transition fader state (up->max, down->min)
}

// 0x80091140
float LoadingScreenFadeInState::FaderGetFadeOpacity() {
    // Calculate opacity based on fader flags:
    // Interpolating up: (duration - elapsed) * rate
    // Interpolating down: elapsed * rate
    // At max: 1.0f
    // At min: 0.0f
    return 0.0f;
}

class LoadingScreenFadeOutState {
public:
    void Update(float dt);
    void DrawTopmost(ERC* rc);
    void FaderUpdate(float dt);
    float FaderGetFadeOpacity();
};

// 0x8009060C, 0x80090704, 0x80091348, 0x800913B8
// Same pattern as FadeInState but with fade-out logic

class LoadingScreenUpdateState {
public:
    void Update(float dt);
    void DrawTopmost(ERC* rc);
    float FaderGetFadeOpacity();
};

// 0x80090454, 0x80090544, 0x80091264
// Holds at full opacity, triggers fade out when load complete

// ============================================================
// QuickData classes
// ============================================================

class ObjectDataID {
public:
    void SetNamespaceID(unsigned int id);
    void SetResourceID(unsigned short id);
    void operator=(ObjectDataID& other);
};

class ObjectDataBehaviorConstants {
public:
    ObjectDataBehaviorConstants();
    ~ObjectDataBehaviorConstants();
};

class QuickDataBehaviorConstants : public ObjectDataBehaviorConstants {
public:
    // offset 0: vtable
    // offset 4: data count (short)
    // offset 8: ObjectDataID
    // offset 24: data pointer
    // offset 28: ref count
    void* operator new(unsigned int size);
    void operator delete(void* ptr);
    int LoadFromIndex(unsigned int namespaceID, int index);
    int LoadFromDataID(ObjectDataID& dataID);
    int QueryInterface(unsigned int iid, void** outPtr);
    int Release();
    QuickDataBehaviorConstants();
    ~QuickDataBehaviorConstants();
};

// 0x80159DE4
void* QuickDataBehaviorConstants::operator new(unsigned int size) {
    if (size == 32) {
        // Check fixed pool for available block
        // Return from pool if available
    }
    return MainHeap()->Malloc(size, 0);
}

// 0x80159E50
void QuickDataBehaviorConstants::operator delete(void* ptr) {
    // Check if ptr is within fixed pool range
    // If so, return to pool free list
    // Otherwise, MainHeap()->Free(ptr)
}

// 0x80159EE4
int QuickDataBehaviorConstants::LoadFromIndex(unsigned int namespaceID, int index) {
    // Load behavior constants from QuickData resource by namespace and index
    // Returns 1 on success, 0 on failure
    return 0;
}

// 0x80159FBC
int QuickDataBehaviorConstants::LoadFromDataID(ObjectDataID& dataID) {
    // Copy data ID, look up in resource manager
    // Find matching BehaviorConstants record
    // Returns 1 on success, 0 on failure
    return 0;
}

// 0x8015A070
int QuickDataBehaviorConstants::QueryInterface(unsigned int iid, void** outPtr) {
    if (outPtr == 0) return 0;
    if (iid == 1 || iid == 0xE7B8CB34) {
        // AddRef via vtable
        *outPtr = this;
        return 1;
    }
    return 0;
}

// 0x8015A0F4
int QuickDataBehaviorConstants::Release() {
    int refCount = *(int*)((char*)this + 28) - 1;
    *(int*)((char*)this + 28) = refCount;
    if (refCount == 0) {
        // Call virtual destructor(3)
        return 0;
    }
    return refCount;
}

// 0x8015A738
QuickDataBehaviorConstants::QuickDataBehaviorConstants() {
    // ObjectDataBehaviorConstants::ObjectDataBehaviorConstants();
    // vtable = QuickDataBehaviorConstants_vtable;
    // m_refCount = 0;
}

// 0x8015A77C
QuickDataBehaviorConstants::~QuickDataBehaviorConstants() {
    // vtable = QuickDataBehaviorConstants_vtable;
    // ObjectDataBehaviorConstants::~ObjectDataBehaviorConstants();
    // if (flags & 1) operator delete(this);
}

// ============================================================
// MembersIndex classes (gperf hash tables)
// All follow same pattern: in_word_set(char*, unsigned int) -> entry*
// ============================================================

// DateMembersIndex, KeyMembersIndex, MathMembersIndex,
// SpriteMembersIndex, StageMembersIndex, StringMembersIndex,
// TextFormatMembersIndex, TextMembersIndex, XmlMemberIndex,
// ArrayMembersIndex
//
// These are gperf-generated perfect hash tables.
// Each has a static word list and hash function.
// in_word_set() computes hash, validates match, returns entry or null.

// ============================================================
// Command tables (gperf dispatch tables)
// SetVariableCommandTable, GetVariableCommandTable,
// GetLocalizableCommandTable
// ============================================================

// Same pattern as MembersIndex: gperf hash lookup dispatching
// to command handler functions by name.

// ============================================================
// Remaining stubs - simple patterns
// ============================================================

// ESpriteRenderMan, FlashBigFile, FloatConstantsQuickData,
// HelpDialog, IconGroupImpl, IconItem, PaneItem,
// QuickDataSlotDescList, QuickDataSoundInfo, QuickResFile,
// ReconBuilder, SerializeUIGameData, SpriteSlot,
// StartScreenStartState, StartScreenVars, TextBaseItem,
// TextFormat, TheSimsEnterMainMenuState,
// TheSimsStartScreenStateMachine, TreeTableEntryQuickData,
// UIAUDIOTarget, UIButtonImages, UIDrawTable, UIHDTV,
// UIObjectBase, UIUpdateTable, UIUserDrawCBTable,
// EQuickdataManager, ERFlash,
// ENgcTexture, ENgcTextureC4_32, ENgcTextureC8_32,
// ENgcTextureUtil, LoadingScreenWaitingForLoadState,
// ObjFnTableQuickData, ScrollingTextBox
//
// These follow standard patterns documented above:
// - Constructors: set vtable, init fields, call parent ctor
// - Destructors: set vtable, cleanup, conditional delete
// - QuickData: binary resource accessors
// - LoadingScreen: Enter/Exit/Update state machine pattern
// - MembersIndex/CommandTable: gperf hash dispatch
