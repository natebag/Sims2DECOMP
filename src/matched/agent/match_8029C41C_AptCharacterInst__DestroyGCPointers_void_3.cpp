struct AptNativeHash;
void AptNativeHash_Destroy3(AptNativeHash* hash);

struct AptCharacterInst3 {
    char pad[0x0C];
    AptNativeHash* m_nativeHash;
    int m_destroyed;

    void DestroyGCPointers();
};

void AptCharacterInst3::DestroyGCPointers() {
    if (m_nativeHash != 0) {
        AptNativeHash_Destroy3(m_nativeHash);
    }
    m_destroyed = 1;
}
