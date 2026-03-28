class FamilyImpl {
public:
    void *vtable;
    void *pad_base;
    int m_number;
    int m_houseNumber;

    int GetHouseNumber(void);
};

int FamilyImpl::GetHouseNumber(void) {
    return m_houseNumber;
}
