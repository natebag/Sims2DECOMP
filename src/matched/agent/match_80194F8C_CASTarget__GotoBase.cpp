typedef int UIScreenID;

class CASTarget {
public:
    char _pad[0x98];
    UIScreenID m_baseScreen;

    void GotoScreen(UIScreenID screen);
    void GotoBase(void);
};

void CASTarget::GotoBase(void) {
    GotoScreen(m_baseScreen);
}
