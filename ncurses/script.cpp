#include <menu.h>
#include <ncurses.h>
#include <vector>

std::vector<const char *> choices = {
    "Choice 1", "Choice 2", "Choice 3", "Choice 4", "Exit",
};

int main() {
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, true);

    std::vector<ITEM *> items;
    for (const auto &choice : choices) {
        items.push_back(new_item(choice, choice));
    }
    items.push_back(nullptr);

    MENU *menu = new_menu(items.data());
    mvprintw(5, 10, "F1 to exit");
    post_menu(menu);
    refresh();

    int c;
    while ((c = getch()) != 'q') {
        switch (c) {
        case 'j':
            menu_driver(menu, REQ_DOWN_ITEM);
            break;
        case 'k':
            menu_driver(menu, REQ_UP_ITEM);
            break;
        }
    }

    free_menu(menu);

    endwin();

    return 0;
}
