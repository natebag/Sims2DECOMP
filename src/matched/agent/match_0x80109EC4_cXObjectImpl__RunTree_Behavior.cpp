// 0x80109EC4 cXObjectImpl::RunTree(Behavior (144 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 31,4; mr 29,3; lwz 9,0x0(31); mr 4,6; mr 30,5; mr 28,7; lha 3,0x48(9); lwz 0,0x4c(9); add 3,31,3; mtspr 8,0; blrl; mr. 3,3; bne 0f; li 3,0; b 1f; 0:; lwz 9,0x0(29); mr 6,3; mr 4,31; mr 5,30; lwz 11,0x0(9); mr 7,28; lwz 9,0x18(11); lha 3,0xa0(9); lwz 0,0xa4(9); add 3,11,3; mtspr 8,0; blrl; 1:; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void f_80109EC4() {}
