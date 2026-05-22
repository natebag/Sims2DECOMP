// 0x80292B58 AptCIH::SetEventHandler(int) (76 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); lwz 9,0x8(3); mr 30,4; lha 0,0x20(9); lwz 9,0x24(9); add 3,3,0; mtspr 8,9; blrl; lwz 0,0x10(3); or 0,0,30; stw 0,0x10(3); lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void f_80292B58() {}
