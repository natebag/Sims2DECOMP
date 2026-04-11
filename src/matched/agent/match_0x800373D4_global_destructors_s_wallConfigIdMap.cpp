// global_destructors keyed to s_wallConfigIdMap
// Address: 0x800373D4 | Size: 44 bytes

extern void cleanup_wallConfigIdMap(int a, unsigned short b);

void global_destructors_wallConfigIdMap() {
    cleanup_wallConfigIdMap(0, 0xFFFF);
}
