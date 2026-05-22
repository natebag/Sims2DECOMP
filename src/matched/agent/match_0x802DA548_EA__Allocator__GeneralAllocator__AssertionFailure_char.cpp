// 0x802DA548 EA::Allocator::GeneralAllocator::AssertionFailure(char (60 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); mr 9,3; lwz 0,0x4d0(9); mr 3,4; cmpwi 0,0; beq 0f; lwz 4,0x4d4(9); mtspr 8,0; blrl; 0:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void f_802DA548() {}
