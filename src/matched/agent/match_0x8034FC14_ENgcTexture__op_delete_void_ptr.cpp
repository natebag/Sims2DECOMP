/* ENgcTexture__op_delete_void_ptr at 0x8034FC14 (44B) */
// FLAGS: -fno-elide-constructors

extern char g_h44d_8034FC14[256];
extern void hf44_8034FC14(void *, void *);

void ENgcTexture__op_delete_void_ptr(void *ptr) { hf44_8034FC14(g_h44d_8034FC14, ptr); }
