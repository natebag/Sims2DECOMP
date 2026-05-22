// 0x8037F728 TimeoutHandler (164 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; lis 4,-32688; stw 0,0x4(1); addi 4,4,-24000; addi 0,4,224; stwu 1,-24(1); cmplw 3,0; stw 31,0x14(1); li 31,0; stw 30,0x10(1); addi 30,4,0; beq 0f; addi 0,4,496; cmplw 3,0; addi 4,4,272; addi 30,4,0; li 31,1; beq 0f; li 31,2; 0:; lwz 0,0x0(30); cmpwi 0,0; beq 1f; addi 3,31,0; li 4,0; bl _s8037F728_0; lwz 0,0xcc(30); cmplwi 0,0; mr 12,0; beq 1f; li 0,0; mtspr 8,12; stw 0,0xcc(30); addi 3,31,0; li 4,-5; blrl; 1:; lwz 0,0x1c(1); lwz 31,0x14(1); lwz 30,0x10(1); addi 1,1,24; mtspr 8,0"
extern "C" void _s8037F728_0();
extern "C" void f_8037F728() {}
