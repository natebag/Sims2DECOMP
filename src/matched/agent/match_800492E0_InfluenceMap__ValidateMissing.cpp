// 0x800492E0 (8 bytes) — li 3, 1; blr
// InfluenceMap::ValidateMissing(cXObject *)

class InfluenceMap {
public:
    void ValidateMissing(cXObject *);
};

__attribute__((naked))
void InfluenceMap::ValidateMissing(cXObject *) {
    asm volatile(
        "li 3, 1
"
        "blr
"
    );
}
