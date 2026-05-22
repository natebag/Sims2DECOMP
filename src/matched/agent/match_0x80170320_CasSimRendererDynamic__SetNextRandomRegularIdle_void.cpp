// 0x80170320 CasSimRendererDynamic::SetNextRandomRegularIdle(void) (116 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 30,3; li 3,100; bl _s80170320_0; cmpwi 3,14; bgt 0f; lwz 9,0x224(30); lwz 31,0x4(9); b 2f; 0:; addi 0,3,-15; cmplwi 0,14; bgt 1f; lwz 9,0x224(30); lwz 31,0x8(9); b 2f; 1:; lwz 9,0x224(30); lwz 31,0x0(9); 2:; mr 3,30; mr 4,31; bl _s80170320_1; mr 3,31; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s80170320_0();
extern "C" void _s80170320_1();
extern "C" void f_80170320() {}
