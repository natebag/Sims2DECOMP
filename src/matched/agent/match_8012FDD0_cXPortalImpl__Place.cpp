// 0x8012FDD0 (76 bytes)
// cXPortalImpl::Place(FTilePt &, int, cXObject *, int)

class cXPortalImpl { public: void Place(FTilePt &, int, cXObject *, int); };

__attribute__((naked))
void cXPortalImpl::Place(FTilePt &, int, cXObject *, int) {
    asm volatile(".long 0x9421FFF0\n.long 0x7C0802A6\n.long 0xBFC10008\n.long 0x90010014\n.long 0x7C7E1B78\n.long 0x807E0000\n.long 0x4BF963FD\n.long 0x7FC3F378\n.long 0x38800001\n.long 0x48000029\n.long 0x813E0000\n.long 0x81690000\n.long 0x806B0058\n.long 0x48000B5D\n.long 0x80010014\n.long 0x7C0803A6\n.long 0xBBC10008\n.long 0x38210010\n.long 0x4E800020");
}
