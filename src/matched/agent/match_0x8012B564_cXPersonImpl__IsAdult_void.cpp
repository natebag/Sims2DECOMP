// 0x8012B564 cXPersonImpl::IsAdult(void) (60 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lwz 3,0x4(3); lwz 9,0x4(3); lha 0,0x150(9); lwz 9,0x154(9); add 3,3,0; mtspr 8,9; blrl; li 3,1; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void f_8012B564() {}
