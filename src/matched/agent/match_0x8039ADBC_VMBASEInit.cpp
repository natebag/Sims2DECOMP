// 0x8039ADBC VMBASEInit (204 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 0,0x14(1); stw 31,0xc(1); stw 30,0x8(1); mr 30,3; lwz 0,-21520(13); cmpwi 0,0; bne 4f; bl _s8039ADBC_0; li 0,1; mr 31,3; stw 0,-21520(13); mr 3,30; bl _s8039ADBC_1; bl _s8039ADBC_2; rlwinm 3,3,0,16,31; lis 0,1; subf 0,3,0; cmplwi 0,20480; blt 0f; bl _s8039ADBC_3; bl _s8039ADBC_4; bl _s8039ADBC_5; b 3f; 0:; cmplwi 0,16384; blt 1f; bl _s8039ADBC_6; bl _s8039ADBC_7; bl _s8039ADBC_8; b 3f; 1:; cmplwi 0,4096; blt 2f; bl _s8039ADBC_9; bl _s8039ADBC_10; bl _s8039ADBC_11; b 3f; 2:; bl _s8039ADBC_12; bl _s8039ADBC_13; bl _s8039ADBC_14; 3:; bl _s8039ADBC_15; bl _s8039ADBC_16; bl _s8039ADBC_17; mr 3,31; bl _s8039ADBC_18; 4:; lwz 0,0x14(1); lwz 31,0xc(1); lwz 30,0x8(1); mtspr 8,0; addi 1,1,16"
extern "C" void _s8039ADBC_0();
extern "C" void _s8039ADBC_1();
extern "C" void _s8039ADBC_2();
extern "C" void _s8039ADBC_3();
extern "C" void _s8039ADBC_4();
extern "C" void _s8039ADBC_5();
extern "C" void _s8039ADBC_6();
extern "C" void _s8039ADBC_7();
extern "C" void _s8039ADBC_8();
extern "C" void _s8039ADBC_9();
extern "C" void _s8039ADBC_10();
extern "C" void _s8039ADBC_11();
extern "C" void _s8039ADBC_12();
extern "C" void _s8039ADBC_13();
extern "C" void _s8039ADBC_14();
extern "C" void _s8039ADBC_15();
extern "C" void _s8039ADBC_16();
extern "C" void _s8039ADBC_17();
extern "C" void _s8039ADBC_18();
extern "C" void f_8039ADBC() {}
