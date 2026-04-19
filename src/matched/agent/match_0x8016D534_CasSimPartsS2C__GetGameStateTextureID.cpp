/* CasSimPartsS2C::GetGameStateTextureID(unsigned int) const at 0x8016D534 (44B) */

struct SimModel_GSTI {
    static int GetGameStateTextureID(unsigned int idx, int flag);
};

struct CasSimPartsS2C_GSTI {
    char m_pad[12];
    int m_flag;
    int GetGameStateTextureID(unsigned int idx) const;
};

int CasSimPartsS2C_GSTI::GetGameStateTextureID(unsigned int idx) const {
    return SimModel_GSTI::GetGameStateTextureID(idx, m_flag ^ 1);
}
