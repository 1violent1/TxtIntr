#include <iostream>
#include <string>
#include <vector>

using namespace std;

void showHelp() {
    cout << "Мультипликативный калькулятор" << endl;
    cout << "Доступные операции:" << endl;
    cout << "  multiply - умножение всех операндов" << endl;
    cout << "  divide - деление первого операнда на остальные" << endl;
    cout << "Количество операндов: от 5 до 7" << endl;
    cout << "Использование:" << endl;
    cout << "./calculator -o <операция> <число1> <число2> ..." << endl;
    cout << "./calculator --operation <операция> <число1> ..." << endl;
    cout << "./calculator -h" << endl;
    cout << "./calculator --help" << endl;
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        showHelp();
        return 0;
    }

    string operation = "";
    vector<double> operands;

    for (int i = 1; i < argc; i++) {
        string arg = argv[i];

        if (arg == "-h" || arg == "--help") {
            showHelp();
            return 0;
        }
        else if (arg == "-o" || arg == "--operation") {
            if (i + 1 < argc) {
                operation = argv[i + 1];
                i++;
            }
        }
        else {
            operands.push_back(stod(argv[i]));
        }
    }

    if (operation == "") {
        cout << "Ошибка: не указана операция!" << endl;
        showHelp();
        return 1;
    }

    if (operands.size() < 5 || operands.size() > 7) {
        cout << "Ошибка: необходимо от 5 до 7 операндов!" << endl;
        return 1;
    }

    if (operation != "multiply" && operation != "divide") {
        cout << "Ошибка: неизвестная операция!" << endl;
        showHelp();
        return 1;
    }

    double result = operands[0];

    if (operation == "multiply") {
        for (std::vector<double>::size_type i = 1; i < operands.size(); i++) {
            result *= operands[i];
        }
    }
    else {
        for (std::vector<double>::size_type i = 1; i < operands.size(); i++) {
            if (operands[i] == 0) {
                cout << "Ошибка - деление на ноль!" << endl;
                return 1;
            }

            result /= operands[i];
        }
    }

    cout << "Результат: " << result << endl;

    return 0;
}