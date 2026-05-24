// 0x8031E1DC ERShader::SetShaderASyncForState(int) (224 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,3; lwz 9,0x58(31); andi. 0,9,2; beq 0f; lbz 0,0x50(31); rlwinm 4,4,0,24,31; cmpw 0,4; beq 4f; andi. 0,9,4; beq 1f; 0:; li 3,0; b 5f; 1:; lbz 0,0x44(31); li 30,0; rlwinm 11,0,0,24,31; mr 10,0; cmpw 30,11; bge 3f; lwz 9,0x48(31); lbz 0,0x0(9); cmpw 0,4; beq 3f; 2:; addi 30,30,1; cmpw 30,11; bge 3f; lbzx 0,9,30; cmpw 0,4; bne 2b; 3:; cmpw 30,10; li 3,0; beq 5f; mr 3,31; bl _s8031E1DC_0; lbz 9,0x64(31); rlwinm 11,30,2,0,29; lwz 0,0x58(31); lis 3,-32692; stb 9,0x65(31); addi 3,3,-17444; ori 0,0,4; stb 30,0x64(31); stw 0,0x58(31); lwz 9,0x4c(31); lwzx 4,11,9; stw 4,0x5c(31); bl _s8031E1DC_1; 4:; li 3,1; 5:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"

extern "C" void _s8031E1DC_0();
extern "C" void _s8031E1DC_1();

struct ERShader {
    void SetShaderASyncForState();
};

void ERShader::SetShaderASyncForState() {
}
