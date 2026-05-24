// 0x80161D84 CasMediator::RemoveListener(CasListener (484 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-88(1); mfspr 0,8; stmw 29,0x4c(1); stw 0,0x5c(1); mr 29,4; mr 31,3; stw 29,0x40(1); addi 8,1,64; lwz 11,0x4(31); lwz 9,0x4(11); cmpwi 9,0; beq 3f; mr 10,29; 0:; lwz 0,0x10(9); cmplw 0,10; blt 1f; mr 11,9; lwz 9,0x8(11); b 2f; 1:; lwz 9,0xc(9); 2:; cmpwi 9,0; bne 0b; 3:; stw 11,0x10(1); lwz 11,0x4(31); lwz 9,0x4(11); cmpwi 9,0; beq 7f; lwz 10,0x0(8); 4:; lwz 0,0x10(9); cmplw 10,0; bge 5f; mr 11,9; lwz 9,0x8(11); b 6f; 5:; lwz 9,0xc(9); 6:; cmpwi 9,0; bne 4b; 7:; lwz 0,0x10(1); stw 11,0xc(1); stw 11,0x18(1); stw 0,0x8(1); b 9f; 8:; bl _s80161D84_0; stw 3,0x10(1); 9:; lwz 3,0x10(1); li 30,1; lwz 10,0xc(1); cmpw 3,10; bne 10f; li 30,0; 10:; cmpwi 30,0; bne 8b; lwz 9,0x8(1); li 8,0; stw 10,0x18(1); stw 9,0x10(1); lwz 11,0x4(31); lwz 0,0x8(11); cmpw 9,0; stw 0,0x20(1); bne 11f; stw 11,0x28(1); xor 8,10,11; subfic 0,8,0; adde 8,0,8; 11:; cmpwi 8,0; beq 14f; lwz 0,0x8(31); cmpwi 0,0; beq 16f; lwz 9,0x4(31); mr 3,31; lwz 4,0x4(9); bl _s80161D84_1; lwz 9,0x4(31); stw 9,0x8(9); lwz 11,0x4(31); stw 30,0x4(11); lwz 9,0x4(31); stw 9,0xc(9); stw 30,0x8(31); b 16f; 12:; mr 3,9; stw 9,0x38(1); bl _s80161D84_2; lwz 5,0x4(31); lwz 0,0x38(1); stw 3,0x10(1); addi 6,5,12; addi 4,5,4; mr 3,0; stw 0,0x30(1); addi 5,5,8; bl _s80161D84_3; mr. 3,3; beq 13f; li 4,20; bl _s80161D84_4; 13:; lwz 9,0x8(31); addi 9,9,-1; stw 9,0x8(31); 14:; lwz 9,0x10(1); li 11,1; lwz 0,0x18(1); cmpw 9,0; bne 15f; li 11,0; 15:; cmpwi 11,0; bne 12b; 16:; lwz 9,0x4(29); li 4,0; lha 3,0x18(9); lwz 0,0x1c(9); add 3,29,3; mtspr 8,0; blrl; lwz 0,0x5c(1); mtspr 8,0; lmw 29,0x4c(1); addi 1,1,88"

extern "C" void _s80161D84_0();
extern "C" void _s80161D84_1();
extern "C" void _s80161D84_2();
extern "C" void _s80161D84_3();
extern "C" void _s80161D84_4();

struct CasMediator {
    void RemoveListener_CasListener();
};

void CasMediator::RemoveListener_CasListener() {
}
