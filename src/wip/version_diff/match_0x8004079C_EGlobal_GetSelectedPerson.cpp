// MATCH: 0x8004079C EGlobal::GetSelectedPerson (16 bytes)
// Raw: 54 84 10 3A 38 63 00 BC 7C 63 20 2E 4E 80 00 20

struct EGlobal {
    char pad[0xBC];
    int* selectedPersons;  // offset 0xBC = 188
};

extern "C" int* EGlobal_GetSelectedPerson(EGlobal* this_, int index) {
    return &this_->selectedPersons[index];
}
