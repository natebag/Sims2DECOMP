// 0x801E4858 WAFTarget::GlowEffectStart(void) (280 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,3; lwz 0,0x270(31); cmpwi 0,0; bne 1f; lwz 0,0x26c(31); cmpwi 0,0; bne 2f; lis 9,-32705; lfs f13,0x278(31); lfs f0,0x6500(9); fcmpu 0,f13,f0; bne 1f; lwz 8,0x94(31); addi 30,31,592; lis 4,-32705; lis 7,-32705; addi 7,7,-8764; li 5,1; li 6,0; addi 4,4,25520; mr 3,30; bl _s801E4858_0; mr 3,30; li 4,0; bl _s801E4858_1; mr 3,30; bl _s801E4858_2; 0:; li 3,0; b 5f; 1:; lwz 0,0x26c(31); cmpwi 0,0; beq 0b; 2:; lwz 0,0x270(31); cmpwi 0,0; bne 0b; lis 9,-32705; lfs f13,0x278(31); lfs f0,0x6504(9); fcmpu 0,f13,f0; beq 3f; lis 9,-32705; lfs f0,0x6500(9); fcmpu 0,f13,f0; bne 4f; 3:; addi 30,31,592; lwz 7,-29208(13); lwz 8,0x94(31); lis 4,-32705; li 5,500; li 6,0; addi 4,4,25520; mr 3,30; bl _s801E4858_3; mr 3,30; li 4,255; bl _s801E4858_4; mr 3,30; bl _s801E4858_5; li 0,1; stw 0,0x270(31); 4:; li 3,1; 5:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s801E4858_0();
extern "C" void _s801E4858_1();
extern "C" void _s801E4858_2();
extern "C" void _s801E4858_3();
extern "C" void _s801E4858_4();
extern "C" void _s801E4858_5();
extern "C" void f_801E4858() {}
