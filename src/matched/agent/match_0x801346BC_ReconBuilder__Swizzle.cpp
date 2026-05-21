// 0x801346BC ReconBuilder::Swizzle(void*, int) (64B)

extern "C" void Swizzle4(void* p);

class ReconBuilder {
public:
    void Swizzle(void* p, int n);
};

void ReconBuilder::Swizzle(void* p, int n) {
    *(unsigned char*)this = 1;
    Swizzle4((char*)this + 4);
    Swizzle4((char*)this + 8);
}
