// 0x801E714C EYETarget::SaveCurrentSetting(void) (256 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,3; lwz 0,0x98(31); cmpwi 0,3; beq 2f; bgt 0f; cmpwi 0,1; beq 4f; cmpwi 0,2; beq 1f; b 5f; 0:; cmpwi 0,4; beq 3f; cmpwi 0,5; bne 5f; lwz 9,0x88(31); addi 9,9,1; stw 9,0x88(31); bl _s801E714C_0; lis 9,-32764; stfs f1,0xa4(31); addi 9,9,-27964; stw 9,0xa8(31); b 6f; 1:; lwz 9,0x88(31); addi 9,9,1; stw 9,0x88(31); bl _s801E714C_1; lis 9,-32764; stfs f1,0xa4(31); addi 9,9,-27728; stw 9,0xa8(31); b 6f; 2:; lwz 9,0x88(31); addi 9,9,1; stw 9,0x88(31); bl _s801E714C_2; lis 9,-32764; stfs f1,0xa4(31); addi 9,9,-27836; stw 9,0xa8(31); b 6f; 3:; lwz 9,0x88(31); addi 9,9,1; stw 9,0x88(31); bl _s801E714C_3; lis 9,-32764; stfs f1,0xa4(31); addi 9,9,-27572; stw 9,0xa8(31); b 6f; 4:; lwz 9,0x88(31); addi 9,9,1; stw 9,0x88(31); 5:; li 0,0; stw 0,0xa8(31); 6:; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s801E714C_0();
extern "C" void _s801E714C_1();
extern "C" void _s801E714C_2();
extern "C" void _s801E714C_3();
extern "C" void f_801E714C() {}
