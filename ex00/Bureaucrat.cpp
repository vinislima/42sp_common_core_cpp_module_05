/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinda-si <vinda-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 23:14:49 by vinda-si          #+#    #+#             */
/*   Updated: 2026/04/26 21:17:39 by vinda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("Default"), grade(150)
{
	std::cout << "[Bureaucrat] Default Constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string& name, int grade) : name(name)
{
	std::cout << "[Bureaucrat] Parameterized Constructor called" << std::endl;
	if (grade < 1)
		throw Bureaucrat::GradeTooHighExcepetion();
	if (grade > 150)
		throw Bureaucrat::GradeTooLowExcepetion();
	this->grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : name(other.name), grade(other.grade)
{
	std::cout << "[Bureaucrat] Copy Constructor called" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	std::cout << "[Bureaucrat] Copy Assignment Operator called" << std::endl;
	if (this != &other)
		this->grade = other.grade;
	return *this;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "[Bureaucrat] Destructor called" << std::endl;
}

std::string Bureaucrat::getName() const
{
	return this->name;
}

int Bureaucrat::getGrade() const
{
	return this->grade;
}

void Bureaucrat::incrementGrade()
{
	if (this->grade - 1 < 1)
		throw Bureaucrat::GradeTooHighExcepetion();
	this->grade--;
}

void Bureaucrat::decrementGrade()
{
	if (this->grade + 1 > 150)
		throw Bureaucrat::GradeTooLowExcepetion();
	this->grade++;
}

const char* Bureaucrat::GradeTooHighExcepetion::what() const throw()
{
	return "Grade is too high! (Highest possible is 1)";
}

const char* Bureaucrat::GradeTooLowExcepetion::what() const throw()
{
	return "Grade is too low! (Lowest possible is 150)";
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj)
{
	os << obj.getName() << ", bureaucrat grade " << obj.getGrade() << ".";
	return os;
}