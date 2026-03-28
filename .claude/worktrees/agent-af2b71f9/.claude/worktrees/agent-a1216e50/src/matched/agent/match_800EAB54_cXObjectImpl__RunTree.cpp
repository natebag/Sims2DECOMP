// 0x800EAB54 (112 bytes)
// cXObjectImpl::RunTree(char *)

class cXObjectImpl { public: void RunTree(char *); };

__attribute__((naked))
void cXObjectImpl::RunTree(char *) {
    asm volatile(".long 0x9421FFE8\n.long 0x7C0802A6\n.long 0xBF810008\n.long 0x9001001C\n.long 0x83C30004\n.long 0x7C9C2378\n.long 0x813E0004\n.long 0xA8690378\n.long 0x3BA900F0\n.long 0x8169037C\n.long 0x7C7E1A14\n.long 0xA80900F0\n.long 0x7D6803A6\n.long 0x7FDE0214\n.long 0x4E800021\n.long 0x801D0004\n.long 0x7C641B78\n.long 0x7FC3F378\n.long 0x7F86E378\n.long 0x38A00000\n.long 0x38E00000\n.long 0x7C0803A6\n.long 0x4E800021\n.long 0x8001001C\n.long 0x7C0803A6\n.long 0xBB810008\n.long 0x38210018\n.long 0x4E800020");
}
