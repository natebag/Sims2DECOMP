// global_destructors keyed to ESimsDataManager__pCurrentManager
// Address: 0x8002369C | Size: 44 bytes
// FLAGS: -fno-elide-constructors

extern void cleanup_ESimsDataManager(int a, unsigned short b);

void global_destructors_ESimsDataManager() {
    cleanup_ESimsDataManager(0, 0xFFFF);
}
