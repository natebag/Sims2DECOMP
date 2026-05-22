// 0x8007D620 CTGMicroTimer::GetElapsedTime(void) (136 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stw 31,0x14(1); stw 0,0x1c(1); mr 31,3; lwz 0,0x18(31); cmpwi 0,0; beq 0f; addi 3,1,8; bl _s8007D620_0; lwz 3,0x8(1); lwz 4,0xc(1); b 1f; 0:; lwz 3,0x8(31); lwz 4,0xc(31); 1:; lis 0,15; lwz 11,0x0(31); lwz 12,0x4(31); ori 0,0,16960; lwz 5,0x10(31); lwz 6,0x14(31); subfc 10,12,4; subfe 9,11,3; mullw 8,9,0; mulhwu 3,10,0; mullw 4,10,0; add 3,3,8; crxor 6,6,6; bl _s8007D620_1; lwz 0,0x1c(1); mtspr 8,0; lwz 31,0x14(1); addi 1,1,24"
extern "C" void _s8007D620_0();
extern "C" void _s8007D620_1();
extern "C" void f_8007D620() {}
