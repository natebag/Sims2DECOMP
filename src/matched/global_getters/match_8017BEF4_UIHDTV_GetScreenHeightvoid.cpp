// 0x8017BEF4 (12 bytes)
class UIHDTV {
public:
    const char* GetScreenHeight() const;
};

extern char gUIHDTVData[];

const char* UIHDTV::GetScreenHeight() const {
    return *(const char**)(gUIHDTVData + 0);
}
