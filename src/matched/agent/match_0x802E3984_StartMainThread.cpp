// 0x802E3984 StartMainThread (108 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lwz 3,-26824(13); bl _s802E3984_0; lis 3,-32693; li 4,30; addi 3,3,-11744; bl _s802E3984_1; lwz 11,-26512(13); lwz 9,0x0(11); lwz 0,0x4c(9); lha 3,0x48(9); mtspr 8,0; add 3,11,3; blrl; bl _s802E3984_2; lwz 0,-26736(13); cmpwi 0,0; beq 0f; mtspr 8,0; blrl; 0:; li 3,0; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s802E3984_0();
extern "C" void _s802E3984_1();
extern "C" void _s802E3984_2();
extern "C" void f_802E3984() {}
