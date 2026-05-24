// 0x803208DC ERShader::GetTimeState(void) (40 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lbz 9,0x67(3); lis 0,-30584; ori 0,0,34953; lbz 3,0x66(3); mulhwu 9,9,0; rlwinm 3,3,2,0,29; rlwinm 9,9,29,3,31; add 3,3,9; rlwinm 3,3,0,24,31"

struct ERShader {
    void GetTimeState();
};

void ERShader::GetTimeState() {
}
