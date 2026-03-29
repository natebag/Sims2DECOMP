// 0x803C9818 (12 bytes)
class EAnimNodeDataPos {
public:
    const char* GetTypeKey() const;
};

extern char gEAnimNodeDataPosData[];

const char* EAnimNodeDataPos::GetTypeKey() const {
    return *(const char**)(gEAnimNodeDataPosData + 0);
}
