/* operator<<(EStream&, ERDataset*) at 0x80368DA0 (32B) */
// 0x80368DA0 (32 bytes)
class EStream;
class EStorable {};
class ERDataset : public EStorable {};
extern EStream& operator<<(EStream& s, EStorable* obj);
EStream& operator<<(EStream& s, ERDataset* obj) {
    return operator<<(s, (EStorable*)obj);
}
