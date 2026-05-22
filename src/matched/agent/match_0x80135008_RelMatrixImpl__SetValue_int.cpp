// 0x80135008 RelMatrixImpl::SetValue(int, (204 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 31,3; mr 30,4; mr 29,5; mr 28,6; bl _s80135008_0; lwz 0,0x8(31); cmpw 3,0; beq 0f; lwz 9,0x0(3); lwz 11,0x0(9); lwz 0,0x4(9); subf 0,11,0; srawi 0,0,2; cmplw 29,0; blt 1f; 0:; lwz 9,0x0(31); mr 4,30; addi 5,29,1; lha 3,0x28(9); lwz 0,0x2c(9); add 3,31,3; mtspr 8,0; blrl; mr 3,31; mr 4,30; bl _s80135008_1; 1:; cmpwi 3,0; beq 2f; lwz 3,0x0(3); cmpwi 3,0; beq 2f; lwz 9,0x0(3); lwz 0,0x4(3); subf 0,9,0; srawi 0,0,2; cmpw 0,29; ble 2f; rlwinm 5,29,2,0,29; lwzx 0,9,5; cmpw 0,28; beq 2f; stwx 28,9,5; 2:; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s80135008_0();
extern "C" void _s80135008_1();
extern "C" void f_80135008() {}
