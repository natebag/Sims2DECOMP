// 0x803C6834 void (144 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-64(1); mfspr 0,8; stmw 27,0x2c(1); stw 0,0x44(1); mr 8,4; mr 9,3; addi 10,8,-12; lis 0,-21846; ori 0,0,43691; subf 11,9,10; lwz 6,0x0(9); mullw 11,11,0; lwz 27,-12(8); mr 7,5; lwz 30,0x4(9); lwz 0,0x8(9); li 4,0; lwz 28,0x4(10); srawi 5,11,2; lwz 29,0x8(10); stw 6,-12(8); stw 30,0x4(10); addi 6,1,24; stw 0,0x8(10); stw 27,0x18(1); stw 28,0x1c(1); stw 29,0x20(1); stw 27,0x8(1); stw 28,0xc(1); stw 29,0x10(1); bl _s803C6834_0; lwz 0,0x44(1); mtspr 8,0; lmw 27,0x2c(1); addi 1,1,64"
extern "C" void _s803C6834_0();
extern "C" void f_803C6834() {}
