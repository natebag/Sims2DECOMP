// 0x80259324 SIRegisterPollingHandler (204 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-24(1); stw 31,0x14(1); stw 30,0x10(1); mr 30,3; bl _s80259324_0; lis 4,-32694; li 0,4; addi 4,4,-21456; mtspr 9,0; addi 31,3,0; addi 3,4,0; 0:; lwz 0,0x0(3); cmplw 0,30; bne 1f; mr 3,31; bl _s80259324_1; li 3,1; b 4f; 1:; addi 3,3,4; bdnz 0b; li 0,4; mtspr 9,0; li 5,0; 2:; lwz 0,0x0(4); cmplwi 0,0; bne 3f; lis 3,-32694; rlwinm 4,5,2,0,29; addi 0,3,-21456; add 3,0,4; stw 30,0x0(3); li 3,1; bl _s80259324_2; mr 3,31; bl _s80259324_3; li 3,1; b 4f; 3:; addi 4,4,4; addi 5,5,1; bdnz 2b; mr 3,31; bl _s80259324_4; li 3,0; 4:; lwz 0,0x1c(1); lwz 31,0x14(1); lwz 30,0x10(1); addi 1,1,24; mtspr 8,0"
extern "C" void _s80259324_0();
extern "C" void _s80259324_1();
extern "C" void _s80259324_2();
extern "C" void _s80259324_3();
extern "C" void _s80259324_4();
extern "C" void f_80259324() {}
