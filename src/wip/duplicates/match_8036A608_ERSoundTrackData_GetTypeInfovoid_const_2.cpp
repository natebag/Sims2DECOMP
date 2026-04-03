// 0x8036A608 (12 bytes)
class ERSoundTrackData {
public:
    struct TypeInfo* GetTypeInfo() const;
};

struct TypeInfo;
extern TypeInfo __ERSoundTrackData_TypeInfo;

struct TypeInfo* ERSoundTrackData::GetTypeInfo() const {
    return &__ERSoundTrackData_TypeInfo;
}
