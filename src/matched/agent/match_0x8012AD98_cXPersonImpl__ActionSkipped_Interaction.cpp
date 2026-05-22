// 0x8012AD98 cXPersonImpl::ActionSkipped(Interaction (240 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 30,4; mr 29,3; mr 3,30; bl _s8012AD98_0; mr 31,3; li 4,0; addi 3,29,304; lwz 9,0x2ac(3); lwz 0,0x2a8(3); cmpw 9,0; beq 2f; lis 8,-13108; ori 8,8,52429; 0:; lwz 11,0x2a8(3); lwz 10,0x2ac(3); add 0,11,4; mulhwu 9,0,8; subf 10,11,10; rlwinm 9,9,29,3,31; mulli 9,9,10; subf 0,9,0; mulli 0,0,68; add 0,3,0; cmpw 30,0; bne 1f; bl _s8012AD98_1; b 2f; 1:; addi 4,4,1; cmplw 4,10; blt 0b; 2:; cmpwi 31,0; beq 3f; lwz 9,0x0(29); lwz 30,0x4(31); lwz 11,0x4(9); lha 29,0x100(30); lwz 9,0x4(11); addi 30,30,256; add 29,31,29; lwz 0,0x32c(9); lha 3,0x328(9); mtspr 8,0; add 3,11,3; blrl; lwz 0,0x4(30); mr 5,3; mr 3,29; li 4,4; li 6,0; mtspr 8,0; blrl; 3:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s8012AD98_0();
extern "C" void _s8012AD98_1();
extern "C" void f_8012AD98() {}
