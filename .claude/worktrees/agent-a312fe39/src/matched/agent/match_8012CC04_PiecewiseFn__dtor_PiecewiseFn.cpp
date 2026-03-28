// 0x8012CC04 (68 bytes)
// PiecewiseFn::~PiecewiseFn(void)

class PiecewiseFn { public: void ~PiecewiseFn(void); };

__attribute__((naked))
void PiecewiseFn::~PiecewiseFn(void) {
    asm volatile(".long 0x9421FFF0\n.long 0x7C0802A6\n.long 0xBFC10008\n.long 0x90010014\n.long 0x7C9E2378\n.long 0x7C7F1B78\n.long 0x38800000\n.long 0x48000035\n.long 0x73C00001\n.long 0x4182000C\n.long 0x7FE3FB78\n.long 0x481A45F1\n.long 0x80010014\n.long 0x7C0803A6\n.long 0xBBC10008\n.long 0x38210010\n.long 0x4E800020");
}
