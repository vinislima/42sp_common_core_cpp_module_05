/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinda-si <vinda-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/13 22:58:26 by vinda-si          #+#    #+#             */
/*   Updated: 2026/07/13 23:21:25 by vinda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <cstdlib>
#include <ctime>

int main()
{
	std::srand(std::time(NULL));

	std::cout << "--- CREATING BUREAUCRATS ---" << std::endl;
	Bureaucrat boss("Boss", 1);
	Bureaucrat intern("Intern", 140);

	std::cout << "\n--- CREATING FORMS ---" << std::endl;
	ShrubberyCreationForm shrub("Garden");
	RobotomyRequestForm robot("Bender");
	PresidentialPardonForm pardon("Fry");

	std::cout << "\n--- TEST 1: Executing Unsigned Form (Expected Failure) ---" << std::endl;
	boss.executeForm(shrub);

	std::cout << "\n--- TEST 2: Shrubbery Creation Form ---" << std::endl;
	intern.signForm(shrub);
	intern.executeForm(shrub);
	boss.executeForm(shrub);

	std::cout << "\n--- TEST 3: Robotomy Request Form ---" << std::endl;
	boss.signForm(robot);
	boss.executeForm(robot);
	boss.executeForm(robot);
	boss.executeForm(robot);

	std::cout << "\n--- TEST 4: Presidential Pardon ---" << std::endl;
	intern.signForm(pardon);
	boss.signForm(pardon);
	boss.executeForm(pardon);

	return 0;
}
