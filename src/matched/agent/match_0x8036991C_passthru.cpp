/* op<<(EStream&, ERSoundEvent*) at 0x8036991C (32B) */
// 0x8036991C (32 bytes)

class EStream;
class EStorable {};
class ERSoundEvent : public EStorable {};
extern EStream& operator<<(EStream& s, EStorable* obj);

EStream& operator<<(EStream& s, ERSoundEvent* obj) {
    return operator<<(s, (EStorable*)obj);
}
