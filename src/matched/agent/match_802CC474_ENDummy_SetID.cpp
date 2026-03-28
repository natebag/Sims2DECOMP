struct ENDummy_SI {
    char pad[0x40];
    int m_id;
    void SetID(int id);
};

void ENDummy_SI::SetID(int id) {
    m_id = id;
}
