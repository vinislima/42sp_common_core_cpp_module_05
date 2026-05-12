/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinda-si <vinda-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 21:52:06 by vinda-si          #+#    #+#             */
/*   Updated: 2026/05/11 23:30:46 by vinda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	std::cout << "--- TEST 1: Form Grade Too High/Low on Construction ---" << std::endl;
	try
	{
		Form f1("Top Secret Form", 0, 10);
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	try
	{
		Form f2("Useless Form", 150, 151);
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception caugth: " << e.what() << std::endl;
	}

	std::cout << "\n--- TEST 2: Successful Signing ---" << std::endl;
	try
	{
		Bureaucrat manager("Alice", 10);
		Form taxForm("Tax Form", 20, 20);

		std::cout << manager << std::endl;
		std::cout << taxForm << std::endl;

		manager.signForm(taxForm);
		std::cout << taxForm << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	std::cout << "\n--- TEST 3: Failed Signing (Grade Too Low) ---" << std::endl;
	try
	{
		Bureaucrat intern("Bob", 150);
		Form ndaForm("NDA Form", 50, 50);

		std::cout << intern << std::endl;
		std::cout << ndaForm << std::endl;

		intern.signForm(ndaForm);
		std::cout << ndaForm << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	return 0;
}
