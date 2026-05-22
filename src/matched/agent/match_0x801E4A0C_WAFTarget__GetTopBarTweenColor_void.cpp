// 0x801E4A0C WAFTarget::GetTopBarTweenColor(void) (240 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); lfs f13,0x278(3); li 31,0; lfs f0,0x274(3); ori 31,31,65280; li 0,1; fcmpu 0,f0,f13; bge 0f; li 0,0; 0:; bne 1f; lis 9,-32705; lfs f0,0x650c(9); fcmpu 7,f13,f0; beq cr7,1f; lis 9,-32705; lfs f0,0x6510(9); fcmpu 0,f13,f0; beq 1f; blt cr7,4f; lis 31,255; ori 31,31,65535; bge 4f; li 31,0; ori 31,31,65280; b 4f; 1:; cmpwi 0,0; beq 2f; lis 9,-32705; lfs f13,0x278(3); lfs f0,0x650c(9); lis 31,255; ori 31,31,65535; fcmpu 0,f13,f0; bge 3f; 2:; li 31,0; ori 31,31,65280; 3:; lwz 8,0x94(3); addi 30,3,592; lis 4,-32705; lis 7,-32705; addi 7,7,-8764; li 5,1; li 6,0; addi 4,4,25584; mr 3,30; bl _s801E4A0C_0; mr 3,30; mr 4,31; bl _s801E4A0C_1; mr 3,30; bl _s801E4A0C_2; 4:; mr 3,31; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s801E4A0C_0();
extern "C" void _s801E4A0C_1();
extern "C" void _s801E4A0C_2();
extern "C" void f_801E4A0C() {}
