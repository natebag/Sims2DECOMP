// 0x801B8F40 (76 bytes)
// H2DTarget::IsActionQueueAvailable(int) const

class H2DTarget { public: void IsActionQueueAvailable(int) const; };

__attribute__((naked))
void H2DTarget::IsActionQueueAvailable(int) const {
    asm volatile(".long 0x9421FFF8\n.long 0x7C0802A6\n.long 0x9001000C\n.long 0x28040001\n.long 0x4081000C\n.long 0x38600000\n.long 0x48000024\n.long 0x392300B4\n.long 0x5480103A\n.long 0x7D29002E\n.long 0x38600000\n.long 0x2C090000\n.long 0x4182000C\n.long 0x7D234B78\n.long 0x4BFE9BBD\n.long 0x8001000C\n.long 0x7C0803A6\n.long 0x38210008\n.long 0x4E800020");
}
