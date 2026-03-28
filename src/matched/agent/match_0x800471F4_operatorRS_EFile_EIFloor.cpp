struct EStorable;
struct EFile;
struct EIFloor;

EFile& operator>>(EFile&, EStorable*&);

EFile& operator>>(EFile& file, EIFloor*& obj) {
    EStorable* storable;
    operator>>(file, storable);
    obj = (EIFloor*)storable;
    return file;
}
