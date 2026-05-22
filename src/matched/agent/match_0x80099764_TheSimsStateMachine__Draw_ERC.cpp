// 0x80099764 TheSimsStateMachine::Draw(ERC (120 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 30,3; mr 31,4; lis 3,-32697; addi 3,3,23428; bl _s80099764_0; mr. 3,3; lis 9,-32697; beq 0f; addi 9,9,23428; li 0,1; stw 0,0x88(9); mr 3,30; mr 4,31; bl _s80099764_1; b 1f; 0:; addi 9,9,23428; stw 3,0x88(9); 1:; lis 3,-32697; mr 4,31; addi 3,3,23428; bl _s80099764_2; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s80099764_0();
extern "C" void _s80099764_1();
extern "C" void _s80099764_2();
extern "C" void f_80099764() {}
