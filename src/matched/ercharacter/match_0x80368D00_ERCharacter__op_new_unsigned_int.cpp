/* ERCharacter__op_new_unsigned_int at 0x80368D00 (48B) */
// FLAGS: -fno-elide-constructors

extern char g_h48n_80368D00[256];
extern void *ha48_80368D00(void *, unsigned int, int);

void *ERCharacter__op_new_unsigned_int(unsigned int size) { return ha48_80368D00(g_h48n_80368D00, size, 8); }
