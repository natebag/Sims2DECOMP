/* NghResFile::GetDefaultNghPath(char *, StackString<260> &) at 0x800D8954 (140B) */

struct NghResFile { void GetDefaultNghPath(); };

__attribute__((naked))
void NghResFile::GetDefaultNghPath() {
    asm volatile(
        ".long 0x9421FED0\n"
        ".long 0x7C0802A6\n"
        ".long 0xBF61011C\n"
        ".long 0x90010134\n"
        ".long 0x816D9738\n"
        ".long 0x3BC10008\n"
        ".long 0x7CBC2B78\n"
        ".long 0x7C9B2378\n"
        ".long 0x812B0338\n"
        ".long 0xA8690030\n"
        ".long 0x80090034\n"
        ".long 0x7C6B1A14\n"
        ".long 0x7C0803A6\n"
        ".long 0x4E800021\n"
        ".long 0x7C7D1B78\n"
        ".long 0x389E0008\n"
        ".long 0x38A00104\n"
        ".long 0x7FC3F378\n"
        ".long 0x4BFCDC11\n"
        ".long 0x38A0FFFF\n"
        ".long 0x7FA4EB78\n"
        ".long 0x7FC3F378\n"
        ".long 0x4BFCDC75\n"
        ".long 0x7FC4F378\n"
        ".long 0x7F83E378\n"
        ".long 0x4BFCDDB1\n"
        ".long 0x7F83E378\n"
        ".long 0x7F64DB78\n"
        ".long 0x38A0FFFF\n"
        ".long 0x4BFCDC59\n"
        ".long 0x80010134\n"
        ".long 0x7C0803A6\n"
        ".long 0xBB61011C\n"
        ".long 0x38210130\n"
        ".long 0x4E800020\n"
    );
}
