/* ERShader__op_new_unsigned_int at 0x803205F0 (48B) */
// FLAGS: -fno-elide-constructors

extern char g_h48n_803205F0[256];
extern void *ha48_803205F0(void *, unsigned int, int);

void *ERShader__op_new_unsigned_int(unsigned int size) { return ha48_803205F0(g_h48n_803205F0, size, 8); }
