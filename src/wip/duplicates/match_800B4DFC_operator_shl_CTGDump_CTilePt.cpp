// 0x800B4DFC (4 bytes)
// operator<<(CTGDump &, CTilePt &)
class CTGDump;
class CTilePt;

CTGDump& operator<<(CTGDump& dump, CTilePt& pt) {
    return dump;
}
