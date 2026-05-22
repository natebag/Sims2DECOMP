// 0x802A1010 AptSharedPtrDelete(AptFile (132 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr. 31,3; beq 1f; lwz 3,-23000(13); mr 4,31; bl _s802A1010_0; lwz 9,0x8(31); addi 9,9,-3; cmplwi 9,2; bgt 0f; lwz 3,0x10(31); lwz 4,0xc(31); addi 3,3,8; bl _s802A1010_1; lis 9,-32694; lwz 3,0x14(31); lwz 0,-16252(9); mtspr 8,0; blrl; 0:; addi 3,31,4; li 4,2; bl _s802A1010_2; mr 3,31; li 4,24; bl _s802A1010_3; 1:; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s802A1010_0();
extern "C" void _s802A1010_1();
extern "C" void _s802A1010_2();
extern "C" void _s802A1010_3();
extern "C" void f_802A1010() {}
