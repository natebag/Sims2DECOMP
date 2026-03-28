class cXPersonImpl {
public:
    char m_pad[1076];
    int m_value;
    void SetValue(int v);
};

void cXPersonImpl::SetValue(int v) {
    m_value = v;
}
