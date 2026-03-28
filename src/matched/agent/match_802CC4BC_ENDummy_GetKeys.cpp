struct ENDummy_GK {
    char pad[0x44];
    int m_keys;
    int GetKeys();
};

int ENDummy_GK::GetKeys() {
    return m_keys;
}
