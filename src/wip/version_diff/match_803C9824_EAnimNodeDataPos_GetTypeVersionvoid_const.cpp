// 0x803C9824 (12 bytes)
class EAnimNodeDataPos {
public:
    short GetTypeVersion() const;
};

extern char gEAnimNodeDataPosData[];

short EAnimNodeDataPos::GetTypeVersion() const {
    return *(short*)(gEAnimNodeDataPosData + 0);
}
