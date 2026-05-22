// 0x8025C410 cbForStateReadingFST (128 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; cmplwi 3,16; stw 0,0x4(1); stwu 1,-24(1); stw 31,0x14(1); bne 0f; bl _s8025C410_0; b 3f; 0:; rlwinm. 0,3,0,31,31; beq 2f; li 31,0; stw 31,-23428(13); bl _s8025C410_1; lis 3,-32694; lwz 4,-23480(13); addi 0,3,-17184; stw 0,-23480(13); stw 31,0xc(4); lwz 12,0x28(4); cmplwi 12,0; beq 1f; mtspr 8,12; li 3,0; blrl; 1:; bl _s8025C410_2; b 3f; 2:; bl _s8025C410_3; 3:; lwz 0,0x1c(1); lwz 31,0x14(1); addi 1,1,24; mtspr 8,0"
extern "C" void _s8025C410_0();
extern "C" void _s8025C410_1();
extern "C" void _s8025C410_2();
extern "C" void _s8025C410_3();
extern "C" void f_8025C410() {}
