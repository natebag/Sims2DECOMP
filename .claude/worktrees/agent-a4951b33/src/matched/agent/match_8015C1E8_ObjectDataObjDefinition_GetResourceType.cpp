// 0x8015C1E8 (12 bytes)
// ObjectDataObjDefinition::GetResourceType(void) const
// lis r3, 0x4F42; ori r3, r3, 0x4A44; blr
// Returns FourCC 'OBJD' (0x4F424A44)
class ObjectDataObjDefinition {
public:
    unsigned int GetResourceType() const;
};

unsigned int ObjectDataObjDefinition::GetResourceType() const {
    return 0x4F424A44; // 'OBJD'
}
