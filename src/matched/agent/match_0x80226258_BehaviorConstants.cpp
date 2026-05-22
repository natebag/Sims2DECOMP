// 0x80226258 BehaviorConstants (96 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 0,0x114(9); lha 3,0x110(9); mtspr 8,0; add 3,11,3; blrl; lis 3,-32697; addi 3,3,24012; bl _s80226258_0; lwz 11,-21424(13); lwz 9,0x0(11); lha 3,0x88(9); lwz 0,0x8c(9); add 3,11,3; mtspr 8,0; blrl; addi 3,1,24; li 4,2; bl _s80226258_1; li 3,1; lwz 0,0x154(1); mtspr 8,0; lmw 14,0x108(1); addi 1,1,336"
extern "C" void _s80226258_0();
extern "C" void _s80226258_1();
extern "C" int f_80226258() {}
