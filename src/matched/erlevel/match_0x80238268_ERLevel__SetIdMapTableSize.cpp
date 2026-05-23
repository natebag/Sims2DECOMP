// ERLevel::SetIdMapTableSize(int) at 0x80238268 (40 bytes)
// Thunk: forwards to embedded EHashTable at offset 0x2A264.

struct EHashTable {
    void SetTableSize(int n);
};

struct ERLevel_SIM {
    char _pad[0x2A264];
    EHashTable m_idMap;

    void SetIdMapTableSize(int size);
};

void ERLevel_SIM::SetIdMapTableSize(int size) {
    m_idMap.SetTableSize(size);
}
