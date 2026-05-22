// 0x801F5F2C INVTarget::SetOnMsgInvShpCurrentCategory(char (148 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 31,3; addi 30,31,376; lwz 9,0x178(31); lwz 0,0x4(30); mr 3,4; subf 0,9,0; rlwinm. 9,0,29,3,31; beq 2f; li 29,0; stb 29,0x3251(31); bl _s801F5F2C_0; mr 11,3; stb 3,0x3250(31); andi. 0,11,128; beq 0f; stb 29,0x3250(31); b 1f; 0:; lwz 9,0x178(31); rlwinm 11,11,0,24,31; lwz 0,0x4(30); subf 0,9,0; srawi 9,0,3; cmplw 11,9; blt 1f; addi 0,9,-1; stb 0,0x3250(31); 1:; mr 3,31; bl _s801F5F2C_1; 2:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s801F5F2C_0();
extern "C" void _s801F5F2C_1();
extern "C" void f_801F5F2C() {}
