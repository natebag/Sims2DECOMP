// 0x80041AC0 EGlobal::BeginSaveGame(void) (172 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lis 3,-32697; addi 3,3,-7672; bl _s80041AC0_0; cmpwi 3,0; beq 0f; lwz 11,-26392(13); lwz 9,0x0(11); lwz 0,0x44(9); lha 3,0x40(9); mtspr 8,0; add 3,11,3; blrl; lwz 11,-22652(13); lwz 9,0x0(11); lha 3,0x38(9); lwz 0,0x3c(9); add 3,11,3; mtspr 8,0; blrl; 0:; lwz 11,-26392(13); lwz 9,0x0(11); lha 3,0x40(9); lwz 0,0x44(9); add 3,11,3; mtspr 8,0; blrl; lis 9,-32697; addi 9,9,24012; lwz 3,0xc8(9); cmpwi 3,0; beq 1f; lwz 0,0xa0(9); cmpwi 0,1; bne 1f; bl _s80041AC0_1; bl _s80041AC0_2; 1:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s80041AC0_0();
extern "C" void _s80041AC0_1();
extern "C" void _s80041AC0_2();
extern "C" void f_80041AC0() {}
