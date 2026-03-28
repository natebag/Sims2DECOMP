// 0x8015BE68 (116 bytes)
// ObjectDataObjDefinition::~ObjectDataObjDefinition(void)

class ObjectDataObjDefinition { public: void ~ObjectDataObjDefinition(void); };

__attribute__((naked))
void ObjectDataObjDefinition::~ObjectDataObjDefinition(void) {
    asm volatile(".long 0x9421FFF0\n.long 0x7C0802A6\n.long 0xBFC10008\n.long 0x90010014\n.long 0x3D208046\n.long 0x7C7F1B78\n.long 0x39295938\n.long 0x7C9E2378\n.long 0x913F0000\n.long 0x4800005D\n.long 0x807F0004\n.long 0x801F0010\n.long 0x2C030000\n.long 0x7C830050\n.long 0x41820018\n.long 0x28040080\n.long 0x4081000C\n.long 0x48175375\n.long 0x48000008\n.long 0x4823FFAD\n.long 0x73C00001\n.long 0x4182000C\n.long 0x7FE3FB78\n.long 0x4817535D\n.long 0x80010014\n.long 0x7C0803A6\n.long 0xBBC10008\n.long 0x38210010\n.long 0x4E800020");
}
