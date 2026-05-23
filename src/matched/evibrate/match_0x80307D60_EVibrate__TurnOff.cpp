struct Motor { int m_on; char _p[0x40]; };
struct EVibrate {
    char _p[0x38];
    Motor m_motors[4];
    void TurnOff(unsigned char idx);
};
void EVibrate::TurnOff(unsigned char idx) { m_motors[idx].m_on = 0; }
