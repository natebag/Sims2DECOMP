// 0x803807B0 CARDGetEncoding (136 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-32(1); stw 31,0x1c(1); addi 31,4,0; addi 4,1,20; bl _s803807B0_0; cmpwi 3,0; bge 0f; b 3f; 0:; lwz 3,0x14(1); lwz 3,0x80(3); lhz 0,0x24(3); sth 0,0x0(31); lwz 31,0x14(1); bl _s803807B0_1; lwz 0,0x0(31); cmpwi 0,0; beq 1f; li 0,0; stw 0,0x4(31); b 2f; 1:; lwz 0,0x4(31); cmpwi 0,-1; bne 2f; li 0,0; stw 0,0x4(31); 2:; bl _s803807B0_2; li 3,0; 3:; lwz 0,0x24(1); lwz 31,0x1c(1); addi 1,1,32; mtspr 8,0"
extern "C" void _s803807B0_0();
extern "C" void _s803807B0_1();
extern "C" void _s803807B0_2();
extern "C" void f_803807B0() {}
