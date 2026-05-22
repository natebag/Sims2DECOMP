// 0x801EA394 FONTarget::GetVariable(char (376 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 30,3; mr 31,4; li 3,32; bl _s801EA394_0; mr 29,3; li 0,0; stb 0,0x0(29); lbz 9,0x0(31); addi 9,9,-48; cmplwi 9,1; bgt 0f; addi 31,31,1; 0:; lis 3,-32704; mr 4,31; addi 3,3,-30456; bl _s801EA394_1; cmpwi 3,0; bne 1f; lis 9,-32704; addi 11,9,-30832; lwz 10,-30832(9); lbz 8,0x6(11); lhz 0,0x4(11); stw 10,0x0(29); sth 0,0x4(29); stb 8,0x6(29); b 7f; 1:; lis 3,-32704; mr 4,31; addi 3,3,-30444; bl _s801EA394_2; cmpwi 3,0; bne 2f; lis 4,-32704; lwz 5,0x88(30); b 5f; 2:; lis 3,-32704; mr 4,31; addi 3,3,-30428; bl _s801EA394_3; mr. 3,3; bne 6f; lwz 9,0x8c(30); stw 3,0x98(30); cmpwi 9,0; beq 4f; lwz 11,0x4(9); cmpwi 11,0; beq 4f; lwz 0,0x8(11); cmpwi 0,0; beq 3f; lwz 0,0x0(9); stw 0,0x4(9); lwz 3,0x8c(30); lwz 4,0x4(3); bl _s801EA394_4; mr 5,3; lwz 9,0x8c(30); stw 5,0x88(30); mr 3,30; lwz 4,0x4(9); bl _s801EA394_5; li 0,1; 3:; stw 0,0x98(30); 4:; lis 4,-32704; lwz 5,0x98(30); 5:; addi 4,4,-30836; mr 3,29; crxor 6,6,6; bl _s801EA394_6; b 7f; 6:; lis 3,-32704; mr 4,31; addi 3,3,-30408; bl _s801EA394_7; cmpwi 3,0; bne 7f; lis 4,-32704; lwz 5,0x98(30); addi 4,4,-30836; mr 3,29; crxor 6,6,6; bl _s801EA394_8; 7:; mr 3,29; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s801EA394_0();
extern "C" void _s801EA394_1();
extern "C" void _s801EA394_2();
extern "C" void _s801EA394_3();
extern "C" void _s801EA394_4();
extern "C" void _s801EA394_5();
extern "C" void _s801EA394_6();
extern "C" void _s801EA394_7();
extern "C" void _s801EA394_8();
extern "C" void f_801EA394() {}
