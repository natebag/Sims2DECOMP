// 0x80320860 ERShader::IsMultiShader(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 3,0x58(3); rlwinm 3,3,31,31,31"

struct ERShader {
    void IsMultiShader();
};

void ERShader::IsMultiShader() {
}
