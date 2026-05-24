// 0x800ABA88 Behavior::GetClassName(short, (140 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); mr 0,4; cmpwi 3,1; beq 2f; bgt 0f; cmpwi 3,0; beq 1f; b 5f; 0:; cmpwi 3,2; beq 3f; cmpwi 3,3; beq 4f; b 5f; 1:; lis 9,-32706; addi 4,9,-27924; b 6f; 2:; lis 9,-32706; addi 4,9,-27912; b 6f; 3:; lis 9,-32706; addi 4,9,-27904; b 6f; 4:; lis 9,-32706; addi 4,9,-27896; b 6f; 5:; lis 9,-32706; addi 4,9,-27884; 6:; mr 3,0; bl _s800ABA88_0; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"

extern "C" void _s800ABA88_0();

struct Behavior {
    void GetClassName();
};

void Behavior::GetClassName() {
}
