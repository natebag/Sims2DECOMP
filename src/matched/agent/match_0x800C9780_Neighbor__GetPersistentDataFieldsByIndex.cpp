// 0x800C9780 Neighbor::GetPersistentDataFieldsByIndex (20B)

struct PersDataField {
    int m_data[2];
};

extern PersDataField *g_persistentDataFields[];

struct Neighbor {
    static PersDataField *GetPersistentDataFieldsByIndex(int index);
};

PersDataField *Neighbor::GetPersistentDataFieldsByIndex(int index) {
    return &g_persistentDataFields[0][index];
}
