// 0x802A8988 AptError::AptError(EAStringC) (152 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 30,3; mr 29,4; li 4,41; bl _s802A8988_0; lis 9,-32703; li 4,8; addi 9,9,8984; addi 3,30,12; stw 9,0x8(30); bl _s802A8988_1; li 0,0; lis 9,-32703; stb 0,0x20(30); addi 9,9,-20464; stw 9,0x8(30); mr 4,29; lwz 0,0x20(30); addi 3,30,36; rlwinm 0,0,0,10,7; stw 0,0x20(30); bl _s802A8988_2; lis 4,-32703; addi 3,30,40; addi 4,4,-23292; bl _s802A8988_3; mr 3,29; li 4,2; bl _s802A8988_4; mr 3,30; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s802A8988_0();
extern "C" void _s802A8988_1();
extern "C" void _s802A8988_2();
extern "C" void _s802A8988_3();
extern "C" void _s802A8988_4();
extern "C" void f_802A8988() {}
