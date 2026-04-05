// global_destructors keyed to ESimsCam__m_modeDef
// Address: 0x8001EB10 | Size: 44 bytes
// FLAGS: -fno-elide-constructors

extern void cleanup_ESimsCam(int a, unsigned short b);

void global_destructors_ESimsCam() {
    cleanup_ESimsCam(0, 0xFFFF);
}
