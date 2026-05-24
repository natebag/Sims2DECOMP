// 0x802B41CC AptValue::ForceDelete(void) (124 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,3; lwz 9,0x8(31); lwz 0,0x5c(9); lha 3,0x58(9); mtspr 8,0; add 3,31,3; blrl; lwz 9,0x8(31); lha 3,0x60(9); lwz 0,0x64(9); add 3,31,3; mtspr 8,0; blrl; cmpwi 31,0; beq 0f; lwz 9,0x8(31); li 4,3; lha 3,0x78(9); lwz 0,0x7c(9); add 3,31,3; mtspr 8,0; blrl; 0:; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"

struct AptValue {
    void ForceDelete();
};

void AptValue::ForceDelete() {
}
