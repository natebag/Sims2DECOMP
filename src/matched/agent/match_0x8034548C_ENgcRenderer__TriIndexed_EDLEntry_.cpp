// 0x8034548C (24B) ENgcRenderer::TriIndexed(EDLEntry *)

extern volatile int g_ENgcR_TriIndexed_dirty;

struct ENgcR_TI { void TriIndexed(void* entry); };

void ENgcR_TI::TriIndexed(void* entry) {
    if (!g_ENgcR_TriIndexed_dirty) return;
    g_ENgcR_TriIndexed_dirty = 0;
}
