// 0x802E1D98 BackgroundImpl::TerminateThread (76b)

struct BackgroundCmd {
    int type;
    char pad[8];
    int param;
};

extern void* __nw__FUl(unsigned long);

struct BackgroundImpl {
    void SendCommand(BackgroundCmd*);
    void TerminateThread();
};

void BackgroundImpl::TerminateThread() {
    BackgroundCmd* cmd = (BackgroundCmd*)__nw__FUl(16);
    cmd->param = 0;
    cmd->type = 2;
    SendCommand(cmd);
}
