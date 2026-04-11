// 0x8003FCC4 EGlobal::GetHUDUIString (112b)
// FLAGS: -fno-schedule-insns

struct ERQuickdata;
struct EGlobal {
    char pad[0xE8];
    ERQuickdata* quickdata;
};

extern void* ERQuickdata_getTable(ERQuickdata*, char*);
extern void* ERQuickdata_getRow(void*, void*, char*);

extern int g_tableDB[];
extern char g_hudUIStringKey[];
extern char g_sda_fallback[4];

extern "C" void* EGlobal_GetHUDUIString(void* retptr, EGlobal* self, char* name) {
    if (name != 0) {
        void* table = ERQuickdata_getTable(self->quickdata, g_hudUIStringKey);
        void* db = *(void**)g_tableDB;
        void* row = ERQuickdata_getRow(db, table, name);
        if (row != 0) {
            *(int*)retptr = *(int*)row;
            goto done;
        }
    }
    *(int*)retptr = *(int*)g_sda_fallback;
done:
    return retptr;
}
