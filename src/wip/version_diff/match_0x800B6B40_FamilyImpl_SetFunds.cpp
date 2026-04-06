// MATCH: 0x800B6B40 FamilyImpl::SetFunds (40 bytes)
// Raw: 3C 00 00 0F 60 00 42 3F 7C 04 00 00 41 81 00 0C 90 83 00 14 4E 80 00 20 90 03 00 14 4E 80 00 20 80 63 00 18 4E 80 00 20

struct FamilyImpl {
    int funds;      // offset 0x14
    int fundsCopy;  // offset 0x18
};

extern "C" int FamilyImpl_SetFunds(FamilyImpl* this_, int funds) {
    const int MAX_FUNDS = 999999;
    if (funds < MAX_FUNDS) {
        this_->funds = funds;
        return funds;
    }
    this_->funds = MAX_FUNDS;
    return MAX_FUNDS;
}
