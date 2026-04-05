// global_destructors keyed to GameData__GameData_void
// Address: 0x8003DEA8 | Size: 44 bytes
// FLAGS: -fno-elide-constructors

extern void cleanup_GameData(int a, unsigned short b);

void global_destructors_GameData() {
    cleanup_GameData(0, 0xFFFF);
}
