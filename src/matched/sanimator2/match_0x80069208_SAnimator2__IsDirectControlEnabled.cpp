/* 0x80069208 (24 bytes) - SAnimator2::IsDirectControlEnabled(void) */
class SAnimator2 {
public:
    char pad[0x2C];
    int m_field_02C;
    int IsDirectControlEnabled(void);
};

int SAnimator2::IsDirectControlEnabled(void) {
    return (unsigned)(m_field_02C - 9) <= 5;
}
