// 0x801FF700 PSETarget::GetVariable(char (188 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 30,4; li 3,128; bl _s801FF700_0; mr 31,3; li 0,0; lis 4,-32704; stb 0,0x0(31); addi 4,4,-19672; mr 3,30; bl _s801FF700_1; cmpwi 3,0; bne 0f; lis 9,-32704; addi 11,9,-30832; lwz 10,-30832(9); lbz 8,0x6(11); lhz 0,0x4(11); stw 10,0x0(31); sth 0,0x4(31); stb 8,0x6(31); b 2f; 0:; lis 4,-32704; mr 3,30; addi 4,4,-19660; bl _s801FF700_2; cmpwi 3,0; bne 2f; lis 3,-32697; addi 3,3,24012; bl _s801FF700_3; cmpwi 3,0; li 0,48; beq 1f; li 0,49; 1:; stb 0,0x0(31); li 0,0; stb 0,0x1(31); 2:; mr 3,31; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s801FF700_0();
extern "C" void _s801FF700_1();
extern "C" void _s801FF700_2();
extern "C" void _s801FF700_3();
extern "C" void f_801FF700() {}
