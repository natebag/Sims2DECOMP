class FamilyImpl {
public:
    void *vtable;
    void *pad_base;
    int m_number;

    void SetNumber(int num);
};

void FamilyImpl::SetNumber(int num) {
    m_number = num;
}
