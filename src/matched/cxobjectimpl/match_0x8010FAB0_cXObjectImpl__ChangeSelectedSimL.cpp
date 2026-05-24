// 0x8010FAB0 (96B) — cXObjectImpl::ChangeSelectedSimL(int) [static]
// ASMPROC_force_reg_at_pos: match="add 30,30,9" pos=0 from_reg=30 to_reg=11
// ASMPROC_force_reg: match="lwz 0,256(30)" from_reg=30 to_reg=11
// ASMPROC_insert_mr: after="# beq  cr0" src=11 dst=9
// ASMPROC_force_reg: match="lwz 3,256(30)" from_reg=30 to_reg=9

struct cXObjectImpl {
    void ChangeSelectedSimL();
};

void cXObjectImpl::ChangeSelectedSimL() {
}
