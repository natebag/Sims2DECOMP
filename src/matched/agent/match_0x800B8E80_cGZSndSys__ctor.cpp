// 0x800B8E80 cGZSndSys::cGZSndSys(void) (104B)
//
// Ctor calling sub-object ctor at this+4 + setting fields. DOL uses r0=1 and
// r9=0 register dataflow; GCC chose r9=1 and r0=0 (swapped).
//
// Recipe: 8-directive replace_insn chain to swap the r0/r9 dataflow.
// region_gpr_relabel would have worked but it lacks immediate-position
// awareness (would corrupt the li r9,0 and li r0,1 immediate operands).
//
// ASMPROC_replace_insn: match="li 9,1" replacement="li 9,0"
// ASMPROC_replace_insn: match="li 0,0" replacement="li 0,1"
// ASMPROC_replace_insn: match="stw 9,1040(30)" replacement="stw 0,1040(30)"
// ASMPROC_replace_insn: match="stw 0,1048(30)" replacement="stw 9,1048(30)"
// ASMPROC_replace_insn: match="stw 0,1028(30)" replacement="stw 9,1028(30)"
// ASMPROC_replace_insn: match="stw 0,1032(30)" replacement="stw 9,1032(30)"
// ASMPROC_replace_insn: match="stw 0,1036(30)" replacement="stw 9,1036(30)"
// ASMPROC_replace_insn: match="stw 0,1044(30)" replacement="stw 9,1044(30)"

extern char cGZSndSys_vt[];
extern "C" void helper_0x802435E4(void* sub, int a, int b);

class cGZSndSys {
public:
    cGZSndSys();
};

cGZSndSys::cGZSndSys() {
    *(volatile int*)((char*)this + 0) = (int)cGZSndSys_vt;
    helper_0x802435E4((char*)this + 4, 0, 1024);
    *(volatile int*)((char*)this + 1040) = 1;
    *(volatile int*)((char*)this + 1048) = 0;
    *(volatile int*)((char*)this + 1028) = 0;
    *(volatile int*)((char*)this + 1032) = 0;
    *(volatile int*)((char*)this + 1036) = 0;
    *(volatile int*)((char*)this + 1044) = 0;
}
