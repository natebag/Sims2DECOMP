// 0x801F73BC INVTarget::GetOnMsgInvShpColorN(char (180 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 28,0x18(1); stw 0,0x2c(1); mr 28,4; mr 31,5; lbz 4,0x3251(3); addi 5,1,8; addi 6,1,16; bl _s801F73BC_0; lwz 0,0x10(1); cmpwi 0,11; bgt 0f; cmpwi 0,9; bge 1f; 0:; lwz 3,0x8(1); bl _s801F73BC_1; lwz 9,0x38(3); lis 30,-32692; addi 30,30,-27556; li 5,0; lwz 11,0xc0(9); li 6,0; mr 3,30; lwz 9,0x0(11); lwz 29,0x0(9); mr 4,29; bl _s801F73BC_2; mr 4,31; bl _s801F73BC_3; mr 5,3; lis 4,-32704; addi 4,4,-30836; mr 3,28; crxor 6,6,6; bl _s801F73BC_4; mr 3,30; mr 4,29; li 5,1; bl _s801F73BC_5; 1:; lwz 0,0x2c(1); mtspr 8,0; lmw 28,0x18(1); addi 1,1,40"
extern "C" void _s801F73BC_0();
extern "C" void _s801F73BC_1();
extern "C" void _s801F73BC_2();
extern "C" void _s801F73BC_3();
extern "C" void _s801F73BC_4();
extern "C" void _s801F73BC_5();
extern "C" void f_801F73BC() {}
