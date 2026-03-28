#ifndef ERQUICKDATA_H
#define ERQUICKDATA_H

#include "types.h"

// ERQuickdata - struct layout extracted from assembly analysis
// Estimated minimum size: 0x1C (28 bytes)
// 4 known fields (1 named), 36 methods

class ERQuickdata {
public:
    // Constructors / Destructors
    ERQuickdata(void)  // 0x8086512C
    ~ERQuickdata(void);  // 0x80865188

    // Methods
    void getTable(char *);  // 0x8086557C (160B)
    void getRow(void *, char *);  // 0x808657C0 (244B)
    void findRow(void *, unsigned int *);  // 0x80865BF4 (404B)
    /* ? */ GetImage(void);  // 0x80866878 (44B)
    void reset(void);  // 0x808651F4 (100B)
    void UnlockImage(void);  // 0x80865258 (32B)
    void LockImage(void);  // 0x80865278 (32B)
    void Reload(EFile *);  // 0x80865298 (196B)
    void Load(EFile *, int);  // 0x8086535C (144B)
    void getTableIndex(int, int, char *);  // 0x808653EC (400B)
    void getRowIndex(int, int, char *, char **);  // 0x8086561C (420B)
    void getStartAddr(int);  // 0x808658B4 (248B)
    void findTableIndex(int, int, void *);  // 0x808659AC (584B)
    void FindTableName(void *, char **);  // 0x80865D88 (164B)
    /* ? */ GetRevisionNumber(void);  // 0x80865E2C (68B)
    /* ? */ GetImageSize(void);  // 0x808668A4 (44B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [W] - vtable pointer (ERQuickdata, ~ERQuickdata)
    u8 _pad_004[0xC];  // 0x004
    u32 m_field_010;  // 0x010 [R/W] (Load)
    u32 m_field_014;  // 0x014 [R/W] (ERQuickdata, FindTableName, Load, ...)
    u32 m_field_018;  // 0x018 [R/W] (ERQuickdata, Load, reset)
};

#endif // ERQUICKDATA_H
