// 0x8037922C __AXOutNewFrame (440 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; lis 4,-32690; stw 0,0x4(1); stwu 1,-24(1); stw 31,0x14(1); addi 31,4,10080; stw 30,0x10(1); addi 30,3,0; bl _s8037922C_0; stw 4,0x4a54(31); stw 3,0x4a50(31); mr 3,30; bl _s8037922C_1; bl _s8037922C_2; bl _s8037922C_3; lis 4,-17730; addi 30,3,0; addi 3,4,384; bl _s8037922C_4; 0:; bl _s8037922C_5; cmplwi 3,0; bne 0b; mr 3,30; bl _s8037922C_6; 1:; bl _s8037922C_7; cmplwi 3,0; bne 1b; bl _s8037922C_8; bl _s8037922C_9; stw 4,0x4a5c(31); stw 3,0x4a58(31); bl _s8037922C_10; bl _s8037922C_11; stw 4,0x4a64(31); stw 3,0x4a60(31); bl _s8037922C_12; stw 4,0x4a6c(31); stw 3,0x4a68(31); lwz 12,-22176(13); cmplwi 12,0; beq 2f; mtspr 8,12; blrl; 2:; bl _s8037922C_13; stw 4,0x4a74(31); stw 3,0x4a70(31); addi 3,31,1920; lwz 0,-22200(13); mulli 0,0,640; add 4,31,0; bl _s8037922C_14; lwz 3,-22200(13); lwz 0,-22152(13); addi 3,3,1; cmplwi 0,1; stw 3,-22200(13); bne 3f; lis 3,-21845; lwz 4,-22200(13); addi 0,3,-21845; mulhwu 0,0,4; rlwinm 0,0,31,1,31; mulli 0,0,3; subf 0,0,4; stw 0,-22200(13); b 4f; 3:; lwz 0,-22200(13); li 4,640; rlwinm 0,0,0,31,31; stw 0,-22200(13); lwz 0,-22200(13); mulli 0,0,640; add 3,31,0; bl _s8037922C_15; 4:; bl _s8037922C_16; stw 4,0x4a7c(31); stw 3,0x4a78(31); bl _s8037922C_17; stw 3,0x4a80(31); bl _s8037922C_18; cmplwi 3,0; beq 6f; li 0,7; mtspr 9,0; addi 4,31,19024; 5:; lbz 0,0x0(4); stb 0,0x0(3); lbz 0,0x1(4); stb 0,0x1(3); lbz 0,0x2(4); stb 0,0x2(3); lbz 0,0x3(4); stb 0,0x3(3); lbz 0,0x4(4); stb 0,0x4(3); lbz 0,0x5(4); stb 0,0x5(3); lbz 0,0x6(4); stb 0,0x6(3); lbz 0,0x7(4); addi 4,4,8; stb 0,0x7(3); addi 3,3,8; bdnz 5b; 6:; lwz 0,0x1c(1); lwz 31,0x14(1); lwz 30,0x10(1); addi 1,1,24; mtspr 8,0"
extern "C" void _s8037922C_0();
extern "C" void _s8037922C_1();
extern "C" void _s8037922C_2();
extern "C" void _s8037922C_3();
extern "C" void _s8037922C_4();
extern "C" void _s8037922C_5();
extern "C" void _s8037922C_6();
extern "C" void _s8037922C_7();
extern "C" void _s8037922C_8();
extern "C" void _s8037922C_9();
extern "C" void _s8037922C_10();
extern "C" void _s8037922C_11();
extern "C" void _s8037922C_12();
extern "C" void _s8037922C_13();
extern "C" void _s8037922C_14();
extern "C" void _s8037922C_15();
extern "C" void _s8037922C_16();
extern "C" void _s8037922C_17();
extern "C" void _s8037922C_18();
extern "C" void f_8037922C() {}
