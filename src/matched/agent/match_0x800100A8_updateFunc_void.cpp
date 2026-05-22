// 0x800100A8 updateFunc(void) (96 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); bl _s800100A8_0; bl _s800100A8_1; mr. 31,3; bge 0f; li 31,0; 0:; cmpwi 31,66; ble 1f; li 31,66; 1:; mr 3,31; bl _s800100A8_2; lis 9,-32697; addi 9,9,24012; lwz 0,0x470(9); add 0,0,31; stw 0,0x470(9); lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s800100A8_0();
extern "C" void _s800100A8_1();
extern "C" void _s800100A8_2();
extern "C" void f_800100A8() {}
