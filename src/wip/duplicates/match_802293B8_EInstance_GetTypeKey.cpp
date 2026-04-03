// 0x802293B8 (12 bytes)
class EInstance {
public:
    unsigned int GetTypeKey() const;
};

// Force lis + lwz pattern
extern char gInstanceData[0xB7B0];

unsigned int EInstance::GetTypeKey() const {
    return *(unsigned int*)(gInstanceData + 0xB7B0);
}
