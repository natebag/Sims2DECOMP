// 0x8023FB10 PCreadAsyncNext (140 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); lis 31,-32694; lis 9,-13312; li 0,4096; lwz 29,-26492(31); ori 9,9,12288; stw 0,0x0(9); bl _s8023FB10_0; lis 10,-32694; lwz 0,-26488(10); cmpwi 0,0; beq 0f; lwz 11,-26492(31); li 30,1024; lwz 9,-26488(10); addi 11,11,1024; addi 9,9,-1; stw 11,-26492(31); stw 9,-26488(10); b 1f; 0:; lis 9,-32694; lwz 30,-26484(9); stw 0,-26484(9); 1:; bl _s8023FB10_1; mr 3,29; mr 4,30; bl _s8023FB10_2; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s8023FB10_0();
extern "C" void _s8023FB10_1();
extern "C" void _s8023FB10_2();
extern "C" void f_8023FB10() {}
