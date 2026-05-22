// 0x8008B4D0 InLevelBaseState::SavePlayerInteractorState(void) (140 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); bl _s8008B4D0_0; li 4,0; li 5,1; bl _s8008B4D0_1; mr. 3,3; beq 0f; lis 9,-32697; li 0,1; stb 0,0x5e84(9); b 1f; 0:; lis 9,-32697; stb 3,0x5e84(9); 1:; lis 9,-32697; lwz 0,0x5c70(9); cmpwi 0,0; beq 3f; bl _s8008B4D0_2; li 4,1; li 5,1; bl _s8008B4D0_3; mr. 3,3; beq 2f; lis 9,-32697; li 0,1; stb 0,0x5e85(9); b 3f; 2:; lis 9,-32697; stb 3,0x5e85(9); 3:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s8008B4D0_0();
extern "C" void _s8008B4D0_1();
extern "C" void _s8008B4D0_2();
extern "C" void _s8008B4D0_3();
extern "C" void f_8008B4D0() {}
