// 0x801BE548 K2YTarget::IsModeValid(void) (36B)
// ASMPROC_replace_insn: match="cmpwi 7,0,1" replacement="cmpwi 7,0,2"
// ASMPROC_inject_before: before="mfcr" lines="cror 4*cr7+so,4*cr7+eq,4*cr7+gt"
// ASMPROC_replace_insn: match="rlwinm 3,3,30,1" replacement="rlwinm 3,3,0,1"

extern int gv_K2YTarget_GetModevoid;

int gf_K2YTarget_IsModeValidvoid() {
    int m = gv_K2YTarget_GetModevoid;
    int r = 0;
    if (m > 8) goto end;
    r = (m >= 2) ? 1 : 0;
end:
    return r;
}
