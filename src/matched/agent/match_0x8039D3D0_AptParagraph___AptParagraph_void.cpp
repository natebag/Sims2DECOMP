// 0x8039D3D0 AptParagraph::~AptParagraph(void) (152 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 31,3; lis 9,-32698; lwz 3,0x0(31); addi 9,9,-21552; mr 29,4; stw 9,0x34(31); cmpwi 3,0; beq 2f; mr 11,3; 0:; lwz 30,0x0(11); cmpwi 11,0; beq 1f; lwz 9,0xc(11); li 4,3; lha 3,0x8(9); lwz 0,0xc(9); add 3,11,3; mtspr 8,0; blrl; 1:; mr. 11,30; bne 0b; 2:; lwz 30,0xc(31); bl _s8039D3D0_0; mr 4,30; bl _s8039D3D0_1; andi. 0,29,1; beq 3f; mr 3,31; bl _s8039D3D0_2; 3:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s8039D3D0_0();
extern "C" void _s8039D3D0_1();
extern "C" void _s8039D3D0_2();
extern "C" void f_8039D3D0() {}
