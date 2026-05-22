// 0x800B720C DiscErrorCallback(bool) (88 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lwz 0,-24508(13); cmpwi 0,0; beq 1f; cmpwi 3,0; beq 0f; lwz 3,-21492(13); bl _s800B720C_0; stw 3,-32064(13); li 4,5; lwz 3,-21492(13); bl _s800B720C_1; b 1f; 0:; lwz 3,-21492(13); lwz 4,-32064(13); bl _s800B720C_2; 1:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s800B720C_0();
extern "C" void _s800B720C_1();
extern "C" void _s800B720C_2();
extern "C" void f_800B720C() {}
