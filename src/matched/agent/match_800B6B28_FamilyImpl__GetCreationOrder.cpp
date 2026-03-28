class FamilyImpl {
public:
    void *vtable;
    void *pad_base;
    int m_number;
    int m_houseNumber;
    int m_creationOrder;

    int GetCreationOrder(void);
};

int FamilyImpl::GetCreationOrder(void) {
    return m_creationOrder;
}
