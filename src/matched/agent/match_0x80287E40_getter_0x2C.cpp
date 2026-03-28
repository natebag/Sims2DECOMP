struct Getter_80287E40 {
    char _pad[0x2C];
    int m_val;
    int GetVal();
};

int Getter_80287E40::GetVal() {
    return m_val;
}
