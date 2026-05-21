// 0x801A0514 CASRoommateTarget::SetButtonState(void) (72B)

class UIObjectBase {
public:
    static void AptViewer_CallFunction(char* widget, char* a, char* b, int n, char** args);
};

extern char s_casRoommateBtnWidget[];  // 0x803ED38C

class CASRoommateTarget {
public:
    void SetButtonState();
    char* GetButtonStateString(char* buf);
};

void CASRoommateTarget::SetButtonState() {
    struct {
        char buf[8];
        char* arg;
    } u;
    GetButtonStateString(u.buf);
    u.arg = u.buf;
    UIObjectBase::AptViewer_CallFunction(s_casRoommateBtnWidget, 0, 0, 1, &u.arg);
}
