// 0x800608DC (76B) SAnimator2::GetTurnRate()
// Tech #17 sda21-ha-lo-declaration-control: char[16] forces HA/LO

extern char DEFAULT_TURN1_18308[16];
extern char DEFAULT_TURN2_18312[16];

class SAnimator2 {
public:
    int m_pad0[6];        // 0..23
    int m_18;             // 24
    int m_pad6[4];        // 28..43
    int m_2C;             // 44
    char m_padPad[152 - 48];
    float m_98;           // 152
    char m_pad10[1528 - 156];
    unsigned char m_5F8;  // 1528
    float GetTurnRate();
};

float SAnimator2::GetTurnRate() {
    float result = *(float*)DEFAULT_TURN1_18308;
    if (m_18 == 3) return result;
    if (m_5F8 == 2) return result;
    int v = m_2C;
    if (v != 12) goto check_others;
def2:
    return *(float*)DEFAULT_TURN2_18312;
check_others:
    if ((unsigned int)(v - 13) <= 1) goto def2;
    return m_98;
}
