// 0x8034EF88 stream_data(Stream (368 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 31,3; lwz 0,0x6c(31); lbz 9,0x74(31); rlwinm 30,0,31,1,31; mr 5,30; cmpwi 9,0; beq 0f; lwz 0,0x68(31); add 29,0,30; b 1f; 0:; lwz 29,0x68(31); 1:; lwz 11,0x60(31); lwz 9,0x64(31); add 0,11,30; cmplw 0,9; ble 5f; cmplw 9,11; ble 2f; subf 30,11,9; li 4,0; subf 5,30,5; add 3,29,30; bl _s8034EF88_0; b 5f; 2:; mr 5,30; mr 3,29; li 4,0; bl _s8034EF88_1; lbz 0,0x74(31); cmpwi 0,0; beq 3f; lwz 0,0x6c(31); mr 5,0; rlwinm 0,0,31,1,31; b 4f; 3:; lwz 5,0x6c(31); li 0,0; 4:; lwz 3,0x68(31); rlwinm 5,5,31,1,31; lwz 4,0x18(31); li 6,0; add 3,3,0; li 7,0; add 4,4,0; li 30,0; bl _s8034EF88_2; 5:; cmpwi 30,0; beq 6f; lwz 9,0x10(31); lis 7,-32715; lwz 0,0x60(31); mr 4,29; lwz 6,0x8(9); addi 7,7,-5440; addi 3,31,36; mr 5,30; add 6,6,0; li 8,1; bl _s8034EF88_3; lbz 0,0x75(31); lwz 9,0x60(31); ori 0,0,16; add 9,9,30; stb 0,0x75(31); stw 9,0x60(31); b 9f; 6:; lwz 9,0x10(31); lwz 0,0x3c(9); andi. 9,0,32768; beq 7f; stw 30,0x60(31); b 9f; 7:; lwz 0,0x74(31); andis. 9,0,128; beq 8f; rlwinm 0,0,0,9,7; stw 0,0x74(31); b 9f; 8:; mr 3,31; bl _s8034EF88_4; 9:; lbz 0,0x74(31); xori 0,0,1; stb 0,0x74(31); lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s8034EF88_0();
extern "C" void _s8034EF88_1();
extern "C" void _s8034EF88_2();
extern "C" void _s8034EF88_3();
extern "C" void _s8034EF88_4();
extern "C" void f_8034EF88() {}
