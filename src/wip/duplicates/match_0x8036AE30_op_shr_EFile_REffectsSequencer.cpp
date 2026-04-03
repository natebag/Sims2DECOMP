/* operator>>(EFile &, REffectsSequencer *&) - 0x8036AE30 (64 bytes) */

struct EStorable;

struct EFile {
    char pad[4];
};

EFile &operator_shr_EFile_EStorable(EFile &, EStorable *&);

struct REffectsSequencer;

EFile &operator_shr_EFile_REffectsSequencer(EFile &s, REffectsSequencer *&p)
{
    EStorable *tmp;
    operator_shr_EFile_EStorable(s, tmp);
    p = (REffectsSequencer *)tmp;
    return s;
}
