// 0x801F65C8 INVTarget::GetOnMsgInvSelectExitReset(char (240 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); lis 9,-32697; mr 31,4; lwz 0,0x618c(9); cmpwi 0,0; beq 0f; bl _s801F65C8_0; b 6f; 0:; lwz 9,0x84(3); addi 10,13,-28700; addi 8,3,216; lis 11,-32704; rlwinm 9,9,2,0,29; addi 30,11,-30820; lwzx 0,9,10; rlwinm 0,0,2,0,29; lwzx 3,8,0; cmpwi 3,0; beq 3f; bl _s801F65C8_1; bl _s801F65C8_2; cmpwi 3,0; beq 2f; lwz 0,-31536(13); cmpwi 0,0; bne 1f; li 3,120; bl _s801F65C8_3; bl _s801F65C8_4; stw 3,-31536(13); 1:; lis 4,28199; lwz 3,-31536(13); ori 4,4,30903; bl _s801F65C8_5; b 5f; 2:; lis 9,-32704; addi 30,9,-30824; b 5f; 3:; lwz 0,-31536(13); cmpwi 0,0; bne 4f; li 3,120; bl _s801F65C8_6; bl _s801F65C8_7; stw 3,-31536(13); 4:; lis 4,28199; lwz 3,-31536(13); ori 4,4,30903; bl _s801F65C8_8; 5:; mr 3,31; mr 4,30; bl _s801F65C8_9; 6:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s801F65C8_0();
extern "C" void _s801F65C8_1();
extern "C" void _s801F65C8_2();
extern "C" void _s801F65C8_3();
extern "C" void _s801F65C8_4();
extern "C" void _s801F65C8_5();
extern "C" void _s801F65C8_6();
extern "C" void _s801F65C8_7();
extern "C" void _s801F65C8_8();
extern "C" void _s801F65C8_9();
extern "C" void f_801F65C8() {}
