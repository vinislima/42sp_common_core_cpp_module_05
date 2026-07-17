/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinda-si <vinda-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 21:58:22 by vinda-si          #+#    #+#             */
/*   Updated: 2026/07/16 22:54:28 by vinda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Intern.hpp"

int	main()
{
	Intern	someRandomIntern;
	AForm*	rrf;
	AForm*	scf;
	AForm*	ppf;
	AForm*	unknown;

	std::cout << "\n--- INTERN CREATING FORMS ---" << std::endl;
	rrf = someRandomIntern.makeForm("robotomy request", "Bender");
	scf = someRandomIntern.makeForm("shrubbery creation", "Garden");
	ppf = someRandomIntern.makeForm("presidential pardon", "Fry");
	unknown = someRandomIntern.makeForm("alien invasion", "Earth");

	std::cout << "\n--- EXECUTING CREATED FORMS ---" << std::endl;
	Bureaucrat boss("Boss", 1);

	if (rrf)
	{
		boss.signForm(*rrf);
		boss.executeForm(*rrf);
		delete rrf;
	}
	if (scf)
	{
		boss.signForm(*scf);
		boss.executeForm(*scf);
		delete scf;
	}
	if (ppf)
	{
		boss.signForm(*ppf);
		boss.executeForm(*ppf);
		delete ppf;
	}
	if (unknown)
	{
		boss.signForm(*unknown);
		boss.executeForm(*unknown);
		delete unknown;
	}

	return 0;
}
