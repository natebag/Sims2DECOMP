struct AptNativeHash;
struct AptCIH;

struct AptDisplayList {
    void RemoveFromDisplayListImpl(AptCIH* cih);
    void RemoveFromDisplayList(AptNativeHash* hash, AptCIH* cih);
};

void AptDisplayList::RemoveFromDisplayList(AptNativeHash* hash, AptCIH* cih) {
    RemoveFromDisplayListImpl(cih);
}
