// 0x803C1444 (12 bytes)
class EStorable {
public:
    unsigned short GetTypeVersion() const;
};

extern unsigned short EStorable_s_typeInfo_version[];

unsigned short EStorable::GetTypeVersion() const {
    return EStorable_s_typeInfo_version[0];
}
