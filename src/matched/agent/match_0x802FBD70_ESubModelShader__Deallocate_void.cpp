// 0x802FBD70 ESubModelShader::Deallocate(void) (204 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,3; lwz 4,0x0(31); cmpwi 4,0; beq 1f; lwz 3,-26392(13); lwz 9,0x0(3); lha 0,0xb0(9); lwz 9,0xb4(9); add 3,3,0; mtspr 8,9; blrl; cmpwi 3,0; beq 0f; lwz 3,-26392(13); lwz 9,0x0(3); lha 0,0x40(9); lwz 9,0x44(9); add 3,3,0; mtspr 8,9; blrl; 0:; lwz 11,-26392(13); lwz 4,0x0(31); lwz 9,0x0(11); lwz 0,0xac(9); lha 3,0xa8(9); mtspr 8,0; add 3,11,3; blrl; li 0,0; stw 0,0x0(31); 1:; lwz 3,0x8(31); cmpwi 3,0; beq 2f; bl _s802FBD70_0; li 0,0; stw 0,0x8(31); 2:; mr 3,31; bl _s802FBD70_1; mr 3,31; bl _s802FBD70_2; mr 3,31; bl _s802FBD70_3; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s802FBD70_0();
extern "C" void _s802FBD70_1();
extern "C" void _s802FBD70_2();
extern "C" void _s802FBD70_3();
extern "C" void f_802FBD70() {}
