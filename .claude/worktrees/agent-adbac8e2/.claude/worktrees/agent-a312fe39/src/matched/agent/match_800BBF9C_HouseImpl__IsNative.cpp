// 0x800BBF9C (112 bytes)
// HouseImpl::IsNative(cXPerson *)

class HouseImpl { public: void IsNative(cXPerson *); };

__attribute__((naked))
void HouseImpl::IsNative(cXPerson *) {
    asm volatile(".long 0x9421FFF0\n.long 0x7C0802A6\n.long 0xBFC10008\n.long 0x90010014\n.long 0x816DAC50\n.long 0x7C9E2378\n.long 0x812B0000\n.long 0x8009003C\n.long 0xA8690038\n.long 0x7C0803A6\n.long 0x7C6B1A14\n.long 0x4E800021\n.long 0x81230000\n.long 0x7FC4F378\n.long 0xA8090050\n.long 0x81290054\n.long 0x7C630214\n.long 0x7D2803A6\n.long 0x4E800021\n.long 0x2C030000\n.long 0x38600001\n.long 0x40820008\n.long 0x38600000\n.long 0x80010014\n.long 0x7C0803A6\n.long 0xBBC10008\n.long 0x38210010\n.long 0x4E800020");
}
