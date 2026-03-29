// 0x80227814 (12 bytes)
class EIGameInstance {
public:
    const char* GetTypeKey() const;
};

extern char gEIGameInstanceData[];

const char* EIGameInstance::GetTypeKey() const {
    return *(const char**)(gEIGameInstanceData + 0);
}
