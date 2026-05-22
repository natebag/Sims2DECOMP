// 0x8032686C EResourceManager::PreloadResource(unsigned (180 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,3; mr 30,4; bl _s8032686C_0; cmpwi 3,0; li 3,1; bne 1f; lwz 3,-22652(13); mr 4,31; mr 5,30; lwz 9,0x0(3); lha 0,0x68(9); lwz 9,0x6c(9); add 3,3,0; mtspr 8,9; blrl; cmpwi 3,0; bne 0f; lwz 9,0xd1c(31); mr 4,30; lwz 0,0x24(9); lha 3,0x20(9); mtspr 8,0; add 3,31,3; blrl; lwz 11,-22652(13); mr 4,31; mr 5,30; lwz 9,0x0(11); lha 3,0x60(9); lwz 0,0x64(9); add 3,11,3; mtspr 8,0; blrl; 0:; mr 3,31; mr 4,30; bl _s8032686C_1; 1:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s8032686C_0();
extern "C" void _s8032686C_1();
extern "C" void f_8032686C() {}
