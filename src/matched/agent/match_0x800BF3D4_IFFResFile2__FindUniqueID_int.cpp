// 0x800BF3D4 IFFResFile2::FindUniqueID(int) (152 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,3; mr 30,4; lwz 9,0xc(31); lha 3,0x60(9); lwz 0,0x64(9); add 3,31,3; mtspr 8,0; blrl; cmpwi 3,0; bne 0f; mr 3,31; li 4,-49; bl _s800BF3D4_0; b 1f; 0:; mr 3,31; li 4,0; bl _s800BF3D4_1; 1:; mr 3,31; bl _s800BF3D4_2; cmpwi 3,0; bne 2f; lwz 3,0x138(31); mr 4,30; li 5,128; bl _s800BF3D4_3; addi 3,3,1; extsh 3,3; b 3f; 2:; li 3,0; 3:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s800BF3D4_0();
extern "C" void _s800BF3D4_1();
extern "C" void _s800BF3D4_2();
extern "C" void _s800BF3D4_3();
extern "C" void f_800BF3D4() {}
