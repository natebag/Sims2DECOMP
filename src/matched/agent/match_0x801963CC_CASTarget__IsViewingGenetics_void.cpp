// 0x801963CC CASTarget::IsViewingGenetics(void) (84 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lwz 0,0x104(3); cmpwi 0,3; beq 0f; cmpwi 0,5; beq 0f; lwz 9,0x84(3); lwz 3,0x1c(9); bl _s801963CC_0; cmpwi 3,8; bgt 0f; cmpwi 3,2; li 3,1; bge 1f; 0:; li 3,0; 1:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s801963CC_0();
extern "C" void f_801963CC() {}
