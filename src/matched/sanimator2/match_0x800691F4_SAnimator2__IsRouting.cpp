/* 0x800691F4 (20 bytes) - SAnimator2::IsRouting(void) */
class SAnimator2 {
public:
    char pad[0x10];
    int m_field_010;
    int IsRouting(void);
};

int SAnimator2::IsRouting(void) {
    return m_field_010 == 1;
}
