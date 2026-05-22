// 0x800EAB54 cXObjectImpl::RunTree(char (112 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); lwz 30,0x4(3); mr 28,4; lwz 9,0x4(30); lha 3,0x378(9); addi 29,9,240; lwz 11,0x37c(9); add 3,30,3; lha 0,0xf0(9); mtspr 8,11; add 30,30,0; blrl; lwz 0,0x4(29); mr 4,3; mr 3,30; mr 6,28; li 5,0; li 7,0; mtspr 8,0; blrl; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void f_800EAB54() {}
