// 0x80090E94 LoadingScreenStateMachine::FaderUpdate(float) (108 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="addi 3,3,168; lwz 0,0xc(3); andi. 9,0,16; beqlr; lis 9,-32706; lfs f0,0x8(3); lfs f13,-32572(9); fcmpu 0,f0,f13; beqlr; fsubs f0,f0,f1; fcmpu 0,f0,f13; stfs f0,0x8(3); cror 3,2,0; bnslr; stfs f13,0x8(3); andi. 9,0,1; beq 0f; rlwinm 0,0,0,0,30; ori 0,0,4; stw 0,0xc(3); blr; 0:; andi. 9,0,2; beqlr; rlwinm 0,0,0,31,29; ori 0,0,8; stw 0,0xc(3)"
extern "C" void f_80090E94() {}
