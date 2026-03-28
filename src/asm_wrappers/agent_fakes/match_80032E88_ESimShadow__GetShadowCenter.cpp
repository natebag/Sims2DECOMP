// 0x80032E88 (112 bytes)
// ESimShadow::GetShadowCenter(EVec3 &) const

class ESimShadow { public: void GetShadowCenter(EVec3 &) const; };

__attribute__((naked))
void ESimShadow::GetShadowCenter(EVec3 &) const {
    asm volatile(".long 0x9421FFF0\n.long 0x7C0802A6\n.long 0xBFC10008\n.long 0x90010014\n.long 0x81630320\n.long 0x7C9E2378\n.long 0x812B0004\n.long 0x8009018C\n.long 0xA8690188\n.long 0x7C0803A6\n.long 0x7C6B1A14\n.long 0x4E800021\n.long 0x81230000\n.long 0x38800002\n.long 0x7FC5F378\n.long 0xA80900E0\n.long 0x812900E4\n.long 0x7C630214\n.long 0x7D2803A6\n.long 0x4E800021\n.long 0x3D20803D\n.long 0xC0091190\n.long 0xD01E0008\n.long 0x80010014\n.long 0x7C0803A6\n.long 0xBBC10008\n.long 0x38210010\n.long 0x4E800020");
}
