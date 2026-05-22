// 0x8008CC90 ChangeHouseDemolishHouse::Reset(void) (48 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lis 9,-32697; li 0,0; stw 0,0x5c44(9); li 3,4; bl _s8008CC90_0; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s8008CC90_0();
extern "C" void f_8008CC90() {}
