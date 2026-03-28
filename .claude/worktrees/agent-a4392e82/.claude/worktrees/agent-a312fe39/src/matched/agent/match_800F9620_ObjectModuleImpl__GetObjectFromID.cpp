// 0x800F9620 (72 bytes)
// ObjectModuleImpl::GetObjectFromID(int)

class ObjectModuleImpl { public: void GetObjectFromID(int); };

__attribute__((naked))
void ObjectModuleImpl::GetObjectFromID(int) {
    asm volatile(".long 0x7C842379\n.long 0x4081001C\n.long 0x81632090\n.long 0x80032094\n.long 0x7C0B0050\n.long 0x7C001670\n.long 0x7C040000\n.long 0x4081000C\n.long 0x38600000\n.long 0x4E800020\n.long 0x3924FFFF\n.long 0x38600000\n.long 0x5529103A\n.long 0x7C8B482E\n.long 0x2C040000\n.long 0x4D820020\n.long 0x80640004\n.long 0x4E800020");
}
