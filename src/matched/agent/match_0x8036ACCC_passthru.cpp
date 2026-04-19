/* REffectsEmitter::CreateCopy(void) at 0x8036ACCC (32B) */
// 0x8036ACCC (32 bytes)
class EStorable {
public:
    EStorable* CreateCopy() const;
};
class REffectsEmitter : public EStorable {
public:
    REffectsEmitter* CreateCopy() const;
};
REffectsEmitter* REffectsEmitter::CreateCopy() const {
    return (REffectsEmitter*)EStorable::CreateCopy();
}
