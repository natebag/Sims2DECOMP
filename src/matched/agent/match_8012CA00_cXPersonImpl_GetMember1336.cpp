class cXPersonImpl {
public:
    char m_pad[1336];
    int m_value;
    int GetValue();
};

int cXPersonImpl::GetValue() {
    return m_value;
}
