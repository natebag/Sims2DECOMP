// 0x80177A64 (52B) UIObjectBase::pushAptButtonFilter(int, char *)

struct UIObjectBase;

struct AptFilterMgr {
    void Push(UIObjectBase* obj, int arg);
};

extern char g_aptFilterMgr[16];

struct UIObjectBase2 {
    void pushAptButtonFilter(int arg1, char* arg2);
};

void UIObjectBase2::pushAptButtonFilter(int arg1, char*) {
    (*(AptFilterMgr**)g_aptFilterMgr)->Push((UIObjectBase*)this, arg1);
}
