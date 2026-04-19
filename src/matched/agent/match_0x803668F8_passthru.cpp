/* operator<<(EStream&, ERAmbientScore*) at 0x803668F8 (32B) */
// 0x803668F8 (32 bytes)
class EStream;
class EStorable {};
class ERAmbientScore : public EStorable {};
extern EStream& operator<<(EStream& s, EStorable* obj);
EStream& operator<<(EStream& s, ERAmbientScore* obj) {
    return operator<<(s, (EStorable*)obj);
}
