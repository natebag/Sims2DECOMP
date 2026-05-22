// 0x801E460C WAFTarget::GetTopBarColorAtTier(void) (160 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); lis 9,-32705; lfs f13,0x278(3); lfs f0,0x64bc(9); li 31,0; ori 31,31,65280; fcmpu 0,f13,f0; beq 0f; lis 9,-32705; lis 31,255; lfs f0,0x64c0(9); ori 31,31,65535; fcmpu 0,f13,f0; bne 0f; li 31,0; ori 31,31,65280; 0:; lwz 8,0x94(3); addi 30,3,592; lis 4,-32705; lis 7,-32705; addi 7,7,-8764; li 5,1; li 6,0; addi 4,4,25584; mr 3,30; bl _s801E460C_0; mr 3,30; mr 4,31; bl _s801E460C_1; mr 3,30; bl _s801E460C_2; mr 3,31; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s801E460C_0();
extern "C" void _s801E460C_1();
extern "C" void _s801E460C_2();
extern "C" void f_801E460C() {}
