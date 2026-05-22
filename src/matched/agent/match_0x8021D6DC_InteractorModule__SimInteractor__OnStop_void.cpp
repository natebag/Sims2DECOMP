// 0x8021D6DC InteractorModule::SimInteractor::OnStop(void) (136 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,3; lis 9,-32697; lwz 11,0x0(31); addi 9,9,24012; li 0,1; addi 9,9,184; stbx 0,9,11; bl _s8021D6DC_0; lwz 4,0x0(31); bl _s8021D6DC_1; lwz 0,0x0(31); li 3,0; cmplwi 0,1; bgt 0f; rlwinm 0,0,2,0,29; addi 9,13,-21420; lwzx 0,9,0; cmpwi 0,0; beq 0f; mr 3,0; 0:; stw 3,0x19c(31); cmpwi 3,0; beq 1f; li 4,3; bl _s8021D6DC_2; 1:; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s8021D6DC_0();
extern "C" void _s8021D6DC_1();
extern "C" void _s8021D6DC_2();
extern "C" void f_8021D6DC() {}
