/* ENgcTextureC8_32__op_new_unsigned_int at 0x80351430 (48B) */
// FLAGS: -fno-elide-constructors

extern char g_h48n_80351430[256];
extern void *ha48_80351430(void *, unsigned int, int);

void *ENgcTextureC8_32__op_new_unsigned_int(unsigned int size) { return ha48_80351430(g_h48n_80351430, size, 8); }
