// 0x8024A8FC new_eh_context (136 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); lis 31,-32688; lwz 0,-5176(31); cmpwi 0,0; bne 0f; lis 5,-32704; li 3,0; addi 5,5,952; li 4,0; crxor 6,6,6; bl _s8024A8FC_0; 0:; lwz 0,-5176(31); li 3,24; mtspr 8,0; blrl; mr. 31,3; bne 1f; bl _s8024A8FC_1; 1:; mr 3,31; li 4,0; li 5,24; crxor 6,6,6; bl _s8024A8FC_2; addi 0,31,16; mr 3,31; stw 0,0x4(31); lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s8024A8FC_0();
extern "C" void _s8024A8FC_1();
extern "C" void _s8024A8FC_2();
extern "C" void f_8024A8FC() {}
