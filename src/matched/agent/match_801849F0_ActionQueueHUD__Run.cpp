class ActionQueueHUD {
public:
    char _pad[0x318];
    unsigned char m_state;

    void RunIngame(void);
    void RunEditActionQueue(void);
    void Run(void);
};

void ActionQueueHUD::Run(void) {
    switch (m_state) {
        case 1:
            RunIngame();
            break;
        case 2:
            RunEditActionQueue();
            break;
    }
}
