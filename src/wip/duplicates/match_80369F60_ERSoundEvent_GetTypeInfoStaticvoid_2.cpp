// 0x80369F60 (12 bytes)
class ERSoundEvent {
public:
    struct TypeInfo* GetTypeInfoStatic() const;
};

struct TypeInfo;
extern TypeInfo __ERSoundEvent_TypeInfo;

struct TypeInfo* ERSoundEvent::GetTypeInfoStatic() const {
    return &__ERSoundEvent_TypeInfo;
}
