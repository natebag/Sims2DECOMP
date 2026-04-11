/* EHouse::InsertHouseObject(EOrderTableData *) at 0x80025464 (68B) */

struct ERLevel {
    void InsertHouseObject(void*);
};

struct EOrderTableData {
    char pad_00[0x24];
    void* m_drawCallback;
};

struct EHouse {
    char pad_00[0x1C];
    ERLevel* m_level;
    char pad_20[0x44];
    int m_orderTableData;

    void InsertHouseObject(EOrderTableData*);
};

void EHouse::InsertHouseObject(EOrderTableData* otd) {
    if (m_level == 0) return;
    if (otd == 0) return;
    otd->m_drawCallback = (void*)&m_orderTableData;
    m_level->InsertHouseObject(otd);
}
