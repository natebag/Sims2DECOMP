// 0x800F5B10 ObjectModuleImpl::UpdateRooms(int) (704 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 27,0xc(1); stw 0,0x24(1); mr 27,3; mr 28,4; lwz 9,0x0(27); lha 3,0x98(9); lwz 0,0x9c(9); add 3,27,3; mtspr 8,0; blrl; mr. 11,3; bne 6f; b 7f; 0:; lwz 3,0x4(31); lwz 9,0x4(3); lha 0,0x350(9); lwz 9,0x354(9); add 3,3,0; mtspr 8,9; blrl; cmpwi 3,0; bne 1f; lwz 11,0x4(31); li 4,1; lwz 9,0x4(11); lha 3,0x1d8(9); lwz 0,0x1dc(9); add 3,11,3; mtspr 8,0; blrl; lis 4,-32706; addi 3,13,-24588; addi 4,4,-17728; bl _s800F5B10_0; 1:; cmpwi 28,0; beq 2f; lwz 3,0x4(31); lwz 9,0x4(3); lha 0,0x350(9); lwz 9,0x354(9); add 3,3,0; mtspr 8,9; blrl; cmpw 3,28; bne 5f; 2:; lwz 11,0x4(31); addi 30,31,104; addi 29,31,40; lwz 9,0x4(11); lwz 0,0x354(9); lha 3,0x350(9); mtspr 8,0; add 3,11,3; blrl; mr 4,3; mr 3,30; bl _s800F5B10_1; extsh 5,3; li 4,29; mr 3,29; bl _s800F5B10_2; lwz 11,0x4(31); lwz 9,0x4(11); lha 3,0x318(9); lwz 0,0x31c(9); add 3,11,3; mtspr 8,0; blrl; cmpwi 3,2; bne 5f; cmpwi 31,0; beq 3f; lwz 9,0x4(31); li 4,2; lwz 3,0x0(9); bl _s800F5B10_3; mr 11,3; b 4f; 3:; li 11,0; 4:; cmpwi 11,0; beq 5f; lwz 9,0x4(11); lha 3,0x1a8(9); lwz 0,0x1ac(9); add 3,11,3; mtspr 8,0; blrl; 5:; lwz 3,0x4(31); lwz 9,0x4(3); lha 0,0x490(9); lwz 9,0x494(9); add 3,3,0; mtspr 8,9; blrl; mr. 11,3; beq 7f; 6:; lwz 9,0x4(11); lha 3,0x520(9); lwz 0,0x524(9); add 3,11,3; mtspr 8,0; blrl; mr 31,3; b 8f; 7:; li 31,0; 8:; cmpwi 31,0; bne 0b; lwz 9,0x0(27); lha 3,0x98(9); lwz 0,0x9c(9); add 3,27,3; mtspr 8,0; blrl; mr. 11,3; beq 9f; lwz 9,0x4(11); lha 3,0x520(9); lwz 0,0x524(9); add 3,11,3; mtspr 8,0; blrl; mr 31,3; b 10f; 9:; li 31,0; 10:; cmpwi 31,0; beq 16f; cmpwi 28,0; mfcr 30; 11:; mtcrf 128,30; beq 12f; lwz 3,0x4(31); lwz 9,0x4(3); lha 0,0x350(9); lwz 9,0x354(9); add 3,3,0; mtspr 8,9; blrl; cmpw 3,28; bne 13f; 12:; lwz 3,0x4(31); li 4,7; li 5,0; li 6,0; lwz 9,0x4(3); lha 0,0x100(9); lwz 9,0x104(9); add 3,3,0; mtspr 8,9; blrl; 13:; lwz 3,0x4(31); lwz 9,0x4(3); lha 0,0x490(9); lwz 9,0x494(9); add 3,3,0; mtspr 8,9; blrl; mr. 11,3; beq 14f; lwz 9,0x4(11); lha 3,0x520(9); lwz 0,0x524(9); add 3,11,3; mtspr 8,0; blrl; mr 31,3; b 15f; 14:; li 31,0; 15:; cmpwi 31,0; bne 11b; 16:; lwz 0,0x24(1); mtspr 8,0; lmw 27,0xc(1); addi 1,1,32"

extern "C" void _s800F5B10_0();
extern "C" void _s800F5B10_1();
extern "C" void _s800F5B10_2();
extern "C" void _s800F5B10_3();

struct ObjectModuleImpl {
    void UpdateRooms();
};

void ObjectModuleImpl::UpdateRooms() {
}
