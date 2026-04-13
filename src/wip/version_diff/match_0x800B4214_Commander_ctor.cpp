// FLAGS: -msdata=eabi -G 8
// 0x800B4214 Commander::Commander(void) (60b)

// SDA globals — small types for r13-relative addressing
extern void* g_CommanderHead;
extern int g_CommanderCount;

// VTable extern
extern int Commander_vtable[];

class Commander {
public:
    Commander* m_next;
    int m_field4;
    Commander* m_prev;
    int* m_vtable;
    Commander();
};

Commander::Commander() {
    Commander* head = (Commander*)g_CommanderHead;
    m_vtable = Commander_vtable;
    m_field4 = 0;
    m_next = head;
    m_prev = head;
    g_CommanderHead = this;
    g_CommanderCount++;
}
