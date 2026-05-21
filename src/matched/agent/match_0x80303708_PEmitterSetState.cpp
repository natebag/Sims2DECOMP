// 0x80303708 PEmitterSetState(PEmitter*, int, int) (40B)
// If enable==0: clear bits; else: set bits. beq branches over OR path to ANDC path.

struct PEmitter {
    char pad[80];
    int m_state;
};

void PEmitterSetState(PEmitter* emitter, int mask, int enable) {
    if (enable == 0)
        goto do_clear;
    emitter->m_state |= mask;
    return;
do_clear:
    emitter->m_state &= ~mask;
}
