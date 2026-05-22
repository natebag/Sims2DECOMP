// 0x8015AE1C ResourceBehaviorTree::LoadFromDataID(ObjectDataID (296 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 31,3; mr 29,4; lwz 9,0x0(29); addi 3,31,88; lwz 0,0x58(31); cmpw 9,0; bne 0f; lwz 0,0x60(31); cmpwi 0,0; beq 0f; lhz 30,0x4(29); bl _s8015AE1C_0; lwz 3,0x60(31); mr 4,30; bl _s8015AE1C_1; cmpwi 3,0; stw 3,0x54(31); beq 0f; li 3,1; b 5f; 0:; lwz 0,0x8(31); cmpwi 0,0; beq 2f; lwz 3,0x60(31); cmpwi 3,0; beq 1f; bl _s8015AE1C_2; li 0,0; stw 0,0x60(31); 1:; li 0,0; stw 0,0x8(31); stw 0,0x60(31); 2:; mr 4,29; addi 3,31,88; bl _s8015AE1C_3; lwz 11,-21508(13); lwz 4,0x0(29); lwz 9,0x0(11); lwz 0,0x3c(9); lha 3,0x38(9); mtspr 8,0; add 3,11,3; blrl; lwz 9,0x8(3); li 5,0; lis 3,-32693; li 6,0; lwz 4,0xc(9); addi 3,3,27900; bl _s8015AE1C_4; stw 3,0x60(31); cmpwi 3,0; beq 3f; lhz 4,0x4(29); bl _s8015AE1C_5; li 0,1; stw 3,0x54(31); stw 0,0x8(31); b 4f; 3:; stw 3,0x54(31); 4:; lwz 0,0x54(31); li 3,1; cmpwi 0,0; bne 5f; li 3,0; 5:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s8015AE1C_0();
extern "C" void _s8015AE1C_1();
extern "C" void _s8015AE1C_2();
extern "C" void _s8015AE1C_3();
extern "C" void _s8015AE1C_4();
extern "C" void _s8015AE1C_5();
extern "C" void f_8015AE1C() {}
