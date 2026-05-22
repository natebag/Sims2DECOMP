// 0x8015AF44 ResourceBehaviorTree::GetFromDataID(ObjectDataID (296 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 31,3; mr 30,4; lwz 0,0x8(31); cmpwi 0,0; beq 1f; lwz 3,0x60(31); cmpwi 3,0; beq 0f; bl _s8015AF44_0; li 0,0; stw 0,0x60(31); 0:; li 0,0; stw 0,0x8(31); stw 0,0x60(31); 1:; lwz 11,-21508(13); lwz 4,0x0(30); lwz 9,0x0(11); lwz 0,0x19c(9); lha 3,0x198(9); mtspr 8,0; add 3,11,3; blrl; mr 29,3; bl _s8015AF44_1; stw 3,0x60(31); mr 4,30; addi 3,31,88; bl _s8015AF44_2; lwz 0,0x60(31); cmpwi 0,0; bne 2f; lwz 11,-21508(13); lwz 4,0x0(30); lwz 9,0x0(11); lwz 0,0x3c(9); lha 3,0x38(9); mtspr 8,0; add 3,11,3; blrl; lwz 9,0x8(3); lis 3,-32693; lwz 4,0xc(9); addi 3,3,27900; bl _s8015AF44_3; mr 0,3; mr 4,0; stw 0,0x60(31); mr 3,29; bl _s8015AF44_4; lwz 0,0x60(31); cmpwi 0,0; beq 3f; 2:; lhz 4,0x4(30); lwz 3,0x60(31); bl _s8015AF44_5; li 0,0; stw 3,0x54(31); stw 0,0x8(31); b 4f; 3:; stw 0,0x54(31); 4:; lwz 0,0x54(31); li 3,1; cmpwi 0,0; bne 5f; li 3,0; 5:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s8015AF44_0();
extern "C" void _s8015AF44_1();
extern "C" void _s8015AF44_2();
extern "C" void _s8015AF44_3();
extern "C" void _s8015AF44_4();
extern "C" void _s8015AF44_5();
extern "C" void f_8015AF44() {}
