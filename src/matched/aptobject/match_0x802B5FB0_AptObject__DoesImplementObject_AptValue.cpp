// 0x802B5FB0 AptObject::DoesImplementObject(AptValue (336 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 29,0x14(1); stw 0,0x24(1); mr 31,3; mr 29,4; lwz 30,0x14(31); cmpwi 30,0; beq 3f; 0:; cmpw 30,29; bne 2f; 1:; li 3,1; b 8f; 2:; lwz 9,0x8(30); lha 3,0x28(9); lwz 0,0x2c(9); add 3,30,3; mtspr 8,0; blrl; cmpwi 3,0; beq 3f; lwz 9,0x8(30); lha 3,0x20(9); lwz 0,0x24(9); add 3,30,3; mtspr 8,0; blrl; lwz 30,0x8(3); cmpwi 30,0; bne 0b; 3:; lbz 0,0x20(31); cmpwi 0,0; beq 7f; addi 30,1,8; lis 4,-32703; addi 4,4,21100; mr 3,30; bl _s802B5FB0_0; mr 4,30; addi 3,31,12; bl _s802B5FB0_1; lbz 0,0x20(31); li 11,0; cmplw 11,0; bge 6f; li 10,0; 4:; lwz 9,0x24(3); lwzx 0,10,9; cmpw 0,29; bne 5f; lwz 4,0x8(1); lhz 9,0x0(4); addi 9,9,-1; rlwinm 0,9,0,16,31; sth 9,0x0(4); cmpwi 0,0; bne 1b; lhz 5,0x4(4); lwz 3,-23020(13); addi 5,5,9; bl _s802B5FB0_2; b 1b; 5:; lbz 0,0x20(31); addi 11,11,1; addi 10,10,4; cmplw 11,0; blt 4b; 6:; lwz 4,0x8(1); lhz 9,0x0(4); addi 9,9,-1; rlwinm 0,9,0,16,31; sth 9,0x0(4); cmpwi 0,0; bne 7f; lhz 5,0x4(4); lwz 3,-23020(13); addi 5,5,9; bl _s802B5FB0_3; 7:; li 3,0; 8:; lwz 0,0x24(1); mtspr 8,0; lmw 29,0x14(1); addi 1,1,32"

extern "C" void _s802B5FB0_0();
extern "C" void _s802B5FB0_1();
extern "C" void _s802B5FB0_2();
extern "C" void _s802B5FB0_3();

struct AptObject {
    void DoesImplementObject_AptValue();
};

void AptObject::DoesImplementObject_AptValue() {
}
