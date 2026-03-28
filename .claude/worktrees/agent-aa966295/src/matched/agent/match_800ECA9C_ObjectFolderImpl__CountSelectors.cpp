// 0x800ECA9C (72 bytes)
// ObjectFolderImpl::CountSelectors(void)

class ObjectFolderImpl { public: void CountSelectors(void); };

__attribute__((naked))
void ObjectFolderImpl::CountSelectors(void) {
    asm volatile(".long 0x39030040\n.long 0x39600000\n.long 0x38600000\n.long 0x5569103A\n.long 0x380B0001\n.long 0x7D28482E\n.long 0x39400000\n.long 0x2C090000\n.long 0x41820014\n.long 0x812900A4\n.long 0x394A0001\n.long 0x2C090000\n.long 0x4082FFF4\n.long 0x7C0B0378\n.long 0x7C635214\n.long 0x2C0B00FF\n.long 0x4081FFCC\n.long 0x4E800020");
}
