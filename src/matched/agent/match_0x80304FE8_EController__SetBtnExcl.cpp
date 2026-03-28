struct BtnData {
    char _p[0x78];
    int m_excl;
};
struct EController {
    char _p[0x200];
    BtnData *m_btnData;
    void SetBtnExcl();
};
void EController::SetBtnExcl() { m_btnData->m_excl = 1; }
