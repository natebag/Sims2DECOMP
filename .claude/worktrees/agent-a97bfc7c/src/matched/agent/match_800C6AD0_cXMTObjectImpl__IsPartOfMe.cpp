// 0x800C6AD0 (64 bytes)
// cXMTObjectImpl::IsPartOfMe(cXObject *)

class cXMTObjectImpl { public: void IsPartOfMe(cXObject *); };

__attribute__((naked))
void cXMTObjectImpl::IsPartOfMe(cXObject *) {
    asm volatile(".long 0x8003000C\n.long 0x2C000000\n.long 0x41820028\n.long 0x7C030378\n.long 0x48000020\n.long 0x81230004\n.long 0x80090000\n.long 0x7C002000\n.long 0x4082000C\n.long 0x38600001\n.long 0x4E800020\n.long 0x80630008\n.long 0x2C030000\n.long 0x4082FFE0\n.long 0x38600000\n.long 0x4E800020");
}
