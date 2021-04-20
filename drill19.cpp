#include <iostream>
#include <vector>

template<typename T> struct S 
{
private:
	T val;

public:
	S(T value) { val = value; }
	T& get();
	T& get() const;
	S operator=(const T&);
};

template<typename T> T& S<T>::get() { return val; }

template<typename T> T& S<T>::get() const { return val; }

template<typename T> S<T> S<T>::operator=(const T& t) 
{
	S::val = t.get();
}

template<typename T> void read_val(T& v)
{
	T v1;
	std::cin >> v1;
	v = v1;
}

int main()
{
	S<int> i(2);
	S<double> d(1.5);
	S<char> c('f');
	S<std::string> s("string");
	S<std::vector<int>> vi(std::vector<int> { 1, 2, 3 });

	std::cout << i.get() << std::endl;
	std::cout << d.get() << std::endl;
	std::cout << c.get() << std::endl;
	std::cout << s.get() << std::endl;
	for (int i : vi.get()) std::cout << i << " ";
	std::cout << std::endl;

	read_val(i.get());
	read_val(d.get());
	read_val(c.get());
	read_val(s.get());

	std::cout << i.get() << std::endl;
	std::cout << d.get() << std::endl;
	std::cout << c.get() << std::endl;
	std::cout << s.get() << std::endl;
}
