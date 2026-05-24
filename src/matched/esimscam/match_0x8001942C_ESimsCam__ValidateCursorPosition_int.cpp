// 0x8001942C ESimsCam::ValidateCursorPosition(int, (508 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-104(1); mfspr 0,8; stmw 24,0x48(1); stw 0,0x6c(1); mr 31,3; mr 24,5; lis 30,-32707; bl _s8001942C_0; addi 26,31,864; lis 4,-32697; addi 3,31,16; addi 4,4,13588; mr 5,26; stfs f1,0x84(4); lfs f1,-7188(30); addi 4,4,128; bl _s8001942C_1; lfs f13,-7188(30); lfs f0,0x8(26); fcmpu 0,f0,f13; bge 0f; addi 25,31,876; lfs f0,0x8(25); fcmpu 0,f0,f13; bge 0f; lwz 0,0x360(31); addi 30,1,8; lwz 9,0x4(26); addi 29,1,24; lwz 11,0x8(26); mr 3,31; stw 0,0x8(1); addi 28,31,900; stw 9,0x4(30); addi 27,31,888; stw 11,0x8(30); stfs f13,0x10(1); lwz 0,0x8(1); lwz 9,0x4(30); lwz 11,0x8(30); stw 0,0x360(31); stw 9,0x4(26); stw 11,0x8(26); lwz 0,0x36c(31); lwz 9,0x4(25); lwz 11,0x8(25); stw 0,0x8(1); stw 9,0x4(30); stw 11,0x8(30); stfs f13,0x10(1); lwz 0,0x8(1); lwz 9,0x4(30); lwz 11,0x8(30); stw 0,0x36c(31); stw 9,0x4(25); stw 11,0x8(25); bl _s8001942C_2; lfs f10,0x360(31); mr 3,31; lfs f11,0x4(26); lfs f9,0x8(26); fmuls f10,f1,f10; lfs f13,0x384(31); fmuls f11,f1,f11; lfs f12,0x8(28); fmuls f1,f1,f9; lfs f0,0x4(28); fadds f13,f13,f10; stfs f13,0x18(1); fadds f12,f12,f1; fadds f0,f0,f11; stfs f12,0x20(1); stfs f0,0x1c(1); stfs f10,0x28(1); stfs f11,0x2c(1); stfs f1,0x30(1); lwz 0,0x18(1); lwz 11,0x4(29); lwz 9,0x8(29); stw 0,0x8(1); stw 11,0x4(30); stw 9,0x8(30); lwz 0,0x8(1); stw 0,0x360(31); stw 9,0x8(26); stw 11,0x4(26); bl _s8001942C_3; lfs f10,0x36c(31); lfs f11,0x4(25); lfs f9,0x8(25); fmuls f10,f1,f10; lfs f13,0x378(31); fmuls f11,f1,f11; lfs f12,0x8(27); fmuls f1,f1,f9; lfs f0,0x4(27); fadds f13,f13,f10; stfs f13,0x18(1); fadds f12,f12,f1; fadds f0,f0,f11; stfs f12,0x20(1); stfs f0,0x1c(1); stfs f10,0x38(1); stfs f11,0x3c(1); stfs f1,0x40(1); lwz 0,0x18(1); lwz 9,0x8(29); lwz 11,0x4(29); stw 0,0x8(1); stw 9,0x8(30); stw 11,0x4(30); lwz 0,0x8(1); stw 0,0x36c(31); stw 9,0x8(25); stw 11,0x4(25); 0:; lis 9,-32697; lwz 0,0x3540(9); cmpwi 0,0; bne 1f; addi 3,31,864; mr 4,24; bl _s8001942C_4; 1:; lwz 0,0x6c(1); mtspr 8,0; lmw 24,0x48(1); addi 1,1,104"

extern "C" void _s8001942C_0();
extern "C" void _s8001942C_1();
extern "C" void _s8001942C_2();
extern "C" void _s8001942C_3();
extern "C" void _s8001942C_4();

struct ESimsCam {
    void ValidateCursorPosition();
};

void ESimsCam::ValidateCursorPosition() {
}
