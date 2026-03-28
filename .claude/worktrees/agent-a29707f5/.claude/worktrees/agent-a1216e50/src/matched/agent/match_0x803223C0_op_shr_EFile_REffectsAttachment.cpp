/* operator>>(EFile &, REffectsAttachment *&) - 0x803223C0 (64 bytes) */

struct EStorable;

struct EFile {
    char pad[4];
};

EFile &operator_shr_EFile_EStorable(EFile &, EStorable *&);

struct REffectsAttachment;

EFile &operator_shr_EFile_REffectsAttachment(EFile &s, REffectsAttachment *&p)
{
    EStorable *tmp;
    operator_shr_EFile_EStorable(s, tmp);
    p = (REffectsAttachment *)tmp;
    return s;
}
