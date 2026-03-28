/* cXObjectImpl::IsPortal(void) at 0x800EAD18 (128B) */

struct cXObjectImpl { int IsPortal(); };

__attribute__((naked))
int cXObjectImpl::IsPortal() {
    asm volatile(
        "stwu 1, -16(1)\n"
        "mflr 0\n"
        "stmw 30, 8(1)\n"
        "stw 0, 20(1)\n"
        "mr 31, 3\n"
        "li 30, 0\n"
        "lwz 3, 4(31)\n"
        "lwz 9, 4(3)\n"
        ".long 0xA8090318\n"
        "lwz 9, 796(9)\n"
        ".long 0x7C630214\n"
        "mtlr 9\n"
        "blrl\n"
        ".long 0x2C030008\n"
        ".long 0x40820030\n"
        ".long 0x2C1F0000\n"
        ".long 0x41820018\n"
        "lwz 9, 4(31)\n"
        "li 4, 6\n"
        "lwz 3, 0(9)\n"
        ".long 0x48007E3D\n"
        ".long 0x48000008\n"
        "li 3, 0\n"
        ".long 0x2C030000\n"
        ".long 0x41820008\n"
        "li 30, 1\n"
        "mr 3, 30\n"
        "lwz 0, 20(1)\n"
        "mtlr 0\n"
        "lmw 30, 8(1)\n"
        "addi 1, 1, 16\n"
        "blr\n"
    );
}
