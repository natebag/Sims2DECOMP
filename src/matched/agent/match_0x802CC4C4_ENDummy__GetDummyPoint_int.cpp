// 0x802CC4C4 ENDummy::GetDummyPoint(int) (108 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mulli 5,5,80; lwz 9,0x48(4); mr 30,3; addi 10,30,4; addi 3,30,16; lwzx 0,9,5; add 9,9,5; stw 0,0x0(30); addi 11,9,4; addi 4,9,16; lfs f0,0x4(9); stfs f0,0x4(30); lfs f13,0x4(11); stfs f13,0x4(10); lfs f0,0x8(11); stfs f0,0x8(10); bl _s802CC4C4_0; mr 3,30; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s802CC4C4_0();
extern "C" void f_802CC4C4() {}
