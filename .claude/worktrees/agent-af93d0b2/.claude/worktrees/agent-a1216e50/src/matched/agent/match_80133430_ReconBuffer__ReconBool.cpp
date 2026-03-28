// 0x80133430 (84 bytes)
// ReconBuffer::ReconBool(bool *)

class ReconBuffer { public: void ReconBool(bool *); };

__attribute__((naked))
void ReconBuffer::ReconBool(bool *) {
    asm volatile(".long 0x9421FFE8\n.long 0x7C0802A6\n.long 0x93E10014\n.long 0x9001001C\n.long 0x7C9F2378\n.long 0x38A00001\n.long 0x801F0000\n.long 0x38810008\n.long 0x98010008\n.long 0x4BFFFE7D\n.long 0x88010008\n.long 0x39200001\n.long 0x2C000000\n.long 0x40820008\n.long 0x39200000\n.long 0x913F0000\n.long 0x8001001C\n.long 0x7C0803A6\n.long 0x83E10014\n.long 0x38210018\n.long 0x4E800020");
}
