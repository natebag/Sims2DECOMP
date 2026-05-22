// 0x802E12D8 EPathUtil::ExtractDirectory(char (148 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,3; cmpw 31,4; beq 0f; bl _s802E12D8_0; 0:; mr 3,31; bl _s802E12D8_1; mr 3,31; li 4,47; bl _s802E12D8_2; mr. 30,3; beq 1f; li 0,0; stb 0,0x1(30); b 3f; 1:; mr 3,31; li 4,58; bl _s802E12D8_3; mr. 3,3; beq 2f; stb 30,0x1(3); b 3f; 2:; lis 9,-32702; addi 11,9,-6348; lhz 0,-6348(9); lbz 10,0x2(11); sth 0,0x0(31); stb 10,0x2(31); 3:; mr 3,31; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s802E12D8_0();
extern "C" void _s802E12D8_1();
extern "C" void _s802E12D8_2();
extern "C" void _s802E12D8_3();
extern "C" void f_802E12D8() {}
