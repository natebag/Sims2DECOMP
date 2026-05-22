// 0x8025EFEC DVDChangeDiskAsync (272 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-48(1); stw 31,0x2c(1); mr 31,4; stw 30,0x28(1); addi 30,5,0; stw 29,0x24(1); addi 29,3,0; lbz 0,0x4(4); extsb. 0,0; bne 0f; lis 3,-32700; crxor 6,6,6; addi 3,3,-14360; bl _s8025EFEC_0; crxor 6,6,6; addi 3,13,-27780; li 4,2902; addi 5,13,-27768; bl _s8025EFEC_1; 0:; li 0,3; stw 0,0x8(29); stw 31,0x24(29); stw 30,0x28(29); lwz 4,-23472(13); lwz 3,0x38(4); lwz 4,0x3c(4); bl _s8025EFEC_2; lwz 0,-27788(13); cmpwi 0,0; beq 2f; lwz 3,0x8(29); cmplwi 3,1; beq 1f; addi 0,3,-4; cmplwi 0,1; ble 1f; cmplwi 3,14; bne 2f; 1:; lwz 3,0x18(29); lwz 4,0x14(29); bl _s8025EFEC_3; 2:; bl _s8025EFEC_4; li 0,2; stw 0,0xc(29); addi 30,3,0; addi 4,29,0; li 3,2; bl _s8025EFEC_5; lwz 0,-23480(13); addi 31,3,0; cmplwi 0,0; bne 3f; lwz 0,-23468(13); cmpwi 0,0; bne 3f; bl _s8025EFEC_6; 3:; mr 3,30; bl _s8025EFEC_7; mr 3,31; lwz 0,0x34(1); lwz 31,0x2c(1); lwz 30,0x28(1); lwz 29,0x24(1); addi 1,1,48; mtspr 8,0"
extern "C" void _s8025EFEC_0();
extern "C" void _s8025EFEC_1();
extern "C" void _s8025EFEC_2();
extern "C" void _s8025EFEC_3();
extern "C" void _s8025EFEC_4();
extern "C" void _s8025EFEC_5();
extern "C" void _s8025EFEC_6();
extern "C" void _s8025EFEC_7();
extern "C" void f_8025EFEC() {}
