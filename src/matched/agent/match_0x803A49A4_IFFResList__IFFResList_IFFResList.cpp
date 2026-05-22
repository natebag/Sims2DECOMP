// 0x803A49A4 IFFResList::IFFResList(IFFResList (300 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-48(1); mfspr 0,8; stmw 25,0x14(1); stw 0,0x34(1); mr 25,4; lis 11,-17874; lwz 9,0x4(25); ori 11,11,35747; lwz 10,0x0(25); li 0,0; mr 27,3; subf 9,10,9; stw 0,0x0(27); mullw 9,9,11; stw 0,0x4(27); addi 8,27,8; stw 0,0x4(8); srawi. 0,9,3; beq 1f; mulli 0,0,88; mr 31,0; cmplwi 0,128; ble 0f; mr 3,31; bl _s803A49A4_0; b 2f; 0:; mr 3,31; bl _s803A49A4_1; b 2f; 1:; li 3,0; li 31,0; 2:; add 0,3,31; stw 3,0x0(27); stw 0,0xc(27); mr 28,3; stw 3,0x4(27); lwz 26,0x4(25); lwz 31,0x0(25); cmpw 31,26; beq 4f; 3:; lwz 0,0x0(31); addi 30,28,16; addi 4,28,24; li 5,64; stw 0,0x0(28); mr 3,30; addi 29,31,16; lwz 0,0x4(31); stw 0,0x4(28); lhz 9,0x8(31); sth 9,0x8(28); lhz 0,0xa(31); sth 0,0xa(28); lwz 9,0xc(31); addi 31,31,88; stw 9,0xc(28); bl _s803A49A4_2; addi 28,28,88; mr 3,30; mr 4,29; li 5,-1; bl _s803A49A4_3; cmpw 31,26; bne 3b; 4:; stw 28,0x4(27); mr 3,27; lwz 0,0x10(25); stw 0,0x10(27); lwz 9,0x14(25); stw 9,0x14(27); lwz 0,0x34(1); mtspr 8,0; lmw 25,0x14(1); addi 1,1,48"
extern "C" void _s803A49A4_0();
extern "C" void _s803A49A4_1();
extern "C" void _s803A49A4_2();
extern "C" void _s803A49A4_3();
extern "C" void f_803A49A4() {}
