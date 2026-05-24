// 0x800B43EC CTilePt::CTilePt(EVec3&) (68B)
// FLAGS: -fno-schedule-insns2
// ASMPROC_inject_before: before="mr 10,3" lines="mr 11,9"
// ASMPROC_remove_mr: match="stb 0,2(10)" assert_op=""
// ASMPROC_remove_mr: match="mr 9,11" assert_op=""
// ASMPROC_inject_before: before="fctiwz 12,0" lines="stb 0,2(10)"
// ASMPROC_replace_insn: match="lwz 11,12(1)" replacement="lwz 9,12(1)"
// ASMPROC_replace_insn: match="stb 11,0(10)" replacement="stb 9,0(10)"
// ASMPROC_replace_insn: match="lwz 9,12(1)" replacement="lwz 11,12(1)" occurrence=1
// ASMPROC_replace_insn: match="stb 9,1(10)" replacement="stb 11,1(10)"

struct CTilePt {
    void CTilePt_EVec3();
};

void CTilePt::CTilePt_EVec3() {
}
