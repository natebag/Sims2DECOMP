// 0x80227820 (12 bytes)
class EIGameInstance {
public:
    short GetTypeVersion() const;
};

extern char gEIGameInstanceData[];

short EIGameInstance::GetTypeVersion() const {
    return *(short*)(gEIGameInstanceData + 0);
}
