// 0x801C861C MMUTarget::OnNGHSelect(char (152 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,3; mr 3,5; bl _s801C861C_0; mr 30,3; lis 4,-32700; rlwinm 0,30,4,0,27; addi 4,4,-25964; lis 3,-32697; add 4,0,4; addi 3,3,-7672; bl _s801C861C_1; stw 30,0x9c(31); lis 9,-32697; addi 9,9,23428; lwz 0,0xf0(9); cmpwi 0,0; beq 0f; lwz 0,0xe8(9); cmpwi 0,0; beq 0f; mr 3,31; bl _s801C861C_2; b 1f; 0:; li 0,2; li 9,1; stw 0,0x8c(31); stw 9,0x90(31); 1:; mr 3,31; bl _s801C861C_3; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s801C861C_0();
extern "C" void _s801C861C_1();
extern "C" void _s801C861C_2();
extern "C" void _s801C861C_3();
extern "C" void f_801C861C() {}
