struct AptNativeHash {
    void DestroyGCPointers();
};

struct AptValueWithHash {
    char _pad[0x0C];
    AptNativeHash m_hash;

    void DestroyGCPointers();
};

void AptValueWithHash::DestroyGCPointers()
{
    m_hash.DestroyGCPointers();
}
