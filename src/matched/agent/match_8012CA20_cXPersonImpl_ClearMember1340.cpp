class cXPersonImpl {
public:
    char m_pad[1340];
    int m_value;
    void ClearValue();
};

void cXPersonImpl::ClearValue() {
    m_value = 0;
}
