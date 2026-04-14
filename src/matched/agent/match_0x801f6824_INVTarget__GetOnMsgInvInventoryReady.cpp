// 0x801f6824 INVTarget::GetOnMsgInvInventoryReady(char *) (52B)

extern int Sprintf(char*, char*, ...);

struct INVTarget {
    int GetOnMsgInvInventoryReady(char* buf);
};

int INVTarget::GetOnMsgInvInventoryReady(char* buf) {
    return Sprintf(buf, "%d", 1);
}
