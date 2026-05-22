// 0x8037B314 AXSetVoiceAddr (272 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-32(1); stw 31,0x1c(1); stw 30,0x18(1); addi 30,4,0; stw 29,0x14(1); addi 29,3,0; addi 31,29,422; bl _s8037B314_0; lwz 0,0x0(30); stw 0,0x0(31); lwz 0,0x4(30); stw 0,0x4(31); lwz 0,0x8(30); stw 0,0x8(31); lwz 0,0xc(30); stw 0,0xc(31); lhz 0,0x2(30); cmpwi 0,10; beq 1f; bge 0f; cmpwi 0,0; beq 3f; b 3f; 0:; cmpwi 0,25; beq 2f; b 3f; 1:; li 4,0; stw 4,0x10(31); lis 0,2048; stw 4,0x14(31); stw 4,0x18(31); stw 4,0x1c(31); stw 4,0x20(31); stw 4,0x24(31); stw 4,0x28(31); stw 4,0x2c(31); stw 0,0x30(31); stw 4,0x34(31); b 3f; 2:; li 4,0; stw 4,0x10(31); lis 0,256; stw 4,0x14(31); stw 4,0x18(31); stw 4,0x1c(31); stw 4,0x20(31); stw 4,0x24(31); stw 4,0x28(31); stw 4,0x2c(31); stw 0,0x30(31); stw 4,0x34(31); 3:; lwz 0,0x1c(29); rlwinm 0,0,0,19,14; stw 0,0x1c(29); lwz 0,0x1c(29); oris 0,0,2; ori 0,0,4096; stw 0,0x1c(29); bl _s8037B314_1; lwz 0,0x24(1); lwz 31,0x1c(1); lwz 30,0x18(1); lwz 29,0x14(1); addi 1,1,32; mtspr 8,0"
extern "C" void _s8037B314_0();
extern "C" void _s8037B314_1();
extern "C" void f_8037B314() {}
