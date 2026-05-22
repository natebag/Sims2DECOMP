// 0x80116460 cTrack::HandleTrackFlowError(char (68 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,3; lwz 0,0x0(31); cmpwi 0,0; beq 0f; addi 3,31,44; bl _s80116460_0; 0:; mr 3,31; bl _s80116460_1; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s80116460_0();
extern "C" void _s80116460_1();
extern "C" void f_80116460() {}
