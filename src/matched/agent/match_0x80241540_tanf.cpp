// 0x80241540 tanf (128 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stw 0,0x1c(1); lfs f2,-28204(13); fmr f0,f1; stfs f0,0x10(1); lwz 9,0x10(1); rlwinm 9,9,0,1,31; lis 0,16201; ori 0,0,4058; cmpw 9,0; bgt 0f; li 3,1; bl _s80241540_0; b 2f; 0:; lis 0,32639; ori 0,0,65535; cmpw 9,0; bgt 1f; addi 3,1,8; bl _s80241540_1; rlwinm 3,3,1,30,30; lfs f1,0x8(1); lfs f2,0xc(1); subfic 3,3,1; bl _s80241540_2; b 2f; 1:; fsubs f1,f1,f1; 2:; lwz 0,0x1c(1); mtspr 8,0; addi 1,1,24"
extern "C" void _s80241540_0();
extern "C" void _s80241540_1();
extern "C" void _s80241540_2();
extern "C" void f_80241540() {}
