// 0x80058474 MorphUtilities::GetBodyLatticeIndexAndValue(float, float&, int&, float&, int&) (132B)
// ASMPROC_inject_before: before="blr" replace="" lines="li 0,0; lis 9,0x803d; stw 0,0(5); lfs 0,0x3c64(9); li 0,-1; stw 0,0(7); stfs 0,0(4); fcmpu cr0,1,0; stfs 0,0(6); cror 3,2,1; bns 2f; lis 9,0x803d; lfs 0,0x3c68(9); fcmpu cr0,1,0; bge 2f; li 0,1; fsubs 0,0,1; 1:; stw 0,0(5); stfs 0,0(4); blr; 2:; lis 9,0x803d; lfs 13,0x3c68(9); fcmpu cr0,1,13; cror 3,2,1; bclr 4,3; lis 9,0x803d; lfs 0,0x3c6c(9); fcmpu cr0,1,0; cror 3,2,0; bclr 4,3; li 0,0; fsubs 0,1,13; b 1b"

struct MorphUtilities {
    void GetBodyLatticeIndexAndValue();
};

void MorphUtilities::GetBodyLatticeIndexAndValue() {
}
