/* RParticle::CreateCopy(void) at 0x8036C284 (32B) */
// 0x8036C284 (32 bytes)
class EStorable {
public:
    EStorable* CreateCopy() const;
};
class RParticle : public EStorable {
public:
    RParticle* CreateCopy() const;
};
RParticle* RParticle::CreateCopy() const {
    return (RParticle*)EStorable::CreateCopy();
}
