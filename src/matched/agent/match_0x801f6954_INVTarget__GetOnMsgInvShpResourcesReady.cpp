// 0x801f6954 INVTarget::GetOnMsgInvShpResourcesReady(char *) (52B)

extern int Sprintf(char*, char*, ...);

struct INVTarget {
    int GetOnMsgInvShpResourcesReady(char* buf);
};

int INVTarget::GetOnMsgInvShpResourcesReady(char* buf) {
    return Sprintf(buf, "%d", 1);
}
