/* ERCharacter::CreateCopy(void) at 0x80368CE0 (32B) */
// 0x80368CE0 (32 bytes)
class EStorable {
public:
    EStorable* CreateCopy() const;
};
class ERCharacter : public EStorable {
public:
    ERCharacter* CreateCopy() const;
};
ERCharacter* ERCharacter::CreateCopy() const {
    return (ERCharacter*)EStorable::CreateCopy();
}
