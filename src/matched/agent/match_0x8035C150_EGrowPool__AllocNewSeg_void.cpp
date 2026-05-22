// 0x8035C150 EGrowPool::AllocNewSeg(void) (216 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,3; lwz 0,0x8(31); cmpwi 0,2044; ble 0f; bl _s8035C150_0; lwz 4,0x8(31); li 5,16; li 6,0; li 7,0; bl _s8035C150_1; mr 8,3; b 3f; 0:; bl _s8035C150_2; li 4,4096; li 5,32; li 6,0; li 7,0; bl _s8035C150_3; mr. 3,3; beq 2f; lwz 0,0x4(31); li 11,4088; li 10,1; stw 0,0x0(3); stw 3,0x4(31); lwz 9,0x8(31); divw 11,11,9; mullw 9,11,9; cmpw 10,11; addi 9,9,-4096; subf 8,9,3; bge 3f; 1:; lwz 9,0x8(31); lwz 0,0x0(31); mullw 9,10,9; addi 10,10,1; cmpw 10,11; addi 9,9,-4096; subf 9,9,3; stw 0,0x0(9); stw 9,0x0(31); blt 1b; b 3f; 2:; li 8,0; 3:; mr 3,8; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s8035C150_0();
extern "C" void _s8035C150_1();
extern "C" void _s8035C150_2();
extern "C" void _s8035C150_3();
extern "C" void f_8035C150() {}
