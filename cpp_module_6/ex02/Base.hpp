/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idouidi <idouidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 02:41:00 by idouidi           #+#    #+#             */
/*   Updated: 2022/07/16 02:25:35 by idouidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __BASE_HPP__
# define  __BASE_HPP__

# include <iostream>
# include <cstdlib> 

class Base
{
public:
    virtual ~Base();
};

class A: public Base
{};
class B: public Base
{};
class C: public Base
{};

Base* generate(void);
void identify(Base* p);
void identify(Base& p);

#endif