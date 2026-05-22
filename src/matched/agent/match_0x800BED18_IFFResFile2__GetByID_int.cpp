// 0x800BED18 IFFResFile2::GetByID(int, (60 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lwz 9,0xc(3); mr 7,6; li 6,0; lha 0,0x98(9); lwz 9,0x9c(9); add 3,3,0; mtspr 8,9; blrl; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void f_800BED18() {}
