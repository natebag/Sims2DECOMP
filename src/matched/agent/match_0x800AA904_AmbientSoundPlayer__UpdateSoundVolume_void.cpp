// 0x800AA904 AmbientSoundPlayer::UpdateSoundVolume(void) (176 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 29,3; lwz 0,0x8(29); cmpwi 0,0; beq 1f; lwz 10,0x4(29); lis 30,20971; lwz 9,0xc(29); ori 30,30,34079; lbz 11,0x18(10); lwz 3,0x0(29); mullw 9,9,11; mulhw 0,9,30; srawi 9,9,31; srawi 0,0,5; subf 31,9,0; bl _s800AA904_0; lbz 0,0x2a(3); lwz 3,0x0(29); mullw 0,31,0; mulhw 30,0,30; srawi 0,0,31; srawi 30,30,5; subf 31,0,30; bl _s800AA904_1; mullw. 4,31,3; bge 0f; addi 4,4,1023; 0:; lwz 3,0x8(29); srawi 4,4,10; lwz 9,0x0(3); lha 0,0x60(9); lwz 9,0x64(9); add 3,3,0; mtspr 8,9; blrl; 1:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s800AA904_0();
extern "C" void _s800AA904_1();
extern "C" void f_800AA904() {}
