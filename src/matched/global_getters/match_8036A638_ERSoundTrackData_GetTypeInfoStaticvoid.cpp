// 0x8036A638 (12 bytes)
class ERSoundTrackData {
public:
    struct TypeInfo* GetTypeInfoStatic() const;
};

struct TypeInfo;
extern TypeInfo __ERSoundTrackData_TypeInfo;

struct TypeInfo* ERSoundTrackData::GetTypeInfoStatic() const {
    return &__ERSoundTrackData_TypeInfo;
}
