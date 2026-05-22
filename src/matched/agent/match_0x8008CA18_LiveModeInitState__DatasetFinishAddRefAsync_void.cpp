// 0x8008CA18 LiveModeInitState::DatasetFinishAddRefAsync(void) (64 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 30,3; lis 3,-32693; lwz 4,0x1c(30); addi 3,3,24536; bl _s8008CA18_0; li 0,0; stw 0,0x1c(30); lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s8008CA18_0();
extern "C" void f_8008CA18() {}
