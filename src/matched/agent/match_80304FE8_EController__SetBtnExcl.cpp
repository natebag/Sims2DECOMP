struct BtnState { char m_pad[120]; int m_excl; };
class EController {
public:
    char m_pad[512];
    BtnState *m_pBtnState;
    void SetBtnExcl();
};
void EController::SetBtnExcl() { m_pBtnState->m_excl = 1; }
