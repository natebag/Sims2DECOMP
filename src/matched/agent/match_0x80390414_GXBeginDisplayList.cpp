// 0x80390414 GXBeginDisplayList (204 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; lis 5,-32688; stw 0,0x4(1); stwu 1,-32(1); stw 31,0x1c(1); addi 31,5,-21840; stw 30,0x18(1); stw 29,0x14(1); addi 29,4,0; stw 28,0x10(1); addi 28,3,0; bl _s80390414_0; lwz 4,-17720(13); mr 30,3; lwz 0,0x5ac(4); cmplwi 0,0; beq 0f; bl _s80390414_1; 0:; lwz 4,-17720(13); lbz 0,0x5a9(4); cmplwi 0,0; beq 1f; addi 3,31,36; li 5,1456; bl _s80390414_2; 1:; addi 0,29,-4; stw 28,0x0(31); add 0,28,0; stw 0,0x4(31); li 4,0; li 0,1; stw 29,0x8(31); mr 3,30; stw 4,0x1c(31); stw 28,0x14(31); stw 28,0x18(31); lwz 4,-17720(13); stb 0,0x5a8(4); bl _s80390414_3; stw 30,-21904(13); mr 3,31; bl _s80390414_4; bl _s80390414_5; lwz 0,0x24(1); lwz 31,0x1c(1); lwz 30,0x18(1); lwz 29,0x14(1); lwz 28,0x10(1); addi 1,1,32; mtspr 8,0"
extern "C" void _s80390414_0();
extern "C" void _s80390414_1();
extern "C" void _s80390414_2();
extern "C" void _s80390414_3();
extern "C" void _s80390414_4();
extern "C" void _s80390414_5();
extern "C" void f_80390414() {}
