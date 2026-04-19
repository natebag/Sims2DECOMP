/* operator<<(EStream&, EAnimNodeDataPos*) at 0x8036C97C (32B) */
// 0x8036C97C (32 bytes)
class EStream;
class EStorable {};
class EAnimNodeDataPos : public EStorable {};
extern EStream& operator<<(EStream& s, EStorable* obj);
EStream& operator<<(EStream& s, EAnimNodeDataPos* obj) {
    return operator<<(s, (EStorable*)obj);
}
