#include <iostream>
#include <vector>
#include <list>
#include <array>

template <typename Iter1, typename Iter2> Iter2& copi(Iter1 f1, Iter1 e1, Iter2 f2)
{
	while (f1 != e1)
	{
		*f2 = *f1;
		*f1++;
		*f2++;
	}
	return f2;
}

template <typename T> void print(T& container)
{
	for (auto i : container)
		std::cout << i << ' ';
	std::cout << '\n';
}

int main()
{
	std::array<int, 10> a_ints{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	std::vector<int> v_ints{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	std::list<int> l_ints = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

	std::cout << "Values:\n";
	print(a_ints);
	print(v_ints);
	print(l_ints);

	std::array<int, 10> ac = a_ints;
	std::vector<int> vc = v_ints;
	std::list<int> lc = l_ints;

	for (int i = 0; i < 10; i++)
	{
		a_ints[i] += 2;
		v_ints[i] += 3;
	}

	std::list<int>::iterator ptr;

	for (ptr = l_ints.begin(); ptr != l_ints.end(); ptr++)
		*ptr += 5;
	std::cout << "\nAfter modification:\n";
	print(a_ints);
	print(v_ints);
	print(l_ints);

	copi(a_ints.begin(), a_ints.end(), v_ints.begin());
	copi(l_ints.begin(), l_ints.end(), a_ints.begin());

	std::cout << "\nVector and array after copy:\n";
	print(v_ints);
	print(a_ints);

	auto v_search = find(v_ints.begin(), v_ints.end(), 3);
	auto l_search = find(l_ints.begin(), l_ints.end(), 27);
	int v_dist = distance(v_ints.begin(), v_search);
	int l_dist = distance(l_ints.begin(), l_search);
	
	if (v_search == v_ints.end())
		std::cout << "Number 3 is not in the vector.\n";
	else
	{
		std::cout << "Number 3 found at place " << v_dist + 1 << std::endl;
	}

	if (l_search == l_ints.end())
		std::cout << "Number 27 is not in the list.\n";
	else
	{
		std::cout << "Number 27 found at place " << l_dist + 1 << std::endl;
	}

}