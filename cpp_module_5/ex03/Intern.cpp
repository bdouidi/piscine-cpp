/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idouidi <idouidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 13:17:05 by user42            #+#    #+#             */
/*   Updated: 2022/07/08 21:06:50 by idouidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
    std::cout << "a little Intern is coming 👉 👈" << std::endl;
}

Intern::Intern(const Intern& i)
{
   *this = i;
}

Intern& Intern::operator=(const Intern& i)
{
    static_cast<void>(i);
    return (*this);
}

Intern ::~Intern()
{
    std::cout << "a litlle Intern vas fired" << std::endl;
}

const char* Intern::FormDoesNotExist::what() const throw()
{
    return ("Form does not exist...");
}

Form* Intern::makeForm(const std::string form_name, const std::string target)
{
    std::string ref[3] = {"shrubbery creation", "robotomy request",
         "presidential pardon"};
    try
    {
        for (int i = 0; i < 3; i++)
        {
            if (!ref[i].compare(form_name))
            {
                std::cout << "Intern creates " << form_name << std::endl;
                switch (i)
                {
                    case 0:
                        return (new ShrubberyCreationForm(target));
                        break;
                    case 1:
                        return (new RobotomyRequestForm(target));
                        break;
                    case 2:
                        return (new PresidentialPardonForm(target));
                        break;
                }
            }
        }
        throw FormDoesNotExist();
    }
    catch(const std::exception& e)
    {
        std::cerr << "Intern can not create " << form_name << " named " << target << ", because "
            << e.what() << std::endl;
    }
    return (NULL);
}