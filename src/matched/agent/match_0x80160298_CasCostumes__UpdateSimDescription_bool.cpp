// 0x80160298 CasCostumes::UpdateSimDescription(bool, (288 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-56(1); mfspr 0,8; mfcr 12; stmw 30,0x30(1); stw 0,0x3c(1); stw 12,0x2c(1); cmpwi 4,4,0; mr 30,6; mfcr 9; rlwinm 9,9,23,27,27; lwzx 11,9,3; add 9,9,3; lwz 0,0x4(9); subf 0,11,0; srawi 0,0,2; cmplw 5,0; blt 0f; li 3,0; b 4f; 0:; rlwinm 9,5,2,0,29; addi 4,1,8; lwzx 31,11,9; li 5,32; addi 3,31,4; bl _s80160298_0; mr 6,30; mr 9,31; li 11,288; 1:; lwz 0,0x0(6); addic. 11,11,-24; stw 0,0x0(9); lwz 0,0x4(6); stw 0,0x4(9); lwz 0,0x8(6); stw 0,0x8(9); lwz 0,0xc(6); stw 0,0xc(9); lwz 0,0x10(6); stw 0,0x10(9); lwz 0,0x14(6); addi 6,6,24; stw 0,0x14(9); addi 9,9,24; bne 1b; lwz 0,0x0(6); addi 3,1,8; addi 4,31,4; li 5,32; stw 0,0x0(9); bl _s80160298_1; beq cr4,2f; lis 3,-32706; addi 4,31,68; addi 3,3,-4564; li 5,32; bl _s80160298_2; b 3f; 2:; lis 3,-32706; addi 4,31,68; addi 3,3,-4556; li 5,32; bl _s80160298_3; 3:; li 0,0; li 3,1; stw 0,0x118(31); 4:; lwz 0,0x3c(1); lwz 12,0x2c(1); mtspr 8,0; lmw 30,0x30(1); mtcrf 8,12; addi 1,1,56"
extern "C" void _s80160298_0();
extern "C" void _s80160298_1();
extern "C" void _s80160298_2();
extern "C" void _s80160298_3();
extern "C" void f_80160298() {}
