// 0x8022C3A0 EIStaticModel::SetupModel(EInstance (252 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stfd f31,0x10(1); stw 31,0xc(1); stw 0,0x1c(1); mr 31,3; lwz 11,0x120(31); cmpwi 11,0; beq 0f; lwz 9,0x8(11); lwz 0,0x110(31); cmpw 9,0; beq 7f; lfs f31,0x88(11); b 1f; 0:; lis 9,-32704; lfs f31,-4596(9); 1:; stw 4,0x18(31); mr 3,31; stw 5,0x7c(31); bl _s8022C3A0_0; lwz 4,0x110(31); cmpwi 4,0; beq 3f; lis 3,-32692; li 5,0; addi 3,3,-27556; li 6,0; bl _s8022C3A0_1; stw 3,0x120(31); cmpwi 3,0; beq 7f; bl _s8022C3A0_2; cmpwi 3,0; beq 2f; lwz 3,0x120(31); bl _s8022C3A0_3; 2:; mr 3,31; bl _s8022C3A0_4; 3:; lwz 9,0x120(31); cmpwi 9,0; beq 4f; lfs f1,0x88(9); b 5f; 4:; lis 9,-32704; lfs f1,-4596(9); 5:; fcmpu 0,f1,f31; beq 6f; fdivs f1,f1,f31; addi 3,31,128; bl _s8022C3A0_5; 6:; lwz 3,0x120(31); bl _s8022C3A0_6; cmpwi 3,0; beq 7f; li 0,0; stw 0,0x114(31); 7:; lwz 0,0x1c(1); mtspr 8,0; lwz 31,0xc(1); lfd f31,0x10(1); addi 1,1,24"
extern "C" void _s8022C3A0_0();
extern "C" void _s8022C3A0_1();
extern "C" void _s8022C3A0_2();
extern "C" void _s8022C3A0_3();
extern "C" void _s8022C3A0_4();
extern "C" void _s8022C3A0_5();
extern "C" void _s8022C3A0_6();
extern "C" void f_8022C3A0() {}
