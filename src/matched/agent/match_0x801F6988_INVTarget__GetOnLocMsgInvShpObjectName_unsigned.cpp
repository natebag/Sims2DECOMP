// 0x801F6988 INVTarget::GetOnLocMsgInvShpObjectName(unsigned (256 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 30,0x20(1); stw 0,0x2c(1); mr 30,4; addi 31,1,8; lbz 4,0x3251(3); mr 5,31; addi 6,1,16; bl _s801F6988_0; lwz 0,0x10(1); cmpwi 0,9; beq 0f; blt 5f; cmpwi 0,10; beq 2f; cmpwi 0,11; beq 2f; b 5f; 0:; lwz 0,0x4(31); cmpwi 0,-1; bne 1f; lis 4,-32697; lis 5,-32704; addi 4,4,24012; addi 5,5,-26072; addi 3,1,20; crxor 6,6,6; bl _s801F6988_1; lwz 9,0x14(1); li 4,0; b 3f; 1:; lwz 9,0x8(1); li 4,0; lwz 9,0x8(9); b 3f; 2:; lwz 9,0x8(1); li 4,0; lwz 9,0x4(9); 3:; cmpwi 9,0; beq 4f; lwz 4,0x0(9); 4:; mr 3,30; bl _s801F6988_2; b 7f; 5:; lwz 0,0x10(1); cmplwi 0,14; bgt 7f; lwz 4,0x8(1); addi 3,1,24; crxor 6,6,6; bl _s801F6988_3; lwz 9,0x18(1); li 4,0; cmpwi 9,0; beq 6f; lwz 4,0x0(9); 6:; mr 3,30; bl _s801F6988_4; 7:; lwz 0,0x2c(1); mtspr 8,0; lmw 30,0x20(1); addi 1,1,40"
extern "C" void _s801F6988_0();
extern "C" void _s801F6988_1();
extern "C" void _s801F6988_2();
extern "C" void _s801F6988_3();
extern "C" void _s801F6988_4();
extern "C" void f_801F6988() {}
