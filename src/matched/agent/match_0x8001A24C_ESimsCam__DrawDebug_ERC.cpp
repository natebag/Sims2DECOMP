// 0x8001A24C ESimsCam::DrawDebug(ERC (108 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); lis 9,-32697; mr 30,3; addi 29,9,13588; mr 31,4; lwz 0,0x78(29); cmpwi 0,0; beq 0f; addi 3,30,864; lis 5,16512; bl _s8001A24C_0; 0:; lwz 0,0xa4(29); cmpwi 0,0; beq 1f; lis 5,16384; addi 3,30,912; mr 4,31; ori 5,5,128; bl _s8001A24C_1; 1:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s8001A24C_0();
extern "C" void _s8001A24C_1();
extern "C" void f_8001A24C() {}
