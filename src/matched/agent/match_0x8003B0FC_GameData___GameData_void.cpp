// 0x8003B0FC GameData::~GameData(void) (232 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,3; mr 30,4; lwz 11,0x54(31); cmpwi 11,0; beq 0f; lwz 9,0x80(11); li 4,3; lha 3,0x8(9); lwz 0,0xc(9); add 3,11,3; mtspr 8,0; blrl; 0:; lwz 11,0x6c(31); cmpwi 11,0; beq 1f; lwz 9,0x80(11); li 4,3; lha 3,0x8(9); lwz 0,0xc(9); add 3,11,3; mtspr 8,0; blrl; 1:; lwz 11,0x70(31); cmpwi 11,0; beq 2f; lwz 9,0x80(11); li 4,3; lha 3,0x8(9); lwz 0,0xc(9); add 3,11,3; mtspr 8,0; blrl; 2:; lwz 11,0x74(31); cmpwi 11,0; beq 3f; lwz 9,0x80(11); li 4,3; lha 3,0x8(9); lwz 0,0xc(9); add 3,11,3; mtspr 8,0; blrl; 3:; addi 3,31,4; li 4,2; bl _s8003B0FC_0; andi. 0,30,1; beq 4f; mr 3,31; bl _s8003B0FC_1; 4:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s8003B0FC_0();
extern "C" void _s8003B0FC_1();
extern "C" void f_8003B0FC() {}
