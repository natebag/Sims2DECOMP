/* 0x8006908C (52 bytes) - SAnimator2::operator delete(void *) */
struct EAHeap_SAOD {
    void Free(void* ptr);
};

EAHeap_SAOD* MainHeap_SAOD();

struct SAnimator2_OD {
    static void operator delete(void* ptr);
};

void SAnimator2_OD::operator delete(void* ptr) {
    MainHeap_SAOD()->Free(ptr);
}
