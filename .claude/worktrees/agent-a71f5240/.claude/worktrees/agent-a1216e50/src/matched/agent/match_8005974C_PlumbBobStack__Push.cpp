// 0x8005974C (76 bytes)
// PlumbBobStack::Push(PlumbBob *)

class PlumbBobStack { public: void Push(PlumbBob *); };

__attribute__((naked))
void PlumbBobStack::Push(PlumbBob *) {
    asm volatile(".long 0x81230000\n.long 0x2C090003\n.long 0x4D810020\n.long 0x55292036\n.long 0x8144016C\n.long 0x39290004\n.long 0x38E40128\n.long 0x7D634A14\n.long 0x914B000C\n.long 0x80040128\n.long 0x81470008\n.long 0x81070004\n.long 0x7C03492E\n.long 0x914B0008\n.long 0x910B0004\n.long 0x81230000\n.long 0x39290001\n.long 0x91230000\n.long 0x4E800020");
}
