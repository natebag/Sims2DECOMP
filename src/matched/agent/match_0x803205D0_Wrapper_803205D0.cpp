/* ERShader::CreateCopy(void) at 0x803205D0 (32B) */
// 0x803205D0 (32 bytes)
class EStorable {
public:
    EStorable* CreateCopy() const;
};
class ERShader : public EStorable {
public:
    ERShader* CreateCopy() const;
};
ERShader* ERShader::CreateCopy() const {
    return (ERShader*)EStorable::CreateCopy();
}
