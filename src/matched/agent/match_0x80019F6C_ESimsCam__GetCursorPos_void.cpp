// 0x80019F6C ESimsCam::GetCursorPos(void) (160 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 29,0x1c(1); stw 0,0x2c(1); lis 9,-32707; addi 31,1,8; lfs f0,-7128(9); mr 29,4; mr 30,3; stfs f0,0x8(31); stfs f0,0x4(31); stfs f0,0x8(1); bl _s80019F6C_0; lwz 4,0x4(29); li 5,-1; bl _s80019F6C_1; mr. 3,3; beq 0f; lwz 11,0x8(3); addi 9,3,8; lwz 10,0x8(9); lwz 0,0x4(9); stw 11,0x8(1); stw 0,0x4(31); stw 10,0x8(31); 0:; lwz 9,0x0(29); mr 3,30; lfs f0,0x8(1); lfs f13,0x8c(9); stfs f0,0x0(30); stfs f13,0x10(1); lfs f0,0x8(31); lfs f13,0x4(31); stfs f0,0x8(30); stfs f13,0x4(30); lwz 0,0x2c(1); mtspr 8,0; lmw 29,0x1c(1); addi 1,1,40"
extern "C" void _s80019F6C_0();
extern "C" void _s80019F6C_1();
extern "C" void f_80019F6C() {}
