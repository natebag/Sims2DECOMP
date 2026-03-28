/* 0x8005A45C (12 bytes) - PlumbBob::BecomeTransitionIndicator(void) */
class PlumbBob {
public:
    char pad[0x160];
    int m_field_160;
    void BecomeTransitionIndicator(void);
};

void PlumbBob::BecomeTransitionIndicator(void) {
    m_field_160 = 1;
}
