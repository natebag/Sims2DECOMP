// 0x8015B524 IFFBehaviorTree::LoadFromDataID(ObjectDataID (248 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 28,0x10(1); stw 0,0x24(1); mr 31,4; mr 28,3; addi 3,28,88; bl _s8015B524_0; lwz 3,-21508(13); lwz 4,0x0(31); lwz 9,0x0(3); lha 0,0x38(9); lwz 9,0x3c(9); add 3,3,0; mtspr 8,9; blrl; mr. 29,3; beq 0f; lwz 9,0xc(29); lis 4,16968; lha 5,0x4(31); ori 4,4,16726; lha 3,0x80(9); li 6,0; lwz 0,0x84(9); add 3,29,3; mtspr 8,0; blrl; mr. 31,3; beq 0f; lwz 0,0x4(31); li 30,0; stw 30,0x8(28); mr 4,31; stw 0,0x54(28); addi 5,28,12; lwz 9,0xc(29); lwz 0,0xa4(9); lha 3,0xa0(9); mtspr 8,0; add 3,29,3; blrl; lwz 9,0xc(29); mr 4,31; sth 30,0x8(1); addi 5,1,8; lha 3,0xb0(9); lwz 0,0xb4(9); add 3,29,3; mtspr 8,0; blrl; lha 4,0x8(1); mr 3,28; bl _s8015B524_1; li 3,1; b 1f; 0:; li 3,0; 1:; lwz 0,0x24(1); mtspr 8,0; lmw 28,0x10(1); addi 1,1,32"
extern "C" void _s8015B524_0();
extern "C" void _s8015B524_1();
extern "C" void f_8015B524() {}
