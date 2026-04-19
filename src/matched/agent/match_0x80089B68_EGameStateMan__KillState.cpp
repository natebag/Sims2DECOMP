/* EGameStateMan::KillState(void) at 0x80089B68 (56B) */

struct EGameStateMan_KS {
    void* m_state;
    void StopState(int* code);
    void KillState();
};

void EGameStateMan_KS::KillState() {
    if (m_state) {
        int code = 2;
        StopState(&code);
    }
}
