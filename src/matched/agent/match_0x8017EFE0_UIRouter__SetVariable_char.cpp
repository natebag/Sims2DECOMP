// 0x8017EFE0 UIRouter::SetVariable(char (240 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-88(1); mfspr 0,8; stmw 28,0x48(1); stw 0,0x5c(1); mr 30,4; mr 29,3; mr 28,5; mr 3,30; bl _s8017EFE0_0; mr. 31,3; beq 4f; cmpwi 31,63; ble 0f; li 31,63; 0:; addi 3,1,8; mr 4,30; addi 5,31,1; bl _s8017EFE0_1; cmpwi 31,63; bne 1f; li 0,0; stb 0,0x47(1); 1:; lis 31,-32706; mr 4,30; addi 3,31,14696; li 5,4; bl _s8017EFE0_2; cmpwi 3,0; bne 2f; addi 9,31,14696; lwz 0,0x3968(31); lhz 11,0x4(9); stw 0,0x8(1); sth 11,0xc(1); b 3f; 2:; lis 31,-32706; mr 4,30; addi 3,31,14704; li 5,6; bl _s8017EFE0_3; cmpwi 3,0; bne 3f; addi 9,31,14704; lwz 8,0x3970(31); lbz 0,0x6(9); addi 11,1,8; lhz 10,0x4(9); stb 0,0x6(11); stw 8,0x8(1); sth 10,0x4(11); 3:; lwz 3,0x88(29); mr 5,30; mr 6,28; addi 4,1,8; bl _s8017EFE0_4; 4:; lwz 0,0x5c(1); mtspr 8,0; lmw 28,0x48(1); addi 1,1,88"
extern "C" void _s8017EFE0_0();
extern "C" void _s8017EFE0_1();
extern "C" void _s8017EFE0_2();
extern "C" void _s8017EFE0_3();
extern "C" void _s8017EFE0_4();
extern "C" void f_8017EFE0() {}
