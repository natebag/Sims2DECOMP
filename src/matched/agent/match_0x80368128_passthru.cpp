/* ERAnim::CreateCopy(void) at 0x80368128 (32B) */
// 0x80368128 (32 bytes)
class EStorable {
public:
    EStorable* CreateCopy() const;
};
class ERAnim : public EStorable {
public:
    ERAnim* CreateCopy() const;
};
ERAnim* ERAnim::CreateCopy() const {
    return (ERAnim*)EStorable::CreateCopy();
}
