// 0x800C8868 (88B) TArray<ENDummyPoint, TArrayDefaultAllocator>::SetSize(int, int)
// Manages an EResource* at offset 48 with ref-counting; second int param unused.
struct EResource {
    void DelRef();
    void AddRef();
};

struct TArray_ENDummyPoint {
    char pad[48];
    EResource* m_res;
    void SetSize(EResource* r, int);
};

void TArray_ENDummyPoint::SetSize(EResource* r, int) {
    EResource* old = m_res;
    if (old != 0 && old != r) {
        old->DelRef();
    }
    m_res = r;
    if (r != 0) {
        r->AddRef();
    }
}
