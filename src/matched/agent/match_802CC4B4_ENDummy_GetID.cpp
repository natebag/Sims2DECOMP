struct ENDummy_GI {
    char pad[0x40];
    int m_id;
    int GetID();
};

int ENDummy_GI::GetID() {
    return m_id;
}
