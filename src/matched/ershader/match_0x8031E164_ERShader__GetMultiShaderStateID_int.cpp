// 0x8031E164 ERShader::GetMultiShaderStateID(int) (120 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 0,0x58(3); andi. 9,0,2; bne 0f; li 3,0; blr; 0:; lbz 0,0x44(3); li 9,0; rlwinm 10,0,0,24,31; mr 8,0; cmpw 9,10; bge 2f; lwz 11,0x48(3); rlwinm 4,4,0,24,31; lbz 0,0x0(11); cmpw 0,4; beq 2f; 1:; addi 9,9,1; cmpw 9,10; bge 2f; lbzx 0,11,9; cmpw 0,4; bne 1b; 2:; cmpw 9,8; beq 3f; lwz 11,0x4c(3); rlwinm 9,9,2,0,29; lwzx 3,9,11; blr; 3:; li 3,0"

struct ERShader {
    void GetMultiShaderStateID();
};

void ERShader::GetMultiShaderStateID() {
}
