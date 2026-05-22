// 0x8003FB0C EGlobal::HouseNameText(char (112 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,3; mr. 30,5; beq 0f; lwz 3,0xe8(4); lis 4,-32707; addi 4,4,10132; bl _s8003FB0C_0; mr 4,3; lis 9,-32697; lwz 3,0x5eb4(9); mr 5,30; bl _s8003FB0C_1; mr. 3,3; beq 0f; lwz 0,0x0(3); b 1f; 0:; lwz 0,-24988(13); 1:; stw 0,0x0(31); mr 3,31; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s8003FB0C_0();
extern "C" void _s8003FB0C_1();
extern "C" void f_8003FB0C() {}
