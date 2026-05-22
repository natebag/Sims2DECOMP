// 0x802E2290 EApp::Main(void) (388 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,3; lis 3,-32702; addi 3,3,-6160; crxor 6,6,6; bl _s802E2290_0; lis 3,-32702; li 4,1; addi 3,3,-6140; crxor 6,6,6; bl _s802E2290_1; lis 3,-32702; li 4,2; addi 3,3,-6112; crxor 6,6,6; bl _s802E2290_2; lis 3,-32702; li 4,4; addi 3,3,-6084; crxor 6,6,6; bl _s802E2290_3; lis 3,-32702; li 4,8; addi 3,3,-6056; crxor 6,6,6; bl _s802E2290_4; lis 3,-32702; li 4,4; addi 3,3,-6028; crxor 6,6,6; bl _s802E2290_5; lis 3,-32702; li 4,4; addi 3,3,-6000; crxor 6,6,6; bl _s802E2290_6; lis 3,-32702; li 4,8; addi 3,3,-5972; crxor 6,6,6; bl _s802E2290_7; lis 3,-32702; li 4,4; addi 3,3,-5944; crxor 6,6,6; bl _s802E2290_8; lwz 11,-26824(13); lwz 9,0x338(11); lwz 0,0x1c(9); lha 3,0x18(9); mtspr 8,0; add 3,11,3; blrl; lwz 11,-26512(13); lwz 9,0x0(11); lha 3,0x20(9); lwz 0,0x24(9); add 3,11,3; mtspr 8,0; blrl; cmpwi 3,0; beq 2f; lwz 9,0x338(31); lwz 0,0xbc(9); lha 3,0xb8(9); b 1f; 0:; lwz 9,0x338(31); lwz 0,0xc4(9); lha 3,0xc0(9); 1:; mtspr 8,0; add 3,31,3; blrl; lwz 0,0x340(31); cmpwi 0,0; beq 0b; lwz 9,0x338(31); lwz 0,0xd4(9); lha 3,0xd0(9); mtspr 8,0; add 3,31,3; blrl; lwz 11,-26512(13); li 4,1; lwz 9,0x0(11); lha 3,0x50(9); lwz 0,0x54(9); add 3,11,3; mtspr 8,0; blrl; 2:; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s802E2290_0();
extern "C" void _s802E2290_1();
extern "C" void _s802E2290_2();
extern "C" void _s802E2290_3();
extern "C" void _s802E2290_4();
extern "C" void _s802E2290_5();
extern "C" void _s802E2290_6();
extern "C" void _s802E2290_7();
extern "C" void _s802E2290_8();
extern "C" void f_802E2290() {}
