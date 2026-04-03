// 0x80369F30 (12 bytes)
class ERSoundEvent {
public:
    struct TypeInfo* GetTypeInfo() const;
};

struct TypeInfo;
extern TypeInfo __ERSoundEvent_TypeInfo;

struct TypeInfo* ERSoundEvent::GetTypeInfo() const {
    return &__ERSoundEvent_TypeInfo;
}
