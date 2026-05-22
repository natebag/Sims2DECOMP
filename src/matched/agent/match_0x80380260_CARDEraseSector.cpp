// 0x80380260 __CARDEraseSector (272 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-40(1); stw 31,0x24(1); stw 30,0x20(1); stw 29,0x1c(1); addi 29,3,0; mulli 6,29,272; lis 3,-32688; addi 0,3,-24000; add 31,0,6; lhz 0,0xa(31); cmplwi 0,128; ble 1f; cmplwi 5,0; beq 0f; addi 12,5,0; mtspr 8,12; addi 3,29,0; li 4,0; blrl; 0:; li 3,0; b 6f; 1:; li 0,241; stb 0,0x94(31); rlwinm 0,4,15,25,31; rlwinm 3,4,23,24,31; stb 0,0x95(31); li 6,3; li 0,-1; stb 3,0x96(31); mr 3,29; li 4,0; stw 6,0xa0(31); stw 0,0xa4(31); stw 6,0xa8(31); bl _s80380260_0; addi 30,3,0; cmpwi 30,-1; bne 2f; li 30,0; b 5f; 2:; cmpwi 30,0; blt 5f; lwz 5,0xa0(31); addi 3,29,0; addi 4,31,148; li 6,1; bl _s80380260_1; cmpwi 3,0; bne 3f; li 0,0; stw 0,0xcc(31); li 30,-3; b 4f; 3:; li 30,0; 4:; mr 3,29; bl _s80380260_2; mr 3,29; bl _s80380260_3; 5:; mr 3,30; 6:; lwz 0,0x2c(1); lwz 31,0x24(1); lwz 30,0x20(1); lwz 29,0x1c(1); addi 1,1,40; mtspr 8,0"
extern "C" void _s80380260_0();
extern "C" void _s80380260_1();
extern "C" void _s80380260_2();
extern "C" void _s80380260_3();
extern "C" void f_80380260() {}
