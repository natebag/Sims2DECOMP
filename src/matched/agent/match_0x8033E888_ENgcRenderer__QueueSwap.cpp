/* ENgcRenderer::QueueSwap(int, int) at 0x8033E888 (52B) */

struct ENgcRendCmd_QS {
    int m_cmd;
    int m_a;
    int m_b;
};

struct ENgcRenderer_QS {
    void Swap(ENgcRendCmd_QS* cmd);
    void QueueSwap(int a, int b);
};

void ENgcRenderer_QS::QueueSwap(int a, int b) {
    ENgcRendCmd_QS cmd;
    cmd.m_cmd = 4;
    cmd.m_a = a;
    cmd.m_b = b;
    Swap(&cmd);
}
