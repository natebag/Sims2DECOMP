// 0x802DBFA8 EA::Allocator::GeneralAllocator::CallocInternal(unsigned (272 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mullw 4,4,5; mr 5,6; bl _s802DBFA8_0; mr. 31,3; beq 9f; lwz 9,-4(31); rlwinm 9,9,0,0,28; addi 5,9,-4; cmplwi 5,32; ble 0f; mr 3,31; li 4,0; bl _s802DBFA8_1; b 9f; 0:; rlwinm 5,5,30,2,31; mr 11,31; cmpwi 5,4; beq 5f; cmplwi 5,4; bgt 1f; cmpwi 5,2; beq 7f; cmplwi 5,2; bgt 6f; cmpwi 5,1; beq 8f; b 9f; 1:; cmpwi 5,6; beq 3f; cmplwi 5,6; blt 4f; cmpwi 5,7; beq 2f; cmpwi 5,8; bne 9f; li 0,0; addi 11,31,4; stw 0,0x0(31); 2:; li 0,0; stw 0,0x0(11); addi 11,11,4; 3:; li 0,0; stw 0,0x0(11); addi 11,11,4; 4:; li 0,0; stw 0,0x0(11); addi 11,11,4; 5:; li 0,0; stw 0,0x0(11); addi 11,11,4; 6:; li 0,0; stw 0,0x0(11); addi 11,11,4; 7:; li 0,0; stw 0,0x0(11); addi 11,11,4; 8:; li 0,0; stw 0,0x0(11); 9:; mr 3,31; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s802DBFA8_0();
extern "C" void _s802DBFA8_1();
extern "C" void f_802DBFA8() {}
