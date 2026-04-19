/* Family::CreateInstance(int &) at 0x800B5F28 (56B) */

struct FamilyImpl_CI {
    char m_data[56];
    explicit FamilyImpl_CI(int id);
};

struct Family_CI {
    int m_id;
    FamilyImpl_CI* CreateInstance(int& out);
};

FamilyImpl_CI* Family_CI::CreateInstance(int& out) {
    return new FamilyImpl_CI(m_id);
}
