/* cXObjectImpl::CanIntersectPeople(void) at 0x800EB6C4 (148B) */

struct cXObjectImpl { int CanIntersectPeople(); };

__attribute__((naked))
int cXObjectImpl::CanIntersectPeople() {
    asm volatile(
        "stwu 1, -16(1)\n"
        "mflr 0\n"
        "stw 31, 12(1)\n"
        "stw 0, 20(1)\n"
        "mr 31, 3\n"
        "lwz 3, 4(31)\n"
        "lwz 9, 4(3)\n"
        ".long 0xA8090470\n"
        "lwz 9, 1140(9)\n"
        ".long 0x7C630214\n"
        "mtlr 9\n"
        "blrl\n"
        ".long 0x2C030000\n"
        ".long 0x40820028\n"
        "lwz 3, 4(31)\n"
        "lwz 9, 4(3)\n"
        ".long 0xA8090398\n"
        "lwz 9, 924(9)\n"
        ".long 0x7C630214\n"
        "mtlr 9\n"
        "blrl\n"
        ".long 0x5463E7FE\n"
        ".long 0x48000028\n"
        "lwz 11, 4(31)\n"
        "lwz 9, 4(11)\n"
        ".long 0xA8690398\n"
        "lwz 0, 924(9)\n"
        ".long 0x7C6B1A14\n"
        "mtlr 0\n"
        "blrl\n"
        ".long 0x68630002\n"
        ".long 0x5463FFFE\n"
        "lwz 0, 20(1)\n"
        "mtlr 0\n"
        "lwz 31, 12(1)\n"
        "addi 1, 1, 16\n"
        "blr\n"
    );
}
