// 0x802A888C AptLoadVars::AptLoadVars(void) (116 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 30,3; li 4,35; bl _s802A888C_0; lis 9,-32703; addi 3,30,12; addi 9,9,8984; li 4,8; stw 9,0x8(30); bl _s802A888C_1; li 0,0; lis 9,-32703; stb 0,0x20(30); addi 9,9,-20328; li 11,0; stw 9,0x8(30); lwz 0,0x20(30); mr 3,30; stw 11,0x24(30); rlwinm 0,0,0,10,7; stw 0,0x20(30); lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s802A888C_0();
extern "C" void _s802A888C_1();
extern "C" void f_802A888C() {}
