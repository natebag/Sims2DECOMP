// 0x8013048C cXPortalImpl::GetOtherSide(void) (244 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 30,3; li 4,15; lwz 11,0x0(30); mr 31,30; lwz 9,0x0(11); lwz 10,0x4(9); lwz 11,0x4(10); lha 3,0x1d0(11); lwz 0,0x1d4(11); add 3,10,3; mtspr 8,0; blrl; 0:; lwz 3,0x0(31); lwz 9,0x8(3); cmpwi 9,0; beq 1f; lwz 9,0x4(9); b 2f; 1:; lwz 3,0xc(3); li 9,0; cmpwi 3,0; beq 2f; lwz 9,0x4(3); 2:; cmpwi 9,0; beq 3f; lwz 9,0x0(9); li 4,11; lwz 3,0x0(9); bl _s8013048C_0; mr 31,3; b 4f; 3:; li 31,0; 4:; cmpw 31,30; bne 5f; li 3,0; b 6f; 5:; lwz 11,0x0(31); li 4,15; lwz 9,0x0(11); lwz 10,0x4(9); lwz 11,0x4(10); lha 3,0x1d0(11); lwz 0,0x1d4(11); add 3,10,3; mtspr 8,0; blrl; cmpwi 3,0; beq 0b; cmpwi 31,0; li 3,0; beq 6f; lwz 3,0x4(31); 6:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s8013048C_0();
extern "C" void f_8013048C() {}
