// 0x8003FB0C EGlobal::HouseNameText (112b)
// FLAGS: -fno-schedule-insns

struct ERQuickdata;
struct EGlobal {
    char pad[0xE8];
    ERQuickdata* quickdata;
};

extern void* ERQuickdata_getTable(ERQuickdata*, char*);
extern void* ERQuickdata_getRow(void*, void*, char*);

extern int g_tableDB[];
extern char g_houseNameKey[];
extern char g_sda_fallback[4];  // SDA global at r13-24988

extern "C" void* EGlobal_HouseNameText(void* retptr, EGlobal* self, char* name) {
    // Force register allocation matching DOL
    register char* rp asm("r31") = (char*)retptr;
    register char* nm asm("r30") = (char*)name;
    register int r0_temp asm("r0");  // Force r0 usage for result
    
    if (nm != 0) {
        void* table = ERQuickdata_getTable(self->quickdata, (char*)g_houseNameKey);
        void* db = *(void**)((char*)g_tableDB + 0);
        void* row = ERQuickdata_getRow(db, table, nm);
        if (row != 0) {
            r0_temp = *(int*)((char*)row + 0);
        } else {
            r0_temp = *(int*)g_sda_fallback;
        }
    } else {
        r0_temp = *(int*)g_sda_fallback;
    }
    *(int*)rp = r0_temp;
    return rp;
}
