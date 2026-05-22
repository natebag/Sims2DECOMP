// 0x80021124 ECheatLookup::ECheatLookup(int, (164 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 26,0x8(1); stw 0,0x24(1); mr 31,3; mr 28,8; stw 4,0x4(31); mr 30,6; mr 4,5; mr 29,7; li 5,64; mr 26,9; mr 27,10; addi 3,31,8; bl _s80021124_0; li 0,0; stw 30,0x4c(31); stw 29,0x50(31); mr 3,28; stb 0,0x47(31); bl _s80021124_1; mr 3,28; bl _s80021124_2; addi 3,3,1; cmpwi 3,350; ble 0f; lis 9,-32707; addi 9,9,-6164; stw 9,0x48(31); b 1f; 0:; stw 28,0x48(31); 1:; li 0,0; stw 27,0x54(31); stw 26,0x58(31); mr 3,31; stw 0,0x5c(31); lwz 0,0x24(1); mtspr 8,0; lmw 26,0x8(1); addi 1,1,32"
extern "C" void _s80021124_0();
extern "C" void _s80021124_1();
extern "C" void _s80021124_2();
extern "C" void f_80021124() {}
