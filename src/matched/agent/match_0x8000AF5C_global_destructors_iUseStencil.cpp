// global_destructors keyed to iUseStencil
// Address: 0x8000AF5C | Size: 44 bytes

extern void cleanup_iUseStencil(int a, unsigned short b);

void global_destructors_iUseStencil() {
    cleanup_iUseStencil(0, 0xFFFF);
}
