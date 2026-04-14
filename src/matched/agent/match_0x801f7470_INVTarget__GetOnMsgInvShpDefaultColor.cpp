// 0x801f7470 INVTarget::GetOnMsgInvShpDefaultColor(char *) (52B)

extern int Sprintf(char*, char*, ...);

struct INVTarget {
    int GetOnMsgInvShpDefaultColor(char* buf);
};

int INVTarget::GetOnMsgInvShpDefaultColor(char* buf) {
    return Sprintf(buf, "%d", 0);
}
