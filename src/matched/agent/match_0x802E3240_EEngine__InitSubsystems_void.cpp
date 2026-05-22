// 0x802E3240 EEngine::InitSubsystems(void) (460 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); lwz 11,-26532(13); mr 31,3; lwz 9,0x0(11); lwz 0,0x14(9); lha 3,0x10(9); mtspr 8,0; add 3,11,3; blrl; lwz 9,0x0(31); lha 3,0x90(9); lwz 0,0x94(9); add 3,31,3; mtspr 8,0; blrl; cmpwi 3,0; li 3,0; beq 4f; lwz 3,-26392(13); lwz 9,0x0(3); lha 0,0x20(9); lwz 9,0x24(9); add 3,3,0; mtspr 8,9; blrl; cmpwi 3,0; li 3,0; beq 4f; lis 3,-32692; addi 3,3,-17464; bl _s802E3240_0; lwz 9,0x0(31); lha 3,0x98(9); lwz 0,0x9c(9); add 3,31,3; mtspr 8,0; blrl; cmpwi 3,0; beq 0f; bl _s802E3240_1; lwz 3,-26524(13); lwz 9,0x20(3); lha 0,0x18(9); lwz 9,0x1c(9); add 3,3,0; mtspr 8,9; blrl; cmpwi 3,0; li 3,0; beq 4f; lwz 3,-26384(13); lwz 9,0x0(3); lha 0,0x10(9); lwz 9,0x14(9); add 3,3,0; mtspr 8,9; blrl; cmpwi 3,1; beq 1f; 0:; li 3,0; b 4f; 1:; lwz 11,-26564(13); cmpwi 11,0; beq 2f; lwz 9,0x0(11); lha 3,0x10(9); lwz 0,0x14(9); add 3,11,3; mtspr 8,0; blrl; 2:; bl _s802E3240_2; bl _s802E3240_3; bl _s802E3240_4; bl _s802E3240_5; bl _s802E3240_6; bl _s802E3240_7; bl _s802E3240_8; bl _s802E3240_9; bl _s802E3240_10; bl _s802E3240_11; bl _s802E3240_12; bl _s802E3240_13; bl _s802E3240_14; bl _s802E3240_15; bl _s802E3240_16; bl _s802E3240_17; bl _s802E3240_18; bl _s802E3240_19; bl _s802E3240_20; bl _s802E3240_21; bl _s802E3240_22; bl _s802E3240_23; bl _s802E3240_24; bl _s802E3240_25; bl _s802E3240_26; bl _s802E3240_27; bl _s802E3240_28; bl _s802E3240_29; lwz 0,-18460(13); li 3,50; cmpwi 0,0; bne 3f; li 3,60; 3:; li 4,1; li 5,0; bl _s802E3240_30; li 3,1; 4:; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s802E3240_0();
extern "C" void _s802E3240_1();
extern "C" void _s802E3240_2();
extern "C" void _s802E3240_3();
extern "C" void _s802E3240_4();
extern "C" void _s802E3240_5();
extern "C" void _s802E3240_6();
extern "C" void _s802E3240_7();
extern "C" void _s802E3240_8();
extern "C" void _s802E3240_9();
extern "C" void _s802E3240_10();
extern "C" void _s802E3240_11();
extern "C" void _s802E3240_12();
extern "C" void _s802E3240_13();
extern "C" void _s802E3240_14();
extern "C" void _s802E3240_15();
extern "C" void _s802E3240_16();
extern "C" void _s802E3240_17();
extern "C" void _s802E3240_18();
extern "C" void _s802E3240_19();
extern "C" void _s802E3240_20();
extern "C" void _s802E3240_21();
extern "C" void _s802E3240_22();
extern "C" void _s802E3240_23();
extern "C" void _s802E3240_24();
extern "C" void _s802E3240_25();
extern "C" void _s802E3240_26();
extern "C" void _s802E3240_27();
extern "C" void _s802E3240_28();
extern "C" void _s802E3240_29();
extern "C" void _s802E3240_30();
extern "C" void f_802E3240() {}
