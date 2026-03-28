struct AptNativeHash;
void AptNativeHash_Destroy(AptNativeHash* hash);

struct AptCharacterInst {
    char pad[0x0C];
    AptNativeHash* m_nativeHash;
    int m_destroyed;

    void DestroyGCPointers();
};

void AptCharacterInst::DestroyGCPointers() {
    if (m_nativeHash != 0) {
        AptNativeHash_Destroy(m_nativeHash);
    }
    m_destroyed = 1;
}
