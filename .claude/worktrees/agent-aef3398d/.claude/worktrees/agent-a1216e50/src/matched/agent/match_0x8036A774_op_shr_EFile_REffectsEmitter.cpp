/* operator>>(EFile &, REffectsEmitter *&) - 0x8036A774 (64 bytes) */

struct EStorable;

struct EFile {
    char pad[4];
};

EFile &operator_shr_EFile_EStorable(EFile &, EStorable *&);

struct REffectsEmitter;

EFile &operator_shr_EFile_REffectsEmitter(EFile &s, REffectsEmitter *&p)
{
    EStorable *tmp;
    operator_shr_EFile_EStorable(s, tmp);
    p = (REffectsEmitter *)tmp;
    return s;
}
