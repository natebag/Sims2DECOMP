class HUDTarget {
public:
    char _pad[0x100];
    unsigned char m_hudTransitionTarget;

    unsigned char GetHudTransitionTarget(void);
};

unsigned char HUDTarget::GetHudTransitionTarget(void) {
    return m_hudTransitionTarget;
}
