// 0x800709D0 SimModel::SetSimDescription(CasSimDescriptionS2C*) (100B)
// Pattern: null guard + optional delete + ptr store + parts->SetGender(raw int)
extern "C" void __builtin_delete(void*);

struct CasSimDescriptionS2C {
    char pad[132];
    int m_gender;
};

struct CasSimPartsS2C {
    void SetGender(int b);
};

struct SimModel {
    char pad[312];
    CasSimPartsS2C* m_parts;
    CasSimDescriptionS2C* m_desc;
    char pad2[20];
    void* m_ownedDesc;
    void SetSimDescription(CasSimDescriptionS2C* d);
};

void SimModel::SetSimDescription(CasSimDescriptionS2C* d) {
    if (d == 0) return;
    if (m_ownedDesc != 0 && m_desc != 0) {
        __builtin_delete(m_desc);
        m_desc = 0;
    }
    m_desc = d;
    m_parts->SetGender(d->m_gender);
}
