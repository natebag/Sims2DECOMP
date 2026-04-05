/* ERShader__op_delete_void_ptr at 0x80320628 (44B) */
// FLAGS: -fno-elide-constructors

extern char g_h44d_80320628[256];
extern void hf44_80320628(void *, void *);

void ERShader__op_delete_void_ptr(void *ptr) { hf44_80320628(g_h44d_80320628, ptr); }
