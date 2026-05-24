// 0x80285340 AptActionQueueC::RemoveActionFor(AptCIH (440 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 26,0x8(1); stw 0,0x24(1); mr 30,3; mr 29,4; lwz 31,0x4(30); lwz 0,0x8(30); cmpw 31,0; beq 7f; lis 28,-13108; lis 27,-32704; lis 26,-32704; ori 28,28,52429; 0:; lwz 0,0x0(31); cmpwi 0,1; bne 6f; lwz 0,0x10(31); cmpw 0,29; bne 6f; lwz 0,0xc(30); cmpw 31,0; beq 6f; lwz 0,0x8(30); cmplw 31,0; bge 2f; lwz 9,0x8(29); addi 5,26,11876; addi 4,27,13140; li 6,1917; lwz 0,0x14(9); lha 3,0x10(9); mtspr 8,0; add 3,29,3; blrl; lwz 5,0x8(30); mr 3,31; addi 4,3,20; subf 5,31,5; mullw 5,5,28; srawi 5,5,2; addi 5,5,-1; mulli 5,5,20; bl _s80285340_0; lwz 9,0x8(30); lwz 0,0x0(30); addi 9,9,-20; cmplw 9,0; bge 1f; lwz 9,0x10(30); mulli 9,9,20; addi 9,9,-20; add 9,0,9; 1:; stw 9,0x8(30); b 7f; 2:; lwz 0,0x4(30); cmplw 31,0; ble 4f; lwz 9,0x8(29); addi 5,26,11876; addi 4,27,13140; li 6,1924; lwz 0,0x14(9); lha 3,0x10(9); mtspr 8,0; add 3,29,3; blrl; lwz 3,0x4(30); subf 5,3,31; mr 4,3; mullw 5,5,28; addi 3,3,20; srawi 5,5,2; mulli 5,5,20; bl _s80285340_1; lwz 0,0x10(30); lwz 11,0x0(30); mulli 0,0,20; lwz 9,0x4(30); addi 9,9,20; add 0,11,0; cmpw 9,0; bne 3f; mr 9,11; 3:; stw 9,0x4(30); b 7f; 4:; cmpw 31,0; bne 6f; lwz 0,0x10(30); addi 3,31,20; lwz 9,0x0(30); mulli 0,0,20; add 0,9,0; cmpw 3,0; bne 5f; mr 3,9; 5:; stw 3,0x4(30); b 7f; 6:; mr 4,31; mr 3,30; bl _s80285340_2; mr 31,3; lwz 0,0x8(30); cmpw 31,0; bne 0b; 7:; lwz 0,0x24(1); mtspr 8,0; lmw 26,0x8(1); addi 1,1,32"

extern "C" void _s80285340_0();
extern "C" void _s80285340_1();
extern "C" void _s80285340_2();

struct AptActionQueueC {
    void RemoveActionFor_AptCIH();
};

void AptActionQueueC::RemoveActionFor_AptCIH() {
}
