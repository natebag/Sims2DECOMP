// 0x80122998 IsMoveOutOfWay(Interaction (124 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,3; bl _s80122998_0; cmpwi 3,0; li 3,0; beq 1f; mr 3,31; bl _s80122998_1; lwz 9,0x4(3); lha 0,0x368(9); lwz 9,0x36c(9); add 3,3,0; mtspr 8,9; blrl; bl _s80122998_2; cmpwi 3,1988; bne 0f; lwz 3,0x14(31); xori 3,3,3; subfic 0,3,0; adde 3,0,3; b 1f; 0:; li 3,0; 1:; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s80122998_0();
extern "C" void _s80122998_1();
extern "C" void _s80122998_2();
extern "C" void f_80122998() {}
