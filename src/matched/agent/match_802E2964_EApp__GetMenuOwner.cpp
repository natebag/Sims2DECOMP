typedef int OVERALL_GAME_STATE;
class EApp {
public:
    char m_pad[1132];
    OVERALL_GAME_STATE m_menuOwner;
    OVERALL_GAME_STATE GetMenuOwner() const;
};
OVERALL_GAME_STATE EApp::GetMenuOwner() const { return m_menuOwner; }
