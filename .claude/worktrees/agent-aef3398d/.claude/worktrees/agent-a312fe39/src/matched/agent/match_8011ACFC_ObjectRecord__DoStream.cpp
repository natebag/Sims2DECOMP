// 0x8011ACFC (104 bytes)
// ObjectRecord::DoStream(ReconBuffer *, int)

class ObjectRecord { public: void DoStream(ReconBuffer *, int); };

__attribute__((naked))
void ObjectRecord::DoStream(ReconBuffer *, int) {
    asm volatile(".long 0x9421FFE8\n.long 0x7C0802A6\n.long 0xBFA1000C\n.long 0x9001001C\n.long 0x816DAC14\n.long 0x7C7D1B78\n.long 0x7C9E2378\n.long 0x7FA5EB78\n.long 0x812B0000\n.long 0xA86901D8\n.long 0x800901DC\n.long 0x7C6B1A14\n.long 0x7C0803A6\n.long 0x4E800021\n.long 0x7FC3F378\n.long 0x389D0004\n.long 0x38A00001\n.long 0x480188D5\n.long 0x7FC3F378\n.long 0x389D0008\n.long 0x480186E5\n.long 0x8001001C\n.long 0x7C0803A6\n.long 0xBBA1000C\n.long 0x38210018\n.long 0x4E800020");
}
