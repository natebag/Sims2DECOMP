// 0x8000D724 AptWord::InsertSpace(void) (264 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 30,0x10(1); stw 0,0x1c(1); mr 31,3; lwz 3,0x8(31); bl _s8000D724_0; addi 30,3,2; bl _s8000D724_1; li 5,0; rlwinm 4,30,1,0,30; bl _s8000D724_2; mr 30,3; lwz 4,0x8(31); bl _s8000D724_3; lis 4,-32707; mr 3,30; addi 4,4,-10492; bl _s8000D724_4; bl _s8000D724_5; lwz 4,0x8(31); bl _s8000D724_6; lwz 11,0xc(31); stw 30,0x8(31); cmpwi 11,0; beq 1f; lwz 0,0x0(11); cmpwi 0,0; bne 0f; lwz 0,0xc(11); cmpwi 0,0; beq 1f; 0:; lis 9,-32707; lfs f1,0x24(11); lfs f2,-10488(9); li 4,1; lwz 3,-32708(13); bl _s8000D724_7; 1:; lwz 4,-32708(13); addi 3,1,8; lwz 5,0x8(31); li 6,1; li 7,0; li 8,0; bl _s8000D724_8; lwz 0,0x8(1); lwz 9,0xc(1); lwz 11,0x10(31); stw 0,0x24(31); cmpwi 11,0; stw 9,0x28(31); beq 2f; lwz 0,0x0(11); cmpwi 0,0; beq 2f; lis 9,-32707; lfs f1,0x24(11); lfs f2,-10488(9); li 4,1; lwz 3,-32708(13); bl _s8000D724_9; 2:; lwz 0,0x1c(1); mtspr 8,0; lmw 30,0x10(1); addi 1,1,24"
extern "C" void _s8000D724_0();
extern "C" void _s8000D724_1();
extern "C" void _s8000D724_2();
extern "C" void _s8000D724_3();
extern "C" void _s8000D724_4();
extern "C" void _s8000D724_5();
extern "C" void _s8000D724_6();
extern "C" void _s8000D724_7();
extern "C" void _s8000D724_8();
extern "C" void _s8000D724_9();
extern "C" void f_8000D724() {}
