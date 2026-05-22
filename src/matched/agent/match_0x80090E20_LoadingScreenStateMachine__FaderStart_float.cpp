// 0x80090E20 LoadingScreenStateMachine::FaderStart(float, (104 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" replace="" lines="li 0,16; addi 10,3,168; stw 0,0xc(10); cmpwi 4,0; beq 1f; stfs f1,0x8(10); lis 9,-32706; stfs f1,0xa8(3); li 11,-14; lfs f0,-32576(9); lwz 0,0xc(10); fdivs f0,f0,f1; and 0,0,11; ori 0,0,2; 0:; stw 0,0xc(10); stfs f0,0x4(10); blr; 1:; stfs f1,0x8(10); lis 9,-32706; stfs f1,0xa8(3); lfs f0,-32576(9); lwz 0,0xc(10); fdivs f0,f0,f1; rlwinm 0,0,0,31,27; ori 0,0,1; b 0b"
extern "C" void f_80090E20() {}
