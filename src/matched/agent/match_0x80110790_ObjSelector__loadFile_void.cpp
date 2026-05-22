// 0x80110790 ObjSelector::loadFile(void) (76 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 30,3; lwz 11,0x50(30); mr 4,30; lwz 9,0x0(11); lha 3,0x148(9); lwz 0,0x14c(9); add 3,11,3; mtspr 8,0; blrl; lwz 3,0x0(30); lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void f_80110790() {}
