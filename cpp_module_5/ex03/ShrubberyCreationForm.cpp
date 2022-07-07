/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idouidi <idouidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 17:24:15 by idouidi           #+#    #+#             */
/*   Updated: 2022/02/23 00:35:43 by idouidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
:Form(target, 145, 137)
{
	setName(target);
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& s)
:Form(s)
{
	setName(s.getName());
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& s)
{
	if (this != &s)
	{
		setName(s.getName());
		setSigned(s.getSigned());
		setGradeRequiredToSign(s.getGradeRequiredToSign());
		setGradeRequiredToExec(s.getGradeRequiredToExec());
	}
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreation Form wad destroyed" << std::endl;
}

const char* ShrubberyCreationForm::ErrorFileExecption::what(void) const throw()
{
	return ("Error with file");
}

void ShrubberyCreationForm::execute(const Bureaucrat& b) const
{
	if (b.getGrade() > getGradeRequiredToExec())
		throw GradeTooLowExecption();
	if (!getSigned())
		throw IsntSignedExecption();

	std::string name_file = getName() + "_shrubbery";
	std::ofstream out_file(name_file);

	if (out_file.fail())
		throw ErrorFileExecption();
	std::string str =
"¨¨¨¨¨¨¨¨¨¨*\n\
¨¨¨¨¨¨¨¨¨ **\n\
 ¨¨¨¨¨¨¨¨¨*o*\n\
 ¨¨¨¨¨¨¨¨*☺*o*\n\
 ¨¨¨¨¨¨¨***o***\n\
 ¨¨¨¨¨¨**o**☺*o*\n\
 ¨¨¨¨¨**☺**o**o**\n\
 ¨¨¨¨**o**☺***☺*o*\n\
 ¨¨¨*****☺*o**o****\n\
 ¨¨**☺**o*****o**☺**\n\
 ¨******o*****☺**o***\n\
 ****o***☺**o***o***☺*\n\
 ¨¨¨¨¨____!_!____ \n\
 ¨¨¨¨¨\\_________/¨¨";
	out_file << str;
	out_file.close();
}