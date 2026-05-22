// 0x800B104C cSoundModeManager::StartBuildBuyMusic(void) (164 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,3; lwz 9,0x30(31); cmpwi 9,0; beq 0f; addi 0,9,1; cmpwi 0,2; stw 0,0x30(31); ble 1f; li 0,1; stw 0,0x30(31); b 1f; 0:; bl _s800B104C_0; lis 0,10922; srawi 9,3,31; ori 0,0,43691; mulhw 0,3,0; srawi 0,0,4; subf 0,9,0; mulli 0,0,96; subf 3,0,3; srawi 3,3,5; addi 3,3,1; stw 3,0x30(31); 1:; lwz 0,0x30(31); lis 9,-32702; addi 9,9,16412; lis 11,-32706; rlwinm 0,0,2,0,29; lfs f1,-26660(11); lwzx 4,9,0; mr 3,31; bl _s800B104C_1; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s800B104C_0();
extern "C" void _s800B104C_1();
extern "C" void f_800B104C() {}
