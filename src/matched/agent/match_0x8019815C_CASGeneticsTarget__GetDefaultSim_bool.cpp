// 0x8019815C CASGeneticsTarget::GetDefaultSim(bool, (184 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 30,4; mr 31,5; mr 29,3; li 4,0; mr 3,31; bl _s8019815C_0; stw 30,0x84(31); cmpwi 30,0; beq 0f; li 9,0; li 11,1; li 10,0; li 0,4; stb 9,0xc4(31); stb 0,0xc5(31); stb 10,0xcc(31); stb 11,0xcd(31); stb 9,0x98(31); stb 9,0x99(31); stw 11,0xa0(31); stw 10,0xc8(31); b 1f; 0:; li 0,1; li 9,4; stb 0,0x98(31); stb 9,0xc5(31); stb 30,0xcd(31); stb 30,0x99(31); stw 30,0xa0(31); stb 30,0xc4(31); stw 30,0xc8(31); stb 30,0xcc(31); 1:; lwz 3,0x94(29); mr 4,31; bl _s8019815C_1; mr 3,31; bl _s8019815C_2; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s8019815C_0();
extern "C" void _s8019815C_1();
extern "C" void _s8019815C_2();
extern "C" void f_8019815C() {}
