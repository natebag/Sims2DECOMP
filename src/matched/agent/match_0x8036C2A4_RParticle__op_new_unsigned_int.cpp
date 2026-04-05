/* RParticle__op_new_unsigned_int at 0x8036C2A4 (48B) */
// FLAGS: -fno-elide-constructors

extern char g_h48n_8036C2A4[256];
extern void *ha48_8036C2A4(void *, unsigned int, int);

void *RParticle__op_new_unsigned_int(unsigned int size) { return ha48_8036C2A4(g_h48n_8036C2A4, size, 8); }
