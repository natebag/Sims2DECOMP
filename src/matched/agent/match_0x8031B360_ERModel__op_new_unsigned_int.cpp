/* ERModel__op_new_unsigned_int at 0x8031B360 (48B) */
// FLAGS: -fno-elide-constructors

extern char g_h48n_8031B360[256];
extern void *ha48_8031B360(void *, unsigned int, int);

void *ERModel__op_new_unsigned_int(unsigned int size) { return ha48_8031B360(g_h48n_8031B360, size, 8); }
