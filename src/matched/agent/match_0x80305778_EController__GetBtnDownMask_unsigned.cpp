// 0x80305778 EController::GetBtnDownMask(unsigned (56 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 30,3; bl _s80305778_0; lwz 9,0x200(30); lwz 0,0x8(9); andc 3,0,3; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s80305778_0();
extern "C" void f_80305778() {}
