/* ENgcRenderer::QueueEndFrame(EEvent &) at 0x8033E858 (48B) */

struct ENgcRendCmd_QEF {
    int m_cmd;
    void* m_event;
    int m_pad1;
    int m_pad2;
};

struct ENgcRenderer_QEF {
    void EndFrame(ENgcRendCmd_QEF* cmd);
    void QueueEndFrame(void* event);
};

void ENgcRenderer_QEF::QueueEndFrame(void* event) {
    ENgcRendCmd_QEF cmd;
    cmd.m_cmd = 3;
    cmd.m_event = event;
    EndFrame(&cmd);
}
