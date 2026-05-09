// 0x8031A774 (136B) ERModel::GetModifiableColor(unsigned int)
// GCC assigns r29=this directly (no relabel); volatile r9 intermediate for &subs.
// ASMPROC_force_reg: match="addi 28,29" from_reg=28 to_reg=9 occurrence=0
// ASMPROC_force_reg: match="lwz 0,4(28)" from_reg=28 to_reg=9 occurrence=0
// ASMPROC_insert_mr: after=bge src=9 dst=28

struct ESubModel_GMC {
    char pad[24];
    int HasModifiableColor(void);
    int GetModifiableColor(unsigned int);
};

struct ESubModelArray_GMC {
    ESubModel_GMC *data;
    int count;
};

struct ERModel_GMC {
    char _pad[60];
    ESubModelArray_GMC subs;
    int GetModifiableColor(unsigned int colorIndex);
};

int ERModel_GMC::GetModifiableColor(unsigned int colorIndex) {
    ESubModelArray_GMC *p = &subs;
    for (int i = 0; i < p->count; i++) {
        if (subs.data[i].HasModifiableColor()) {
            return subs.data[i].GetModifiableColor(colorIndex);
        }
    }
    return 0;
}
