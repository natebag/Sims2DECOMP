// 0x80160900 (116 bytes)
// CasGenetics::ChoosePersonalityTraits(CasSimDescriptionS2C &)

class CasGenetics { public: void ChoosePersonalityTraits(CasSimDescriptionS2C &); };

__attribute__((naked))
void CasGenetics::ChoosePersonalityTraits(CasSimDescriptionS2C &) {
    asm volatile(".long 0x9421FFE8\n.long 0x7C0802A6\n.long 0xBFA1000C\n.long 0x9001001C\n.long 0x7C9D2378\n.long 0x3BC0000C\n.long 0x4BF45BE1\n.long 0x7FC3F396\n.long 0x3D20803E\n.long 0x3BBD011C\n.long 0x38E9EFEF\n.long 0x39400000\n.long 0x1FDE000C\n.long 0x7C7E1850\n.long 0x7C630774\n.long 0x5460103A\n.long 0x7D001A14\n.long 0x7C0A4214\n.long 0x396A0001\n.long 0x7D2700AE\n.long 0x7D3D51AE\n.long 0x7D6A0774\n.long 0x2C0A0004\n.long 0x4081FFE8\n.long 0x8001001C\n.long 0x7C0803A6\n.long 0xBBA1000C\n.long 0x38210018\n.long 0x4E800020");
}
