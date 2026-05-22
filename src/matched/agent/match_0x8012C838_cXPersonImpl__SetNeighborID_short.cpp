// 0x8012C838 cXPersonImpl::SetNeighborID(short) (64 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lwz 11,0x4(3); mr 5,4; li 4,31; lwz 9,0x4(11); lha 3,0x140(9); lwz 0,0x144(9); add 3,11,3; mtspr 8,0; blrl; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void f_8012C838() {}
