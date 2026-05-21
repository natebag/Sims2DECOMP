// 0x801F66B8 INVTarget::GetOnMsgInvBackExitReset(char *) (64B)

extern char g_BackExitFlag[16];
extern char g_BackExitDefault_block[16];

class INVTarget {
public:
    void Cheat_HandleReturnUpHierarchy(char* s);
    void GetOnMsgInvBackExitReset(char* out);
};

void INVTarget::GetOnMsgInvBackExitReset(char* out) {
    if (*(void**)g_BackExitFlag != 0) {
        Cheat_HandleReturnUpHierarchy(out);
    } else {
        *(short*)out = *(short*)g_BackExitDefault_block;
    }
}
