// 0x802B5C2C AptGlobal::AptGlobal(void) (120 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 30,3; li 4,25; bl _s802B5C2C_0; lis 9,-32703; li 4,11; addi 9,9,8984; addi 3,30,12; stw 9,0x8(30); bl _s802B5C2C_1; li 0,0; lis 9,-32703; stb 0,0x20(30); addi 9,9,18472; mr 3,30; stw 9,0x8(30); lwz 0,0x20(30); li 4,1; rlwinm 0,0,0,10,7; stw 0,0x20(30); bl _s802B5C2C_2; mr 3,30; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s802B5C2C_0();
extern "C" void _s802B5C2C_1();
extern "C" void _s802B5C2C_2();
extern "C" void f_802B5C2C() {}
