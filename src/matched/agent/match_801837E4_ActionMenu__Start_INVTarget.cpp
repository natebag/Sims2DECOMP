class INVTarget;

class ActionMenu {
public:
    INVTarget* m_target;
    char _pad1[0x05];
    unsigned char m_active;
    char _pad2[0x9E];
    int m_playerIndex;

    void Start(INVTarget* target, int playerIndex);
};

void ActionMenu::Start(INVTarget* target, int playerIndex) {
    m_playerIndex = playerIndex;
    m_target = target;
    m_active = 1;
}
