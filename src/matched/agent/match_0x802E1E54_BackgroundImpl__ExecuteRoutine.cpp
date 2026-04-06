// 0x802E1E54 BackgroundImpl::ExecuteRoutine (84b)

struct BackgroundCmd {
    int type;
    void* routine;
    int pad;
    int param;
};

extern void* __nw__FUl(unsigned long);

struct BackgroundImpl {
    void SendCommand(BackgroundCmd*);
    void ExecuteRoutine(void (*func)(void));
};

void BackgroundImpl::ExecuteRoutine(void (*func)(void)) {
    BackgroundCmd* cmd = (BackgroundCmd*)__nw__FUl(16);
    cmd->param = 0;
    cmd->type = 3;
    cmd->routine = (void*)func;
    SendCommand(cmd);
}
