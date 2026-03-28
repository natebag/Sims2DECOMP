// 0x80145188 (84 bytes)
// IFFSlotDescList::IFFSlotDescList(void)

class IFFSlotDescList { public: void IFFSlotDescList(void); };

__attribute__((naked))
void IFFSlotDescList::IFFSlotDescList(void) {
    asm volatile(".long 0x9421FFE8\n.long 0x7C0802A6\n.long 0xBFC10010\n.long 0x9001001C\n.long 0x7C7E1B78\n.long 0x4BFFF45D\n.long 0x3D208046\n.long 0x38000000\n.long 0x39294A50\n.long 0x901E0054\n.long 0x913E0000\n.long 0x397E005C\n.long 0x901E0058\n.long 0x7FC3F378\n.long 0x900B0004\n.long 0x901E0064\n.long 0x8001001C\n.long 0x7C0803A6\n.long 0xBBC10010\n.long 0x38210018\n.long 0x4E800020");
}
