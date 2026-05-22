// 0x800B1E00 ChainResFile::~ChainResFile(void) (152 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); lis 9,-32698; mr 30,3; addi 9,9,-5448; addic. 0,30,16; mr 28,4; stw 9,0xc(30); beq 3f; addi 31,30,208; cmpw 0,31; beq 3f; mr 29,0; 0:; addi 31,31,-24; mr 9,31; lwzu 3,0x4(9); cmpwi 3,0; beq 2f; lwz 0,0xc(9); subf 0,3,0; rlwinm 4,0,0,0,29; cmplwi 4,128; ble 1f; bl _s800B1E00_0; b 2f; 1:; bl _s800B1E00_1; 2:; cmpw 29,31; bne 0b; 3:; mr 3,30; mr 4,28; bl _s800B1E00_2; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s800B1E00_0();
extern "C" void _s800B1E00_1();
extern "C" void _s800B1E00_2();
extern "C" void f_800B1E00() {}
