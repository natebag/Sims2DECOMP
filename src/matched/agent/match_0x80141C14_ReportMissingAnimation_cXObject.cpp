// 0x80141C14 ReportMissingAnimation(cXObject (108 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 30,4; lwz 11,0x0(30); li 4,67; lwz 10,0x0(11); lwz 9,0x18(10); lwz 0,0x2c(9); lha 3,0x28(9); mtspr 8,0; add 3,10,3; blrl; lwz 11,0x0(30); li 4,67; lwz 9,0x4(11); lha 3,0x110(9); lwz 0,0x114(9); add 3,11,3; mtspr 8,0; blrl; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void f_80141C14() {}
