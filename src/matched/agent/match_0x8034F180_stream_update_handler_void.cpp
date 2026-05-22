// 0x8034F180 stream_update_handler(void (108 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,7; lwz 0,0x74(31); andis. 9,0,32; bne 0f; lwz 0,0x70(31); add 9,4,6; li 3,0; rlwinm 0,0,31,1,31; cmplw 9,0; blt 1f; mr 3,31; bl _s8034F180_0; lwz 3,0x70(31); rlwinm 3,3,31,1,31; b 1f; 0:; mr 3,31; bl _s8034F180_1; li 3,0; 1:; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s8034F180_0();
extern "C" void _s8034F180_1();
extern "C" void f_8034F180() {}
