/* ENgcRenderer::QueueBeginFrame(int) at 0x8033E7F4 (48B) */

struct ENgcRendCmd_QBF {
    int m_cmd;
    int m_arg;
    int m_pad1;
    int m_pad2;
};

struct ENgcRenderer_QBF {
    void BeginFrame(ENgcRendCmd_QBF* cmd);
    void QueueBeginFrame(int arg);
};

void ENgcRenderer_QBF::QueueBeginFrame(int arg) {
    ENgcRendCmd_QBF cmd;
    cmd.m_cmd = 1;
    cmd.m_arg = arg;
    BeginFrame(&cmd);
}
