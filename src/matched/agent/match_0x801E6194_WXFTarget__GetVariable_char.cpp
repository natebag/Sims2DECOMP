// 0x801E6194 WXFTarget::GetVariable(char (264 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 29,3; mr 30,4; li 3,32; bl _s801E6194_0; mr 31,3; li 0,0; lis 3,-32705; stb 0,0x0(31); addi 3,3,26060; mr 4,30; bl _s801E6194_1; cmpwi 3,0; bne 0f; li 0,1; lis 9,-32705; stw 0,0x88(29); addi 11,9,-8792; lwz 10,-8792(9); lbz 8,0x6(11); lhz 0,0x4(11); stw 10,0x0(31); sth 0,0x4(31); stb 8,0x6(31); b 3f; 0:; lis 3,-32705; mr 4,30; addi 3,3,26072; bl _s801E6194_2; cmpwi 3,0; bne 2f; mr 3,29; bl _s801E6194_3; cmplwi 3,4; ble 1f; li 3,0; 1:; lis 4,-32705; mr 5,3; addi 4,4,-8800; mr 3,31; crxor 6,6,6; bl _s801E6194_4; b 3f; 2:; lis 3,-32705; mr 4,30; addi 3,3,26088; bl _s801E6194_5; cmpwi 3,0; bne 3f; lwz 5,0x128(29); lis 4,-32705; addi 4,4,-8800; mr 3,31; subfic 0,5,0; adde 5,0,5; crxor 6,6,6; bl _s801E6194_6; 3:; mr 3,31; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s801E6194_0();
extern "C" void _s801E6194_1();
extern "C" void _s801E6194_2();
extern "C" void _s801E6194_3();
extern "C" void _s801E6194_4();
extern "C" void _s801E6194_5();
extern "C" void _s801E6194_6();
extern "C" void f_801E6194() {}
