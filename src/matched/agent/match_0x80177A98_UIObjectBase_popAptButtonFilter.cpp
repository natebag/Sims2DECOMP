// 0x80177A98 (52B) UIObjectBase::popAptButtonFilter(int, unsigned int)

struct UIObjectBase;

struct AptFilterMgr {
    void Pop(UIObjectBase* obj, int arg);
};

extern char g_aptFilterMgr[16];

struct UIObjectBase2 {
    void popAptButtonFilter(int arg1, unsigned int arg2);
};

void UIObjectBase2::popAptButtonFilter(int arg1, unsigned int) {
    (*(AptFilterMgr**)g_aptFilterMgr)->Pop((UIObjectBase*)this, arg1);
}
