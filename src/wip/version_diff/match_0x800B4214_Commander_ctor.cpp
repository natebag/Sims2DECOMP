// FLAGS: -msdata=eabi -G 8
// 0x800B4214 Commander::Commander(void) (60b)

// SDA globals — small types for r13-relative addressing
extern void* g_CommanderHead;      // At -32076(r13)
extern int g_CommanderCount;       // At -32072(r13)

// VTable extern
extern int Commander_vtable[];

struct Commander {
    Commander* m_next;
    int m_field4;
    Commander* m_prev;
    int* m_vtable;
};

void Commander_ctor(Commander* this_) {
    Commander* head = (Commander*)g_CommanderHead;
    this_->m_vtable = Commander_vtable;
    this_->m_field4 = 0;
    this_->m_next = head;
    this_->m_prev = 0;
    g_CommanderHead = this_;
    g_CommanderCount++;
}
