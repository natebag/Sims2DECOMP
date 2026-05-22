// 0x8035C228 EGrowPool::Reset(void) (112 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 29,3; lwz 0,0x8(29); cmpwi 0,2044; ble 0f; bl _s8035C228_0; b 3f; 0:; lwz 31,0x4(29); li 0,0; stw 0,0x0(29); cmpwi 31,0; beq 2f; 1:; lwz 30,0x0(31); bl _s8035C228_1; mr 4,31; bl _s8035C228_2; mr. 31,30; bne 1b; 2:; li 0,0; stw 0,0x4(29); 3:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s8035C228_0();
extern "C" void _s8035C228_1();
extern "C" void _s8035C228_2();
extern "C" void f_8035C228() {}
