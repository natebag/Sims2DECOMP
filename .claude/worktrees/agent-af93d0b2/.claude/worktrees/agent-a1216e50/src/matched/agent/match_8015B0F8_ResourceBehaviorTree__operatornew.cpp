// 0x8015B0F8 (108 bytes)
// ResourceBehaviorTree::operator new(unsigned int)

class ResourceBehaviorTree { public: void operator new(unsigned int); };

__attribute__((naked))
void ResourceBehaviorTree::operator new(unsigned int) {
    asm volatile(".long 0x9421FFF0\n.long 0x7C0802A6\n.long 0x93E1000C\n.long 0x90010014\n.long 0x7C7F1B78\n.long 0x2C1F0068\n.long 0x40820030\n.long 0x3D208048\n.long 0x396974C0\n.long 0x806B0004\n.long 0x2C030000\n.long 0x4182001C\n.long 0x81230004\n.long 0x3C004445\n.long 0x60005355\n.long 0x912B0004\n.long 0x90030000\n.long 0x40820014\n.long 0x48174DC1\n.long 0x7FE4FB78\n.long 0x38A00000\n.long 0x48175959\n.long 0x80010014\n.long 0x7C0803A6\n.long 0x83E1000C\n.long 0x38210010\n.long 0x4E800020");
}
