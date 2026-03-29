// 0x803C1438 (12 bytes)
class EStorable {
public:
    const char* GetTypeKey() const;
};

extern char gEStorableData[];

const char* EStorable::GetTypeKey() const {
    return *(const char**)(gEStorableData + 0);
}
