// 0x801BBF6C INGTarget::create_edit_buffer(void) (424 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-328(1); mfspr 0,8; stmw 24,0x128(1); stw 0,0x14c(1); mr 27,3; li 4,0; addi 30,27,516; li 5,576; mr 3,30; bl _s801BBF6C_0; lwz 0,0x200(27); cmpwi 0,0; bne 0f; li 3,0; b 9f; 0:; bl _s801BBF6C_1; mr. 0,3; li 3,0; beq 9f; mr 3,0; addi 4,1,8; li 5,72; li 26,0; bl _s801BBF6C_2; li 28,0; lwz 3,0x200(27); addi 24,1,8; bl _s801BBF6C_3; mr 25,3; cmplw 26,25; bge 3f; mr 29,30; addi 31,27,520; 1:; lwz 3,0x200(27); mr 4,28; bl _s801BBF6C_4; mr. 30,3; beq 2f; mr 3,30; bl _s801BBF6C_5; cmpwi 3,6; bne 2f; mr 3,29; bl _s801BBF6C_6; mr 3,30; bl _s801BBF6C_7; extsh 5,3; li 4,72; addi 3,1,8; bl _s801BBF6C_8; cmpwi 3,0; stw 3,-4(31); beq 2f; mr 3,30; addi 29,29,8; bl _s801BBF6C_9; addi 26,26,1; stw 3,0x0(31); addi 31,31,8; 2:; addi 28,28,1; cmplw 28,25; blt 1b; 3:; li 29,0; lwzx 31,24,29; cmpwi 31,0; beq 8f; rlwinm 9,26,3,0,28; lis 28,15; addi 9,9,520; mr 25,24; add 30,9,27; ori 28,28,16960; 4:; lha 0,0x2(31); cmpwi 0,0; bne 5f; lwz 3,0x200(27); li 5,0; lha 4,0x0(31); bl _s801BBF6C_10; mr. 3,3; bne 7f; stw 31,-4(30); stw 3,0x0(30); b 6f; 5:; lwz 9,0x28(31); lwz 0,-30260(13); cmpw 9,0; bgt 7f; stw 31,-4(30); stw 28,0x0(30); 6:; addi 26,26,1; addi 30,30,8; cmplwi 26,71; bgt 8f; 7:; addi 29,29,1; cmplwi 29,71; bgt 8f; lwzu 31,0x4(25); cmpwi 31,0; bne 4b; 8:; li 3,1; 9:; lwz 0,0x14c(1); mtspr 8,0; lmw 24,0x128(1); addi 1,1,328"
extern "C" void _s801BBF6C_0();
extern "C" void _s801BBF6C_1();
extern "C" void _s801BBF6C_2();
extern "C" void _s801BBF6C_3();
extern "C" void _s801BBF6C_4();
extern "C" void _s801BBF6C_5();
extern "C" void _s801BBF6C_6();
extern "C" void _s801BBF6C_7();
extern "C" void _s801BBF6C_8();
extern "C" void _s801BBF6C_9();
extern "C" void _s801BBF6C_10();
extern "C" void f_801BBF6C() {}
