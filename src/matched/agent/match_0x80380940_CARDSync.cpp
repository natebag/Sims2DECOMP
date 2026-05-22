// 0x80380940 __CARDSync (152 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-32(1); stw 31,0x1c(1); stw 30,0x18(1); stw 29,0x14(1); stw 28,0x10(1); addi 28,3,0; mulli 4,28,272; lis 3,-32688; addi 0,3,-24000; add 31,0,4; bl _s80380940_0; mr 29,3; b 1f; 0:; addi 3,31,140; bl _s80380940_1; 1:; cmpwi 28,0; blt 2f; cmpwi 28,2; blt 3f; 2:; li 0,-128; b 4f; 3:; lwz 0,0x4(31); 4:; mr 30,0; cmpwi 30,-1; beq 0b; mr 3,29; bl _s80380940_2; mr 3,30; lwz 0,0x24(1); lwz 31,0x1c(1); lwz 30,0x18(1); lwz 29,0x14(1); lwz 28,0x10(1); addi 1,1,32; mtspr 8,0"
extern "C" void _s80380940_0();
extern "C" void _s80380940_1();
extern "C" void _s80380940_2();
extern "C" void f_80380940() {}
