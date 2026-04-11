// 0x80161A00 CasGenetics::FemaleInnerLayerTorsoLocked (32b)
// FLAGS: -msdata=eabi -G 8
// CasGenetics::FemaleInnerLayerTorsoLocked(signed char)

struct CasGenetics;

int CasGenetics_FemaleInnerLayerTorsoLocked(CasGenetics* self, signed char val) {
    if (val == 8 || val == 0xB) {
        return 1;
    }
    return 0;
}
