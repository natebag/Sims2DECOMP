/* operator>>(EStream &, EIFloor *&) at 0x800471B4 (64B) */

struct EStorable;
struct EStream;
struct EIFloor;

EStream *operator_shr_EStream_EStorable(EStream *stream, EStorable **out);

EStream *operator_shr_EStream_EIFloor(EStream *stream, EIFloor **out) {
    EStorable *tmp;
    operator_shr_EStream_EStorable(stream, &tmp);
    *out = (EIFloor *)tmp;
    return stream;
}
