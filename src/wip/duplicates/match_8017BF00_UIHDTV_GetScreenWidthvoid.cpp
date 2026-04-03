// 0x8017BF00 (12 bytes)
class UIHDTV {
public:
    const char* GetScreenWidth() const;
};

extern char gUIHDTVData[];

const char* UIHDTV::GetScreenWidth() const {
    return *(const char**)(gUIHDTVData + 0);
}
