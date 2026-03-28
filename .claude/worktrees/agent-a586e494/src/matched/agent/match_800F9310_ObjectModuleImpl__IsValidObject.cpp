// 0x800F9310 (116 bytes)
// ObjectModuleImpl::IsValidObject(cXObject *)

class ObjectModuleImpl { public: void IsValidObject(cXObject *); };

__attribute__((naked))
void ObjectModuleImpl::IsValidObject(cXObject *) {
    asm volatile(".long 0x9421FFF0\n.long 0x7C0802A6\n.long 0x93E1000C\n.long 0x90010014\n.long 0x81230000\n.long 0x7C9F2378\n.long 0xA8090098\n.long 0x8129009C\n.long 0x7C630214\n.long 0x7D2803A6\n.long 0x48000028\n.long 0x7C0BF800\n.long 0x4082000C\n.long 0x38600001\n.long 0x48000028\n.long 0x812B0004\n.long 0xA8690490\n.long 0x80090494\n.long 0x7C6B1A14\n.long 0x7C0803A6\n.long 0x4E800021\n.long 0x7C6B1B79\n.long 0x4082FFD4\n.long 0x38600000\n.long 0x80010014\n.long 0x7C0803A6\n.long 0x83E1000C\n.long 0x38210010\n.long 0x4E800020");
}
