// 0x8003FB0C EGlobal::HouseNameText (112b)

struct StringTableGlobals {
    void* tables[4];
};
extern StringTableGlobals g_stringTables;

extern void* GetQuickData(void);
extern void* GetRow(void* db, void* table, const char* name);
extern void* GetString(void* row);

void HouseNameText(void* retptr, void* self, const char* name) {
    void** out = (void**)retptr;
    if (!name) return;
    void* qd = GetQuickData();
    void* table = *(void**)((char*)qd + 0xE8);
    void* row = GetRow(table, table, name);
    void* str = GetString(row);
    if (str) {
        *out = str;
    } else {
        *out = g_stringTables.tables[0];
    }
}
