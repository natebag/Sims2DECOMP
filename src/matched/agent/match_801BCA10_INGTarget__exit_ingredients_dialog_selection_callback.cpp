class INGTarget {
public:
    void end_dialog(int);
    void exit_ingredients_dialog_selection_callback(int);
};

void INGTarget::exit_ingredients_dialog_selection_callback(int choice) {
    if (choice == 0) {
        end_dialog(0);
    }
}
