// 0x8023FFE4 CompleteAsync (84 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lis 9,-32700; lwz 0,-23472(9); cmpwi 0,0; bne 0f; li 3,0; b 3f; 0:; lwz 0,-23472(9); cmpwi 0,5; bne 1f; bl _s8023FFE4_0; b 2f; 1:; bl _s8023FFE4_1; 2:; lis 9,-32694; lwz 3,-26472(9); 3:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s8023FFE4_0();
extern "C" void _s8023FFE4_1();
extern "C" void f_8023FFE4() {}
