class cXPersonImpl {
public:
    char m_pad[1336];
    int m_value;
    void SetValue(int v);
};

void cXPersonImpl::SetValue(int v) {
    m_value = v;
}
