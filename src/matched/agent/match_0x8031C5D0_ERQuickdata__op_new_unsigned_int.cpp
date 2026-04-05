/* ERQuickdata__op_new_unsigned_int at 0x8031C5D0 (48B) */
// FLAGS: -fno-elide-constructors

extern char g_h48n_8031C5D0[256];
extern void *ha48_8031C5D0(void *, unsigned int, int);

void *ERQuickdata__op_new_unsigned_int(unsigned int size) { return ha48_8031C5D0(g_h48n_8031C5D0, size, 8); }
