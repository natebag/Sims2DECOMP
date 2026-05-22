// 0x802020E4 RGTTarget::GetVariable(char (196 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 29,3; mr 31,4; li 3,32; bl _s802020E4_0; mr 30,3; li 0,0; stb 0,0x0(30); lbz 9,0x0(31); addi 9,9,-48; cmplwi 9,1; bgt 0f; addi 31,31,1; 0:; lis 3,-32704; mr 4,31; addi 3,3,-17564; bl _s802020E4_1; cmpwi 3,0; bne 1f; lis 9,-32704; addi 11,9,-30832; lwz 10,-30832(9); lbz 8,0x6(11); lhz 0,0x4(11); stw 10,0x0(30); sth 0,0x4(30); stb 8,0x6(30); b 2f; 1:; lis 3,-32704; mr 4,31; addi 3,3,-17552; bl _s802020E4_2; cmpwi 3,0; bne 2f; lis 4,-32704; lwz 5,0x84(29); addi 4,4,-30836; mr 3,30; crxor 6,6,6; bl _s802020E4_3; 2:; mr 3,30; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s802020E4_0();
extern "C" void _s802020E4_1();
extern "C" void _s802020E4_2();
extern "C" void _s802020E4_3();
extern "C" void f_802020E4() {}
