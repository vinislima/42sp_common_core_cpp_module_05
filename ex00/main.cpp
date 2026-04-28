/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinda-si <vinda-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 21:52:06 by vinda-si          #+#    #+#             */
/*   Updated: 2026/04/27 22:52:33 by vinda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	std::cout << "--- TEST 1: Normal Bureaucrat ---" << std::endl;
	try
	{
		Bureaucrat b1("John", 42);
		std::cout << b1 << std::endl;
		b1.incrementGrade();
		std::cout << "After increment: " << b1 << std::endl;
		b1.decrementGrade();
		std::cout << "After decrement: " << b1 << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "Expection caught: " << e.what() << std::endl;
	}

	std::cout << "\n--- TEST 2: Grade Too High on Construction ---" << std::endl;
	try
	{
		Bureaucrat b2("Boss", 0);
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	std::cout << "\n--- TEST 3: Grade Too Low on Construction ---" << std::endl;
	try
	{
		Bureaucrat b3("Slacker", 151);
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	std::cout << "\n--- TEST 4: Incrementing beyond limits ---" << std::endl;
	try
	{
		Bureaucrat b4("Top", 1);
		std::cout << b4 << std::endl;
		b4.incrementGrade();
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	std::cout << "\n--- TEST 5: Decrementing beyond limits ---" << std::endl;
	try
	{
		Bureaucrat b5("Bottom", 150);
		std::cout << b5 << std::endl;
		b5.decrementGrade();
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	return 0;
}