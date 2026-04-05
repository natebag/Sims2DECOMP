/* ENgcTextureC8__op_delete_void_ptr at 0x80350DBC (44B) */
// FLAGS: -fno-elide-constructors

extern char g_h44d_80350DBC[256];
extern void hf44_80350DBC(void *, void *);

void ENgcTextureC8__op_delete_void_ptr(void *ptr) { hf44_80350DBC(g_h44d_80350DBC, ptr); }
