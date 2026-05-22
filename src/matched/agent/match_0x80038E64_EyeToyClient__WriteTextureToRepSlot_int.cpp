// 0x80038E64 EyeToyClient::WriteTextureToRepSlot(int, (136 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 27,0xc(1); stw 0,0x24(1); mulli 3,3,12; lis 9,-32702; addi 9,9,15808; mr 27,5; li 30,1; lwzx 31,3,9; add 29,3,9; lwz 3,0x4(31); bl _s80038E64_0; lwz 9,0x4(31); lwz 0,0x4(29); lwz 28,0x20(9); cmpw 30,0; bge 1f; addi 31,31,12; 0:; lwz 3,0x0(31); mr 4,28; li 5,0; addi 30,30,1; bl _s80038E64_1; addi 31,31,8; lwz 0,0x4(29); cmpw 30,0; blt 0b; 1:; stw 27,0x8(29); lwz 0,0x24(1); mtspr 8,0; lmw 27,0xc(1); addi 1,1,32"
extern "C" void _s80038E64_0();
extern "C" void _s80038E64_1();
extern "C" void f_80038E64() {}
