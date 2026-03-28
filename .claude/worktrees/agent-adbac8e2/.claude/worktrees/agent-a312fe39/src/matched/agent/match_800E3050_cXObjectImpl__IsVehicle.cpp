// 0x800E3050 (68 bytes)
// cXObjectImpl::IsVehicle(void)

class cXObjectImpl { public: void IsVehicle(void); };

__attribute__((naked))
void cXObjectImpl::IsVehicle(void) {
    asm volatile(".long 0x9421FFF8\n.long 0x7C0802A6\n.long 0x9001000C\n.long 0x80630004\n.long 0x81230004\n.long 0xA8090318\n.long 0x8129031C\n.long 0x7C630214\n.long 0x7D2803A6\n.long 0x4E800021\n.long 0x6863000C\n.long 0x20030000\n.long 0x7C601914\n.long 0x8001000C\n.long 0x7C0803A6\n.long 0x38210008\n.long 0x4E800020");
}
