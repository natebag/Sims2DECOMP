// 0x802CBB70 EThreadMutex::Release(void) (100 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,3; li 4,-1; bl _s802CBB70_0; lwz 0,0x3c(31); cmpwi 0,1; bne 0f; addi 3,31,28; bl _s802CBB70_1; li 0,0; stw 0,0x38(31); 0:; lwz 9,0x3c(31); mr 3,31; addi 9,9,-1; stw 9,0x3c(31); bl _s802CBB70_2; li 3,1; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s802CBB70_0();
extern "C" void _s802CBB70_1();
extern "C" void _s802CBB70_2();
extern "C" void f_802CBB70() {}
