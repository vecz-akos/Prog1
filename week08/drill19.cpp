#include <iostream>
#include <vector>

template<class T>
struct S {
	S() : val(T{}) {};
	S(T vv) : val(vv) {};
	const T& get() const;
	T& get();
	void set(T newval);
	T& operator=(const T& arg);
	void read_val();
private:
	T val;
};

template<class T>
const T& S<T>::get() const {
	return val;
};

template<class T>
T& S<T>::get() {
	return val;
};

template<class T>
void S<T>::set(T newval) {
	val = newval;
};

template<class T>
T& S<T>::operator=(const T& arg) {
	val = arg;
	return this->val;
};

template<class T>
void S<T>::read_val() {
	std::cin >> val;
};

template<class T>
std::istream& operator>>(std::istream& is, S<T>& arg) {
	S<T> val {};
	is >> val;
	if (!is) return is;
	arg = val;
	return is;
};

template<class T>
std::ostream& operator<<(std::ostream& os, const S<T> arg) {
	os << arg.get();
	return os;
};

std::ostream& operator<<(std::ostream& os, const S<std::vector<int>> veki) {
	os << '{';
	for (long unsigned int i = 0; i < veki.get().size()-1; ++i) {
		os << veki.get()[i] << ", ";
	}
	os << veki.get()[veki.get().size()-1] << '}';

	return os;
};

int main()
try {

	S<int> num;
	num = 10;

	S<char> ch = 'M';
	const S<double> frac = 3.6;
	S<std::string> str {"kakaoscsiga"};
	S<std::vector<int>> numvec {{11, 22, 33}};

	std::cout << num.get() << '\t' << ch.get() << std::endl;

	num.set(23);
	ch.set('A');

	std::cout << num.get() << '\t' << ch.get() << std::endl;

	num = 11;
	ch = 'X';

	std::cout << num << '\t'
		<< ch << '\t'
		<< frac << '\t'
		<< str << '\t'
		<< numvec << '\t'
		<< std::endl;

	S<std::string> read {};
	read.read_val();
	std::cout << read << std::endl;


	return 0;
} catch (std::runtime_error& e) {
	std::cerr << "exception:\t" << e.what() << std::endl;
	return 1;
} catch (...) {
	std::cerr << "Something wibble-wobble happened :(\n";
	return 2;
}