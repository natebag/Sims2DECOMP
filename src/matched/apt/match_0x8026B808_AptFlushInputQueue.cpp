// FLAGS: -fno-schedule-insns -fno-schedule-insns2
// 0x8026B808 (36B) AptFlushInputQueue(void)

extern char g_aptInputQueue[16];

struct AptManager {
    char pad[0x34];
    int m_field34;
};

extern AptManager* g_aptManager;

void AptFlushInputQueue() {
    if (*(int*)g_aptInputQueue != 0) {
        return;
    }
    AptManager* mgr = g_aptManager;
    if (mgr == 0) {
        return;
    }
    mgr->m_field34 = 0;
}
