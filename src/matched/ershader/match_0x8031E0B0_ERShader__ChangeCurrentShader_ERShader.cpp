// 0x8031E0B0 ERShader::ChangeCurrentShader(ERShader (180 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,3; mr. 30,4; beq 3f; lwz 4,0x18(31); cmpwi 4,0; beq 0f; lis 3,-32692; li 5,1; addi 3,3,-17444; bl _s8031E0B0_0; li 0,0; stw 0,0x18(31); 0:; li 0,0; stw 30,0x18(31); stw 0,0x14(31); addi 7,31,32; li 0,2; addi 8,30,32; mtspr 9,0; addi 10,31,40; li 11,0; 1:; lwzx 9,11,8; stwx 9,11,7; cmpwi 9,0; beq 2f; lwz 0,0x8(9); stw 0,0x0(10); 2:; addi 10,10,4; addi 11,11,4; bdnz 1b; lwz 0,0x30(30); stw 0,0x30(31); lwz 9,0x34(30); stw 9,0x34(31); lwz 0,0x38(30); stw 0,0x38(31); 3:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"

extern "C" void _s8031E0B0_0();

struct ERShader {
    void ChangeCurrentShader_ERShader();
};

void ERShader::ChangeCurrentShader_ERShader() {
}
