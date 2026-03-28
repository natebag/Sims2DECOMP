#ifndef ERESOURCEMANAGER_H
#define ERESOURCEMANAGER_H

#include "types.h"

// EResourceManager - struct layout extracted from assembly analysis
// Estimated minimum size: 0xD20 (3360 bytes)
// 11 known fields (5 named), 130 methods

class EResourceManager {
public:
    // Constructors / Destructors
    EResourceManager(void)  // 0x8088C974
    ~EResourceManager(void);  // 0x8088CA08

    // Methods
    void Free(void *);  // 0x80890DD8 (132B)
    void Shutdown(void);  // 0x8088CB18 (248B)
    void CalcId(char *);  // 0x8089045C (232B)
    void DelRef(unsigned int, EResourceManager::DelRefMode);  // 0x8088F7A4 (388B)
    void Init(char *);  // 0x8088CC10 (1404B)
    void AddRefAll(void);  // 0x8088D834 (464B)
    void Alloc(unsigned long, unsigned int);  // 0x80890C68 (368B)
    bool IsValid(unsigned int);  // 0x80890208 (92B)
    void DelRefAsync(unsigned int);  // 0x8088FA2C (472B)
    void AddRefAsync(unsigned int);  // 0x8088F31C (88B)
    /* ? */ GetRef(unsigned int);  // 0x8088DE94 (428B)
    void DelRef(EResource *, EResourceManager::DelRefMode);  // 0x8088FC04 (976B)
    void LookupId(EResourceManager *, unsigned int, unsigned int &, unsigned int &);  // 0x80897908 (92B)
    void AddRefAsync(char *);  // 0x8088F254 (200B)
    /* ? */ GetHeap(void);  // 0x80890B14 (64B)
    bool CanCache(void);  // 0x80897874 (40B)
    bool CanCache(EResource *);  // 0x8089789C (108B)
    /* ? */ GetRef(char *);  // 0x8088E040 (188B)
    void MakeSpace(void);  // 0x80890B54 (108B)
    void PushLoggingOutput(char *);  // 0x80890544 (368B)
    void PopLoggingOutput(void);  // 0x808906B4 (344B)
    bool IsLoaded(unsigned int);  // 0x80890264 (124B)
    void PreloadResource(unsigned int);  // 0x8088E198 (304B)
    void PreloadResource(char *);  // 0x8088E2C8 (92B)
    void FreeUnreferencedResources(void);  // 0x80890BC0 (96B)
    void AddResource(EResource *, unsigned int);  // 0x8088EB28 (76B)
    void DelRefAll(void);  // 0x8088DBF4 (148B)
    void AddRef(unsigned int, EFile *, int);  // 0x8088F0F8 (96B)
    void AddRef(char *, EFile *, int);  // 0x8088F158 (252B)
    void TryIncrementResource(unsigned int, EResource **);  // 0x8088E6B0 (980B)
    void RefreshResources(void);  // 0x8088F42C (60B)
    /* ? */ GetArchiveFile(void);  // 0x8088D2AC (484B)
    void CloseArchiveFile(void);  // 0x8088D57C (112B)
    void AddDelRefAll(void);  // 0x8088DA04 (496B)
    void PrintLoadedResources(void);  // 0x8088DC88 (88B)
    void PrintUnmanagedResources(void);  // 0x8088DD38 (348B)
    void PrintResourceSizes(void);  // 0x8088DCE0 (88B)
    /* ? */ GetUnreferencedResourceCount(void);  // 0x80890C20 (72B)
    void LookupId(unsigned int, unsigned int &, unsigned int &);  // 0x8088D6E4 (336B)
    void AddResource(EResource *, unsigned int, bool);  // 0x8088EC38 (1216B)
    void LogResourceLoad(EResource *);  // 0x8088EB74 (196B)
    void ResourceDestructing(EResource *);  // 0x8089033C (288B)
    void Detach(EResource *);  // 0x8088FFD4 (256B)
    void AddRef(EResource *);  // 0x8088F65C (328B)
    void Refresh(EResource *);  // 0x8088F468 (188B)
    /* ? */ GetPos(unsigned int);  // 0x808900D4 (108B)
    /* ? */ GetSize(unsigned int);  // 0x80890140 (200B)
    void ReadData(void *, unsigned int, unsigned int);  // 0x8088E0FC (156B)
    void ArchiveFileIsOpen(void);  // 0x8088D518 (100B)
    void ArchiveFileIsUsingHDD(void);  // 0x8088D490 (136B)
    void SetLoggingOutput(char *, bool);  // 0x8089080C (776B)
    void DelRef(char *, EResourceManager::DelRefMode);  // 0x8088F928 (184B)
    /* ? */ GetOverriddenFile(unsigned int, unsigned int &);  // 0x80890E5C (228B)
    void CalcPath(void);  // 0x8088D18C (288B)
    void BinarySearch(unsigned int, unsigned int *, int);  // 0x8088D5EC (248B)
    void addRef(unsigned int, EFile *, unsigned int, bool);  // 0x8088E324 (908B)
    bool IsResourceIncludedInLog(char *);  // 0x8088EA84 (164B)
    /* ? */ GetIds(unsigned int *&, int &);  // 0x8088F374 (184B)
    void Refresh(unsigned int);  // 0x8088F524 (236B)
    void Refresh(char *);  // 0x8088F610 (76B)
    void DelRefAsync(char *);  // 0x8088F9E0 (76B)
    bool IsLoaded(char *);  // 0x808902E0 (92B)
    bool IsInitialized(void);  // 0x80897848 (44B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [R/W] - vtable pointer (AddDelRefAll, AddRef, AddRefAll, ...)
    u32 m_field_004;  // 0x004 [R/W] (AddDelRefAll, AddRefAll, ResourceIndexRecord * __unguarded_partition<EResourceManager::ResourceIndexRecord *, EResourceManager::ResourceIndexRecord, bool)
    u32 m_field_008;  // 0x008 [R/W] (AddDelRefAll, AddRefAll, ResourceIndexRecord * __unguarded_partition<EResourceManager::ResourceIndexRecord *, EResourceManager::ResourceIndexRecord, bool)
    s16 m_ref_00C;  // 0x00C [R/W] (AddDelRefAll, AddRefAll, GetRef)
    u8 _pad_00E[0x32];  // 0x00E
    u32 m_field_040;  // 0x040 [R/W] (AddResource, CalcPath, Init, ...)
    u32 m_archiveFile;  // 0x044 [R] (CalcPath, GetArchiveFile, ~EResourceManager)
    u32 m_field_048;  // 0x048 [R/W] (DelRef, Detach, EResourceManager, ...)
    u32 m_field_04C;  // 0x04C [R/W] (AddDelRefAll, AddRefAll, DelRefAll, ...)
    u32 m_archiveFile_050;  // 0x050 [R/W] (ArchiveFileIsOpen, ArchiveFileIsUsingHDD, CloseArchiveFile, ...)
    u32 m_archiveFile_054;  // 0x054 [R/W] (EResourceManager, GetArchiveFile)
    u8 _pad_058[0xCC4];  // 0x058
    u32 m_field_D1C;  // 0xD1C [R/W] (Alloc, DelRef, EResourceManager, ...)
};

#endif // ERESOURCEMANAGER_H
