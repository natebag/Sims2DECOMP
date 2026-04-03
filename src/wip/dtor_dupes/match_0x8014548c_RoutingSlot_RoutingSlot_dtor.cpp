extern int VT_RoutingSlot_RoutingSlot[];
void del_RoutingSlot_RoutingSlot(void *);
void dtor_RoutingSlot_RoutingSlot(char *self, int __in_chrg) {
    *(int **)self = VT_RoutingSlot_RoutingSlot;
    if (__in_chrg & 1) {
        del_RoutingSlot_RoutingSlot(self);
    }
}
