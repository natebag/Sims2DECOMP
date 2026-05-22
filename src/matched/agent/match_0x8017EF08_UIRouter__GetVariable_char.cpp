// 0x8017EF08 UIRouter::GetVariable(char (216 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-88(1); mfspr 0,8; stmw 29,0x4c(1); stw 0,0x5c(1); mr 30,4; mr 29,3; mr 3,30; bl _s8017EF08_0; mr. 31,3; bne 0f; li 3,0; b 5f; 0:; cmpwi 31,63; ble 1f; li 31,63; 1:; addi 3,1,8; mr 4,30; addi 5,31,1; bl _s8017EF08_1; cmpwi 31,63; bne 2f; li 0,0; stb 0,0x47(1); 2:; lis 31,-32706; mr 4,30; addi 3,31,14692; li 5,3; bl _s8017EF08_2; cmpwi 3,0; bne 3f; lwz 0,0x3964(31); stw 0,0x8(1); b 4f; 3:; lis 31,-32706; mr 4,30; addi 3,31,14696; li 5,5; bl _s8017EF08_3; cmpwi 3,0; bne 4f; addi 9,31,14696; lwz 0,0x3968(31); lhz 11,0x4(9); stw 0,0x8(1); sth 11,0xc(1); 4:; lwz 3,0x84(29); mr 5,30; addi 4,1,8; bl _s8017EF08_4; 5:; lwz 0,0x5c(1); mtspr 8,0; lmw 29,0x4c(1); addi 1,1,88"
extern "C" void _s8017EF08_0();
extern "C" void _s8017EF08_1();
extern "C" void _s8017EF08_2();
extern "C" void _s8017EF08_3();
extern "C" void _s8017EF08_4();
extern "C" void f_8017EF08() {}
