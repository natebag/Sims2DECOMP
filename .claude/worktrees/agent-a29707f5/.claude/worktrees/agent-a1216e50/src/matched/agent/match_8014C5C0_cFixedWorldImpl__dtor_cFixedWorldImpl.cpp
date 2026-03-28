// 0x8014C5C0 (112 bytes)
// cFixedWorldImpl::~cFixedWorldImpl(void)

class cFixedWorldImpl { public: void ~cFixedWorldImpl(void); };

__attribute__((naked))
void cFixedWorldImpl::~cFixedWorldImpl(void) {
    asm volatile(".long 0x9421FFF0\n.long 0x7C0802A6\n.long 0xBFC10008\n.long 0x90010014\n.long 0x3D208046\n.long 0x3D608046\n.long 0x7C7F1B78\n.long 0x39295368\n.long 0x396B5388\n.long 0x7C9E2378\n.long 0x913F0010\n.long 0x917F0000\n.long 0x480004D1\n.long 0x387F0004\n.long 0x38800000\n.long 0x4BF67C55\n.long 0x3D208046\n.long 0x73C00001\n.long 0x392954C8\n.long 0x913F0000\n.long 0x4182000C\n.long 0x7FE3FB78\n.long 0x48184C09\n.long 0x80010014\n.long 0x7C0803A6\n.long 0xBBC10008\n.long 0x38210010\n.long 0x4E800020");
}
