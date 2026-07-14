/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinda-si <vinda-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/13 22:58:26 by vinda-si          #+#    #+#             */
/*   Updated: 2026/07/13 23:08:59 by vinda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	std::cout << "--- CREATING BUREAUCRATS ---" << std::endl;
	Bureaucrat boss("Boss", 1);
	Bureaucrat intern("Intern", 140);

	std::cout << "\n--- CREATING FORMS ---" << std::endl;
	ShrubberyCreationForm shrub("Garden");
	RobotomyRequestForm robot("Bender");
	PresidentialPardonForm pardon("Fry");

	std::cout << "\n--- TEST 1: Shrubbery ---" << std::endl;
	intern.signForm(shrub);
	intern.executeForm(shrub);
	boss.executeForm(shrub);

	std::cout << "\n--- TEST 2: Robotomy ---" << std::endl;
	boss.signForm(robot);
	boss.executeForm(robot);

	std::cout << "\n--- TEST 3: Presidential Pardon ---" << std::endl;
	intern.signForm(pardon);
	boss.signForm(pardon);
	boss.executeForm(pardon);

	return 0;
}
