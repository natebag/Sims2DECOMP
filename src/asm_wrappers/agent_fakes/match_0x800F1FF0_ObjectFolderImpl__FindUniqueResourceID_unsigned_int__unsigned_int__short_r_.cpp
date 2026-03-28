/* ObjectFolderImpl::FindUniqueResourceID(unsigned int, unsigned int, short &) at 0x800F1FF0 (132B) */

struct ObjectFolderImpl { void FindUniqueResourceID(); };

__attribute__((naked))
void ObjectFolderImpl::FindUniqueResourceID() {
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
        ".long 0xA86900D0\n"
        ".long 0x800900D4\n"
        ".long 0x7C6B1A14\n"
        ".long 0x7C0803A6\n"
        ".long 0x4E800021\n"
        ".long 0xB07E0000\n"
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
