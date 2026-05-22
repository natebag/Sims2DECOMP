// 0x802D7450 ENgcFileSystem::Init(EFile::DeviceType) (152 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,4; mr 30,3; bl _s802D7450_0; lis 0,-32768; cmpw 31,0; bne 0f; li 31,3; 0:; mr 4,31; mr 3,30; bl _s802D7450_1; mr. 31,3; beq 1f; lis 8,-32722; mr 3,30; addi 8,8,6424; lis 4,-32768; lis 5,-32768; lis 6,-32768; li 7,0; bl _s802D7450_2; 1:; lis 8,-32723; mr 3,30; addi 8,8,32004; lis 4,-32768; li 5,2; lis 6,-32768; li 7,0; bl _s802D7450_3; mr 3,31; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s802D7450_0();
extern "C" void _s802D7450_1();
extern "C" void _s802D7450_2();
extern "C" void _s802D7450_3();
extern "C" void f_802D7450() {}
