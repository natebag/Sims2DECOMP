// 0x8034D058 ENgcSFXStreamer::Pause(unsigned (260 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,4; cmpwi 31,-1; beq 4f; bl _s8034D058_0; mulli 0,31,68; lis 9,-32690; addi 9,9,-19244; lwzx 3,9,0; add 31,0,9; cmpwi 3,0; beq 1f; lwz 0,0x40(31); cmpwi 0,0; bge 1f; li 4,7; bl _s8034D058_1; lwz 0,0x40(31); lwz 3,0x38(31); oris 0,0,16384; cmpwi 3,0; stw 0,0x40(31); beq 0f; lwz 3,0x0(3); li 4,7; bl _s8034D058_2; lwz 9,0x38(31); lwz 0,0x40(9); oris 0,0,16384; stw 0,0x40(9); 0:; lwz 3,0x34(31); cmpwi 3,0; beq 3f; lwz 3,0x0(3); li 4,7; bl _s8034D058_3; lwz 9,0x34(31); lwz 0,0x40(9); oris 0,0,16384; stw 0,0x40(9); b 3f; 1:; lwz 0,0x40(31); lwz 9,0x38(31); oris 0,0,16384; stw 0,0x40(31); cmpwi 9,0; beq 2f; lwz 0,0x40(9); oris 0,0,16384; stw 0,0x40(9); 2:; lwz 4,0x34(31); cmpwi 4,0; beq 3f; lwz 0,0x40(4); oris 0,0,16384; stw 0,0x40(4); 3:; bl _s8034D058_4; 4:; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s8034D058_0();
extern "C" void _s8034D058_1();
extern "C" void _s8034D058_2();
extern "C" void _s8034D058_3();
extern "C" void _s8034D058_4();
extern "C" void f_8034D058() {}
