// 0x80285A2C AptArray::AptArray(void) (124 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 30,3; li 4,22; bl _s80285A2C_0; lis 9,-32703; addi 3,30,12; addi 9,9,8984; li 4,8; stw 9,0x8(30); bl _s80285A2C_1; li 0,0; lis 9,-32704; stb 0,0x20(30); li 11,0; addi 9,9,16352; mr 3,30; lwz 0,0x20(30); stw 9,0x8(30); rlwinm 0,0,0,10,7; stw 11,0x2c(30); stw 11,0x28(30); stw 0,0x20(30); stw 11,0x24(30); lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s80285A2C_0();
extern "C" void _s80285A2C_1();
extern "C" void f_80285A2C() {}
