// 0x800A0170 BString2::ref_count(void) (12 B)

struct BString2 {
    void* m_buffer;
    int ref_count();
};

int BString2::ref_count() {
    int* p = (int*)m_buffer;
    return p[3];
}
