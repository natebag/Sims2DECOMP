// 0x80368A54 ERCharacter::Refresh(EFile (64 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); mr 11,3; mr. 4,4; beq 0f; lwz 9,0x0(11); lha 3,0x48(9); lwz 0,0x4c(9); add 3,11,3; mtspr 8,0; blrl; 0:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void f_80368A54() {}
