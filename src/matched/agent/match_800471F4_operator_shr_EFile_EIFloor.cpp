/* operator>>(EFile &, EIFloor *&) at 0x800471F4 (64B) */

struct EStorable;
struct EFile;
struct EIFloor;

EFile *operator_shr_EFile_EStorable(EFile *file, EStorable **out);

EFile *operator_shr_EFile_EIFloor(EFile *file, EIFloor **out) {
    EStorable *tmp;
    operator_shr_EFile_EStorable(file, &tmp);
    *out = (EIFloor *)tmp;
    return file;
}
