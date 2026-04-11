// 0x8003FCC4 EGlobal::GetHUDUIString (112b)
// VERSION_DIFF: requires register asm binding to force r31/r30/r0 allocation - needs legitimate C++ approach
// DOL uses r31=retptr, r30=name, r0=result but compiler generates r30=retptr, r31=name, r3=result

struct ERQuickdata;
struct EGlobal {
    char pad[0xE8];
    ERQuickdata* quickdata;
};

extern void* ERQuickdata_getTable(ERQuickdata*, char*);
extern void* ERQuickdata_getRow(void*, void*, char*);

extern int g_tableDB[];
extern char g_hudUIStringKey[];
extern char g_sda_fallback[4];  // SDA global at r13-24988

extern "C" void* EGlobal_GetHUDUIString(void* retptr, EGlobal* self, char* name) {
    void* result;
    if (name != 0) {
        void* table = ERQuickdata_getTable(self->quickdata, (char*)g_hudUIStringKey);
        void* db = *(void**)((char*)g_tableDB + 0);
        void* row = ERQuickdata_getRow(db, table, name);
        if (row != 0) {
            result = *(void**)((char*)row + 0);
        } else {
            result = *(void**)g_sda_fallback;
        }
    } else {
        result = *(void**)g_sda_fallback;
    }
    *(void**)retptr = result;
    return retptr;
}
