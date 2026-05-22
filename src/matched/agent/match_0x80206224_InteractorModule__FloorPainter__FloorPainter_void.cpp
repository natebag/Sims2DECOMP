// 0x80206224 InteractorModule::FloorPainter::FloorPainter(void) (148 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stw 31,0x14(1); stw 0,0x1c(1); mr 31,3; bl _s80206224_0; lis 9,-32697; lis 11,-32698; addi 9,9,-32400; li 0,0; stw 9,0x5c(31); addi 11,11,29008; addi 9,31,128; li 10,5; stw 11,0x10(9); addi 3,31,168; stw 0,0x20(9); addi 11,31,176; stw 10,0x80(31); lis 8,-32697; stw 0,0xa8(31); li 4,0; stw 0,0x4(3); stw 0,0x4(11); stw 0,0xb8(31); lwz 9,0x5ea0(8); lwz 9,0x0(9); cmpwi 9,0; beq 0f; lwz 4,-4(9); 0:; bl _s80206224_1; mr 3,31; lwz 0,0x1c(1); mtspr 8,0; lwz 31,0x14(1); addi 1,1,24"
extern "C" void _s80206224_0();
extern "C" void _s80206224_1();
extern "C" void f_80206224() {}
