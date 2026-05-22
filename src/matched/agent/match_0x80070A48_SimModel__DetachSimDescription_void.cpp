// 0x80070A48 SimModel::DetachSimDescription(void) (256 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-312(1); mfspr 0,8; stmw 30,0x130(1); stw 0,0x13c(1); mr 31,3; lwz 0,0x154(31); cmpwi 0,0; bne 2f; lwz 0,0x13c(31); cmpwi 0,0; beq 2f; addi 11,1,8; mr 9,0; mr 30,11; li 10,288; 0:; lwz 0,0x0(9); addic. 10,10,-24; stw 0,0x0(11); lwz 0,0x4(9); stw 0,0x4(11); lwz 0,0x8(9); stw 0,0x8(11); lwz 0,0xc(9); stw 0,0xc(11); lwz 0,0x10(9); stw 0,0x10(11); lwz 0,0x14(9); addi 9,9,24; stw 0,0x14(11); addi 11,11,24; bne 0b; lwz 0,0x0(9); li 3,292; stw 0,0x0(11); bl _s80070A48_0; bl _s80070A48_1; stw 3,0x13c(31); mr 11,30; li 0,288; 1:; lwz 9,0x0(11); addic. 0,0,-24; stw 9,0x0(3); lwz 9,0x4(11); stw 9,0x4(3); lwz 9,0x8(11); stw 9,0x8(3); lwz 9,0xc(11); stw 9,0xc(3); lwz 9,0x10(11); stw 9,0x10(3); lwz 9,0x14(11); addi 11,11,24; stw 9,0x14(3); addi 3,3,24; bne 1b; lwz 9,0x0(11); li 0,1; stw 9,0x0(3); stw 0,0x154(31); 2:; lwz 0,0x13c(1); mtspr 8,0; lmw 30,0x130(1); addi 1,1,312"
extern "C" void _s80070A48_0();
extern "C" void _s80070A48_1();
extern "C" void f_80070A48() {}
