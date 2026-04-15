// FLAGS: -O1
// 0x80089910 CreateASimBaseState::CASAccepted(void) (40B)

struct CreateASimBaseState {
    char pad[0x20];
    int m_field20;
    char pad2[4];
    int m_field28;

    int CASAccepted(void);
};

int CreateASimBaseState::CASAccepted(void) {
    int r = 0;
    if (m_field20 == 0 && m_field28 != 0) {
        r = 1;
    }
    return r;
}
