// 0x80193F2C CASTarget::UnloadLastScreen(void) (132 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 31,3; lis 9,-32697; lwz 4,0x90(31); li 29,0; lwz 30,0x5f10(9); cmpwi 4,0; beq 0f; mr 3,30; bl _s80193F2C_0; cmpwi 3,0; bne 1f; lwz 4,0x90(31); mr 3,30; bl _s80193F2C_1; cmpwi 3,0; bne 1f; lwz 4,0x90(31); mr 3,30; bl _s80193F2C_2; lwz 0,0x90(31); stw 29,0x90(31); stw 0,0x94(31); 0:; li 29,1; 1:; mr 3,29; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s80193F2C_0();
extern "C" void _s80193F2C_1();
extern "C" void _s80193F2C_2();
extern "C" void f_80193F2C() {}
