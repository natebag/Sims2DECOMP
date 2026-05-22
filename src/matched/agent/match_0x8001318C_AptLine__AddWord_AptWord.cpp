// 0x8001318C AptLine::AddWord(AptWord (56 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="bl _s8001318C_0; lwz 9,0x34(29); lwz 10,0x0(9); lwz 11,0x4(10); lha 3,0x250(11); lwz 0,0x254(11); add 3,10,3; mtspr 8,0; blrl; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s8001318C_0();
extern "C" int f_8001318C() {}
