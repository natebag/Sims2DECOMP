/* ObjectFolderImpl::GetSemiGlobalID(unsigned int) at 0x800EDD00 (148B) */

struct ObjectFolderImpl { void GetSemiGlobalID(); };

__attribute__((naked))
void ObjectFolderImpl::GetSemiGlobalID() {
    asm volatile(
        ".long 0x9421FFE8\n"
        ".long 0x7C0802A6\n"
        ".long 0x93E10014\n"
        ".long 0x9001001C\n"
        ".long 0x7C7F1B78\n"
        ".long 0x813F0000\n"
        ".long 0xA8690038\n"
        ".long 0x8009003C\n"
        ".long 0x7C7F1A14\n"
        ".long 0x7C0803A6\n"
        ".long 0x4E800021\n"
        ".long 0x7C631B79\n"
        ".long 0x41820020\n"
        ".long 0x80030008\n"
        ".long 0x7C040378\n"
        ".long 0x2C000000\n"
        ".long 0x41820010\n"
        ".long 0x80840034\n"
        ".long 0x2C040000\n"
        ".long 0x4082000C\n"
        ".long 0x3860FFFF\n"
        ".long 0x4800002C\n"
        ".long 0x807F0690\n"
        ".long 0x38A10008\n"
        ".long 0x4822E02D\n"
        ".long 0x2C030000\n"
        ".long 0x3800FFFF\n"
        ".long 0x41820008\n"
        ".long 0x80010008\n"
        ".long 0x7C030379\n"
        ".long 0x40820008\n"
        ".long 0x3860FFFF\n"
        ".long 0x8001001C\n"
        ".long 0x7C0803A6\n"
        ".long 0x83E10014\n"
        ".long 0x38210018\n"
        ".long 0x4E800020\n"
    );
}
