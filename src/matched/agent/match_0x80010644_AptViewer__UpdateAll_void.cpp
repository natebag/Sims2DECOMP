// 0x80010644 AptViewer::UpdateAll(void) (308 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,3; lwz 0,0x350(31); cmpwi 0,0; beq 2f; lwz 11,-26532(13); lis 9,-32693; addi 30,9,-11760; addi 31,31,856; lwz 9,0x0(11); mr 4,30; lwz 0,0x2c(9); lha 3,0x28(9); mtspr 8,0; add 3,11,3; blrl; lwz 11,-26532(13); mr 4,30; lfs f0,-25140(13); lwz 9,0x0(11); fsubs f1,f1,f0; lwz 0,0x2c(9); lha 3,0x28(9); mtspr 8,0; stfs f1,-32704(13); add 3,11,3; blrl; stfs f1,-25148(13); mr 3,31; li 4,-1; bl _s80010644_0; lwz 0,-31488(13); cmpwi 0,0; bne 0f; li 3,16; bl _s80010644_1; bl _s80010644_2; stw 3,-31488(13); 0:; lwz 3,-31488(13); bl _s80010644_3; bl _s80010644_4; lwz 0,-31488(13); cmpwi 0,0; bne 1f; li 3,16; bl _s80010644_5; bl _s80010644_6; stw 3,-31488(13); 1:; lwz 3,-31488(13); bl _s80010644_7; mr 3,31; bl _s80010644_8; lwz 11,-26532(13); mr 4,30; lwz 9,0x0(11); lwz 0,0x2c(9); lha 3,0x28(9); mtspr 8,0; add 3,11,3; blrl; lwz 11,-26532(13); mr 4,30; lwz 9,0x0(11); lha 3,0x28(9); lwz 0,0x2c(9); add 3,11,3; mtspr 8,0; blrl; stfs f1,-25140(13); 2:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s80010644_0();
extern "C" void _s80010644_1();
extern "C" void _s80010644_2();
extern "C" void _s80010644_3();
extern "C" void _s80010644_4();
extern "C" void _s80010644_5();
extern "C" void _s80010644_6();
extern "C" void _s80010644_7();
extern "C" void _s80010644_8();
extern "C" void f_80010644() {}
