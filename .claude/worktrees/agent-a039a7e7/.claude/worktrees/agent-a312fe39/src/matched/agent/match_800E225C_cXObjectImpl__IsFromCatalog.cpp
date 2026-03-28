// 0x800E225C (108 bytes)
// cXObjectImpl::IsFromCatalog(void)

class cXObjectImpl { public: void IsFromCatalog(void); };

__attribute__((naked))
void cXObjectImpl::IsFromCatalog(void) {
    asm volatile(".long 0x9421FFF8\n.long 0x7C0802A6\n.long 0x9001000C\n.long 0x81630004\n.long 0x812B0004\n.long 0x80090314\n.long 0xA8690310\n.long 0x7C0803A6\n.long 0x7C6B1A14\n.long 0x4E800021\n.long 0xA803004E\n.long 0x2C000000\n.long 0x40820010\n.long 0xA8030050\n.long 0x2C000000\n.long 0x4182000C\n.long 0x38600001\n.long 0x48000018\n.long 0xA803008A\n.long 0x38600001\n.long 0x2C000000\n.long 0x40820008\n.long 0x38600000\n.long 0x8001000C\n.long 0x7C0803A6\n.long 0x38210008\n.long 0x4E800020");
}
