// 0x8037E2C4 DSPInit (196 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; lis 3,-32698; stw 0,0x4(1); addi 5,3,-28000; crxor 6,6,6; addi 3,5,72; stwu 1,-16(1); addi 4,5,104; stw 31,0xc(1); addi 5,5,116; bl _s8037E2C4_0; lwz 0,-22056(13); cmpwi 0,1; beq 0f; lwz 3,-25352(13); bl _s8037E2C4_1; bl _s8037E2C4_2; lis 4,-32712; addi 31,3,0; addi 4,4,-6604; li 3,7; bl _s8037E2C4_3; lis 3,256; bl _s8037E2C4_4; lis 3,-13312; addi 6,3,20480; lhz 3,0x500a(3); li 0,-169; and 0,3,0; ori 0,0,2048; sth 0,0xa(6); li 5,-173; li 4,0; lhz 7,0xa(6); li 0,1; addi 3,31,0; and 5,7,5; sth 5,0xa(6); stw 4,-22028(13); stw 4,-22016(13); stw 4,-22024(13); stw 4,-22020(13); stw 0,-22056(13); bl _s8037E2C4_5; 0:; lwz 0,0x14(1); lwz 31,0xc(1); addi 1,1,16; mtspr 8,0"
extern "C" void _s8037E2C4_0();
extern "C" void _s8037E2C4_1();
extern "C" void _s8037E2C4_2();
extern "C" void _s8037E2C4_3();
extern "C" void _s8037E2C4_4();
extern "C" void _s8037E2C4_5();
extern "C" void f_8037E2C4() {}
