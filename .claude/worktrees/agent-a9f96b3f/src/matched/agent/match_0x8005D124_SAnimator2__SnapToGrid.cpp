/* 0x8005D124 (12 bytes) - SAnimator2::SnapToGrid(void) */
class SAnimator2 {
public:
    char pad[0x24];
    int m_field_024;
    void SnapToGrid(void);
};

void SAnimator2::SnapToGrid(void) {
    m_field_024 = 1;
}
