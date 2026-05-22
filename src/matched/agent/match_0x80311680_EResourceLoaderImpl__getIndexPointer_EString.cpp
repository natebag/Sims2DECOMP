// 0x80311680 EResourceLoaderImpl::getIndexPointer(EString (188 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-48(1); mfspr 0,8; stmw 25,0x14(1); stw 0,0x34(1); mr 26,4; addi 27,3,852; li 25,0; 0:; lwz 4,0x0(27); addi 27,27,4; cmpwi 4,0; beq 3f; addi 3,1,8; li 31,0; bl _s80311680_0; lwz 9,0x8(1); addi 28,1,8; lwz 29,0x0(9); cmpw 31,29; bge 3f; mr 30,28; 1:; mr 4,31; mr 3,30; bl _s80311680_1; lwz 4,0x4(30); add 4,4,3; mr 3,26; bl _s80311680_2; cmpwi 3,0; bne 2f; addi 4,31,1; mr 3,28; bl _s80311680_3; lwz 0,0x4(28); add 3,0,3; b 4f; 2:; addi 31,31,2; cmpw 31,29; blt 1b; 3:; addi 25,25,1; cmpwi 25,1; ble 0b; li 3,0; 4:; lwz 0,0x34(1); mtspr 8,0; lmw 25,0x14(1); addi 1,1,48"
extern "C" void _s80311680_0();
extern "C" void _s80311680_1();
extern "C" void _s80311680_2();
extern "C" void _s80311680_3();
extern "C" void f_80311680() {}
