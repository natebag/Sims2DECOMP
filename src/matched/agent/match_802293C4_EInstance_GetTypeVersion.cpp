// 0x802293C4 (12 bytes)
class EInstance {
public:
    unsigned short GetTypeVersion() const;
};

extern unsigned short EInstance_typeInfo_version[];

unsigned short EInstance::GetTypeVersion() const {
    return EInstance_typeInfo_version[0];
}
