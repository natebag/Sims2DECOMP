// 0x80194CD0 CASTarget::HandleNav(int) (212 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,3; lwz 0,0x8c(31); cmpwi 0,0; beq 5f; cmpwi 7,4,259; ble cr7,0f; bl _s80194CD0_0; b 5f; 0:; cmpwi 4,258; bne 1f; mr 3,31; bl _s80194CD0_1; b 5f; 1:; bne cr7,2f; mr 3,31; bl _s80194CD0_2; b 5f; 2:; cmpwi 4,257; bne 4f; lwz 3,-26564(13); lwz 9,0x0(3); lha 0,0x48(9); lwz 9,0x4c(9); add 3,3,0; mtspr 8,9; blrl; lwz 3,-24508(13); cmpwi 3,0; beq 3f; addi 3,3,48; li 4,32; bl _s80194CD0_3; lwz 3,-24508(13); li 4,32; addi 3,3,48; bl _s80194CD0_4; 3:; lwz 3,-21492(13); li 4,3; bl _s80194CD0_5; mr 3,31; bl _s80194CD0_6; b 5f; 4:; mr 3,31; bl _s80194CD0_7; 5:; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s80194CD0_0();
extern "C" void _s80194CD0_1();
extern "C" void _s80194CD0_2();
extern "C" void _s80194CD0_3();
extern "C" void _s80194CD0_4();
extern "C" void _s80194CD0_5();
extern "C" void _s80194CD0_6();
extern "C" void _s80194CD0_7();
extern "C" void f_80194CD0() {}
