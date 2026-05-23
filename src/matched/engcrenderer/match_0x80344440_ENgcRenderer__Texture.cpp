// ENgcRenderer::Texture(EDLEntry *) at 0x80344440 (60B)
// DOL:
//   prologue, save r30..r31; r5 = cmd[1] (lbz); r30 = this; r4 = cmd[4]
//   bl SetTexture(this, ptr, byte); m_active = 1; epilogue

struct EDLEntry_TX {
    char pad0;
    unsigned char m_byte1;
    char pad2[2];
    void* m_ptr4;
};

struct ENgcRenderer_TX {
    char pad[1296];
    int m_active;
    void Texture(EDLEntry_TX* cmd);
    void SetTexture(void* tex, int flag);
};

void ENgcRenderer_TX::Texture(EDLEntry_TX* cmd) {
    SetTexture(cmd->m_ptr4, cmd->m_byte1);
    m_active = 1;
}
