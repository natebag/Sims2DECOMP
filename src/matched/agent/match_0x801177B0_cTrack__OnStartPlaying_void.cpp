// 0x801177B0 cTrack::OnStartPlaying(void) (156 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,3; lwz 9,0x0(31); lbz 0,0x1a(9); cmplwi 0,99; bgt 1f; cmpwi 0,0; beq 0f; bl _s801177B0_0; li 0,100; lwz 9,0x0(31); divwu 0,3,0; lbz 11,0x1a(9); mulli 0,0,100; subf 3,0,3; cmpw 3,11; blt 1f; 0:; li 3,0; b 3f; 1:; lwz 5,0x0(31); lbz 0,0x1c(5); andi. 9,0,1; beq 2f; lbz 5,0x16(5); cmplwi 5,1; ble 2f; mr 3,31; addi 5,5,-1; li 4,17; bl _s801177B0_1; 2:; li 3,1; 3:; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s801177B0_0();
extern "C" void _s801177B0_1();
extern "C" void f_801177B0() {}
