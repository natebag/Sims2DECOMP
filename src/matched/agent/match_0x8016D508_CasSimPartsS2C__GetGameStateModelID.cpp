/* CasSimPartsS2C::GetGameStateModelID(unsigned int) const at 0x8016D508 (44B) */

struct SimModel_GSMI {
    static int GetGameStateModelID(unsigned int idx, int flag);
};

struct CasSimPartsS2C_GSMI {
    char m_pad[12];
    int m_flag;
    int GetGameStateModelID(unsigned int idx) const;
};

int CasSimPartsS2C_GSMI::GetGameStateModelID(unsigned int idx) const {
    return SimModel_GSMI::GetGameStateModelID(idx, m_flag ^ 1);
}
