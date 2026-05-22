// 0x801F74E8 INVTarget::GetOnMsgInvShpCategoryN(char (104 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lwz 11,0x178(3); mr 8,4; lwz 0,0x17c(3); li 10,0; subf 0,11,0; srawi 0,0,3; cmplw 5,0; bge 0f; rlwinm 9,5,3,0,28; lwzx 10,11,9; 0:; lis 9,-32704; rlwinm 0,10,2,0,29; addi 9,9,-14376; lis 4,-32704; lwzx 5,9,0; mr 3,8; addi 4,4,-30836; crxor 6,6,6; bl _s801F74E8_0; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s801F74E8_0();
extern "C" void f_801F74E8() {}
