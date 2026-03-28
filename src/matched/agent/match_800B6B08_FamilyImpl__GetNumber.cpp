class FamilyImpl {
public:
    void *vtable;
    void *pad_base;
    int m_number;

    int GetNumber(void);
};

int FamilyImpl::GetNumber(void) {
    return m_number;
}
