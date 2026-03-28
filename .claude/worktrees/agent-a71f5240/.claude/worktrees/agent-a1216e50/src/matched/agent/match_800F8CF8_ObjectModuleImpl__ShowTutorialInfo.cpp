// 0x800F8CF8 (76 bytes)
// ObjectModuleImpl::ShowTutorialInfo(void)

class ObjectModuleImpl { public: void ShowTutorialInfo(void); };

__attribute__((naked))
void ObjectModuleImpl::ShowTutorialInfo(void) {
    asm volatile(".long 0x9421FFF8\n.long 0x7C0802A6\n.long 0x9001000C\n.long 0x81232088\n.long 0x2C090000\n.long 0x41820028\n.long 0x81690004\n.long 0x3C80803E\n.long 0x3884BB88\n.long 0x812B0004\n.long 0xA86900F8\n.long 0x800900FC\n.long 0x7C6B1A14\n.long 0x7C0803A6\n.long 0x4E800021\n.long 0x8001000C\n.long 0x7C0803A6\n.long 0x38210008\n.long 0x4E800020");
}
