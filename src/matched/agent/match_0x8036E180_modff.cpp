// 0x8036E180 modff (160 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); stfs f1,0x8(1); lwz 8,0x8(1); mr 10,8; mr 11,10; rlwinm 9,11,9,24,31; addi 9,9,-127; cmpwi 9,22; bgt 2f; cmpwi 9,0; bge 0f; rlwinm 0,11,0,0,0; stw 0,0x0(3); b 3f; 0:; lis 0,127; ori 0,0,65535; sraw 0,0,9; and. 9,11,0; bne 1f; stw 8,0x0(3); rlwinm 8,11,0,0,0; stw 8,0x8(1); lfs f0,0x8(1); fmr f1,f0; b 3f; 1:; andc 0,10,0; stw 0,0x0(3); stw 8,0x8(1); lfs f13,0x8(1); stw 0,0x8(1); lfs f0,0x8(1); fsubs f1,f13,f0; b 3f; 2:; stw 8,0x0(3); rlwinm 8,10,0,0,0; stw 8,0x8(1); lfs f13,0x8(1); fmr f1,f13; 3:; addi 1,1,16"
extern "C" void f_8036E180() {}
