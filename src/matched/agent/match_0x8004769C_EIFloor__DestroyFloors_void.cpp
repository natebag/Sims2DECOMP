// 0x8004769C EIFloor::DestroyFloors(void) (156 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); lis 9,-32696; lwz 30,-29684(9); addi 29,9,-29684; b 1f; 0:; lwz 11,0x1c(30); lwz 30,0x10(30); lwz 9,0x0(11); lha 3,0x8(9); lwz 0,0xc(9); add 3,11,3; mtspr 8,0; blrl; 1:; li 31,1; cmpwi 30,0; bne 2f; li 31,0; 2:; cmpwi 31,0; bne 0b; mr 3,29; bl _s8004769C_0; lwz 30,-32508(13); cmpwi 30,0; beq 3f; li 4,0; mr 3,30; bl _s8004769C_1; bl _s8004769C_2; mr 4,30; bl _s8004769C_3; 3:; stw 31,-32508(13); lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s8004769C_0();
extern "C" void _s8004769C_1();
extern "C" void _s8004769C_2();
extern "C" void _s8004769C_3();
extern "C" void f_8004769C() {}
