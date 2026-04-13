// 0x80194F8C CASTarget::GotoBase (36B)

struct UIScreenID;
void CASTarget_GotoScreen(void* self, int screenId);

struct CASTarget {
    char pad[0x98];
    int m_baseScreenId;

    void GotoBase();
};

void CASTarget::GotoBase() {
    CASTarget_GotoScreen(this, m_baseScreenId);
}
