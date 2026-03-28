#ifndef UISCREENMANAGER_H
#define UISCREENMANAGER_H

#include "types.h"

// UIScreenManager - struct layout extracted from assembly analysis
// Estimated minimum size: 0x84 (132 bytes)
// 18 known fields (1 named), 38 methods

class UIScreenManager {
public:
    // Constructors / Destructors
    UIScreenManager(void)  // 0x8049271C
    ~UIScreenManager(void);  // 0x80492B84

    // Methods
    bool IsScreenManaged(UIScreenID);  // 0x8049355C (108B)
    /* ? */ GetScreenFlashName(char *, UIScreenID);  // 0x80493CF4 (444B)
    void FindDataByID(UIScreenID);  // 0x80492CEC (352B)
    void process_cheats(UIScreenID);  // 0x80492E4C (44B)
    void LoadUIScreen(UIScreenID, UIScreenInputMode);  // 0x80492E78 (1048B)
    void SuspendAllActiveScreens(void);  // 0x804935C8 (348B)
    void SuspendScreenList(UIScreenID *);  // 0x80493724 (596B)
    void SetHandlesInput(UIScreenID, bool);  // 0x80493FD4 (276B)
    void AddScreen(UIScreenID, int);  // 0x80493978 (552B)
    void UnloadUIScreen(UIScreenID);  // 0x80493290 (716B)
    void FindRecordIndexByID(UIScreenID);  // 0x80493BA0 (172B)
    void PopQueue(int);  // 0x804943D8 (132B)
    void RemoveScreen(UIScreenID);  // 0x80493C4C (168B)
    bool IsUIScreenUnloaded(UIScreenID);  // 0x80493EB0 (116B)
    bool IsUIScreenMarkedForUnloading(UIScreenID);  // 0x80493F24 (176B)
    void SetVariable(char *, char *);  // 0x804940E8 (544B)
    void Update(void);  // 0x80494308 (208B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [R/W] - vtable pointer (AddScreen, GetScreenFlashName, UIScreenManager, ...)
    u32 m_field_004;  // 0x004 [R/W] (AddScreen, UIScreenManager, ~UIScreenManager)
    u32 m_field_008;  // 0x008 [R/W] (UIScreenManager, ~UIScreenManager)
    u32 m_field_00C;  // 0x00C [R/W] (AddScreen, UIScreenManager, ~UIScreenManager)
    u32 m_field_010;  // 0x010 [R/W] (UIScreenManager, ~UIScreenManager)
    u32 m_field_014;  // 0x014 [R/W] (UIScreenManager, ~UIScreenManager)
    u32 m_field_018;  // 0x018 [R/W] (UIScreenManager, ~UIScreenManager)
    u32 m_field_01C;  // 0x01C [R/W] (UIScreenManager, ~UIScreenManager)
    u32 m_field_020;  // 0x020 [R/W] (UIScreenManager, ~UIScreenManager)
    u32 m_field_024;  // 0x024 [R/W] (UIScreenManager, ~UIScreenManager)
    u32 m_field_028;  // 0x028 [W] (UIScreenManager)
    u8 _pad_02C[0xC];  // 0x02C
    u32 m_field_038;  // 0x038 [W] (UIScreenManager)
    u8 _pad_03C[0xC];  // 0x03C
    u32 m_field_048;  // 0x048 [W] (UIScreenManager)
    u8 _pad_04C[0xC];  // 0x04C
    u32 m_field_058;  // 0x058 [R/W] (UIScreenManager, ~UIScreenManager)
    u8 _pad_05C[0xC];  // 0x05C
    u32 m_field_068;  // 0x068 [R/W] (UIScreenManager, ~UIScreenManager)
    u8 _pad_06C[0xC];  // 0x06C
    u32 m_field_078;  // 0x078 [W] (UIScreenManager)
    u32 m_field_07C;  // 0x07C [R/W] (UIScreenManager, ~UIScreenManager)
    u32 m_field_080;  // 0x080 [W] (UIScreenManager, ~UIScreenManager)
};

#endif // UISCREENMANAGER_H
