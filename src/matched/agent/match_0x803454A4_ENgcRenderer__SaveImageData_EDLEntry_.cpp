// 0x803454A4 (24B) ENgcRenderer::SaveImageData(EDLEntry *)

extern volatile int g_ENgcR_SaveImageData_dirty;

struct ENgcR_SID { void SaveImageData(void* entry); };

void ENgcR_SID::SaveImageData(void* entry) {
    if (!g_ENgcR_SaveImageData_dirty) return;
    g_ENgcR_SaveImageData_dirty = 0;
}
