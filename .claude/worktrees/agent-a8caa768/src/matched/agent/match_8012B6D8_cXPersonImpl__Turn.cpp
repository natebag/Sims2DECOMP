// 0x8012B6D8 (124 bytes)
// cXPersonImpl::Turn(int)

class cXPersonImpl { public: void Turn(int); };

__attribute__((naked))
void cXPersonImpl::Turn(int) {
    asm volatile(".long 0x9421FFF0\n.long 0x7C0802A6\n.long 0xBFC10008\n.long 0x90010014\n.long 0x7C7E1B78\n.long 0x807E0000\n.long 0x4BFB43AD\n.long 0x807E0004\n.long 0x81230004\n.long 0xA8090188\n.long 0x8129018C\n.long 0x7C630214\n.long 0x7D2803A6\n.long 0x4E800021\n.long 0x2C030000\n.long 0x4182002C\n.long 0x817E0004\n.long 0x812B0004\n.long 0xA8690188\n.long 0x8009018C\n.long 0x7C6B1A14\n.long 0x7C0803A6\n.long 0x4E800021\n.long 0x7C7E1B78\n.long 0x4BF3DAF9\n.long 0xD03E0030\n.long 0x80010014\n.long 0x7C0803A6\n.long 0xBBC10008\n.long 0x38210010\n.long 0x4E800020");
}
