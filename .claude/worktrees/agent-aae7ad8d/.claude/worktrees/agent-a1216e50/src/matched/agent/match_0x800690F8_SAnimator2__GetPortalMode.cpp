/* 0x800690F8 (12 bytes) - SAnimator2::GetPortalMode(void) */
class SAnimator2 {
public:
    char pad[0x5F8];
    signed char m_portalMode;
    signed char GetPortalMode(void);
};

signed char SAnimator2::GetPortalMode(void) {
    return m_portalMode;
}
