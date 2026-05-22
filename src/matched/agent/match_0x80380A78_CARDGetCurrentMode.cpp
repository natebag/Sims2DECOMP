// 0x80380A78 CARDGetCurrentMode (172 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-32(1); stw 31,0x1c(1); addi 31,4,0; addi 4,1,16; bl _s80380A78_0; cmpwi 3,0; bge 0f; b 6f; 0:; lwz 3,0x10(1); lhz 0,0xa(3); cmpwi 0,512; beq 1f; bge 2f; cmpwi 0,128; beq 2f; b 2f; 1:; li 0,1; stw 0,0x0(31); b 3f; 2:; li 0,0; stw 0,0x0(31); 3:; lwz 31,0x10(1); bl _s80380A78_1; lwz 0,0x0(31); cmpwi 0,0; beq 4f; li 0,0; stw 0,0x4(31); b 5f; 4:; lwz 0,0x4(31); cmpwi 0,-1; bne 5f; li 0,0; stw 0,0x4(31); 5:; bl _s80380A78_2; li 3,0; 6:; lwz 0,0x24(1); lwz 31,0x1c(1); addi 1,1,32; mtspr 8,0"
extern "C" void _s80380A78_0();
extern "C" void _s80380A78_1();
extern "C" void _s80380A78_2();
extern "C" void f_80380A78() {}
