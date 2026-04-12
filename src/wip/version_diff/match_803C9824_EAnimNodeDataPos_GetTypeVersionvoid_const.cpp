// 0x803C9824 (12 bytes)
class EAnimNodeDataPos {
public:
    unsigned short GetTypeVersion() const;
};

extern unsigned short gEAnimNodeDataPosData[];

unsigned short EAnimNodeDataPos::GetTypeVersion() const {
    return gEAnimNodeDataPosData[0];
}
