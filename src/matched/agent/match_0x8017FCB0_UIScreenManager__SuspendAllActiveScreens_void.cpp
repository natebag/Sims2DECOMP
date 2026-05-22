// 0x8017FCB0 UIScreenManager::SuspendAllActiveScreens(void) (168 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-64(1); mfspr 0,8; stmw 26,0x28(1); stw 0,0x44(1); lwz 9,-31496(13); mr 29,3; li 3,0; li 26,2; addi 9,9,1; lis 27,-32706; stw 9,-31496(13); lis 28,-32706; addi 31,29,132; li 30,23; 0:; lwz 0,0x4(31); cmpwi 0,1; bne 1f; lwz 0,-31496(13); addi 4,1,8; lwz 5,0x0(31); mr 3,29; stw 26,0x4(31); stw 0,0x8(31); bl _s8017FCB0_0; lwz 3,-25136(13); addi 4,27,15128; li 5,0; li 6,0; li 7,2; addi 8,28,15188; addi 9,1,8; crxor 6,6,6; bl _s8017FCB0_1; lwz 3,-31496(13); 1:; addi 31,31,16; addic. 30,30,-1; bge 0b; lwz 0,0x44(1); mtspr 8,0; lmw 26,0x28(1); addi 1,1,64"
extern "C" void _s8017FCB0_0();
extern "C" void _s8017FCB0_1();
extern "C" void f_8017FCB0() {}
