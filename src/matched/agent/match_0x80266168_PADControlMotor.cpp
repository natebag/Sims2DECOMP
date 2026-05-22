// 0x80266168 PADControlMotor (184 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-40(1); stw 31,0x24(1); stw 30,0x20(1); addi 30,4,0; stw 29,0x1c(1); addi 29,3,0; bl _s80266168_0; lis 0,-32768; lwz 4,-23180(13); srw 0,0,29; and. 0,4,0; addi 31,3,0; beq 2f; mr 3,29; bl _s80266168_1; rlwinm. 0,3,0,2,2; bne 2f; lwz 0,-27640(13); cmplwi 0,2; bge 0f; cmplwi 30,2; bne 0f; li 30,0; 0:; lis 3,-32768; lbz 0,0x30e3(3); rlwinm. 0,0,0,26,26; beq 1f; li 30,0; 1:; lwz 4,-27644(13); rlwinm 0,30,0,30,31; addi 3,29,0; oris 4,4,64; or 4,4,0; bl _s80266168_2; bl _s80266168_3; 2:; mr 3,31; bl _s80266168_4; lwz 0,0x2c(1); lwz 31,0x24(1); lwz 30,0x20(1); lwz 29,0x1c(1); addi 1,1,40; mtspr 8,0"
extern "C" void _s80266168_0();
extern "C" void _s80266168_1();
extern "C" void _s80266168_2();
extern "C" void _s80266168_3();
extern "C" void _s80266168_4();
extern "C" void f_80266168() {}
