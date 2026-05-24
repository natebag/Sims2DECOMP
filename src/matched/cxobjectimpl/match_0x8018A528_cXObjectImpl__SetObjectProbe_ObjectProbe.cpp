// 0x8018A528 cXObjectImpl::SetObjectProbe(ObjectProbe (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" replace="b f_8018A6A8" lines="li 0,-1"

struct cXObjectImpl {
    void SetObjectProbe_ObjectProbe();
};

void cXObjectImpl::SetObjectProbe_ObjectProbe() {
}
