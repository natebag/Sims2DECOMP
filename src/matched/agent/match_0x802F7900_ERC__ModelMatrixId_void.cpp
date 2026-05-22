// 0x802F7900 ERC::ModelMatrixId(void) (60 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lwz 9,0x70(3); li 4,0; li 5,254; lha 0,0xe0(9); lwz 9,0xe4(9); add 3,3,0; mtspr 8,9; blrl; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void f_802F7900() {}
