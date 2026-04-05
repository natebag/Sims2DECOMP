/* ENgcTextureRGBA8__op_new_unsigned_int at 0x80351800 (48B) */
// FLAGS: -fno-elide-constructors

extern char g_h48n_80351800[256];
extern void *ha48_80351800(void *, unsigned int, int);

void *ENgcTextureRGBA8__op_new_unsigned_int(unsigned int size) { return ha48_80351800(g_h48n_80351800, size, 8); }
