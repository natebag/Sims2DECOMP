// 0x80356870 Effects::FastParticleEmitter::AllocateParticlePackets(int) (228 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 5,17477; lwz 6,-25872(13); mr 7,3; li 8,0; ori 5,5,21333; li 10,0; b 1f; 0:; addi 10,10,4; addi 8,8,1; 1:; cmpw 8,4; bge 3f; lwz 11,0x4(6); cmpwi 11,0; beq 2f; lwz 0,0x4(11); stw 0,0x4(6); stw 5,0x0(11); 2:; lwz 9,0x19c(7); stwx 11,10,9; lwz 11,0x19c(7); lwzx 0,10,11; cmpwi 0,0; bne 0b; mr 4,8; 3:; cmpwi 4,0; bne 4f; sth 4,0x164(7); li 3,0; sth 4,0x168(7); blr; 4:; lwz 9,0x18c(7); rlwinm 6,4,4,0,27; lwz 0,0x48(9); andi. 9,0,4096; beq 7f; li 8,0; cmpw 8,4; bge 7f; lis 9,-32702; lfs f0,0x2a4c(9); 5:; li 9,16; lwz 10,0x19c(7); rlwinm 11,8,2,0,29; mtspr 9,9; lwzx 9,11,10; addi 0,8,1; addi 9,9,684; 6:; stfs f0,0x0(9); addi 9,9,-32; bdnz 6b; mr 8,0; cmpw 8,4; blt 5b; 7:; sth 6,0x168(7); li 3,1; sth 4,0x164(7)"

struct Effects {
    void FastParticleEmitter__AllocateParticlePackets();
};

void Effects::FastParticleEmitter__AllocateParticlePackets() {
}
