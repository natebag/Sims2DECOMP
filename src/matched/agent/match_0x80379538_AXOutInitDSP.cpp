// 0x80379538 __AXOutInitDSP (204 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; lis 5,-32712; stw 0,0x4(1); lis 3,-32699; addi 0,3,26592; stwu 1,-16(1); lis 4,-32690; li 9,0; stw 31,0xc(1); addi 31,4,10080; lis 4,-32712; stw 0,0x4a0c(31); addi 8,31,2560; li 7,16; lhz 0,-25360(13); li 6,48; addi 5,5,-27488; stw 0,0x4a10(31); li 0,8192; addi 4,4,-27468; stw 9,0x4a14(31); lis 3,-32712; stw 8,0x4a18(31); stw 0,0x4a1c(31); addi 0,3,-27380; addi 3,13,-22160; stw 9,0x4a20(31); sth 7,0x4a24(31); sth 6,0x4a26(31); stw 5,0x4a28(31); stw 4,0x4a2c(31); stw 0,0x4a30(31); stw 9,0x4a34(31); stw 9,0x4a04(31); stw 9,-22172(13); stw 9,-22168(13); bl _s80379538_0; bl _s80379538_1; cmpwi 3,0; bne 0f; bl _s80379538_2; 0:; addi 3,31,18944; bl _s80379538_3; 1:; lwz 0,-22172(13); cmpwi 0,0; beq 1b; lwz 0,0x14(1); lwz 31,0xc(1); addi 1,1,16; mtspr 8,0"
extern "C" void _s80379538_0();
extern "C" void _s80379538_1();
extern "C" void _s80379538_2();
extern "C" void _s80379538_3();
extern "C" void f_80379538() {}
