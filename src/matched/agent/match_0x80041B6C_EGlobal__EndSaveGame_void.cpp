// 0x80041B6C EGlobal::EndSaveGame(void) (48 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lis 9,-32697; lwz 3,0x5e94(9); cmpwi 3,0; beq 0f; bl _s80041B6C_0; 0:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s80041B6C_0();
extern "C" void f_80041B6C() {}
