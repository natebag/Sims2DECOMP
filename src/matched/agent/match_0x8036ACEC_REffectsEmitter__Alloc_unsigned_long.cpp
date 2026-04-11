/* REffectsEmitter__Alloc_unsigned_long at 0x8036ACEC (48B) */
// FLAGS: -fno-elide-constructors

extern char g_h48n_8036ACEC[256];
extern void *ha48_8036ACEC(void *, unsigned int, int);

void *REffectsEmitter__Alloc_unsigned_long(unsigned int size) { return ha48_8036ACEC(g_h48n_8036ACEC, size, 8); }
