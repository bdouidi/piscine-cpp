/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serial.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idouidi <idouidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 00:48:08 by idouidi           #+#    #+#             */
/*   Updated: 2022/07/16 01:04:53 by idouidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __SERIAL_HPP__
# define __SERIAL_HPP__

# include <iostream>
# include <stdint.h>

typedef struct  s_data
{
    void        *ptr;
}               Data;

uintptr_t	    serialize(Data *ptr);
Data		    *deserialize(uintptr_t ptr);

std::ostream	&operator<<(std::ostream &flux, const Data &d);

#endif