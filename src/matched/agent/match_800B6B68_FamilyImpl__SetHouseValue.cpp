class FamilyImpl {
public:
    void *vtable;
    void *pad_base;
    int m_number;
    int m_houseNumber;
    int m_creationOrder;
    int m_funds;
    int m_houseValue;

    void SetHouseValue(int value);
};

void FamilyImpl::SetHouseValue(int value) {
    m_houseValue = value;
}
