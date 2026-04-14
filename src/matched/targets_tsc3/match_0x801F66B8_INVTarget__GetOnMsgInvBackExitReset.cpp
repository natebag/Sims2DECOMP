// 0x801F66B8 INVTarget::GetOnMsgInvBackExitReset(char*) (64B)
// Pattern: non-SDA global ptr check + conditional call vs default short copy
extern int g_cheatMgrPtr[3];                    // non-SDA
extern const unsigned short g_defaultChar_BE[16];  // non-SDA

struct INVTarget {
    int Cheat_HandleReturnUpHierarchy(char* s);
    void GetOnMsgInvBackExitReset(char* p);
};

void INVTarget::GetOnMsgInvBackExitReset(char* p) {
    if (g_cheatMgrPtr[0] != 0) {
        Cheat_HandleReturnUpHierarchy(p);
    } else {
        *(unsigned short*)p = g_defaultChar_BE[0];
    }
}
