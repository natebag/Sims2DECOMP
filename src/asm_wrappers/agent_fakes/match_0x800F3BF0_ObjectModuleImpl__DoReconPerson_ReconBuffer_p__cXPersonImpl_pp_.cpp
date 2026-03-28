/* ObjectModuleImpl::DoReconPerson(ReconBuffer *, cXPersonImpl **) at 0x800F3BF0 (160B) */

struct ObjectModuleImpl { void DoReconPerson(); };

__attribute__((naked))
void ObjectModuleImpl::DoReconPerson() {
    asm volatile(
        ".long 0x9421FFE8\n"
        ".long 0x7C0802A6\n"
        ".long 0xBFC10010\n"
        ".long 0x9001001C\n"
        ".long 0x7CBF2B78\n"
        ".long 0x7C6B1B78\n"
        ".long 0x813F0000\n"
        ".long 0x7C9E2378\n"
        ".long 0x2C090000\n"
        ".long 0x41820010\n"
        ".long 0x80090000\n"
        ".long 0x90010008\n"
        ".long 0x48000008\n"
        ".long 0x91210008\n"
        ".long 0x812B0000\n"
        ".long 0x7FC4F378\n"
        ".long 0x38A10008\n"
        ".long 0x800901DC\n"
        ".long 0xA86901D8\n"
        ".long 0x7C0803A6\n"
        ".long 0x7C6B1A14\n"
        ".long 0x4E800021\n"
        ".long 0x801E000C\n"
        ".long 0x2C000000\n"
        ".long 0x4082002C\n"
        ".long 0x81210008\n"
        ".long 0x2C090000\n"
        ".long 0x4182001C\n"
        ".long 0x81290004\n"
        ".long 0x38800007\n"
        ".long 0x80690000\n"
        ".long 0x4BFFEF39\n"
        ".long 0x907F0000\n"
        ".long 0x48000008\n"
        ".long 0x913F0000\n"
        ".long 0x8001001C\n"
        ".long 0x7C0803A6\n"
        ".long 0xBBC10010\n"
        ".long 0x38210018\n"
        ".long 0x4E800020\n"
    );
}
