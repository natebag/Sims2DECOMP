// 0x80227808 (12 bytes)
class EIGameInstance {
public:
    const char* GetTypeName() const;
};

extern char gEIGameInstanceData[];

const char* EIGameInstance::GetTypeName() const {
    return *(const char**)(gEIGameInstanceData + 0);
}
