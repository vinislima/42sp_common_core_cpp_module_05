/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinda-si <vinda-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 21:49:41 by vinda-si          #+#    #+#             */
/*   Updated: 2026/05/10 22:28:21 by vinda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : name("Default Form"), isSigned(false), gradeToSign(150), gradeToExecute(150)
{
	std::cout << "[Form] Default Constructor called" << std::endl;
}

Form::Form(const std::string& name, int gradeToSign, int gradeToExecute)
		: name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
	std::cout << "[Form] Parameterized Constructor called" << std::endl;
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw Form::GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw Form::GradeTooLowException();
}

Form::Form(const Form& other)
		: name(other.name), isSigned(other.isSigned), gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute)
{
	std::cout << "[Form] Copy Constructor called" << std::endl;
}

Form& Form::operator=(const Form& other)
{
	std::cout << "[Form] Copy Assignment Operator called" << std::endl;
	if (this != &other)
	{
		this->isSigned = other.isSigned;
	}
	return *this;
}

Form::~Form()
{
	std::cout << "[Form] Destructor called" << std::endl;
}

std::string Form::getName() const
{
	return this->name;
}

bool Form::getIsSigned() const
{
	return this->isSigned;
}

int Form::getGradeToSign() const
{
	return this->gradeToSign;
}

int Form::getGradeToExecute() const
{
	return this->gradeToExecute;
}

void Form::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() > this->gradeToSign)
		throw Form::GradeTooLowException();
	this->isSigned = true;
}

const char* Form::GradeTooHighException::what() const throw()
{
	return "Form grade is too high!";
}

const char* Form::GradeTooLowException::what() const throw()
{
	return "Form grade is too low!";
}

std::ostream& operator<<(std::ostream& os, const Form& obj)
{
	os	<< "Form: " << obj.getName()
		<< " | Signed: " << (obj.getGradeToSign() ? "Yes" : "No")
		<< " | Grade to sign: " << obj.getGradeToSign()
		<< " | Grade to execute: " << obj.getGradeToExecute();
	return os;
}