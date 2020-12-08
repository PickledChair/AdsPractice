#include <iostream>

int get_row2(int row0, int row1) {
    return row0 * (row1 % 10);
}

int get_row3(int row0, int row1) {
    return row0 * (row1 / 10);
}

bool validate_row2(int row0, int row1) {
    int row2 = get_row2(row0, row1);
    return row2 % 100 >= 30 && row2 % 100 < 40 && row2 > 100;
}

bool validate_row3(int row0, int row1) {
    int row3 = get_row3(row0, row1);
    return row3 >= 10 && row3 < 100;
}

bool validate_row4(int row0, int row1) {
    int row4 = row0 * row1;
    return row4 % 100 >= 40 && row4 % 100 < 50 && row4 > 100;
}

int main() {
    int row0 = 20;
    int row1 = 10;

    for (;;) {
        if (row1 == 100) {
            row0++;
            row1 = 10;
        } else {
            row1++;
        }

        if (!validate_row2(row0, row1)) continue;
        if (!validate_row3(row0, row1)) continue;
        if (validate_row4(row0, row1)) {
            std::cout << " " << row0 << std::endl;
            std::cout << "*" << row1 << std::endl;
            std::cout << "---" << std::endl;
            std::cout << get_row2(row0, row1) << std::endl;
            std::cout << get_row3(row0, row1) << std::endl;
            std::cout << "---" << std::endl;
            std::cout << row0 * row1 << std::endl;
            break;
        } else {
            continue;
        }
    }

    return 0;
}