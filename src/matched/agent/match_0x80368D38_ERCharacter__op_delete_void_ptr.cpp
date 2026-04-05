/* ERCharacter__op_delete_void_ptr at 0x80368D38 (44B) */
// FLAGS: -fno-elide-constructors

extern char g_h44d_80368D38[256];
extern void hf44_80368D38(void *, void *);

void ERCharacter__op_delete_void_ptr(void *ptr) { hf44_80368D38(g_h44d_80368D38, ptr); }
