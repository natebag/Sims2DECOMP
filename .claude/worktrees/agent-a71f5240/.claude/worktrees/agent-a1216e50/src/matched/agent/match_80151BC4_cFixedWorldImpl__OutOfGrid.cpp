// 0x80151BC4 (108 bytes)
// cFixedWorldImpl::OutOfGrid(FTilePt &) const

class cFixedWorldImpl { public: void OutOfGrid(FTilePt &) const; };

__attribute__((naked))
void cFixedWorldImpl::OutOfGrid(FTilePt &) const {
    asm volatile(".long 0x9421FFE0\n.long 0x7C0802A6\n.long 0xBFA10014\n.long 0x90010024\n.long 0x7C7D1B78\n.long 0x38A00001\n.long 0x83DD0000\n.long 0x38610008\n.long 0xA81E0060\n.long 0x3BDE0060\n.long 0x7FBD0214\n.long 0x4BF62A0D\n.long 0x801E0004\n.long 0x38810008\n.long 0x7FA3EB78\n.long 0x7C0803A6\n.long 0x4E800021\n.long 0x7C7E1B78\n.long 0x38800002\n.long 0x38610008\n.long 0x4BF62B11\n.long 0x7FC3F378\n.long 0x80010024\n.long 0x7C0803A6\n.long 0xBBA10014\n.long 0x38210020\n.long 0x4E800020");
}
