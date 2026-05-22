// 0x802E2994 EEngine::EEngine(void) (292 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); lis 9,-32697; mr 31,3; addi 9,9,-24288; li 4,5; stw 9,0x0(31); bl _s802E2994_0; addi 30,31,52; lis 9,-32697; mr 3,30; addi 9,9,-22776; stw 9,0x0(31); bl _s802E2994_1; mr 3,30; li 4,2; li 5,0; bl _s802E2994_2; lwz 11,-18460(13); li 9,0; li 0,1; stw 9,0x8(31); stw 0,0xc(31); cmpwi 11,1; stw 9,0x4(31); bne 0f; lis 9,-32702; lfs f0,-5680(9); b 1f; 0:; lis 9,-32702; lfs f0,-5676(9); 1:; stfs f0,-22744(13); lis 3,-32693; addi 3,3,-11952; bl _s802E2994_3; lis 9,-32702; lis 5,-32693; lfs f0,-5672(9); lis 11,-32702; lfs f13,-5668(11); addi 9,5,-11796; addi 7,9,24; lis 10,-32693; stfs f13,0x8(7); addi 11,10,-11824; stfs f0,-11824(10); lis 8,-32693; stfs f13,0xc(11); addi 6,8,-11808; stfs f0,0x4(6); addi 4,9,12; stfs f0,-11808(8); li 0,0; stfs f13,-11796(5); mr 3,31; stfs f0,0x8(4); stfs f0,0x18(9); stfs f0,0x4(7); stfs f0,0x8(11); stfs f0,0x4(11); stfs f0,0x8(6); stfs f0,0x4(9); stfs f0,0x8(9); stfs f0,0xc(9); stfs f13,0x4(4); stw 0,0x30(31); lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s802E2994_0();
extern "C" void _s802E2994_1();
extern "C" void _s802E2994_2();
extern "C" void _s802E2994_3();
extern "C" void f_802E2994() {}
