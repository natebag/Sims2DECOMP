// 0x802E3658 EEngine::ShutdownResourceManagers(void) (352 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); bl _s802E3658_0; lis 3,-32693; addi 3,3,5024; bl _s802E3658_1; lis 3,-32693; addi 3,3,31260; bl _s802E3658_2; lis 3,-32693; addi 3,3,24536; bl _s802E3658_3; lwz 11,-22572(13); cmpwi 11,0; beq 0f; lwz 9,0xd1c(11); lha 3,0x18(9); lwz 0,0x1c(9); add 3,11,3; mtspr 8,0; blrl; 0:; lis 3,-32693; addi 3,3,14424; bl _s802E3658_4; lis 3,-32692; addi 3,3,-20832; bl _s802E3658_5; lis 3,-32693; addi 3,3,17784; bl _s802E3658_6; lis 3,-32692; addi 3,3,-24196; bl _s802E3658_7; lis 3,-32693; addi 3,3,11064; bl _s802E3658_8; lis 3,-32693; addi 3,3,21144; bl _s802E3658_9; lis 3,-32692; addi 3,3,-27556; bl _s802E3658_10; lis 3,-32692; addi 3,3,-30916; bl _s802E3658_11; lis 3,-32692; addi 3,3,-17444; bl _s802E3658_12; lis 3,-32692; addi 3,3,-7364; bl _s802E3658_13; lis 3,-32693; addi 3,3,7704; bl _s802E3658_14; lis 3,-32692; addi 3,3,-10724; bl _s802E3658_15; lis 3,-32692; addi 3,3,-14084; bl _s802E3658_16; lis 3,-32692; addi 3,3,-4004; bl _s802E3658_17; lis 3,-32692; addi 3,3,-644; bl _s802E3658_18; lis 3,-32692; addi 3,3,2716; bl _s802E3658_19; lwz 11,-22756(13); lwz 9,0x0(11); lwz 0,0x1c(9); lha 3,0x18(9); mtspr 8,0; add 3,11,3; blrl; lwz 11,-22652(13); lwz 9,0x0(11); lha 3,0x18(9); lwz 0,0x1c(9); add 3,11,3; mtspr 8,0; blrl; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s802E3658_0();
extern "C" void _s802E3658_1();
extern "C" void _s802E3658_2();
extern "C" void _s802E3658_3();
extern "C" void _s802E3658_4();
extern "C" void _s802E3658_5();
extern "C" void _s802E3658_6();
extern "C" void _s802E3658_7();
extern "C" void _s802E3658_8();
extern "C" void _s802E3658_9();
extern "C" void _s802E3658_10();
extern "C" void _s802E3658_11();
extern "C" void _s802E3658_12();
extern "C" void _s802E3658_13();
extern "C" void _s802E3658_14();
extern "C" void _s802E3658_15();
extern "C" void _s802E3658_16();
extern "C" void _s802E3658_17();
extern "C" void _s802E3658_18();
extern "C" void _s802E3658_19();
extern "C" void f_802E3658() {}
