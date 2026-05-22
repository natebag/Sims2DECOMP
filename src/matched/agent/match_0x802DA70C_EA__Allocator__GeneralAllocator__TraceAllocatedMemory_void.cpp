// 0x802DA70C EA::Allocator::GeneralAllocator::TraceAllocatedMemory(void (288 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-2544(1); mfspr 0,8; stmw 27,0x9dc(1); stw 0,0x9f4(1); mr 31,3; mr 29,4; lwz 3,0x4fc(31); mr 28,5; mr 30,6; mr 27,7; stw 3,0x9d0(1); cmpwi 3,0; beq 0f; bl _s802DA70C_0; 0:; lwz 0,0x4(31); andi. 9,0,1; beq 1f; mr 3,31; bl _s802DA70C_1; 1:; cmpwi 29,0; bne 2f; lwz 29,0x4d8(31); 2:; cmpwi 28,0; bne 3f; lwz 28,0x4dc(31); 3:; cmpwi 29,0; beq 8f; mr 7,30; mr 8,27; li 4,0; li 5,2; li 6,0; mr 3,31; bl _s802DA70C_2; mr 30,3; li 5,15; mr 3,31; mr 4,30; b 7f; 4:; lwz 0,0x4f8(31); lwz 4,0x0(3); cmpwi 0,0; bne 5f; lwz 0,0x4(4); andi. 9,0,4; bne 6f; 5:; mr 3,31; addi 5,1,8; li 6,2500; bl _s802DA70C_3; addi 3,1,8; mr 4,28; mtspr 8,29; blrl; 6:; mr 3,31; mr 4,30; li 5,15; 7:; bl _s802DA70C_4; mr. 3,3; bne 4b; mr 3,31; mr 4,30; bl _s802DA70C_5; 8:; lwz 3,0x9d0(1); cmpwi 3,0; beq 9f; bl _s802DA70C_6; 9:; lwz 0,0x9f4(1); mtspr 8,0; lmw 27,0x9dc(1); addi 1,1,2544"
extern "C" void _s802DA70C_0();
extern "C" void _s802DA70C_1();
extern "C" void _s802DA70C_2();
extern "C" void _s802DA70C_3();
extern "C" void _s802DA70C_4();
extern "C" void _s802DA70C_5();
extern "C" void _s802DA70C_6();
extern "C" void f_802DA70C() {}
