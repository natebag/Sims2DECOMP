#ifndef ERESOURCELOADERIMPL_H
#define ERESOURCELOADERIMPL_H

#include "types.h"

// EResourceLoaderImpl - struct layout extracted from assembly analysis
// Estimated minimum size: 0xD08 (3336 bytes)
// 26 known fields (5 named), 92 methods

class EResourceLoaderImpl {
public:
    // Constructors / Destructors
    EResourceLoaderImpl(void)  // 0x808422E0
    ~EResourceLoaderImpl(void);  // 0x808423E0

    // Methods
    /* ? */ GetQueueStats(int &, int &, int &, int &);  // 0x808421C4 (92B)
    /* ? */ GetQueuedCommandCount(void);  // 0x80842220 (72B)
    bool IsBusy(void);  // 0x80842268 (120B)
    void Shutdown(void);  // 0x808424E4 (396B)
    void TerminateThread(void);  // 0x80842670 (240B)
    void sendCommand(EResLoadCmd *);  // 0x80842E60 (208B)
    bool IsCallingThread(void);  // 0x80842760 (72B)
    void Init(void);  // 0x808427A8 (452B)
    void allocateGlobalIndex(void);  // 0x80844CE0 (1196B)
    void RefreshResources(void);  // 0x8084296C (808B)
    void LoadRecentlyBuiltFilesList(void);  // 0x80842C94 (320B)
    void Update(void);  // 0x80842E40 (32B)
    void FlushCommandQueue(char *, int);  // 0x80842F30 (628B)
    void AddManager(EResourceManager *);  // 0x808431A4 (420B)
    void getIndexPointer(EString &);  // 0x8084518C (296B)
    void RemoveManager(EResourceManager *);  // 0x80843348 (312B)
    void CollapseDelRef(EResourceManager *, unsigned int);  // 0x80843480 (88B)
    bool IsInQueue(EResourceManager *, unsigned int);  // 0x808434D8 (88B)
    void Load(EResourceManager *, unsigned int, EFile *, unsigned int, unsigned int, bool);  // 0x80843530 (704B)
    void DoLoadResource(EResourceManager *, unsigned int, EFile *, unsigned int, unsigned int);  // 0x80845D10 (1392B)
    void Unload(EResourceManager *, unsigned int);  // 0x808437F0 (288B)
    void ReadData(EFile *, void *, unsigned int, unsigned int, bool, EResLoadCmdResult *);  // 0x80843910 (900B)
    void ReadData(EResourceManager *, void *, unsigned int, unsigned int, bool, EResLoadCmdResult *);  // 0x80843C94 (716B)
    void WriteData(EFile *, void *, unsigned int, unsigned int, bool, EResLoadCmdResult *);  // 0x80843F60 (900B)
    void FindResourceManager(char *);  // 0x808442E4 (112B)
    void FindResourceManagerInternal(char *);  // 0x80844354 (160B)
    void OpenFiles(void);  // 0x808443F4 (200B)
    void CloseArchiveFile(EResourceManager *);  // 0x808444BC (448B)
    void AddRefDelRefAllResources(void);  // 0x8084467C (184B)
    void PrintLoadedResources(void);  // 0x80844734 (148B)
    void PrintLoadedResources(char *);  // 0x808447C8 (128B)
    void PrintResourceSizes(void);  // 0x80844848 (144B)
    void PrintResourceSizes(char *);  // 0x808448D8 (128B)
    void FreeUnreferencedResources(void);  // 0x80844958 (176B)
    void FreeUnreferencedResources(char *);  // 0x80844A08 (164B)
    /* ? */ GetUnreferencedResourceCount(void);  // 0x80844AAC (152B)
    /* ? */ GetUnreferencedResourceCount(char *);  // 0x80844B44 (164B)
    void deallocateGlobalIndex(void);  // 0x80844BE8 (248B)
    void Main(void);  // 0x808452B4 (160B)
    void ProcessMessage(unsigned int);  // 0x80845354 (2492B)
    void EnableReloads(bool);  // 0x80847D18 (40B)
    void PauseLoads(void);  // 0x80847D40 (40B)
    void UnPauseLoads(void);  // 0x80847D68 (68B)
    void AreLoadsPaused(void);  // 0x80847DAC (44B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [R/W] - vtable pointer (AddRefDelRefAllResources, CloseArchiveFile, EResourceLoaderImpl, ...)
    u32 m_field_004;  // 0x004 [R/W] (CloseArchiveFile, Load, ReadData, ...)
    u32 m_field_008;  // 0x008 [W] (Load, ReadData, Unload, ...)
    u32 m_field_00C;  // 0x00C [W] (Load, ReadData, Unload, ...)
    s16 m_field_010;  // 0x010 [R/W] (CloseArchiveFile, DoLoadResource, Load, ...)
    u8 _pad_012[2];  // 0x012
    u32 m_field_014;  // 0x014 [R/W] (CloseArchiveFile, Load, ReadData, ...)
    s16 m_field_018;  // 0x018 [R/W] (CloseArchiveFile, ReadData, WriteData)
    u8 _pad_01A[2];  // 0x01A
    u32 m_field_01C;  // 0x01C [R/W] (CloseArchiveFile, FlushCommandQueue, ReadData, ...)
    u32 m_field_020;  // 0x020 [W] (CloseArchiveFile, Load, ReadData, ...)
    u8 _pad_024[4];  // 0x024
    s16 m_field_028;  // 0x028 [R] (CloseArchiveFile, FlushCommandQueue, Unload)
    u8 _pad_02A[2];  // 0x02A
    u32 m_field_02C;  // 0x02C [R] (CloseArchiveFile, FlushCommandQueue, Unload)
    u8 _pad_030[8];  // 0x030
    s16 m_field_038;  // 0x038 [R] (CloseArchiveFile, Load)
    u8 _pad_03A[2];  // 0x03A
    u32 m_field_03C;  // 0x03C [R] (CloseArchiveFile, Load)
    u32 m_field_040;  // 0x040 [R] (AddManager, AddRefDelRefAllResources)
    u8 _pad_044[8];  // 0x044
    u32 m_field_04C;  // 0x04C [W] (deallocateGlobalIndex)
    u8 _pad_050[0x20];  // 0x050
    s16 m_field_070;  // 0x070 [R] (ReadData)
    u8 _pad_072[0x2CE];  // 0x072
    u32 m_field_340;  // 0x340 [W] (EResourceLoaderImpl, ~EResourceLoaderImpl)
    u8 _pad_344[4];  // 0x344
    u32 m_unreferencedResourceCount_348;  // 0x348 [R/W] (AddManager, AddRefDelRefAllResources, EResourceLoaderImpl, ...)
    u32 m_field_34C;  // 0x34C [W] (EResourceLoaderImpl)
    u32 m_field_350;  // 0x350 [R/W] (EResourceLoaderImpl, Init, RemoveManager, ...)
    u8 _pad_354[8];  // 0x354
    u32 m_unreferencedResourceCount_35C;  // 0x35C [R] (AddManager, AddRefDelRefAllResources, CloseArchiveFile, ...)
    u8 _pad_360[0x80];  // 0x360
    u32 m_field_3E0;  // 0x3E0 [W] (EResourceLoaderImpl)
    u32 m_bIsBusy;  // 0x3E4 [R/W] (EResourceLoaderImpl, Init, IsBusy, ...)
    u32 m_bIsBusy_3E8;  // 0x3E8 [R/W] (EResourceLoaderImpl, Init, IsBusy, ...)
    u8 _pad_3EC[0x914];  // 0x3EC
    u32 m_field_D00;  // 0xD00 [W] (AddManager)
    u32 m_field_D04;  // 0xD04 [R/W] (AddManager, AddRefDelRefAllResources, OpenFiles, ...)
};

#endif // ERESOURCELOADERIMPL_H
