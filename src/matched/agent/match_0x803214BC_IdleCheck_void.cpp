// 0x803214BC IdleCheck(void) (128 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-72(1); mfspr 0,8; stw 0,0x4c(1); b 1f; 0:; lwz 3,-22652(13); lwz 9,0x0(3); lha 0,0x38(9); lwz 9,0x3c(9); add 3,3,0; mtspr 8,9; blrl; addi 3,1,8; bl _s803214BC_0; addi 3,1,8; li 4,500; bl _s803214BC_1; addi 3,1,8; li 4,2; bl _s803214BC_2; 1:; lwz 3,-22652(13); lwz 9,0x0(3); lha 0,0x90(9); lwz 9,0x94(9); add 3,3,0; mtspr 8,9; blrl; cmpwi 3,0; bne 0b; lwz 0,0x4c(1); mtspr 8,0; addi 1,1,72"
extern "C" void _s803214BC_0();
extern "C" void _s803214BC_1();
extern "C" void _s803214BC_2();
extern "C" void f_803214BC() {}
