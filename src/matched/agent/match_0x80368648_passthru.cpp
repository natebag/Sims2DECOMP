/* operator<<(EStream&, ERCharacter*) at 0x80368648 (32B) */
// 0x80368648 (32 bytes)
class EStream;
class EStorable {};
class ERCharacter : public EStorable {};
extern EStream& operator<<(EStream& s, EStorable* obj);
EStream& operator<<(EStream& s, ERCharacter* obj) {
    return operator<<(s, (EStorable*)obj);
}
