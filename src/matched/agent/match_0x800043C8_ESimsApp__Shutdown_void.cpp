// 0x800043C8 ESimsApp::Shutdown(void) (236 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,3; lis 3,-32697; addi 3,3,24012; bl _s800043C8_0; lwz 3,-32060(13); bl _s800043C8_1; lis 9,-32692; lwz 0,-17472(9); cmpwi 0,0; beq 0f; lwz 4,-26656(13); cmpwi 4,0; beq 0f; lis 3,-32692; addi 3,3,-17444; bl _s800043C8_2; li 0,0; stw 0,-26652(13); stw 0,-26656(13); 0:; bl _s800043C8_3; lwz 3,0x478(31); bl _s800043C8_4; lwz 3,0x478(31); cmpwi 3,0; beq 1f; li 4,3; bl _s800043C8_5; 1:; li 0,0; lis 3,-32697; addi 3,3,24012; stw 0,0x488(31); stw 0,0x478(31); stb 0,0x484(31); bl _s800043C8_6; bl _s800043C8_7; lwz 11,0x480(31); cmpwi 11,0; beq 2f; lwz 9,0x9c(11); li 4,3; lha 3,0x8(9); lwz 0,0xc(9); add 3,11,3; mtspr 8,0; blrl; 2:; lis 3,-32696; addi 3,3,32332; bl _s800043C8_8; addi 3,13,-24588; bl _s800043C8_9; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s800043C8_0();
extern "C" void _s800043C8_1();
extern "C" void _s800043C8_2();
extern "C" void _s800043C8_3();
extern "C" void _s800043C8_4();
extern "C" void _s800043C8_5();
extern "C" void _s800043C8_6();
extern "C" void _s800043C8_7();
extern "C" void _s800043C8_8();
extern "C" void _s800043C8_9();
extern "C" void f_800043C8() {}
