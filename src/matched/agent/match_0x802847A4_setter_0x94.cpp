struct Setter_802847A4 {
    char _pad[0x94];
    int m_val;
    void SetVal(int v);
};

void Setter_802847A4::SetVal(int v) {
    m_val = v;
}
