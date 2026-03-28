/* ObjectModuleImpl::PostLoad(iResFile *, int, bool) at 0x800F39DC (128B) */

struct ObjectModuleImpl { void PostLoad(); };

__attribute__((naked))
void ObjectModuleImpl::PostLoad() {
    asm volatile(
        ".long 0x9421FFE0\n"
        ".long 0x7C0802A6\n"
        ".long 0xBF61000C\n"
        ".long 0x90010024\n"
        ".long 0x7C7E1B78\n"
        ".long 0x7C9B2378\n"
        ".long 0x83FE002C\n"
        ".long 0x7CBC2B78\n"
        ".long 0x7CDD3378\n"
        ".long 0x2C1F0000\n"
        ".long 0x41820030\n"
        ".long 0x813F00EC\n"
        ".long 0x7F84E378\n"
        ".long 0x7FA5EB78\n"
        ".long 0xA8690030\n"
        ".long 0x80090034\n"
        ".long 0x7C7F1A14\n"
        ".long 0x7C0803A6\n"
        ".long 0x4E800021\n"
        ".long 0x83FF005C\n"
        ".long 0x2C1F0000\n"
        ".long 0x4082FFD8\n"
        ".long 0x7FC3F378\n"
        ".long 0x7F64DB78\n"
        ".long 0x4BFFFCA9\n"
        ".long 0x7FC3F378\n"
        ".long 0x48001E39\n"
        ".long 0x80010024\n"
        ".long 0x7C0803A6\n"
        ".long 0xBB61000C\n"
        ".long 0x38210020\n"
        ".long 0x4E800020\n"
    );
}
