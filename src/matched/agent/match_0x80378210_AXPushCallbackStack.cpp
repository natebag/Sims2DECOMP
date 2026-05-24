// FLAGS: -fno-schedule-insns
// 0x80378210 __AXPushCallbackStack (16B)
// lwz r0,-22288(r13); stw r0,0x8(r3); stw r3,-22288(r13); blr
struct AXCallbackEntry {
    char pad[8];
    AXCallbackEntry* m_prev;
};
extern AXCallbackEntry* gAXCallbackStack;
void AXPushCallbackStack(AXCallbackEntry* entry) {
    entry->m_prev = gAXCallbackStack;
    gAXCallbackStack = entry;
}
