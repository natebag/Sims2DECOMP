// 0x80166E94 CasScene::GetObjectPosition(unsigned (240 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="cmpwi 4,2; beq 1f; cmplwi 4,2; bgt 0f; cmpwi 4,0; beq 2f; cmpwi 4,1; beq 3f; b 6f; 0:; cmplwi 4,6; bgt 6f; b 4f; 1:; lis 9,-32696; lis 10,-32706; lwz 8,0x77b0(9); addi 11,9,30640; lwz 0,0x8(11); lwz 9,0x4(11); lfs f0,-864(10); stw 0,0x8(5); stw 8,0x0(5); b 5f; 2:; lis 9,-32696; lis 10,-32706; lwz 8,0x77bc(9); addi 11,9,30652; lwz 0,0x8(11); lwz 9,0x4(11); lfs f0,-860(10); stw 0,0x8(5); stw 8,0x0(5); b 5f; 3:; lis 9,-32696; lis 10,-32706; lwz 8,0x77c8(9); addi 11,9,30664; lwz 0,0x8(11); lwz 9,0x4(11); lfs f0,-860(10); stw 0,0x8(5); stw 8,0x0(5); b 5f; 4:; mulli 8,4,12; lis 11,-32706; lis 9,-32696; lfs f0,-856(11); addi 9,9,30688; lwzx 11,8,9; add 10,8,9; lwz 0,0x8(10); lwz 9,0x4(10); stw 0,0x8(5); stw 11,0x0(5); 5:; stw 9,0x4(5); stfs f0,0x0(6); b 7f; 6:; li 3,0; blr; 7:; li 3,1"

struct CasScene {
    void GetObjectPosition();
};

void CasScene::GetObjectPosition() {
}
