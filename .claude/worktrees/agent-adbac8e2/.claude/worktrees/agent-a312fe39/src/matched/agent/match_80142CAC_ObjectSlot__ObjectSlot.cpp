// 0x80142CAC (124 bytes)
// ObjectSlot::ObjectSlot(SlotDescriptor *)

class ObjectSlot { public: void ObjectSlot(SlotDescriptor *); };

__attribute__((naked))
void ObjectSlot::ObjectSlot(SlotDescriptor *) {
    asm volatile(".long 0x9421FFE8\n.long 0x7C0802A6\n.long 0xBFA1000C\n.long 0x9001001C\n.long 0x7C7E1B78\n.long 0x7C9D2378\n.long 0x4BFFFCB9\n.long 0x3D208046\n.long 0x38000000\n.long 0x39294A10\n.long 0x7FC3F378\n.long 0x913E0000\n.long 0xC01D0004\n.long 0xD01E0014\n.long 0xC1BD0008\n.long 0xD1BE0018\n.long 0xC01D000C\n.long 0xB01E0004\n.long 0xD01E001C\n.long 0x801D0010\n.long 0x901E000C\n.long 0x813D0014\n.long 0x913E0010\n.long 0x809D0018\n.long 0x48000059\n.long 0x7FC3F378\n.long 0x8001001C\n.long 0x7C0803A6\n.long 0xBBA1000C\n.long 0x38210018\n.long 0x4E800020");
}
