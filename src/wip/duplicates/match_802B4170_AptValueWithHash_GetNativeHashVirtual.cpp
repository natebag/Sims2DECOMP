struct AptValueWithHash_GNH {
    char pad[0x0C];
    int m_hash;
    int* GetNativeHashVirtual();
};

int* AptValueWithHash_GNH::GetNativeHashVirtual() {
    return &m_hash;
}
