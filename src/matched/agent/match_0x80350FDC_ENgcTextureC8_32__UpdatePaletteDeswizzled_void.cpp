// 0x80350FDC ENgcTextureC8_32::UpdatePaletteDeswizzled(void) (188 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,3; li 5,32; lhz 4,0x14(31); lis 3,-32692; addi 3,3,-7364; rlwinm 4,4,2,0,29; bl _s80350FDC_0; cmpwi 3,0; stw 3,0xd4(31); beq 1f; lhz 0,0x14(31); li 5,0; cmplw 5,0; bge 1f; li 4,0; 0:; lwz 8,0xcc(31); add 9,5,5; lwz 7,0xd0(31); addi 5,5,1; add 11,9,8; lbzx 0,9,8; lbz 10,0x1(11); add 8,9,7; lbzx 6,9,7; rlwinm 0,0,16,0,15; lbz 9,0x1(8); rlwinm 10,10,24,0,7; or 0,0,10; lwz 11,0xd4(31); or 0,0,6; rlwinm 9,9,8,0,23; or 0,0,9; stwx 0,4,11; addi 4,4,4; lhz 0,0x14(31); cmplw 5,0; blt 0b; 1:; lwz 3,0xd4(31); lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s80350FDC_0();
extern "C" void f_80350FDC() {}
