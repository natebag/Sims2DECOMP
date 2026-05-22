// 0x801890CC HUDTarget::ResetJobHudProperties(void) (244 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 29,3; li 10,0; li 3,5; addi 6,29,164; mtspr 9,3; addi 7,29,170; li 8,0; li 0,0; li 4,-100; li 5,100; addi 11,29,136; addi 9,29,188; 0:; stbx 8,6,10; stbx 8,7,10; sth 0,-12(9); addi 10,10,1; sth 0,0x0(9); sth 4,-2(11); addi 9,9,2; sth 5,0x0(11); addi 11,11,4; bdnz 0b; lwz 31,0xa0(29); li 0,0; li 9,100; sth 0,0x9a(29); sth 9,0x9c(29); cmpwi 31,0; beq 4f; lwz 9,0x0(31); cmpwi 9,0; beq 3f; lwz 0,-8(9); mulli 0,0,20; add 30,9,0; cmpw 9,30; beq 2f; 1:; addi 30,30,-20; li 4,0; mr 3,30; bl _s801890CC_0; lwz 0,0x0(31); cmpw 0,30; bne 1b; 2:; lwz 3,0x0(31); addi 3,3,-8; bl _s801890CC_1; 3:; li 30,0; mr 3,31; stw 30,0x0(31); bl _s801890CC_2; stw 30,0xa0(29); 4:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s801890CC_0();
extern "C" void _s801890CC_1();
extern "C" void _s801890CC_2();
extern "C" void f_801890CC() {}
