// 0x8034A718 (24B) ENgcRenderer::SetMipMap(EDLEntry *)

extern volatile int g_ENgcR_SetMipMap_dirty;

struct ENgcR_SMM { void SetMipMap(void* entry); };

void ENgcR_SMM::SetMipMap(void* entry) {
    if (!g_ENgcR_SetMipMap_dirty) return;
    g_ENgcR_SetMipMap_dirty = 0;
}
