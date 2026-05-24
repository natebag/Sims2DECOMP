// 0x80320070 ERShader::SetDayNightShaderToClosestTime(int, (160 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lis 0,-30584; srawi 9,5,31; ori 0,0,34953; lbz 10,0x44(3); mulhw 0,5,0; rlwinm 4,4,2,0,29; li 8,0; li 11,0; cmpw 8,10; add 0,0,5; srawi 0,0,3; subf 0,9,0; add 4,4,0; rlwinm 4,4,0,24,31; bge 1f; lwz 9,0x48(3); lbz 0,0x0(9); cmplw 0,4; bgt 1f; 0:; addi 11,11,1; cmpw 11,10; bge 1f; lbzx 0,9,11; cmplw 0,4; bgt 1f; mr 8,11; b 0b; 1:; lbz 0,0x44(3); cmpw 11,0; beq 2f; lwz 9,0x48(3); lbzx 4,9,8; bl _s80320070_0; 2:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"

extern "C" void _s80320070_0();

struct ERShader {
    void SetDayNightShaderToClosestTime();
};

void ERShader::SetDayNightShaderToClosestTime() {
}
