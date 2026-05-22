// 0x80124A4C cXPersonImpl::NetTrySnapTo(StackElem (144 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 30,0x10(1); stw 0,0x1c(1); stw 5,0x8(1); mr 30,3; addi 4,1,8; li 5,1; lwz 10,0x0(30); lwz 11,0x4(10); lwz 9,0x4(11); lwz 0,0x334(9); lha 3,0x330(9); mtspr 8,0; add 3,11,3; blrl; lwz 11,0x4(30); lwz 9,0x4(11); lwz 0,0x18c(9); lha 3,0x188(9); mtspr 8,0; add 3,11,3; blrl; lwz 9,0x0(3); lha 0,0x40(9); lwz 9,0x44(9); add 3,3,0; mtspr 8,9; blrl; li 3,0; li 4,1; lwz 0,0x1c(1); mtspr 8,0; lmw 30,0x10(1); addi 1,1,24"
extern "C" void f_80124A4C() {}
