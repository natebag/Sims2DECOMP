/* ENgcRenderer::QueueDisplayList(EDL *, bool) at 0x8033E824 (52B) */

struct ENgcRendCmd_QDL {
    int m_cmd;
    void* m_dl;
    int m_flag;
};

struct ENgcRenderer_QDL {
    void DisplayList(ENgcRendCmd_QDL* cmd);
    void QueueDisplayList(void* dl, int flag);
};

void ENgcRenderer_QDL::QueueDisplayList(void* dl, int flag) {
    ENgcRendCmd_QDL cmd;
    cmd.m_cmd = 2;
    cmd.m_dl = dl;
    cmd.m_flag = flag;
    DisplayList(&cmd);
}
