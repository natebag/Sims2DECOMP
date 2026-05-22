// 0x802606A8 DVDCompareDiskID (248 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-24(1); stw 31,0x14(1); addi 31,4,0; stw 30,0x10(1); mr 30,3; lbz 0,0x0(3); extsb. 0,0; beq 0f; lbz 0,0x0(31); extsb. 0,0; beq 0f; addi 3,30,0; addi 4,31,0; li 5,4; bl _s802606A8_0; cmpwi 3,0; beq 0f; li 3,0; b 5f; 0:; lbz 0,0x4(30); extsb. 0,0; beq 1f; lbz 0,0x4(31); extsb. 0,0; beq 1f; addi 3,30,4; addi 4,31,4; li 5,2; bl _s802606A8_1; cmpwi 3,0; beq 2f; 1:; li 3,0; b 5f; 2:; lbz 3,0x6(30); cmplwi 3,255; beq 3f; lbz 0,0x6(31); cmplwi 0,255; beq 3f; cmplw 3,0; beq 3f; li 3,0; b 5f; 3:; lbz 3,0x7(30); cmplwi 3,255; beq 4f; lbz 0,0x7(31); cmplwi 0,255; beq 4f; cmplw 3,0; beq 4f; li 3,0; b 5f; 4:; li 3,1; 5:; lwz 0,0x1c(1); lwz 31,0x14(1); lwz 30,0x10(1); addi 1,1,24; mtspr 8,0"
extern "C" void _s802606A8_0();
extern "C" void _s802606A8_1();
extern "C" void f_802606A8() {}
