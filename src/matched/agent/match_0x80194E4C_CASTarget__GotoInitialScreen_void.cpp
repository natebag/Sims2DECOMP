// 0x80194E4C CASTarget::GotoInitialScreen(void) (112 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lwz 0,0x104(3); cmpwi 0,2; beq 3f; bgt 0f; cmpwi 0,0; beq 3f; cmpwi 0,1; beq 2f; b 3f; 0:; cmpwi 0,4; beq 3f; blt 1f; cmpwi 0,5; beq 2f; b 3f; 1:; li 4,24; b 4f; 2:; li 4,10; b 4f; 3:; li 4,3; 4:; bl _s80194E4C_0; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s80194E4C_0();
extern "C" void f_80194E4C() {}
