/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinda-si <vinda-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 22:41:05 by vinda-si          #+#    #+#             */
/*   Updated: 2026/07/16 22:57:25 by vinda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern()
{
	std::cout << "[Intern] Default Constructor called" << std::endl;
}

Intern::Intern(const Intern& other)
{
	std::cout << "[Intern] Copy Constructor called" << std::endl;
	*this = other;
}

Intern& Intern::operator=(const Intern& other)
{
	std::cout << "[Intern] Copy Assignment Operator called" << std::endl;
	(void)other;
	return *this;
}

Intern::~Intern()
{
	std::cout << "[Intern] Destructor called" << std::endl;
}

AForm* Intern::makeShrubbery(const std::string& target) const
{
	return new ShrubberyCreationForm(target);
}

AForm* Intern::makeRobotomy(const std::string& target) const
{
	return new RobotomyRequestForm(target);
}

AForm* Intern::makePresidential(const std::string& target) const
{
	return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(const std::string& formName, const std::string& target) const
{
	std::string formNames[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	AForm* (Intern::*formCreators[3])(const std::string&) const = {
		&Intern::makeShrubbery,
		&Intern::makeRobotomy,
		&Intern::makePresidential
	};

	for (int i = 0; i < 3; i++)
	{
		if (formName == formNames[i])
		{
			std::cout << "Intern creates " << formName << std::endl;
			return (this->*formCreators[i])(target);
		}
	}

	std::cerr << "Intern could not create form. Reason: " << formName << " does not exist." << std::endl;
	return NULL;
}
