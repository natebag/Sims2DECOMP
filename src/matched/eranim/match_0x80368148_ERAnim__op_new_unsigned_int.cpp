/* ERAnim__op_new_unsigned_int at 0x80368148 (48B) */
// FLAGS: -fno-elide-constructors

extern char g_h48n_80368148[256];
extern void *ha48_80368148(void *, unsigned int, int);

void *ERAnim__op_new_unsigned_int(unsigned int size) { return ha48_80368148(g_h48n_80368148, size, 8); }
