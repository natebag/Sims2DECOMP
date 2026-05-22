// 0x801F9960 KEYTarget::GetName(void) (156 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lwz 0,0x8c(3); li 3,0; cmpwi 0,2; beq 2f; bgt 0f; cmpwi 0,1; beq 1f; b 5f; 0:; cmpwi 0,3; beq 3f; cmpwi 0,4; beq 4f; b 5f; 1:; lis 3,-32704; addi 3,3,-22336; bl _s801F9960_0; b 5f; 2:; lis 3,-32704; addi 3,3,-22316; bl _s801F9960_1; b 5f; 3:; lis 3,-32704; addi 3,3,-22300; bl _s801F9960_2; b 5f; 4:; lis 3,-32704; addi 3,3,-22280; bl _s801F9960_3; 5:; cmpwi 3,0; bne 6f; lis 9,-32704; addi 3,9,-30460; 6:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s801F9960_0();
extern "C" void _s801F9960_1();
extern "C" void _s801F9960_2();
extern "C" void _s801F9960_3();
extern "C" void f_801F9960() {}
