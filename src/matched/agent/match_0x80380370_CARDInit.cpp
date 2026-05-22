// 0x80380370 CARDInit (172 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; lis 3,-32688; stw 0,0x4(1); stwu 1,-24(1); stw 31,0x14(1); stw 30,0x10(1); addi 30,3,-24000; stw 29,0xc(1); lwz 0,0x10c(30); cmplwi 0,0; beq 0f; lwz 0,0x21c(30); cmplwi 0,0; bne 2f; 0:; bl _s80380370_0; sth 3,-22008(13); lwz 3,-25344(13); bl _s80380370_1; bl _s80380370_2; bl _s80380370_3; li 29,0; li 31,-3; 1:; stw 31,0x4(30); addi 3,30,140; bl _s80380370_4; addi 3,30,224; bl _s80380370_5; addi 29,29,1; cmpwi 29,2; addi 30,30,272; blt 1b; lis 3,-32768; bl _s80380370_6; lis 3,-32698; addi 3,3,-27480; bl _s80380370_7; 2:; lwz 0,0x1c(1); lwz 31,0x14(1); lwz 30,0x10(1); lwz 29,0xc(1); addi 1,1,24; mtspr 8,0"
extern "C" void _s80380370_0();
extern "C" void _s80380370_1();
extern "C" void _s80380370_2();
extern "C" void _s80380370_3();
extern "C" void _s80380370_4();
extern "C" void _s80380370_5();
extern "C" void _s80380370_6();
extern "C" void _s80380370_7();
extern "C" void f_80380370() {}
