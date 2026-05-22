// 0x80040A20 EGlobal::GetFamilyIndexOfPerson(ObjectModule (192 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 25,0xc(1); stw 0,0x2c(1); mr 26,4; mr 28,5; mr. 25,6; bne 1f; b 3f; 0:; mr 3,31; b 4f; 1:; lwz 9,0x0(28); li 31,0; lha 3,0x30(9); lwz 0,0x34(9); add 3,28,3; mtspr 8,0; blrl; mr 27,3; cmpw 31,27; bge 3f; 2:; lwz 9,0x0(28); mr 4,31; lwz 11,0x0(26); lwz 0,0x3c(9); lha 3,0x38(9); addi 29,11,232; mtspr 8,0; lha 30,0xe8(11); add 3,28,3; add 30,26,30; blrl; lwz 0,0x4(29); lwz 4,0x0(3); mr 3,30; mtspr 8,0; blrl; cmpw 3,25; beq 0b; addi 31,31,1; cmpw 31,27; blt 2b; 3:; li 3,-1; 4:; lwz 0,0x2c(1); mtspr 8,0; lmw 25,0xc(1); addi 1,1,40"
extern "C" void f_80040A20() {}
