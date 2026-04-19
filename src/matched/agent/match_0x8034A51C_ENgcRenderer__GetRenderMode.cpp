/* ENgcRenderer::GetRenderMode(void) at 0x8034A51C (28B) */

struct ENgcRenderModeData_GRM { char _x; };

struct ENgcRenderer_GRM {
    char _pad[0x34C];
    int m_modeEnabled;          // 0x34C
    char _pad2[20];
    ENgcRenderModeData_GRM m_renderMode; // 0x364
    ENgcRenderModeData_GRM* GetRenderMode();
};

ENgcRenderModeData_GRM* ENgcRenderer_GRM::GetRenderMode() {
    if (m_modeEnabled != 0) return &m_renderMode;
    return 0;
}
