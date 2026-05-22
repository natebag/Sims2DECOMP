// 0x8032C8E0 ENgcAudio::GetVoiceState(EVoice (144 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,4; li 0,0; lwz 4,0x8(31); mr 30,5; stw 0,0x18(31); cmpwi 4,-1; beq 0f; lwz 3,-26556(13); bl _s8032C8E0_0; stw 3,0x18(31); 0:; li 0,31; stw 0,0x0(30); lwz 9,0x4(31); cmpwi 9,0; beq 1f; lwz 0,0x24(9); stw 0,0x14(30); b 2f; 1:; stw 9,0x14(30); 2:; lwz 0,0x18(31); stw 0,0x10(30); lfs f0,0x14(31); stfs f0,0xc(30); lfs f13,0xc(31); stfs f13,0x4(30); lfs f0,0x10(31); stfs f0,0x8(30); lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s8032C8E0_0();
extern "C" void f_8032C8E0() {}
