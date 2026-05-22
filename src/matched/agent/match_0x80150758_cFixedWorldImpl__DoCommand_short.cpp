// 0x80150758 cFixedWorldImpl::DoCommand(short, (156 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stw 31,0x1c(1); stw 0,0x24(1); mr 31,3; stw 5,0x10(1); cmpwi 4,145; beq 0f; cmpwi 4,258; beq 1f; b 2f; 0:; lwz 9,0x0(31); mr 4,5; lha 3,0x110(9); lwz 0,0x114(9); add 3,31,3; mtspr 8,0; blrl; li 3,1; b 3f; 1:; lha 4,0x12(1); li 6,0; lha 5,0x10(1); addi 3,1,8; bl _s80150758_0; addi 4,1,8; mr 3,31; bl _s80150758_1; addi 3,1,8; li 4,2; bl _s80150758_2; li 3,1; b 3f; 2:; li 3,0; 3:; lwz 0,0x24(1); mtspr 8,0; lwz 31,0x1c(1); addi 1,1,32"
extern "C" void _s80150758_0();
extern "C" void _s80150758_1();
extern "C" void _s80150758_2();
extern "C" void f_80150758() {}
