// 0x802DA8E4 EA::Allocator::GeneralAllocator::ReportBegin(void (108 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); mr 0,3; mr. 3,4; beq 0f; lis 0,21326; lwz 9,0x0(3); ori 0,0,16720; cmpw 9,0; beq 1f; li 3,0; b 1f; 0:; mr 4,5; mr 3,0; mr 5,6; mr 6,7; mr 7,8; bl _s802DA8E4_0; mr. 3,3; beq 1f; li 0,1; stw 0,0x10(3); 1:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s802DA8E4_0();
extern "C" void f_802DA8E4() {}
