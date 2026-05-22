// 0x80094A58 PreGameCasPlayer1State::Update(float) (152 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,3; bl _s80094A58_0; lwz 0,0x20(31); li 9,0; cmpwi 0,0; bne 0f; lwz 0,0x28(31); cmpwi 0,0; beq 0f; li 9,1; 0:; cmpwi 9,0; beq 1f; mr 3,31; li 4,2; bl _s80094A58_1; b 3f; 1:; lwz 0,0x20(31); li 9,0; cmpwi 0,0; bne 2f; lwz 0,0x2c(31); cmpwi 0,0; beq 2f; li 9,1; 2:; cmpwi 9,0; beq 3f; mr 3,31; li 4,1; bl _s80094A58_2; 3:; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s80094A58_0();
extern "C" void _s80094A58_1();
extern "C" void _s80094A58_2();
extern "C" void f_80094A58() {}
