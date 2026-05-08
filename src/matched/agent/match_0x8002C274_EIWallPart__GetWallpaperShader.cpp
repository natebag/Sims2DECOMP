// EIWallPart::GetWallpaperShader(void) at 0x8002C274 (76 bytes)
// Returns cached m_pShader if set, else walks m_pPart -> m_pSlot -> shader.

struct EIWP_GWS_Inner_Inner {
    void* m_p0;
    char _pad[4];
    void* m_p8;            // offset 8 — the returned shader
};

struct EIWP_GWS_Inner {
    EIWP_GWS_Inner_Inner* m_p0;   // offset 0
    int m_p4;                      // offset 4 — guard
};

struct EIWP_GWS_Outer {
    char _pad[60];
    EIWP_GWS_Inner* m_p60;         // offset 60
    int m_p64;                     // offset 64 — guard
};

struct EIWP_GWS {
    char _pad[288];
    EIWP_GWS_Outer* m_p288;        // offset 288
    char _pad2[636];                // 928 - 288 - 4 = 636
    void* m_p928;                   // offset 928 — cached shader
    void* GetWallpaperShader();
};

void* EIWP_GWS::GetWallpaperShader() {
    if (m_p928) return m_p928;
    EIWP_GWS_Outer* outer = m_p288;
    EIWP_GWS_Inner* inner;
    if (!outer)            goto RET0;
    if (!outer->m_p64)     goto RET0;
    inner = outer->m_p60;
    if (inner->m_p4)       goto RET_OK;
RET0:
    return 0;
RET_OK:
    return inner->m_p0->m_p8;
}
