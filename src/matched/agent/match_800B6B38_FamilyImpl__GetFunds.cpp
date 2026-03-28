class FamilyImpl {
public:
    void *vtable;
    void *pad_base;
    int m_number;
    int m_houseNumber;
    int m_creationOrder;
    int m_funds;

    int GetFunds(void);
};

int FamilyImpl::GetFunds(void) {
    return m_funds;
}
