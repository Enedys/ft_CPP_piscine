#include "Brain.hpp"
#include <iomanip>

const std::string	Brain::identify(void) const
{
	std::stringstream	stream_ptr;
	const Brain			*brain_ptr = this;
	const void *ptr_adr = static_cast<const void*>(this);

	stream_ptr << "0x" << std::uppercase << std::hex << (long long)(ptr_adr);
	return (stream_ptr.str());
}

void				Brain::show_iq(void) const
{
	std::cout << "IQ: " << iq_ << std::endl;
}

void				Brain::set_iq(int new_iq)
{
	iq_ = new_iq;
}

Brain::Brain(int iq) : iq_(iq)
{
}

Brain::Brain() : iq_(120)
{
}

Brain::~Brain()
{
}