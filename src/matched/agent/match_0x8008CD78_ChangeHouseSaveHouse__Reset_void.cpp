// 0x8008CD78 ChangeHouseSaveHouse::Reset(void) (36 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); li 3,7; bl _s8008CD78_0; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s8008CD78_0();
extern "C" void f_8008CD78() {}
