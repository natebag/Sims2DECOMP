// 0x801E4548 WAFTarget::OnTopBarTweenComplete(void) (112 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,3; lfs f13,0x27c(31); lfs f0,0x274(31); fcmpu 0,f13,f0; bne 0f; li 0,1; stw 0,0x268(31); 0:; lfs f0,0x27c(31); li 0,0; stw 0,0x264(31); mr 3,31; stfs f0,0x278(31); bl _s801E4548_0; lwz 0,0x26c(31); cmpwi 0,0; bne 1f; mr 3,31; bl _s801E4548_1; 1:; li 3,1; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s801E4548_0();
extern "C" void _s801E4548_1();
extern "C" void f_801E4548() {}
