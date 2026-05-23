// 0x80215C34 (92B) InteractorModule::InteractorVisualizer::PreDraw(WallManipulator&)
// Sibling of the 5-family but with m_field_108 at offset 108 (vs offset 8 in others).

struct EOrderTableData;

struct EHouse {
    void InsertHouseObject(EOrderTableData* data);
};

extern char g_pHouse[16];

struct Entry {
    char pad[8];
    void* field_8;
    char pad2[12];
    int field_18;
};

struct Interactor {
    int m_id;
    char pad[104];
    char m_field108[1];  // at offset 108
};

struct InteractorVisualizer {
    Entry* m_entries[256];
    void PreDraw(Interactor& interactor);
};

void InteractorVisualizer::PreDraw(Interactor& interactor) {
    m_entries[interactor.m_id]->field_18 = interactor.m_id;
    m_entries[interactor.m_id]->field_8 = &interactor.m_field108;
    (*(EHouse**)g_pHouse)->InsertHouseObject((EOrderTableData*)m_entries[interactor.m_id]);
}
