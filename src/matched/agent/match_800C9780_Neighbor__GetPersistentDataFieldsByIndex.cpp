/* Neighbor::GetPersistentDataFieldsByIndex(int) - 20 bytes */

struct PersDataField {
    int m_data[2];
};

extern PersDataField *g_persistentDataFields;

struct Neighbor {
    static PersDataField *GetPersistentDataFieldsByIndex(int index);
};

PersDataField *Neighbor::GetPersistentDataFieldsByIndex(int index) {
    return &g_persistentDataFields[index];
}
