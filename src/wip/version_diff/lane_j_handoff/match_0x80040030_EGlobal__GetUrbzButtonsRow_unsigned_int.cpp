// 0x80040030 (128B) EGlobal::GetUrbzButtonsRow(unsigned int)
// Table lookup via ERQuickdata.

struct ERQuickdataTableEntry {
    unsigned int m_value;
    char pad[8];
};

struct ERQuickdataTable {
    char pad[4];
    ERQuickdataTableEntry* m_entries;
    char pad2[4];
    int m_count;
};

struct ERQuickdata {
    ERQuickdataTable* getTable(const char* name);
};

struct EGlobal {
    char pad[0xe8];
    ERQuickdata* m_quickdata;
    
    ERQuickdataTableEntry* GetUrbzButtonsRow(unsigned int value);
};

ERQuickdataTableEntry* EGlobal::GetUrbzButtonsRow(unsigned int value) {
    ERQuickdataTable* table = m_quickdata->getTable("UrbzButtons");
    if (table) {
        for (int i = 0; i < table->m_count; i++) {
            if (table->m_entries[i].m_value == value) {
                return &table->m_entries[i];
            }
        }
    }
    return 0;
}
