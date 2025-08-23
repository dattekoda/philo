#include "philo.h"

int	main(int argc, char *argv[])
{
	t_philo	*philo;

	if (is_arg_valid(argc, argv) == false)
		return (1);
	philo = get_philo(argc, argv);
	if (philo == NULL)
		return (1);
	end_philo(philo); // It gets philo for only free and destroy.
}
