// 0x802342E4 EStream (240 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" replace="b f_80234404" lines="li 31,0; 0:; addi 9,27,-23880; mr 3,26; lwzx 5,9,31; addi 4,1,8; addi 6,1,48; mr 30,27; addi 5,5,60; addi 29,29,1; bl _s802342E4_0; addi 31,31,4; lwz 0,-15688(30); cmpw 29,0; blt 0b; lwz 6,0x8(25); addi 7,28,12; lwz 9,0x8(1); mr 3,28; lwz 0,0x4(25); lwz 11,0x14(1); lwz 10,0x8(24); lwz 8,0x4(24); stw 9,0x0(28); stw 0,0x4(28); stw 6,0x8(28); stw 11,0xc(28); stw 10,0x8(7); stw 8,0x4(7); lwz 0,0x5c(1); mtspr 8,0; lmw 24,0x38(1); addi 1,1,88; blr; stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); addis 5,3,3; lwz 7,-23884(5); addi 4,5,-24204; lwz 6,-15688(5); addi 3,3,24; addi 5,5,-23880; bl _s802342E4_1; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8; blr; stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 30,3; li 31,0; bl _s802342E4_2; mr 3,30; bl _s802342E4_3; addis 30,30,3; lwz 9,-23948(30); cmpwi 9,0"
extern "C" void _s802342E4_0();
extern "C" void _s802342E4_1();
extern "C" void _s802342E4_2();
extern "C" void _s802342E4_3();
extern "C" void f_80234404();
extern "C" void f_802342E4() {}
