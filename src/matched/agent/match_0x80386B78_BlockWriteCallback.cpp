// 0x80386B78 BlockWriteCallback (232 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-32(1); stw 31,0x1c(1); stw 30,0x18(1); mr. 30,4; stw 29,0x14(1); addi 29,3,0; mulli 5,29,272; lis 3,-32688; addi 0,3,-24000; add 31,0,5; blt 0f; lwz 3,0xb8(31); lhz 0,0xa(31); add 0,3,0; stw 0,0xb8(31); lwz 3,0xb0(31); lhz 0,0xa(31); add 0,3,0; stw 0,0xb0(31); lwz 3,0xb4(31); lhz 0,0xa(31); add 0,3,0; stw 0,0xb4(31); lwz 3,0xac(31); addic. 0,3,-1; stw 0,0xac(31); ble 0f; lis 3,-32712; addi 4,3,27512; addi 3,29,0; bl _s80386B78_0; mr. 30,3; bge 2f; 0:; lwz 0,0xd0(31); cmplwi 0,0; bne 1f; addi 3,31,0; addi 4,30,0; bl _s80386B78_1; 1:; lwz 0,0xd4(31); cmplwi 0,0; mr 12,0; beq 2f; li 0,0; mtspr 8,12; stw 0,0xd4(31); addi 3,29,0; addi 4,30,0; blrl; 2:; lwz 0,0x24(1); lwz 31,0x1c(1); lwz 30,0x18(1); lwz 29,0x14(1); addi 1,1,32; mtspr 8,0"
extern "C" void _s80386B78_0();
extern "C" void _s80386B78_1();
extern "C" void f_80386B78() {}
