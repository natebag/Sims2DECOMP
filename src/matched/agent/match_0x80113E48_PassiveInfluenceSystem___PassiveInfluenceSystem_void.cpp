// 0x80113E48 PassiveInfluenceSystem::~PassiveInfluenceSystem(void) (188 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); lwz 0,-31780(13); mr 31,3; mr 29,4; cmpw 0,31; bne 0f; lwz 3,-31784(13); li 0,0; stw 0,-31780(13); cmpwi 3,0; beq 0f; bl _s80113E48_0; 0:; addi 30,31,16; mr 3,30; bl _s80113E48_1; lwz 3,0x4(30); cmpwi 3,0; beq 1f; li 4,12; bl _s80113E48_2; 1:; addi 30,31,8; mr 3,30; bl _s80113E48_3; lwz 3,0x4(30); cmpwi 3,0; beq 2f; li 4,12; bl _s80113E48_4; 2:; mr 3,31; bl _s80113E48_5; lwz 3,0x4(31); cmpwi 3,0; beq 3f; li 4,12; bl _s80113E48_6; 3:; andi. 0,29,1; beq 4f; mr 3,31; bl _s80113E48_7; 4:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s80113E48_0();
extern "C" void _s80113E48_1();
extern "C" void _s80113E48_2();
extern "C" void _s80113E48_3();
extern "C" void _s80113E48_4();
extern "C" void _s80113E48_5();
extern "C" void _s80113E48_6();
extern "C" void _s80113E48_7();
extern "C" void f_80113E48() {}
