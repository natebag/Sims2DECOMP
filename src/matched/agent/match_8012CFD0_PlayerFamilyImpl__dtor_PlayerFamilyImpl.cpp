// 0x8012CFD0 (104 bytes)
// PlayerFamilyImpl::~PlayerFamilyImpl(void)

class PlayerFamilyImpl { public: void ~PlayerFamilyImpl(void); };

__attribute__((naked))
void PlayerFamilyImpl::~PlayerFamilyImpl(void) {
    asm volatile(".long 0x9421FFE8\n.long 0x7C0802A6\n.long 0xBFA1000C\n.long 0x9001001C\n.long 0x3D208046\n.long 0x7C7E1B78\n.long 0x39293248\n.long 0x7C9D2378\n.long 0x913E0000\n.long 0x387E0CDC\n.long 0x38800002\n.long 0x4BF8B479\n.long 0x387E00C8\n.long 0x38800002\n.long 0x48031AB1\n.long 0x387E0038\n.long 0x38800002\n.long 0x4BF1D329\n.long 0x7FC3F378\n.long 0x7FA4EB78\n.long 0x4BF89049\n.long 0x8001001C\n.long 0x7C0803A6\n.long 0xBBA1000C\n.long 0x38210018\n.long 0x4E800020");
}
