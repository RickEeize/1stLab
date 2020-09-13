//var 8

#include <iostream>
#include "List.h"
#include <string>

using namespace std;


int main()
{
	setlocale(0, "");
    List<string> list;
	string el;
    size_t parameter;
	bool flag = 1;
	while (flag) {
		cout << "0 - выход" << endl;
		cout << "1 - вставить" << endl;
		cout << "2 - вставить на позицию" << endl;
		cout << "3 - удалить" << endl;
		cout << "4 - удалить с позиции" << endl;
		cout << "5 - вывести на экран" << endl;
		cout << "6 - изменить" << endl;
		cout << "7 - позиция элемента" << endl;
		cout << "8 - получить элемент" << endl;
		cout << "9 - содержит ли" << endl;
		cout << "10 - пустой ли список" << endl;
		cout << "11 - размер списка" << endl;
		cout << "12 - число итераций(вставки, удаления, проверки на содержание)" << endl;
		cin >> parameter;
		if (parameter > 12) {
			cout << "Неправильный выбор" << endl;
			continue;
		}
		switch (parameter)
		{
		case 0:
			flag = 0;
			break;
		case 1: // insert
			cout << "Введите элемент" << endl;
			cin >> el;
			list.insert(el);
			break;
		case 2: // insert pos
			cout << "Введите элемент и позицию" << endl;
			cin >> el >> parameter;
			list.insert(el, parameter);
			break;
		case 3: // remove
			cout << "Введите элемент" << endl;
			cin >> el;
			list.remove(el);
			break;
		case 4: // remove pos
			cout << "Введите позицию" << endl;
			cin >> parameter;
			list.remove(parameter);
			break;
		case 5: // print
			list.print();
			break;
		case 6: // change
			cout << "Введите элемент и позицию" << endl;
			cin >> el >> parameter;
			list.change(el, parameter);
			break;
		case 7: // position
			cout << "Введите элемент" << endl;
			cin >> el;
			cout << list.position(el) << endl;
			break;
		case 8: // get
			cout << "Введите позицию" << endl;
			cin >> parameter;
			cout << list.get(parameter) << endl;
			break;
		case 9: // contains
			cout << "Введите элемент" << endl;
			cin >> el;
			cout << list.contains(el) << endl;
			break;
		case 10: // is empty
			cout << list.isEmpty() << endl;
			break;
		case 11: // size
			cout << list.size() << endl;
			break;
		case 12: // num of iterations
			cout << list.getLastOperatorIterations() << endl;
			break;
		default:
			break;
		}
	}
}