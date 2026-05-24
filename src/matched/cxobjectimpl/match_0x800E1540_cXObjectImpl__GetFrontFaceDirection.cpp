// FLAGS: -fno-schedule-insns
// ASMPROC_region_gpr_relabel: start_anchor="lwz 9,140(3)" end_anchor="add 3,10,3" rename="9:4,10:11,11:9"

struct cXObjectImpl {
    void GetFrontFaceDirection();
};

void cXObjectImpl::GetFrontFaceDirection() {
}
