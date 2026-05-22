// 0x802F9A80 ERC::ModelMatrix(EMat4 (56 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lwz 9,0x70(3); li 5,1; lha 0,0xe8(9); lwz 9,0xec(9); add 3,3,0; mtspr 8,9; blrl; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void f_802F9A80() {}
