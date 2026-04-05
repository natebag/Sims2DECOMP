/* ERSoundEvent__op_new_unsigned_int at 0x80369FEC (48B) */
// FLAGS: -fno-elide-constructors

extern char g_h48n_80369FEC[256];
extern void *ha48_80369FEC(void *, unsigned int, int);

void *ERSoundEvent__op_new_unsigned_int(unsigned int size) { return ha48_80369FEC(g_h48n_80369FEC, size, 8); }
