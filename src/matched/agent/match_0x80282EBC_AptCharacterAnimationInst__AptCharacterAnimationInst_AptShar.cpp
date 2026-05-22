// 0x80282EBC AptCharacterAnimationInst::AptCharacterAnimationInst(AptSharedPtr<AptFile>) (152 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,3; mr 30,4; bl _s80282EBC_0; lis 9,-32704; li 0,0; addi 11,31,52; addi 9,9,13304; stw 9,0x14(31); cmpw 30,11; stw 0,0x30(31); stw 0,0x34(31); beq 0f; lwz 3,0x0(30); stw 3,0x0(11); cmpwi 3,0; beq 0f; bl _s80282EBC_1; 0:; lwz 9,0x0(30); lwz 0,0x10(9); stw 0,0x8(31); lwz 3,0x0(30); cmpwi 3,0; beq 1f; bl _s80282EBC_2; cmpwi 3,0; bne 1f; lwz 3,0x0(30); bl _s80282EBC_3; 1:; mr 3,31; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s80282EBC_0();
extern "C" void _s80282EBC_1();
extern "C" void _s80282EBC_2();
extern "C" void _s80282EBC_3();
extern "C" void f_80282EBC() {}
