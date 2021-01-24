#include "mutantstack.hpp"
# include <iostream>
# include <list>

int main()
{
	MutantStack<int> mstack;
	std::cout << "-Push: 5\n";
	mstack.push(5);
	std::cout << "-Push: 17\n";
	mstack.push(17);
	std::cout << "at TOP: " << mstack.top() << std::endl;
	std::cout << "-Pop\n";
	mstack.pop();
	std::cout << "Stack size: "<< mstack.size() << std::endl;
	std::cout << "-Push: 3\n";
	std::cout << "-Push: 5\n";
	mstack.push(3);
	mstack.push(5);
	std::cout << "-Push: 737\n";
	mstack.push(737);
	//[...]
	std::cout << "-Push: 0\n";
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	std::cout << "While iter_begin != iter_end ->> cout:\n";
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);

	std::cout << "\033[32mMy tests (REVERSE ITERATOR): \033[0m \n";
	MutantStack<int> mstack1;
	mstack1.push(1);
	mstack1.push(17);
	mstack1.push(71);
	mstack1.push(15);
	mstack1.push(51);
	mstack1.push(19);
	MutantStack<int>::reverse_iterator rb = mstack1.rbegin();
	MutantStack<int>::reverse_iterator re = mstack1.rend();
	while (rb != re)
	{
		std::cout << *rb << std::endl;
		rb++;
	}
	std::cout << "\033[32mMy tests (CONST DIRECT ITERATOR): \033[0m \n";
	MutantStack<int>::const_iterator cb = mstack1.cbegin();
	MutantStack<int>::const_iterator ce = mstack1.cend();
	while (cb != ce)
	{
		std::cout << *cb << std::endl;
		cb++;
	}
	std::cout << "\033[32mMy tests (CONST REVERSE ITERATOR): \033[0m \n";
	MutantStack<int>::const_reverse_iterator crb = mstack1.crbegin();
	MutantStack<int>::const_reverse_iterator cre = mstack1.crend();
	while (crb != cre)
	{
		std::cout << *crb << std::endl;
		crb++;
	}

	return 0;
}