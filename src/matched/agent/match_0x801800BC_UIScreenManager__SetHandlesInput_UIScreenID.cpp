// 0x801800BC UIScreenManager::SetHandlesInput(UIScreenID, (224 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-144(1); mfspr 0,8; stmw 27,0x7c(1); stw 0,0x94(1); addi 30,1,8; mr 29,3; mr 28,4; mr 27,5; li 4,0; li 5,64; mr 3,30; crxor 6,6,6; bl _s801800BC_0; mr 3,29; mr 5,28; mr 4,30; bl _s801800BC_1; lis 9,-32706; stw 30,0x6c(1); addi 9,9,15232; cmpwi 27,0; stw 9,0x68(1); beq 0f; lis 9,-32706; addi 9,9,15248; b 1f; 0:; lis 9,-32706; addi 9,9,15252; 1:; stw 9,0x70(1); addi 10,1,88; lwz 0,0x68(1); addi 9,1,104; lwz 29,0x8(9); addi 11,1,72; lwz 30,0x4(9); lis 4,-32706; stw 0,0x58(1); addi 4,4,15128; stw 29,0x8(10); mr 8,11; stw 30,0x4(10); li 5,0; lwz 3,-25136(13); li 6,0; lwz 0,0x58(1); li 7,3; stw 0,0x48(1); stw 30,0x4(11); stw 29,0x8(11); bl _s801800BC_2; li 3,1; lwz 0,0x94(1); mtspr 8,0; lmw 27,0x7c(1); addi 1,1,144"
extern "C" void _s801800BC_0();
extern "C" void _s801800BC_1();
extern "C" void _s801800BC_2();
extern "C" void f_801800BC() {}
