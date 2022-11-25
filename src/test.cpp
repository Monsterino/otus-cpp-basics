#include "test.h"

#include <string>

void p_container_int_homework_test() {

	std::cout << "p_container_int_test" << std::endl;
	P_Container<int> cont;
	cont.push_back(0);
	cont.push_back(1);
	cont.push_back(2);
	cont.push_back(3);
	cont.push_back(4);
	cont.push_back(5);
	cont.push_back(6);
	cont.push_back(7);
	cont.push_back(8);
	cont.push_back(9);

	std::cout << "Start container:";
	std::cout << cont << std::endl;

	std::cout << "Container size: " << cont.size() << " elements" << std::endl;

	std::cout << "Deleting elements :3,5,7" << std::endl;
	cont.erase(3);
	cont.erase(4);
	cont.erase(5);
	std::cout << cont << std::endl;

	std::cout << "Adding 10 to position 1:" << std::endl;
	cont.insert(1, 10);
	std::cout << cont << std::endl;

	std::cout << "Adding 20 to middle:" << std::endl;
	cont.insert(std::floor(cont.size() / 2)+1, 20);
	std::cout << cont << std::endl;


	std::cout << "Adding 30 to end:" << std::endl;
	cont.push_back(30);
	std::cout << cont << std::endl << std::endl;


}


void n_container_int_homework_test() {
	std::cout << "n_container_int_test" << std::endl;

	N_Container<int> cont;

	cont.push_back(0);
	cont.push_back(1);
	cont.push_back(2);
	cont.push_back(3);
	cont.push_back(4);
	cont.push_back(5);
	cont.push_back(6);
	cont.push_back(7);
	cont.push_back(8);
	cont.push_back(9);

	std::cout << "Start container:";
	std::cout << cont << std::endl;

	std::cout << "Container size: " << cont.size() << " elements" << std::endl;

	std::cout << "Deleting elements :3,5,7" << std::endl;
	cont.erase(3);
	cont.erase(4);
	cont.erase(5);
	std::cout << cont << std::endl;

	std::cout << "Adding 10 to position 1:" << std::endl;
	cont.insert(1, 10);
	std::cout << cont << std::endl;

	std::cout << "Adding 20 to middle:" << std::endl;
	cont.insert(std::floor(cont.size() / 2) + 1, 20);
	std::cout << cont << std::endl;


	std::cout << "Adding 30 to end:" << std::endl;
	cont.push_back(30);
	std::cout << cont << std::endl << std::endl;

}

void p_container_char_homework_test() {

	std::cout << "p_container_char_test" << std::endl;
	P_Container<char> cont;
	cont.push_back('a');
	cont.push_back('b');
	cont.push_back('c');
	cont.push_back('d');
	cont.push_back('e');
	cont.push_back('f');
	cont.push_back('g');
	cont.push_back('h');
	cont.push_back('i');
	cont.push_back('j');

	std::cout << "Start container:";
	std::cout << cont << std::endl;

	std::cout << "Container size: " << cont.size() << " elements" << std::endl;

	std::cout << "Deleting elements :3,5,7" << std::endl;
	cont.erase(3);
	cont.erase(4);
	cont.erase(5);
	std::cout << cont << std::endl;

	std::cout << "Adding A to position 1:" << std::endl;
	cont.insert(1, 'A');
	std::cout << cont << std::endl;

	std::cout << "Adding B to middle:" << std::endl;
	cont.insert(std::floor(cont.size() / 2) + 1, 'B');
	std::cout << cont << std::endl;


	std::cout << "Adding C to end:" << std::endl;
	cont.push_back('C');
	std::cout << cont << std::endl << std::endl;

}


void n_container_char_homework_test() {
	std::cout << "n_container_char_test" << std::endl;

	N_Container<char> cont;
	cont.push_back('a');
	cont.push_back('b');
	cont.push_back('c');
	cont.push_back('d');
	cont.push_back('e');
	cont.push_back('f');
	cont.push_back('g');
	cont.push_back('h');
	cont.push_back('i');
	cont.push_back('j');

	std::cout << "Start container:";
	std::cout << cont << std::endl;

	std::cout << "Container size: " << cont.size() << " elements" << std::endl;

	std::cout << "Deleting elements :3,5,7" << std::endl;
	cont.erase(3);
	cont.erase(4);
	cont.erase(5);
	std::cout << cont << std::endl;

	std::cout << "Adding A to position 1:" << std::endl;
	cont.insert(1, 'A');
	std::cout << cont << std::endl;

	std::cout << "Adding B to middle:" << std::endl;
	cont.insert(std::floor(cont.size() / 2) + 1, 'B');
	std::cout << cont << std::endl;


	std::cout << "Adding C to end:" << std::endl;
	cont.push_back('C');
	std::cout << cont << std::endl << std::endl;

}

void p_container_int_test() {
	P_Container<int> cont;

	cont.push_back(0);
	cont.push_back(1);
	cont.push_back(2);
	cont.push_back(3);
	cont.push_back(4);
	cont.push_back(5);
	cont.push_back(6);
	cont.push_back(7);
	cont.push_back(8);
	cont.push_back(9);

	cont.print_elements();


	std::cout << "Container size: " << cont.size() << " elements" << std::endl;

	cont.insert(1, 10);
	std::cout << "After insert 10 to the first position: ";
	cont.print_elements();
	std::cout << "Container size: " << cont.size() << " elements" << std::endl;

	cont.insert(6, 50);
	std::cout << "After insert 50 to six position: ";
	cont.print_elements();
	std::cout << "Container size: " << cont.size() << " elements" << std::endl;


	std::cout << "After 3 numbers: ";

	cont.push_back(10);
	cont.push_back(11);
	cont.push_back(12);
	cont.print_elements();
	std::cout << "Container size: " << cont.size() << " elements" << std::endl;


	std::cout << "After insert 70 to 12 position: ";
	cont.insert(12, 70);
	cont.print_elements();
	std::cout << "Container size: " << cont.size() << " elements" << std::endl;


	std::cout << "After insert 80 to 10 position: ";
	cont.insert(10, 80);
	cont.print_elements();
	std::cout << "Container size: " << cont.size() << " elements" << std::endl;


	std::cout << "After insert 90 to 7 position: ";
	cont.insert(7, 90);
	cont.print_elements();
	std::cout << "Container size: " << cont.size() << " elements" << std::endl;


	std::cout << "After erase 3 element: ";
	cont.erase(3);
	cont.print_elements();
	std::cout << "Container size: " << cont.size() << " elements" << std::endl;

	std::cout << "After erase 7 element: ";
	cont.erase(7);
	cont.print_elements();
	std::cout << "Container size: " << cont.size() << " elements" << std::endl;

	std::cout << "After erase 11 element: ";
	cont.erase(11);
	cont.print_elements();
	std::cout << "Container size: " << cont.size() << " elements" << std::endl;


	std::cout << cont << std::endl;


	for (P_Container<int>::Iterator it = cont.begin(); it != cont.end(); ++it) {
		const auto i = *it;
		std::cout << i << " ";
	}
	std::cout << std::endl;
};

void p_container_str_test() {
	P_Container<char> cont;

	//��������� 10 ���� 
	cont.push_back('a');
	cont.push_back('b');
	cont.push_back('c');
	cont.push_back('d');
	cont.push_back('e');
	cont.push_back('f');
	cont.push_back('g');
	cont.push_back('h');
	cont.push_back('i');
	cont.push_back('j');

	//
	cont.print_elements();


	std::cout << "Container size: " << cont.size() << " elements" << std::endl;

	std::cout << "After insert Z to the first position: ";
	cont.insert(1, 'Z');
	cont.print_elements();
	std::cout << "Container size: " << cont.size() << " elements" << std::endl;

	std::cout << "After insert Y to six position: ";
	cont.insert(6, 'Y');
	cont.print_elements();
	std::cout << "Container size: " << cont.size() << " elements" << std::endl;


	std::cout << "After 3 chars: ";

	cont.push_back('k');
	cont.push_back('l');
	cont.push_back('m');
	cont.print_elements();
	std::cout << "Container size: " << cont.size() << " elements" << std::endl;


	std::cout << "After insert N to 12 position: ";
	cont.insert(12, 'N');
	cont.print_elements();
	std::cout << "Container size: " << cont.size() << " elements" << std::endl;


	std::cout << "After insert O to 10 position: ";
	cont.insert(10, 'O');
	cont.print_elements();
	std::cout << "Container size: " << cont.size() << " elements" << std::endl;


	std::cout << "After insert P to 7 position: ";
	cont.insert(7, 'P');
	cont.print_elements();
	std::cout << "Container size: " << cont.size() << " elements" << std::endl;


	std::cout << "After erase 3 element: ";
	cont.erase(3);
	cont.print_elements();
	std::cout << "Container size: " << cont.size() << " elements" << std::endl;

	std::cout << "After erase 7 element: ";
	cont.erase(7);
	cont.print_elements();
	std::cout << "Container size: " << cont.size() << " elements" << std::endl;

	std::cout << "After erase 11 element: ";
	cont.erase(11);
	cont.print_elements();
	std::cout << "Container size: " << cont.size() << " elements" << std::endl;


	std::cout << cont << std::endl;


	for (P_Container<char>::Iterator it = cont.begin(); it != cont.end(); ++it) {
		const auto i = *it;
		std::cout << i << " ";
	}
	std::cout << std::endl;
};

void n_container_test() {
	N_Container<int> ncont;
	std::cout << std::endl << "N_container_test" << std::endl;
	ncont.push_back(0);
	ncont.push_back(1);
	ncont.push_back(2);
	ncont.push_back(3);
	ncont.push_back(4);
	ncont.push_back(5);
	ncont.push_back(6);
	ncont.push_back(7);
	ncont.push_back(8);
	ncont.push_back(9);

	ncont.print_elements();

	std::cout << "Container size: " << ncont.size() << " elements" << std::endl;

	ncont.insert(1, 10);
	std::cout << "After insert 10 to the first position: ";
	ncont.print_elements();
	std::cout << "Container size: " << ncont.size() << " elements" << std::endl;

	ncont.insert(6, 50);
	std::cout << "After insert 50 to six position: ";
	ncont.print_elements();
	std::cout << "Container size: " << ncont.size() << " elements" << std::endl;


	std::cout << "After 3 numbers: ";

	ncont.push_back(10);
	ncont.push_back(11);
	ncont.push_back(12);
	ncont.print_elements();
	std::cout << "Container size: " << ncont.size() << " elements" << std::endl;


	std::cout << "After insert 70 to 12 position: ";
	ncont.insert(12, 70);
	ncont.print_elements();
	std::cout << "Container size: " << ncont.size() << " elements" << std::endl;


	std::cout << "After insert 80 to 10 position: ";
	ncont.insert(10, 80);
	ncont.print_elements();
	std::cout << "Container size: " << ncont.size() << " elements" << std::endl;


	std::cout << "After insert 90 to 7 position: ";
	ncont.insert(7, 90);
	ncont.print_elements();
	std::cout << "Container size: " << ncont.size() << " elements" << std::endl;


	std::cout << "After erase 3 element: ";
	ncont.erase(3);
	ncont.print_elements();
	std::cout << "Container size: " << ncont.size() << " elements" << std::endl;


	std::cout << "After erase 7 element: ";
	ncont.erase(7);
	ncont.print_elements();
	std::cout << "Container size: " << ncont.size() << " elements" << std::endl;

	std::cout << "After erase 11 element: ";
	ncont.erase(11);
	ncont.print_elements();
	std::cout << "Container size: " << ncont.size() << " elements" << std::endl;



	std::cout << ncont << std::endl;

	for (N_Container<int>::Iterator it = ncont.begin(); it != ncont.end(); ++it) {
		const auto i = *it;
		std::cout << i << " ";
	}
	std::cout << std::endl;

};