// 0x8007581C SimsMemCardWrap::LoadGame(int, (160 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-264(1); mfspr 0,8; stmw 30,0x100(1); stw 0,0x10c(1); mr 30,3; bl _s8007581C_0; mr 31,3; cmpwi 31,1; beq 1f; b 3f; 0:; li 31,-4; b 2f; 1:; lwz 31,-31932(13); addi 3,1,8; bl _s8007581C_1; mr 3,30; addi 4,1,8; bl _s8007581C_2; cmpwi 3,0; beq 0b; lwz 3,-32056(13); mr 4,31; rlwinm 5,30,0,24,31; bl _s8007581C_3; mr 31,3; cmpwi 31,1; bne 2f; lis 9,-32697; addi 4,1,8; lwz 3,0x5f14(9); bl _s8007581C_4; 2:; lwz 3,-31932(13); mr 4,30; bl _s8007581C_5; mr 3,31; 3:; lwz 0,0x10c(1); mtspr 8,0; lmw 30,0x100(1); addi 1,1,264"
extern "C" void _s8007581C_0();
extern "C" void _s8007581C_1();
extern "C" void _s8007581C_2();
extern "C" void _s8007581C_3();
extern "C" void _s8007581C_4();
extern "C" void _s8007581C_5();
extern "C" void f_8007581C() {}
