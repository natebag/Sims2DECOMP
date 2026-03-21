// uibase_medium.cpp - UIObjectBase medium functions (65-256 bytes)
// Object file: uibase.obj
// 6 functions

#include "ui/uicore.h"

// External functions
extern "C" {
    char* GetAptButtonFilterName(int player);  // 0x80177a64
    void pushAptButtonFilterImpl(void* self, int player, char* name);  // 0x80177acc
    void swprintf_impl(unsigned short* buf, int dummy, int size, ...);  // 0x802435e4
    int sprintf_impl(char* buf, const char* fmt, ...);  // 0x802de888
    void wcsncpy_impl(unsigned short* dst, unsigned short* src);  // 0x8000ada0
    void wcsncat_impl(unsigned short* dst, unsigned short* src);  // Similar
    void EAMoneyFormat_Init(void* fmt, unsigned short* buf);  // 0x800a6ce4
    unsigned short* EAMoneyFormat_GetString(void* fmt);  // 0x800a6e68
    void wcsncpy2(unsigned short* dst, unsigned short* src);  // 0x800a7ed0
    void EAMoneyFormat_Format(void* fmt, void* self, int amount);  // 0x8007b5f4
    void AptViewer_Call(void* viewer, char* funcName, char* p1, char* p2, int nArgs, char** args);  // 0x800104b0
}

// Global pointers
extern void* g_aptRouterObj;  // lis r9,-32697; lwz r11,24312(r9)
extern void* g_aptViewerObj;  // lis r9,-32697; lwz r3,24192(r9)

// String table
static const char s_uiFlowGotoFmt[] = "state";  // 0x803e248c - flow goto var name

// 0x80177b44 | 96 bytes
// Pushes button filter for all 48 players
char* UIObjectBase::pushAptButtonFilterALL(int player, char* name) {
    char* filterName = GetAptButtonFilterName(player);
    if (filterName == 0) {
        return 0;
    }
    for (int i = 1; i <= 48; i++) {
        pushAptButtonFilterImpl(this, i, filterName);
    }
    return filterName;
}

// 0x80177ba4 | 140 bytes
// Converts integer to wchar_t number string
// NON_MATCHING - sprintf format details uncertain
void UIObjectBase::makeNumberString(int number, unsigned short* outStr) {
    if (outStr == 0) {
        return;
    }
    unsigned short buf[16];
    swprintf_impl(buf, 0, 32);
    int len = sprintf_impl((char*)buf, "%d", number);
    wcsncpy_impl(buf, outStr);
    // null terminate
    unsigned short* end = buf + len + len;
    *(unsigned short*)((char*)outStr + (int)end) = 0;
}

// 0x80177c30 | 120 bytes
// Converts integer to money string with optional sign
// NON_MATCHING - EAMoneyFormat usage uncertain
void UIObjectBase::makeMoneyString(int amount, unsigned short* outStr, bool addSign) {
    if (outStr == 0) {
        return;
    }
    u8 moneyFmt[0x200];
    unsigned short moneyBuf[128];
    EAMoneyFormat_Init(moneyFmt, moneyBuf);
    EAMoneyFormat_Format(moneyFmt, this, amount);
    unsigned short* result = EAMoneyFormat_GetString(moneyFmt);
    wcsncpy2(outStr, result);
}

// 0x80177cc8 | 68 bytes
// Routes a SetVariable call through the APT system
void UIObjectBase::UIRouter_SetVariable(char* name, char* value) {
    void* routerObj = g_aptRouterObj;
    void** vtable = *(void***)((u8*)routerObj + 0x80);
    s16 offset = *(s16*)((u8*)vtable + 0x10);
    void* func = *(void**)((u8*)vtable + 0x14);
    void* thisAdj = (void*)((u8*)routerObj + offset);
    // Virtual call: routerObj->SetVariable(name, value)
    typedef void (*SetVarFn)(void*, char*, char*);
    ((SetVarFn)func)(thisAdj, name, value);
}

// 0x80177d0c | 72 bytes
// Routes a FlowGoto call through the APT system
void UIObjectBase::UIRouter_FlowGoto(char* target) {
    void* routerObj = g_aptRouterObj;
    void** vtable = *(void***)((u8*)routerObj + 0x80);
    s16 offset = *(s16*)((u8*)vtable + 0x10);
    void* func = *(void**)((u8*)vtable + 0x14);
    void* thisAdj = (void*)((u8*)routerObj + offset);
    // Virtual call: routerObj->SetVariable("state", target)
    typedef void (*SetVarFn)(void*, char*, char*);
    ((SetVarFn)func)(thisAdj, (char*)s_uiFlowGotoFmt, target);
}

// 0x80177d54 | 84 bytes
// Calls a function on the APT viewer
void UIObjectBase::AptViewer_CallFunction(char* funcName, char* param1, char* param2, int numArgs, char** args) {
    void* viewer = g_aptViewerObj;
    AptViewer_Call(viewer, funcName, param1, param2, numArgs, args);
}
