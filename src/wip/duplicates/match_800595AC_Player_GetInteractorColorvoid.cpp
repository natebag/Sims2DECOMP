// 0x800595AC (12 bytes)
class Player {
public:
    struct TypeInfo* GetInteractorColor() const;
};

struct TypeInfo;
extern TypeInfo __Player_TypeInfo;

struct TypeInfo* Player::GetInteractorColor() const {
    return &__Player_TypeInfo;
}
