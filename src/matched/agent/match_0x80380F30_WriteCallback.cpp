// 0x80380F30 WriteCallback (208 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-32(1); stw 31,0x1c(1); stw 30,0x18(1); mr. 30,4; stw 29,0x14(1); addi 29,3,0; mulli 5,29,272; lis 3,-32688; addi 0,3,-24000; add 31,0,5; blt 1f; lwz 3,0x80(31); lwz 0,0x84(31); addi 4,3,8192; cmplw 0,4; addi 0,3,16384; bne 0f; stw 0,0x84(31); mr 3,0; li 5,8192; bl _s80380F30_0; b 1f; 0:; stw 4,0x84(31); addi 3,4,0; mr 4,0; li 5,8192; bl _s80380F30_1; 1:; lwz 0,0xd0(31); cmplwi 0,0; bne 2f; addi 3,31,0; addi 4,30,0; bl _s80380F30_2; 2:; lwz 0,0xd8(31); cmplwi 0,0; mr 12,0; beq 3f; li 0,0; mtspr 8,12; stw 0,0xd8(31); addi 3,29,0; addi 4,30,0; blrl; 3:; lwz 0,0x24(1); lwz 31,0x1c(1); lwz 30,0x18(1); lwz 29,0x14(1); addi 1,1,32; mtspr 8,0"
extern "C" void _s80380F30_0();
extern "C" void _s80380F30_1();
extern "C" void _s80380F30_2();
extern "C" void f_80380F30() {}
