struct EStorable;
struct EFile;
struct ISimsCounterTopObject;

EFile& operator>>(EFile&, EStorable*&);

EFile& operator>>(EFile& file, ISimsCounterTopObject*& obj) {
    EStorable* storable;
    operator>>(file, storable);
    obj = (ISimsCounterTopObject*)storable;
    return file;
}
