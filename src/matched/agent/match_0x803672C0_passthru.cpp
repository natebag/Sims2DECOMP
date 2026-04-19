/* ERAmbientScore::CreateCopy(void) at 0x803672C0 (32B) */
// 0x803672C0 (32 bytes)
class EStorable {
public:
    EStorable* CreateCopy() const;
};
class ERAmbientScore : public EStorable {
public:
    ERAmbientScore* CreateCopy() const;
};
ERAmbientScore* ERAmbientScore::CreateCopy() const {
    return (ERAmbientScore*)EStorable::CreateCopy();
}
