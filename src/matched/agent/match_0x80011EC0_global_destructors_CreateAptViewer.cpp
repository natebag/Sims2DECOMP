// global_destructors keyed to CreateAptViewer(void)
// Address: 0x80011EC0 | Size: 44 bytes
// FLAGS: -fno-elide-constructors

extern void cleanup_CreateAptViewer(int a, unsigned short b);

void global_destructors_CreateAptViewer() {
    cleanup_CreateAptViewer(0, 0xFFFF);
}
