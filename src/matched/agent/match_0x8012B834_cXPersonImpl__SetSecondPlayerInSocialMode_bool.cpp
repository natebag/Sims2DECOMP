// 0x8012B834 cXPersonImpl::SetSecondPlayerInSocialMode(bool) (144 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); lis 9,-32697; mr 29,3; addi 9,9,24012; mr 28,4; addi 30,9,188; li 31,0; 0:; lwz 9,0x0(30); lwz 0,0x4(29); addi 30,30,4; cmpw 9,0; bne 1f; bl _s8012B834_0; mr 4,31; li 5,0; bl _s8012B834_1; mr. 11,3; beq 1f; lwz 9,0x5c(11); lha 3,0x80(9); lwz 0,0x84(9); add 3,11,3; mtspr 8,0; blrl; 1:; addi 31,31,1; cmplwi 31,1; ble 0b; stw 28,0x548(29); lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s8012B834_0();
extern "C" void _s8012B834_1();
extern "C" void f_8012B834() {}
