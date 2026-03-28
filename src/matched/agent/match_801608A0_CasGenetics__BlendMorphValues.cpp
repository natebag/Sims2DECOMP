// 0x801608A0 (96 bytes)
// CasGenetics::BlendMorphValues(float, float)

class CasGenetics { public: void BlendMorphValues(float, float); };

__attribute__((naked))
void CasGenetics::BlendMorphValues(float, float) {
    asm volatile(".long 0x9421FFE0\n.long 0x7C0802A6\n.long 0xDBC10010\n.long 0xDBE10018\n.long 0xBFC10008\n.long 0x90010024\n.long 0xFFE00890\n.long 0x3BC00064\n.long 0xFFC01090\n.long 0x4BF45C35\n.long 0x7FC3F396\n.long 0xFC20F890\n.long 0x1FDE0064\n.long 0x7C7E1850\n.long 0x2C030031\n.long 0x40810008\n.long 0xFC20F090\n.long 0x80010024\n.long 0x7C0803A6\n.long 0xBBC10008\n.long 0xCBC10010\n.long 0xCBE10018\n.long 0x38210020\n.long 0x4E800020");
}
