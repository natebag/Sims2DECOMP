// 0x80161A00 CasGenetics::FemaleInnerLayerTorsoLocked(signed char) (32B)

struct CasGenetics {
    int FemaleInnerLayerTorsoLocked(signed char t);
};

int CasGenetics::FemaleInnerLayerTorsoLocked(signed char t) {
    if (t == 8 || t == 11) return 1;
    return 0;
}
