// 0x80227838 (12 bytes)
class EIGameInstance {
public:
    short GetReadVersion() const;
};

extern char gEIGameInstanceData[];

short EIGameInstance::GetReadVersion() const {
    return *(short*)(gEIGameInstanceData + 0);
}
