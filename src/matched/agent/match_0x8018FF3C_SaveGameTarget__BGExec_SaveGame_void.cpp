// 0x8018FF3C SaveGameTarget::BGExec_SaveGame(void (80 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr. 31,3; beq 0f; lwz 3,0x128(31); lis 6,171; li 4,1; li 5,0; ori 6,6,52719; bl _s8018FF3C_0; stw 3,0x13c(31); 0:; li 0,1; stw 0,-21480(13); lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s8018FF3C_0();
extern "C" void f_8018FF3C() {}
