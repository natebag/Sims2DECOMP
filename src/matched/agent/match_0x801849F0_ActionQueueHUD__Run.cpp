// ActionQueueHUD::Run(void) @ 0x801849F0 (64B)

struct AQH_Run {
    char _pad[792];
    unsigned char m_active;
    void Run();
    void RunIngame();
    void RunEditActionQueue();
};

void AQH_Run::Run() {
    unsigned char active = m_active;
    if (active == 1) goto do_ingame;
    if (active == 2) goto do_edit;
    return;
do_ingame:
    RunIngame();
    return;
do_edit:
    RunEditActionQueue();
}
