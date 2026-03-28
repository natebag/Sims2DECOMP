#ifndef QUICKSTRINGSET_H
#define QUICKSTRINGSET_H

#include "types.h"

// QuickStringSet - struct layout extracted from assembly analysis
// Estimated minimum size: 0x18 (24 bytes)
// 5 known fields (5 named), 88 methods

class QuickStringSet {
public:
    // Constructors / Destructors
    QuickStringSet(void)  // 0x80204A08
    ~QuickStringSet(void);  // 0x80204A80

    // Methods
    void CreateInstance(void);  // 0x80204844 (80B)
    void CreateInstance(ObjectDataID &);  // 0x80204894 (84B)
    void QueryInterface(unsigned int, void **);  // 0x802060C0 (232B)
    void AddRef(void);  // 0x802061A8 (64B)
    void Release(void);  // 0x802061E8 (160B)
    /* ? */ GetDataID(void);  // 0x80205EC8 (80B)
    void LoadFromDataID(ObjectDataID &);  // 0x80205F18 (156B)
    void LoadFromIndex(unsigned int, int);  // 0x80205FB4 (48B)
    void SaveDataByID(ObjectDataID &);  // 0x80205FE4 (44B)
    /* ? */ GetResourceName(StringBuffer &);  // 0x80206010 (44B)
    void SetResourceName(StringBuffer &);  // 0x8020603C (44B)
    /* ? */ GetDataSourceType(void);  // 0x80206068 (40B)
    void LoadOnlyNameAndIDFromIndex(unsigned int, int);  // 0x80206090 (48B)
    void Copy(StringSet *);  // 0x80204FB4 (148B)
    void Count(char);  // 0x80205048 (128B)
    void size(void);  // 0x802050C8 (108B)
    /* ? */ GetString(int, char);  // 0x80205134 (152B)
    /* ? */ GetLocString(int);  // 0x802051CC (164B)
    /* ? */ GetNativeString(int, char *);  // 0x80205270 (172B)
    void SetString(int, char *, char);  // 0x8020531C (144B)
    void SetString(int, unsigned wchar_t *, char);  // 0x802053AC (144B)
    void InsertString(int, char *, char);  // 0x8020543C (144B)
    void RemoveString(int, char);  // 0x802054CC (140B)
    /* ? */ GetDescription(int, char);  // 0x80205558 (48B)
    void SetDescription(int, char *, char);  // 0x80205588 (144B)
    /* ? */ GetName(StringBuffer *);  // 0x80205618 (60B)
    void SetName(StringBuffer *);  // 0x80205654 (136B)
    void SetInfo(unsigned int, short, unsigned int, bool, char);  // 0x802056DC (160B)
    void SetLocInfo(unsigned int, short, unsigned int, bool, char);  // 0x8020577C (160B)
    void LoadRes(unsigned int, short);  // 0x8020581C (148B)
    void LoadLocRes(unsigned int, short);  // 0x802058B0 (148B)
    void Save(unsigned int, short);  // 0x80205944 (148B)
    void LoadDef(bool, bool);  // 0x80205D78 (48B)
    void Save(void);  // 0x80205DA8 (152B)
    /* ? */ GetID(void);  // 0x80205E40 (72B)
    void SetInfo(iResFile *, short, unsigned int, bool, char);  // 0x802059D8 (200B)
    void SetLocInfo(iResFile *, short, unsigned int, bool, char);  // 0x80205AA0 (184B)
    void LoadRes(iResFile *, short);  // 0x80205B58 (264B)
    void LoadLocRes(iResFile *, short);  // 0x80205C60 (120B)
    void Save(iResFile *, short);  // 0x80205CD8 (160B)
    void WriteAnsiToDB(void);  // 0x80205E88 (32B)
    void WriteWideToDB(void);  // 0x80205EA8 (32B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [R/W] - vtable pointer (Count, GetLocString, LoadFromDataID, ...)
    u32 m_info;  // 0x004 [R/W] (Count, LoadLocRes, LoadRes, ...)
    u32 m_string;  // 0x008 [R/W] (Count, GetString, LoadLocRes, ...)
    u8 _pad_00C[4];  // 0x00C
    u32 m_info_010;  // 0x010 [R/W] (LoadRes, Release, SetInfo)
    u32 m_locInfo;  // 0x014 [R] (LoadLocRes, SetLocInfo)
};

#endif // QUICKSTRINGSET_H
