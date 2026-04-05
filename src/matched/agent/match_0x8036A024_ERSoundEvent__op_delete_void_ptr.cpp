/* ERSoundEvent__op_delete_void_ptr at 0x8036A024 (44B) */
// FLAGS: -fno-elide-constructors

extern char g_h44d_8036A024[256];
extern void hf44_8036A024(void *, void *);

void ERSoundEvent__op_delete_void_ptr(void *ptr) { hf44_8036A024(g_h44d_8036A024, ptr); }
