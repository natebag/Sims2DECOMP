// 0x80214F38 InteractorModule::InteractorVisualizer::PreDraw(WallPainter&) (92B)
// InteractorModule::InteractorVisualizer::PreDraw template — matches 5 functions:
// 0x80214f38 WallPainter
// 0x80216d08 ObjectManipulator
// 0x80216ef8 SimInteractor
// 0x80217140 DirectInteractor
// 0x8021729c SocialModeInteractor
// All 5 share identical 23-insn body; only the bl offset to EHouse::InsertHouseObject differs.
// Key techniques:
//   - m_entries is an INLINE ARRAY at offset 0 (not a pointer) — single lwzx load
//   - interactor.m_id re-read 3 times (aliasing defeats caching)
//   - g_pHouse declared as 16-byte char array to exceed -G 8 SDA threshold,
//     forcing non-SDA lis/lwz absolute addressing

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
    int pad;
    char m_field8[1];
};

struct InteractorVisualizer {
    Entry* m_entries[256];
    void PreDraw(Interactor& interactor);
};

void InteractorVisualizer::PreDraw(Interactor& interactor) {
    m_entries[interactor.m_id]->field_18 = interactor.m_id;
    m_entries[interactor.m_id]->field_8 = &interactor.m_field8;
    (*(EHouse**)g_pHouse)->InsertHouseObject((EOrderTableData*)m_entries[interactor.m_id]);
}
