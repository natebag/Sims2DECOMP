/* ENgcTextureCMPR__op_delete_void_ptr at 0x80351570 (44B) */
// FLAGS: -fno-elide-constructors

extern char g_h44d_80351570[256];
extern void hf44_80351570(void *, void *);

void ENgcTextureCMPR__op_delete_void_ptr(void *ptr) { hf44_80351570(g_h44d_80351570, ptr); }
