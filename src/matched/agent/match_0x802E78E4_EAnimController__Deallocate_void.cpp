// 0x802E78E4 EAnimController::Deallocate(void) (272 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 30,3; bl _s802E78E4_0; mr 3,30; bl _s802E78E4_1; lwz 0,0xc(30); cmpwi 0,0; beq 0f; bl _s802E78E4_2; lwz 4,0xc(30); bl _s802E78E4_3; li 0,0; stw 0,0xc(30); 0:; lwz 0,0x44(30); mr 3,0; cmpwi 0,0; beq 4f; lwz 0,-8(3); mulli 0,0,176; add 31,3,0; cmpw 3,31; beq 3f; li 29,0; 1:; addi 31,31,-176; addi 3,31,140; bl _s802E78E4_4; lwz 3,0x7c(31); cmpwi 3,0; beq 2f; bl _s802E78E4_5; stw 29,0x7c(31); 2:; lwz 0,0x44(30); mr 3,0; cmpw 0,31; bne 1b; 3:; addi 3,3,-8; bl _s802E78E4_6; li 0,0; stw 0,0x44(30); 4:; lwz 0,0x70(30); cmpwi 0,0; beq 5f; bl _s802E78E4_7; lwz 4,0x70(30); bl _s802E78E4_8; li 0,0; stw 0,0x70(30); 5:; lwz 3,0x24(30); li 31,0; li 0,-1; stw 31,0x6c(30); stw 0,0x8(30); cmpwi 3,0; stw 31,0x38(30); stw 31,0x3c(30); stw 31,0x40(30); beq 6f; bl _s802E78E4_9; stw 31,0x24(30); 6:; stw 31,0x24(30); lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s802E78E4_0();
extern "C" void _s802E78E4_1();
extern "C" void _s802E78E4_2();
extern "C" void _s802E78E4_3();
extern "C" void _s802E78E4_4();
extern "C" void _s802E78E4_5();
extern "C" void _s802E78E4_6();
extern "C" void _s802E78E4_7();
extern "C" void _s802E78E4_8();
extern "C" void _s802E78E4_9();
extern "C" void f_802E78E4() {}
