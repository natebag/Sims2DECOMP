// 0x800F97CC (84 bytes)
// ObjectModuleImpl::GetObject(int)

class ObjectModuleImpl { public: void GetObject(int); };

__attribute__((naked))
void ObjectModuleImpl::GetObject(int) {
    asm volatile(".long 0x3804C000\n.long 0x2800000F\n.long 0x41810028\n.long 0x5400103A\n.long 0x392320A0\n.long 0x7C69002E\n.long 0x38000000\n.long 0x2C030000\n.long 0x41820008\n.long 0x80030004\n.long 0x7C030378\n.long 0x4E800020\n.long 0x81632090\n.long 0x5489103A\n.long 0x38000000\n.long 0x7C6B482E\n.long 0x2C030000\n.long 0x41820008\n.long 0x80030004\n.long 0x7C030378\n.long 0x4E800020");
}
