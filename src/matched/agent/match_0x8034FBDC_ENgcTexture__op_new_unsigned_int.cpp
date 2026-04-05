/* ENgcTexture__op_new_unsigned_int at 0x8034FBDC (48B) */
// FLAGS: -fno-elide-constructors

extern char g_h48n_8034FBDC[256];
extern void *ha48_8034FBDC(void *, unsigned int, int);

void *ENgcTexture__op_new_unsigned_int(unsigned int size) { return ha48_8034FBDC(g_h48n_8034FBDC, size, 8); }
