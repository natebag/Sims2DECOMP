struct AptNativeHash {
    void DestroyGCPointers();
};

struct AptCharacterInst {
    char pad[0x0C];
    AptNativeHash *m_hash;
    int m_gcPointersDestroyed;

    void DestroyGCPointers();
};

void AptCharacterInst::DestroyGCPointers() {
    if (m_hash != 0) {
        m_hash->DestroyGCPointers();
    }
    m_gcPointersDestroyed = 1;
}
