// 0x80142AD8 (124 bytes)
// RoutingSlot::WriteSlot(SlotDescriptor *)

class RoutingSlot { public: void WriteSlot(SlotDescriptor *); };

__attribute__((naked))
void RoutingSlot::WriteSlot(SlotDescriptor *) {
    asm volatile(".long 0x38000003\n.long 0xB0040000\n.long 0x8003001C\n.long 0x90040028\n.long 0x81230010\n.long 0x9124001C\n.long 0x80030014\n.long 0x90040020\n.long 0x81230018\n.long 0x91240024\n.long 0x80030020\n.long 0x9004002C\n.long 0x81230024\n.long 0x91240030\n.long 0x80030028\n.long 0x90040034\n.long 0x8123002C\n.long 0x91240038\n.long 0xC0030030\n.long 0xD004003C\n.long 0x80030034\n.long 0x90040040\n.long 0x81230038\n.long 0x91240044\n.long 0xC0030004\n.long 0xD0040004\n.long 0xC1A30008\n.long 0xD1A40008\n.long 0xC003000C\n.long 0xD004000C\n.long 0x4E800020");
}
