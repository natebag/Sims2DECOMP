// 0x803C980C (12 bytes)
class EAnimNodeDataPos {
public:
    const char* GetTypeName() const;
};

extern char gEAnimNodeDataPosData[];

const char* EAnimNodeDataPos::GetTypeName() const {
    return *(const char**)(gEAnimNodeDataPosData + 0);
}
