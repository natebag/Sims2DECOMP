/* ENgcTextureC8__op_new_unsigned_int at 0x80350D84 (48B) */
// FLAGS: -fno-elide-constructors

extern char g_h48n_80350D84[256];
extern void *ha48_80350D84(void *, unsigned int, int);

void *ENgcTextureC8__op_new_unsigned_int(unsigned int size) { return ha48_80350D84(g_h48n_80350D84, size, 8); }
