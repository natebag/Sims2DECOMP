/* cXObjectImpl::GetRootObject(FTilePt &, int) at 0x800DCA2C (160B) */

struct cXObjectImpl { void GetRootObject(); };

__attribute__((naked))
void cXObjectImpl::GetRootObject() {
    asm volatile(
        ".long 0x9421FFE8\n"
        ".long 0x7C0802A6\n"
        ".long 0xBFC10010\n"
        ".long 0x9001001C\n"
        ".long 0x7C7E1B78\n"
        ".long 0x38610008\n"
        ".long 0x4BFD7BB9\n"
        ".long 0x806DAC14\n"
        ".long 0x38810008\n"
        ".long 0x81230000\n"
        ".long 0xA8090250\n"
        ".long 0x81290254\n"
        ".long 0x7C630214\n"
        ".long 0x7D2803A6\n"
        ".long 0x4E800021\n"
        ".long 0x7C631B79\n"
        ".long 0x4182003C\n"
        ".long 0x817E0004\n"
        ".long 0x7C641B78\n"
        ".long 0x812B0004\n"
        ".long 0xA8690488\n"
        ".long 0x8009048C\n"
        ".long 0x7C6B1A14\n"
        ".long 0x7C0803A6\n"
        ".long 0x4E800021\n"
        ".long 0x7C7E1B78\n"
        ".long 0x38800002\n"
        ".long 0x38610008\n"
        ".long 0x4BFD7C89\n"
        ".long 0x7FC3F378\n"
        ".long 0x48000014\n"
        ".long 0x38610008\n"
        ".long 0x38800002\n"
        ".long 0x4BFD7C75\n"
        ".long 0x38600000\n"
        ".long 0x8001001C\n"
        ".long 0x7C0803A6\n"
        ".long 0xBBC10010\n"
        ".long 0x38210018\n"
        ".long 0x4E800020\n"
    );
}
