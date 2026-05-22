// 0x8005AF94 PlumbBob::ResetMomentum(bool) (120 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); lis 9,-32707; addi 8,1,8; lfs f0,0x4240(9); cmpwi 4,0; stfs f0,0x8(8); stfs f0,0x4(8); stfs f0,0x8(1); beq 0f; lfs f0,0x14(3); stfs f0,0x10(1); 0:; lwz 0,0x8(1); addi 10,3,12; lwz 9,0x4(8); lwz 11,0x8(8); stw 0,0xc(3); stw 9,0x4(10); stw 11,0x8(10); beq 1f; lfs f0,0x8(10); stfs f0,0x10(1); 1:; lwz 10,0x8(1); addi 11,3,24; lwz 0,0x8(8); lwz 9,0x4(8); stw 10,0x18(3); stw 0,0x8(11); stw 9,0x4(11); addi 1,1,24"
extern "C" void f_8005AF94() {}
