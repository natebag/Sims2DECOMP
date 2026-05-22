// 0x8025B4D8 DVDOpen (200 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-152(1); stw 31,0x94(1); addi 31,4,0; stw 30,0x90(1); addi 30,3,0; bl _s8025B4D8_0; cmpwi 3,0; bge 0f; addi 3,1,16; li 4,128; bl _s8025B4D8_1; lis 3,-32700; crxor 6,6,6; addi 3,3,-15384; addi 4,30,0; addi 5,1,16; bl _s8025B4D8_2; li 3,0; b 4f; 0:; mulli 5,3,12; lwz 3,-23508(13); lwzx 0,3,5; rlwinm. 0,0,0,0,7; bne 1f; li 0,0; b 2f; 1:; li 0,1; 2:; cmpwi 0,0; beq 3f; li 3,0; b 4f; 3:; add 3,3,5; lwz 4,0x4(3); li 0,0; li 3,1; stw 4,0x30(31); lwz 4,-23508(13); add 4,4,5; lwz 4,0x8(4); stw 4,0x34(31); stw 0,0x38(31); stw 0,0xc(31); 4:; lwz 0,0x9c(1); lwz 31,0x94(1); lwz 30,0x90(1); addi 1,1,152; mtspr 8,0"
extern "C" void _s8025B4D8_0();
extern "C" void _s8025B4D8_1();
extern "C" void _s8025B4D8_2();
extern "C" void f_8025B4D8() {}
