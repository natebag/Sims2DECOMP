/* ESim::UpdateQueuedOperation(void) at 0x800348B8 (80B) */

extern void* gThread;

struct EThread {
    void IsCallingThread(void);
};

struct ESim {
    char pad_00[0x43C];
    int m_field43C;
    char pad_440[0x520 - 0x440];
    int m_field520;

    void UpdateQueuedOperation(void);
};

void ESim::UpdateQueuedOperation(void) {
    ((EThread*)gThread)->IsCallingThread();
    if (m_field520 != 0) {
        if (m_field43C <= 0) {
            m_field520 = 0;
        }
    }
}
