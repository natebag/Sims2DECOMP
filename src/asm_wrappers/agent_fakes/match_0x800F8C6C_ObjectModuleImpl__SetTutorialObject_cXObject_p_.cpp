/* ObjectModuleImpl::SetTutorialObject(cXObject *) at 0x800F8C6C (140B) */

struct ObjectModuleImpl { void SetTutorialObject(); };

__attribute__((naked))
void ObjectModuleImpl::SetTutorialObject() {
    asm volatile(
        ".long 0x9421FFF0\n"
        ".long 0x7C0802A6\n"
        ".long 0x93E1000C\n"
        ".long 0x90010014\n"
        ".long 0x7C7F1B78\n"
        ".long 0x7C842379\n"
        ".long 0x41820020\n"
        ".long 0x81240004\n"
        ".long 0xA8690520\n"
        ".long 0x80090524\n"
        ".long 0x7C641A14\n"
        ".long 0x7C0803A6\n"
        ".long 0x4E800021\n"
        ".long 0x48000008\n"
        ".long 0x38600000\n"
        ".long 0x801F2088\n"
        ".long 0x7C090378\n"
        ".long 0x2C000000\n"
        ".long 0x41820014\n"
        ".long 0x2C030000\n"
        ".long 0x4182000C\n"
        ".long 0x38600000\n"
        ".long 0x48000020\n"
        ".long 0x7C091800\n"
        ".long 0x41820014\n"
        ".long 0x907F2088\n"
        ".long 0x38800000\n"
        ".long 0x38600103\n"
        ".long 0x4BFBB5E1\n"
        ".long 0x38600001\n"
        ".long 0x80010014\n"
        ".long 0x7C0803A6\n"
        ".long 0x83E1000C\n"
        ".long 0x38210010\n"
        ".long 0x4E800020\n"
    );
}
