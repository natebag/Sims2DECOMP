// 0x8001E87C __static_initialization_and_destruction_0 (200 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); li 0,0; ori 0,0,65535; cmpw 4,0; bne 4f; cmpwi 3,0; beq 1f; lis 3,-32697; li 30,1; addi 3,3,13588; bl _s8001E87C_0; lis 9,-32697; addi 31,9,13784; 0:; mr 3,31; bl _s8001E87C_1; addi 31,31,456; cmpwi 30,0; addi 30,30,-1; bne 0b; b 4f; 1:; lis 9,-32697; addi 9,9,13784; cmpwi 9,0; beq 3f; addi 31,9,912; cmpw 31,9; beq 3f; mr 30,9; 2:; addi 31,31,-456; li 4,0; lwz 9,0x1c4(31); lha 3,0x8(9); lwz 0,0xc(9); add 3,31,3; mtspr 8,0; blrl; cmpw 31,30; bne 2b; 3:; lis 9,-32698; lis 11,-32697; addi 9,9,-20984; stw 9,0x35d4(11); 4:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s8001E87C_0();
extern "C" void _s8001E87C_1();
extern "C" void f_8001E87C() {}
