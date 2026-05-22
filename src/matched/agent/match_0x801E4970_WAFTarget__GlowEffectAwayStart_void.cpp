// 0x801E4970 WAFTarget::GlowEffectAwayStart(void) (144 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 30,3; bl _s801E4970_0; lwz 0,0x26c(30); cmpwi 0,0; beq 0f; lis 9,-32705; lfs f13,0x278(30); lfs f0,0x6508(9); fcmpu 0,f13,f0; bne 0f; li 0,0; stw 0,0x270(30); b 1f; 0:; lwz 8,0x94(30); lis 4,-32705; addi 30,30,592; lwz 7,-29196(13); addi 4,4,25520; mr 3,30; li 5,500; li 6,0; bl _s801E4970_1; mr 3,30; li 4,0; bl _s801E4970_2; mr 3,30; bl _s801E4970_3; 1:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s801E4970_0();
extern "C" void _s801E4970_1();
extern "C" void _s801E4970_2();
extern "C" void _s801E4970_3();
extern "C" void f_801E4970() {}
