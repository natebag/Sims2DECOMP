// 0x801FACC4 MSGTarget::GetVariable(char (368 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 30,3; mr 31,4; li 3,32; bl _s801FACC4_0; mr 29,3; li 0,0; stb 0,0x0(29); lbz 9,0x0(31); addi 9,9,-48; cmplwi 9,1; bgt 0f; addi 31,31,1; 0:; lis 3,-32704; mr 4,31; addi 3,3,-21392; bl _s801FACC4_1; cmpwi 3,0; bne 1f; lis 9,-32704; addi 11,9,-30832; lwz 10,-30832(9); lbz 8,0x6(11); lhz 0,0x4(11); stw 10,0x0(29); sth 0,0x4(29); stb 8,0x6(29); b 7f; 1:; lis 3,-32704; mr 4,31; addi 3,3,-21380; bl _s801FACC4_2; mr. 3,3; bne 4f; lwz 0,0x98(30); li 11,20; lis 9,-32700; mtspr 9,11; mulli 0,0,40; addi 9,9,-25200; stw 3,0x84(30); add 11,0,9; 2:; lhz 0,0x0(11); addi 11,11,2; cmpwi 0,0; beq 3f; lwz 9,0x84(30); addi 9,9,1; stw 9,0x84(30); 3:; bdnz 2b; lis 4,-32704; lwz 5,0x84(30); addi 4,4,-30836; mr 3,29; crxor 6,6,6; bl _s801FACC4_3; b 7f; 4:; lis 3,-32704; mr 4,31; addi 3,3,-21364; li 5,14; bl _s801FACC4_4; cmpwi 3,0; bne 7f; addi 3,31,14; bl _s801FACC4_5; lwz 9,0x98(30); lis 11,-32700; lwz 0,0x88(30); addi 11,11,-25200; mulli 9,9,40; add 3,3,0; add 3,3,3; add 3,3,9; lhzx 0,11,3; andi. 9,0,32768; beq 5f; lis 9,-32704; lhz 0,-30820(9); b 6f; 5:; lis 9,-32704; lhz 0,-30824(9); 6:; sth 0,0x0(29); 7:; mr 3,29; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s801FACC4_0();
extern "C" void _s801FACC4_1();
extern "C" void _s801FACC4_2();
extern "C" void _s801FACC4_3();
extern "C" void _s801FACC4_4();
extern "C" void _s801FACC4_5();
extern "C" void f_801FACC4() {}
