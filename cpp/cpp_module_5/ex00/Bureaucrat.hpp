/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idouidi <idouidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 03:39:30 by idouidi           #+#    #+#             */
/*   Updated: 2022/02/21 17:23:23 by idouidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __BUREAUCRAT_HPP__
# define  __BUREAUCRAT_HPP__

# include <iostream>
# include <exception>

class Bureaucrat
{
private:
	const std::string 	_name;
	int					_grade;
public:
	Bureaucrat(const std::string name, int grade);
	Bureaucrat(const Bureaucrat& b);
	Bureaucrat& operator=(const Bureaucrat& b);
	virtual ~Bureaucrat();

	const std::string getName() const;
	int getGrade() const;

	void increaseGrade();
	void decreaseGrade();

	class GradeTooHighException: public std::exception
	{
		public: const char* what(void) const throw();
	};

	class GradeTooLowException: public std::exception
	{
		public: const char* what(void) const throw();
	};
};


std::ostream& operator<<(std::ostream& flux, const Bureaucrat& b);
#endif