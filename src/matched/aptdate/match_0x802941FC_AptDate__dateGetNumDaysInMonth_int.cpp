// 0x802941FC AptDate::dateGetNumDaysInMonth(int, (172 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); cmpwi 4,5; li 0,31; beq 4f; bgt 1f; cmpwi 4,2; beq 2f; bgt 0f; cmpwi 4,0; beq 2f; cmpwi 4,1; beq 3f; b 5f; 0:; cmpwi 4,3; beq 4f; cmpwi 4,4; beq 2f; b 5f; 1:; cmpwi 4,8; beq 4f; blt 2f; cmpwi 4,10; beq 4f; blt 2f; cmpwi 4,11; bne 5f; 2:; li 0,31; b 5f; 3:; mr 4,5; bl _s802941FC_0; cmpwi 3,0; li 0,28; beq 5f; li 0,29; b 5f; 4:; li 0,30; 5:; mr 3,0; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"

extern "C" void _s802941FC_0();

struct AptDate {
    void dateGetNumDaysInMonth();
};

void AptDate::dateGetNumDaysInMonth() {
}
