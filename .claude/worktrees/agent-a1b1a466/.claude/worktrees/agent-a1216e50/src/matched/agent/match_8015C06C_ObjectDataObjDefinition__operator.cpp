// 0x8015C06C (124 bytes)
// ObjectDataObjDefinition::operator=(ObjDefinition &)

class ObjectDataObjDefinition { public: void operator=(ObjDefinition &); };

__attribute__((naked))
void ObjectDataObjDefinition::operator=(ObjDefinition &) {
    asm volatile(".long 0x9421FF98\n.long 0x7C0802A6\n.long 0xBF610054\n.long 0x9001006C\n.long 0x7C7C1B78\n.long 0x3BA10008\n.long 0x7C9B2378\n.long 0x4BFFFE61\n.long 0x937C001C\n.long 0x3FC0803E\n.long 0x3BDEE030\n.long 0x389D0008\n.long 0x38A00040\n.long 0x7FA3EB78\n.long 0x4BF4A509\n.long 0x38A0FFFF\n.long 0x7FC4F378\n.long 0x7FA3EB78\n.long 0x4BF4A56D\n.long 0x7FA4EB78\n.long 0x7F83E378\n.long 0x48000729\n.long 0xA89B00BC\n.long 0x7F83E378\n.long 0x48000961\n.long 0x7F83E378\n.long 0x8001006C\n.long 0x7C0803A6\n.long 0xBB610054\n.long 0x38210068\n.long 0x4E800020");
}
