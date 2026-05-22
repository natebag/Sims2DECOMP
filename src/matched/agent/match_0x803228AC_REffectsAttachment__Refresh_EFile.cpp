// 0x803228AC REffectsAttachment::Refresh(EFile (232 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-48(1); mfspr 0,8; stmw 30,0x28(1); stw 0,0x34(1); mr 31,3; mr. 30,4; beq 4f; li 0,0; addi 6,1,8; stw 0,0x8(1); addi 8,6,8; stw 0,0x4(6); addi 7,31,28; stw 0,0x4(8); lwz 0,0x18(31); lwz 9,0x14(31); lwz 11,0x8(1); lwz 10,0xc(1); stw 9,0x8(1); stw 0,0xc(1); stw 11,0x14(31); lwz 0,0x4(8); stw 10,0x18(31); stw 0,0x24(1); lwz 9,0x1c(31); lwz 0,0x4(7); stw 9,0x8(6); stw 0,0x4(8); lwz 9,0x20(1); lwz 0,0x24(1); stw 9,0x1c(31); stw 0,0x4(7); lwz 0,0x4(6); lwz 9,0x8(1); cmpw 9,0; beq 1f; 0:; addi 9,9,8; cmpw 9,0; bne 0b; 1:; lwz 3,0x0(6); cmpwi 3,0; beq 3f; lwz 0,0xc(6); subf 0,3,0; rlwinm 4,0,0,0,28; cmplwi 4,128; ble 2f; bl _s803228AC_0; b 3f; 2:; bl _s803228AC_1; 3:; mr 3,31; mr 4,30; bl _s803228AC_2; 4:; lwz 0,0x34(1); mtspr 8,0; lmw 30,0x28(1); addi 1,1,48"
extern "C" void _s803228AC_0();
extern "C" void _s803228AC_1();
extern "C" void _s803228AC_2();
extern "C" void f_803228AC() {}
