// 0x8039ECEC __unguarded_linear_insert<Neighbor**, Neighbor*, RelationsCmp> (96B)

struct Neighbor;
struct RelationsCmp {
    bool operator()(Neighbor* a, Neighbor* b);
};

void __unguarded_linear_insert_Neighbor(Neighbor** last, Neighbor* value, RelationsCmp& cmp) {
    Neighbor** next = last - 1;
    while (cmp(value, *next)) {
        *last = *next;
        last = next;
        next = last - 1;
    }
    *last = value;
}
