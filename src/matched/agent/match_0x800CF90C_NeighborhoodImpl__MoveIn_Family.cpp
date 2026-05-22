// 0x800CF90C NeighborhoodImpl::MoveIn(Family (164 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,5; mr 11,3; addi 0,31,-1; mr 30,4; cmplwi 0,15; bgt 0f; lwz 9,0x0(11); mr 4,31; lha 3,0x128(9); lwz 0,0x12c(9); add 3,11,3; mtspr 8,0; blrl; cmpwi 3,0; bne 0f; lwz 9,0x0(30); mr 4,31; lwz 0,0xb4(9); lha 3,0xb0(9); mtspr 8,0; add 3,30,3; blrl; lwz 9,0x0(30); li 4,1; lha 3,0x120(9); lwz 0,0x124(9); add 3,30,3; mtspr 8,0; blrl; li 3,0; b 1f; 0:; li 3,-1; 1:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void f_800CF90C() {}
