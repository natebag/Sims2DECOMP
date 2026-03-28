// 0x8013532C (88 bytes)
// RelArray::DoStream(ReconBuffer *, int)

class RelArray { public: void DoStream(ReconBuffer *, int); };

__attribute__((naked))
void RelArray::DoStream(ReconBuffer *, int) {
    asm volatile(".long 0x9421FFE8\n.long 0x7C0802A6\n.long 0xBFA1000C\n.long 0x9001001C\n.long 0x7C7F1B78\n.long 0x7C9E2378\n.long 0x7CBD2B79\n.long 0x40810014\n.long 0x7FC3F378\n.long 0x389F0010\n.long 0x38A00001\n.long 0x4BFFE2DD\n.long 0x7FE3FB78\n.long 0x7FC5F378\n.long 0x80830000\n.long 0x7FA6EB78\n.long 0x48277065\n.long 0x8001001C\n.long 0x7C0803A6\n.long 0xBBA1000C\n.long 0x38210018\n.long 0x4E800020");
}
