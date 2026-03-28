/* ObjectFolderImpl::FindUniqueResourceName(unsigned int, unsigned int, StringBuffer &) at 0x800F1F6C (132B) */

struct ObjectFolderImpl { void FindUniqueResourceName(); };

__attribute__((naked))
void ObjectFolderImpl::FindUniqueResourceName() {
    asm volatile(
        ".long 0x9421FFF0\n"
        ".long 0x7C0802A6\n"
        ".long 0xBFC10008\n"
        ".long 0x90010014\n"
        ".long 0x7C6B1B78\n"
        ".long 0x7CBF2B78\n"
        ".long 0x7CDE3378\n"
        ".long 0x2C04FFFF\n"
        ".long 0x4182004C\n"
        ".long 0x812B0000\n"
        ".long 0xA8690038\n"
        ".long 0x8009003C\n"
        ".long 0x7C6B1A14\n"
        ".long 0x7C0803A6\n"
        ".long 0x4E800021\n"
        ".long 0x7C6B1B79\n"
        ".long 0x4182002C\n"
        ".long 0x812B000C\n"
        ".long 0x7FE4FB78\n"
        ".long 0x7FC5F378\n"
        ".long 0xA86900C8\n"
        ".long 0x800900CC\n"
        ".long 0x7C6B1A14\n"
        ".long 0x7C0803A6\n"
        ".long 0x4E800021\n"
        ".long 0x38600001\n"
        ".long 0x48000008\n"
        ".long 0x38600000\n"
        ".long 0x80010014\n"
        ".long 0x7C0803A6\n"
        ".long 0xBBC10008\n"
        ".long 0x38210010\n"
        ".long 0x4E800020\n"
    );
}
