// 0x800F9820 (64 bytes)
// ObjectModuleImpl::GetNumObjects(void)

class ObjectModuleImpl { public: void GetNumObjects(void); };

__attribute__((naked))
void ObjectModuleImpl::GetNumObjects(void) {
    asm volatile(".long 0x38000010\n.long 0x39600000\n.long 0x7C0903A6\n.long 0x392320A0\n.long 0x80090000\n.long 0x39290004\n.long 0x2C000000\n.long 0x41820008\n.long 0x396B0001\n.long 0x4200FFEC\n.long 0x80032090\n.long 0x80632094\n.long 0x7C601850\n.long 0x7C631670\n.long 0x7C635A14\n.long 0x4E800020");
}
