// 0x802E3438 EEngine::InitResourceManagers(void) (544 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lwz 11,-22652(13); lwz 9,0x0(11); lwz 0,0x14(9); lha 3,0x10(9); mtspr 8,0; add 3,11,3; blrl; lwz 11,-22756(13); lwz 9,0x0(11); lha 3,0x10(9); lwz 0,0x14(9); add 3,11,3; mtspr 8,0; blrl; lis 3,-32692; lis 4,-32702; addi 3,3,-17444; addi 4,4,-5620; bl _s802E3438_0; lis 3,-32692; lis 4,-32702; addi 3,3,-7364; addi 4,4,-5612; bl _s802E3438_1; lis 3,-32693; lis 4,-32702; addi 3,3,11064; addi 4,4,-5600; bl _s802E3438_2; lis 3,-32692; lis 4,-32702; addi 3,3,-27556; addi 4,4,-5588; bl _s802E3438_3; lwz 11,-22572(13); cmpwi 11,0; beq 0f; lwz 9,0xd1c(11); lis 4,-32702; addi 4,4,-5580; lha 3,0x10(9); lwz 0,0x14(9); add 3,11,3; mtspr 8,0; blrl; 0:; lis 3,-32693; lis 4,-32702; addi 3,3,21144; addi 4,4,-5572; bl _s802E3438_4; lis 3,-32693; lis 4,-32702; addi 3,3,24536; addi 4,4,-5560; bl _s802E3438_5; lis 3,-32692; lis 4,-32702; addi 3,3,-20832; addi 4,4,-5548; bl _s802E3438_6; lis 3,-32693; lis 4,-32702; addi 3,3,31260; addi 4,4,-5536; bl _s802E3438_7; lis 3,-32692; lis 4,-32702; addi 3,3,6092; addi 4,4,-5528; bl _s802E3438_8; lis 3,-32692; lis 4,-32702; addi 3,3,-4004; addi 4,4,-5516; bl _s802E3438_9; lis 3,-32692; lis 4,-32702; addi 3,3,-644; addi 4,4,-5496; bl _s802E3438_10; lis 3,-32692; lis 4,-32702; addi 3,3,2716; addi 4,4,-5480; bl _s802E3438_11; lis 3,-32692; lis 4,-32702; addi 3,3,-30916; addi 4,4,-5460; bl _s802E3438_12; lis 3,-32693; lis 4,-32702; addi 3,3,27900; addi 4,4,-5452; bl _s802E3438_13; lis 3,-32693; lis 4,-32702; addi 3,3,14424; addi 4,4,-5436; bl _s802E3438_14; lis 3,-32692; lis 4,-32702; addi 3,3,-24196; addi 4,4,-5420; bl _s802E3438_15; lis 3,-32693; lis 4,-32702; addi 3,3,17784; addi 4,4,-5412; bl _s802E3438_16; lis 3,-32693; lis 4,-32702; addi 3,3,7704; addi 4,4,-5400; bl _s802E3438_17; lis 3,-32692; lis 4,-32702; addi 3,3,-10724; addi 4,4,-5384; bl _s802E3438_18; lis 3,-32692; lis 4,-32702; addi 3,3,-14084; addi 4,4,-5368; bl _s802E3438_19; lis 3,-32693; addi 3,3,5024; bl _s802E3438_20; li 3,1; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s802E3438_0();
extern "C" void _s802E3438_1();
extern "C" void _s802E3438_2();
extern "C" void _s802E3438_3();
extern "C" void _s802E3438_4();
extern "C" void _s802E3438_5();
extern "C" void _s802E3438_6();
extern "C" void _s802E3438_7();
extern "C" void _s802E3438_8();
extern "C" void _s802E3438_9();
extern "C" void _s802E3438_10();
extern "C" void _s802E3438_11();
extern "C" void _s802E3438_12();
extern "C" void _s802E3438_13();
extern "C" void _s802E3438_14();
extern "C" void _s802E3438_15();
extern "C" void _s802E3438_16();
extern "C" void _s802E3438_17();
extern "C" void _s802E3438_18();
extern "C" void _s802E3438_19();
extern "C" void _s802E3438_20();
extern "C" void f_802E3438() {}
