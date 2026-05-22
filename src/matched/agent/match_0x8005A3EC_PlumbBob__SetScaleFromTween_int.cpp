// 0x8005A3EC PlumbBob::SetScaleFromTween(int, (112 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 9,-32697; rlwinm 4,4,2,0,29; addi 9,9,24012; addi 9,9,280; lwzx 11,9,4; li 9,0; lwz 0,0x160(11); cmpwi 0,0; beq 0f; cmpwi 0,8; beq 0f; li 9,1; 0:; cmpwi 9,0; bne 1f; lis 9,-32696; lis 11,-32707; lfs f0,0x55e4(9); lfs f13,0x4214(11); lwz 9,0x164(3); fsubs f0,f0,f13; fmadds f0,f0,f1,f13; stfs f0,0x0(9); blr; 1:; lis 9,-32707; lwz 11,0x164(3); lfs f0,0x4214(9); stfs f0,0x0(11)"
extern "C" void f_8005A3EC() {}
