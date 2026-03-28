#ifndef RESFILE_H
#define RESFILE_H

#include "types.h"

// Forward declarations
class StringBuffer;
class ReconBuffer;
class ResFile;

template <int N>
class StackString;

namespace Memory {
    class HandleNode;
}

// SCID - Service Class ID for dynamic casting
typedef int SCID;

// SCID constants used by _dyncastimpl
// 0x0C = ObjResFile ID
// 0x0D = StdResFile ID
// 0x0E = SeqResFile ID
// 0x0F = ChainResFile ID
// 0x10 = iResFile base ID
// 0x11 = QuickResFile ID

// ============================================================================
// iResFile - Abstract base class for resource files
// Size: 0x10
// Vtable at 0x804643B8
// Object file: resfile.obj
// ============================================================================
class iResFile {
public:
    /* +0x00 */ iResFile* m_next;     // linked list next pointer
    /* +0x04 */ int m_error;          // error code
    /* +0x08 */ ResFile* m_resFileData; // associated ResFile data
    /* +0x0C */ void* m_vtable2;      // secondary vtable pointer

    static iResFile* sFileList; // global linked list of all iResFile instances

    iResFile(void);
    virtual ~iResFile(void);

    void Link(void);
    void Unlink(void);

    int GetError(void);
    void SetError(int error);
    ResFile* GetResFileData(void) const;
    void SetResFileData(ResFile* data);

    virtual iResFile* _dyncastimpl(SCID id);
    virtual int Create(StringBuffer& name) = 0;
    virtual int Delete(StringBuffer& name) = 0;
    virtual int Open(StringBuffer& name) = 0;
    virtual int Close(void) = 0;
    virtual int CloseForReopen(void) = 0;
    virtual int Reopen(void) = 0;
    virtual void Update(void) = 0;
    virtual int Writable(void) = 0;
    virtual void GetFileName(StringBuffer& name) = 0;
    virtual int ValidFile(void) = 0;
    virtual int CountTypes(void) = 0;
    virtual int GetIndType(short index) = 0;
    virtual int Count(int type) = 0;
    virtual Memory::HandleNode* GetByIDAndLanguage(int type, short id, char lang, void (*callback)(void*, int)) = 0;
    virtual Memory::HandleNode* GetByID(int type, short id, void (*callback)(void*, int)) = 0;
    virtual Memory::HandleNode* GetByName(int type, StringBuffer& name, void (*callback)(void*, int)) = 0;
    virtual Memory::HandleNode* GetByIndex(int type, short index, void (*callback)(void*, int)) = 0;
    virtual void GetName(Memory::HandleNode* node, StringBuffer& name) = 0;
    virtual int GetLanguage(Memory::HandleNode* node);
    virtual int GetResType(Memory::HandleNode* node) = 0;
    virtual void GetID(Memory::HandleNode* node, short* id) = 0;
    virtual void GetIndex(Memory::HandleNode* node, short* index) = 0;
    virtual void FindUniqueName(int type, StringBuffer& name) = 0;
    virtual int FindUniqueID(int type) = 0;
    virtual void Detach(Memory::HandleNode* node) = 0;
    virtual void Load(Memory::HandleNode* node) = 0;
    virtual int IsLittleEndian(Memory::HandleNode* node) = 0;
    virtual void SetID(Memory::HandleNode* node, short id) = 0;
    virtual int Add(Memory::HandleNode* node, int type, short id, StringBuffer& name, bool flag) = 0;
    virtual int AddWithLanguage(Memory::HandleNode* node, int type, short id, StringBuffer& name, char lang, bool flag);
    virtual int Write(Memory::HandleNode* node) = 0;
    virtual int Remove(Memory::HandleNode* node) = 0;
    virtual void SetInfo(Memory::HandleNode* node, short id, StringBuffer& name, char lang) = 0;

    int Open(StringBuffer& name, int flags);
    void Release(Memory::HandleNode* node);

    enum OpenFlags {
        // flags TBD
    };
};

// ============================================================================
// ChainResFile - Chains multiple iResFile instances together
// Size: ~0xD0
// Vtable at 0x8045EAB8
// Object file: chainresfile.obj
//
// Layout:
//   +0x00 - +0x0C: iResFile base
//   +0x10: first file slot (ptr at +0x10, data at +0x14..+0x28)
//   Each slot is 0x18 bytes, 8 slots total
// ============================================================================
class ChainResFile : public iResFile {
public:
    struct FileSlot {
        /* +0x00 */ iResFile* m_file;
        /* +0x04 */ void* m_data;     // additional data per slot
        /* +0x08 */ u32 m_pad[4];
        /* +0x18 */ int m_active;     // whether this slot is active
    };

    /* +0x10 */ iResFile* m_files[8];   // file pointers (stride 0x18)
    // ... additional slot data interleaved

    ChainResFile(void);
    virtual ~ChainResFile(void);

    void AddFile(iResFile* file);
    short CountFiles(void);

    virtual iResFile* _dyncastimpl(SCID id);
    virtual int Create(StringBuffer& name);
    virtual int Delete(StringBuffer& name);
    virtual int Open(StringBuffer& name);
    virtual int Close(void);
    virtual int CloseForReopen(void);
    virtual int Reopen(void);
    virtual void Update(void);
    virtual int Writable(void);
    virtual void GetFileName(StringBuffer& name);
    virtual int ValidFile(void);
    virtual int CountTypes(void);
    virtual int GetIndType(short index);
    virtual int Count(int type);
    virtual Memory::HandleNode* GetByIDAndLanguage(int type, short id, char lang, void (*callback)(void*, int));
    virtual Memory::HandleNode* GetByID(int type, short id, void (*callback)(void*, int));
    virtual Memory::HandleNode* GetByName(int type, StringBuffer& name, void (*callback)(void*, int));
    virtual Memory::HandleNode* GetByIndex(int type, short index, void (*callback)(void*, int));
    virtual void GetName(Memory::HandleNode* node, StringBuffer& name);
    virtual int GetLanguage(Memory::HandleNode* node);
    virtual int GetResType(Memory::HandleNode* node);
    virtual void GetID(Memory::HandleNode* node, short* id);
    virtual void GetIndex(Memory::HandleNode* node, short* index);
    virtual void FindUniqueName(int type, StringBuffer& name);
    virtual int FindUniqueID(int type);
    virtual void Detach(Memory::HandleNode* node);
    virtual void Load(Memory::HandleNode* node);
    virtual int IsLittleEndian(Memory::HandleNode* node);
    virtual void SetID(Memory::HandleNode* node, short id);
    virtual int Add(Memory::HandleNode* node, int type, short id, StringBuffer& name, bool flag);
    virtual int AddWithLanguage(Memory::HandleNode* node, int type, short id, StringBuffer& name, char lang, bool flag);
    virtual int Write(Memory::HandleNode* node);
    virtual int Remove(Memory::HandleNode* node);
    virtual void SetInfo(Memory::HandleNode* node, short id, StringBuffer& name, char lang);
};

// ============================================================================
// QuickResFile - Quick/lightweight resource file wrapper
// Size: ~0x10
// Vtable at 0x80464180
// Object file: quickresfile.obj
// ============================================================================
class QuickResFile : public iResFile {
public:
    QuickResFile(void);
    virtual ~QuickResFile(void);

    virtual iResFile* _dyncastimpl(SCID id);
    virtual int Create(StringBuffer& name);
    virtual int Delete(StringBuffer& name);
    virtual int Open(StringBuffer& name);
    virtual int Close(void);
    virtual int CloseForReopen(void);
    virtual int Reopen(void);
    virtual void Update(void);
    virtual int Writable(void);
    virtual void GetFileName(StringBuffer& name);
    virtual int ValidFile(void);
    virtual int CountTypes(void);
    virtual int GetIndType(short index);
    virtual int Count(int type);
    virtual Memory::HandleNode* GetByIDAndLanguage(int type, short id, char lang, void (*callback)(void*, int));
    virtual Memory::HandleNode* GetByID(int type, short id, void (*callback)(void*, int));
    virtual Memory::HandleNode* GetByName(int type, StringBuffer& name, void (*callback)(void*, int));
    virtual Memory::HandleNode* GetByIndex(int type, short index, void (*callback)(void*, int));
    virtual void GetName(Memory::HandleNode* node, StringBuffer& name);
    virtual int GetLanguage(Memory::HandleNode* node);
    virtual int GetResType(Memory::HandleNode* node);
    virtual void GetID(Memory::HandleNode* node, short* id);
    virtual void GetIndex(Memory::HandleNode* node, short* index);
    virtual void FindUniqueName(int type, StringBuffer& name);
    virtual int FindUniqueID(int type);
    virtual void Detach(Memory::HandleNode* node);
    virtual void Load(Memory::HandleNode* node);
    virtual int IsLittleEndian(Memory::HandleNode* node);
    virtual void SetID(Memory::HandleNode* node, short id);
    virtual int Add(Memory::HandleNode* node, int type, short id, StringBuffer& name, bool flag);
    virtual int AddWithLanguage(Memory::HandleNode* node, int type, short id, StringBuffer& name, char lang, bool flag);
    virtual int Write(Memory::HandleNode* node);
    virtual int Remove(Memory::HandleNode* node);
    virtual void SetInfo(Memory::HandleNode* node, short id, StringBuffer& name, char lang);

    void GetString(StringBuffer& buffer, short id, short index);
};

// ============================================================================
// ObjResFile - Object resource file
// Size: ~0x10
// Vtable at 0x80462158
// Object file: objresfile.obj
// ============================================================================
class ObjResFile : public iResFile {
public:
    ObjResFile(void);
    virtual ~ObjResFile(void);

    virtual iResFile* _dyncastimpl(SCID id);
    virtual int Open(StringBuffer& name);
};

// ============================================================================
// SeqResFile - Sequential resource file
// Size: ~0xD4
// Vtable at 0x80464508
// Object file: seqresfile.obj
// ============================================================================
class SeqResFile : public iResFile {
public:
    struct OpenSpec {
        int m_type;
        char* m_extension;
    };

    // data members up to +0xD0
    u8 m_pad[0xC4];        // padding to reach m_numOpenSpecs
    /* +0xD0 */ int m_numOpenSpecs;

    SeqResFile(void);
    virtual ~SeqResFile(void);

    void ClearOpenSpecs(void);
    void AddOpenSpec(int type, char* ext);

    virtual iResFile* _dyncastimpl(SCID id);
    virtual int Create(StringBuffer& name);
    virtual int Delete(StringBuffer& name);
    virtual int Open(StringBuffer& name);
    virtual int Close(void);
    virtual void GetFileName(StringBuffer& name);
};

// ============================================================================
// StdResFile - Standard resource file (SeqResFile subclass)
// Vtable at 0x80464E38
// Object file: stdresfile.obj
// ============================================================================
class StdResFile : public SeqResFile {
public:
    StdResFile(void);
    virtual ~StdResFile(void);

    virtual iResFile* _dyncastimpl(SCID id);
    virtual int Open(StringBuffer& name);
};

// ============================================================================
// EdithResFile - Edith resource file (SeqResFile subclass)
// Vtable at 0x80464D08
// Object file: stdresfile.obj
// ============================================================================
class EdithResFile : public SeqResFile {
public:
    EdithResFile(void);
    virtual ~EdithResFile(void);

    virtual int Open(StringBuffer& name);
};

// ============================================================================
// NghLayout - NGH file layout descriptor
// ============================================================================
struct NghLayout {
    /* +0x00 */ int m_field_0;
    /* +0x04 */ int m_field_4;
    /* +0x08 */ int m_field_8;
    /* +0x0C */ int m_numSubSections;
    /* +0x10 */ int m_totalSize;
    /* +0x14 */ int m_numSections;
};

// ============================================================================
// NghResFileWriteInfo - Write info node for NGH
// ============================================================================
struct NghResFileWriteInfo;

// ============================================================================
// NghResFileSectionHeader - Section header in NGH file
// ============================================================================
struct NghResFileSectionHeader;

// ============================================================================
// EMC_OpStatus - Memory card operation status
// ============================================================================
struct EMC_OpStatus;

// Forward declare NghResFile for MemoryCardCache
class NghResFile;

// ============================================================================
// MemoryCardCache - Cache for memory card data
// ============================================================================
class MemoryCardCache {
public:
    void Init(NghLayout* layout);
    void Destroy(void);
    void GetSection(NghLayout* layout, char* data, unsigned int offset, unsigned int size);
    void PutSection(NghLayout* layout, char* data, unsigned int offset, unsigned int size);
    void CacheNghSection(NghLayout* layout, char* data, unsigned int offset, unsigned int size);
    int SaveAllToMemoryCard(int slot);
    int LoadCacheFromMemoryCard(int slot);
    int LoadCacheFromMemoryCard(int slot, NghResFile* file);
    void LoadConfigFromMemoryCard(int slot);
    void PutConfig(char* data, unsigned int size);
    int GetConfig(char* data, unsigned int size, int slot);
    int GetMemoryUsage(NghLayout* layout);
    int GetSubSectionMemoryUsage(NghLayout* layout, int section);
};

// ============================================================================
// NghResFile - NGH resource file implementation
// Size: large, many members
// Vtable at 0x80460830
// Object file: nghresfile.obj
// ============================================================================
class NghResFile : public iResFile {
public:
    typedef int RegistryID;
    typedef int SectionID;

    struct SaveRecord {
        // details TBD
    };

    struct RegistryNode {
        // details TBD
    };

    /* +0x20 */ int m_sourceType;
    /* +0x24 */ int m_currentHouse;     // stored as 0-based internally, 1-based externally
    /* +0x28 */ char m_fileName[256];   // placeholder for file name storage

    // Thumbnail GUIDs start at offset +0x194
    // m_thumbGUIDs[36] at +0x194

    // +0x13C: house contents array (pointers to section data)

    // +0x184: write ref count (short)

    // +0x18C: m_storeChecksum (bool stored as int)

    static unsigned int m_uBothSectionChecksum;
    static unsigned int m_uLastBothSectionChecksum;

    NghResFile(void);
    virtual ~NghResFile(void);

    void init(void);
    void reset(void);

    // iResFile overrides - many are stubs returning 0
    virtual iResFile* _dyncastimpl(SCID id);
    virtual int Create(StringBuffer& name);
    virtual int Delete(StringBuffer& name);
    virtual int Open(StringBuffer& name);
    virtual int Close(void);
    virtual int CloseForReopen(void);
    virtual int Reopen(void);
    virtual void Update(void);
    virtual int Writable(void);
    virtual void GetFileName(StringBuffer& name);
    virtual int ValidFile(void);
    virtual int CountTypes(void);
    virtual int GetIndType(short index);
    virtual int Count(int type);
    virtual Memory::HandleNode* GetByIDAndLanguage(int type, short id, char lang, void (*callback)(void*, int));
    virtual Memory::HandleNode* GetByID(int type, short id, void (*callback)(void*, int));
    virtual Memory::HandleNode* GetByName(int type, StringBuffer& name, void (*callback)(void*, int));
    virtual Memory::HandleNode* GetByIndex(int type, short index, void (*callback)(void*, int));
    virtual void GetName(Memory::HandleNode* node, StringBuffer& name);
    virtual int GetResType(Memory::HandleNode* node);
    virtual void GetID(Memory::HandleNode* node, short* id);
    virtual void GetIndex(Memory::HandleNode* node, short* index);
    virtual void FindUniqueName(int type, StringBuffer& name);
    virtual int FindUniqueID(int type);
    virtual void Detach(Memory::HandleNode* node);
    virtual void Load(Memory::HandleNode* node);
    virtual int IsLittleEndian(Memory::HandleNode* node);
    virtual void SetID(Memory::HandleNode* node, short id);
    virtual int Add(Memory::HandleNode* node, int type, short id, StringBuffer& name, bool flag);
    virtual int Write(Memory::HandleNode* node);
    virtual int Remove(Memory::HandleNode* node);
    virtual void SetInfo(Memory::HandleNode* node, short id, StringBuffer& name, char lang);

    // NGH-specific methods
    void SetCurrentHouse(unsigned int house);
    unsigned int GetCurrentHouse(void) const;
    int GetSourceType(void) const;

    int PrepareMemCardWrite(char* data, unsigned char flag);
    int FinishMemCardWrite(char* data, unsigned char flag);

    int GetThumbIdFromFamilyAndIndex(int family, int index);
    void StoreFamilyThumbGUID(int family, int index, unsigned int guid);
    void StoreThumbGUID(unsigned int thumbId, unsigned int guid);
    unsigned int GetThumbGUID(unsigned int thumbId);
    unsigned short GetResIDFromThumbGUID(unsigned int guid);

    bool AreHouseContentsLoaded(unsigned int house) const;

    void SwapTwoByteNumber(unsigned short* ptr);
    void SwapFourByteNumber(unsigned int* ptr);

    int IsIDRegistered(RegistryID id);
    int FindNodeInRegistry(RegistryID id, RegistryNode& node);

    void SetStoreChecksum(bool value);
    bool GetStoreChecksum(void);
    void ResetChecksums(void);

    void SetFileName(char* name);
    MemoryCardCache* GetMemoryCardCache(void);

    void RegisterSection(RegistryID id,
        void (*loadFunc)(SectionID, SaveRecord&),
        void (*saveFunc)(SectionID, SaveRecord&),
        void (*completeFunc)(SectionID, SaveRecord&));

    int SectionLoadViaRegistry(RegistryID id, SectionID secId, SaveRecord& record);
    int SectionSaveViaRegistry(RegistryID id, SectionID secId, SaveRecord& record);
    int SaveCompleteViaRegistry(RegistryID id, SectionID secId, SaveRecord& record);

    void FlushHouseData(unsigned int house);
    void FlushCharacterData(bool flag);
    void FlushNeighborData(void);
    void FlushAllData(void);
    void FlushSection(unsigned int section);
    void FlushAllHouseContents(void);
    void FlushHouseContents(unsigned int house);

    void GetDefaultNghPath(char* path, StackString<260>& result);
};

// ============================================================================
// IFF Resource File types
// ============================================================================

struct IFFHeader;

struct IFFResNode {
    // details managed by vector
};

struct IFFResList {
    // details managed by vector
};

class IFFResMap {
public:
    int CountTypes(void);
    void DoStream(ReconBuffer* buffer, int direction);
};

class IFFResFile2 : public iResFile {
public:
    // member at +0x10: EString filename
    // member at +0x11C: m_writable (int)
    // member at +0x134: MemFile vtable pointer
    // member at +0x148: m_optimizeTarget (int)

    struct MemFile {
        // nested MemFile class
    };

    IFFResFile2(void);
    virtual ~IFFResFile2(void);

    virtual int Writable(void);
    virtual void GetFileName(StringBuffer& name);
    virtual int ValidFile(void);
    virtual Memory::HandleNode* GetByID(int type, short id, void (*callback)(void*, int));
    virtual int Add(Memory::HandleNode* node, int type, short id, StringBuffer& name, bool flag);
    virtual int AddWithLanguage(Memory::HandleNode* node, int type, short id, StringBuffer& name, char lang, bool flag);

    void SetOptimizeTarget(void);
};

class IFFBehResFile : public IFFResFile2 {
public:
    virtual ~IFFBehResFile(void);
};

// ============================================================================
// SimpleReconObject<IFFResMap>
// ============================================================================
template <class T>
class SimpleReconObject {
public:
    /* +0x00 */ void* m_vtable;
    /* +0x04 */ T* m_object;
    /* +0x08 */ unsigned int m_type;

    virtual ~SimpleReconObject(void);
    virtual void DoStream(ReconBuffer* buffer, int direction);
    virtual unsigned int GetType(void);
};

// ============================================================================
// Free functions
// ============================================================================

// IFF helpers
short GetLanguage(short value);
void SetLanguage(short* dest, char lang);

// NGH helpers
int GetNumNghSubSections(NghLayout* layout);
int GetTotalSaveGameSize(void);
int GetTotalNumberOfSaveGameSections(void);
unsigned int getCurrentbuildVerNum(int a, int b, int c, int d);
int GetNghIndex(int value);
int GetHouseIndex(int value);
int GetUserIndex(int value);

int SaveAllMemoryCardCache(int slot);
int LoadCacheFromMemoryCard(int slot);
int LoadCacheFromMemoryCard(NghResFile* file, int slot);
int GetTotalMemoryCardCacheSize(void);
int GetMemoryCardCacheSectionSize(unsigned int section);

int PutConfigInMemoryCardCache(char* data, unsigned int size);
int GetConfigFromMemoryCardCache(char* data, unsigned int size, int slot);

void TMtraceNull(...);

// External functions referenced
void StringBuffer_Clear(StringBuffer& buf);  // at 0x800a6610
void StringBuffer_CopyFrom(StringBuffer& dest, StringBuffer& src);  // at 0x800a6768
int EString_IsValid(void* estring);  // at 0x800a62f0
void EString_GetFileName(void* estring, StringBuffer& dest);  // at 0x800a641c

#endif // RESFILE_H
