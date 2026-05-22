// 0x8021E610 InteractorModule::SimInteractor::ReturnPlumbBobToOwner(void) (208 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,3; lwz 3,0x19c(31); cmpwi 3,0; beq 0f; li 0,-1; lwz 4,0x190(31); stw 0,0x190(31); bl _s8021E610_0; lwz 11,0x19c(31); li 8,1; lis 9,-32697; lwz 10,0x164(11); addi 9,9,24012; addi 30,9,188; stw 8,0x20(10); lwz 9,0x19c(31); lwz 11,0x164(9); stw 8,0x24(11); lwz 0,0x0(31); rlwinm 0,0,2,0,29; lwzx 11,30,0; cmpwi 11,0; beq 0f; lwz 9,0x4(11); li 4,36; li 5,50; lwz 0,0x144(9); lha 3,0x140(9); mtspr 8,0; add 3,11,3; blrl; lwz 0,0x0(31); rlwinm 0,0,2,0,29; lwzx 11,30,0; lwz 9,0x4(11); lha 3,0x188(9); lwz 0,0x18c(9); add 3,11,3; mtspr 8,0; blrl; lis 9,-32704; lfs f1,-8940(9); bl _s8021E610_1; 0:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s8021E610_0();
extern "C" void _s8021E610_1();
extern "C" void f_8021E610() {}
