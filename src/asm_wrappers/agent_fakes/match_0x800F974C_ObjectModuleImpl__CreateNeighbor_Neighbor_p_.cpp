/* ObjectModuleImpl::CreateNeighbor(Neighbor *) at 0x800F974C (128B) */

struct ObjectModuleImpl { void CreateNeighbor(); };

__attribute__((naked))
void ObjectModuleImpl::CreateNeighbor() {
    asm volatile(
        ".long 0x9421FFF0\n"
        ".long 0x7C0802A6\n"
        ".long 0xBFC10008\n"
        ".long 0x90010014\n"
        ".long 0x7C7E1B78\n"
        ".long 0x8084000C\n"
        ".long 0x813E0000\n"
        ".long 0x38A00000\n"
        ".long 0x80090054\n"
        ".long 0xA8690050\n"
        ".long 0x7C0803A6\n"
        ".long 0x7C7E1A14\n"
        ".long 0x4E800021\n"
        ".long 0x813E0000\n"
        ".long 0x7C641B78\n"
        ".long 0xA8690090\n"
        ".long 0x80090094\n"
        ".long 0x7C7E1A14\n"
        ".long 0x7C0803A6\n"
        ".long 0x4E800021\n"
        ".long 0x7C631B79\n"
        ".long 0x41820014\n"
        ".long 0x80630000\n"
        ".long 0x38800002\n"
        ".long 0x4BFF93F9\n"
        ".long 0x48000008\n"
        ".long 0x38600000\n"
        ".long 0x80010014\n"
        ".long 0x7C0803A6\n"
        ".long 0xBBC10008\n"
        ".long 0x38210010\n"
        ".long 0x4E800020\n"
    );
}
