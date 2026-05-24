// 0x80040168 EGlobal::GetGoalsLegendRow(unsigned (340 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); cmpwi 4,6; beq 8f; cmplwi 4,6; bgt 1f; cmpwi 4,2; beq 4f; cmplwi 4,2; bgt 0f; cmpwi 4,0; beq 14f; cmpwi 4,1; beq 3f; b 14f; 0:; cmpwi 4,4; beq 6f; cmplwi 4,4; bgt 7f; b 5f; 1:; cmpwi 4,9; beq 11f; cmplwi 4,9; bgt 2f; cmpwi 4,7; beq 9f; cmpwi 4,8; beq 10f; b 14f; 2:; cmpwi 4,11; beq 13f; cmplwi 4,11; blt 12f; b 14f; 3:; lis 9,-32707; addi 31,9,10292; b 15f; 4:; lis 9,-32707; addi 31,9,10300; b 15f; 5:; lis 9,-32707; addi 31,9,10308; b 15f; 6:; lis 9,-32707; addi 31,9,10316; b 15f; 7:; lis 9,-32707; addi 31,9,10320; b 15f; 8:; lis 9,-32707; addi 31,9,10328; b 15f; 9:; lis 9,-32707; addi 31,9,10336; b 15f; 10:; lis 9,-32707; addi 31,9,10344; b 15f; 11:; lis 9,-32707; addi 31,9,10352; b 15f; 12:; lis 9,-32707; addi 31,9,10360; b 15f; 13:; lis 9,-32707; addi 31,9,10368; b 15f; 14:; lis 9,-32707; addi 31,9,10376; 15:; lwz 3,0xe8(3); lis 4,-32707; addi 4,4,10384; bl _s80040168_0; mr 4,3; lis 9,-32697; lwz 3,0x5eb4(9); mr 5,31; bl _s80040168_1; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"

extern "C" void _s80040168_0();
extern "C" void _s80040168_1();

struct EGlobal {
    void GetGoalsLegendRow();
};

void EGlobal::GetGoalsLegendRow() {
}
