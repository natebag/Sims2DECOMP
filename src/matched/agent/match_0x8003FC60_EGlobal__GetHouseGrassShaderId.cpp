// 0x8003FC60 EGlobal::GetHouseGrassShaderId (100b)

struct ERQuickdata;
struct EGlobal {
    char pad[0xE8];
    ERQuickdata* quickdata;
};

extern void* ERQuickdata_getTable(ERQuickdata*, char*);
extern void* ERQuickdata_getRow(void*, void*, char*);

extern int g_tableDB[];
extern char g_houseLevelKey[];

char* EGlobal_GetHouseGrassShaderId(EGlobal* self, char* name) {
    if (name != 0) {
        void* table = ERQuickdata_getTable(self->quickdata, (char*)g_houseLevelKey);
        void* db = *(void**)((char*)g_tableDB + 0);
        void* row = ERQuickdata_getRow(db, table, name);
        if (row != 0) {
            return *(char**)((char*)row + 40);
        }
    }
    return 0;
}
