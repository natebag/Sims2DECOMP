// 0x8012AD28 (112 bytes)
// cXPersonImpl::DeleteTopAction(void)

class cXPersonImpl { public: void DeleteTopAction(void); };

__attribute__((naked))
void cXPersonImpl::DeleteTopAction(void) {
    asm volatile(".long 0x9421FFF8\n.long 0x7C0802A6\n.long 0x9001000C\n.long 0x80030534\n.long 0x39600000\n.long 0x2C000000\n.long 0x41820008\n.long 0x39600001\n.long 0x39230130\n.long 0x808902A8\n.long 0x800902AC\n.long 0x7C040050\n.long 0x7C005840\n.long 0x4081002C\n.long 0x3C00CCCC\n.long 0x7C845A14\n.long 0x6000CCCD\n.long 0x7C040016\n.long 0x5400E8FE\n.long 0x1C00000A\n.long 0x7C802050\n.long 0x1C840044\n.long 0x7C892214\n.long 0x48000015\n.long 0x8001000C\n.long 0x7C0803A6\n.long 0x38210008\n.long 0x4E800020");
}
