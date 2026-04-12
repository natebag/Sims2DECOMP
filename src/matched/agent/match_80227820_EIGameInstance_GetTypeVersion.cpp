// 0x80227820 (12 bytes)
class EIGameInstance {
public:
    unsigned short GetTypeVersion() const;
};

extern unsigned short EIGameInstance_typeInfo_version[];

unsigned short EIGameInstance::GetTypeVersion() const {
    return EIGameInstance_typeInfo_version[0];
}
