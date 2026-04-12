// 0x80227838 (12 bytes)
class EIGameInstance {
public:
    unsigned short GetReadVersion() const;
};

extern unsigned short EIGameInstance_readVersion[];

unsigned short EIGameInstance::GetReadVersion() const {
    return EIGameInstance_readVersion[0];
}
