#include <iostream>
#include <string>
#include <ctime>
#include <cctype>
#include <cstdlib>

struct Data {
	std::string	s1;
	int			n;
	std::string	s2;
};

int		getRandomAlphanum()
{
	int	randn = rand() % 62;
	if (randn < 26)
		return (65 + randn);
	else if (randn >= 26 && randn < 52)
		return (97 + randn - 26);
	else
		return (48 + randn - 52);
}

void	*serialize(void)
{
	char	*seria = NULL;
	try
	{
		seria = new char[2 * sizeof(std::string) + sizeof(int)];
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return (NULL);
	}
	srand(time(0));
	bzero(seria, 52);
	std::string	s(8, '\0');
	seria[0] = 16;
	for (size_t j = 1; j < 9; j++)
		seria[j] = getRandomAlphanum();
	char	*toInt = seria + sizeof(std::string);
	for (int i = 0; i < 4; i++)
		toInt[i] = getRandomAlphanum();
	seria[sizeof(std::string) + sizeof(int) + 4] = 16;
	for (size_t j = 1; j < 9; j++)
		seria[j + sizeof(std::string) + sizeof(int) + 4] = getRandomAlphanum();
	return (reinterpret_cast<void *>(seria));
}

Data	*deserialize(void *raw)
{
	if (!raw)
		return (NULL);
	return (reinterpret_cast<Data *>(raw));
}

int main()
{
	void *s = serialize();
	if (s)
	{
		std::cout << "\033[32mRaw data representation:\033[0m\n";
		std::cout << "String1:\t" << *reinterpret_cast<std::string *>(s) << std::endl;
		std::cout << "N:\t\t" << *reinterpret_cast<int *>(reinterpret_cast<char *>(s) + sizeof(std::string)) << std::endl;
		std::cout << "String2:\t" << *reinterpret_cast<std::string *>(reinterpret_cast<char *>(s) + sizeof(std::string) + sizeof(int) * 2) << std::endl;
	}
	struct Data *ds = deserialize(s);
	if (ds)
	{
		std::cout << "\n\033[32mDeserialize data representation:\033[0m\n";
		std::cout << "String1:\t" << ds->s1 << std::endl;
		std::cout << "N:\t\t" << ds->n << std::endl;
		std::cout << "String2:\t" << ds->s2 << std::endl;
	}
	delete reinterpret_cast<char *>(s);
	return (0);
}