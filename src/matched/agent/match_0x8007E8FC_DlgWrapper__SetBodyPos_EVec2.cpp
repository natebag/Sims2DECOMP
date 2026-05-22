// 0x8007E8FC DlgWrapper::SetBodyPos(EVec2 (88 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 0,0x14(1); mr 9,4; addi 11,1,8; lfs f13,0x0(9); mr 4,11; lfs f0,0x4(9); stfs f13,0x8(1); stfs f0,0x4(11); lwz 9,0xac(3); lwz 10,0x64(9); lwz 11,0x1c(10); lha 3,0x38(11); lwz 0,0x3c(11); add 3,10,3; mtspr 8,0; blrl; lwz 0,0x14(1); mtspr 8,0; addi 1,1,16"
extern "C" void f_8007E8FC() {}
