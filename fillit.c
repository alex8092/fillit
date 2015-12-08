#include "fillit.h"

t_fillit	*ft_get_fillit(void)
{
	static t_fillit	_instance;
	return (&_instance);
}
