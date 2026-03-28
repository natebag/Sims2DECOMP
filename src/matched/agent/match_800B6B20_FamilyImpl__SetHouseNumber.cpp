class FamilyImpl {
public:
    void *vtable;
    void *pad_base;
    int m_number;
    int m_houseNumber;

    void SetHouseNumber(int num);
};

void FamilyImpl::SetHouseNumber(int num) {
    m_houseNumber = num;
}
