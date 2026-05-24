// FLAGS: -fno-schedule-insns
// 0x80253428 OSInitThreadQueue (16B)
// li r0,0; stw r0,0x4(r3); stw r0,0x0(r3); blr — tail stored first
struct OSThreadQueue { int m_head; int m_tail; };
void OSInitThreadQueue(OSThreadQueue* q) {
    q->m_tail = 0;
    q->m_head = 0;
}
