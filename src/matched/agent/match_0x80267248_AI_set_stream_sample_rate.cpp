// 0x80267248 __AI_set_stream_sample_rate (212 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-48(1); stmw 25,0x14(1); mr 25,3; bl _s80267248_0; cmplw 25,3; beq 0f; lis 31,-13312; lwz 0,0x6c00(31); rlwinm 0,0,0,31,31; mr 29,0; bl _s80267248_1; mr 28,3; bl _s80267248_2; addi 27,3,0; li 3,0; bl _s80267248_3; li 3,0; bl _s80267248_4; lwz 3,0x6c00(31); lwz 0,0x6c00(31); rlwinm 26,3,0,25,25; rlwinm 0,0,0,26,24; stw 0,0x6c00(31); bl _s80267248_5; mr 30,3; bl _s80267248_6; lwz 4,0x6c00(31); rlwinm 0,25,1,0,30; addi 3,30,0; or 4,4,26; stw 4,0x6c00(31); lwz 4,0x6c00(31); rlwinm 4,4,0,27,25; ori 4,4,32; stw 4,0x6c00(31); lwz 4,0x6c00(31); rlwinm 4,4,0,31,29; or 0,4,0; stw 0,0x6c00(31); bl _s80267248_7; mr 3,29; bl _s80267248_8; mr 3,28; bl _s80267248_9; mr 3,27; bl _s80267248_10; 0:; lmw 25,0x14(1); lwz 0,0x34(1); addi 1,1,48; mtspr 8,0"
extern "C" void _s80267248_0();
extern "C" void _s80267248_1();
extern "C" void _s80267248_2();
extern "C" void _s80267248_3();
extern "C" void _s80267248_4();
extern "C" void _s80267248_5();
extern "C" void _s80267248_6();
extern "C" void _s80267248_7();
extern "C" void _s80267248_8();
extern "C" void _s80267248_9();
extern "C" void _s80267248_10();
extern "C" void f_80267248() {}
