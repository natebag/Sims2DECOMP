// 0x8018A9E4 cXObjectImpl::GetRelMatrix(void) (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" replace="b f_8018AAD4" lines="bl _s8018A9E4_0"

extern "C" void _s8018A9E4_0();

struct cXObjectImpl {
    void GetRelMatrix();
};

void cXObjectImpl::GetRelMatrix() {
}
