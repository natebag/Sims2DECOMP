// 0x8011A984 (92 bytes)
// MotiveInc::DoStream(ReconBuffer *, int)

class MotiveInc { public: void DoStream(ReconBuffer *, int); };

__attribute__((naked))
void MotiveInc::DoStream(ReconBuffer *, int) {
    asm volatile(".long 0x9421FFE8\n.long 0x7C0802A6\n.long 0xBFA1000C\n.long 0x9001001C\n.long 0x7C7D1B78\n.long 0x7C9E2378\n.long 0x7FC3F378\n.long 0x7FA4EB78\n.long 0x38A00001\n.long 0x48018C6D\n.long 0x7FC3F378\n.long 0x389D0004\n.long 0x38A00001\n.long 0x48018E29\n.long 0x7FC3F378\n.long 0x389D0008\n.long 0x38A00001\n.long 0x48018E19\n.long 0x8001001C\n.long 0x7C0803A6\n.long 0xBBA1000C\n.long 0x38210018\n.long 0x4E800020");
}
