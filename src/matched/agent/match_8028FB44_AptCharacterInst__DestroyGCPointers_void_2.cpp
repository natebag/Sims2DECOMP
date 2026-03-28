struct AptNativeHash;
void AptNativeHash_Destroy2(AptNativeHash* hash);

struct AptCharacterInst2 {
    char pad[0x0C];
    AptNativeHash* m_nativeHash;
    int m_destroyed;

    void DestroyGCPointers();
};

void AptCharacterInst2::DestroyGCPointers() {
    if (m_nativeHash != 0) {
        AptNativeHash_Destroy2(m_nativeHash);
    }
    m_destroyed = 1;
}
