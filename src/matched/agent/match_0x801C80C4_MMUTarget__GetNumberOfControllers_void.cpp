// 0x801C80C4 MMUTarget::GetNumberOfControllers(void) (284 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); lwz 3,-26524(13); li 4,0; li 31,0; bl _s801C80C4_0; mr. 11,3; beq 0f; lwz 9,0x208(11); lwz 0,0x14(9); lha 3,0x10(9); mtspr 8,0; add 3,11,3; blrl; andi. 3,3,5; xori 31,3,5; subfic 0,31,0; adde 31,0,31; 0:; lwz 3,-26524(13); li 4,1; bl _s801C80C4_1; mr. 11,3; beq 1f; lwz 9,0x208(11); lha 3,0x10(9); lwz 0,0x14(9); add 3,11,3; mtspr 8,0; blrl; andi. 3,3,5; cmpwi 3,5; bne 1f; addi 31,31,1; 1:; lwz 3,-26524(13); li 4,2; bl _s801C80C4_2; mr. 11,3; beq 2f; lwz 9,0x208(11); lha 3,0x10(9); lwz 0,0x14(9); add 3,11,3; mtspr 8,0; blrl; andi. 3,3,5; cmpwi 3,5; bne 2f; addi 31,31,1; 2:; lwz 3,-26524(13); li 4,3; bl _s801C80C4_3; mr. 11,3; beq 3f; lwz 9,0x208(11); lha 3,0x10(9); lwz 0,0x14(9); add 3,11,3; mtspr 8,0; blrl; andi. 3,3,5; cmpwi 3,5; bne 3f; addi 31,31,1; 3:; mr 3,31; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s801C80C4_0();
extern "C" void _s801C80C4_1();
extern "C" void _s801C80C4_2();
extern "C" void _s801C80C4_3();
extern "C" void f_801C80C4() {}
