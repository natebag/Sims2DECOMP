// 0x800394B8 EyeToyClient::Debug::WriteTGAToHost(ETexture*) (88B)

class ETexture {
public:
    char pad[0x10];
    unsigned short m_10;
    unsigned short m_12;
    char pad14[0x10];
    int* m_24;  // vtable ptr at 0x24
};

class EyeToyClient {
public:
    class Debug {
    public:
        static void WriteTGAToHost(short* data, int h, int w);
        static void WriteTGAToHost(ETexture* tex);
    };
};

void EyeToyClient::Debug::WriteTGAToHost(ETexture* tex) {
    char buf[8];
    // vcall slot 8 (0x40/0x44) — returns short*
    short* data = (short*)0;  // placeholder; will be set by call
    {
        // MI vcall pattern — vptr at m_24
        int* vtbl = tex->m_24;
        // Adjustor at 0x40, fn at 0x44
        short adj = *(short*)((char*)vtbl + 0x40);
        void* (*fn)(void*, int, char*, char*) = *(void* (**)(void*, int, char*, char*))((char*)vtbl + 0x44);
        char* adjusted = (char*)tex + adj;
        data = (short*)fn(adjusted, 0, buf, buf);
    }
    WriteTGAToHost(data, tex->m_10, tex->m_12);
}
