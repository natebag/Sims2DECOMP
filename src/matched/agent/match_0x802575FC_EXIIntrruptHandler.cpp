// 0x802575FC EXIIntrruptHandler (200 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-760(1); stw 31,0x2f4(1); stw 30,0x2f0(1); stw 29,0x2ec(1); addi 31,4,0; extsh 3,3; addi 0,3,-9; lis 3,21845; addi 3,3,21846; mulhw 3,3,0; rlwinm 0,3,1,31,31; add 30,3,0; mulli 0,30,20; lis 3,-13312; addi 3,3,26624; add 3,3,0; lwz 0,0x0(3); andi. 0,0,2037; ori 0,0,2; stw 0,0x0(3); rlwinm 4,30,6,0,25; lis 3,-32694; addi 0,3,-22064; add 3,0,4; lwz 0,0x0(3); mr 29,0; cmplwi 0,0; beq 0f; addi 3,1,24; bl _s802575FC_0; addi 3,1,24; bl _s802575FC_1; addi 3,30,0; addi 4,31,0; addi 12,29,0; mtspr 8,12; blrl; addi 3,1,24; bl _s802575FC_2; mr 3,31; bl _s802575FC_3; 0:; lwz 0,0x2fc(1); lwz 31,0x2f4(1); lwz 30,0x2f0(1); lwz 29,0x2ec(1); addi 1,1,760; mtspr 8,0"
extern "C" void _s802575FC_0();
extern "C" void _s802575FC_1();
extern "C" void _s802575FC_2();
extern "C" void _s802575FC_3();
extern "C" void f_802575FC() {}
