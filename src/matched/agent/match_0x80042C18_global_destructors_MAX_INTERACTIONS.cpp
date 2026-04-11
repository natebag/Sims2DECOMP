// global_destructors keyed to MAX_INTERACTIONS
// Address: 0x80042C18 | Size: 44 bytes

extern void cleanup_MAX_INTERACTIONS(int a, unsigned short b);

void global_destructors_MAX_INTERACTIONS() {
    cleanup_MAX_INTERACTIONS(0, 0xFFFF);
}
