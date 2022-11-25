#include <iostream>
#include <cmath>

template <typename T>
class P_Container {
public:
	P_Container() 
		:size_container{0}
		,container{nullptr}
		,reserved_size{0} {};


		~P_Container() { delete[] container; }

		
		int size() { return size_container; }		

		void print_elements() {					
			for (int i = 0; size_container > i; ++i) {
				std::cout << *(container + i) << " ";
			}
			std::cout << std::endl;
		}

		void erase(int id) {					
			if (id > size_container || id < 0) {
				std::cout << "Array index is out of bound";
				exit(0);
			}

			int delta = 0;
			int index = id - 1;

			if (size_container == (int(std::pow(2, reserved_size - 1))) + 1) {
				reserved_size -= 1;

				T* updated_container = new T[int(std::pow(2, reserved_size))];
				for (int i = 0; size_container > i; ++i) {
					if (i == id - 1) {
						delta = 1;
						continue;
					}
					updated_container[i - delta] = container[i];
				}

				delete[] container;
				container = updated_container;
			}
			else {
				for (int i = 0; size_container > i; ++i) {
					if (i == index) {
						delta = 1;
						continue;
					}
					container[i - delta] = container[i];

				}
			}

			size_container -= 1;

		}
				
		void push_back(T element) {										

			if ((size_container == int(std::pow(2, reserved_size))) || (size_container == 0)) {

				reserved_size += 1;
				T* updated_container = new T[int(std::pow(2, reserved_size))];
				for (int i = 0; size_container > i; ++i) {
					updated_container[i] = container[i];
				}

				delete[] container;
				container = updated_container;

			}

			container[size_container] = element;
			size_container += 1;

		}
		
										
		void insert(int id, T element) {									
			if (id > size_container || id < 0) {
				std::cout << "Array index is out of bound";
				exit(0);
			}

			int delta = 0;
			int index = id - 1;

			if ((size_container == int(std::pow(2, reserved_size))) || (size_container == 0)) {

				reserved_size += 1;

				T* updated_container = new T[int(std::pow(2, reserved_size))];
				for (int i = 0; size_container + 1 > i; ++i) {
					if (i == index) {
						updated_container[i] = element;
						delta = 1;
						continue;
					}
					updated_container[i] = container[i - delta];
				}

				delete[] container;
				container = updated_container;

			}
			else
			{
				delta = 1;
				for (int i = size_container - 1; i >= -1; --i) {
					if (i >= index) {
						container[i + delta] = container[i];
					}
					else {
						container[i + 1] = element;
						delta = 0;
						break;
					}

				}
			}
			size_container += 1;

		}
		
		
		T* return_container() { return container; };				

		T& operator[](int index) {									
			if (index > size_container) {
				std::cout << "Array index is out of bound";
				exit(0);
			}
			return *(container + (index - 1));
		}


		friend std::ostream& operator<<(std::ostream& os, P_Container& container) {
			for (int i = 0; container.size() > i; ++i) {
				T *ptr = container.return_container();
				os << *(ptr + i) << " ";
			}
			return os;
		}
		

		P_Container& operator+=(T value) {
			push_back(value);
			return *this;
		}

		struct Iterator
		{
			Iterator(T* ptr) : ptr(ptr) {};

			T operator*() const { return *ptr; };
			Iterator operator++() { ptr++; return *this; };
			friend bool operator!=(const Iterator& first, const Iterator& second) {return first.ptr != second.ptr;};
			friend bool operator==(const Iterator& first, const Iterator& second) { return first.ptr == second.ptr; };


			private:
				T* ptr;
			
		};
		
		Iterator begin() { return Iterator(container); };
		Iterator end() { return Iterator(container + size_container); };



	private:

		int size_container;					
		T* container;						
		int reserved_size;					


};

