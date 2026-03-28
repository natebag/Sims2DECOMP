class FamilyImpl {
public:
    void *vtable;
    void *pad_base;
    int m_number;
    int m_houseNumber;
    int m_creationOrder;

    void SetCreationOrder(int order);
};

void FamilyImpl::SetCreationOrder(int order) {
    m_creationOrder = order;
}
