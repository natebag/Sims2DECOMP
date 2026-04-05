/* REffectsEmitter__Free_void_ptr at 0x8036AD4C (44B) */
// FLAGS: -fno-elide-constructors

extern char g_h44d_8036AD4C[256];
extern void hf44_8036AD4C(void *, void *);

void REffectsEmitter__Free_void_ptr(void *ptr) { hf44_8036AD4C(g_h44d_8036AD4C, ptr); }
