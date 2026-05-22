// 0x80138B98 SpacePartition::FindInterfacePoint(ASTNode (136 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 30,0x20(1); stw 0,0x2c(1); mr 30,3; mr 3,4; mr 4,5; mr 5,6; addi 6,1,16; bl _s80138B98_0; lwz 10,0x14(1); mr 3,30; lwz 9,0x1c(1); lwz 0,0x18(1); lwz 8,0x10(1); add 9,9,10; rlwinm 11,9,1,31,31; add 0,0,8; add 9,9,11; rlwinm 10,0,1,31,31; srawi 9,9,1; add 0,0,10; stw 9,0x8(1); srawi 0,0,1; stw 0,0xc(1); lwz 9,0x8(1); lwz 10,0xc(1); stw 9,0x0(30); stw 10,0x4(30); lwz 0,0x2c(1); mtspr 8,0; lmw 30,0x20(1); addi 1,1,40"
extern "C" void _s80138B98_0();
extern "C" void f_80138B98() {}
