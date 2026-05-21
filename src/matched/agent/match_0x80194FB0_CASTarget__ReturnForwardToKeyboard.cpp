// 0x80194FB0 CASTarget::ReturnForwardToKeyboard() (80B)

class UIDB {
public:
    static int UIDBGetInt(char* name);
};

class K2YTarget {
public:
    static void SetStartMode(int mode);
};

extern char g_keyMode_name_803FC0C0[];

class CASTarget {
public:
    static void ReturnForwardToKeyboard();
};

void CASTarget::ReturnForwardToKeyboard() {
    int v = UIDB::UIDBGetInt(g_keyMode_name_803FC0C0);
    if (v == 0) goto mode2;
    if (v == 1) goto mode4;
    return;
mode2:
    K2YTarget::SetStartMode(2);
    return;
mode4:
    K2YTarget::SetStartMode(4);
}
