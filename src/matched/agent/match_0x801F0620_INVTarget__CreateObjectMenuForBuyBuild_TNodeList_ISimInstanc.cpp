// 0x801F0620 INVTarget::CreateObjectMenuForBuyBuild(TNodeList<ISimInstance (204 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-48(1); mfspr 0,8; stmw 27,0x1c(1); stw 0,0x34(1); lwz 4,0x0(4); cmpwi 4,0; bne 0f; li 3,0; b 3f; 0:; mr 31,4; addi 29,3,12700; addi 27,1,16; li 28,0; 1:; lwz 3,0x0(31); bl _s801F0620_0; mr 30,3; bl _s801F0620_1; mr 4,3; addi 3,1,8; bl _s801F0620_2; mr 4,27; stw 28,0x10(1); mr 3,30; bl _s801F0620_3; mr 7,3; lwz 8,0x10(1); mr 3,29; mr 4,30; li 5,0; addi 6,1,8; li 9,0; bl _s801F0620_4; lwz 3,0x10(1); cmpwi 3,0; beq 2f; bl _s801F0620_5; stw 28,0x10(1); 2:; lwz 31,0x8(31); addi 3,1,8; li 4,2; bl _s801F0620_6; cmpwi 31,0; bne 1b; mr 3,29; bl _s801F0620_7; li 3,1; 3:; lwz 0,0x34(1); mtspr 8,0; lmw 27,0x1c(1); addi 1,1,48"
extern "C" void _s801F0620_0();
extern "C" void _s801F0620_1();
extern "C" void _s801F0620_2();
extern "C" void _s801F0620_3();
extern "C" void _s801F0620_4();
extern "C" void _s801F0620_5();
extern "C" void _s801F0620_6();
extern "C" void _s801F0620_7();
extern "C" void f_801F0620() {}
