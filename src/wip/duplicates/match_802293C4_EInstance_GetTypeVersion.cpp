// 0x802293C4 (12 bytes)
class EInstance {
public:
    short GetTypeVersion() const;
};

// Force lis + lha pattern
extern char gInstanceData[0xB7B4];

short EInstance::GetTypeVersion() const {
    return *(short*)(gInstanceData + 0xB7B4);
}
