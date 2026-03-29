// 0x803C1444 (12 bytes)
class EStorable {
public:
    short GetTypeVersion() const;
};

extern char gEStorableData[];

short EStorable::GetTypeVersion() const {
    return *(short*)(gEStorableData + 0);
}
