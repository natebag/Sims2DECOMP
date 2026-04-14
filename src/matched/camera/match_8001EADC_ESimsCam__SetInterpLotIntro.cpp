// 0x8001EADC (8 bytes) — stw r4, 0x568(r3); blr

class ESimsCam {
public:
    char _pad[0x568];
    int m_interpLotIntroFlag;

    void SetInterpolatingFromLotIntroCameraFlag(bool val);
};

void ESimsCam::SetInterpolatingFromLotIntroCameraFlag(bool val) {
    m_interpLotIntroFlag = val;
}
