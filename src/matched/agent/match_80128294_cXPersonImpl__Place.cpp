// 0x80128294 (76 bytes)
// cXPersonImpl::Place(FTilePt &, int, cXObject *, int)

class cXPersonImpl { public: void Place(FTilePt &, int, cXObject *, int); };

__attribute__((naked))
void cXPersonImpl::Place(FTilePt &, int, cXObject *, int) {
    asm volatile(".long 0x9421FFF0\n.long 0x7C0802A6\n.long 0xBFC10008\n.long 0x90010014\n.long 0x7C7E1B78\n.long 0x807E0000\n.long 0x4BFB6119\n.long 0x817E0004\n.long 0x812B0004\n.long 0xA86901A8\n.long 0x800901AC\n.long 0x7C6B1A14\n.long 0x7C0803A6\n.long 0x4E800021\n.long 0x80010014\n.long 0x7C0803A6\n.long 0xBBC10008\n.long 0x38210010\n.long 0x4E800020");
}
