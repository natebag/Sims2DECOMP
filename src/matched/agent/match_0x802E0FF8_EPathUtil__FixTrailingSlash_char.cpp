// 0x802E0FF8 EPathUtil::FixTrailingSlash(char (112 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,3; cmpw 31,4; beq 0f; bl _s802E0FF8_0; 0:; mr 3,31; bl _s802E0FF8_1; mr 3,31; bl _s802E0FF8_2; mr. 3,3; beq 1f; add 9,3,31; lbz 0,-1(9); cmpwi 0,47; beq 1f; lis 4,-32702; mr 3,31; addi 4,4,-6352; bl _s802E0FF8_3; 1:; mr 3,31; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s802E0FF8_0();
extern "C" void _s802E0FF8_1();
extern "C" void _s802E0FF8_2();
extern "C" void _s802E0FF8_3();
extern "C" void f_802E0FF8() {}
