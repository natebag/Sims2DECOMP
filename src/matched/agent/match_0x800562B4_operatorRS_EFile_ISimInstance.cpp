struct EStorable;
struct EFile;
struct ISimInstance;

EFile& operator>>(EFile&, EStorable*&);

EFile& operator>>(EFile& file, ISimInstance*& obj) {
    EStorable* storable;
    operator>>(file, storable);
    obj = (ISimInstance*)storable;
    return file;
}
