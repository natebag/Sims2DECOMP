// 0x8034A700 (24B) ENgcRenderer::RecalcMatrices(EDLEntry *)

extern volatile int g_ENgcR_RecalcMatrices_dirty;

struct ENgcR_RM { void RecalcMatrices(void* entry); };

void ENgcR_RM::RecalcMatrices(void* entry) {
    if (!g_ENgcR_RecalcMatrices_dirty) return;
    g_ENgcR_RecalcMatrices_dirty = 0;
}
