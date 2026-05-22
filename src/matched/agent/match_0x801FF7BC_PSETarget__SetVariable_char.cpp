// 0x801FF7BC PSETarget::SetVariable(char (124 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); lis 3,-32704; mr 31,5; addi 3,3,-19640; bl _s801FF7BC_0; cmpwi 3,0; bne 1f; mr 3,31; bl _s801FF7BC_1; cmpwi 3,2; beq 0f; bgt 1f; cmpwi 3,1; bne 1f; lis 3,-32704; li 4,1; addi 3,3,-19536; bl _s801FF7BC_2; b 1f; 0:; lis 3,-32704; li 4,6; addi 3,3,-19536; bl _s801FF7BC_3; 1:; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s801FF7BC_0();
extern "C" void _s801FF7BC_1();
extern "C" void _s801FF7BC_2();
extern "C" void _s801FF7BC_3();
extern "C" void f_801FF7BC() {}
