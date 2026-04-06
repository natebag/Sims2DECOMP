// 0x802E1EA8 BackgroundImpl::ExecuteArgRoutine (88b)

struct BackgroundCmd {
    int type;
    void* routine;
    int pad;
    void* arg;
};

extern void* __nw__FUl(unsigned long);

struct BackgroundImpl {
    void SendCommand(BackgroundCmd*);
    void ExecuteArgRoutine(void (*func)(void*), void* arg);
};

void BackgroundImpl::ExecuteArgRoutine(void (*func)(void*), void* arg) {
    BackgroundCmd* cmd = (BackgroundCmd*)__nw__FUl(16);
    cmd->type = 4;
    cmd->routine = (void*)func;
    cmd->arg = arg;
    SendCommand(cmd);
}
