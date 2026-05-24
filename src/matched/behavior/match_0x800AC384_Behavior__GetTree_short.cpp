// 0x800AC384 Behavior::GetTree(short, (236 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 29,0x14(1); stw 0,0x24(1); lwz 9,0x0(3); mr 30,4; mr 31,5; lha 0,0x30(9); mr 29,6; lwz 9,0x34(9); add 3,3,0; mtspr 8,9; blrl; cmpwi 3,-1; beq 3f; mr 4,3; rlwinm 5,30,0,16,31; addi 3,1,8; bl _s800AC384_0; lwz 0,0x0(31); cmpwi 0,0; bne 0f; bl _s800AC384_1; lwz 9,0x0(3); lis 4,11243; ori 4,4,9254; addi 5,1,8; lha 0,0x20(9); mr 6,31; lwz 9,0x24(9); add 3,3,0; mtspr 8,9; blrl; lwz 0,0x0(31); cmpwi 0,0; beq 3f; 0:; cmpwi 29,0; beq 1f; lwz 3,0x0(31); addi 4,1,8; lwz 9,0x0(3); lha 0,0x28(9); lwz 9,0x2c(9); b 2f; 1:; lwz 3,0x0(31); addi 4,1,8; lwz 9,0x0(3); lha 0,0x68(9); lwz 9,0x6c(9); 2:; add 3,3,0; mtspr 8,9; blrl; b 4f; 3:; li 3,0; 4:; lwz 0,0x24(1); mtspr 8,0; lmw 29,0x14(1); addi 1,1,32"

extern "C" void _s800AC384_0();
extern "C" void _s800AC384_1();

struct Behavior {
    void GetTree();
};

void Behavior::GetTree() {
}
