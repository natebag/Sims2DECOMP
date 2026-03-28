/* PassiveInfluenceMap::ValidateMissing(PassiveInfluenceItem*) - 0x80113DA8 - 8 bytes */
/* li r3, 1; blr */

struct PassiveInfluenceItem;

class PassiveInfluenceMap {
public:
    int ValidateMissing(PassiveInfluenceItem* item);
};

int PassiveInfluenceMap::ValidateMissing(PassiveInfluenceItem* item) {
    return 1;
}
