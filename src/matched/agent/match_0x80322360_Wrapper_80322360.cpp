/* operator<<(EStream&, REffectsAttachment*) at 0x80322360 (32B) */
// 0x80322360 (32 bytes)
class EStream;
class EStorable {};
class REffectsAttachment : public EStorable {};
extern EStream& operator<<(EStream& s, EStorable* obj);
EStream& operator<<(EStream& s, REffectsAttachment* obj) {
    return operator<<(s, (EStorable*)obj);
}
