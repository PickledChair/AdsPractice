#include <iostream>

int get_row2(int row0, int row1) {
    return row0 * (row1 % 10);
}

int get_row3(int row0, int row1) {
    return row0 * ((row1 / 10) % 10);
}

int get_row4(int row0, int row1) {
    return row0 * ((row1 / 100) % 10);
}

int get_row5(int row0, int row1) {
    return row0 * (row1 / 1000);
}

bool validate_row2(int row0, int row1) {
    int row2 = get_row2(row0, row1);
    return row2 / 10000 == 66 && row2 > 660000;
}

bool validate_row3(int row0, int row1) {
    int row3 = get_row3(row0, row1);
    return row3 / 100000 == 6 && row3 > 600000;
}

bool validate_row4(int row0, int row1) {
    int row4 = get_row4(row0, row1);
    return (row4 / 100) % 1000 == 666 && row4 > 1000000;
}

bool validate_row5(int row0, int row1) {
    int row5 = get_row5(row0, row1);
    return (row5 / 1000) % 10 == 6 && row5 % 10 == 6 && row5 > 100000;
}

bool validate_row6(int row0, int row1) {
    int row6 = row0 * row1;
    return (row6 / 10000) % 100 == 66 && row6 > 1000000000;
}

int main() {
    int row0 = 100000;
    int row1 = 999;

    for (;;) {
        if (row1 == 9999) {
            row0++;
            row1 = 1000;
        } else {
            row1++;
        }

        if (!validate_row2(row0, row1)) continue;
        if (!validate_row3(row0, row1)) continue;
        if (!validate_row4(row0, row1)) continue;
        if (!validate_row5(row0, row1)) continue;
        if (validate_row6(row0, row1)) {
            std::cout << "    " << row0 << std::endl;
            std::cout << "   *  " << row1 << std::endl;
            std::cout << "   -------" << std::endl;
            std::cout << "    " << get_row2(row0, row1) << std::endl;
            std::cout << "   " << get_row3(row0, row1) << std::endl;
            std::cout << " " << get_row4(row0, row1) << std::endl;
            std::cout << " " << get_row5(row0, row1) << std::endl;
            std::cout << "----------" << std::endl;
            std::cout << row0 * row1 << std::endl;
            break;
        } else {
            continue;
        }
    }

    return 0;
}