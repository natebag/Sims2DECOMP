/* ERSoundEvent::CreateCopy(void) at 0x80369FCC (32B) */
// 0x80369FCC (32 bytes)

class EStorable {
public:
    EStorable* CreateCopy() const;
};
class ERSoundEvent : public EStorable {
public:
    ERSoundEvent* CreateCopy() const;
};

ERSoundEvent* ERSoundEvent::CreateCopy() const {
    return (ERSoundEvent*)EStorable::CreateCopy();
}
