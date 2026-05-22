// 0x802A8900 AptError::AptError(void) (136 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 30,3; li 4,41; lis 29,-32703; bl _s802A8900_0; lis 9,-32703; li 4,8; addi 9,9,8984; addi 3,30,12; stw 9,0x8(30); bl _s802A8900_1; li 0,0; lis 9,-32703; stb 0,0x20(30); addi 9,9,-20464; stw 9,0x8(30); addi 4,29,-23292; lwz 0,0x20(30); addi 3,30,36; rlwinm 0,0,0,10,7; stw 0,0x20(30); bl _s802A8900_2; addi 4,29,-23292; addi 3,30,40; bl _s802A8900_3; mr 3,30; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s802A8900_0();
extern "C" void _s802A8900_1();
extern "C" void _s802A8900_2();
extern "C" void _s802A8900_3();
extern "C" void f_802A8900() {}
