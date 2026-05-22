// 0x80226A58 InteractorModule::WallPainter::RestoreFromHoldPos(EVec3 (116 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); lwz 0,0x88(3); andi. 9,0,4096; beq 0f; addi 9,3,120; lwz 10,0x78(3); lwz 0,0x8(9); lwz 11,0x4(9); stw 0,0x8(4); stw 10,0x0(4); stw 11,0x4(4); lwz 0,0x88(3); rlwinm 0,0,0,20,18; stw 0,0x88(3); b 1f; 0:; lis 11,-32704; addi 9,1,8; lfs f0,-7160(11); stfs f0,0x8(9); stfs f0,0x4(9); stfs f0,0x8(1); lwz 0,0x8(9); lwz 11,0x8(1); lwz 10,0x4(9); stw 0,0x8(4); stw 11,0x0(4); stw 10,0x4(4); 1:; addi 1,1,24"
extern "C" void f_80226A58() {}
