// 0x801193D8 cSampleChannel::Unpause(void) (80 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lwz 3,0x0(3); cmpwi 3,0; beq 0f; lwz 11,0x18(3); cmpwi 11,0; beq 0f; lwz 9,0x0(11); lha 3,0x40(9); lwz 0,0x44(9); add 3,11,3; mtspr 8,0; blrl; 0:; li 3,1; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void f_801193D8() {}
