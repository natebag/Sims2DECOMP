// 0x8013FFB4 (116 bytes)
// ObjectModuleImpl::GetSimMemory(int, int, int)

class ObjectModuleImpl { public: void GetSimMemory(int, int, int); };

__attribute__((naked))
void ObjectModuleImpl::GetSimMemory(int, int, int) {
    asm volatile(".long 0x9421FFE8\n.long 0x7C0802A6\n.long 0xBFC10010\n.long 0x9001001C\n.long 0x7C832378\n.long 0x38000000\n.long 0x7CA42B78\n.long 0x7CDE3378\n.long 0x38A10008\n.long 0x9001000C\n.long 0x90010008\n.long 0x38C1000C\n.long 0x4BFFFD21\n.long 0x81610008\n.long 0x38A00002\n.long 0x8081000C\n.long 0x812B0000\n.long 0xA8690040\n.long 0x80090044\n.long 0x7C6B1A14\n.long 0x7C0803A6\n.long 0x4E800021\n.long 0x7FC4F378\n.long 0x4BFFFCB9\n.long 0x8001001C\n.long 0x7C0803A6\n.long 0xBBC10010\n.long 0x38210018\n.long 0x4E800020");
}
