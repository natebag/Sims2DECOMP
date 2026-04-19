/* ENgcRenderer::Flush(void) at 0x8033E8BC (44B) */

struct ENgcRendCmd_FLU {
    int m_cmd;
    int m_pad1;
    int m_pad2;
};

struct ENgcRenderer_FLU {
    void Flush(ENgcRendCmd_FLU* cmd);
    void Flush();
};

void ENgcRenderer_FLU::Flush() {
    ENgcRendCmd_FLU cmd;
    cmd.m_cmd = 5;
    Flush(&cmd);
}
