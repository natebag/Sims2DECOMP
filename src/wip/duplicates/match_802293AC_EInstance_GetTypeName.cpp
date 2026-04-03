// 0x802293AC (12 bytes)
class EInstance {
public:
    const char* GetTypeName() const;
};

// Force lis + lwz pattern
extern char gInstanceData[0xB7AC];

const char* EInstance::GetTypeName() const {
    return *(const char**)(gInstanceData + 0xB7AC);
}
