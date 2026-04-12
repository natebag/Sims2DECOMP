// 0x802293DC (12 bytes)
class EInstance {
public:
    unsigned short GetReadVersion() const;
};

extern unsigned short EInstance_readVersion[];

unsigned short EInstance::GetReadVersion() const {
    return EInstance_readVersion[0];
}
