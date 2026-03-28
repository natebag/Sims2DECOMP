#ifndef OBJECTFOLDERIMPL_H
#define OBJECTFOLDERIMPL_H

#include "types.h"

// ObjectFolderImpl - struct layout extracted from assembly analysis
// Estimated minimum size: 0x6D4 (1748 bytes)
// 39 known fields (10 named), 142 methods

class ObjectFolderImpl {
public:
    // Constructors / Destructors
    ObjectFolderImpl(void)  // 0x802C3C7C
    ~ObjectFolderImpl(void);  // 0x802C3E24

    // Methods
    void Destroy(void);  // 0x802C4AB4 (924B)
    void CountSelectors(void);  // 0x802C3F20 (72B)
    /* ? */ GetSelectorByGUID(int);  // 0x802C3F68 (88B)
    /* ? */ GetNextSelector(ObjSelector *);  // 0x802C3FC0 (200B)
    /* ? */ GetSubTileSelector(ObjSelector *, int, int, int);  // 0x802C4088 (516B)
    /* ? */ GetLeadSelector(ObjSelector *);  // 0x802C428C (472B)
    /* ? */ GetNthSubSelector(ObjSelector *, int);  // 0x802C4464 (440B)
    /* ? */ GetQueueShaderByGUID(int);  // 0x802C461C (244B)
    /* ? */ GetMasterSelector(ObjSelector *);  // 0x802C4710 (536B)
    void Init(char *, bool);  // 0x802C4928 (396B)
    void LoadDatabase(void);  // 0x802C5D20 (2188B)
    void DestroySelector(ObjSelector *);  // 0x802C4E50 (952B)
    void AddUserSelector(int, short);  // 0x802C5208 (924B)
    /* ? */ GetSemiGlobalID(unsigned int);  // 0x802C55A4 (248B)
    void AddSelector(ObjDefinition *, char *, char *, ResFile *, short, Sim::NPC *);  // 0x802C569C (1160B)
    void OpenResFile(ObjSelector *);  // 0x802C5B24 (384B)
    void CloseResFile(ObjSelector *);  // 0x802C5CA4 (96B)
    void ReconSelector(ObjSelector **, ReconBuffer *, bool, int);  // 0x802C65AC (740B)
    /* ? */ GetSelectorByBehavior(Behavior *);  // 0x802C6890 (264B)
    void ReconBehavior(Behavior **, ReconBuffer *, int);  // 0x802C6998 (832B)
    /* ? */ GetPersonGlobNamespaceID(void);  // 0x802C6CD8 (264B)
    /* ? */ GetFileByID(unsigned int);  // 0x802C6DE0 (384B)
    void LoadUserData(iResFile *);  // 0x802C6F60 (912B)
    void SaveUserData(iResFile *);  // 0x802C75E4 (1064B)
    void CreateNewUserSelector(void);  // 0x802C7A0C (152B)
    void RemoveSelector(ObjSelector *);  // 0x802C7AA4 (388B)
    void ForceDataPreload(ObjSelector *, bool);  // 0x802C7C28 (504B)
    void forceDataPreload(ObjSelector *, bool);  // 0x802C7E20 (260B)
    void CreatingInstance(ObjSelector *);  // 0x802C7F24 (168B)
    void DeletingInstance(ObjSelector *);  // 0x802C7FCC (204B)
    void UnloadData(ObjSelector *);  // 0x802C8A24 (252B)
    void CreatingResFile(iResFile *);  // 0x802C8098 (36B)
    void DeletingResFile(iResFile *);  // 0x802C80BC (36B)
    void PrepareForModuleLoad(iResFile *);  // 0x802C80E0 (644B)
    void PrepareForModuleSave(iResFile *);  // 0x802C8364 (460B)
    /* ? */ GetPlaceholder(void);  // 0x802C8530 (124B)
    void FreeUnusedData(void);  // 0x802C85AC (292B)
    void DeleteUserSelectors(void);  // 0x802C86D0 (532B)
    void DeleteSelectorAnimLists(void);  // 0x802C88E4 (320B)
    /* ? */ GetTypeAttrBlock(int);  // 0x802C8B20 (172B)
    void Save(iResFile *);  // 0x802C8BCC (92B)
    void Load(iResFile *);  // 0x802C8C28 (92B)
    void DoStream(ReconBuffer *, int);  // 0x802C8C84 (1048B)
    /* ? */ GetRumbleByName(char *);  // 0x802C909C (248B)
    /* ? */ GetCameraBloomByName(char *);  // 0x802C9194 (248B)
    /* ? */ GetCameraBlurByName(char *);  // 0x802C928C (248B)
    /* ? */ GetAnimPreloadList(ChecksumList &);  // 0x802C941C (484B)
    void SuspendObjectFiles(void);  // 0x802C9600 (32B)
    void ResumeObjectFiles(void);  // 0x802C9620 (32B)
    void DoCommand(short, int);  // 0x802C9640 (52B)
    /* ? */ GetTreeTable(ObjSelector *);  // 0x802C9674 (1280B)
    void LoadResourceByIndex(unsigned int, short, ObjectDataInterface &, unsigned int, unsigned int);  // 0x802C9B74 (620B)
    void LoadResourceByID(unsigned int, short, ObjectDataInterface &, unsigned int);  // 0x802C9DE0 (272B)
    void SaveResource(unsigned int, short, StringBuffer &, ObjectDataInterface &);  // 0x802C9EF0 (176B)
    /* ? */ GetResourceCount(unsigned int, unsigned int, unsigned int);  // 0x802C9FA0 (208B)
    void RemoveResourceByID(unsigned int, short, unsigned int);  // 0x802CA070 (664B)
    void ChangeResourceID(unsigned int, short, short, unsigned int);  // 0x802CA308 (664B)
    /* ? */ GetNamespaceName(unsigned int, StringBuffer &);  // 0x802CA5A0 (212B)
    void FindUniqueResourceName(unsigned int, unsigned int, StringBuffer &);  // 0x802CA674 (228B)
    void FindUniqueResourceID(unsigned int, unsigned int, short &);  // 0x802CA758 (236B)
    bool IsNamespaceWriteable(unsigned int);  // 0x802CA844 (68B)
    bool IsBehaviorWriteable(unsigned int);  // 0x802CA888 (68B)
    /* ? */ GetStringFromNamespaceID(unsigned int, StringBuffer &, short, short);  // 0x802CA8CC (372B)
    void ClearAllCaches(void);  // 0x802CAA40 (284B)
    /* ? */ GetNamespaceSelector(unsigned int);  // 0x802CACDC (300B)
    void FlushNamespaceCaches(void);  // 0x802CAE08 (60B)
    /* ? */ GetPath(void);  // 0x802D073C (72B)
    /* ? */ GetBehaviorFinder(void);  // 0x802D0784 (44B)
    /* ? */ GetObjectsDatabase(void);  // 0x802D07B0 (44B)

    // ---- Field Layout (from assembly analysis) ----
    u16 m_stringFromNamespaceID;  // 0x000 [R/W] (AddSelector, AddUserSelector, ChangeResourceID, ...)
    u8 _pad_002[2];  // 0x002
    u32 m_fileByID;  // 0x004 [R/W] (AddSelector, AddUserSelector, Destroy, ...)
    u32 m_fileByID_008;  // 0x008 [R/W] (AddSelector, AddUserSelector, Destroy, ...)
    u32 m_selectorByBehavior;  // 0x00C [R/W] (AddSelector, AddUserSelector, Destroy, ...)
    u32 m_namespaceSelector;  // 0x010 [R/W] (AddSelector, AddUserSelector, GetNamespaceSelector, ...)
    u32 m_field_014;  // 0x014 [R/W] (AddSelector, AddUserSelector, LoadUserData, ...)
    u32 m_field_018;  // 0x018 [R/W] (AddSelector, AddUserSelector, Destroy)
    u32 m_field_01C;  // 0x01C [R/W] (AddUserSelector)
    u8 _pad_020[0x14];  // 0x020
    u32 m_field_034;  // 0x034 [R] (AddSelector)
    u32 m_field_038;  // 0x038 [W] (Destroy, Init, ObjectFolderImpl)
    u32 m_fileByID_03C;  // 0x03C [R/W] (ClearAllCaches, CloseResFile, Destroy, ...)
    u8 _pad_040[0x10];  // 0x040
    u32 m_field_050;  // 0x050 [W] (AddSelector, AddUserSelector)
    u32 m_queueShaderByGUID;  // 0x054 [R/W] (AddSelector, AddUserSelector, GetQueueShaderByGUID)
    u8 _pad_058[0xC];  // 0x058
    u32 m_field_064;  // 0x064 [R/W] (ClearAllCaches)
    u8 _pad_068[4];  // 0x068
    s16 m_field_06C;  // 0x06C [R] (PrepareForModuleLoad)
    u8 _pad_06E[2];  // 0x06E
    u32 m_field_070;  // 0x070 [W] (AddSelector, AddUserSelector)
    u8 _pad_074[4];  // 0x074
    s16 m_field_078;  // 0x078 [R] (LoadUserData)
    u8 _pad_07A[2];  // 0x07A
    u32 m_field_07C;  // 0x07C [R/W] (AddSelector, AddUserSelector, LoadUserData)
    u16 m_field_07E;  // 0x07E [R] (AddSelector, AddUserSelector)
    u8 _pad_080[0xC];  // 0x080
    u32 m_field_08C;  // 0x08C [W] (CreateNewUserSelector)
    s16 m_field_090;  // 0x090 [R/W] (AddSelector, LoadUserData)
    u8 _pad_092[2];  // 0x092
    u32 m_field_094;  // 0x094 [R] (LoadUserData)
    u8 _pad_098[0xC];  // 0x098
    u32 m_selectorByBehavior_0A4;  // 0x0A4 [R/W] (AddSelector, AddUserSelector, DeleteUserSelectors, ...)
    u8 _pad_0A8[8];  // 0x0A8
    s16 m_field_0B0;  // 0x0B0 [R] (LoadUserData)
    u8 _pad_0B2[2];  // 0x0B2
    s16 m_field_0B4;  // 0x0B4 [R] (AddUserSelector, LoadUserData)
    u8 _pad_0B6[6];  // 0x0B6
    u16 m_field_0BC;  // 0x0BC [W] (AddUserSelector)
    u8 _pad_0BE[0x382];  // 0x0BE
    u32 m_fileByID_440;  // 0x440 [R/W] (Destroy, GetAnimPreloadList, GetFileByID, ...)
    u8 _pad_444[0x218];  // 0x444
    u32 m_field_65C;  // 0x65C [R/W] (AddSelector, Init, ObjectFolderImpl)
    u32 m_field_660;  // 0x660 [R/W] (AddSelector, AddUserSelector, Destroy, ...)
    u32 m_field_664;  // 0x664 [R] (DoStream)
    u8 _pad_668[8];  // 0x668
    u32 m_field_670;  // 0x670 [R/W] (ObjectFolderImpl, PrepareForModuleLoad, PrepareForModuleSave, ...)
    u32 m_field_674;  // 0x674 [R/W] (PrepareForModuleSave, ReconBehavior, ReconSelector)
    u8 _pad_678[8];  // 0x678
    u32 m_field_680;  // 0x680 [R/W] (ObjectFolderImpl, PrepareForModuleLoad, ReconSelector, ...)
    u8 _pad_684[0xC];  // 0x684
    u32 m_fileByID_690;  // 0x690 [R/W] (AddSelector, Destroy, GetCameraBloomByName, ...)
    u32 m_field_694;  // 0x694 [R/W] (Destroy, LoadDatabase, ObjectFolderImpl)
    u32 m_field_698;  // 0x698 [R/W] (AddUserSelector, LoadDatabase, ObjectFolderImpl)
    u8 _pad_69C[0x1C];  // 0x69C
    u32 m_field_6B8;  // 0x6B8 [R] (AddUserSelector)
    u16 m_field_6BC;  // 0x6BC [R/W] (CreateNewUserSelector, LoadUserData, ObjectFolderImpl)
    u8 _pad_6BE[0x12];  // 0x6BE
    u32 m_field_6D0;  // 0x6D0 [W] (ObjectFolderImpl)
};

#endif // OBJECTFOLDERIMPL_H
