// 0x803451BC (40B) ENgcRenderer::Debug(EDLEntry *)

extern volatile int g_ENgcR_Debug_dirty;
extern int g_ENgcR_DebugVal;
extern int g_ENgcR_DebugMode;

struct ENgcR_Dbg { void Debug(void* entry); };

void ENgcR_Dbg::Debug(void* entry) {
    if (g_ENgcR_Debug_dirty) g_ENgcR_Debug_dirty = 0;
    g_ENgcR_DebugVal = ((int*)entry)[1];
    g_ENgcR_DebugMode = ((unsigned char*)entry)[1];
}
