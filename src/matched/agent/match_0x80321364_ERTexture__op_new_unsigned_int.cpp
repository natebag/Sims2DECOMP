/* ERTexture__op_new_unsigned_int at 0x80321364 (48B) */
// FLAGS: -fno-elide-constructors

extern char g_h48n_80321364[256];
extern void *ha48_80321364(void *, unsigned int, int);

void *ERTexture__op_new_unsigned_int(unsigned int size) { return ha48_80321364(g_h48n_80321364, size, 8); }
