/* ENgcTextureC4_32__op_new_unsigned_int at 0x80350C20 (48B) */
// FLAGS: -fno-elide-constructors

extern char g_h48n_80350C20[256];
extern void *ha48_80350C20(void *, unsigned int, int);

void *ENgcTextureC4_32__op_new_unsigned_int(unsigned int size) { return ha48_80350C20(g_h48n_80350C20, size, 8); }
