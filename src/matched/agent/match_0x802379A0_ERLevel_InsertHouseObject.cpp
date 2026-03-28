struct EOrderTableData {
    char pad[0x28];
    EOrderTableData *m_next;
};

struct ERLevel {
    char pad0[0x2E2D0];
    EOrderTableData *m_houseObjectList;

    void InsertHouseObject(EOrderTableData *otd);
};

void ERLevel::InsertHouseObject(EOrderTableData *otd) {
    otd->m_next = m_houseObjectList;
    m_houseObjectList = otd;
}
