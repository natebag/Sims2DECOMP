// 0x803451A4 (24B) ENgcRenderer::MipMapSetup(EDLEntry *)

extern volatile int g_ENgcR_MipMapSetup_dirty;

struct ENgcR_MMS { void MipMapSetup(void* entry); };

void ENgcR_MMS::MipMapSetup(void* entry) {
    if (!g_ENgcR_MipMapSetup_dirty) return;
    g_ENgcR_MipMapSetup_dirty = 0;
}
