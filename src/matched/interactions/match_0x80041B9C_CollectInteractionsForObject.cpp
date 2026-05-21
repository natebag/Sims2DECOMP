// 0x80041B9C CollectInteractionsForObject(cXObject*, InteractionList&, int, int) (68B)

class cXObject;
class InteractionList;
class cXPerson;

extern struct Globals {
    char pad_00[188];
    cXPerson* persons[1];  // at offset 188
} _globals;

extern void CollectInteractionsForObject(cXObject* obj, InteractionList& list, cXPerson* person, int who);

void CollectInteractionsForObject(cXObject* obj, InteractionList& list, int idx, int who) {
    if (obj == 0) return;
    cXPerson* p = _globals.persons[idx];
    if (p == 0) return;
    CollectInteractionsForObject(obj, list, p, who);
}
