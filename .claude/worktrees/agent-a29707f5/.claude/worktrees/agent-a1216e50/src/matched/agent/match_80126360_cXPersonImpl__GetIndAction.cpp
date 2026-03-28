// 0x80126360 (104 bytes)
// cXPersonImpl::GetIndAction(int, bool)

class cXPersonImpl { public: void GetIndAction(int, bool); };

__attribute__((naked))
void cXPersonImpl::GetIndAction(int, bool) {
    asm volatile(".long 0x2C050000\n.long 0x40820014\n.long 0x80030534\n.long 0x2C000000\n.long 0x41820008\n.long 0x38840001\n.long 0x2C040000\n.long 0x4180001C\n.long 0x39230130\n.long 0x806902A8\n.long 0x800902AC\n.long 0x7C030050\n.long 0x7C040040\n.long 0x4180000C\n.long 0x38600000\n.long 0x4E800020\n.long 0x3C00CCCC\n.long 0x7C632214\n.long 0x6000CCCD\n.long 0x7C030016\n.long 0x5400E8FE\n.long 0x1C00000A\n.long 0x7C601850\n.long 0x1C630044\n.long 0x7C691A14\n.long 0x4E800020");
}
