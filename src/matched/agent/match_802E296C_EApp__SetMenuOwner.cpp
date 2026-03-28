typedef int OVERALL_GAME_STATE;
class EApp {
public:
    char m_pad[1132];
    OVERALL_GAME_STATE m_menuOwner;
    void SetMenuOwner(OVERALL_GAME_STATE);
};
void EApp::SetMenuOwner(OVERALL_GAME_STATE owner) { m_menuOwner = owner; }
