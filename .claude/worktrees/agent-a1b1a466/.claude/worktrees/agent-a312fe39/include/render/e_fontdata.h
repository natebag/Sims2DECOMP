#ifndef E_FONTDATA_H
#define E_FONTDATA_H

#include "types.h"

// Forward declarations
class EStream;
class EFile;
class EResource;
class EStorable;

// ============================================================================
// ETypeInfo - Runtime type information for EStorable-derived classes
// Used by the serialization system for factory creation and versioning
// Size: at least 0x18
// ============================================================================
struct ETypeInfo {
    u32 m_field_00;          // +0x00
    u32 m_field_04;          // +0x04
    u32 m_field_08;          // +0x08
    const char* m_pName;     // +0x0C - type name string
    u32 m_nKey;              // +0x10 - type key / hash
    u16 m_nVersion;          // +0x14 - current version
    u16 m_nReadVersion;      // +0x16 - read version
};

// ============================================================================
// EStorable - Base class for serializable engine objects
// Defined in base_ngc_release_dvd.lib(e_storable.obj)
// We only need the forward-declared interface here
// Size: 0x04 (vtable pointer)
// ============================================================================

// ============================================================================
// TArray - Template dynamic array
// ============================================================================
struct TArrayDefaultAllocator {};

template<typename T, typename Alloc = TArrayDefaultAllocator>
class TArray {
public:
    T* m_pData;     // +0x00
    int m_nSize;    // +0x04
    int m_nAlloc;   // +0x08

    void Init(void);
    TArray(void);
    ~TArray(void);
    void Destruct(T* ptr, int count);
    void Construct(T* ptr, int count);
    void Copy(T* dst, T* src, int count);
    void Deallocate(void);
    void SafeDeleteAll(void);
    void SetSize(int size, int growBy);
};

// ============================================================================
// THashTable - Template hash table (forward declared, used by EFontPage)
// ============================================================================
template<typename K, typename V>
class THashTable;

// ============================================================================
// TNodeList - Template linked list (forward declared, used by EFontData)
// ============================================================================
template<typename T>
class TNodeList;

// ============================================================================
// EFontCharacter - Individual font character data
// Size: 0x10
// Vtable at 0x8046D9E8
// Object file: engine_ngc_release_dvd.lib(e_fontdata.obj)
// ============================================================================
class EFontCharacter {
public:
    // vtable at +0x00
    u32 m_field_04;   // +0x04
    u32 m_field_08;   // +0x08
    u32 m_field_0C;   // +0x0C

    // Virtual functions (vtable order)
    virtual void SafeDelete(void);                          // +0x0C
    virtual const ETypeInfo* GetTypeInfo(void) const;       // +0x14
    virtual const char* GetTypeName(void) const;            // +0x1C
    virtual u32 GetTypeKey(void) const;                     // +0x24
    virtual u16 GetTypeVersion(void) const;                 // +0x2C
    virtual ~EFontCharacter();                              // +0x34
    virtual void Read(EStream& stream);                     // +0x3C
    virtual void Write(EStream& stream);                    // +0x44
    virtual void Load(EFile& file);                         // +0x4C

    // Static factory functions
    static EFontCharacter* New(void);
    static void Construct(EFontCharacter* obj);
    static void Destruct(EFontCharacter* obj);
    static const ETypeInfo* GetTypeInfoStatic(void);
    static u16 GetReadVersion(void);
    static void RegisterType(u16 version);

    // Non-virtual member functions
    EFontCharacter* CreateCopy(void) const;
};

// ============================================================================
// EFontPage - Page of font characters (maps character codes to glyphs)
// Size: 0x14
// Vtable at 0x8046D990
// ============================================================================
class EFontPage {
public:
    // vtable at +0x00
    u32 m_field_04;           // +0x04 - zeroed in ctor
    EResource* m_pShader;     // +0x08 - shader resource, zeroed in ctor
    u32 m_field_0C;           // +0x0C - not initialized in ctor
    u32 m_field_10;           // +0x10 - not initialized in ctor

    EFontPage(void);

    // Virtual functions
    virtual void SafeDelete(void);
    virtual const ETypeInfo* GetTypeInfo(void) const;
    virtual const char* GetTypeName(void) const;
    virtual u32 GetTypeKey(void) const;
    virtual u16 GetTypeVersion(void) const;
    virtual ~EFontPage();
    virtual void Read(EStream& stream);
    virtual void Write(EStream& stream);
    virtual void Load(EFile& file);

    // Non-virtual
    void DeallocateShader(void);

    // Static factory functions
    static EFontPage* New(void);
    static void Construct(EFontPage* obj);
    static void Destruct(EFontPage* obj);
    static const ETypeInfo* GetTypeInfoStatic(void);
    static u16 GetReadVersion(void);
    static void RegisterType(u16 version);
    EFontPage* CreateCopy(void) const;
};

// ============================================================================
// EFontSize - Font at a specific size (contains pages)
// Size: 0x2C
// Vtable at 0x8046D938
// ============================================================================
class EFontSize {
public:
    // vtable at +0x00
    u32 m_field_04;                       // +0x04
    u32 m_field_08;                       // +0x08
    u32 m_field_0C;                       // +0x0C
    u32 m_field_10;                       // +0x10
    u32 m_field_14;                       // +0x14
    u32 m_field_18;                       // +0x18
    u32 m_field_1C;                       // +0x1C
    TArray<EFontPage*> m_pages;           // +0x20 (size 0x0C)

    EFontSize(void);

    // Virtual functions
    virtual void SafeDelete(void);
    virtual const ETypeInfo* GetTypeInfo(void) const;
    virtual const char* GetTypeName(void) const;
    virtual u32 GetTypeKey(void) const;
    virtual u16 GetTypeVersion(void) const;
    virtual ~EFontSize();
    virtual void Read(EStream& stream);
    virtual void Write(EStream& stream);
    virtual void Load(EFile& file);

    // Non-virtual
    void Deallocate(void);
    void DeallocatePages(void);
    void DeallocateShaders(void);

    // Static factory functions
    static EFontSize* New(void);
    static void Construct(EFontSize* obj);
    static void Destruct(EFontSize* obj);
    static const ETypeInfo* GetTypeInfoStatic(void);
    static u16 GetReadVersion(void);
    static void RegisterType(u16 version);
    EFontSize* CreateCopy(void) const;
};

// ============================================================================
// EFontData - Top-level font data container (contains font sizes)
// Size: 0x38
// Vtable at 0x8046D8E0
// ============================================================================
class EFontData {
public:
    // vtable at +0x00 (inherited from EStorable)
    // ... member fields ...

    EFontData(void);

    // Virtual functions
    virtual void SafeDelete(void);
    virtual const ETypeInfo* GetTypeInfo(void) const;
    virtual const char* GetTypeName(void) const;
    virtual u32 GetTypeKey(void) const;
    virtual u16 GetTypeVersion(void) const;
    virtual ~EFontData();
    virtual void Read(EStream& stream);
    virtual void Write(EStream& stream);
    virtual void Load(EFile& file);

    // Non-virtual
    void Deallocate(void);

    // Static factory functions
    static EFontData* New(void);
    static void Construct(EFontData* obj);
    static void Destruct(EFontData* obj);
    static const ETypeInfo* GetTypeInfoStatic(void);
    static u16 GetReadVersion(void);
    static void RegisterType(u16 version);
    EFontData* CreateCopy(void) const;
};

// ============================================================================
// Global type info pointers (BSS)
// ============================================================================
extern ETypeInfo* gpTypeInfo_EFontCharacter;
extern ETypeInfo* gpTypeInfo_EFontPage;
extern ETypeInfo* gpTypeInfo_EFontSize;
extern ETypeInfo* gpTypeInfo_EFontData;

// ============================================================================
// Stream operators
// ============================================================================
EStream& operator<<(EStream& stream, EFontCharacter* obj);
EStream& operator>>(EStream& stream, EFontCharacter*& obj);
EFile&   operator>>(EFile& file, EFontCharacter*& obj);

EStream& operator<<(EStream& stream, EFontPage* obj);
EStream& operator>>(EStream& stream, EFontPage*& obj);
EFile&   operator>>(EFile& file, EFontPage*& obj);

EStream& operator<<(EStream& stream, EFontSize* obj);
EStream& operator>>(EStream& stream, EFontSize*& obj);
EFile&   operator>>(EFile& file, EFontSize*& obj);

EStream& operator<<(EStream& stream, EFontData* obj);
EStream& operator>>(EStream& stream, EFontData*& obj);
EFile&   operator>>(EFile& file, EFontData*& obj);

// ============================================================================
// External functions used by this module
// ============================================================================
extern EStream& operator<<(EStream& stream, EStorable* obj);
extern EStream& operator>>(EStream& stream, EStorable*& obj);
extern EFile&   operator>>(EFile& file, EStorable*& obj);

#endif // E_FONTDATA_H
