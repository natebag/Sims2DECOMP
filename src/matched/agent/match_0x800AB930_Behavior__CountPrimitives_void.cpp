// 0x800AB930 Behavior::CountPrimitives(void) (56 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lwz 3,0x8(3); lwz 9,0x0(3); lha 0,0x28(9); lwz 9,0x2c(9); add 3,3,0; mtspr 8,9; blrl; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void f_800AB930() {}
