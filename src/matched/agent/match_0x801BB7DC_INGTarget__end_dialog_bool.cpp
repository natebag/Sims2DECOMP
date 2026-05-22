// 0x801BB7DC INGTarget::end_dialog(bool) (316 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 26,0x8(1); stw 0,0x24(1); mr 28,3; mr. 26,4; beq 3f; lha 3,0x9a(28); lwz 4,0x1e0(28); lwz 5,0x1e8(28); lwz 6,0x1f0(28); lwz 7,0x1f8(28); bl _s801BB7DC_0; mr. 26,3; beq 3f; lwz 0,0x200(28); cmpwi 0,0; beq 3f; li 27,0; addic. 31,28,516; beq 2f; lwz 0,0x204(28); cmpwi 0,0; beq 2f; mr 30,31; 0:; lwz 4,0x0(31); lha 0,0x2(4); cmpwi 0,0; bne 1f; lha 29,0x0(4); li 5,0; lwz 3,0x200(28); mr 4,29; bl _s801BB7DC_1; mr. 3,3; beq 1f; bl _s801BB7DC_2; lwz 0,0x4(31); subf. 5,0,3; beq 1f; lwz 3,0x200(28); mr 4,29; li 6,0; bl _s801BB7DC_3; 1:; addi 27,27,1; addi 30,30,8; cmplwi 27,71; bgt 2f; mr 31,30; cmpwi 30,0; beq 2f; lwz 0,0x0(30); cmpwi 0,0; bne 0b; 2:; li 4,0; mr 3,28; bl _s801BB7DC_4; mr 30,3; li 3,0; bl _s801BB7DC_5; subf 4,30,3; li 3,0; bl _s801BB7DC_6; 3:; li 9,0; cmpwi 26,0; li 10,0; beq 4f; li 9,0; li 10,1; 4:; lis 3,-32705; sth 10,-31828(13); addi 3,3,6560; bl _s801BB7DC_7; li 3,1; lwz 0,0x24(1); mtspr 8,0; lmw 26,0x8(1); addi 1,1,32"
extern "C" void _s801BB7DC_0();
extern "C" void _s801BB7DC_1();
extern "C" void _s801BB7DC_2();
extern "C" void _s801BB7DC_3();
extern "C" void _s801BB7DC_4();
extern "C" void _s801BB7DC_5();
extern "C" void _s801BB7DC_6();
extern "C" void _s801BB7DC_7();
extern "C" void f_801BB7DC() {}
