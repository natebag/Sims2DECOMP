// 0x8031DFE0 ERShader::SetCurrentShaderForState(unsigned (208 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,3; lwz 0,0x58(31); andi. 9,0,2; bne 0f; li 3,0; b 3f; 0:; lbz 0,0x44(31); li 30,0; rlwinm 11,0,0,24,31; mr 10,0; cmpw 30,11; bge 2f; lwz 9,0x48(31); lbz 0,0x0(9); cmpw 0,4; beq 2f; 1:; addi 30,30,1; cmpw 30,11; bge 2f; lbzx 0,9,30; cmpw 0,4; bne 1b; 2:; cmpw 30,10; li 3,0; beq 3f; mr 3,31; bl _s8031DFE0_0; stb 30,0x64(31); rlwinm 10,30,2,0,29; lwz 9,0x48(31); lis 3,-32692; lwz 11,0x4c(31); li 5,0; lbzx 0,9,30; li 6,0; addi 3,3,-17444; stb 0,0x50(31); lwzx 4,10,11; bl _s8031DFE0_1; mr 4,3; mr 3,31; bl _s8031DFE0_2; li 3,1; 3:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"

extern "C" void _s8031DFE0_0();
extern "C" void _s8031DFE0_1();
extern "C" void _s8031DFE0_2();

struct ERShader {
    void SetCurrentShaderForState();
};

void ERShader::SetCurrentShaderForState() {
}
