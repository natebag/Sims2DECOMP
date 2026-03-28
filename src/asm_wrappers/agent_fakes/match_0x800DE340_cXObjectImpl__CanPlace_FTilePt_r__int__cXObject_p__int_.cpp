/* cXObjectImpl::CanPlace(FTilePt &, int, cXObject *, int) at 0x800DE340 (132B) */

struct cXObjectImpl { void CanPlace(); };

__attribute__((naked))
void cXObjectImpl::CanPlace() {
    asm volatile(
        ".long 0x9421FFD0\n"
        ".long 0x7C0802A6\n"
        ".long 0xBF810020\n"
        ".long 0x90010034\n"
        ".long 0x7C7C1B78\n"
        ".long 0x7C9F2378\n"
        ".long 0x7CBE2B78\n"
        ".long 0x7CFD3B78\n"
        ".long 0x7CC63379\n"
        ".long 0x41820020\n"
        ".long 0x81260004\n"
        ".long 0xA8690520\n"
        ".long 0x80090524\n"
        ".long 0x7C661A14\n"
        ".long 0x7C0803A6\n"
        ".long 0x4E800021\n"
        ".long 0x48000008\n"
        ".long 0x38600000\n"
        ".long 0x7C661B78\n"
        ".long 0x7FE4FB78\n"
        ".long 0x7FC5F378\n"
        ".long 0x7FA7EB78\n"
        ".long 0x38610008\n"
        ".long 0x4BFFEA65\n"
        ".long 0x7F83E378\n"
        ".long 0x38810008\n"
        ".long 0x38A00000\n"
        ".long 0x4BFFF33D\n"
        ".long 0x80010034\n"
        ".long 0x7C0803A6\n"
        ".long 0xBB810020\n"
        ".long 0x38210030\n"
        ".long 0x4E800020\n"
    );
}
