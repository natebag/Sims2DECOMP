// 0x8005A184 PlumbBob::SetParticleVisibility(bool) (148 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; mfcr 12; stmw 28,0x10(1); stw 0,0x24(1); stw 12,0xc(1); mr 31,3; li 29,0; lwz 0,0x1f4(31); mr 28,4; cmpw 29,0; bge 3f; cmpwi 4,28,0; addi 30,31,492; 0:; lwz 3,0x0(30); li 4,4; addi 30,30,4; mr 5,28; bl _s8005A184_0; beq cr4,1f; lwz 0,0x154(31); ori 0,0,16; b 2f; 1:; lwz 0,0x154(31); rlwinm 0,0,0,28,26; 2:; stw 0,0x154(31); lwz 0,0x1f4(31); addi 29,29,1; cmpw 29,0; blt 0b; 3:; lwz 0,0x24(1); lwz 12,0xc(1); mtspr 8,0; lmw 28,0x10(1); mtcrf 8,12; addi 1,1,32"
extern "C" void _s8005A184_0();
extern "C" void f_8005A184() {}
