// 0x80319E88 (128B) ERModel::GenerateMorphTargetDeltas(ERModel *)
// GCC: r27=this, r28=target, r29=&subs. DOL: r28=this, r29=target, r27=&subs.
// Two-relabel rotation: swap27:29 → swap28:29, then lazy volatile r9 + count-reg fix.
// ASMPROC_gpr_relabel: swap=27:29 skip_opcodes=stmw,lmw
// ASMPROC_gpr_relabel: swap=28:29 skip_opcodes=stmw,lmw
// ASMPROC_force_reg: match="addi 27,28" from_reg=27 to_reg=9 occurrence=0
// ASMPROC_force_reg: match="lwz 9,64(29)" from_reg=9 to_reg=11 occurrence=0
// ASMPROC_force_reg: match="lwz 0,4(27)" from_reg=27 to_reg=9 occurrence=0
// ASMPROC_insert_mr: after="lwz 0,4(9)" src=9 dst=27 occurrence=0
// ASMPROC_force_reg: match="cmpw 0,9,0" from_reg=9 to_reg=11 occurrence=0
// ASMPROC_force_reg: match="cmpw 0,30,9" from_reg=9 to_reg=11 occurrence=0

struct ESubModel_ERGMD {
    char pad[24];
    void GenerateMorphTargetDeltas(ESubModel_ERGMD *target);
};

struct ESubModelArray_ERGMD {
    ESubModel_ERGMD *data;
    int count;
};

struct ERModel_GMD {
    char _pad[60];
    ESubModelArray_ERGMD subs;
    void GenerateMorphTargetDeltas(ERModel_GMD *target);
};

void ERModel_GMD::GenerateMorphTargetDeltas(ERModel_GMD *target) {
    if (target == 0) return;
    ESubModelArray_ERGMD *p = &subs;
    if (target->subs.count != p->count) return;
    for (int i = 0; i < p->count; i++) {
        subs.data[i].GenerateMorphTargetDeltas(&target->subs.data[i]);
    }
}
