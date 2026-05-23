// PRAGMA_STUB: EGlobal::GetCounterModelTable(void)
// EGlobal::GetCounterModelTable(void)
// Address: 0x80041758 | Size: 48 bytes
// FLAGS: -fno-elide-constructors

struct ERQuickdataTable;

struct ERQuickdata {
    void* m_vtable;
    ERQuickdataTable* getTable(const char* name);
};

struct ERQuickdataTable {
    char pad[4];
    void* m_data;
};

struct EGlobal {
    char pad[0xEC];
    ERQuickdata* m_quickdata;
};

extern "C" ERQuickdataTable* _ZN11ERQuickdata8getTableEPc(ERQuickdata* self, const char* name);

void* EGlobal__GetCounterModelTable(EGlobal* self) {
    const char* name = "CounterModelTable";
    ERQuickdata* qd = self->m_quickdata;
    ERQuickdataTable* table = _ZN11ERQuickdata8getTableEPc(qd, name);
    return table->m_data;
}
