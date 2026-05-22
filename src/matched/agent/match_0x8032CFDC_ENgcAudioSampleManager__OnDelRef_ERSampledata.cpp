// 0x8032CFDC ENgcAudioSampleManager::OnDelRef(ERSampledata (68 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,4; lwz 0,-26544(13); lwz 4,0x1c(31); cmplw 4,0; blt 0f; bl _s8032CFDC_0; li 0,0; stw 0,0x1c(31); 0:; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s8032CFDC_0();
extern "C" void f_8032CFDC() {}
