// 0x8036B2E8 RParticle::RParticle(void) (100 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,3; bl _s8036B2E8_0; lis 9,-32697; li 10,8; addi 9,9,-7864; li 0,0; mtspr 9,10; stw 9,0x0(31); stw 0,0x18(31); li 11,0; stw 0,0x14(31); addi 9,31,56; 0:; stw 11,0x0(9); addi 9,9,-4; bdnz 0b; mr 3,31; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s8036B2E8_0();
extern "C" void f_8036B2E8() {}
