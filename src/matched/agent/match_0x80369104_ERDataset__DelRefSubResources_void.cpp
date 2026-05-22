// 0x80369104 ERDataset::DelRefSubResources(void) (172 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 26,0x8(1); stw 0,0x24(1); mr 31,3; lis 0,-21846; addi 10,31,20; lwz 11,0x14(31); lwz 9,0x4(10); ori 0,0,43691; li 29,0; subf 9,11,9; mullw 9,9,0; rlwinm. 0,9,30,2,31; beq 2f; lis 28,-21846; mr 27,10; li 26,0; ori 28,28,43691; li 30,0; 0:; lwz 9,0x14(31); add 9,9,30; lwz 3,0x8(9); cmpwi 3,0; beq 1f; bl _s80369104_0; lwz 9,0x14(31); add 9,9,30; stw 26,0x8(9); 1:; lwz 0,0x4(27); addi 29,29,1; lwz 9,0x14(31); addi 30,30,12; subf 0,9,0; mullw 0,0,28; srawi 0,0,2; cmplw 29,0; blt 0b; 2:; lwz 0,0x24(1); mtspr 8,0; lmw 26,0x8(1); addi 1,1,32"
extern "C" void _s80369104_0();
extern "C" void f_80369104() {}
