// FLAGS: -fno-elide-constructors
// ASMPROC_region_gpr_relabel: start_anchor="lwz 0,104(31)" start_mode=at end_anchor="mullw 0,0,0" end_mode=at rename="0:11,11:0" unsafe_clobber=true
// ASMPROC_region_gpr_relabel: start_anchor="lfd 0,.LC0@l(9)" start_mode=after end_anchor="mullw 11,11,11" end_mode=at rename="0:11,11:0" unsafe_clobber=true
// 0x800DFE38 (168B) — cXObjectImpl::CalcShortDistance(cXObject *)

struct cXObjectImpl {
    void CalcShortDistance_cXObject();
};

void cXObjectImpl::CalcShortDistance_cXObject() {
}
