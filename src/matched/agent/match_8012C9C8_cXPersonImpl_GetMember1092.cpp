class cXPersonImpl {
public:
    char m_pad[1092];
    int m_value;
    int GetValue();
};

int cXPersonImpl::GetValue() {
    return m_value;
}
