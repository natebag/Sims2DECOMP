// 0x80195C1C CASTarget::CFCShouldGotoBodyScreenNext(void) (36 B)

struct CASTarget {
    char pad_0000[0xa4];
    int m_fieldA4;
    char pad_00a8[0x104 - 0xa8];
    int m_field104;

    int CFCShouldGotoBodyScreenNext();
};

int CASTarget::CFCShouldGotoBodyScreenNext() {
    if (m_field104 != 0) goto ret0;
    if (m_fieldA4 == 19) return 1;
ret0:
    return 0;
}
