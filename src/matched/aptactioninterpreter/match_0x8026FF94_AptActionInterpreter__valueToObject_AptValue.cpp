// 0x8026FF94 AptActionInterpreter::valueToObject(AptValue (220 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 31,5; mr 28,3; lwz 0,0x0(31); mr 29,4; mr 30,6; li 11,0; rlwinm 9,0,0,25,31; addi 9,9,-12; cmplwi 9,7; bgt 0f; rlwinm 11,0,5,31,31; 0:; cmpwi 11,0; bne 1f; lwz 9,0x8(31); lha 3,0x28(9); lwz 0,0x2c(9); add 3,31,3; mtspr 8,0; blrl; cmpwi 3,0; beq 2f; 1:; stw 31,0x0(30); b 6f; 2:; lwz 0,0x0(31); li 11,0; mr 9,0; rlwinm 0,0,0,25,31; cmpwi 0,1; beq 3f; cmpwi 0,42; bne 4f; 3:; andis. 0,9,2048; beq 4f; li 11,1; 4:; cmpwi 11,0; beq 6f; rlwinm 0,9,0,25,31; mr 5,31; cmpwi 0,1; beq 5f; lwz 5,0x24(5); 5:; mr 3,28; mr 4,29; addi 5,5,12; bl _s8026FF94_0; stw 3,0x0(30); 6:; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"

extern "C" void _s8026FF94_0();

struct AptActionInterpreter {
    void valueToObject();
};

void AptActionInterpreter::valueToObject() {
}
