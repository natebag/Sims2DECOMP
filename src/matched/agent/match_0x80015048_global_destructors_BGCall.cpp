// global_destructors keyed to BGCall_LoadDefaultNeighborhood(void)
// Address: 0x80015048 | Size: 44 bytes
// FLAGS: -fno-elide-constructors

extern void cleanup_BGCall(int a, unsigned short b);

void global_destructors_BGCall() {
    cleanup_BGCall(0, 0xFFFF);
}
